#!/bin/bash

####################################
# This script is used to generate histograms to extract all the calibration constants,
# including the time walk parameters. Is part of the calibration suite that 
# must be run at the beginning of each data taking.
# Usage:
# > ./run_richTiming.sh <phase> <outdir> <outpref> [RN] [-tw <twfile>] [-to <tofile>] [-tow <tofile> <twfile>]
# <phase>  = The phase in which the program will run 
#          (0: make hist for time offset, 1: make hist for time walk).
# <outdir> = output directory
# [RN]     = Optional parameter, run number.
#
###################################
source setenv.sh

### Prefix of filenames
FILEPREFIX="calib_clas_00"

## Get run number from command line or filename
if [ -z $4 ]; then
    RN="`ls *.hipo | head -1`"
    RN=${RN##*$FILEPREFIX}
    RN=${RN%%.*.hipo}
else
    RN=$4
fi
outpref=$3

echo "### output ps ###"
ps
echo "### output ls ###"
ls

echo "RUN NUMBER "$RN
phase=$1
outdir=$2

TFILE=""
topt=""
if [ "$5" == "-tw" ]; then
    TFILE=$6
    topt=" -W "$TFILE
elif [ "$5" == "-to" ]; then
    TFILE=$6
    topt=" -O "$TFILE
elif [ "$5" == "-tow" ]; then
    TFILE=$6
    topt=" -O "$TFILE
    TFILE=$7
    topt=$topt" -W "$TFILE
fi

ldd ./richTiming
printenv
echo $topt
cmd="./richTiming -R $RN -r -P 0 -T $phase *.hipo $topt"  
echo $cmd
## Running the application
$cmd
#./richTiming -R $RN -r -P 0 -T $phase *.hipo $topt

echo "### output ls ###"
ls
ofile="`ls *.root`"

## Setting the output file transfer
swif outfile $ofile file:$outdir/${outpref}__${ofile}
