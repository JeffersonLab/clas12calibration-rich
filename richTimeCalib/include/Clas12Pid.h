/* Code for Particle identification */

#define mElectron 0.00054858
#define mProton 0.93827
#define mPion 0.13957

/* speed of ligth cm/ns */
#define vLight 29.979

/* ================================================================ */
/* type of particles to use */
extern int RichParticleID;
int GoodRichParticle(int richhadron_index);
int GoodRichParticle_ZeroField(int richhadron_index);
int GoodParticleID(int ipart, int pid);

/* Particle identification cuts */
int IsElectron(int ipart);
int IsPiplus(int ipart);
int IsPiminus(int ipart);
int IsStraightTrack(int ipart);

/* Particle identification cuts not using PID and charge */
int ElectronCuts(int ipart);
int PionCuts(int ipart);


int HtccPE(int ipart);
int CaloSampling(int ipart);
void GetSamplingFractionLimits(double momentum, double *SamplingFractionMin, double *SamplingFractionMax);
int CaloFiducial(int ipart);
int ScintillatorBeta(int ipart, double mass);

double GetCaloEnergy(int ipart);

double PminElectron = 1.5;
double PminPion = 1.5;






/* ===================================================== */
int GoodRichParticle_ZeroField(int richhadron_index)
{
  /* Selecting good particles for RICH timing using zero field data 
     Here I assume all the negative particles have pid=-211 (pi-) and 
     all positive particle have pid=2212 (protons) as it looks like 
     in the reconstructed files
   */

  get_RICH__hadrons(richhadron_index);
  int recparticle_pindex = RICH__hadrons_particle_index;
  get_REC__Particle(recparticle_pindex);
  int recparticle_pid = REC__Particle_pid;

  
  /* good particle ID, only negative */
  if (recparticle_pid == -211) {
    int ipart = recparticle_pindex;

    /* Momentum cut */
    TVector3 P3(REC__Particle_px, REC__Particle_py, REC__Particle_pz);
    if (P3.Mag() > PminElectron) {
  
      /* Calorimeter fiducial cuts */
      if (CaloFiducial(ipart)) {
	
	/* HTCC nphe cut */
	if (HtccPE(ipart)) {

	  /* Beta cut */
	  if (ScintillatorBeta(ipart, mElectron)) {
	    
	    if (GetCaloEnergy(ipart) > 0.3) {
	      return 1;
	    }
	  }
	}
      }
    }
  }
  

  return 0;
}
/* ===================================================== */
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
       (RichParticleID == -1)||  // All positive particles
       (RichParticleID == 99) )  // Straight tracks with zero field
    {

      
      /* Checking quality of the PID */
      if (GoodParticleID(recparticle_pindex, RichParticleID)) return 1;
      else return 0;
    
    }

  return -1;
}
/* ------------------------------------------------------ */
int GoodParticleID(int ipart, int pid)
{
  /* Verifying that a rec particle is well identified with PID=pid
     ipart=row in the REC__Particle bank 
  */

  

  /* Identified particles */
  if ( (pid == 11) || (pid == 0) || (pid == -1) ) {
    if (IsElectron(ipart) ) {
      return 1;
    }
  }

  if ( (pid == 211) || (pid == 0) || (pid == 1) ) {
    if (IsPiplus(ipart)) return 1;
  }

  if ( (pid == -211) || (pid == 0) || (pid == -1) ) {
    if (IsPiminus(ipart)) {
      return 1;
    }
  }

  /* straight tracks */
  if ( (pid == 99) ) {
    if (IsStraightTrack(ipart)) {
      return 1;
    }
  }

  
  return 0;
}
/* ------------------------------------------------------- */
int IsStraightTrack(int ipart)
{
  /* Selecting straight tracks for zero field runs 
     It uses cuts for electrons, without the PID and charge check
     The only change is to replace the SF cut (useless with no momentum measurements)
     with a minimum calorimeter energy = 300 MeV
   */
  get_REC__Particle(ipart);

  if (REC__Particle_pid == -211) {
    /* Momentum cut */
    TVector3 P3(REC__Particle_px, REC__Particle_py, REC__Particle_pz);
    if (P3.Mag() >= PminElectron) {
      
      /* Calorimeter fiducial cuts */
      if (CaloFiducial(ipart)) {
	
	/* HTCC nphe cut */
	if (HtccPE(ipart)) {
	  
	  /* Beta cut */
	  if (ScintillatorBeta(ipart, mElectron)) {
	    /* calorimeter energy cut */
	    if (GetCaloEnergy(ipart) > 0.3) {
	      
	      return 1;
	    }
	    
	  }
	  
	}
	
      }
      
    }

  }
  
  return 0;
}
/* ------------------------------------------------------- */
/* ------------------------------------------------------- */
int IsElectron(int ipart)
{
  get_REC__Particle(ipart);
  
  /* Charge */
  if (REC__Particle_charge != -1) return 0;

  /* Event builder */
  if (REC__Particle_pid != 11) return 0;

  /* Other detector cuts for electrons */
  if (ElectronCuts(ipart)) return 1;

  return 0;
}
/* ------------------------------------------------------- */
int IsPiplus(int ipart)
{
  get_REC__Particle(ipart);
  
  /* Charge */
  if (REC__Particle_charge != 1) return 0;

  /* Event builder */
  if (REC__Particle_pid != 211) return 0;
   
  /* Other detector cuts for pions */
  if (PionCuts(ipart)) return 1;

  return 0;
}
/* ------------------------------------------------------- */
int IsPiminus(int ipart)
{
  get_REC__Particle(ipart);

  /* Charge */
  if (REC__Particle_charge != -1) return 0;

  /* Event builder */
  if (REC__Particle_pid != -211) return 0;
  
  /* Not an electron */
  if (IsElectron(ipart)) return 0;

  /* Other detector cuts for pions */
  if (PionCuts(ipart)) return 1;

  return 0;
}
/* ---------------------------------------- */
int ElectronCuts(int ipart)
{
  get_REC__Particle(ipart);

  /* Momentum cut */
  TVector3 P3(REC__Particle_px, REC__Particle_py, REC__Particle_pz);
  if (P3.Mag() < PminElectron) return 0;
  
  /* Calorimeter fiducial cuts */
  if (!CaloFiducial(ipart)) return 0;
  
  /* calorimeter energy cut */
  if (!CaloSampling(ipart)) return 0;
  
  /* HTCC nphe cut */
  if (!HtccPE(ipart)) return 0;
  
  /* Beta cut */
  if (!ScintillatorBeta(ipart, mElectron)) return 0;


  return 1;
}
/* ---------------------------------------- */
int PionCuts(int ipart)
{
  get_REC__Particle(ipart);
  
  /* Momentum cut */
  TVector3 P3(REC__Particle_px, REC__Particle_py, REC__Particle_pz);
  if (P3.Mag() < PminPion) return 0;

  /* Beta cut */
  if (!ScintillatorBeta(ipart, mPion)) return 0;
  
  return 1;
}
/* ---------------------------------------- */
int HtccPE(int ipart)
{
  double NpeMin = 2.5;

  int CherHtcc_index = indexMap[HtccID][0][ipart];

  if (CherHtcc_index != -1) {
    get_REC__Cherenkov(CherHtcc_index);
    if (REC__Cherenkov_nphe > NpeMin) return 1;
  }

  return 0;

}
/* ---------------------------------------- */
int CaloSampling(int ipart)
{
  /* Cut on the sampling fraction of the calorimeter for electrons */
  get_REC__Particle(ipart);
  
  TVector3 P3(REC__Particle_px, REC__Particle_py, REC__Particle_pz);
  TLorentzVector P;
  P.SetVectM(P3, mElectron);

  /* Calorimeter total energy */
  double CaloEnergy = 0;

  int CaloPcal_index = indexMap[CaloID][CaloLayerPcal][ipart];
  if (CaloPcal_index != -1) {
    get_REC__Calorimeter(CaloPcal_index);
    CaloEnergy = CaloEnergy + REC__Calorimeter_energy;
  }

  int CaloEin_index = indexMap[CaloID][CaloLayerEin][ipart];
  if (CaloEin_index != -1) {
    get_REC__Calorimeter(CaloEin_index);
    CaloEnergy = CaloEnergy + REC__Calorimeter_energy;
  }

  int CaloEout_index = indexMap[CaloID][CaloLayerEout][ipart];
  if (CaloEout_index != -1) {
    get_REC__Calorimeter(CaloEout_index);
    CaloEnergy = CaloEnergy + REC__Calorimeter_energy;
  }
  
  double SamplingFraction = CaloEnergy / P3.Mag();
  double SamplingFractionMin = 0;
  double SamplingFractionMax = 0;
  GetSamplingFractionLimits(P3.Mag(), &SamplingFractionMin, &SamplingFractionMax);
  if ( (SamplingFraction < SamplingFractionMin) || (SamplingFraction > SamplingFractionMax) ) return 0;

  return 1;
}
/* ---------------------------------------- */
double GetCaloEnergy(int ipart)
{
   
  /* Calorimeter total energy */
  double CaloEnergy = 0;

  int CaloPcal_index = indexMap[CaloID][CaloLayerPcal][ipart];
  if (CaloPcal_index != -1) {
    get_REC__Calorimeter(CaloPcal_index);
    CaloEnergy = CaloEnergy + REC__Calorimeter_energy;
  }

  int CaloEin_index = indexMap[CaloID][CaloLayerEin][ipart];
  if (CaloEin_index != -1) {
    get_REC__Calorimeter(CaloEin_index);
    CaloEnergy = CaloEnergy + REC__Calorimeter_energy;
  }

  int CaloEout_index = indexMap[CaloID][CaloLayerEout][ipart];
  if (CaloEout_index != -1) {
    get_REC__Calorimeter(CaloEout_index);
    CaloEnergy = CaloEnergy + REC__Calorimeter_energy;
  }

 
  return CaloEnergy;
}
/* ---------------------------------------- */
void GetSamplingFractionLimits(double momentum, double *SamplingFractionMin, double *SamplingFractionMax)
{
  /* Calculate limits for the electron sampling fraction
     For the moment just approximated fixed cuts
 */

  double mean = 0.23;
  double sigma = 0.08;

  *SamplingFractionMin = mean - sigma;
  *SamplingFractionMax = mean + sigma;

  return;
}
/* --------------------------------------------- */
int CaloFiducial(int ipart)
{
  /* Calorimeter fiducial cuts */

  int lMin = 40;
  int lMax = 410;
  
  /* PCAL */
  int CaloPcal_index = indexMap[CaloID][CaloLayerPcal][ipart];
  if (CaloPcal_index != -1) {
    get_REC__Calorimeter(CaloPcal_index);
    if ( (REC__Calorimeter_lu < lMin) || (REC__Calorimeter_lu > lMax) ) return 0;
    if ( (REC__Calorimeter_lv < lMin) || (REC__Calorimeter_lv > lMax) ) return 0;
    if ( (REC__Calorimeter_lw < lMin) || (REC__Calorimeter_lw > lMax) ) return 0;
  }


  /* EC in */
  int CaloEin_index = indexMap[CaloID][CaloLayerEin][ipart];
  if (CaloEin_index != -1) {
    get_REC__Calorimeter(CaloEin_index);
    if ( (REC__Calorimeter_lu < lMin) || (REC__Calorimeter_lu > lMax) ) return 0;
    if ( (REC__Calorimeter_lv < lMin) || (REC__Calorimeter_lv > lMax) ) return 0;
    if ( (REC__Calorimeter_lw < lMin) || (REC__Calorimeter_lw > lMax) ) return 0;
  }


  /* EC out */
  int CaloEout_index = indexMap[CaloID][CaloLayerEout][ipart];
  if (CaloEout_index != -1) {
    get_REC__Calorimeter(CaloEout_index);
    if ( (REC__Calorimeter_lu < lMin) || (REC__Calorimeter_lu > lMax) ) return 0;
    if ( (REC__Calorimeter_lv < lMin) || (REC__Calorimeter_lv > lMax) ) return 0;
    if ( (REC__Calorimeter_lw < lMin) || (REC__Calorimeter_lw > lMax) ) return 0;
  }


  return 1;
}
/* --------------------------------------------------- */
int ScintillatorBeta(int ipart, double mass)
{
  double BetaCut = 0.01;

  get_REC__Particle(ipart);

  TVector3 P3(REC__Particle_px, REC__Particle_py, REC__Particle_pz);
  TLorentzVector P;
  P.SetVectM(P3, mass);
  
  if (TMath::Abs(P.Beta() - REC__Particle_beta) < BetaCut) return 1;
  return 0;
}
