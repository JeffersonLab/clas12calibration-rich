#!/usr/bin/env python
import glob
import os
from sys import argv
import subprocess

RICHTIMECALIB = os.getenv("RICHTIMECALIB")
if RICHTIMECALIB == "":
    print ("environment variable $RICHTIMECALIB must be set to")
    print ("the location of the time calibration suite. setenv RICHTIMECALIB `pwd`")
    exit(1)

RICHTIMECALIB_OUTPATH = os.getenv("RICHTIMECALIB_OUTPATH")
if RICHTIMECALIB_OUTPATH == "":
    print ("environment variable $RICHTIMECALIB_OUTPATH must be set to")
    print ("the location of the time calibration suite.")
    exit(1)

############## global setting ###########
outdir_pref = RICHTIMECALIB_OUTPATH
appHist   = RICHTIMECALIB + "/bin/richTiming"
aBin = [RICHTIMECALIB + "/bin/richTimeWalks"]
aBin.append(RICHTIMECALIB + "/bin/richTimeCheck")
scriptHist= RICHTIMECALIB + "/script/run_richTiming.sh"
aScript  = [RICHTIMECALIB + "/script/run_TW_corr.sh"]
aScript.append(RICHTIMECALIB + "/script/run_TC.sh")
maps = [RICHTIMECALIB + "/maps/SspRich_mapCHANNEL2PIXEL.txt"]
maps.append(RICHTIMECALIB + "/maps/SspRich_mapFIBER2PMT_sortbyPMT.txt")
envscript = RICHTIMECALIB + "/script/setenv.sh"
ofile_pref = "RichTimeCalib_"
WF    = "RICH_TC_WALK"
RN    = 0
TRACK = "analysis"
TOFILE = ""
BS = 10  # hist jobs bunch size
## debug run ##
DEBUG = False
MAXJOBS = 2
#################################################
def checkdir(path):
    if not os.path.isdir(path):
        print ("The directory " + path + " does not exist")
        print ("creating it")
        cmd = "mkdir -p " + path
        subprocess.call(cmd,shell=True)
        return 0
        
####################

def get_file_list(path,regexp="*.hipo"):
    flist=glob.glob(path + "/" + regexp)
    return sorted(flist)

###### import file list from file ############
def import_flist(fname):
    infile=open(fname)
    flist=[]
    for line in infile:
        flist.append(line.strip())
    return flist

##### add histogram job to workflow
def add_hist_job(wf,fnl,phase=0,c=0):
    global outdir_pref, appHist, scriptHist, RN, envscript, TOFILE
    script = scriptHist
    jname = wf + "_" + "ph" + str(phase) + "_" + str(c)
    size = 0
    for fname in fnl:
        size += os.path.getsize(fname)/1024./1024.*1.15
    cmd  = "swif add-job -workflow " + wf + " -ram 1500mb -project clas12 -time 6h -disk " + "{0:.0f}".format(size) + "mb "
    cmd += " -track "+ TRACK
    cmd += " -phase " + str(phase)
    cmd += " -name " + jname
    cmd += " -shell /bin/bash" 
    cmd += " -input " + appHist.split("/")[-1] + " file:" + appHist
    cmd += " -input " + script.split("/")[-1] + " file:" + script
    cmd += " -input " + maps[0].split("/")[-1] + " file:" + maps[0]
    cmd += " -input " + maps[1].split("/")[-1] + " file:" + maps[1]
    cmd += " -input " + envscript.split("/")[-1] + " file:" + envscript

    for fname in fnl:
        cmd += " -input " + fname.split("/")[-1] + " file:" + fname

    T = phase/2 + 1

    corr_type = "Walks"
    if phase > 0:
        cmd += " -input richTime" + corr_type + "_ccdb_" + RN + ".txt" + " file:" + outdir_pref + "/T" + corr_type + "O/richTime" + corr_type + "_ccdb_" + RN + ".txt"

    cmd += " -input " + TOFILE.split('/')[-1] + " file:" + TOFILE

    outdir = outdir_pref + "/T" + str(T) + "O" 
    checkdir(outdir)

    firstf = fnl[0].split('/')[-1].replace(".hipo","")
    lastf  = fnl[-1].split('/')[-1].replace(".hipo","")
    outpref = firstf + "_" + lastf.split(".")[-1]

    cmd += " ./" + script.split("/")[-1] + " " + str(T) +  " " + outdir + " " + outpref + " " + RN + " -to " + TOFILE.split('/')[-1]
    if DEBUG : print (cmd)
    subprocess.call(cmd,shell=True)

