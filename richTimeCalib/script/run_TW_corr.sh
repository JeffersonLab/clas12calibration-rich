#!/bin/bash

####################################
# This script is used to generate histograms to extract all the calibration constants,
# including the time walk parameters. Is part of the calibration suite that 
# must be run at the beginning of each data taking.
# Usage:
# > ./run_TW_corr.sh <outdir> [RN]
# <outdir> = output directory
# [RN]     = Optional parameter, run number.
#
###################################
source setenv.sh

outdir=$1
echo "### output ps ###"
ps
echo "### output ls ###"
ls

RFNAME="`ls *.root | head -1`"
RFNAME=${RFNAME/*__/} 

### Prefix of filenames
FILEPREFIX="RichTimeCalibE_"

## Get run number from command line or filename
if [ -z $2 ]; then
    RN=${RFNAME#RichTimeCalibE_*};
    RN=${RN%_?.root}
else
    RN=$2
fi

rhadd=`root-config --bindir`/hadd
$rhadd $RFNAME *__*.root

./richTimeWalks $RFNAME $RN
echo "### output ls ###"
ls

## Setting the output file transfer
ofile=$RFNAME
swif outfile $ofile file:$outdir/${ofile}

ofile="`ls richTimeWalks_${RN}.root`"
swif outfile $ofile file:$outdir/${ofile}

ofile="`ls richTimeWalks_${RN}.pdf`"
swif outfile $ofile file:$outdir/${ofile}

ofile="`ls richTimeWalks_${RN}.out`"
swif outfile $ofile file:$outdir/${ofile}

ofile="`ls richTimeWalks_ccdb_${RN}.txt`"
swif outfile $ofile file:$outdir/${ofile}
