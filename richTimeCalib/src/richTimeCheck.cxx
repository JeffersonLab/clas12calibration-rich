#include "TF1.h"
#include "TH1.h"
#include "TH2D.h"
#include "TH2I.h"
#include "TH2.h"
#include "TROOT.h"
#include "TRint.h"
#include "TStyle.h"
#include "stdio.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "math.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TBenchmark.h"

using namespace std;

/* ================================ */

#include "RichHW.h"
#include "RichGeometry.h"

#define MAX 200

/* ================================ */
int nmin = 10;

TObjArray Hlist(0);

/* Average values to select on-time hits */
double DTmean = 0;
double DTsigma = 0.7;
double DTnsigma = 2.;


/* ================================== */
int main(int argc, char *argv[])
{

  TBenchmark bench;
  bench.Start("MAIN_TCheck");

  if (argc<3){
    std::cout<<"root file with histogram and run number needed as first two arguments"<<std::endl;
    exit(1);
  }

  TString fileHist = argv[1];
  int run = atoi(argv[2]);


  Char_t fname[100];
  Char_t hname[100];
  Char_t hname2[100];
  //  Char_t title[100];


  /* limits to select problematic channels */
  double SigmaLimit = DTnsigma * DTsigma;
  double MeanLimit0 = DTmean;
  double MeanLimit1 = SigmaLimit;


  
  /************************************************************/
  /* Map of the counts per PMT */
  double xmin, xmax, ymin, ymax;
  int nbinx, nbiny;
  GetMapBinning(&nbinx, &nbiny, &xmin, &xmax, &ymin, &ymax);


  /******************************************/
  /* Opening root histogram file */
  TFile *fHist = new TFile(fileHist);
  if (fHist->IsZombie()) {
    cout << "  error: No file " << fileHist << endl;
    return 1;
  }


  /********************************************/
  /* Root canvas */
  TCanvas *c1 = new TCanvas("c1");
   
  /* per legende */
  /*
  double sizeTXT = 0.04;
  double dxLeg = 0.25;
  double x1Leg, x2Leg;
  
  double dyLeg = 0.04;
  double y2Leg, y1Leg;

  x1Leg = 0.65;
  x2Leg = x1Leg + dxLeg;
  y2Leg = 0.9;
  y1Leg = y2Leg - dyLeg;
  */

  int color;
  int marker;
  double size;

  /*
  double X[MAX];
  double Y[MAX];
  double Z[MAX];
  double U[MAX];
  double S[MAX];
  */

  /*******************************************************/
  /* text output with problematic channels */ 
  sprintf(fname, "richTimeCheck_%d.out", run);
  FILE *fOut = fopen(&fname[0], "w");
  sprintf(fname, "richTimeCheck_ccdb_%d.out", run);
  FILE *fOut2 = fopen(&fname[0], "w");


  /*******************************************************/
  /* file pdf */ 
  sprintf(fname, "richTimeCheck_%d.pdf", run);
  c1->Print(Form("%s[", fname));

  /* =============================================== */
  /* Gaussian fit function */
  TF1 *fTimeVsDuration = new TF1("fTimeVsDuration", "gaus", -5, 5);
  fTimeVsDuration->SetLineWidth(1);

  
  /* =================== */
  /* 2D plots of Delta T */

  /* no correction */
  sprintf(hname, "hDTime");
  TH2F *hDTime = (TH2F*)fHist->Get(hname);

  /* with correction */
  sprintf(hname, "hDTimeCorr");
  TH2F *hDTimeCorr = (TH2F*)fHist->Get(hname);

  
  /* =================== */
  /* 2D plots of Delta L */
  //sprintf(hname, "hDLenCorr");
  //  TH2F *hDLenCorr = (TH2F*)fHist->Get(hname);

  /* =================================== */
  /* Maps after the corrections */

  /* Time peak map */
  TH2F *hToffsetMap = new TH2F("hToffsetMap", "Time, peak position map (ns)", nbinx, xmin, xmax, nbiny, ymin, ymax);
  Hlist.Add(hToffsetMap);
  
  /* Gauss mean map */
  TH2F *hMeanMap = new TH2F("hMeanMap", "Time, gauss mean map (ns)", nbinx, xmin, xmax, nbiny, ymin, ymax);
  Hlist.Add(hMeanMap);
  
  /* Gauss sigma map */
  TH2F *hSigmaMap = new TH2F("hSigmaMap", "Time, gauss sigma map (ns)", nbinx, xmin, xmax, nbiny, ymin, ymax);
  Hlist.Add(hSigmaMap);
  
  /* Number of events map */
  TH2F *hNevtMap = new TH2F("hNevtMap", "Number of events map", nbinx, xmin, xmax, nbiny, ymin, ymax);
  Hlist.Add(hNevtMap);


  /* =================================== */
  /* Distributions after the corrections */
  double dtmin = -10;
  double dtmax = 10;
  double ndt = 200;

  TH1F *hToffsetDist = new TH1F("hToffsetDist", "Time, peak position distribution (ns)", ndt, dtmin, dtmax);
  Hlist.Add(hToffsetDist);

  TH1F *hMeanDist = new TH1F("hMeanDist", "Time, gauss mean distribution (ns)", ndt, dtmin, dtmax);
  Hlist.Add(hMeanDist);

  TH1F *hSigmaDist = new TH1F("hSigmaDist", "Time, gauss sigma distribution (ns)", ndt, 0, dtmax);
  Hlist.Add(hSigmaDist);

  double nmax = 5000;
  TH1F *hNevtDist = new TH1F("hNevtDist", "Number of events per channel", 200, 0, nmax);
  Hlist.Add(hNevtDist);

  TGraph *gMeanVsChannel = new TGraph;
  gMeanVsChannel->SetNameTitle("gMeanVsChannel", "Gaussian mean vs channel number");
  Hlist.Add(gMeanVsChannel);

  TGraph *gSigmaVsChannel = new TGraph;
  gSigmaVsChannel->SetNameTitle("gSigmaVsChannel", "Gaussian sigma vs channel number");
  Hlist.Add(gSigmaVsChannel);

  
  /* =================================== */
  /* Scatter plots vs number of events */
  TGraph *gMeanVsNevt = new TGraph;
  gMeanVsNevt->SetNameTitle("gMeanVsNevt", "Gaussian mean vs Number of events");
  Hlist.Add(gMeanVsNevt);

  TGraph *gSigmaVsNevt = new TGraph;
  gSigmaVsNevt->SetNameTitle("gSigmaVsNevt", "Gaussian sigma vs Number of events");
  Hlist.Add(gSigmaVsNevt);

  /* =================================== */
  double peak;
  int nevt;
  double xanode, yanode;
  double x1, x2;
  double ToffsetMin = 1000;
  double ToffsetMax = -1000;

  int nDeadChannels = 0;
  int nLowStatChannels = 0;
  int nBadPeaks = 0;
  
  fprintf(fOut, "-> Channels with bad timing\n");
  
  int npmts = nPMTS;
  //npmts = 10;
  for (int pmt=1; pmt<=npmts; pmt++) {
    if ( ((pmt)%50) == 0) {
      fprintf(stdout, "PMT %d\r", pmt);
      fflush(stdout);
    }

    /* LOOP over anodes */
    for (int a=0; a<nANODES; a++) {
      
      /* Absolute channel number */
      int c = (pmt-1)*nANODES + a;

      hDTimeCorr->ProjectionY("_py", c+1, c+1);
      TH1F *hDTimeCorr_c = (TH1F*)gDirectory->GetList()->FindObject(Form("%s_py", hDTimeCorr->GetName()));
      if (hDTimeCorr_c) {
	sprintf(hname2, "%s_c%d", hDTimeCorr->GetName(), c);
	hDTimeCorr_c->SetName(hname2);
	
	sprintf(hname2, "#Delta T, PMT %d, Anode %d, Channel %d", pmt, a+1, c);
	hDTimeCorr_c->SetTitle(hname2);

	peak = hDTimeCorr_c->GetBinCenter(hDTimeCorr_c->GetMaximumBin());
	nevt = hDTimeCorr_c->GetBinContent(hDTimeCorr_c->GetMaximumBin());
	GetCoordinates(pmt, a+1, &xanode, &yanode);
	hToffsetMap->Fill(xanode, yanode, peak);
	hToffsetDist->Fill(peak);
	hNevtDist->Fill(hDTimeCorr_c->GetEntries());
	hNevtMap->Fill(xanode, yanode, hDTimeCorr_c->GetEntries());
	
	/* Gaussian fit */
	double ChannelMean = 0;
	double ChannelSigma = 0;
	if (hDTimeCorr_c->GetEntries() > nmin) {
	  x1 = peak - 2;
	  x2 = peak + 2;
	  fTimeVsDuration->SetParameter(0, hDTimeCorr_c->GetMaximum());
	  fTimeVsDuration->SetParameter(1, peak);
	  fTimeVsDuration->SetParameter(2, 0.7);
	  hDTimeCorr_c->Fit("fTimeVsDuration", "q", "", x1, x2);
	  hMeanMap->Fill(xanode, yanode, fTimeVsDuration->GetParameter(1));
	  hSigmaMap->Fill(xanode, yanode, TMath::Abs(fTimeVsDuration->GetParameter(2)));
	  hMeanDist->Fill(fTimeVsDuration->GetParameter(1));
	  hSigmaDist->Fill(TMath::Abs(fTimeVsDuration->GetParameter(2)));

	  gMeanVsChannel->SetPoint(gMeanVsChannel->GetN(), (float)c, fTimeVsDuration->GetParameter(1));
	  gSigmaVsChannel->SetPoint(gSigmaVsChannel->GetN(), (float)c, TMath::Abs(fTimeVsDuration->GetParameter(2)));

	  gMeanVsNevt->SetPoint(gMeanVsNevt->GetN(), hDTimeCorr_c->GetEntries(), fTimeVsDuration->GetParameter(1));
	  gSigmaVsNevt->SetPoint(gSigmaVsNevt->GetN(), hDTimeCorr_c->GetEntries(), TMath::Abs(fTimeVsDuration->GetParameter(2)));
	  ChannelMean = fTimeVsDuration->GetParameter(1);
	  ChannelSigma = fTimeVsDuration->GetParameter(2);
	  
	  /* Problematic channels */
	  //if ( (TMath::Abs(fTimeVsDuration->GetParameter(2)) > SigmaLimit) ||
	  //   (TMath::Abs(fTimeVsDuration->GetParameter(1)-MeanLimit0) > MeanLimit1) ) {
	  if ( (TMath::Abs(fTimeVsDuration->GetParameter(2)) > SigmaLimit) ||
	       (TMath::Abs(fTimeVsDuration->GetParameter(1)-MeanLimit0) > MeanLimit1) ) {
	    fprintf(fOut, "%3d %2d %5d  %6d  %6.2f  %6.2f   %6.2f  %6.2f\n", pmt, a+1, c, (int)hDTimeCorr_c->GetEntries(), fTimeVsDuration->GetParameter(1), fTimeVsDuration->GetParError(1), TMath::Abs(fTimeVsDuration->GetParameter(2)), fTimeVsDuration->GetParError(2));
	    nBadPeaks++;

	    /*plotting the problematic channel */
	    c1->cd();
	    gStyle->SetOptStat(111111);
	    gStyle->SetOptFit(1111);
	    hDTimeCorr_c->Draw();
	    c1->Print(Form("%s", fname));
	    
	  }
	}
	else {
	  hMeanMap->Fill(xanode, yanode, -10.);
	  hSigmaMap->Fill(xanode, yanode, 0);

	  if (hDTimeCorr_c->GetEntries()) nLowStatChannels++;
	  else nDeadChannels++;
	}

	fprintf(fOut2, "%1d %3d %1d  %7.4f  %7.4f\n", RichSector, pmt, a+1, ChannelMean, ChannelSigma);
	
	if (nevt) {
	  if (peak < ToffsetMin) ToffsetMin = peak;
	  if (peak > ToffsetMax) ToffsetMax = peak;
	}
      }

      
    }/* END loop over anodes */
  }/* END loop over pmts */

  /* Coloring the background of the maps */
  for (int ix=1; ix<=hToffsetMap->GetXaxis()->GetNbins(); ix++) {
    double x = hToffsetMap->GetXaxis()->GetBinCenter(ix);
    for (int iy=1; iy<=hToffsetMap->GetYaxis()->GetNbins(); iy++) {
      double y = hToffsetMap->GetYaxis()->GetBinCenter(iy);
      if (hToffsetMap->GetBinContent(ix, iy) == 0) {
	hToffsetMap->Fill(x, y, -10);
	hMeanMap->Fill(x, y, -10);
      }
    }
  }

  fprintf(fOut, "Total number: %d\n", nBadPeaks);

  
  printf("ToffsetMin=%lf   ToffsetMax=%lf\n", ToffsetMin, ToffsetMax);
  printf("Number of dead channels: %d\n", nDeadChannels);
  printf("Number of channels with less than %d events: %d\n", nmin, nLowStatChannels);
  printf("Total number of channel with bad timing: %d\n", nBadPeaks);

  /* ============================ */
  /* PLOTS of the time distributions */
  c1->cd(1);
  gStyle->SetOptStat(0);

  /* no correction */
  c1->SetLogz();
  hDTime->Draw("colz");
  c1->Print(Form("%s", fname));

  /* with correction */
  c1->SetLogz();
  hDTimeCorr->Draw("colz");
  c1->Print(Form("%s", fname));

  /* Delta L */
  //c1->SetLogz();
  //hDLenCorr->Draw("colz");
  //c1->Print(Form("%s", fname));
  
  c1->SetLogz(0);

  
  /* ============================ */
  /* PLOTS of the maps */
  
  c1->cd();
  gStyle->SetOptStat(0);

  hToffsetMap->GetZaxis()->SetRangeUser(-2, 2);
  hToffsetMap->Draw("colz");
  c1->Print(Form("%s", fname));
  

  hMeanMap->GetZaxis()->SetRangeUser(-2, 2);
  hMeanMap->Draw("colz");
  c1->Print(Form("%s", fname));
  

  hSigmaMap->GetZaxis()->SetRangeUser(0, 2);
  hSigmaMap->Draw("colz");
  c1->Print(Form("%s", fname));
  
  double nnn = 2. * hNevtDist->GetMean();
  hNevtMap->GetZaxis()->SetRangeUser(0, nnn);
  hNevtMap->Draw("colz");
  c1->Print(Form("%s", fname));


  /* ============================ */
  /* PLOTS of the distributions */
  
  c1->cd(1);
  gStyle->SetOptStat(111111);
  c1->SetLogy();

  hToffsetDist->Draw();
  hToffsetDist->GetXaxis()->SetTitle("Peak position (ns)");
  c1->Print(Form("%s", fname));

  hMeanDist->Draw();
  hMeanDist->GetXaxis()->SetTitle("Peak mean (ns)");
  c1->Print(Form("%s", fname));
  fprintf(fOut, "Gaussian means: average=%6.2f   RMS=%6.2f\n", hMeanDist->GetMean(), hMeanDist->GetRMS());

  hSigmaDist->Draw();
  hSigmaDist->GetXaxis()->SetTitle("Peak sigma (ns)");
  c1->Print(Form("%s", fname));
  fprintf(fOut, "Gaussian sigma: average=%6.2f   RMS=%6.2f\n", hSigmaDist->GetMean(), hSigmaDist->GetRMS());
  

  hNevtDist->Draw();
  hNevtDist->GetXaxis()->SetTitle("Number of events per channel");
  c1->Print(Form("%s", fname));
  fprintf(fOut, "N. of events: average=%6.2f   RMS=%6.2f\n", hNevtDist->GetMean(), hNevtDist->GetRMS());


  
  c1->cd();
  c1->SetLogy(0);

  size = 0.4;
  marker = 20;
  color = 4;

  gMeanVsChannel->SetMarkerStyle(marker);
  gMeanVsChannel->SetMarkerSize(size);
  gMeanVsChannel->SetMarkerColor(color);
  gMeanVsChannel->Draw("awp");
  gMeanVsChannel->GetXaxis()->SetTitle("channel number");
  gMeanVsChannel->GetYaxis()->SetTitle("Peak mean (ns)");
  gMeanVsChannel->GetXaxis()->SetLimits(-0.5, nPMTS*nANODES-0.5);
  gMeanVsChannel->GetYaxis()->SetRangeUser(dtmin, dtmax);
  c1->Print(Form("%s", fname));

  gSigmaVsChannel->SetMarkerStyle(marker);
  gSigmaVsChannel->SetMarkerSize(size);
  gSigmaVsChannel->SetMarkerColor(color);
  gSigmaVsChannel->Draw("awp");
  gSigmaVsChannel->GetXaxis()->SetTitle("channel number");
  gSigmaVsChannel->GetYaxis()->SetTitle("Peak sigma (ns)");
  gSigmaVsChannel->GetXaxis()->SetLimits(-0.5, nPMTS*nANODES-0.5);
  gSigmaVsChannel->GetYaxis()->SetRangeUser(0, dtmax);
  c1->Print(Form("%s", fname));



  /* ============================ */
  /* Scatter plots */
  size = 0.2;
  marker = 20;
  color = 2;
  double smax = 5;

  c1->cd();
  c1->SetLogy(0);

  /* Mean vs number of events */
  TH2F *hMeanVsNevt = new TH2F("hMeanVsNevt", "Gaussian mean vs Number of events", 2, 0., nmax, 2, -smax, smax);
  hMeanVsNevt->Draw();
  hMeanVsNevt->GetXaxis()->SetTitle("Number of events");
  hMeanVsNevt->GetYaxis()->SetTitle("Gaussian mean (ns)");
  gStyle->SetOptStat(0);
  
  gMeanVsNevt->SetMarkerStyle(marker);
  gMeanVsNevt->SetMarkerSize(size);
  gMeanVsNevt->SetMarkerColor(color);
  gMeanVsNevt->Draw("p");
  //gMeanVsNevt->GetXaxis()->SetTitle("Number of events");
  //gMeanVsNevt->GetYaxis()->SetTitle("Gaussian mean (ns)");
  c1->SetGrid();


  TLine *lMeanVsNevt1 = new TLine(0, MeanLimit0+MeanLimit1, nmax, MeanLimit0+MeanLimit1);
  lMeanVsNevt1->SetLineColor(4);
  lMeanVsNevt1->SetLineWidth(2);
  lMeanVsNevt1->Draw("same");

  TLine *lMeanVsNevt2 = new TLine(0, MeanLimit0-MeanLimit1, nmax, MeanLimit0-MeanLimit1);
  lMeanVsNevt2->SetLineColor(4);
  lMeanVsNevt2->SetLineWidth(2);
  lMeanVsNevt2->Draw("same");

  
  c1->Print(Form("%s", fname));

  /* Sigma Vs number of events */
  TH2F *hSigmaVsNevt = new TH2F("hSigmaVsNevt", "Gaussian sigma vs Number of events", 2, 0., nmax, 2, 0, smax);
  hSigmaVsNevt->Draw();
  hSigmaVsNevt->GetXaxis()->SetTitle("Number of events");
  hSigmaVsNevt->GetYaxis()->SetTitle("Gaussian sigma (ns)");
  gStyle->SetOptStat(0);

  gSigmaVsNevt->SetMarkerStyle(marker);
  gSigmaVsNevt->SetMarkerSize(size);
  gSigmaVsNevt->SetMarkerColor(color);
  gSigmaVsNevt->Draw("p");
  //gSigmaVsNevt->GetXaxis()->SetTitle("Number of events");
  //gSigmaVsNevt->GetYaxis()->SetTitle("Gaussian sigma (ns)");

  TLine *lSigmaVsNevt = new TLine(0, SigmaLimit, nmax, SigmaLimit);
  lSigmaVsNevt->SetLineColor(4);
  lSigmaVsNevt->SetLineWidth(2);
  lSigmaVsNevt->Draw("same");
  c1->SetGrid();

  c1->Print(Form("%s", fname));

  
  printf("N. of events per channel: mean=%6.0f\n", hNevtDist->GetMean());
  printf("Peak Position: mean=%6.2f  RMS=%6.2f ns\n", hToffsetDist->GetMean(), hToffsetDist->GetRMS());
  printf("Gauss fit: <mean>=%6.2f  <sigma>=%6.2f ns\n", hMeanDist->GetMean(), hSigmaDist->GetMean());
    
  /******************************************/
  /* Histogram outputs */
  TFile f(Form("richTimeCheck_%d.root", run), "recreate");
  //Hlist.ls();
  Hlist.Write();
  f.Close();

  /******************************************/
  c1->Print(Form("%s]", fname));
  c1->Close();
  fHist->Close();
  fclose(fOut);
  fclose(fOut2);
  bench.Show("MAIN_TCheck");
  return 0;
}
