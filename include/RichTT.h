/* Rich translation tables */
#include <cstdlib>
#include "TString.h"

void SetRichTT();

void SetPmtTile(const char *fMap);
int TileOfPmt[nPMTS];
int PmtOfTile[nTILES][nASICS];
int SlotOfPmt[nPMTS];
int FiberOfPmt[nPMTS];
int AsicOfPmt[nPMTS];

void SetMarocAnode(const char *fMap);
int MarocOfAnode[nANODES];

int GetTrunkNumber(int slot, int fiber);

/**********************************************/
void SetRichTT()
{
  TString file = "SspRich_mapFIBER2PMT_sortbyPMT.txt";
  SetPmtTile(file.Data());

  file = "SspRich_mapCHANNEL2PIXEL.txt";
  SetMarocAnode(file);

  return;
}
/* ----------------------------------------- */
void SetPmtTile(const char *fMap)
{
  FILE *fIn = fopen(fMap, "r");
  if (fIn) {
    printf("READING file %s\n", fMap);

    char str[200];
    fgets(str, sizeof(str), fIn);
    fgets(str, sizeof(str), fIn);
    fgets(str, sizeof(str), fIn);

    int pmt, tile, asic;
    int slot, fiber;
    while (fscanf(fIn, "%d %d %d %d %d ", &slot, &fiber, &asic, &pmt, &tile) != EOF) {
      TileOfPmt[pmt-1] = tile;
      SlotOfPmt[pmt-1] = slot;
      FiberOfPmt[pmt-1] = fiber;
      AsicOfPmt[pmt-1] = asic;

      PmtOfTile[tile-1][asic] = pmt;
    }

    fclose(fIn);
  }
  else {
    printf("ERROR: Cannot read TT PMT-tile from file %s\n", fMap);
  }

  
  return;
}
/* ------------------------------------- */
void SetMarocAnode(const char *fMap)
{
  FILE *fIn = fopen(fMap, "r");
  if (fIn) {
    printf("READING file %s\n", fMap);

    char str[200];
    fgets(str, sizeof(str), fIn);
    fgets(str, sizeof(str), fIn);
    fgets(str, sizeof(str), fIn);

    int maroc, anode;
    while (fscanf(fIn, "%d %d ", &maroc, &anode) != EOF) {
      MarocOfAnode[anode-1] = maroc;
    }    

    fclose(fIn);
  }
  else {
    printf("ERROR: Cannot read TT MAROC-anode from file %s\n", fMap);
  }


}
/* ------------------------------------------- */
int GetTrunkNumber(int slot, int fiber)
{
  /* One trunk has 12 MTP (plugged to the SSP) and 12x4=48 fibers (plugged to the FPGA)
     MTP plugging in the SSPs:
     trunk 1 -> slot 3 (0 to 7) + slot 4 (0 to 3)
     trunk 2 -> slot 4 (4 to 7) + slot 5 (0 to 7)
     trunk 3 -> slot 6 (0 to 7) + slot 7 (0 to 3)

     One MTP has 4 fibers
  */
  int trunk = -1;
  

  int mtp = fiber / 4;
  int nn = (slot - 3) * 8 + mtp;
  trunk = nn / nMTPS;
  //printf(" slot=%d  fiber=%d   mtp=%d   nn=%d  trunk=%d\n", slot, fiber, mtp, nn, trunk);
  
  return trunk;
}

