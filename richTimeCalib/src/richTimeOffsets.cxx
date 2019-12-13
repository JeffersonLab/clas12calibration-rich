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
#include "RichTT.h"

double TimeOffset[nPMTS][nANODES];

TObjArray Hlist(0);


int main(int argc, char *argv[])
{
  TBenchmark bench;
  bench.Start("MAIN_TO");
  if (argc<3){
    std::cout<<"root file with histogram and run number needed as first two arguments"<<std::endl;
    exit(1);
  }

  TString fileHist = argv[1];
  int run = atoi(argv[2]);

  bool doCorrectedTime = false;
  if (argc==4){
    std::cout<<"doing time correction"<<std::endl;
    doCorrectedTime = true;
  }


  Char_t fname[100];
  Char_t hname[100];
  Char_t hname2[100];
  Char_t title[100];



  
  /************************************************************/
  /* Map of the counts per PMT */
  double xmin, xmax, ymin, ymax;
  int nbinx, nbiny;
  GetMapBinning(&nbinx, &nbiny, &xmin, &xmax, &ymin, &ymax);

  /**************************************************************/
  /* Rich translation tables */
  SetRichTT();


  /******************************************/
  /* Opening root histogram file */
  TFile *fHist = new TFile(fileHist);
  if (fHist->IsZombie()) {
    cout << "  error: No file " << fileHist << endl;
    return 1;
  }


  /********************************************/
  /* Root canvas */
  TCanvas *c1 = new TCanvas("c1", "", 700, 575);
  c1->Divide(8, 8);

  TCanvas *c2 = new TCanvas("c2", "", 700, 700);
  c2->Divide(6, 6);

  TCanvas *c3 = new TCanvas("c3", "", 700, 700);

  int color;
  //  int marker;
  //double size;


  /*******************************************************/
  /* file pdf */ 
  sprintf(fname, "richTimeOffsets_%d.pdf", run);
  c1->Print(Form("%s[", fname));

  /******************************************************/
  /* text file with time offsets */
  FILE *fOut = fopen(Form("richTimeOffsets_%d.out", run), "w");
  FILE *fOut2 = fopen(Form("richTimeOffsets_ccdb_%d.out", run), "w");

  /********************************************************/
  /* Getting the Histogram */
  sprintf(hname,"hDTime"); 
  if (doCorrectedTime) sprintf(hname,"hDTimeCorr"); 
  TH2F *hDTime = (TH2F*)fHist->Get(hname);
  if (!hDTime) {
    printf("ERROR: Cannot find histogram \n");
    return 1;
  }


  /******************************************/
  /* some summary histograms */

  /* Time offset distribution */
  double Xmin = hDTime->GetYaxis()->GetXmin();
  double Xmax = hDTime->GetYaxis()->GetXmax();
  int nbins = 500;
  TH1F *hDTimeDist = new TH1F("hDTimeDist", "Time offset distribution", nbins, Xmin, Xmax);
  Hlist.Add(hDTimeDist);

  /* Time offset graph */
  TGraph *gDTime = new TGraph(0);
  gDTime->SetNameTitle("gDTime", "Time offset vs channel");
  gDTime->SetMarkerStyle(20);
  gDTime->SetMarkerSize(0.4);
  gDTime->SetMarkerColor(2);
  gDTime->SetLineColor(2);
  
  /* Time offset map */
  TH2F *hToffsetMap = new TH2F("hToffsetMap", "Time offset map", nbinx, xmin, xmax, nbiny, ymin, ymax);
  Hlist.Add(hToffsetMap);

  for (int pmt=1; pmt<=nPMTS; pmt++) {
    sprintf(hname, "hToffsetMap_pmt%d", pmt);
    sprintf(title, "Time offset map, pmt %d\n", pmt);
    TH2F *hToffsetMap_pmt = new TH2F(hname, title, 8, 0.5, 8.5, 8, -8.5, -0.5);
    Hlist.Add(hToffsetMap_pmt);
  }
  
  /********************************************************/
  /* Loop over PMTs */
  int binmax = 0;
  double peak = 0;
  double nevt = 0;
  TLatex *ttx;
  double xl, yl;
  TLine *lToffset;
  double xanode, yanode;
  int tile;
  TH2F *h2;

  double ToffsetMin = 1000;
  double ToffsetMax = -1000;
  
  int npmts = nPMTS;
//  npmts = 10;
  for (int pmt=1; pmt<=npmts; pmt++) {
    if ( ((pmt)%50) == 0) {
      fprintf(stdout, "PMT %d\r", pmt);
      fflush(stdout);
    }

    tile = TileOfPmt[pmt-1];

    /* LOOP over anodes */
    for (Int_t a=0; a<nANODES; a++) {
      
      /* Absolute channel number */
      int c = (pmt-1)*nANODES + a;

      TimeOffset[pmt-1][a] = 0;


      hDTime->ProjectionY("_py", c+1, c+1);
      TH1F *hDTime_c = (TH1F*)gDirectory->GetList()->FindObject(Form("%s_py", hDTime->GetName()));
      if (hDTime_c) {
	sprintf(hname2, "%s_c%d", hDTime->GetName(), c);
	hDTime_c->SetName(hname2);
	
	sprintf(hname2, "#Delta T, PMT %d, Anode %d, Channel %d", pmt, a+1, c);
	hDTime_c->SetTitle(hname2);

	c1->cd(a+1);
	hDTime_c->SetLineWidth(1);
	hDTime_c->SetLineColor(1);

	peak = 0;
	nevt = 0;
	if (hDTime_c->GetEntries()) {
	  //printf("pmt %d  anode %d\n", pmt, a+1);
	  binmax = hDTime_c->GetMaximumBin();
	  for (int b=binmax-2; b<=binmax+2; b++) {
	    peak = peak + hDTime_c->GetBinContent(b)*hDTime_c->GetBinCenter(b);
	    nevt = nevt + hDTime_c->GetBinContent(b);
	    //printf("   bin=%4d   n=%f  t=%f  peak=%f  nevt=%f\n", b, hDTime_c->GetBinContent(b), hDTime_c->GetBinCenter(b), peak/nevt, nevt);
	  }
	  if (nevt) {
	    peak = peak / nevt;
	    if (peak < ToffsetMin) ToffsetMin = peak;
	    if (peak > ToffsetMax) ToffsetMax = peak;
	  }
	}

	//hDTime_c->GetXaxis()->SetRangeUser(-120., -60.);
	hDTime_c->GetXaxis()->SetRangeUser(peak-10., peak+20.);
	hDTime_c->Draw();
	
	color = 2;
	//xl = -95.;
	xl = peak + 3.;
	yl = hDTime_c->GetMaximum()/2.;
	ttx = new TLatex(xl, yl, Form("T_{off} = %6.1f ns", peak));
	ttx->SetTextColor(color);
	ttx->SetTextSize(0.08);
	ttx->Draw("same");
	fprintf(fOut, "%3d  %3d  %2d  %5d   %8.0f  %9.3f\n", pmt, tile, a+1, c, nevt, peak);
	fprintf(fOut2, "%1d %3d  %2d  %9.3f\n", RichSector, pmt, a+1, peak);

	lToffset = new TLine(peak, 0, peak, hDTime_c->GetMaximum());
	lToffset->SetLineColor(color);
	lToffset->SetLineWidth(1.);
	lToffset->SetLineStyle(2);
	lToffset->Draw("same");
	
	//c1->Print(Form("%s", fname));

	/* filling the histograms */
	hDTimeDist->Fill(peak);
	gDTime->SetPoint(gDTime->GetN(), c+1, peak);

	GetCoordinates(pmt, a+1, &xanode, &yanode);
	hToffsetMap->Fill(xanode, yanode, peak);

	sprintf(hname, "hToffsetMap_pmt%d", pmt);
	gDirectory->GetObject(hname, h2);
	GetLocalCoordinates(a+1, &xanode, &yanode);
	h2->Fill(xanode/PixelSize+1, yanode/PixelSize-1, peak);
	//if (pmt == 1) printf("a=%d  x=%f  y=%f\n", a+1, xanode, yanode);
      }
      
    }
    c1->Print(Form("%s", fname));

  }
  c1->cd();
  gStyle->SetOptStat(1111);


  /******************************************/
  /* Summary plots */
  double ToffsetAve = hDTimeDist->GetMean();

  c3->cd();
  gStyle->SetOptStat(111111);
  //hDTimeDist->GetXaxis()->SetRangeUser(ToffsetMin-2, ToffsetMax+2);
  hDTimeDist->GetXaxis()->SetRangeUser(ToffsetAve-20, ToffsetAve+20);
  hDTimeDist->Draw();
  c3->SetLogy();
  c3->Print(Form("%s", fname));
  c3->SetLogy(0);

  c3->cd();
  //gDTime->GetYaxis()->SetRangeUser(ToffsetMin-2, ToffsetMax+2);
  gDTime->GetYaxis()->SetRangeUser(ToffsetAve-10, ToffsetAve+10);
  gDTime->Draw("awp");
  c3->Print(Form("%s", fname));

  
  c3->cd();
  gStyle->SetOptStat(0);
  //hToffsetMap->GetZaxis()->SetRangeUser(ToffsetMin, ToffsetMax);
  hToffsetMap->GetZaxis()->SetRangeUser(ToffsetAve-10, ToffsetAve+10);
  hToffsetMap->Draw("colz");
  c3->Print(Form("%s", fname));

  int iplot = 1;
  for (int pmt=1; pmt<=npmts; pmt++) {
    c2->cd(iplot);

    sprintf(hname, "hToffsetMap_pmt%d", pmt);
    gDirectory->GetObject(hname, h2);
    //h2->GetZaxis()->SetRangeUser(ToffsetMin, ToffsetMax);
    h2->GetZaxis()->SetRangeUser(ToffsetAve-10, ToffsetAve+10);
    h2->Draw("colz");

    
    iplot++;
    if ( (iplot > 36) || (pmt == npmts) ) {
      iplot = 1;
      c2->Print(Form("%s", fname));
      c2->Clear(); 
      c2->Divide(6, 6);
    }
  }


  c2->cd();
  gStyle->SetOptStat(1111);
  
  /******************************************/
  /* Histogram outputs */
  TFile f(Form("richTimeOffsets_%d.root", run), "recreate");
  //Hlist.ls();
  Hlist.Write();
  f.Close();
 

  
  /******************************************/
  c1->Print(Form("%s]", fname));
  c1->Close();
  c2->Close();
  c3->Close();
  fHist->Close();
  fclose(fOut);
  fclose(fOut2);
  bench.Show("MAIN_TO");
  return 0;
}
