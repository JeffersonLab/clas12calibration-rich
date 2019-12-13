/* define the position of the PMT as 391 8x8 matrix 
   units are mm
*/


#define PixelSize 6
#define nPixelRows 8
#define nPixelColumns 8
#define nPixels 64
#define nPmts 391
#define nChannels 25024

#define PmtClearance 0.

#define nPmtRows 23
#define nPmtTotal 391
#define nPmtsFirstRow 6
Int_t FirstPmtOfTheRow[nPmtRows];

/* ------------------------------------- */
int RichSector = 4;


/* ------------------------------------- */
void SetGeometry();
Int_t GetPmtRow(Int_t pmt);
Int_t GetPmtColumn(Int_t pmt, Int_t row);
void GetRowAnode1(Int_t RowID, Double_t *x1, Double_t *y1);
void GetLocalCoordinates(Int_t anode, Double_t *localx, Double_t *localy);
void GetCoordinates(Int_t pmt, Int_t anode, Double_t *x, Double_t *y);
Int_t GetNColumns(Int_t row);
void GetRowCol(int anode, int *row, int *col);
void GetMapBinning(int *nbinx, int *nbiny, double *xmin, double *xmax, double *ymin, double *ymax);

void PrintV3(TVector3 P, const char *name);

/* Function to project a track on a plane */
TVector3 GetProjectedTrackDir(TVector3 Hit1, TVector3 Hit2, TVector3 Vplane, Double_t Cplane);

