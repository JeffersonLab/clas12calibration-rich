#include <getopt.h>
/* For time correction */
extern int iTimeCorr;
extern int iCalibratedTime;
extern int iTimeCorrFast;

/* For RICH event solution */
extern int iRayTracing;

/* Particle ID*/
extern int RichParticleID;

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

/*timewalk parameters file*/
extern TString timewalk_file;

/*timeoffset parameters file*/
extern TString timeoffset_file;

inline void print_help()
{
  std::cout<<"####### Help #########\n"
    "Usage: richTiming [-Options] file1.hipo file2.hipo ...\n\n"
    "  Options:\n"
    "\t[-n | --max-events] <n>              : Set max number of entries to be processed to <n>. Default all\n"
    "\t[-R | --run-number] <R>              : Set run number to <R>. Default 0\n"
    "\t[-T | --time-correction-type] <T>    : Set the time correction type to be loaded: 0=No corr; 1=Only time offset; 2=time offset and time-walk; 3=only timewalk. Default 0. Overwriten by option -C\n"
    "\t[-C | --use-rich-calib-time]         : Use RICH calibrated time. The option -T is forced to 0.\n"
    "\t[-W | --timewalk-file] <file>        : use timewalk parameters in <file>. Option -C will be neglected.\n"
    "\t[-O | --timeoffset-file] <file>      : use timeoffset parameters in <file>. Option -C will be neglected.\n"
    "\t[-r | --use-ray-traced]              : Use ray tracing solution instead of Analytic solution.\n"
    "\t[-P | --use-pid] <pid>               : Use event builder pid <pid>. Default 11 (electrons). Not event builder pid values: -1->AllNeg; +1->AllPos; 0->All;\n"
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
    {"timewalk-file",           required_argument, 0, 'W'},
    {"timeoffset-file",         required_argument, 0, 'O'},
    {"use-ray-traced",          no_argument, 0,       'r'},
    {"use-pid",                 required_argument, 0, 'P'},
    {0, 0, 0, 0}
  };
  
  if(argc==1)
    print_help();
  while ( (c = getopt_long(argc, argv, "n:hR:T:CsrP:W:O:t:Z", long_options, &option_index))  != -1)
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
      
    case 'T':
      iTimeCorr = atoi(optarg);
      printf("Applying time correction with flag %d\n", iTimeCorr);
      break;
      
    case 'C':
      iCalibratedTime = 1;
      printf("Using RICH calibrated time (time correction flag forced to 0)\n");
      break;

    case 'W':
      timewalk_file = optarg;
      printf("timewalk parameters file to be used: %s.\n",optarg);
      break;

    case 'O':
      timeoffset_file = optarg;
      printf("timeoffset parameters file to be used: %s.\n",optarg);
      break;
      
    case 'P':
      RichParticleID = atoi(optarg);
      printf("Using particles with PID %d\n", RichParticleID);
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
