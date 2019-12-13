/* RICH time correction stuff */
/* Time offset correction per channel */
extern int RunNumber;
double TimeOffset[nPMTS][nANODES];
void LoadTimeOffsets();

/* time walk correction per PMT */
#define nTimeWalkPar 4
double TimeWalkParameter[nPMTS][nTimeWalkPar];
void LoadTimeWalkPars();

/* Total correction */
void InitTimeCorrections();
void SetTimeCorrection();
double GetCorrectedTime(int pmt, int anode, double dtime, double duration);


/* ========================================= */
void LoadTimeOffsets()
{
  /* Loading the time offset correction */
  FILE *fIn;
  int sector, pmt, anode;

  /* Reading the corrections */
  TString filename = Form("richTimeOffsets_ccdb_%d.out",RunNumber);
  std::cout <<"correction file: "<< filename << std::endl;
  fIn = fopen(filename.Data(), "r");
  if (fIn) {
    printf("Reading time offset corrections \n");

    for (int p=0; p<nPMTS; p++) {
      
      for (int a=0; a<nANODES; a++) {
	fscanf(fIn, "%d %d %d %lf", &sector, &pmt, &anode, &TimeOffset[p][a]);
	//printf("%d %d %lf\n", p+1, a+1, TimeOffset[p][a]);
      }

    }
    
    fclose(fIn);
  }
  else {
    printf("WARNING: Cannot read time offset corrections, set to 0\n");
  }
  
 
  return;
}
/* --------------------------------- */
void LoadTimeWalkPars()
{
  /* Loading the time walk correction 
     The correction function is made by 2 straight lines 
  */
  FILE *fIn;


  /* Reading the corrections */
  TString filename = Form("richTimeWalks_ccdb_%d.out",RunNumber);
  std::cout <<"correction file: "<< filename << std::endl;
  fIn = fopen(filename.Data(), "r");
  if (fIn) {
    printf("Reading time walk correction\n");
    int sector, pmt, anode;

    for (int p=0; p<nPMTS; p++) {
      fscanf(fIn, "%d %d %d", &sector, &pmt, &anode);
      for (int j=0; j<nTimeWalkPar; j++) {
	fscanf(fIn, "%lf", &TimeWalkParameter[p][j]);
      }
      //printf("p=%d  p[0]=%f  p[1]=%f  p[2]=%f  p[3]=%f  \n", p+1, TimeWalkParameter[p][0], TimeWalkParameter[p][1], TimeWalkParameter[p][2], TimeWalkParameter[p][3]);
      
    }
    fclose(fIn);
  }
  else {
    printf("WARNING: Cannot read time walk correction, set to 0\n");
  }
  
  return;
}
/* ------------------------------------  */
void InitTimeCorrections()
{
  /* Time correction parameter inizializations, all set to 0 */


  for (int p=0; p<nPMTS; p++) {
    /* time offsets */
    for (int a=0; a<nANODES; a++) {
      TimeOffset[p][a] = 0;
    }
    
   
    /* Time walk */
    for (int j=0; j<nTimeWalkPar; j++) {
      TimeWalkParameter[p][j] = 0;
    }
  }



  return;
}
/* ---------------------------------------------- */
void SetTimeCorrection()
{
  /* Inizializing and loading the time corrections */
  InitTimeCorrections();
  LoadTimeOffsets();
  LoadTimeWalkPars();

  return;
}
/* --------------------------------- */
double GetCorrectedTime(int pmt, int anode, double dtime, double duration)
{
  /* full time correction
     dtime = time difference Measured-Calculated
     It works also if dtime is the raw time of the RICH
  */
  
  /* time offset correction */
  double timeCorr1 = dtime - TimeOffset[pmt-1][anode-1];

  /* Time walk correction */
  double D0 = TimeWalkParameter[pmt-1][0];
  double T0 = TimeWalkParameter[pmt-1][1];
  double m1 = TimeWalkParameter[pmt-1][2];
  double m2 = TimeWalkParameter[pmt-1][3];

  
  double f1 = m1 * duration + T0;
  double f1T = m1 * D0 + T0;

  double f2 = m2 * (duration - D0) + f1T;
  double f = f1;
  if (duration > D0) f = f2;

  double timeCorr2 = timeCorr1 - f;
  
  return timeCorr2;
}
/* --------------------------------- */
