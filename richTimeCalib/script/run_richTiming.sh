#!/bin/bash

####################################
# This script is used to generate histograms to extract all the calibration constants,
# including the time walk parameters. Is part of the calibration suite that 
# must be run at the beginning of each data taking.
# Usage:
# > ./run_richTimimg.sh <phase> <outdir> [RN]
# <phase>  = The phase in which the program will run 
#          (0: make hist for time offset, 1: make hist for time walk).
# <outdir> = output directory
# [RN]     = Optional parameter, run number.
#
###################################
source /group/clas12/packages/setup.csh
module load clas12/pro

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

echo "RUN NUMBER "$RN
phase=$1
outdir=$2

ldd ./richTiming
printenv
## Running the application
./richTiming -R $RN -r -P 0 -T $phase *.hipo
ls
ofile="`ls *.root`"

## Setting the output file transfer
swif outfile $ofile file:$outdir/${outpref}__${ofile}