/* ------------------------------------------- */
void SetGeometry()
{

  /* Setting the first PMT ID of the row */
  FirstPmtOfTheRow[0] = 1;
  for (Int_t r=1; r<nPmtRows; r++) {
    FirstPmtOfTheRow[r] = FirstPmtOfTheRow[r-1] + nPmtsFirstRow + r-1;
  }

  //for (Int_t r=0; r<nPmtRows; r++) cout << "r=" << r << "  id=" << FirstPmtOfTheRow[r] << endl;


}
/* ------------------------------------------- */
Int_t GetPmtRow(Int_t pmt)
{
  Int_t RowID = nPmtRows;
  for (Int_t r=0; r<nPmtRows; r++) {
    //cout << "--> r=" << r << "  pmt1=" << FirstPmtOfTheRow[r] << endl;
    if (pmt < FirstPmtOfTheRow[r]) {
      RowID = r;
      //cout << "   found rowID= " << RowID << endl;
      break;
    }
  }
  //printf("pmt %d   row=%d\n", pmt, RowID);

  return RowID;
}
/* -------------------------------------------- */
Int_t GetPmtColumn(Int_t pmt, Int_t row)
{
  Int_t ColumnID = 1 + pmt - FirstPmtOfTheRow[row-1];

  /* number of columns of this row */
  int nCols = GetNColumns(row);
  ColumnID = 1 + nCols - ColumnID;

  //printf("pmt %d   col=%d  nCol=%d\n", pmt, ColumnID, nCols);


  return ColumnID;
}
/* -------------------------------------------- */
Int_t GetNColumns(Int_t row)
{
  /* return the number of PMTs in the row */
  
  int nCols = FirstPmtOfTheRow[row] - FirstPmtOfTheRow[row-1];
  if (row == nPmtRows) nCols = nPmtTotal - FirstPmtOfTheRow[row-1] + 1;

  return nCols;
}
/* -------------------------------------------- */
void GetRowAnode1(Int_t RowID, Double_t *x1, Double_t *y1)
{
  /* Return the position of anode 1 of the leftmost pmt of the row 
     Anode 1 is top left pixel of the PMT 
  */
  double anode1x = -(RowID - 1) * 0.5 * (nPixelColumns * PixelSize + PmtClearance);
  double anode1y =  RowID * (nPixelColumns * PixelSize + PmtClearance);
  
  (*x1) = anode1x;
  (*y1) = anode1y;
  

  return;
}
/* -------------------------------- */
void GetLocalCoordinates(Int_t anode, Double_t *localx, Double_t *localy)
{
  /* anode start from 1 
     column is from 1 to 8
     row is from -1 to -8
     anode 1 is in column 1 and row -1
     anode 64 is in column 8 and row -8
  */

  /* row and column of the anode */
  int column = 1 + (anode-1)%nPixelRows;
  int row = -(1 + (anode-1)/nPixelRows);

  //cout << "anode=" << anode << "  row=" << row << "  col=" << column << endl;

  (*localx) = (column - 1) * PixelSize;
  (*localy) = (row + 1) * PixelSize;


  return;
}
/* --------------------------------------- */
void GetRowCol(int anode, int *row, int *col)
{
  /* Returns row and column of the anode 
     anode 1 is top left: row=8 col=1
     anode 64 is bottom right: row=1 col=8 
  */

  *row = 1 + (anode-1)%8;

  *col = 1 + (anode-1)/8;
  *col = 9 - *col;

  
  return;
}
/* ------------------------------------ */
void GetCoordinates(Int_t pmt, Int_t anode, Double_t *x, Double_t *y)
{
  /* Finding the row and column of the pmt */
  Int_t RowID = GetPmtRow(pmt);
  Int_t ColumnID = GetPmtColumn(pmt, RowID);

  /* number of columns of this row */
  //  int nCols = GetNColumns(RowID);
  
  /* Finding the position of the first anode of the row */
  Double_t x1, y1;
  GetRowAnode1(RowID, &x1, &y1);

  //if (anode == 1) cout << "pmt=" << pmt << "  rowID=" << RowID << "  colID=" << ColumnID << "  nCols=" << nCols << "  x1=" << x1 << "  y1=" << y1 << endl;

  /* finding the local coordinates of the anode in the pmt */
  Double_t localx, localy;
  GetLocalCoordinates(anode, &localx, &localy);
  

  (*x) = localx + x1 + (ColumnID - 1) * (nPixelColumns * PixelSize + PmtClearance);
  (*y) = localy + y1;
  //if (anode == 1) cout << "  localx=" << localx << "   localy=" << localy << "   x=" << *x << "  y=" << *y << endl;

  return;
}
/* ------------------------------------------- */
void GetMapBinning(int *nbinx, int *nbiny, double *xmin, double *xmax, double *ymin, double *ymax)
{
  
  SetGeometry();
  Double_t x, y;

  //GetCoordinates(1, 64, &x, &y);
  GetCoordinates(6, 64, &x, &y);
  *ymin = y - PixelSize/2.;
  *ymin = y - PixelSize/2. - 4*PixelSize;
  
  //GetCoordinates(364, 64, &x, &y);
  GetCoordinates(391, 1, &x, &y);
  *xmin = x - PixelSize/2.;
  *xmin = x - PixelSize/2. - 4*PixelSize;

  //GetCoordinates(391, 1, &x, &y);
  GetCoordinates(364, 64, &x, &y);
  *xmax = x + PixelSize/2.;
  *xmax = x + PixelSize/2. + 4*PixelSize;
  
  GetCoordinates(364, 1, &x, &y);
  *ymax = y + PixelSize/2.;
  *ymax = y + PixelSize/2. + 4*PixelSize;
  
  *nbinx = (*xmax - *xmin) / PixelSize;
  *nbiny = (*ymax - *ymin) / PixelSize;
  cout << "MAP LIMITS" << endl;
  cout << "xmin=" << *xmin << "  xmax=" << *xmax << "  nbinx=" << *nbinx << endl;
  cout << "ymin=" << *ymin << "  ymax=" << *ymax << "  nbiny=" << *nbiny << endl;

  return;
}
/* ====================================== */
void PrintV3(TVector3 P, const char *name)
{
  printf("%10s  %f  %f  %f\n", name, P.X(), P.Y(), P.Z());

  return;
}

/* ---------------------------------------------- */
TVector3 GetProjectedTrackDir(TVector3 Hit1, TVector3 Hit2, TVector3 Vplane, Double_t Cplane)
{
  /* PROJECTION OF THE TRACK TO A PLANE FOR DIRECT LIGHT */

  /* P=(x,y,z) is a generic point in the space
     The track is defined by the vectors Hit1 and Hit2
                    P = Hit1 + t (Hit1-Hit2)
     The plane where the track is projected is defined by the equation
                    Vplane * P = Cplane
  */

  TVector3 Vintersection(0,0,0);

  Double_t c1 = Vplane.Dot(Hit1);
  Double_t c2 = Vplane.Dot(Hit2-Hit1);
  Double_t c3 = (Cplane - c1)/c2;

  Vintersection = Hit1 + c3 * (Hit2 - Hit1);

  //cout << "X:  P=" << Hit1.X() << "  Q=" << (Hit2-Hit1).X() << "  c=" << c3 << "   X=" << Vintersection.X() << endl;
  //cout << "Z:  P=" << Hit1.Z() << "  Q=" << (Hit2-Hit1).Z() << "  c=" << c3 << "   X=" << Vintersection.Z() << endl;


  return Vintersection;
}
