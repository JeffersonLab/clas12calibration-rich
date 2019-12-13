/* Code to access detector information */


/* ================================================================= */
/* Number of the detectors to match with REC__Particle (up to SVT) */
#define nDetectors 25
#define nLayers 10
#define MaxParticles 100
int indexMap[nDetectors][nLayers][MaxParticles];
void LoadPindexMap(int np);


/* DETECTOR ID, LAYER ID */
#define ScID 12
#define ScLayer1A 1 
#define ScLayer1B 2 
#define ScLayer2 3

#define CaloID 7
#define CaloLayerPcal 1
#define CaloLayerEin 4
#define CaloLayerEout 7

#define HtccID 15
#define LtccID 16

/* ==================================================== */
void LoadPindexMap(int np)
{
  /* Loading map of the pindex to access detector information */
  
  /* memory allocation */
  for (int d=0; d<nDetectors; d++) {
    for (int l=0; l<nLayers; l++) {
      for (int p=0; p<np; p++) {
	indexMap[d][l][p] = -1;
      }
    }
  }
  

  /* Looking at Scintillators */
  for (int d=0; d<REC__Scintillator->getRows(); d++) {
    get_REC__Scintillator(d);
    int pindex = REC__Scintillator_pindex;
    int detector = REC__Scintillator_detector;
    int layer = REC__Scintillator_layer;
    indexMap[detector][layer][pindex] = d;
    //printf("SC:  d=%d  det=%d  layer=%d  pindex=%d  index=%d\n", d, detector, layer, pindex, indexMap[detector][layer][pindex]);

  }

  /* Looking at Calorimeters */
  for (int d=0; d<REC__Calorimeter->getRows(); d++) {
    get_REC__Calorimeter(d);

    int pindex = REC__Calorimeter_pindex;
    int detector = REC__Calorimeter_detector;
    int layer = REC__Calorimeter_layer;

    indexMap[detector][layer][pindex] = d;
    //printf("Calo:  d=%d  det=%d  layer=%d  pindex=%d  index=%d\n", d, detector, layer, pindex, indexMap[detector][layer][pindex]);
  }

  /* Looking at Cherenkov counters */
  for (int d=0; d<REC__Cherenkov->getRows(); d++) {
    get_REC__Cherenkov(d);

    int pindex = REC__Cherenkov_pindex;
    int detector = REC__Cherenkov_detector;
    int layer = 0;

    indexMap[detector][layer][pindex] = d;
    //printf("HTCC:  d=%d  det=%d  layer=%d  pindex=%d  index=%d\n", d, detector, layer, pindex, indexMap[detector][layer][pindex]);

  }

  
  return;
}
