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
#include "TLatex.h"
#include "TBenchmark.h"

using namespace std;

/* ================================ */

#include "RichHW.h"
#include "RichGeometry.h"

#define MAX 200

/* ================================ */


/* min number of peak events for the projections */
Double_t nmin = 5;

/* number of RMS for mean and error */
Double_t nRMS = 1.5;

/* ================================== */
/* Time Walk fit */
double fTimeWalk(double *x, double *par);
int npar = 4;

double fTimeWalk3(double *x, double *par);
int npar3 = 3;

double fTimeWalk2(double *x, double *par);
int npar2 = 4;

double dtfit1 = 10.;
double dtfit2 = 100.;

TObjArray Hlist(0);

/* ================================== */
int main (int argc, char *argv[])
{
  TBenchmark bench;
  bench.Start("MAIN_TW");

  if (argc<3){
    std::cout<<"root file with histogram and run number needed as first two arguments"<<std::endl;
    exit(1);
  }

  TString fileHist = argv[1];
  int run = atoi(argv[2]);


  Char_t fname[100];
  Char_t hname[100];
  Char_t hname2[100];
  Char_t title[100];

  
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

  TCanvas *c2 = new TCanvas("c2");
  int nx = 8;
  int ny = 8;
  c2->Divide(nx, ny);

  TCanvas *c3 = new TCanvas("c3");
  c3->Divide(2,2);



 
  /* per legende */
  /*
  Double_t sizeTXT = 0.04;
  Double_t dxLeg = 0.25;
  Double_t x1Leg, x2Leg;
  
  Double_t dyLeg = 0.04;
  Double_t y2Leg, y1Leg;
  x1Leg = 0.65;
  x2Leg = x1Leg + dxLeg;
  y2Leg = 0.9;
  y1Leg = y2Leg - dyLeg;

  */
  Int_t color;
  Int_t marker;
  Double_t size;




  Double_t X[MAX];
  Double_t Y[MAX];
  Double_t Z[MAX];
  Double_t U[MAX];
  //  Double_t S[MAX];

  /*******************************************************/
  /* text output: time walk fit parameters */ 
  sprintf(fname, "richTimeWalks_%d.out", run);
  FILE *fOut = fopen(&fname[0], "w");
  sprintf(fname, "richTimeWalks_ccdb_%d.out", run);
  FILE *fOut2 = fopen(&fname[0], "w");

  /*******************************************************/
  /* file pdf */ 
  sprintf(fname, "richTimeWalks_%d.pdf", run);
  c1->Print(Form("%s[", fname));


  /*******************************************************/
  /* Loop over PMTS */

  /* Duration bins for the analysis */
  int firstbin = 14;
  int lastbin = firstbin + nx*ny;
  double dt;

  /* number of populated bins for one pmt */
  int nbins = 0;


  /* Variables to set the Peak region */
  double x1;
  double x2;


  /* Function to fit the Time Walk */
  TF1 *fTW = new TF1("fTW", fTimeWalk, 10, 100, npar);
  fTW->SetParName(0, "D_{0}");
  fTW->SetParName(1, "T_{0}");
  fTW->SetParName(2, "m_{1}");
  fTW->SetParName(3, "m_{2}");
  fTW->SetLineColor(6);

  //TF1 *fTW3 = new TF1("fTW3", fTimeWalk3, dtfit1, dtfit2, npar3);
  //fTW3->SetParName(0, "D0");
  //fTW3->SetParName(1, "c1");
  //fTW3->SetParName(2, "c2");
  //fTW3->SetLineColor(6);

  /* duration interval for the Time Walk fit */
  dtfit1 = 35;
  dtfit2 = 66;


  double PmtID[nPMTS];
  double E[nPMTS];
  double fD0[nPMTS];
  double fD0u[nPMTS];
  double fT0[nPMTS];
  double fT0u[nPMTS];
  double fM1[nPMTS];
  double fM1u[nPMTS];
  double fM2[nPMTS];
  double fM2u[nPMTS];

  /* Gaussian fit function */
  TF1 *fTimeVsDuration = new TF1("fTimeVsDuration", "gaus", -5, 5);
  fTimeVsDuration->SetLineWidth(1);

  /* PLOTS */
  int iplot = 0;
  
  int npmts = nPMTS;
  //npmts = 10;
  for (int pmt=1; pmt<=npmts; pmt++) {
    if ( ((pmt)%50) == 0) {
      fprintf(stdout, "PMT %d\r", pmt);
      fflush(stdout);
    }


    /* PMT histogram */
    sprintf(hname, "hDTimeCorrVsDuration_Pmt%d", pmt);
    TH2F *hTimeVsDuration = (TH2F*)fHist->Get(hname);
    if (hTimeVsDuration) {

      /* Slice bins */
      iplot = 1;
      nbins = 0;

      for (Int_t b=firstbin; b<lastbin; b++) {
	//for (Int_t b=1; b<=4; b++) {
	dt = hTimeVsDuration->GetXaxis()->GetBinCenter(b);

	
	c2->cd(iplot);


	hTimeVsDuration->ProjectionY("_py", b, b);
	TH1F *hTimeVsDuration_p = (TH1F*)gDirectory->GetList()->FindObject(Form("%s_py", hTimeVsDuration->GetName()));
	if (hTimeVsDuration_p) {
	  sprintf(hname2, "%s_b%d", hTimeVsDuration->GetName(), b);
	  hTimeVsDuration_p->SetName(hname2);
	  
	  sprintf(hname2, "Time, PMT %d, DT=%4.1f", pmt, dt);
	  hTimeVsDuration_p->SetTitle(hname2);
	  
	  hTimeVsDuration_p->Draw();
	  gPad->SetGrid();
	  hTimeVsDuration_p->GetXaxis()->SetLabelOffset(0.02);
	  	
      
	  if (hTimeVsDuration_p->GetEntries()) {
	  
	
	    if (hTimeVsDuration_p->GetMaximum() >= nmin) {

	      /* Mean and RMS in the peak region for gauss fit starting values */
	      x1 = hTimeVsDuration_p->GetBinCenter(hTimeVsDuration_p->GetMaximumBin() - 5);
	      x2 = hTimeVsDuration_p->GetBinCenter(hTimeVsDuration_p->GetMaximumBin() + 5);
	    
	      hTimeVsDuration_p->GetXaxis()->SetRangeUser(x1, x2);

	      X[nbins] = dt;
	      Z[nbins] = 0;
	      Y[nbins] = hTimeVsDuration_p->GetMean();
	      U[nbins] = hTimeVsDuration_p->GetRMS() / TMath::Sqrt(hTimeVsDuration_p->GetEffectiveEntries());
	      //S[nbins] = hTimeVsDuration_p->GetRMS();


	      color = 6;
	  
	      TLine *cut1 = new TLine(x1, 0, x1, hTimeVsDuration_p->GetMaximum());
	      cut1->SetLineColor(color);
	      cut1->Draw("same");
	  
	      TLine *cut2 = new TLine(x2, 0, x2, hTimeVsDuration_p->GetMaximum());
	      cut2->SetLineColor(color);
	      cut2->Draw("same");
	      

	      /* resetting the X range for the plot  */
	      hTimeVsDuration_p->GetXaxis()->SetRangeUser(-15, 25);

	      
	      nbins++;
	    }/* END projection with minimum entries */


	  }

	}


	iplot++;
      }/* END loop over slice bins */
      
      c2->Print(Form("%s", fname));
      
    
      /* --------------------------------------- */
      /* TGraph with mean values */
      marker = 20;
      color = 2;
      size = 0.5;
      TGraphErrors *gTimeVsDuration = new TGraphErrors(nbins, X, Y, Z, U);
      gTimeVsDuration->SetMarkerStyle(marker);
      gTimeVsDuration->SetMarkerColor(color);
      gTimeVsDuration->SetMarkerSize(size);
      gTimeVsDuration->SetLineColor(color);    
          
    
      /* --------------------------------------- */
      /* 2D plot */
      c1->cd();
      gStyle->SetOptStat(0);
      hTimeVsDuration->Draw("colz");
      gTimeVsDuration->Draw("p");
 
      /* Fit of the Time Walk */
      if (nbins >= npar) {
	PmtID[pmt-1] = pmt;
	E[pmt-1] = 0;

	gStyle->SetOptFit(1111);
	/* fit with 2 lines */
	fTW->SetParameter(0, 55.);
	fTW->FixParameter(0, 55.);
	fTW->SetParameter(1, 23);
	fTW->SetParameter(2, -0.5);
	fTW->SetParameter(3, 0.);
	gTimeVsDuration->Fit(fTW, "q0", "", dtfit1, dtfit2);
	fTW->ReleaseParameter(0);
	gTimeVsDuration->Fit(fTW, "q", "", dtfit1, dtfit2);
	
	fD0[pmt-1] = fTW->GetParameter(0);
	fD0u[pmt-1] = fTW->GetParError(0);
	fT0[pmt-1] = fTW->GetParameter(1);
	fT0u[pmt-1] = fTW->GetParError(1);
	fM1[pmt-1] = fTW->GetParameter(2);
	fM1u[pmt-1] = fTW->GetParError(2);
	fM2[pmt-1] = fTW->GetParameter(3);
	fM2u[pmt-1] = fTW->GetParError(3);
	

	/* fit with 2deg poly (but 2-order par is set to 0) and 0 after saturation 
	fTW3->SetParameter(0, 60.);
	fTW3->FixParameter(0, 60.);
	fTW3->SetParameter(1, -0.5);
	fTW3->SetParameter(2, -0.);
	fTW3->FixParameter(2, 0.);
	gTimeVsDuration->Fit(fTW3, "q0", "", dtfit1, dtfit2);
	fTW3->ReleaseParameter(0);
	gTimeVsDuration->Fit(fTW3, "q", "", dtfit1, dtfit2);
	
	fD0[pmt-1] = fTW3->GetParameter(0);
	fD0u[pmt-1] = fTW3->GetParError(0);
	fT0[pmt-1] = -fTW3->GetParameter(1) * fTW3->GetParameter(0);
	fT0u[pmt-1] = fT0[pmt-1] * TMath::Sqrt( TMath::Power((fTW3->GetParError(0)/fTW3->GetParameter(0)), 2) + TMath::Power((fTW3->GetParError(1)/fTW3->GetParameter(1)), 2) );
	fM1[pmt-1] = fTW3->GetParameter(1);
	fM1u[pmt-1] = fTW3->GetParError(1);
	fM2[pmt-1] = 0;
	fM2u[pmt-1] = 0;*/

      }
      else {
	fD0[pmt-1] = 0;
	fD0u[pmt-1] = 0;
	fT0[pmt-1] = 0;
	fT0u[pmt-1] = 0;
	fM1[pmt-1] = 0;
	fM1u[pmt-1] = 0;
	fM2[pmt-1] = 0;
	fM2u[pmt-1] = 0;
      }
     
      c1->SetGrid();
      c1->Print(Form("%s", fname));

      fprintf(fOut, "%3d   %7.3f %7.3f  %7.3f %7.3f  %7.4f %7.4f  %7.4f %7.4f\n", pmt, fD0[pmt-1], fD0u[pmt-1], fT0[pmt-1], fT0u[pmt-1], fM1[pmt-1], fM1u[pmt-1], fM2[pmt-1], fM2u[pmt-1]);
      fprintf(fOut2, "%1d %3d %1d  %7.3f  %7.3f  %7.4f  %7.4f\n", RichSector, pmt, 0, fD0[pmt-1], fT0[pmt-1], fM1[pmt-1], fM2[pmt-1]);

    }/* END TH2F */


    
  }

  c1->cd();
  gStyle->SetOptStat(0);

  /******************************************/
  /* Plot of the time walk fit parameters */
  /******************************************/

    
  /* -------------------------------------- */
  /* Plots vs channel */
  size = 0.5;
  
  /* D0 */
  c3->cd(1);
  sprintf(title, "Time Walk Fit parameter D_{0}");
  TH2F *hD0 = new TH2F("hD0", title, 2, 0.5, 0.5+npmts, 2, 40., 80.);
  hD0->Draw();
  hD0->GetXaxis()->SetTitle("PMT #");
  hD0->GetYaxis()->SetTitle("D_{0} (ns)");
    
  marker = 20;
  color = 4;
  TGraphErrors *gD0 = new TGraphErrors(npmts, PmtID, fD0, E, fD0u);
  gD0->SetNameTitle("gD0", "Time Walk Fit parameter D_{0}");
  Hlist.Add(gD0);
  gD0->SetMarkerStyle(marker);
  gD0->SetMarkerColor(color);
  gD0->SetMarkerSize(size);
  gD0->SetLineColor(color);    
  gD0->Draw("p");
  


  /* T0 */
  c3->cd(2);
  sprintf(title, "Time Walk Fit parameter T_{0}");
  TH2F *hT0 = new TH2F("hT0", title, 2, 0.5, 0.5+npmts, 2, 0., 50.);
  hT0->Draw();
  hT0->GetXaxis()->SetTitle("PMT #");
  hT0->GetYaxis()->SetTitle("T_{0} (ns)");
  
  marker = 20;
  color = 4;
  TGraphErrors *gT0 = new TGraphErrors(npmts, PmtID, fT0, E, fT0u);
  gT0->SetNameTitle("gT0", "Time Walk Fit parameter T_{0}");
  Hlist.Add(gT0);
  gT0->SetMarkerStyle(marker);
  gT0->SetMarkerColor(color);
  gT0->SetMarkerSize(size);
  gT0->SetLineColor(color);    
  gT0->Draw("p");
  


  /* m1 */
  c3->cd(3);
  sprintf(title, "Time Walk Fit parameter m_{1}");
  TH2F *hM1 = new TH2F("hM1", title, 2, 0.5, 0.5+npmts, 2, -1., 0.);
  hM1->Draw();
  hM1->GetXaxis()->SetTitle("PMT #");
  hM1->GetYaxis()->SetTitle("m_{1} (ns)");
  
  marker = 20;
  color = 4;
  TGraphErrors *gM1 = new TGraphErrors(npmts, PmtID, fM1, E, fM1u);
  gM1->SetNameTitle("gM1", "Time Walk Fit parameter m_{1}");
  Hlist.Add(gM1);
  gM1->SetMarkerStyle(marker);
  gM1->SetMarkerColor(color);
  gM1->SetMarkerSize(size);
  gM1->SetLineColor(color);    
  gM1->Draw("p");
  


  /* m2 */
  c3->cd(4);
  sprintf(title, "Time Walk Fit parameter m_{2}");
  TH2F *hM2 = new TH2F("hM2", title, 2, 0.5, 0.5+npmts, 2, -0.5, 0.5);
  hM2->Draw();
  hM2->GetXaxis()->SetTitle("PMT #");
  hM2->GetYaxis()->SetTitle("m_{2}");

  marker = 20;
  color = 4;
  TGraphErrors *gM2 = new TGraphErrors(npmts, PmtID, fM2, E, fM2u);
  gM2->SetNameTitle("gM2", "Time Walk Fit parameter m_{2}");
  Hlist.Add(gM2);
  gM2->SetMarkerStyle(marker);
  gM2->SetMarkerColor(color);
  gM2->SetMarkerSize(size);
  gM2->SetLineColor(color);    
  gM2->Draw("p");


  
  c3->Print(Form("%s", fname));


  
  /* -------------------------------------- */
  /* Plots of distributions */
  c1->cd();
  gStyle->SetOptStat(111111);
    
  /* D0 */
  c3->cd(1);
  sprintf(title, "D_{0} (ns)");
  TH1F *hD0_dist = new TH1F("hD0_dist", title, 100, 40., 80.);
  Hlist.Add(hD0_dist);
  for (int p=0; p<npmts; p++) {
    hD0_dist->Fill(fD0[p]);
  }
  hD0_dist->Draw();
  

  /* T0 */
  c3->cd(2);
  sprintf(title, "T_{0} (ns)");
  TH1F *hT0_dist = new TH1F("hT0_dist", title, 100, 0., 50.);
  Hlist.Add(hT0_dist);
  for (int p=0; p<npmts; p++) {
    hT0_dist->Fill(fT0[p]);
  }
  hT0_dist->Draw();
  
  
  /* M1 */
  c3->cd(3);
  sprintf(title, "m_{1}");
  TH1F *hM1_dist = new TH1F("hM1_dist", title, 100, -1., 0.);
  Hlist.Add(hM1_dist);
  for (int p=0; p<npmts; p++) {
    hM1_dist->Fill(fM1[p]);
  }
  hM1_dist->Draw();
  

  /* M2 */
  c3->cd(4);
  sprintf(title, "m_{2}");
  TH1F *hM2_dist = new TH1F("hM2_dist", title, 100, -0.5, 0.5);
  Hlist.Add(hM2_dist);
  for (int p=0; p<npmts; p++) {
    hM2_dist->Fill(fM2[p]);
  }
  hM2_dist->Draw();
  

  c3->Print(Form("%s", fname));

  
  /******************************************/
  /* Histogram outputs */
  TFile f(Form("richTimeWalks_%d.root", run), "recreate");
  //Hlist.ls();
  Hlist.Write();
  f.Close();
  
  
  /******************************************/
  c1->cd();
  c1->Print(Form("%s]", fname));
  c1->Close();
  c2->Close();
  c3->Close();
  fHist->Close();
  fclose(fOut);
  fclose(fOut2);
  bench.Show("MAIN_TW");
  return 0;
}
/* ---------------------------------------- */
double fTimeWalk(double *x, double *par)
{
  /* Time Vs duration fit
     The function is Two lines 
  */

  double D0 = par[0];
  double T0 = par[1];
  double m1 = par[2];
  double m2 = par[3];

  double f1 = m1 * x[0] + T0;
  double f1T = m1 * D0 + T0;

  double f2 = m2 * (x[0] - D0) + f1T;
  double f = f1;
  if (x[0] > D0) f = f2;

  return f;
}
double fTimeWalk2(double *x, double *par)
{
  /* Time Vs duration fit
     The function is one constant and a 2deg polynomial
  */

  /* asymptotic time */
  double T1 = par[0];
  /* duration saturation value */
  double D0 = par[1];
  double m2 = par[2];
  double c2 = par[3];

  double f2 = T1;
  double f1 = T1 + m2 * (x[0] - D0) + c2 * (x[0] - D0)*(x[0] - D0);

  double f = f1;
  if (x[0] > D0) f = f2;

  return f;
}
double fTimeWalk3(double *x, double *par)
{
  /* Time Vs duration fit
     The function is a 2deg polynomial up to a saturation value, than 0
  */
  
  /* duration saturation value */
  double D0 = par[0];

  double c1 = par[1];
  double c2 = par[2];
  double f1 = c1 * (x[0] - D0) + c2 * (x[0] - D0)*(x[0] - D0);

  double f = f1;
  if (x[0] > D0) f = 0;

  return f;
}