#### add analysis job ##########################
def add_ana_job(wf,flist,phase=0):
    global outdir_pref, aBin, aScript, RN, envscript
    size = 24*len(flist)*1.15
    cmd  = "swif add-job -workflow " + wf + " -ram 2500mb -project clas12 -time 6h -disk " + "{0:.0f}".format(size) + "mb "
    cmd += " -track "+ TRACK
    cmd += " -phase " + str(phase)
    cmd += " -shell /bin/bash" 

    T = (phase+1)/2

    ind=int((phase-1)/2)
    script = aScript[ind]
    app = aBin[ind]

    cmd += " -input " + app.split("/")[-1] + " file:" + app
    cmd += " -input " + script.split("/")[-1] + " file:" + script

    cmd += " -input " + maps[0].split("/")[-1] + " file:" + maps[0]
    cmd += " -input " + maps[1].split("/")[-1] + " file:" + maps[1]

    cmd += " -input " + envscript.split("/")[-1] + " file:" + envscript

    jname = wf + "_" + "ph" + str(phase) 

    corr_type = ["TWalks","TCheck"]
    outdir = outdir_pref + "/" + corr_type[ind] + "O"
    jname += "_" + corr_type[ind]

    cmd += " -name " + jname

    checkdir(outdir)

    c = 0
    for fnl in flist:
        firstf = fnl[0].split('/')[-1].replace(".hipo","")
        lastf  = fnl[-1].split('/')[-1].replace(".hipo","")
        fname  = firstf + "_" + lastf.split(".")[-1]

        fname = outdir_pref + "/T"+ str(T) +"O/" + fname + "__RichTimeCalibE_" + RN + "_" + str(T) +".root"
        cmd += " -input " + fname.split("/")[-1] + " file:" + fname
        c +=1
        if c>= MAXJOBS and DEBUG: break

    cmd += ' ./' + script.split("/")[-1] + " " + outdir + " " + RN
    if DEBUG : print (cmd)
    subprocess.call(cmd,shell=True)

### group files in bunchs ###
def add_hist_job_bunch(flist,phase=0):
    global WF
    c=0
    for fnl in flist:
        add_hist_job(WF,fnl,phase,c)
        c +=1
        if c>= MAXJOBS and DEBUG: break


######### create workflow #####
def create_wf():
    global WF
    with open(os.devnull, "w") as devnull:
        ret = subprocess.call("swif status " + WF,shell=True,stderr=devnull,stdout=devnull)
    if not ret:
        cmd  = "swif cancel -delete -workflow " + WF
        subprocess.call(cmd,shell=True)
    cmd ="swif create " + WF
    if DEBUG : print (cmd)
    subprocess.call(cmd,shell=True)

#### run workflow ############
def run_wf():
    global WF
    cmd="swif run -workflow " + WF
    subprocess.check_call(cmd.split(" "))

######## main routine ####

def main():
    global WF, RN, outdir_pref, MAXJOBS, BS, TOFILE, RICHTIMECALIB_OUTPATH
    if len(argv)!=4: 
        print ("A directory with calibration files or filelist must be supplied together with a run number and a timeoffset parameters file")
        print (argv[0] + " filelist.txt <RN> <TOFILE>")
        exit (1)
    if not os.path.exists(argv[1]):
        print ("The file or path " + argv[1] + " does not exist")
        exit (1)

    try:
        RN = int(argv[2])
    except ValueError:
        print ("The run number must be an integer!. You supplied " + argv[2])
        exit(0)
    
    TOFILE = os.path.abspath(argv[3])

    if RN == 0:
        RN = "" 
    else:
        RN = str(RN)

    WF += "_" + str(RN)
    outdir_pref += "/" + RN
    create_wf()
    flist_flat = []
    if os.path.isdir(argv[1]):
        flist_flat = get_file_list(argv[1])
    elif os.path.isfile(argv[1]):
        flist_flat = import_flist(argv[1])
    else:
        print (argv[1] + " is not a file nor a directory.")

    #### making a nested file list with maximum BS file per bunch ####
    flist = [flist_flat[x*BS:(x+1)*BS] for x in range( -(-len(flist_flat) // BS ) )]
    ##### Setting jobs phase ###########
    phase = 0
    ##### Putting jobs to make histograms without correction ####
    add_hist_job_bunch(flist,phase)

    ##### Setting jobs phase ###########
    phase +=1
    #### Putting jobs to make TW corrections with TO parameters in file####
    add_ana_job(WF,flist,phase)

    ##### Setting jobs phase ###########
    phase +=1
    #### Putting jobs to make histogram with TO and TW corrections ####
    add_hist_job_bunch(flist,phase)

    ##### Setting jobs phase ###########
    phase +=1
    #### Putting jobs to produce checking plots ####
    add_ana_job(WF,flist,phase)

if __name__=="__main__":
    main()
    run_wf()
