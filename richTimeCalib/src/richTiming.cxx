#include "Riostream.h"
#include "TApplication.h"
#include "TBenchmark.h"
#include "TROOT.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TMath.h"
#include "TDatabasePDG.h"
#include "TParticlePDG.h"
#include <TTree.h>
#include <TChain.h>
#include <TH2F.h>
#include <TF1.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TCanvas.h>
#include <TApplication.h>
#include <TRint.h>
#include <TStyle.h>
#include <TBenchmark.h>
#include <sstream> 

/****************************************/
/* CLAS12 Bank definition */
#include <Clas12Banks4.h>

/* ================================================================ */
/* MAX number of hipo files */
#define MAXFILES 10000
/* == Process options ============================================= */
#include "process_opt.h"
/*==================================================================*/

using namespace std;

/* ================================================================ */
/* For time correction */
int iTimeCorr = 0;
int iCalibratedTime = 0;

/* For RICH event solution */
int iRayTracing = 0;

/* Particle ID*/
int RichParticleID = 11;

/* number of input files */
int nFiles = 0;

/* max number of entries to read */
int nEntries = 0;

/* run number*/
int RunNumber = 0;

/* list of input file names */
TString inputFiles[MAXFILES];

/* output root file */
TString rootFile = "";

/*timewalk parameters file.*/
TString timewalk_file = "";

/*timeoffset parameters file.*/
TString timeoffset_file = "";

/* ================================================================ */
#include <RichHW.h>
#include "Clas12Detectors.h"
#include <RichTimeCorr.h>

/* ================================================================ */
int GoodRichParticle(int richhadron_index);
int GoodParticleID(int ipart, int pid);
int GoodRichPhoton(int photon_index);

double PminElectron = 1.5;
double PminPion = 1.5;

/* speed of ligth cm/ns */
#define vLight 29.979


/* ================================================================ */
/* Histograms */
void makeHistos();
TObjArray Hlist(0);

