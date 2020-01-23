/* RICH time correction stuff */
/* Time offset correction per channel */
extern int RunNumber;
double TimeOffset[nPMTS][nANODES];
void LoadTimeOffsets(TString filename = "");

/* time walk correction per PMT */
#define nTimeWalkPar 4
double TimeWalkParameter[nPMTS][nTimeWalkPar];
void LoadTimeWalkPars(TString filename = "");

/* Total correction */
void InitTimeCorrections();
void SetTimeCorrection();
double GetCorrectedTime(int pmt, int anode, double dtime, double duration);


/* ========================================= */
void LoadTimeOffsets(TString filename)
{
  /* Loading the time offset correction */
  std::ifstream fIn;
  std::stringstream ss;
  char aux[500];
  TString line;

  int sector, pmt, anode;

  /* Reading the corrections */
  if (filename=="")
    filename   = Form("richTimeOffsets_ccdb_%d.out",RunNumber);
  std::cout <<"correction file: "<< filename << std::endl;
  fIn.open(filename.Data());
  if (!fIn.is_open()){
    printf("ERROR: Cannot read time offset corrections, set to 0\n");
    exit(1);
  }
  printf("Reading time offset corrections \n");
  while (fIn.good()) {
    fIn.getline(aux,500);
    line = aux;
    if (!(line[0]=='#'|| line.Length()==0)) break;
  }
  for (int p=0; p<nPMTS; p++) {
      for (int a=0; a<nANODES; a++) {
	line=aux;
	ss<<line;
	ss>>sector>>pmt>>anode>>TimeOffset[p][a];
	ss.clear();
	fIn.getline(aux,500);
      }
      
  }
    
  fIn.close(); 
 
  return;
}

/* --------------------------------- */
void LoadTimeWalkPars(TString filename)
{
  /* Loading the time walk correction 
     The correction function is made by 2 straight lines 
  */
  std::ifstream fIn;
  std::stringstream ss;
  char aux[500];
  TString line;
  int sector=-1, pmt=-1, anode=-1;

  /* Reading the corrections */
  if (filename == "")
    filename = Form("richTimeWalks_ccdb_%d.out",RunNumber);

  std::cout <<"correction file: "<< filename << std::endl;
  fIn.open(filename.Data());
  if (!fIn.is_open()){
    printf("ERROR: Cannot read time walk correction, set to 0\n");
    exit(1);
  }

  printf("Reading time walk correction\n");
  while (fIn.good()) {
    fIn.getline(aux,500);
    line = aux;
    if (!(line[0]=='#'|| line.Length()==0)) break;
  }
  for (int p=0; p<nPMTS; p++) {
    line = aux;
    ss<<line;
    ss>>sector>>pmt>>anode;
    for (int j=0; j<nTimeWalkPar; j++) {
      ss>>TimeWalkParameter[p][j];
    }
    ss.clear();
    fIn.getline(aux,500);
  }  
    //printf("p=%d  p[0]=%f  p[1]=%f  p[2]=%f  p[3]=%f  \n", p+1, TimeWalkParameter[p][0], TimeWalkParameter[p][1], TimeWalkParameter[p][2], TimeWalkParameter[p][3]);
  fIn.close();
  
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
