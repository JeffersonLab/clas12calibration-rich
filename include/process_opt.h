#include <getopt.h>
/* For time correction */
extern int iTimeCorr;
extern int iCalibratedTime;

/* For RICH event solution */
extern int iRayTracing;

/* Particle ID*/
extern int RichParticleID;

/* For the event start time correction */
extern int iSTtimeCorr;

/* Average DTime range for histograms */
extern double HistoAveDT;

/* Flag for Zero Filed run analysis */
extern int IsZeroField;

/* number of input files */
extern int nFiles;

/* max number of entries to read */
extern int nEntries;

/* run number*/
extern int RunNumber;

/* list of input file names */
extern TString inputFiles[MAXFILES];

/* Name of the application called*/
extern TString processName;

inline void print_help()
{
  std::cout<<"####### Help #########\n"
    "Usage: richTiming [-Options] file1.hipo file2.hipo ...\n\n"
    "  Options:\n"
    "\t[-n | --max-events] <n>              : Set max number of entries to be processed to <n>. Default all\n"
    "\t[-R | --run-number] <R>              : Set run number to <R>. Default 0\n"
    "\t[-T | --time-correction-type] <T>    : Set Time correction type: 0=No corr; 1=Only offset; 2=offset and time-walk; 3=Only time-walk. Default 0. Overwriten by option -C\n"
    "\t[-C | --use-rich-calib-time]         : Use RICH calibrated time. The option -T is forced to 0.\n"
    "\t[-s | --add-event-start-time]        : Add event start time to photons start time. This should already been done in RICH recconstruction process.\n"
    "\t[-r | --use-ray-traced]              : Use ray tracing solution instead of Analytic solution.\n"
    "\t[-P | --use-pid] <pid>               : Use event builder pid <pid>. Default 11 (electrons). Not event builder pid values: -1->AllNeg; +1->AllPos; 0->All; 99->Straight tracks\n"
    "\t[-t | --set-avg-DTime-window] <t>    : Set the average of the DTime window in the histograms to <t> ns. Default: -90.\n"
    "\t[-Z | --analyse-zero-filed-data]     : Analysis of Zero Field data\n"
    "\t[-h | --help]                        : Print this help.\n"
    "#########################"	   <<std::endl;
  exit(0);
}


inline int parse_opt(int argc, char* argv[])
{
  int c;
  int option_index = 0;
  static struct option long_options[] =
  {
    {"max-events",              required_argument, 0, 'n'},
    {"help",                    no_argument, 0,       'h'},
    {"run-number",              required_argument, 0, 'R'},
    {"time-correction",         required_argument, 0, 'T'},
    {"use-rich-calib-time",     no_argument, 0,       'C'},
    {"add-event-start-time",    no_argument, 0,       's'},
    {"use-ray-traced",          no_argument, 0,       'r'},
    {"use-pid",                 required_argument, 0, 'P'},
    {"set-avg-DTime-window",    required_argument, 0, 't'},
    {"analyse-zero-filed-data", no_argument, 0,       'Z'},
    {0, 0, 0, 0}
  };
  
  if(argc==1)
    print_help();
  while ( (c = getopt_long(argc, argv, "n:hR:T:CsrP:t:Z", long_options, &option_index))  != -1)
    switch (c){
    case 'h':
      print_help();
      break;
      
    case 'n':
      nEntries = atoi(optarg);
      printf("Reading %d entries per file\n", nEntries);
      break;
      
    case 'R':
      RunNumber = atoi(optarg);
      printf("Run number: %d\n", RunNumber);
      break;
      
    case 'r':
      iRayTracing = 1;
      printf("Using Ray Tracing solution\n");
      break;
      
    case 's':
      iSTtimeCorr = 1;
      printf("Correcting the event start time by hand\n");
      break;
      
    case 'T':
      iTimeCorr = atoi(optarg);
      printf("Applying time correction with flag %d\n", iTimeCorr);
      break;
      
    case 'C':
      iCalibratedTime = 1;
      printf("Using RICH calibrated time (time correction flag forced to 0)\n");
      break;
      
    case 't':
      HistoAveDT = atof(optarg);
      printf("DTime histogram average: %lf\n", HistoAveDT);
      break;
      
    case 'P':
      RichParticleID = atoi(optarg);
      printf("Using particles with PID %d\n", RichParticleID);
      break;
      
    case 'Z':
      IsZeroField = 1;
      printf("Analysis of Zero Field data\n");
      break;

    case '?':
      if (isprint (optopt))
	fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      break;
      
    default:
      print_help();
      abort();
    }
  
  /*********** non-optional arguments.**************/
  while (optind<argc){
    inputFiles[nFiles++] = argv[optind++];
  }
  
  return 0;
} 