/******************************************/
int main(int argc, char* argv[]) {
  TBenchmark bench;
  bench.Start("MAIN");

  /* ======================================== */
  /* Scanning the command line */
  parse_opt(argc,argv); // Check process_opt.h for modifications.
 
  if (RunNumber == 0) {
    std::cout<<"Please give the run number\n";
    return -1;
  }

  if (timewalk_file != "" || timeoffset_file != "") {
    iCalibratedTime = 0;
  }
  
  rootFile =  Form("RichTimeCalibE_%d",RunNumber);
  std::cout<<"Root file name: " + rootFile<<std::endl;
  rootFile += Form("_%s.root",(!iCalibratedTime?Form("%d",iTimeCorr):"C"));
  printf("Reading %d files\n", nFiles);
  //  for (int k=0; k<nFiles;k++) std::cout<<inputFiles[k]<<" ";
  //  std::cout<<std::endl;
  std::cout<<"Root file name: " + rootFile<<std::endl;

  /* ===================================== */
  /* Histograms */
  makeHistos();

  /* ===================================== */
  /* Enforcing no time correction if the RICH calibrated time is used */
  if (iCalibratedTime) iTimeCorr = 0;

  /* ===================================== */
  /* Time corrections */
  InitTimeCorrections();
  if ( (iTimeCorr == 1) || (iTimeCorr == 2)) LoadTimeOffsets(timeoffset_file);
  if (( (iTimeCorr == 2) || (iTimeCorr == 3) )) LoadTimeWalkPars(timewalk_file);

  if (timewalk_file!="") LoadTimeWalkPars(timewalk_file); 

  /* ===================================== */
  /* Some counters */
  int entry = 0;
  int nTriggers = 0;
  int nRec = 0;
  int nRichBadClusters = 0;
  int nRichTracks = 0;
  int nRich = 0;
  int nphotons = 0;

  //  int tile
  int  pmt, anode, absChannel;
  //  TH1F *h1;
  TH2F *h2;
  char name[200];

  /* ====================================== */
  /* LOOP OVER THE HIPO FILES */
  for (int l=0; l<nFiles; l++) {
    /* ===================================== */
    /* hipo4 object inizializations */
    fEvent = new hipo::event();
    fFactory = new hipo::dictionary();
    fReader = new hipo::reader();

    printf("==>> READING HIPO FILE: %s\n", inputFiles[l].Data());
 
    /* opening the hipo4 file */
    //fReader->open(flist[f]);  TString input
    std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
    fReader->open(inputFiles[l].Data());
    std::cout<<__FILE__<<":"<<__LINE__<<std::endl;

    /* Bank definition */
    fReader->readDictionary(*fFactory);
    //    if (!fFactory) continue;
    InitBanks();

    /* looping over the current file */
    while( (fReader->next() )  && ( (entry < nEntries)||(nEntries == 0) ) ) {
      fReader->read(*fEvent);
       /* looking for CLAS12 banks */
      if (FillBanks() ) {

	/* looking for good triggers */
	if (RUN__config->getRows()) {
	  get_RUN__config(0);
	  nTriggers++;

	  if (REC__Event->getRows()) {
	    get_REC__Event(0);
	    nRec++;

	    /* time stamp correction */
	    double ts = 0;
	    if ( (RUN__config_timestamp % 2) == 1) ts = 4.;

	    /* Loading the pindex Map */
	    LoadPindexMap(REC__Particle->getRows());
	    
	    /* Selecting events with 1 track in the RICH */
	    if (RICH__hadrons->getRows() == 1) {
	      int richhadron_index = 0;
	    
	      /* Selecting the good particle in the RICH */
	      int RichParticleQ = GoodRichParticle(richhadron_index);
	      if (RichParticleQ > 0) {
		nRichTracks++;
	      
		/* ------------------------------ */
		/* loop over the RICH photons */
		nphotons = 0;
		for (int f=0; f<RICH__photons->getRows(); f++) {
		  get_RICH__photons(f);
		  int richhit_pindex = RICH__photons_hit_index;
		  //int richhadron_pindex = RICH__photons_hadron_index;

		  /* Good RICH photon, reconstruction is ok */
		  if ( GoodRichPhoton(f) ) {
		    nphotons++;

		    /* channel info */
		    get_RICH__hits(richhit_pindex);
		    //tile = RICH__hits_tile;
		    pmt = RICH__hits_pmt;
		    anode = RICH__hits_anode;
		    absChannel = anode + (pmt-1)*nANODES;

		    /* signal duration */
		    double duration = RICH__hits_duration;

		    /* Measured photon time */
		    double MeasPhotonTime = RICH__hits_rawtime + ts;

		    /* Photon path time from production to the MAPMT */
		    double PhotonPathTime = RICH__photons_analytic_time;
		    if (iRayTracing) PhotonPathTime = RICH__photons_traced_time;

		    /* Calculated photon time with respect to the event start time */
		    double PhotonStartTime = RICH__photons_start_time;
		    double CalcPhotonTime = PhotonStartTime + PhotonPathTime;

		    /* Delta T (measured-calculated) */
		    double DTime = MeasPhotonTime - CalcPhotonTime;
		
		    sprintf(name, "hDTime");
		    gDirectory->GetObject(name, h2);
		    h2->Fill(absChannel, DTime);
		  
		    sprintf(name, "hDTime2");
		    gDirectory->GetObject(name, h2);
		    h2->Fill(absChannel, DTime);

		    sprintf(name, "hDTimeVsDuration_Pmt%d", pmt);
		    gDirectory->GetObject(name, h2);
		    h2->Fill(duration, DTime);

		    /* Corrected delta T */
		    double DTimeCorr = DTime;

		    /* use calibrated measured time */
		    if (iCalibratedTime){
		      double MeasPhotonTimeCorr = RICH__hits_time;
		      DTimeCorr = MeasPhotonTimeCorr - CalcPhotonTime;
		    }
		    else {
		      /* Reapplying the correction */
		      if (iTimeCorr || timewalk_file != "") {
			/* Corrected measured time */
			double MeasPhotonTimeCorr = GetCorrectedTime(pmt, anode, MeasPhotonTime, duration);
			DTimeCorr = MeasPhotonTimeCorr - CalcPhotonTime;
		      }
		    }

		    sprintf(name, "hDTimeCorr");
		    gDirectory->GetObject(name, h2);
		    h2->Fill(absChannel, DTimeCorr);

		    sprintf(name, "hDLenCorr");
		    gDirectory->GetObject(name, h2);
		    h2->Fill(absChannel, DTimeCorr*vLight);
		    
		    sprintf(name, "hDTimeCorrVsDuration_Pmt%d", pmt);
		    gDirectory->GetObject(name, h2);
		    h2->Fill(duration, DTimeCorr);

		  }/* END good RICH photon */


		}/* END loop over RICH photons */

		
		if (nphotons) nRich++;
	      }/* Good RICH particle */
	      else {
		if (RichParticleQ == 0) {
		  nRichBadClusters++;
		}
	      }


	    }/* END events with one track in the RICH */

	  }


	}
      }/* END event with CLAS12 banks */

      entry++;
      if ( (entry%1000) == 0) {
	fprintf(stdout, "%d  %d  %d  %d  %d\r", entry, nTriggers, nRec, nRichTracks, nRich);
	fflush(stdout);	
      }


    }/* END loop over the current file */

    delete fEvent;
    delete fFactory;
    delete fReader;
	  
  }
  printf("Total number of events:  %d \n", entry);
  printf("Number of triggers found: %d\n", nTriggers);
  printf("Number of rec. events: %d\n", nRec);
  printf("Number of RICH clusters: %d\n", (nRichTracks+nRichBadClusters));
  printf("Number of RICH good tracks: %d\n", nRichTracks);
  printf("Number of RICH events: %d\n", nRich);

 
  /*******************************************************/
  /* Out histograms */
  TFile f(&rootFile[0], "recreate");
  //Hlist.ls();
  Hlist.Write();
  f.Close();
  bench.Show("MAIN");
  return 0;
}
/* ------------------------------------------------------ */
void makeHistos()
{
  /* Histograms for the time calibration */
  TString name,title;

  /* channel binning */
  int nbins = nPMTS*nANODES;
  double bmin = 0.5;
  double bmax = nbins + 0.5;

  /* ====================================== */
  /* larger time window to accomodate all the possible timing variations */
  int na = 1000;
  double amin = -700.;
  double amax = 300;
  /* ======== */
  

  /* DeltaTcorr binning */
  int ndt = 500;
  double dt1 = -150;
  double dt2 = 50;

  /* duration binning */
  int nc = 100;
  double cmin = -0.5;
  double cmax = cmin + nc;


  title = "#Delta T vs channel";
  name = "hDTime";
  TH2F *hDTime = new TH2F(name, title, nbins, bmin, bmax, na, amin, amax);
  Hlist.Add(hDTime);
  
  title = "#Delta T vs channel";
  name = "hDTime2";
  TH2F *hDTime2 = new TH2F(name, title, nbins, bmin, bmax, na, -1500, 1500);
  Hlist.Add(hDTime2);

  title = "#Delta T_{corr} vs channel";
  name = "hDTimeCorr";
  TH2F *hDTimeCorr = new TH2F(name, title, nbins, bmin, bmax, ndt, dt1, dt2);
  Hlist.Add(hDTimeCorr);

  title = "#Delta L vs channel";
  name =  "hDLenCorr";
  TH2F *hDLenCorr = new TH2F(name, title, nbins, bmin, bmax, ndt, 30*dt1, 30*dt2);
  Hlist.Add(hDLenCorr);


  /* Delta T vs Duration per PMT */
  for (Int_t p=0; p<nPMTS; p++) {

      
    name = Form("hDTimeVsDuration_Pmt%d", p+1);
    title = Form("#Delta T vs Duration, PMT %d", p+1);
    TH2F *hDTimeVsDuration_Pmt = new TH2F(name, title, nc, cmin, cmax, na, amin, amax);
    Hlist.Add(hDTimeVsDuration_Pmt);

    name = Form("hDTimeCorrVsDuration_Pmt%d", p+1);
    title = Form("#Delta T_{corr} vs Duration, PMT %d", p+1);
    TH2F *hDTimeCorrVsDuration_Pmt = new TH2F(name, title, nc, cmin, cmax, ndt, dt1, dt2);
    Hlist.Add(hDTimeCorrVsDuration_Pmt);

  }
 
}
/* --------------------------------------------- */
int GoodRichParticle(int richhadron_index)
{
  /* Selecting good particles for RICH timing */

  
  get_RICH__hadrons(richhadron_index);
  int recparticle_pindex = RICH__hadrons_particle_index;
  get_REC__Particle(recparticle_pindex);
  int recparticle_pid = REC__Particle_pid;

  /* good particle ID */
  if ( (recparticle_pid == RichParticleID) ||  //specific ID
       (RichParticleID == 0) ||  //All particles
       (RichParticleID == 1) ||  // All positive particles
       (RichParticleID == -1)||  // All negative particles
       (RichParticleID == 99) )  // Straight tracks with zero field
    {

      /* Checking quality of the PID */
      if (GoodParticleID(recparticle_pindex, RichParticleID)) return 1;
      else return 0;

    }
  
  return -1;
}
/* -------------------------------------------- */
int GoodParticleID(int ipart, int pid)
{
  /* Verifying that a rec particle is well identified with PID=pid
     ipart=row in the REC__Particle bank 
  */

  get_REC__Particle(ipart);
  TVector3 P3(REC__Particle_px, REC__Particle_py, REC__Particle_pz);

  /* Identified particles */
  if ( (pid == 11) || (pid == 0) || (pid == -1) ) {
    if ( (REC__Particle_pid == 11) && (P3.Mag() > PminElectron) ) return 1;
    //else return 0;
  }

  if ( (pid == 211) || (pid == 0) || (pid == 1) ) {
    if ( (REC__Particle_pid == 211) && (P3.Mag() > PminPion) ) return 1;
    //else return 0;
  }

  if ( (pid == -211) || (pid == 0) || (pid == -1) ) {
    if ( (REC__Particle_pid == -211) && (P3.Mag() > PminPion) ) return 1;
    //else return 0;
  }


  
  return 0;
}
/* -------------------------------------------- */
int GoodRichPhoton(int photon_index)
{
  get_RICH__photons(photon_index);

  if (RICH__photons_type != 0) return 0;

  if (RICH__photons_traced_EtaC == 0) return 0;

  if (RICH__photons_traced_the == 0) return 0;
  if (RICH__photons_traced_phi == 0) return 0;

  return 1;
}
