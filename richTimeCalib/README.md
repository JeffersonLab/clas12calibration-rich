# RICH Time Calibration package
This package contains a set of tools to extract time calibration parameters for the CLAS12 RICH detector.

## Requirement
* Hipo4 c++ installed and environments variables ```HIPO4LIB``` and  ```HIPO4INC``` pointing to the path with the hipo4 library and headers (*.h) respectively
* Root version >= 5.34

## Getting ready for running on farm
```
git clone https://github.com/JeffersonLab/clas12calibration-rich
cd clas12calibration-rich/richTimeCalib

# use the script depending on your system: setenv.csh (setenv.sh)
source script/setenv.csh   (source script/setenv.sh)
make
make install
setenv RICHTIMECALIB `pwd`  # (export RICHTIMECALIB=`pwd`)
setenv RICHTIMECALIB_OUTPATH <output-path>   (export RICHTIMECALIB_OUTPATH=<output-path>)
```
add the enviroments variables ```RICHTIMECALIB``` and ```RICHTIMECALIB_OUTPATH``` to your login script.
Once you run the programs a folder for each run number will be created under the path ```RICHTIMECALIB_OUTPATH```


## Use
### Mode 1: Full Calibration, estimate time-offsets and time-walks.
```
cd $RICHTIMECALIB/script
./send_richTimeCalib.py <path-to-calib-files or list-of-calib-files> <run-number>
```
After finishing you will have a folder in ```$RICHTIMECALIB_OUTPATH``` named ```<run-number>```

The structure inside ```$RICHTIMECALIB_OUTPATH/<run-number>``` is:
```
$RICHTIMECALIB_OUTPATH/<run-number>`
├── T0       # Histograms without corrections
│   ├── ...
├── T1       # Histograms with Time offset correction
│   ├── ...
├── T2       # Histograms with time walk and time offset correction
│   ├── ...
├── TCheck   # Summary histograms and diagnose information
│   ├── ...
├── TOffsets # Time offset correction histograms and calibration parameters
│   ├── ...
└── TWalks   # Time walk correction histograms and calibration parameters
    └── ...
```

### Mode 2: Partial Calibration, estimate time-offsets given time-walks.
```
cd $RICHTIMECALIB/script
./send_richTimeCalib_offset.py <path-to-calib-files or list-of-calib-files> <run-number> <timewalk-file>
```
After finishing you will have a folder in ```$RICHTIMECALIB_OUTPATH``` named ```<run-number>```

The structure inside ```$RICHTIMECALIB_OUTPATH/<run-number>``` is:
```
$RICHTIMECALIB_OUTPATH/<run-number>`
├── T0W       # Histograms with time walk corrections
│   ├── ...
├── T2W       # Histograms with time walk and time offset correction
│   ├── ...
├── TCheckW   # Summary histograms and diagnose information
│   ├── ...
├── TOffsetsW # Time offset correction histograms and calibration parameters
    └── ...
```

### Mode 3: Perform the reconstruction time check, use calibrated time from reconstruction.
```
cd $RICHTIMECALIB/script
./send_richRecTimeCheck.py <path-to-calib-files or list-of-calib-files> <run-number>
```
After finishing you will have a folder in ```$RICHTIMECALIB_OUTPATH``` named ```<run-number>```

The structure inside ```$RICHTIMECALIB_OUTPATH/<run-number>``` is:
```
$RICHTIMECALIB_OUTPATH/<run-number>`
├── TC        # Histograms with time corrections from reconstruction.
│   ├── ...
├── TRecCheck # Summary histograms and diagnose information
    └── ...
```

### Mode 4: Check specific corrections given time-offsets and time-walks.
```
cd $RICHTIMECALIB/script
./send_richTimeCalib_offset_walks.py <path-to-calib-files or list-of-calib-files> <run-number> <timeoffset-file> <timewalk-file>
```
After finishing you will have a folder in ```$RICHTIMECALIB_OUTPATH``` named ```<run-number>```

The structure inside ```$RICHTIMECALIB_OUTPATH/<run-number>``` is:
```
$RICHTIMECALIB_OUTPATH/<run-number>`
├── T2OW      # Histograms with time walk and time offset correction
│   ├── ...
├── TCheckOW  # Summary histograms and diagnose information
    └── ...
```

## Package Structure
The package structure is organize in the folowing way:
```
$RICHTIMECALIB
├── Makefile
├── README.md
├── include # Headers needed to read hipo files and write root files and other tools
│   ├── ...
├── maps    # RICH PMT/ANODE maps
│   ├── ...
├── script  # script to run binaries in bin/. Includes python script to create swif workflow
│   ├── ...
└── src	    # ...
    └── ...
```
After compilation two folders are created ```bin/``` and ```.obj/```
## FAQ
**Q:** Some of the jobs have status error AUGER-TIMEOUT, what can I do?

**A:**  you can add time to the problematic jobs doing ```swif modify-jobs rich_timeCalib -time add 3h -problems AUGER-TIMEOUT```

**Q:** How to avoid the jobs that have finished with errors like, SWIF-USER-NON-ZERO in phase 0?

**A:**  you can exclude from your input list files with small size. Probably these files are corrupted from reconstruction.
  
  