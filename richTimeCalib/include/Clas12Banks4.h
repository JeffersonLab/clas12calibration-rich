//// File automatically produced by create_hiponodes.py do not make changes here!!
#include "reader.h"





/*************************************************************************/
/*  Declaration of bank variables */
/*************************************************************************/
hipo::bank *RF__tdc ;
int get_RF__tdc(int row);
short  RF__tdc_sector ;
short  RF__tdc_layer ;
short  RF__tdc_component ;
short  RF__tdc_order ;
int  RF__tdc_TDC ;
hipo::bank *FTCAL__clusters ;
int get_FTCAL__clusters(int row);
short  FTCAL__clusters_size ;
short  FTCAL__clusters_id ;
float  FTCAL__clusters_x ;
float  FTCAL__clusters_y ;
float  FTCAL__clusters_z ;
float  FTCAL__clusters_widthX ;
float  FTCAL__clusters_widthY ;
float  FTCAL__clusters_radius ;
float  FTCAL__clusters_time ;
float  FTCAL__clusters_energy ;
float  FTCAL__clusters_maxEnergy ;
float  FTCAL__clusters_recEnergy ;
hipo::bank *RAW__scaler ;
int get_RAW__scaler(int row);
short  RAW__scaler_crate ;
short  RAW__scaler_slot ;
short  RAW__scaler_channel ;
short  RAW__scaler_helicity ;
short  RAW__scaler_quartet ;
long  RAW__scaler_value ;
hipo::bank *BAND__adc ;
int get_BAND__adc(int row);
short  BAND__adc_sector ;
short  BAND__adc_layer ;
short  BAND__adc_component ;
short  BAND__adc_order ;
int  BAND__adc_ADC ;
float  BAND__adc_time ;
short  BAND__adc_ped ;
hipo::bank *RUN__config ;
int get_RUN__config(int row);
int  RUN__config_run ;
int  RUN__config_event ;
int  RUN__config_unixtime ;
long  RUN__config_trigger ;
long  RUN__config_timestamp ;
short  RUN__config_type ;
short  RUN__config_mode ;
float  RUN__config_torus ;
float  RUN__config_solenoid ;
hipo::bank *TimeBasedTrkg__TBSegments ;
int get_TimeBasedTrkg__TBSegments(int row);
short  TimeBasedTrkg__TBSegments_id ;
short  TimeBasedTrkg__TBSegments_status ;
short  TimeBasedTrkg__TBSegments_sector ;
short  TimeBasedTrkg__TBSegments_superlayer ;
short  TimeBasedTrkg__TBSegments_Cluster_ID ;
short  TimeBasedTrkg__TBSegments_Hit1_ID ;
short  TimeBasedTrkg__TBSegments_Hit2_ID ;
short  TimeBasedTrkg__TBSegments_Hit3_ID ;
short  TimeBasedTrkg__TBSegments_Hit4_ID ;
short  TimeBasedTrkg__TBSegments_Hit5_ID ;
short  TimeBasedTrkg__TBSegments_Hit6_ID ;
short  TimeBasedTrkg__TBSegments_Hit7_ID ;
short  TimeBasedTrkg__TBSegments_Hit8_ID ;
short  TimeBasedTrkg__TBSegments_Hit9_ID ;
short  TimeBasedTrkg__TBSegments_Hit10_ID ;
short  TimeBasedTrkg__TBSegments_Hit11_ID ;
short  TimeBasedTrkg__TBSegments_Hit12_ID ;
float  TimeBasedTrkg__TBSegments_avgWire ;
float  TimeBasedTrkg__TBSegments_fitChisqProb ;
float  TimeBasedTrkg__TBSegments_fitSlope ;
float  TimeBasedTrkg__TBSegments_fitSlopeErr ;
float  TimeBasedTrkg__TBSegments_fitInterc ;
float  TimeBasedTrkg__TBSegments_fitIntercErr ;
float  TimeBasedTrkg__TBSegments_SegEndPoint1X ;
float  TimeBasedTrkg__TBSegments_SegEndPoint1Z ;
float  TimeBasedTrkg__TBSegments_SegEndPoint2X ;
float  TimeBasedTrkg__TBSegments_SegEndPoint2Z ;
float  TimeBasedTrkg__TBSegments_resiSum ;
float  TimeBasedTrkg__TBSegments_timeSum ;
short  TimeBasedTrkg__TBSegments_size ;
hipo::bank *REC__Calorimeter ;
int get_REC__Calorimeter(int row);
short  REC__Calorimeter_index ;
short  REC__Calorimeter_pindex ;
short  REC__Calorimeter_detector ;
short  REC__Calorimeter_sector ;
short  REC__Calorimeter_layer ;
float  REC__Calorimeter_energy ;
float  REC__Calorimeter_time ;
float  REC__Calorimeter_path ;
float  REC__Calorimeter_chi2 ;
float  REC__Calorimeter_x ;
float  REC__Calorimeter_y ;
float  REC__Calorimeter_z ;
float  REC__Calorimeter_hx ;
float  REC__Calorimeter_hy ;
float  REC__Calorimeter_hz ;
float  REC__Calorimeter_lu ;
float  REC__Calorimeter_lv ;
float  REC__Calorimeter_lw ;
float  REC__Calorimeter_du ;
float  REC__Calorimeter_dv ;
float  REC__Calorimeter_dw ;
float  REC__Calorimeter_m2u ;
float  REC__Calorimeter_m2v ;
float  REC__Calorimeter_m2w ;
float  REC__Calorimeter_m3u ;
float  REC__Calorimeter_m3v ;
float  REC__Calorimeter_m3w ;
short  REC__Calorimeter_status ;
hipo::bank *REC__CovMat ;
int get_REC__CovMat(int row);
short  REC__CovMat_index ;
short  REC__CovMat_pindex ;
float  REC__CovMat_C11 ;
float  REC__CovMat_C12 ;
float  REC__CovMat_C13 ;
float  REC__CovMat_C14 ;
float  REC__CovMat_C15 ;
float  REC__CovMat_C22 ;
float  REC__CovMat_C23 ;
float  REC__CovMat_C24 ;
float  REC__CovMat_C25 ;
float  REC__CovMat_C33 ;
float  REC__CovMat_C34 ;
float  REC__CovMat_C35 ;
float  REC__CovMat_C44 ;
float  REC__CovMat_C45 ;
float  REC__CovMat_C55 ;
hipo::bank *RAW__epics ;
int get_RAW__epics(int row);
short  RAW__epics_json ;
hipo::bank *FTHODO__clusters ;
int get_FTHODO__clusters(int row);
short  FTHODO__clusters_size ;
short  FTHODO__clusters_id ;
float  FTHODO__clusters_x ;
float  FTHODO__clusters_y ;
float  FTHODO__clusters_z ;
float  FTHODO__clusters_widthX ;
float  FTHODO__clusters_widthY ;
float  FTHODO__clusters_radius ;
float  FTHODO__clusters_time ;
float  FTHODO__clusters_energy ;
hipo::bank *RUN__scaler ;
int get_RUN__scaler(int row);
float  RUN__scaler_fcupgated ;
float  RUN__scaler_fcup ;
float  RUN__scaler_livetime ;
hipo::bank *BAND__hits ;
int get_BAND__hits(int row);
short  BAND__hits_id ;
short  BAND__hits_sector ;
short  BAND__hits_layer ;
short  BAND__hits_component ;
float  BAND__hits_meantimeTdc ;
float  BAND__hits_meantimeFadc ;
float  BAND__hits_difftimeTdc ;
float  BAND__hits_difftimeFadc ;
float  BAND__hits_adcLcorr ;
float  BAND__hits_adcRcorr ;
float  BAND__hits_tFadcLcorr ;
float  BAND__hits_tFadcRcorr ;
float  BAND__hits_tTdcLcorr ;
float  BAND__hits_tTdcRcorr ;
float  BAND__hits_x ;
float  BAND__hits_y ;
float  BAND__hits_z ;
float  BAND__hits_ux ;
float  BAND__hits_uy ;
float  BAND__hits_uz ;
hipo::bank *ECAL__clusters ;
int get_ECAL__clusters(int row);
short  ECAL__clusters_id ;
short  ECAL__clusters_status ;
short  ECAL__clusters_sector ;
short  ECAL__clusters_layer ;
float  ECAL__clusters_x ;
float  ECAL__clusters_y ;
float  ECAL__clusters_z ;
float  ECAL__clusters_energy ;
float  ECAL__clusters_time ;
float  ECAL__clusters_widthU ;
float  ECAL__clusters_widthV ;
float  ECAL__clusters_widthW ;
short  ECAL__clusters_idU ;
short  ECAL__clusters_idV ;
short  ECAL__clusters_idW ;
int  ECAL__clusters_coordU ;
int  ECAL__clusters_coordV ;
int  ECAL__clusters_coordW ;
hipo::bank *FT__particles ;
int get_FT__particles(int row);
short  FT__particles_id ;
short  FT__particles_charge ;
float  FT__particles_energy ;
float  FT__particles_cx ;
float  FT__particles_cy ;
float  FT__particles_cz ;
float  FT__particles_time ;
short  FT__particles_calID ;
short  FT__particles_hodoID ;
short  FT__particles_trkID ;
hipo::bank *REC__Track ;
int get_REC__Track(int row);
short  REC__Track_index ;
short  REC__Track_pindex ;
short  REC__Track_detector ;
short  REC__Track_sector ;
short  REC__Track_status ;
short  REC__Track_q ;
float  REC__Track_chi2 ;
short  REC__Track_NDF ;
hipo::bank *TimeBasedTrkg__TBCrosses ;
int get_TimeBasedTrkg__TBCrosses(int row);
short  TimeBasedTrkg__TBCrosses_id ;
short  TimeBasedTrkg__TBCrosses_status ;
short  TimeBasedTrkg__TBCrosses_sector ;
short  TimeBasedTrkg__TBCrosses_region ;
float  TimeBasedTrkg__TBCrosses_x ;
float  TimeBasedTrkg__TBCrosses_y ;
float  TimeBasedTrkg__TBCrosses_z ;
float  TimeBasedTrkg__TBCrosses_err_x ;
float  TimeBasedTrkg__TBCrosses_err_y ;
float  TimeBasedTrkg__TBCrosses_err_z ;
float  TimeBasedTrkg__TBCrosses_ux ;
float  TimeBasedTrkg__TBCrosses_uy ;
float  TimeBasedTrkg__TBCrosses_uz ;
float  TimeBasedTrkg__TBCrosses_err_ux ;
float  TimeBasedTrkg__TBCrosses_err_uy ;
float  TimeBasedTrkg__TBCrosses_err_uz ;
short  TimeBasedTrkg__TBCrosses_Segment1_ID ;
short  TimeBasedTrkg__TBCrosses_Segment2_ID ;
hipo::bank *FTCAL__adc ;
int get_FTCAL__adc(int row);
short  FTCAL__adc_sector ;
short  FTCAL__adc_layer ;
short  FTCAL__adc_component ;
short  FTCAL__adc_order ;
int  FTCAL__adc_ADC ;
float  FTCAL__adc_time ;
short  FTCAL__adc_ped ;
hipo::bank *CND__adc ;
int get_CND__adc(int row);
short  CND__adc_sector ;
short  CND__adc_layer ;
short  CND__adc_component ;
short  CND__adc_order ;
int  CND__adc_ADC ;
float  CND__adc_time ;
short  CND__adc_ped ;
hipo::bank *FTOF__hits ;
int get_FTOF__hits(int row);
short  FTOF__hits_id ;
short  FTOF__hits_status ;
short  FTOF__hits_trackid ;
short  FTOF__hits_sector ;
short  FTOF__hits_layer ;
short  FTOF__hits_component ;
float  FTOF__hits_energy ;
float  FTOF__hits_time ;
float  FTOF__hits_energy_unc ;
float  FTOF__hits_time_unc ;
float  FTOF__hits_x ;
float  FTOF__hits_y ;
float  FTOF__hits_z ;
float  FTOF__hits_x_unc ;
float  FTOF__hits_y_unc ;
float  FTOF__hits_z_unc ;
float  FTOF__hits_tx ;
float  FTOF__hits_ty ;
float  FTOF__hits_tz ;
short  FTOF__hits_adc_idx1 ;
short  FTOF__hits_adc_idx2 ;
short  FTOF__hits_tdc_idx1 ;
short  FTOF__hits_tdc_idx2 ;
float  FTOF__hits_pathLength ;
float  FTOF__hits_pathLengthThruBar ;
hipo::bank *REC__ForwardTagger ;
int get_REC__ForwardTagger(int row);
short  REC__ForwardTagger_index ;
short  REC__ForwardTagger_pindex ;
short  REC__ForwardTagger_detector ;
short  REC__ForwardTagger_layer ;
float  REC__ForwardTagger_energy ;
float  REC__ForwardTagger_time ;
float  REC__ForwardTagger_path ;
float  REC__ForwardTagger_chi2 ;
float  REC__ForwardTagger_x ;
float  REC__ForwardTagger_y ;
float  REC__ForwardTagger_z ;
float  REC__ForwardTagger_dx ;
float  REC__ForwardTagger_dy ;
float  REC__ForwardTagger_radius ;
short  REC__ForwardTagger_size ;
short  REC__ForwardTagger_status ;
hipo::bank *TimeBasedTrkg__TBSegmentTrajectory ;
int get_TimeBasedTrkg__TBSegmentTrajectory(int row);
short  TimeBasedTrkg__TBSegmentTrajectory_segmentID ;
short  TimeBasedTrkg__TBSegmentTrajectory_sector ;
short  TimeBasedTrkg__TBSegmentTrajectory_superlayer ;
short  TimeBasedTrkg__TBSegmentTrajectory_layer ;
short  TimeBasedTrkg__TBSegmentTrajectory_matchedHitID ;
float  TimeBasedTrkg__TBSegmentTrajectory_trkDoca ;
hipo::bank *CTOF__tdc ;
int get_CTOF__tdc(int row);
short  CTOF__tdc_sector ;
short  CTOF__tdc_layer ;
short  CTOF__tdc_component ;
short  CTOF__tdc_order ;
int  CTOF__tdc_TDC ;
hipo::bank *REC__Cherenkov ;
int get_REC__Cherenkov(int row);
short  REC__Cherenkov_index ;
short  REC__Cherenkov_pindex ;
short  REC__Cherenkov_detector ;
short  REC__Cherenkov_sector ;
float  REC__Cherenkov_nphe ;
float  REC__Cherenkov_time ;
float  REC__Cherenkov_path ;
float  REC__Cherenkov_chi2 ;
float  REC__Cherenkov_x ;
float  REC__Cherenkov_y ;
float  REC__Cherenkov_z ;
float  REC__Cherenkov_dtheta ;
float  REC__Cherenkov_dphi ;
short  REC__Cherenkov_status ;
hipo::bank *FTHODO__hits ;
int get_FTHODO__hits(int row);
short  FTHODO__hits_sector ;
short  FTHODO__hits_layer ;
short  FTHODO__hits_component ;
float  FTHODO__hits_x ;
float  FTHODO__hits_y ;
float  FTHODO__hits_z ;
float  FTHODO__hits_energy ;
float  FTHODO__hits_time ;
short  FTHODO__hits_hitID ;
short  FTHODO__hits_clusterID ;
hipo::bank *RECFT__Event ;
int get_RECFT__Event(int row);
short  RECFT__Event_EvCAT ;
float  RECFT__Event_startTime ;
hipo::bank *FTOF__adc ;
int get_FTOF__adc(int row);
short  FTOF__adc_sector ;
short  FTOF__adc_layer ;
short  FTOF__adc_component ;
short  FTOF__adc_order ;
int  FTOF__adc_ADC ;
float  FTOF__adc_time ;
short  FTOF__adc_ped ;
hipo::bank *MC__Lund ;
int get_MC__Lund(int row);
short  MC__Lund_index ;
float  MC__Lund_lifetime ;
short  MC__Lund_type ;
int  MC__Lund_pid ;
short  MC__Lund_parent ;
short  MC__Lund_daughter ;
float  MC__Lund_px ;
float  MC__Lund_py ;
float  MC__Lund_pz ;
float  MC__Lund_energy ;
float  MC__Lund_mass ;
float  MC__Lund_vx ;
float  MC__Lund_vy ;
float  MC__Lund_vz ;
hipo::bank *CTOF__adc ;
int get_CTOF__adc(int row);
short  CTOF__adc_sector ;
short  CTOF__adc_layer ;
short  CTOF__adc_component ;
short  CTOF__adc_order ;
int  CTOF__adc_ADC ;
float  CTOF__adc_time ;
short  CTOF__adc_ped ;
hipo::bank *MC__Header ;
int get_MC__Header(int row);
int  MC__Header_run ;
int  MC__Header_event ;
short  MC__Header_type ;
float  MC__Header_helicity ;
hipo::bank *HEL__online ;
int get_HEL__online(int row);
short  HEL__online_helicity ;
short  HEL__online_helicityRaw ;
hipo::bank *REC__Event ;
int get_REC__Event(int row);
long  REC__Event_category ;
long  REC__Event_topology ;
float  REC__Event_beamCharge ;
double  REC__Event_liveTime ;
float  REC__Event_startTime ;
float  REC__Event_RFTime ;
short  REC__Event_helicity ;
short  REC__Event_helicityRaw ;
float  REC__Event_procTime ;
hipo::bank *REC__Particle ;
int get_REC__Particle(int row);
int  REC__Particle_pid ;
float  REC__Particle_px ;
float  REC__Particle_py ;
float  REC__Particle_pz ;
float  REC__Particle_vx ;
float  REC__Particle_vy ;
float  REC__Particle_vz ;
short  REC__Particle_charge ;
float  REC__Particle_beta ;
float  REC__Particle_chi2pid ;
short  REC__Particle_status ;
hipo::bank *REC__Traj ;
int get_REC__Traj(int row);
short  REC__Traj_pindex ;
short  REC__Traj_index ;
short  REC__Traj_detector ;
short  REC__Traj_layer ;
float  REC__Traj_x ;
float  REC__Traj_y ;
float  REC__Traj_z ;
float  REC__Traj_cx ;
float  REC__Traj_cy ;
float  REC__Traj_cz ;
float  REC__Traj_path ;
hipo::bank *FTOF__tdc ;
int get_FTOF__tdc(int row);
short  FTOF__tdc_sector ;
short  FTOF__tdc_layer ;
short  FTOF__tdc_component ;
short  FTOF__tdc_order ;
int  FTOF__tdc_TDC ;
hipo::bank *RICH__hits ;
int get_RICH__hits(int row);
short  RICH__hits_id ;
short  RICH__hits_sector ;
short  RICH__hits_tile ;
short  RICH__hits_pmt ;
short  RICH__hits_anode ;
float  RICH__hits_x ;
float  RICH__hits_y ;
float  RICH__hits_z ;
float  RICH__hits_time ;
float  RICH__hits_rawtime ;
short  RICH__hits_cluster ;
short  RICH__hits_xtalk ;
short  RICH__hits_duration ;
hipo::bank *MC__True ;
int get_MC__True(int row);
short  MC__True_detector ;
int  MC__True_pid ;
int  MC__True_mpid ;
int  MC__True_tid ;
int  MC__True_mtid ;
int  MC__True_otid ;
float  MC__True_trackE ;
float  MC__True_totEdep ;
float  MC__True_avgX ;
float  MC__True_avgY ;
float  MC__True_avgZ ;
float  MC__True_avgLx ;
float  MC__True_avgLy ;
float  MC__True_avgLz ;
float  MC__True_px ;
float  MC__True_py ;
float  MC__True_pz ;
float  MC__True_vx ;
float  MC__True_vy ;
float  MC__True_vz ;
float  MC__True_mvx ;
float  MC__True_mvy ;
float  MC__True_mvz ;
float  MC__True_avgT ;
int  MC__True_nsteps ;
int  MC__True_procID ;
int  MC__True_hitn ;
hipo::bank *FTCAL__hits ;
int get_FTCAL__hits(int row);
short  FTCAL__hits_idx ;
short  FTCAL__hits_idy ;
float  FTCAL__hits_x ;
float  FTCAL__hits_y ;
float  FTCAL__hits_z ;
float  FTCAL__hits_energy ;
float  FTCAL__hits_time ;
short  FTCAL__hits_hitID ;
short  FTCAL__hits_clusterID ;
hipo::bank *MC__Event ;
int get_MC__Event(int row);
short  MC__Event_npart ;
short  MC__Event_atarget ;
short  MC__Event_ztarget ;
float  MC__Event_ptarget ;
float  MC__Event_pbeam ;
short  MC__Event_btype ;
float  MC__Event_ebeam ;
short  MC__Event_targetid ;
short  MC__Event_processid ;
float  MC__Event_weight ;
hipo::bank *BAND__tdc ;
int get_BAND__tdc(int row);
short  BAND__tdc_sector ;
short  BAND__tdc_layer ;
short  BAND__tdc_component ;
short  BAND__tdc_order ;
int  BAND__tdc_TDC ;
hipo::bank *RF__adc ;
int get_RF__adc(int row);
short  RF__adc_sector ;
short  RF__adc_layer ;
short  RF__adc_component ;
short  RF__adc_order ;
int  RF__adc_ADC ;
float  RF__adc_time ;
short  RF__adc_ped ;
hipo::bank *REC__Scintillator ;
int get_REC__Scintillator(int row);
short  REC__Scintillator_index ;
short  REC__Scintillator_pindex ;
short  REC__Scintillator_detector ;
short  REC__Scintillator_sector ;
short  REC__Scintillator_layer ;
short  REC__Scintillator_component ;
float  REC__Scintillator_energy ;
float  REC__Scintillator_time ;
float  REC__Scintillator_path ;
float  REC__Scintillator_chi2 ;
float  REC__Scintillator_x ;
float  REC__Scintillator_y ;
float  REC__Scintillator_z ;
float  REC__Scintillator_hx ;
float  REC__Scintillator_hy ;
float  REC__Scintillator_hz ;
short  REC__Scintillator_status ;
hipo::bank *ECAL__peaks ;
int get_ECAL__peaks(int row);
short  ECAL__peaks_id ;
short  ECAL__peaks_status ;
short  ECAL__peaks_sector ;
short  ECAL__peaks_layer ;
float  ECAL__peaks_energy ;
float  ECAL__peaks_time ;
float  ECAL__peaks_xo ;
float  ECAL__peaks_yo ;
float  ECAL__peaks_zo ;
float  ECAL__peaks_xe ;
float  ECAL__peaks_ye ;
float  ECAL__peaks_ze ;
float  ECAL__peaks_width ;
hipo::bank *MC__Particle ;
int get_MC__Particle(int row);
int  MC__Particle_pid ;
float  MC__Particle_px ;
float  MC__Particle_py ;
float  MC__Particle_pz ;
float  MC__Particle_vx ;
float  MC__Particle_vy ;
float  MC__Particle_vz ;
float  MC__Particle_vt ;
hipo::bank *ECAL__tdc ;
int get_ECAL__tdc(int row);
short  ECAL__tdc_sector ;
short  ECAL__tdc_layer ;
short  ECAL__tdc_component ;
short  ECAL__tdc_order ;
int  ECAL__tdc_TDC ;
hipo::bank *RICH__tdc ;
int get_RICH__tdc(int row);
short  RICH__tdc_sector ;
short  RICH__tdc_layer ;
short  RICH__tdc_component ;
short  RICH__tdc_order ;
int  RICH__tdc_TDC ;
hipo::bank *LTCC__clusters ;
int get_LTCC__clusters(int row);
short  LTCC__clusters_id ;
short  LTCC__clusters_status ;
short  LTCC__clusters_sector ;
short  LTCC__clusters_segment ;
float  LTCC__clusters_x ;
float  LTCC__clusters_y ;
float  LTCC__clusters_z ;
float  LTCC__clusters_nphe ;
float  LTCC__clusters_time ;
short  LTCC__clusters_nHits ;
float  LTCC__clusters_minTheta ;
float  LTCC__clusters_maxTheta ;
float  LTCC__clusters_minPhi ;
float  LTCC__clusters_maxPhi ;
hipo::bank *RICH__hadrons ;
int get_RICH__hadrons(int row);
short  RICH__hadrons_id ;
short  RICH__hadrons_hit_index ;
short  RICH__hadrons_particle_index ;
float  RICH__hadrons_traced_the ;
float  RICH__hadrons_traced_phi ;
float  RICH__hadrons_traced_hitx ;
float  RICH__hadrons_traced_hity ;
float  RICH__hadrons_traced_hitz ;
float  RICH__hadrons_traced_time ;
float  RICH__hadrons_traced_path ;
short  RICH__hadrons_traced_ilay ;
short  RICH__hadrons_traced_ico ;
float  RICH__hadrons_traced_emix ;
float  RICH__hadrons_traced_emiy ;
float  RICH__hadrons_traced_emiz ;
float  RICH__hadrons_EtaC_ele ;
float  RICH__hadrons_EtaC_pi ;
float  RICH__hadrons_EtaC_k ;
float  RICH__hadrons_EtaC_pr ;
float  RICH__hadrons_EtaC_min ;
float  RICH__hadrons_EtaC_max ;
hipo::bank *FTHODO__adc ;
int get_FTHODO__adc(int row);
short  FTHODO__adc_sector ;
short  FTHODO__adc_layer ;
short  FTHODO__adc_component ;
short  FTHODO__adc_order ;
int  FTHODO__adc_ADC ;
float  FTHODO__adc_time ;
short  FTHODO__adc_ped ;
hipo::bank *HTCC__rec ;
int get_HTCC__rec(int row);
short  HTCC__rec_id ;
short  HTCC__rec_nhits ;
float  HTCC__rec_nphe ;
short  HTCC__rec_ntheta ;
short  HTCC__rec_nphi ;
short  HTCC__rec_mintheta ;
short  HTCC__rec_maxtheta ;
short  HTCC__rec_minphi ;
short  HTCC__rec_maxphi ;
float  HTCC__rec_time ;
float  HTCC__rec_theta ;
float  HTCC__rec_dtheta ;
float  HTCC__rec_phi ;
float  HTCC__rec_dphi ;
float  HTCC__rec_x ;
float  HTCC__rec_y ;
float  HTCC__rec_z ;
hipo::bank *RUN__trigger ;
int get_RUN__trigger(int row);
int  RUN__trigger_id ;
int  RUN__trigger_trigger ;
hipo::bank *ECAL__adc ;
int get_ECAL__adc(int row);
short  ECAL__adc_sector ;
short  ECAL__adc_layer ;
short  ECAL__adc_component ;
short  ECAL__adc_order ;
int  ECAL__adc_ADC ;
float  ECAL__adc_time ;
short  ECAL__adc_ped ;
hipo::bank *ECAL__calib ;
int get_ECAL__calib(int row);
short  ECAL__calib_sector ;
short  ECAL__calib_layer ;
float  ECAL__calib_energy ;
float  ECAL__calib_rawEU ;
float  ECAL__calib_rawEV ;
float  ECAL__calib_rawEW ;
float  ECAL__calib_recEU ;
float  ECAL__calib_recEV ;
float  ECAL__calib_recEW ;
hipo::bank *RUN__rf ;
int get_RUN__rf(int row);
short  RUN__rf_id ;
float  RUN__rf_time ;
hipo::bank *LTCC__adc ;
int get_LTCC__adc(int row);
short  LTCC__adc_sector ;
short  LTCC__adc_layer ;
short  LTCC__adc_component ;
short  LTCC__adc_order ;
int  LTCC__adc_ADC ;
float  LTCC__adc_time ;
short  LTCC__adc_ped ;
hipo::bank *TimeBasedTrkg__TBHits ;
int get_TimeBasedTrkg__TBHits(int row);
short  TimeBasedTrkg__TBHits_id ;
short  TimeBasedTrkg__TBHits_status ;
short  TimeBasedTrkg__TBHits_sector ;
short  TimeBasedTrkg__TBHits_superlayer ;
short  TimeBasedTrkg__TBHits_layer ;
short  TimeBasedTrkg__TBHits_wire ;
int  TimeBasedTrkg__TBHits_TDC ;
float  TimeBasedTrkg__TBHits_doca ;
float  TimeBasedTrkg__TBHits_docaError ;
float  TimeBasedTrkg__TBHits_trkDoca ;
float  TimeBasedTrkg__TBHits_timeResidual ;
float  TimeBasedTrkg__TBHits_fitResidual ;
short  TimeBasedTrkg__TBHits_LR ;
float  TimeBasedTrkg__TBHits_X ;
float  TimeBasedTrkg__TBHits_Z ;
float  TimeBasedTrkg__TBHits_B ;
float  TimeBasedTrkg__TBHits_Alpha ;
float  TimeBasedTrkg__TBHits_TProp ;
float  TimeBasedTrkg__TBHits_TFlight ;
float  TimeBasedTrkg__TBHits_T0 ;
float  TimeBasedTrkg__TBHits_TStart ;
short  TimeBasedTrkg__TBHits_clusterID ;
short  TimeBasedTrkg__TBHits_trkID ;
float  TimeBasedTrkg__TBHits_time ;
float  TimeBasedTrkg__TBHits_beta ;
float  TimeBasedTrkg__TBHits_tBeta ;
hipo::bank *HTCC__adc ;
int get_HTCC__adc(int row);
short  HTCC__adc_sector ;
short  HTCC__adc_layer ;
short  HTCC__adc_component ;
short  HTCC__adc_order ;
int  HTCC__adc_ADC ;
float  HTCC__adc_time ;
short  HTCC__adc_ped ;
hipo::bank *CTOF__hits ;
int get_CTOF__hits(int row);
short  CTOF__hits_id ;
short  CTOF__hits_status ;
short  CTOF__hits_trkID ;
short  CTOF__hits_sector ;
short  CTOF__hits_layer ;
short  CTOF__hits_component ;
float  CTOF__hits_energy ;
float  CTOF__hits_time ;
float  CTOF__hits_energy_unc ;
float  CTOF__hits_time_unc ;
float  CTOF__hits_x ;
float  CTOF__hits_y ;
float  CTOF__hits_z ;
float  CTOF__hits_x_unc ;
float  CTOF__hits_y_unc ;
float  CTOF__hits_z_unc ;
float  CTOF__hits_tx ;
float  CTOF__hits_ty ;
float  CTOF__hits_tz ;
short  CTOF__hits_adc_idx1 ;
short  CTOF__hits_adc_idx2 ;
short  CTOF__hits_tdc_idx1 ;
short  CTOF__hits_tdc_idx2 ;
float  CTOF__hits_pathLength ;
float  CTOF__hits_pathLengthThruBar ;
hipo::bank *CND__tdc ;
int get_CND__tdc(int row);
short  CND__tdc_sector ;
short  CND__tdc_layer ;
short  CND__tdc_component ;
short  CND__tdc_order ;
int  CND__tdc_TDC ;
hipo::bank *CVTRec__Tracks ;
int get_CVTRec__Tracks(int row);
short  CVTRec__Tracks_ID ;
short  CVTRec__Tracks_fittingMethod ;
float  CVTRec__Tracks_c_x ;
float  CVTRec__Tracks_c_y ;
float  CVTRec__Tracks_c_z ;
float  CVTRec__Tracks_c_ux ;
float  CVTRec__Tracks_c_uy ;
float  CVTRec__Tracks_c_uz ;
float  CVTRec__Tracks_pathlength ;
short  CVTRec__Tracks_q ;
float  CVTRec__Tracks_p ;
float  CVTRec__Tracks_pt ;
float  CVTRec__Tracks_phi0 ;
float  CVTRec__Tracks_tandip ;
float  CVTRec__Tracks_z0 ;
float  CVTRec__Tracks_d0 ;
float  CVTRec__Tracks_cov_d02 ;
float  CVTRec__Tracks_cov_d0phi0 ;
float  CVTRec__Tracks_cov_d0rho ;
float  CVTRec__Tracks_cov_phi02 ;
float  CVTRec__Tracks_cov_phi0rho ;
float  CVTRec__Tracks_cov_rho2 ;
float  CVTRec__Tracks_cov_z02 ;
float  CVTRec__Tracks_cov_tandip2 ;
float  CVTRec__Tracks_circlefit_chi2_per_ndf ;
float  CVTRec__Tracks_linefit_chi2_per_ndf ;
float  CVTRec__Tracks_chi2 ;
short  CVTRec__Tracks_ndf ;
short  CVTRec__Tracks_Cross1_ID ;
short  CVTRec__Tracks_Cross2_ID ;
short  CVTRec__Tracks_Cross3_ID ;
short  CVTRec__Tracks_Cross4_ID ;
short  CVTRec__Tracks_Cross5_ID ;
short  CVTRec__Tracks_Cross6_ID ;
short  CVTRec__Tracks_Cross7_ID ;
short  CVTRec__Tracks_Cross8_ID ;
short  CVTRec__Tracks_Cross9_ID ;
hipo::bank *RICH__photons ;
int get_RICH__photons(int row);
short  RICH__photons_id ;
short  RICH__photons_type ;
short  RICH__photons_hit_index ;
short  RICH__photons_hadron_index ;
float  RICH__photons_start_time ;
float  RICH__photons_analytic_the ;
float  RICH__photons_analytic_phi ;
float  RICH__photons_analytic_path ;
float  RICH__photons_analytic_time ;
float  RICH__photons_analytic_EtaC ;
float  RICH__photons_analytic_aeron ;
float  RICH__photons_analytic_elpr ;
float  RICH__photons_analytic_pipr ;
float  RICH__photons_analytic_kpr ;
float  RICH__photons_analytic_prpr ;
float  RICH__photons_analytic_bgpr ;
float  RICH__photons_traced_the ;
float  RICH__photons_traced_phi ;
float  RICH__photons_traced_hitx ;
float  RICH__photons_traced_hity ;
float  RICH__photons_traced_hitz ;
float  RICH__photons_traced_path ;
float  RICH__photons_traced_time ;
short  RICH__photons_traced_nrfl ;
short  RICH__photons_traced_nrfr ;
short  RICH__photons_traced_1rfl ;
float  RICH__photons_traced_EtaC ;
float  RICH__photons_traced_aeron ;
float  RICH__photons_traced_elpr ;
float  RICH__photons_traced_pipr ;
float  RICH__photons_traced_kpr ;
float  RICH__photons_traced_prpr ;
float  RICH__photons_traced_bgpr ;
hipo::bank *RECFT__Particle ;
int get_RECFT__Particle(int row);
int  RECFT__Particle_pid ;
float  RECFT__Particle_beta ;
float  RECFT__Particle_chi2pid ;
short  RECFT__Particle_status ;
hipo::bank *HEL__flip ;
int get_HEL__flip(int row);
int  HEL__flip_run ;
int  HEL__flip_event ;
long  HEL__flip_timestamp ;
short  HEL__flip_helicity ;
short  HEL__flip_helicityRaw ;
short  HEL__flip_pair ;
short  HEL__flip_pattern ;
short  HEL__flip_status ;
hipo::bank *TimeBasedTrkg__TBTracks ;
int get_TimeBasedTrkg__TBTracks(int row);
short  TimeBasedTrkg__TBTracks_id ;
short  TimeBasedTrkg__TBTracks_status ;
short  TimeBasedTrkg__TBTracks_sector ;
float  TimeBasedTrkg__TBTracks_c1_x ;
float  TimeBasedTrkg__TBTracks_c1_y ;
float  TimeBasedTrkg__TBTracks_c1_z ;
float  TimeBasedTrkg__TBTracks_c1_ux ;
float  TimeBasedTrkg__TBTracks_c1_uy ;
float  TimeBasedTrkg__TBTracks_c1_uz ;
float  TimeBasedTrkg__TBTracks_c3_x ;
float  TimeBasedTrkg__TBTracks_c3_y ;
float  TimeBasedTrkg__TBTracks_c3_z ;
float  TimeBasedTrkg__TBTracks_c3_ux ;
float  TimeBasedTrkg__TBTracks_c3_uy ;
float  TimeBasedTrkg__TBTracks_c3_uz ;
float  TimeBasedTrkg__TBTracks_t1_x ;
float  TimeBasedTrkg__TBTracks_t1_y ;
float  TimeBasedTrkg__TBTracks_t1_z ;
float  TimeBasedTrkg__TBTracks_t1_px ;
float  TimeBasedTrkg__TBTracks_t1_py ;
float  TimeBasedTrkg__TBTracks_t1_pz ;
float  TimeBasedTrkg__TBTracks_Vtx0_x ;
float  TimeBasedTrkg__TBTracks_Vtx0_y ;
float  TimeBasedTrkg__TBTracks_Vtx0_z ;
float  TimeBasedTrkg__TBTracks_p0_x ;
float  TimeBasedTrkg__TBTracks_p0_y ;
float  TimeBasedTrkg__TBTracks_p0_z ;
short  TimeBasedTrkg__TBTracks_Cross1_ID ;
short  TimeBasedTrkg__TBTracks_Cross2_ID ;
short  TimeBasedTrkg__TBTracks_Cross3_ID ;
short  TimeBasedTrkg__TBTracks_q ;
float  TimeBasedTrkg__TBTracks_pathlength ;
float  TimeBasedTrkg__TBTracks_chi2 ;
short  TimeBasedTrkg__TBTracks_ndf ;
hipo::bank *TimeBasedTrkg__Trajectory ;
int get_TimeBasedTrkg__Trajectory(int row);
short  TimeBasedTrkg__Trajectory_id ;
short  TimeBasedTrkg__Trajectory_detector ;
short  TimeBasedTrkg__Trajectory_layer ;
float  TimeBasedTrkg__Trajectory_x ;
float  TimeBasedTrkg__Trajectory_y ;
float  TimeBasedTrkg__Trajectory_z ;
float  TimeBasedTrkg__Trajectory_tx ;
float  TimeBasedTrkg__Trajectory_ty ;
float  TimeBasedTrkg__Trajectory_tz ;
float  TimeBasedTrkg__Trajectory_B ;
float  TimeBasedTrkg__Trajectory_path ;
hipo::bank *CND__hits ;
int get_CND__hits(int row);
short  CND__hits_id ;
short  CND__hits_status ;
short  CND__hits_trkID ;
short  CND__hits_sector ;
short  CND__hits_layer ;
short  CND__hits_component ;
float  CND__hits_energy ;
float  CND__hits_time ;
float  CND__hits_energy_unc ;
float  CND__hits_time_unc ;
float  CND__hits_x ;
float  CND__hits_y ;
float  CND__hits_z ;
float  CND__hits_x_unc ;
float  CND__hits_y_unc ;
float  CND__hits_z_unc ;
float  CND__hits_tx ;
float  CND__hits_ty ;
float  CND__hits_tz ;
float  CND__hits_tlength ;
float  CND__hits_pathlength ;
short  CND__hits_indexLadc ;
short  CND__hits_indexRadc ;
short  CND__hits_indexLtdc ;
short  CND__hits_indexRtdc ;



/*************************************************************************/
/* Hipo reader objects */
/*************************************************************************/
hipo::reader *fReader;
hipo::event *fEvent;
hipo::dictionary *fFactory;





/*************************************************************************/
/* Hipo reader functions */
/*************************************************************************/
int get_RF__tdc(int row){
	RF__tdc_sector = RF__tdc->getByte("sector",row);
	RF__tdc_layer = RF__tdc->getByte("layer",row);
	RF__tdc_component = RF__tdc->getShort("component",row);
	RF__tdc_order = RF__tdc->getByte("order",row);
	RF__tdc_TDC = RF__tdc->getInt("TDC",row);
	return 0;
} 

int get_FTCAL__clusters(int row){
	FTCAL__clusters_size = FTCAL__clusters->getShort("size",row);
	FTCAL__clusters_id = FTCAL__clusters->getShort("id",row);
	FTCAL__clusters_x = FTCAL__clusters->getFloat("x",row);
	FTCAL__clusters_y = FTCAL__clusters->getFloat("y",row);
	FTCAL__clusters_z = FTCAL__clusters->getFloat("z",row);
	FTCAL__clusters_widthX = FTCAL__clusters->getFloat("widthX",row);
	FTCAL__clusters_widthY = FTCAL__clusters->getFloat("widthY",row);
	FTCAL__clusters_radius = FTCAL__clusters->getFloat("radius",row);
	FTCAL__clusters_time = FTCAL__clusters->getFloat("time",row);
	FTCAL__clusters_energy = FTCAL__clusters->getFloat("energy",row);
	FTCAL__clusters_maxEnergy = FTCAL__clusters->getFloat("maxEnergy",row);
	FTCAL__clusters_recEnergy = FTCAL__clusters->getFloat("recEnergy",row);
	return 0;
} 

int get_RAW__scaler(int row){
	RAW__scaler_crate = RAW__scaler->getByte("crate",row);
	RAW__scaler_slot = RAW__scaler->getByte("slot",row);
	RAW__scaler_channel = RAW__scaler->getShort("channel",row);
	RAW__scaler_helicity = RAW__scaler->getByte("helicity",row);
	RAW__scaler_quartet = RAW__scaler->getByte("quartet",row);
	RAW__scaler_value = RAW__scaler->getLong("value",row);
	return 0;
} 

int get_BAND__adc(int row){
	BAND__adc_sector = BAND__adc->getByte("sector",row);
	BAND__adc_layer = BAND__adc->getByte("layer",row);
	BAND__adc_component = BAND__adc->getShort("component",row);
	BAND__adc_order = BAND__adc->getByte("order",row);
	BAND__adc_ADC = BAND__adc->getInt("ADC",row);
	BAND__adc_time = BAND__adc->getFloat("time",row);
	BAND__adc_ped = BAND__adc->getShort("ped",row);
	return 0;
} 

int get_RUN__config(int row){
	RUN__config_run = RUN__config->getInt("run",row);
	RUN__config_event = RUN__config->getInt("event",row);
	RUN__config_unixtime = RUN__config->getInt("unixtime",row);
	RUN__config_trigger = RUN__config->getLong("trigger",row);
	RUN__config_timestamp = RUN__config->getLong("timestamp",row);
	RUN__config_type = RUN__config->getByte("type",row);
	RUN__config_mode = RUN__config->getByte("mode",row);
	RUN__config_torus = RUN__config->getFloat("torus",row);
	RUN__config_solenoid = RUN__config->getFloat("solenoid",row);
	return 0;
} 

int get_TimeBasedTrkg__TBSegments(int row){
	TimeBasedTrkg__TBSegments_id = TimeBasedTrkg__TBSegments->getShort("id",row);
	TimeBasedTrkg__TBSegments_status = TimeBasedTrkg__TBSegments->getShort("status",row);
	TimeBasedTrkg__TBSegments_sector = TimeBasedTrkg__TBSegments->getByte("sector",row);
	TimeBasedTrkg__TBSegments_superlayer = TimeBasedTrkg__TBSegments->getByte("superlayer",row);
	TimeBasedTrkg__TBSegments_Cluster_ID = TimeBasedTrkg__TBSegments->getShort("Cluster_ID",row);
	TimeBasedTrkg__TBSegments_Hit1_ID = TimeBasedTrkg__TBSegments->getShort("Hit1_ID",row);
	TimeBasedTrkg__TBSegments_Hit2_ID = TimeBasedTrkg__TBSegments->getShort("Hit2_ID",row);
	TimeBasedTrkg__TBSegments_Hit3_ID = TimeBasedTrkg__TBSegments->getShort("Hit3_ID",row);
	TimeBasedTrkg__TBSegments_Hit4_ID = TimeBasedTrkg__TBSegments->getShort("Hit4_ID",row);
	TimeBasedTrkg__TBSegments_Hit5_ID = TimeBasedTrkg__TBSegments->getShort("Hit5_ID",row);
	TimeBasedTrkg__TBSegments_Hit6_ID = TimeBasedTrkg__TBSegments->getShort("Hit6_ID",row);
	TimeBasedTrkg__TBSegments_Hit7_ID = TimeBasedTrkg__TBSegments->getShort("Hit7_ID",row);
	TimeBasedTrkg__TBSegments_Hit8_ID = TimeBasedTrkg__TBSegments->getShort("Hit8_ID",row);
	TimeBasedTrkg__TBSegments_Hit9_ID = TimeBasedTrkg__TBSegments->getShort("Hit9_ID",row);
	TimeBasedTrkg__TBSegments_Hit10_ID = TimeBasedTrkg__TBSegments->getShort("Hit10_ID",row);
	TimeBasedTrkg__TBSegments_Hit11_ID = TimeBasedTrkg__TBSegments->getShort("Hit11_ID",row);
	TimeBasedTrkg__TBSegments_Hit12_ID = TimeBasedTrkg__TBSegments->getShort("Hit12_ID",row);
	TimeBasedTrkg__TBSegments_avgWire = TimeBasedTrkg__TBSegments->getFloat("avgWire",row);
	TimeBasedTrkg__TBSegments_fitChisqProb = TimeBasedTrkg__TBSegments->getFloat("fitChisqProb",row);
	TimeBasedTrkg__TBSegments_fitSlope = TimeBasedTrkg__TBSegments->getFloat("fitSlope",row);
	TimeBasedTrkg__TBSegments_fitSlopeErr = TimeBasedTrkg__TBSegments->getFloat("fitSlopeErr",row);
	TimeBasedTrkg__TBSegments_fitInterc = TimeBasedTrkg__TBSegments->getFloat("fitInterc",row);
	TimeBasedTrkg__TBSegments_fitIntercErr = TimeBasedTrkg__TBSegments->getFloat("fitIntercErr",row);
	TimeBasedTrkg__TBSegments_SegEndPoint1X = TimeBasedTrkg__TBSegments->getFloat("SegEndPoint1X",row);
	TimeBasedTrkg__TBSegments_SegEndPoint1Z = TimeBasedTrkg__TBSegments->getFloat("SegEndPoint1Z",row);
	TimeBasedTrkg__TBSegments_SegEndPoint2X = TimeBasedTrkg__TBSegments->getFloat("SegEndPoint2X",row);
	TimeBasedTrkg__TBSegments_SegEndPoint2Z = TimeBasedTrkg__TBSegments->getFloat("SegEndPoint2Z",row);
	TimeBasedTrkg__TBSegments_resiSum = TimeBasedTrkg__TBSegments->getFloat("resiSum",row);
	TimeBasedTrkg__TBSegments_timeSum = TimeBasedTrkg__TBSegments->getFloat("timeSum",row);
	TimeBasedTrkg__TBSegments_size = TimeBasedTrkg__TBSegments->getByte("size",row);
	return 0;
} 

int get_REC__Calorimeter(int row){
	REC__Calorimeter_index = REC__Calorimeter->getShort("index",row);
	REC__Calorimeter_pindex = REC__Calorimeter->getShort("pindex",row);
	REC__Calorimeter_detector = REC__Calorimeter->getByte("detector",row);
	REC__Calorimeter_sector = REC__Calorimeter->getByte("sector",row);
	REC__Calorimeter_layer = REC__Calorimeter->getByte("layer",row);
	REC__Calorimeter_energy = REC__Calorimeter->getFloat("energy",row);
	REC__Calorimeter_time = REC__Calorimeter->getFloat("time",row);
	REC__Calorimeter_path = REC__Calorimeter->getFloat("path",row);
	REC__Calorimeter_chi2 = REC__Calorimeter->getFloat("chi2",row);
	REC__Calorimeter_x = REC__Calorimeter->getFloat("x",row);
	REC__Calorimeter_y = REC__Calorimeter->getFloat("y",row);
	REC__Calorimeter_z = REC__Calorimeter->getFloat("z",row);
	REC__Calorimeter_hx = REC__Calorimeter->getFloat("hx",row);
	REC__Calorimeter_hy = REC__Calorimeter->getFloat("hy",row);
	REC__Calorimeter_hz = REC__Calorimeter->getFloat("hz",row);
	REC__Calorimeter_lu = REC__Calorimeter->getFloat("lu",row);
	REC__Calorimeter_lv = REC__Calorimeter->getFloat("lv",row);
	REC__Calorimeter_lw = REC__Calorimeter->getFloat("lw",row);
	REC__Calorimeter_du = REC__Calorimeter->getFloat("du",row);
	REC__Calorimeter_dv = REC__Calorimeter->getFloat("dv",row);
	REC__Calorimeter_dw = REC__Calorimeter->getFloat("dw",row);
	REC__Calorimeter_m2u = REC__Calorimeter->getFloat("m2u",row);
	REC__Calorimeter_m2v = REC__Calorimeter->getFloat("m2v",row);
	REC__Calorimeter_m2w = REC__Calorimeter->getFloat("m2w",row);
	REC__Calorimeter_m3u = REC__Calorimeter->getFloat("m3u",row);
	REC__Calorimeter_m3v = REC__Calorimeter->getFloat("m3v",row);
	REC__Calorimeter_m3w = REC__Calorimeter->getFloat("m3w",row);
	REC__Calorimeter_status = REC__Calorimeter->getShort("status",row);
	return 0;
} 

int get_REC__CovMat(int row){
	REC__CovMat_index = REC__CovMat->getShort("index",row);
	REC__CovMat_pindex = REC__CovMat->getShort("pindex",row);
	REC__CovMat_C11 = REC__CovMat->getFloat("C11",row);
	REC__CovMat_C12 = REC__CovMat->getFloat("C12",row);
	REC__CovMat_C13 = REC__CovMat->getFloat("C13",row);
	REC__CovMat_C14 = REC__CovMat->getFloat("C14",row);
	REC__CovMat_C15 = REC__CovMat->getFloat("C15",row);
	REC__CovMat_C22 = REC__CovMat->getFloat("C22",row);
	REC__CovMat_C23 = REC__CovMat->getFloat("C23",row);
	REC__CovMat_C24 = REC__CovMat->getFloat("C24",row);
	REC__CovMat_C25 = REC__CovMat->getFloat("C25",row);
	REC__CovMat_C33 = REC__CovMat->getFloat("C33",row);
	REC__CovMat_C34 = REC__CovMat->getFloat("C34",row);
	REC__CovMat_C35 = REC__CovMat->getFloat("C35",row);
	REC__CovMat_C44 = REC__CovMat->getFloat("C44",row);
	REC__CovMat_C45 = REC__CovMat->getFloat("C45",row);
	REC__CovMat_C55 = REC__CovMat->getFloat("C55",row);
	return 0;
} 

int get_RAW__epics(int row){
	RAW__epics_json = RAW__epics->getByte("json",row);
	return 0;
} 

int get_FTHODO__clusters(int row){
	FTHODO__clusters_size = FTHODO__clusters->getShort("size",row);
	FTHODO__clusters_id = FTHODO__clusters->getShort("id",row);
	FTHODO__clusters_x = FTHODO__clusters->getFloat("x",row);
	FTHODO__clusters_y = FTHODO__clusters->getFloat("y",row);
	FTHODO__clusters_z = FTHODO__clusters->getFloat("z",row);
	FTHODO__clusters_widthX = FTHODO__clusters->getFloat("widthX",row);
	FTHODO__clusters_widthY = FTHODO__clusters->getFloat("widthY",row);
	FTHODO__clusters_radius = FTHODO__clusters->getFloat("radius",row);
	FTHODO__clusters_time = FTHODO__clusters->getFloat("time",row);
	FTHODO__clusters_energy = FTHODO__clusters->getFloat("energy",row);
	return 0;
} 

int get_RUN__scaler(int row){
	RUN__scaler_fcupgated = RUN__scaler->getFloat("fcupgated",row);
	RUN__scaler_fcup = RUN__scaler->getFloat("fcup",row);
	RUN__scaler_livetime = RUN__scaler->getFloat("livetime",row);
	return 0;
} 

int get_BAND__hits(int row){
	BAND__hits_id = BAND__hits->getShort("id",row);
	BAND__hits_sector = BAND__hits->getByte("sector",row);
	BAND__hits_layer = BAND__hits->getByte("layer",row);
	BAND__hits_component = BAND__hits->getShort("component",row);
	BAND__hits_meantimeTdc = BAND__hits->getFloat("meantimeTdc",row);
	BAND__hits_meantimeFadc = BAND__hits->getFloat("meantimeFadc",row);
	BAND__hits_difftimeTdc = BAND__hits->getFloat("difftimeTdc",row);
	BAND__hits_difftimeFadc = BAND__hits->getFloat("difftimeFadc",row);
	BAND__hits_adcLcorr = BAND__hits->getFloat("adcLcorr",row);
	BAND__hits_adcRcorr = BAND__hits->getFloat("adcRcorr",row);
	BAND__hits_tFadcLcorr = BAND__hits->getFloat("tFadcLcorr",row);
	BAND__hits_tFadcRcorr = BAND__hits->getFloat("tFadcRcorr",row);
	BAND__hits_tTdcLcorr = BAND__hits->getFloat("tTdcLcorr",row);
	BAND__hits_tTdcRcorr = BAND__hits->getFloat("tTdcRcorr",row);
	BAND__hits_x = BAND__hits->getFloat("x",row);
	BAND__hits_y = BAND__hits->getFloat("y",row);
	BAND__hits_z = BAND__hits->getFloat("z",row);
	BAND__hits_ux = BAND__hits->getFloat("ux",row);
	BAND__hits_uy = BAND__hits->getFloat("uy",row);
	BAND__hits_uz = BAND__hits->getFloat("uz",row);
	return 0;
} 

int get_ECAL__clusters(int row){
	ECAL__clusters_id = ECAL__clusters->getShort("id",row);
	ECAL__clusters_status = ECAL__clusters->getShort("status",row);
	ECAL__clusters_sector = ECAL__clusters->getByte("sector",row);
	ECAL__clusters_layer = ECAL__clusters->getByte("layer",row);
	ECAL__clusters_x = ECAL__clusters->getFloat("x",row);
	ECAL__clusters_y = ECAL__clusters->getFloat("y",row);
	ECAL__clusters_z = ECAL__clusters->getFloat("z",row);
	ECAL__clusters_energy = ECAL__clusters->getFloat("energy",row);
	ECAL__clusters_time = ECAL__clusters->getFloat("time",row);
	ECAL__clusters_widthU = ECAL__clusters->getFloat("widthU",row);
	ECAL__clusters_widthV = ECAL__clusters->getFloat("widthV",row);
	ECAL__clusters_widthW = ECAL__clusters->getFloat("widthW",row);
	ECAL__clusters_idU = ECAL__clusters->getByte("idU",row);
	ECAL__clusters_idV = ECAL__clusters->getByte("idV",row);
	ECAL__clusters_idW = ECAL__clusters->getByte("idW",row);
	ECAL__clusters_coordU = ECAL__clusters->getInt("coordU",row);
	ECAL__clusters_coordV = ECAL__clusters->getInt("coordV",row);
	ECAL__clusters_coordW = ECAL__clusters->getInt("coordW",row);
	return 0;
} 

int get_FT__particles(int row){
	FT__particles_id = FT__particles->getShort("id",row);
	FT__particles_charge = FT__particles->getByte("charge",row);
	FT__particles_energy = FT__particles->getFloat("energy",row);
	FT__particles_cx = FT__particles->getFloat("cx",row);
	FT__particles_cy = FT__particles->getFloat("cy",row);
	FT__particles_cz = FT__particles->getFloat("cz",row);
	FT__particles_time = FT__particles->getFloat("time",row);
	FT__particles_calID = FT__particles->getShort("calID",row);
	FT__particles_hodoID = FT__particles->getShort("hodoID",row);
	FT__particles_trkID = FT__particles->getShort("trkID",row);
	return 0;
} 

int get_REC__Track(int row){
	REC__Track_index = REC__Track->getShort("index",row);
	REC__Track_pindex = REC__Track->getShort("pindex",row);
	REC__Track_detector = REC__Track->getByte("detector",row);
	REC__Track_sector = REC__Track->getByte("sector",row);
	REC__Track_status = REC__Track->getShort("status",row);
	REC__Track_q = REC__Track->getByte("q",row);
	REC__Track_chi2 = REC__Track->getFloat("chi2",row);
	REC__Track_NDF = REC__Track->getShort("NDF",row);
	return 0;
} 

int get_TimeBasedTrkg__TBCrosses(int row){
	TimeBasedTrkg__TBCrosses_id = TimeBasedTrkg__TBCrosses->getShort("id",row);
	TimeBasedTrkg__TBCrosses_status = TimeBasedTrkg__TBCrosses->getShort("status",row);
	TimeBasedTrkg__TBCrosses_sector = TimeBasedTrkg__TBCrosses->getByte("sector",row);
	TimeBasedTrkg__TBCrosses_region = TimeBasedTrkg__TBCrosses->getByte("region",row);
	TimeBasedTrkg__TBCrosses_x = TimeBasedTrkg__TBCrosses->getFloat("x",row);
	TimeBasedTrkg__TBCrosses_y = TimeBasedTrkg__TBCrosses->getFloat("y",row);
	TimeBasedTrkg__TBCrosses_z = TimeBasedTrkg__TBCrosses->getFloat("z",row);
	TimeBasedTrkg__TBCrosses_err_x = TimeBasedTrkg__TBCrosses->getFloat("err_x",row);
	TimeBasedTrkg__TBCrosses_err_y = TimeBasedTrkg__TBCrosses->getFloat("err_y",row);
	TimeBasedTrkg__TBCrosses_err_z = TimeBasedTrkg__TBCrosses->getFloat("err_z",row);
	TimeBasedTrkg__TBCrosses_ux = TimeBasedTrkg__TBCrosses->getFloat("ux",row);
	TimeBasedTrkg__TBCrosses_uy = TimeBasedTrkg__TBCrosses->getFloat("uy",row);
	TimeBasedTrkg__TBCrosses_uz = TimeBasedTrkg__TBCrosses->getFloat("uz",row);
	TimeBasedTrkg__TBCrosses_err_ux = TimeBasedTrkg__TBCrosses->getFloat("err_ux",row);
	TimeBasedTrkg__TBCrosses_err_uy = TimeBasedTrkg__TBCrosses->getFloat("err_uy",row);
	TimeBasedTrkg__TBCrosses_err_uz = TimeBasedTrkg__TBCrosses->getFloat("err_uz",row);
	TimeBasedTrkg__TBCrosses_Segment1_ID = TimeBasedTrkg__TBCrosses->getShort("Segment1_ID",row);
	TimeBasedTrkg__TBCrosses_Segment2_ID = TimeBasedTrkg__TBCrosses->getShort("Segment2_ID",row);
	return 0;
} 

int get_FTCAL__adc(int row){
	FTCAL__adc_sector = FTCAL__adc->getByte("sector",row);
	FTCAL__adc_layer = FTCAL__adc->getByte("layer",row);
	FTCAL__adc_component = FTCAL__adc->getShort("component",row);
	FTCAL__adc_order = FTCAL__adc->getByte("order",row);
	FTCAL__adc_ADC = FTCAL__adc->getInt("ADC",row);
	FTCAL__adc_time = FTCAL__adc->getFloat("time",row);
	FTCAL__adc_ped = FTCAL__adc->getShort("ped",row);
	return 0;
} 

int get_CND__adc(int row){
	CND__adc_sector = CND__adc->getByte("sector",row);
	CND__adc_layer = CND__adc->getByte("layer",row);
	CND__adc_component = CND__adc->getShort("component",row);
	CND__adc_order = CND__adc->getByte("order",row);
	CND__adc_ADC = CND__adc->getInt("ADC",row);
	CND__adc_time = CND__adc->getFloat("time",row);
	CND__adc_ped = CND__adc->getShort("ped",row);
	return 0;
} 

int get_FTOF__hits(int row){
	FTOF__hits_id = FTOF__hits->getShort("id",row);
	FTOF__hits_status = FTOF__hits->getShort("status",row);
	FTOF__hits_trackid = FTOF__hits->getShort("trackid",row);
	FTOF__hits_sector = FTOF__hits->getByte("sector",row);
	FTOF__hits_layer = FTOF__hits->getByte("layer",row);
	FTOF__hits_component = FTOF__hits->getShort("component",row);
	FTOF__hits_energy = FTOF__hits->getFloat("energy",row);
	FTOF__hits_time = FTOF__hits->getFloat("time",row);
	FTOF__hits_energy_unc = FTOF__hits->getFloat("energy_unc",row);
	FTOF__hits_time_unc = FTOF__hits->getFloat("time_unc",row);
	FTOF__hits_x = FTOF__hits->getFloat("x",row);
	FTOF__hits_y = FTOF__hits->getFloat("y",row);
	FTOF__hits_z = FTOF__hits->getFloat("z",row);
	FTOF__hits_x_unc = FTOF__hits->getFloat("x_unc",row);
	FTOF__hits_y_unc = FTOF__hits->getFloat("y_unc",row);
	FTOF__hits_z_unc = FTOF__hits->getFloat("z_unc",row);
	FTOF__hits_tx = FTOF__hits->getFloat("tx",row);
	FTOF__hits_ty = FTOF__hits->getFloat("ty",row);
	FTOF__hits_tz = FTOF__hits->getFloat("tz",row);
	FTOF__hits_adc_idx1 = FTOF__hits->getShort("adc_idx1",row);
	FTOF__hits_adc_idx2 = FTOF__hits->getShort("adc_idx2",row);
	FTOF__hits_tdc_idx1 = FTOF__hits->getShort("tdc_idx1",row);
	FTOF__hits_tdc_idx2 = FTOF__hits->getShort("tdc_idx2",row);
	FTOF__hits_pathLength = FTOF__hits->getFloat("pathLength",row);
	FTOF__hits_pathLengthThruBar = FTOF__hits->getFloat("pathLengthThruBar",row);
	return 0;
} 

int get_REC__ForwardTagger(int row){
	REC__ForwardTagger_index = REC__ForwardTagger->getShort("index",row);
	REC__ForwardTagger_pindex = REC__ForwardTagger->getShort("pindex",row);
	REC__ForwardTagger_detector = REC__ForwardTagger->getByte("detector",row);
	REC__ForwardTagger_layer = REC__ForwardTagger->getByte("layer",row);
	REC__ForwardTagger_energy = REC__ForwardTagger->getFloat("energy",row);
	REC__ForwardTagger_time = REC__ForwardTagger->getFloat("time",row);
	REC__ForwardTagger_path = REC__ForwardTagger->getFloat("path",row);
	REC__ForwardTagger_chi2 = REC__ForwardTagger->getFloat("chi2",row);
	REC__ForwardTagger_x = REC__ForwardTagger->getFloat("x",row);
	REC__ForwardTagger_y = REC__ForwardTagger->getFloat("y",row);
	REC__ForwardTagger_z = REC__ForwardTagger->getFloat("z",row);
	REC__ForwardTagger_dx = REC__ForwardTagger->getFloat("dx",row);
	REC__ForwardTagger_dy = REC__ForwardTagger->getFloat("dy",row);
	REC__ForwardTagger_radius = REC__ForwardTagger->getFloat("radius",row);
	REC__ForwardTagger_size = REC__ForwardTagger->getShort("size",row);
	REC__ForwardTagger_status = REC__ForwardTagger->getShort("status",row);
	return 0;
} 

int get_TimeBasedTrkg__TBSegmentTrajectory(int row){
	TimeBasedTrkg__TBSegmentTrajectory_segmentID = TimeBasedTrkg__TBSegmentTrajectory->getShort("segmentID",row);
	TimeBasedTrkg__TBSegmentTrajectory_sector = TimeBasedTrkg__TBSegmentTrajectory->getByte("sector",row);
	TimeBasedTrkg__TBSegmentTrajectory_superlayer = TimeBasedTrkg__TBSegmentTrajectory->getByte("superlayer",row);
	TimeBasedTrkg__TBSegmentTrajectory_layer = TimeBasedTrkg__TBSegmentTrajectory->getByte("layer",row);
	TimeBasedTrkg__TBSegmentTrajectory_matchedHitID = TimeBasedTrkg__TBSegmentTrajectory->getShort("matchedHitID",row);
	TimeBasedTrkg__TBSegmentTrajectory_trkDoca = TimeBasedTrkg__TBSegmentTrajectory->getFloat("trkDoca",row);
	return 0;
} 

int get_CTOF__tdc(int row){
	CTOF__tdc_sector = CTOF__tdc->getByte("sector",row);
	CTOF__tdc_layer = CTOF__tdc->getByte("layer",row);
	CTOF__tdc_component = CTOF__tdc->getShort("component",row);
	CTOF__tdc_order = CTOF__tdc->getByte("order",row);
	CTOF__tdc_TDC = CTOF__tdc->getInt("TDC",row);
	return 0;
} 

int get_REC__Cherenkov(int row){
	REC__Cherenkov_index = REC__Cherenkov->getShort("index",row);
	REC__Cherenkov_pindex = REC__Cherenkov->getShort("pindex",row);
	REC__Cherenkov_detector = REC__Cherenkov->getByte("detector",row);
	REC__Cherenkov_sector = REC__Cherenkov->getByte("sector",row);
	REC__Cherenkov_nphe = REC__Cherenkov->getFloat("nphe",row);
	REC__Cherenkov_time = REC__Cherenkov->getFloat("time",row);
	REC__Cherenkov_path = REC__Cherenkov->getFloat("path",row);
	REC__Cherenkov_chi2 = REC__Cherenkov->getFloat("chi2",row);
	REC__Cherenkov_x = REC__Cherenkov->getFloat("x",row);
	REC__Cherenkov_y = REC__Cherenkov->getFloat("y",row);
	REC__Cherenkov_z = REC__Cherenkov->getFloat("z",row);
	REC__Cherenkov_dtheta = REC__Cherenkov->getFloat("dtheta",row);
	REC__Cherenkov_dphi = REC__Cherenkov->getFloat("dphi",row);
	REC__Cherenkov_status = REC__Cherenkov->getShort("status",row);
	return 0;
} 

int get_FTHODO__hits(int row){
	FTHODO__hits_sector = FTHODO__hits->getByte("sector",row);
	FTHODO__hits_layer = FTHODO__hits->getByte("layer",row);
	FTHODO__hits_component = FTHODO__hits->getShort("component",row);
	FTHODO__hits_x = FTHODO__hits->getFloat("x",row);
	FTHODO__hits_y = FTHODO__hits->getFloat("y",row);
	FTHODO__hits_z = FTHODO__hits->getFloat("z",row);
	FTHODO__hits_energy = FTHODO__hits->getFloat("energy",row);
	FTHODO__hits_time = FTHODO__hits->getFloat("time",row);
	FTHODO__hits_hitID = FTHODO__hits->getShort("hitID",row);
	FTHODO__hits_clusterID = FTHODO__hits->getShort("clusterID",row);
	return 0;
} 

int get_RECFT__Event(int row){
	RECFT__Event_EvCAT = RECFT__Event->getShort("EvCAT",row);
	RECFT__Event_startTime = RECFT__Event->getFloat("startTime",row);
	return 0;
} 

int get_FTOF__adc(int row){
	FTOF__adc_sector = FTOF__adc->getByte("sector",row);
	FTOF__adc_layer = FTOF__adc->getByte("layer",row);
	FTOF__adc_component = FTOF__adc->getShort("component",row);
	FTOF__adc_order = FTOF__adc->getByte("order",row);
	FTOF__adc_ADC = FTOF__adc->getInt("ADC",row);
	FTOF__adc_time = FTOF__adc->getFloat("time",row);
	FTOF__adc_ped = FTOF__adc->getShort("ped",row);
	return 0;
} 

int get_MC__Lund(int row){
	MC__Lund_index = MC__Lund->getByte("index",row);
	MC__Lund_lifetime = MC__Lund->getFloat("lifetime",row);
	MC__Lund_type = MC__Lund->getByte("type",row);
	MC__Lund_pid = MC__Lund->getInt("pid",row);
	MC__Lund_parent = MC__Lund->getByte("parent",row);
	MC__Lund_daughter = MC__Lund->getByte("daughter",row);
	MC__Lund_px = MC__Lund->getFloat("px",row);
	MC__Lund_py = MC__Lund->getFloat("py",row);
	MC__Lund_pz = MC__Lund->getFloat("pz",row);
	MC__Lund_energy = MC__Lund->getFloat("energy",row);
	MC__Lund_mass = MC__Lund->getFloat("mass",row);
	MC__Lund_vx = MC__Lund->getFloat("vx",row);
	MC__Lund_vy = MC__Lund->getFloat("vy",row);
	MC__Lund_vz = MC__Lund->getFloat("vz",row);
	return 0;
} 

int get_CTOF__adc(int row){
	CTOF__adc_sector = CTOF__adc->getByte("sector",row);
	CTOF__adc_layer = CTOF__adc->getByte("layer",row);
	CTOF__adc_component = CTOF__adc->getShort("component",row);
	CTOF__adc_order = CTOF__adc->getByte("order",row);
	CTOF__adc_ADC = CTOF__adc->getInt("ADC",row);
	CTOF__adc_time = CTOF__adc->getFloat("time",row);
	CTOF__adc_ped = CTOF__adc->getShort("ped",row);
	return 0;
} 

int get_MC__Header(int row){
	MC__Header_run = MC__Header->getInt("run",row);
	MC__Header_event = MC__Header->getInt("event",row);
	MC__Header_type = MC__Header->getByte("type",row);
	MC__Header_helicity = MC__Header->getFloat("helicity",row);
	return 0;
} 

int get_HEL__online(int row){
	HEL__online_helicity = HEL__online->getByte("helicity",row);
	HEL__online_helicityRaw = HEL__online->getByte("helicityRaw",row);
	return 0;
} 

int get_REC__Event(int row){
	REC__Event_category = REC__Event->getLong("category",row);
	REC__Event_topology = REC__Event->getLong("topology",row);
	REC__Event_beamCharge = REC__Event->getFloat("beamCharge",row);
	REC__Event_liveTime = REC__Event->getDouble("liveTime",row);
	REC__Event_startTime = REC__Event->getFloat("startTime",row);
	REC__Event_RFTime = REC__Event->getFloat("RFTime",row);
	REC__Event_helicity = REC__Event->getByte("helicity",row);
	REC__Event_helicityRaw = REC__Event->getByte("helicityRaw",row);
	REC__Event_procTime = REC__Event->getFloat("procTime",row);
	return 0;
} 

int get_REC__Particle(int row){
	REC__Particle_pid = REC__Particle->getInt("pid",row);
	REC__Particle_px = REC__Particle->getFloat("px",row);
	REC__Particle_py = REC__Particle->getFloat("py",row);
	REC__Particle_pz = REC__Particle->getFloat("pz",row);
	REC__Particle_vx = REC__Particle->getFloat("vx",row);
	REC__Particle_vy = REC__Particle->getFloat("vy",row);
	REC__Particle_vz = REC__Particle->getFloat("vz",row);
	REC__Particle_charge = REC__Particle->getByte("charge",row);
	REC__Particle_beta = REC__Particle->getFloat("beta",row);
	REC__Particle_chi2pid = REC__Particle->getFloat("chi2pid",row);
	REC__Particle_status = REC__Particle->getShort("status",row);
	return 0;
} 

int get_REC__Traj(int row){
	REC__Traj_pindex = REC__Traj->getShort("pindex",row);
	REC__Traj_index = REC__Traj->getShort("index",row);
	REC__Traj_detector = REC__Traj->getByte("detector",row);
	REC__Traj_layer = REC__Traj->getByte("layer",row);
	REC__Traj_x = REC__Traj->getFloat("x",row);
	REC__Traj_y = REC__Traj->getFloat("y",row);
	REC__Traj_z = REC__Traj->getFloat("z",row);
	REC__Traj_cx = REC__Traj->getFloat("cx",row);
	REC__Traj_cy = REC__Traj->getFloat("cy",row);
	REC__Traj_cz = REC__Traj->getFloat("cz",row);
	REC__Traj_path = REC__Traj->getFloat("path",row);
	return 0;
} 

int get_FTOF__tdc(int row){
	FTOF__tdc_sector = FTOF__tdc->getByte("sector",row);
	FTOF__tdc_layer = FTOF__tdc->getByte("layer",row);
	FTOF__tdc_component = FTOF__tdc->getShort("component",row);
	FTOF__tdc_order = FTOF__tdc->getByte("order",row);
	FTOF__tdc_TDC = FTOF__tdc->getInt("TDC",row);
	return 0;
} 

int get_RICH__hits(int row){
	RICH__hits_id = RICH__hits->getShort("id",row);
	RICH__hits_sector = RICH__hits->getShort("sector",row);
	RICH__hits_tile = RICH__hits->getShort("tile",row);
	RICH__hits_pmt = RICH__hits->getShort("pmt",row);
	RICH__hits_anode = RICH__hits->getShort("anode",row);
	RICH__hits_x = RICH__hits->getFloat("x",row);
	RICH__hits_y = RICH__hits->getFloat("y",row);
	RICH__hits_z = RICH__hits->getFloat("z",row);
	RICH__hits_time = RICH__hits->getFloat("time",row);
	RICH__hits_rawtime = RICH__hits->getFloat("rawtime",row);
	RICH__hits_cluster = RICH__hits->getShort("cluster",row);
	RICH__hits_xtalk = RICH__hits->getShort("xtalk",row);
	RICH__hits_duration = RICH__hits->getShort("duration",row);
	return 0;
} 

int get_MC__True(int row){
	MC__True_detector = MC__True->getByte("detector",row);
	MC__True_pid = MC__True->getInt("pid",row);
	MC__True_mpid = MC__True->getInt("mpid",row);
	MC__True_tid = MC__True->getInt("tid",row);
	MC__True_mtid = MC__True->getInt("mtid",row);
	MC__True_otid = MC__True->getInt("otid",row);
	MC__True_trackE = MC__True->getFloat("trackE",row);
	MC__True_totEdep = MC__True->getFloat("totEdep",row);
	MC__True_avgX = MC__True->getFloat("avgX",row);
	MC__True_avgY = MC__True->getFloat("avgY",row);
	MC__True_avgZ = MC__True->getFloat("avgZ",row);
	MC__True_avgLx = MC__True->getFloat("avgLx",row);
	MC__True_avgLy = MC__True->getFloat("avgLy",row);
	MC__True_avgLz = MC__True->getFloat("avgLz",row);
	MC__True_px = MC__True->getFloat("px",row);
	MC__True_py = MC__True->getFloat("py",row);
	MC__True_pz = MC__True->getFloat("pz",row);
	MC__True_vx = MC__True->getFloat("vx",row);
	MC__True_vy = MC__True->getFloat("vy",row);
	MC__True_vz = MC__True->getFloat("vz",row);
	MC__True_mvx = MC__True->getFloat("mvx",row);
	MC__True_mvy = MC__True->getFloat("mvy",row);
	MC__True_mvz = MC__True->getFloat("mvz",row);
	MC__True_avgT = MC__True->getFloat("avgT",row);
	MC__True_nsteps = MC__True->getInt("nsteps",row);
	MC__True_procID = MC__True->getInt("procID",row);
	MC__True_hitn = MC__True->getInt("hitn",row);
	return 0;
} 

int get_FTCAL__hits(int row){
	FTCAL__hits_idx = FTCAL__hits->getByte("idx",row);
	FTCAL__hits_idy = FTCAL__hits->getByte("idy",row);
	FTCAL__hits_x = FTCAL__hits->getFloat("x",row);
	FTCAL__hits_y = FTCAL__hits->getFloat("y",row);
	FTCAL__hits_z = FTCAL__hits->getFloat("z",row);
	FTCAL__hits_energy = FTCAL__hits->getFloat("energy",row);
	FTCAL__hits_time = FTCAL__hits->getFloat("time",row);
	FTCAL__hits_hitID = FTCAL__hits->getShort("hitID",row);
	FTCAL__hits_clusterID = FTCAL__hits->getShort("clusterID",row);
	return 0;
} 

int get_MC__Event(int row){
	MC__Event_npart = MC__Event->getShort("npart",row);
	MC__Event_atarget = MC__Event->getShort("atarget",row);
	MC__Event_ztarget = MC__Event->getShort("ztarget",row);
	MC__Event_ptarget = MC__Event->getFloat("ptarget",row);
	MC__Event_pbeam = MC__Event->getFloat("pbeam",row);
	MC__Event_btype = MC__Event->getShort("btype",row);
	MC__Event_ebeam = MC__Event->getFloat("ebeam",row);
	MC__Event_targetid = MC__Event->getShort("targetid",row);
	MC__Event_processid = MC__Event->getShort("processid",row);
	MC__Event_weight = MC__Event->getFloat("weight",row);
	return 0;
} 

int get_BAND__tdc(int row){
	BAND__tdc_sector = BAND__tdc->getByte("sector",row);
	BAND__tdc_layer = BAND__tdc->getByte("layer",row);
	BAND__tdc_component = BAND__tdc->getShort("component",row);
	BAND__tdc_order = BAND__tdc->getByte("order",row);
	BAND__tdc_TDC = BAND__tdc->getInt("TDC",row);
	return 0;
} 

int get_RF__adc(int row){
	RF__adc_sector = RF__adc->getByte("sector",row);
	RF__adc_layer = RF__adc->getByte("layer",row);
	RF__adc_component = RF__adc->getShort("component",row);
	RF__adc_order = RF__adc->getByte("order",row);
	RF__adc_ADC = RF__adc->getInt("ADC",row);
	RF__adc_time = RF__adc->getFloat("time",row);
	RF__adc_ped = RF__adc->getShort("ped",row);
	return 0;
} 

int get_REC__Scintillator(int row){
	REC__Scintillator_index = REC__Scintillator->getShort("index",row);
	REC__Scintillator_pindex = REC__Scintillator->getShort("pindex",row);
	REC__Scintillator_detector = REC__Scintillator->getByte("detector",row);
	REC__Scintillator_sector = REC__Scintillator->getByte("sector",row);
	REC__Scintillator_layer = REC__Scintillator->getByte("layer",row);
	REC__Scintillator_component = REC__Scintillator->getShort("component",row);
	REC__Scintillator_energy = REC__Scintillator->getFloat("energy",row);
	REC__Scintillator_time = REC__Scintillator->getFloat("time",row);
	REC__Scintillator_path = REC__Scintillator->getFloat("path",row);
	REC__Scintillator_chi2 = REC__Scintillator->getFloat("chi2",row);
	REC__Scintillator_x = REC__Scintillator->getFloat("x",row);
	REC__Scintillator_y = REC__Scintillator->getFloat("y",row);
	REC__Scintillator_z = REC__Scintillator->getFloat("z",row);
	REC__Scintillator_hx = REC__Scintillator->getFloat("hx",row);
	REC__Scintillator_hy = REC__Scintillator->getFloat("hy",row);
	REC__Scintillator_hz = REC__Scintillator->getFloat("hz",row);
	REC__Scintillator_status = REC__Scintillator->getShort("status",row);
	return 0;
} 

int get_ECAL__peaks(int row){
	ECAL__peaks_id = ECAL__peaks->getShort("id",row);
	ECAL__peaks_status = ECAL__peaks->getShort("status",row);
	ECAL__peaks_sector = ECAL__peaks->getByte("sector",row);
	ECAL__peaks_layer = ECAL__peaks->getByte("layer",row);
	ECAL__peaks_energy = ECAL__peaks->getFloat("energy",row);
	ECAL__peaks_time = ECAL__peaks->getFloat("time",row);
	ECAL__peaks_xo = ECAL__peaks->getFloat("xo",row);
	ECAL__peaks_yo = ECAL__peaks->getFloat("yo",row);
	ECAL__peaks_zo = ECAL__peaks->getFloat("zo",row);
	ECAL__peaks_xe = ECAL__peaks->getFloat("xe",row);
	ECAL__peaks_ye = ECAL__peaks->getFloat("ye",row);
	ECAL__peaks_ze = ECAL__peaks->getFloat("ze",row);
	ECAL__peaks_width = ECAL__peaks->getFloat("width",row);
	return 0;
} 

int get_MC__Particle(int row){
	MC__Particle_pid = MC__Particle->getInt("pid",row);
	MC__Particle_px = MC__Particle->getFloat("px",row);
	MC__Particle_py = MC__Particle->getFloat("py",row);
	MC__Particle_pz = MC__Particle->getFloat("pz",row);
	MC__Particle_vx = MC__Particle->getFloat("vx",row);
	MC__Particle_vy = MC__Particle->getFloat("vy",row);
	MC__Particle_vz = MC__Particle->getFloat("vz",row);
	MC__Particle_vt = MC__Particle->getFloat("vt",row);
	return 0;
} 

int get_ECAL__tdc(int row){
	ECAL__tdc_sector = ECAL__tdc->getByte("sector",row);
	ECAL__tdc_layer = ECAL__tdc->getByte("layer",row);
	ECAL__tdc_component = ECAL__tdc->getShort("component",row);
	ECAL__tdc_order = ECAL__tdc->getByte("order",row);
	ECAL__tdc_TDC = ECAL__tdc->getInt("TDC",row);
	return 0;
} 

int get_RICH__tdc(int row){
	RICH__tdc_sector = RICH__tdc->getByte("sector",row);
	RICH__tdc_layer = RICH__tdc->getByte("layer",row);
	RICH__tdc_component = RICH__tdc->getShort("component",row);
	RICH__tdc_order = RICH__tdc->getByte("order",row);
	RICH__tdc_TDC = RICH__tdc->getInt("TDC",row);
	return 0;
} 

int get_LTCC__clusters(int row){
	LTCC__clusters_id = LTCC__clusters->getShort("id",row);
	LTCC__clusters_status = LTCC__clusters->getByte("status",row);
	LTCC__clusters_sector = LTCC__clusters->getByte("sector",row);
	LTCC__clusters_segment = LTCC__clusters->getShort("segment",row);
	LTCC__clusters_x = LTCC__clusters->getFloat("x",row);
	LTCC__clusters_y = LTCC__clusters->getFloat("y",row);
	LTCC__clusters_z = LTCC__clusters->getFloat("z",row);
	LTCC__clusters_nphe = LTCC__clusters->getFloat("nphe",row);
	LTCC__clusters_time = LTCC__clusters->getFloat("time",row);
	LTCC__clusters_nHits = LTCC__clusters->getShort("nHits",row);
	LTCC__clusters_minTheta = LTCC__clusters->getFloat("minTheta",row);
	LTCC__clusters_maxTheta = LTCC__clusters->getFloat("maxTheta",row);
	LTCC__clusters_minPhi = LTCC__clusters->getFloat("minPhi",row);
	LTCC__clusters_maxPhi = LTCC__clusters->getFloat("maxPhi",row);
	return 0;
} 

int get_RICH__hadrons(int row){
	RICH__hadrons_id = RICH__hadrons->getShort("id",row);
	RICH__hadrons_hit_index = RICH__hadrons->getShort("hit_index",row);
	RICH__hadrons_particle_index = RICH__hadrons->getShort("particle_index",row);
	RICH__hadrons_traced_the = RICH__hadrons->getFloat("traced_the",row);
	RICH__hadrons_traced_phi = RICH__hadrons->getFloat("traced_phi",row);
	RICH__hadrons_traced_hitx = RICH__hadrons->getFloat("traced_hitx",row);
	RICH__hadrons_traced_hity = RICH__hadrons->getFloat("traced_hity",row);
	RICH__hadrons_traced_hitz = RICH__hadrons->getFloat("traced_hitz",row);
	RICH__hadrons_traced_time = RICH__hadrons->getFloat("traced_time",row);
	RICH__hadrons_traced_path = RICH__hadrons->getFloat("traced_path",row);
	RICH__hadrons_traced_ilay = RICH__hadrons->getShort("traced_ilay",row);
	RICH__hadrons_traced_ico = RICH__hadrons->getShort("traced_ico",row);
	RICH__hadrons_traced_emix = RICH__hadrons->getFloat("traced_emix",row);
	RICH__hadrons_traced_emiy = RICH__hadrons->getFloat("traced_emiy",row);
	RICH__hadrons_traced_emiz = RICH__hadrons->getFloat("traced_emiz",row);
	RICH__hadrons_EtaC_ele = RICH__hadrons->getFloat("EtaC_ele",row);
	RICH__hadrons_EtaC_pi = RICH__hadrons->getFloat("EtaC_pi",row);
	RICH__hadrons_EtaC_k = RICH__hadrons->getFloat("EtaC_k",row);
	RICH__hadrons_EtaC_pr = RICH__hadrons->getFloat("EtaC_pr",row);
	RICH__hadrons_EtaC_min = RICH__hadrons->getFloat("EtaC_min",row);
	RICH__hadrons_EtaC_max = RICH__hadrons->getFloat("EtaC_max",row);
	return 0;
} 

int get_FTHODO__adc(int row){
	FTHODO__adc_sector = FTHODO__adc->getByte("sector",row);
	FTHODO__adc_layer = FTHODO__adc->getByte("layer",row);
	FTHODO__adc_component = FTHODO__adc->getShort("component",row);
	FTHODO__adc_order = FTHODO__adc->getByte("order",row);
	FTHODO__adc_ADC = FTHODO__adc->getInt("ADC",row);
	FTHODO__adc_time = FTHODO__adc->getFloat("time",row);
	FTHODO__adc_ped = FTHODO__adc->getShort("ped",row);
	return 0;
} 

int get_HTCC__rec(int row){
	HTCC__rec_id = HTCC__rec->getShort("id",row);
	HTCC__rec_nhits = HTCC__rec->getShort("nhits",row);
	HTCC__rec_nphe = HTCC__rec->getFloat("nphe",row);
	HTCC__rec_ntheta = HTCC__rec->getShort("ntheta",row);
	HTCC__rec_nphi = HTCC__rec->getShort("nphi",row);
	HTCC__rec_mintheta = HTCC__rec->getShort("mintheta",row);
	HTCC__rec_maxtheta = HTCC__rec->getShort("maxtheta",row);
	HTCC__rec_minphi = HTCC__rec->getShort("minphi",row);
	HTCC__rec_maxphi = HTCC__rec->getShort("maxphi",row);
	HTCC__rec_time = HTCC__rec->getFloat("time",row);
	HTCC__rec_theta = HTCC__rec->getFloat("theta",row);
	HTCC__rec_dtheta = HTCC__rec->getFloat("dtheta",row);
	HTCC__rec_phi = HTCC__rec->getFloat("phi",row);
	HTCC__rec_dphi = HTCC__rec->getFloat("dphi",row);
	HTCC__rec_x = HTCC__rec->getFloat("x",row);
	HTCC__rec_y = HTCC__rec->getFloat("y",row);
	HTCC__rec_z = HTCC__rec->getFloat("z",row);
	return 0;
} 

int get_RUN__trigger(int row){
	RUN__trigger_id = RUN__trigger->getInt("id",row);
	RUN__trigger_trigger = RUN__trigger->getInt("trigger",row);
	return 0;
} 

int get_ECAL__adc(int row){
	ECAL__adc_sector = ECAL__adc->getByte("sector",row);
	ECAL__adc_layer = ECAL__adc->getByte("layer",row);
	ECAL__adc_component = ECAL__adc->getShort("component",row);
	ECAL__adc_order = ECAL__adc->getByte("order",row);
	ECAL__adc_ADC = ECAL__adc->getInt("ADC",row);
	ECAL__adc_time = ECAL__adc->getFloat("time",row);
	ECAL__adc_ped = ECAL__adc->getShort("ped",row);
	return 0;
} 

int get_ECAL__calib(int row){
	ECAL__calib_sector = ECAL__calib->getByte("sector",row);
	ECAL__calib_layer = ECAL__calib->getByte("layer",row);
	ECAL__calib_energy = ECAL__calib->getFloat("energy",row);
	ECAL__calib_rawEU = ECAL__calib->getFloat("rawEU",row);
	ECAL__calib_rawEV = ECAL__calib->getFloat("rawEV",row);
	ECAL__calib_rawEW = ECAL__calib->getFloat("rawEW",row);
	ECAL__calib_recEU = ECAL__calib->getFloat("recEU",row);
	ECAL__calib_recEV = ECAL__calib->getFloat("recEV",row);
	ECAL__calib_recEW = ECAL__calib->getFloat("recEW",row);
	return 0;
} 

int get_RUN__rf(int row){
	RUN__rf_id = RUN__rf->getShort("id",row);
	RUN__rf_time = RUN__rf->getFloat("time",row);
	return 0;
} 

int get_LTCC__adc(int row){
	LTCC__adc_sector = LTCC__adc->getByte("sector",row);
	LTCC__adc_layer = LTCC__adc->getByte("layer",row);
	LTCC__adc_component = LTCC__adc->getShort("component",row);
	LTCC__adc_order = LTCC__adc->getByte("order",row);
	LTCC__adc_ADC = LTCC__adc->getInt("ADC",row);
	LTCC__adc_time = LTCC__adc->getFloat("time",row);
	LTCC__adc_ped = LTCC__adc->getShort("ped",row);
	return 0;
} 

int get_TimeBasedTrkg__TBHits(int row){
	TimeBasedTrkg__TBHits_id = TimeBasedTrkg__TBHits->getShort("id",row);
	TimeBasedTrkg__TBHits_status = TimeBasedTrkg__TBHits->getShort("status",row);
	TimeBasedTrkg__TBHits_sector = TimeBasedTrkg__TBHits->getByte("sector",row);
	TimeBasedTrkg__TBHits_superlayer = TimeBasedTrkg__TBHits->getByte("superlayer",row);
	TimeBasedTrkg__TBHits_layer = TimeBasedTrkg__TBHits->getByte("layer",row);
	TimeBasedTrkg__TBHits_wire = TimeBasedTrkg__TBHits->getShort("wire",row);
	TimeBasedTrkg__TBHits_TDC = TimeBasedTrkg__TBHits->getInt("TDC",row);
	TimeBasedTrkg__TBHits_doca = TimeBasedTrkg__TBHits->getFloat("doca",row);
	TimeBasedTrkg__TBHits_docaError = TimeBasedTrkg__TBHits->getFloat("docaError",row);
	TimeBasedTrkg__TBHits_trkDoca = TimeBasedTrkg__TBHits->getFloat("trkDoca",row);
	TimeBasedTrkg__TBHits_timeResidual = TimeBasedTrkg__TBHits->getFloat("timeResidual",row);
	TimeBasedTrkg__TBHits_fitResidual = TimeBasedTrkg__TBHits->getFloat("fitResidual",row);
	TimeBasedTrkg__TBHits_LR = TimeBasedTrkg__TBHits->getByte("LR",row);
	TimeBasedTrkg__TBHits_X = TimeBasedTrkg__TBHits->getFloat("X",row);
	TimeBasedTrkg__TBHits_Z = TimeBasedTrkg__TBHits->getFloat("Z",row);
	TimeBasedTrkg__TBHits_B = TimeBasedTrkg__TBHits->getFloat("B",row);
	TimeBasedTrkg__TBHits_Alpha = TimeBasedTrkg__TBHits->getFloat("Alpha",row);
	TimeBasedTrkg__TBHits_TProp = TimeBasedTrkg__TBHits->getFloat("TProp",row);
	TimeBasedTrkg__TBHits_TFlight = TimeBasedTrkg__TBHits->getFloat("TFlight",row);
	TimeBasedTrkg__TBHits_T0 = TimeBasedTrkg__TBHits->getFloat("T0",row);
	TimeBasedTrkg__TBHits_TStart = TimeBasedTrkg__TBHits->getFloat("TStart",row);
	TimeBasedTrkg__TBHits_clusterID = TimeBasedTrkg__TBHits->getShort("clusterID",row);
	TimeBasedTrkg__TBHits_trkID = TimeBasedTrkg__TBHits->getByte("trkID",row);
	TimeBasedTrkg__TBHits_time = TimeBasedTrkg__TBHits->getFloat("time",row);
	TimeBasedTrkg__TBHits_beta = TimeBasedTrkg__TBHits->getFloat("beta",row);
	TimeBasedTrkg__TBHits_tBeta = TimeBasedTrkg__TBHits->getFloat("tBeta",row);
	return 0;
} 

int get_HTCC__adc(int row){
	HTCC__adc_sector = HTCC__adc->getByte("sector",row);
	HTCC__adc_layer = HTCC__adc->getByte("layer",row);
	HTCC__adc_component = HTCC__adc->getShort("component",row);
	HTCC__adc_order = HTCC__adc->getByte("order",row);
	HTCC__adc_ADC = HTCC__adc->getInt("ADC",row);
	HTCC__adc_time = HTCC__adc->getFloat("time",row);
	HTCC__adc_ped = HTCC__adc->getShort("ped",row);
	return 0;
} 

int get_CTOF__hits(int row){
	CTOF__hits_id = CTOF__hits->getShort("id",row);
	CTOF__hits_status = CTOF__hits->getShort("status",row);
	CTOF__hits_trkID = CTOF__hits->getShort("trkID",row);
	CTOF__hits_sector = CTOF__hits->getByte("sector",row);
	CTOF__hits_layer = CTOF__hits->getByte("layer",row);
	CTOF__hits_component = CTOF__hits->getShort("component",row);
	CTOF__hits_energy = CTOF__hits->getFloat("energy",row);
	CTOF__hits_time = CTOF__hits->getFloat("time",row);
	CTOF__hits_energy_unc = CTOF__hits->getFloat("energy_unc",row);
	CTOF__hits_time_unc = CTOF__hits->getFloat("time_unc",row);
	CTOF__hits_x = CTOF__hits->getFloat("x",row);
	CTOF__hits_y = CTOF__hits->getFloat("y",row);
	CTOF__hits_z = CTOF__hits->getFloat("z",row);
	CTOF__hits_x_unc = CTOF__hits->getFloat("x_unc",row);
	CTOF__hits_y_unc = CTOF__hits->getFloat("y_unc",row);
	CTOF__hits_z_unc = CTOF__hits->getFloat("z_unc",row);
	CTOF__hits_tx = CTOF__hits->getFloat("tx",row);
	CTOF__hits_ty = CTOF__hits->getFloat("ty",row);
	CTOF__hits_tz = CTOF__hits->getFloat("tz",row);
	CTOF__hits_adc_idx1 = CTOF__hits->getShort("adc_idx1",row);
	CTOF__hits_adc_idx2 = CTOF__hits->getShort("adc_idx2",row);
	CTOF__hits_tdc_idx1 = CTOF__hits->getShort("tdc_idx1",row);
	CTOF__hits_tdc_idx2 = CTOF__hits->getShort("tdc_idx2",row);
	CTOF__hits_pathLength = CTOF__hits->getFloat("pathLength",row);
	CTOF__hits_pathLengthThruBar = CTOF__hits->getFloat("pathLengthThruBar",row);
	return 0;
} 

int get_CND__tdc(int row){
	CND__tdc_sector = CND__tdc->getByte("sector",row);
	CND__tdc_layer = CND__tdc->getByte("layer",row);
	CND__tdc_component = CND__tdc->getShort("component",row);
	CND__tdc_order = CND__tdc->getByte("order",row);
	CND__tdc_TDC = CND__tdc->getInt("TDC",row);
	return 0;
} 

int get_CVTRec__Tracks(int row){
	CVTRec__Tracks_ID = CVTRec__Tracks->getShort("ID",row);
	CVTRec__Tracks_fittingMethod = CVTRec__Tracks->getByte("fittingMethod",row);
	CVTRec__Tracks_c_x = CVTRec__Tracks->getFloat("c_x",row);
	CVTRec__Tracks_c_y = CVTRec__Tracks->getFloat("c_y",row);
	CVTRec__Tracks_c_z = CVTRec__Tracks->getFloat("c_z",row);
	CVTRec__Tracks_c_ux = CVTRec__Tracks->getFloat("c_ux",row);
	CVTRec__Tracks_c_uy = CVTRec__Tracks->getFloat("c_uy",row);
	CVTRec__Tracks_c_uz = CVTRec__Tracks->getFloat("c_uz",row);
	CVTRec__Tracks_pathlength = CVTRec__Tracks->getFloat("pathlength",row);
	CVTRec__Tracks_q = CVTRec__Tracks->getByte("q",row);
	CVTRec__Tracks_p = CVTRec__Tracks->getFloat("p",row);
	CVTRec__Tracks_pt = CVTRec__Tracks->getFloat("pt",row);
	CVTRec__Tracks_phi0 = CVTRec__Tracks->getFloat("phi0",row);
	CVTRec__Tracks_tandip = CVTRec__Tracks->getFloat("tandip",row);
	CVTRec__Tracks_z0 = CVTRec__Tracks->getFloat("z0",row);
	CVTRec__Tracks_d0 = CVTRec__Tracks->getFloat("d0",row);
	CVTRec__Tracks_cov_d02 = CVTRec__Tracks->getFloat("cov_d02",row);
	CVTRec__Tracks_cov_d0phi0 = CVTRec__Tracks->getFloat("cov_d0phi0",row);
	CVTRec__Tracks_cov_d0rho = CVTRec__Tracks->getFloat("cov_d0rho",row);
	CVTRec__Tracks_cov_phi02 = CVTRec__Tracks->getFloat("cov_phi02",row);
	CVTRec__Tracks_cov_phi0rho = CVTRec__Tracks->getFloat("cov_phi0rho",row);
	CVTRec__Tracks_cov_rho2 = CVTRec__Tracks->getFloat("cov_rho2",row);
	CVTRec__Tracks_cov_z02 = CVTRec__Tracks->getFloat("cov_z02",row);
	CVTRec__Tracks_cov_tandip2 = CVTRec__Tracks->getFloat("cov_tandip2",row);
	CVTRec__Tracks_circlefit_chi2_per_ndf = CVTRec__Tracks->getFloat("circlefit_chi2_per_ndf",row);
	CVTRec__Tracks_linefit_chi2_per_ndf = CVTRec__Tracks->getFloat("linefit_chi2_per_ndf",row);
	CVTRec__Tracks_chi2 = CVTRec__Tracks->getFloat("chi2",row);
	CVTRec__Tracks_ndf = CVTRec__Tracks->getShort("ndf",row);
	CVTRec__Tracks_Cross1_ID = CVTRec__Tracks->getShort("Cross1_ID",row);
	CVTRec__Tracks_Cross2_ID = CVTRec__Tracks->getShort("Cross2_ID",row);
	CVTRec__Tracks_Cross3_ID = CVTRec__Tracks->getShort("Cross3_ID",row);
	CVTRec__Tracks_Cross4_ID = CVTRec__Tracks->getShort("Cross4_ID",row);
	CVTRec__Tracks_Cross5_ID = CVTRec__Tracks->getShort("Cross5_ID",row);
	CVTRec__Tracks_Cross6_ID = CVTRec__Tracks->getShort("Cross6_ID",row);
	CVTRec__Tracks_Cross7_ID = CVTRec__Tracks->getShort("Cross7_ID",row);
	CVTRec__Tracks_Cross8_ID = CVTRec__Tracks->getShort("Cross8_ID",row);
	CVTRec__Tracks_Cross9_ID = CVTRec__Tracks->getShort("Cross9_ID",row);
	return 0;
} 

int get_RICH__photons(int row){
	RICH__photons_id = RICH__photons->getShort("id",row);
	RICH__photons_type = RICH__photons->getShort("type",row);
	RICH__photons_hit_index = RICH__photons->getShort("hit_index",row);
	RICH__photons_hadron_index = RICH__photons->getShort("hadron_index",row);
	RICH__photons_start_time = RICH__photons->getFloat("start_time",row);
	RICH__photons_analytic_the = RICH__photons->getFloat("analytic_the",row);
	RICH__photons_analytic_phi = RICH__photons->getFloat("analytic_phi",row);
	RICH__photons_analytic_path = RICH__photons->getFloat("analytic_path",row);
	RICH__photons_analytic_time = RICH__photons->getFloat("analytic_time",row);
	RICH__photons_analytic_EtaC = RICH__photons->getFloat("analytic_EtaC",row);
	RICH__photons_analytic_aeron = RICH__photons->getFloat("analytic_aeron",row);
	RICH__photons_analytic_elpr = RICH__photons->getFloat("analytic_elpr",row);
	RICH__photons_analytic_pipr = RICH__photons->getFloat("analytic_pipr",row);
	RICH__photons_analytic_kpr = RICH__photons->getFloat("analytic_kpr",row);
	RICH__photons_analytic_prpr = RICH__photons->getFloat("analytic_prpr",row);
	RICH__photons_analytic_bgpr = RICH__photons->getFloat("analytic_bgpr",row);
	RICH__photons_traced_the = RICH__photons->getFloat("traced_the",row);
	RICH__photons_traced_phi = RICH__photons->getFloat("traced_phi",row);
	RICH__photons_traced_hitx = RICH__photons->getFloat("traced_hitx",row);
	RICH__photons_traced_hity = RICH__photons->getFloat("traced_hity",row);
	RICH__photons_traced_hitz = RICH__photons->getFloat("traced_hitz",row);
	RICH__photons_traced_path = RICH__photons->getFloat("traced_path",row);
	RICH__photons_traced_time = RICH__photons->getFloat("traced_time",row);
	RICH__photons_traced_nrfl = RICH__photons->getShort("traced_nrfl",row);
	RICH__photons_traced_nrfr = RICH__photons->getShort("traced_nrfr",row);
	RICH__photons_traced_1rfl = RICH__photons->getShort("traced_1rfl",row);
	RICH__photons_traced_EtaC = RICH__photons->getFloat("traced_EtaC",row);
	RICH__photons_traced_aeron = RICH__photons->getFloat("traced_aeron",row);
	RICH__photons_traced_elpr = RICH__photons->getFloat("traced_elpr",row);
	RICH__photons_traced_pipr = RICH__photons->getFloat("traced_pipr",row);
	RICH__photons_traced_kpr = RICH__photons->getFloat("traced_kpr",row);
	RICH__photons_traced_prpr = RICH__photons->getFloat("traced_prpr",row);
	RICH__photons_traced_bgpr = RICH__photons->getFloat("traced_bgpr",row);
	return 0;
} 

int get_RECFT__Particle(int row){
	RECFT__Particle_pid = RECFT__Particle->getInt("pid",row);
	RECFT__Particle_beta = RECFT__Particle->getFloat("beta",row);
	RECFT__Particle_chi2pid = RECFT__Particle->getFloat("chi2pid",row);
	RECFT__Particle_status = RECFT__Particle->getShort("status",row);
	return 0;
} 

int get_HEL__flip(int row){
	HEL__flip_run = HEL__flip->getInt("run",row);
	HEL__flip_event = HEL__flip->getInt("event",row);
	HEL__flip_timestamp = HEL__flip->getLong("timestamp",row);
	HEL__flip_helicity = HEL__flip->getByte("helicity",row);
	HEL__flip_helicityRaw = HEL__flip->getByte("helicityRaw",row);
	HEL__flip_pair = HEL__flip->getByte("pair",row);
	HEL__flip_pattern = HEL__flip->getByte("pattern",row);
	HEL__flip_status = HEL__flip->getByte("status",row);
	return 0;
} 

int get_TimeBasedTrkg__TBTracks(int row){
	TimeBasedTrkg__TBTracks_id = TimeBasedTrkg__TBTracks->getShort("id",row);
	TimeBasedTrkg__TBTracks_status = TimeBasedTrkg__TBTracks->getShort("status",row);
	TimeBasedTrkg__TBTracks_sector = TimeBasedTrkg__TBTracks->getByte("sector",row);
	TimeBasedTrkg__TBTracks_c1_x = TimeBasedTrkg__TBTracks->getFloat("c1_x",row);
	TimeBasedTrkg__TBTracks_c1_y = TimeBasedTrkg__TBTracks->getFloat("c1_y",row);
	TimeBasedTrkg__TBTracks_c1_z = TimeBasedTrkg__TBTracks->getFloat("c1_z",row);
	TimeBasedTrkg__TBTracks_c1_ux = TimeBasedTrkg__TBTracks->getFloat("c1_ux",row);
	TimeBasedTrkg__TBTracks_c1_uy = TimeBasedTrkg__TBTracks->getFloat("c1_uy",row);
	TimeBasedTrkg__TBTracks_c1_uz = TimeBasedTrkg__TBTracks->getFloat("c1_uz",row);
	TimeBasedTrkg__TBTracks_c3_x = TimeBasedTrkg__TBTracks->getFloat("c3_x",row);
	TimeBasedTrkg__TBTracks_c3_y = TimeBasedTrkg__TBTracks->getFloat("c3_y",row);
	TimeBasedTrkg__TBTracks_c3_z = TimeBasedTrkg__TBTracks->getFloat("c3_z",row);
	TimeBasedTrkg__TBTracks_c3_ux = TimeBasedTrkg__TBTracks->getFloat("c3_ux",row);
	TimeBasedTrkg__TBTracks_c3_uy = TimeBasedTrkg__TBTracks->getFloat("c3_uy",row);
	TimeBasedTrkg__TBTracks_c3_uz = TimeBasedTrkg__TBTracks->getFloat("c3_uz",row);
	TimeBasedTrkg__TBTracks_t1_x = TimeBasedTrkg__TBTracks->getFloat("t1_x",row);
	TimeBasedTrkg__TBTracks_t1_y = TimeBasedTrkg__TBTracks->getFloat("t1_y",row);
	TimeBasedTrkg__TBTracks_t1_z = TimeBasedTrkg__TBTracks->getFloat("t1_z",row);
	TimeBasedTrkg__TBTracks_t1_px = TimeBasedTrkg__TBTracks->getFloat("t1_px",row);
	TimeBasedTrkg__TBTracks_t1_py = TimeBasedTrkg__TBTracks->getFloat("t1_py",row);
	TimeBasedTrkg__TBTracks_t1_pz = TimeBasedTrkg__TBTracks->getFloat("t1_pz",row);
	TimeBasedTrkg__TBTracks_Vtx0_x = TimeBasedTrkg__TBTracks->getFloat("Vtx0_x",row);
	TimeBasedTrkg__TBTracks_Vtx0_y = TimeBasedTrkg__TBTracks->getFloat("Vtx0_y",row);
	TimeBasedTrkg__TBTracks_Vtx0_z = TimeBasedTrkg__TBTracks->getFloat("Vtx0_z",row);
	TimeBasedTrkg__TBTracks_p0_x = TimeBasedTrkg__TBTracks->getFloat("p0_x",row);
	TimeBasedTrkg__TBTracks_p0_y = TimeBasedTrkg__TBTracks->getFloat("p0_y",row);
	TimeBasedTrkg__TBTracks_p0_z = TimeBasedTrkg__TBTracks->getFloat("p0_z",row);
	TimeBasedTrkg__TBTracks_Cross1_ID = TimeBasedTrkg__TBTracks->getShort("Cross1_ID",row);
	TimeBasedTrkg__TBTracks_Cross2_ID = TimeBasedTrkg__TBTracks->getShort("Cross2_ID",row);
	TimeBasedTrkg__TBTracks_Cross3_ID = TimeBasedTrkg__TBTracks->getShort("Cross3_ID",row);
	TimeBasedTrkg__TBTracks_q = TimeBasedTrkg__TBTracks->getByte("q",row);
	TimeBasedTrkg__TBTracks_pathlength = TimeBasedTrkg__TBTracks->getFloat("pathlength",row);
	TimeBasedTrkg__TBTracks_chi2 = TimeBasedTrkg__TBTracks->getFloat("chi2",row);
	TimeBasedTrkg__TBTracks_ndf = TimeBasedTrkg__TBTracks->getShort("ndf",row);
	return 0;
} 

int get_TimeBasedTrkg__Trajectory(int row){
	TimeBasedTrkg__Trajectory_id = TimeBasedTrkg__Trajectory->getShort("id",row);
	TimeBasedTrkg__Trajectory_detector = TimeBasedTrkg__Trajectory->getShort("detector",row);
	TimeBasedTrkg__Trajectory_layer = TimeBasedTrkg__Trajectory->getByte("layer",row);
	TimeBasedTrkg__Trajectory_x = TimeBasedTrkg__Trajectory->getFloat("x",row);
	TimeBasedTrkg__Trajectory_y = TimeBasedTrkg__Trajectory->getFloat("y",row);
	TimeBasedTrkg__Trajectory_z = TimeBasedTrkg__Trajectory->getFloat("z",row);
	TimeBasedTrkg__Trajectory_tx = TimeBasedTrkg__Trajectory->getFloat("tx",row);
	TimeBasedTrkg__Trajectory_ty = TimeBasedTrkg__Trajectory->getFloat("ty",row);
	TimeBasedTrkg__Trajectory_tz = TimeBasedTrkg__Trajectory->getFloat("tz",row);
	TimeBasedTrkg__Trajectory_B = TimeBasedTrkg__Trajectory->getFloat("B",row);
	TimeBasedTrkg__Trajectory_path = TimeBasedTrkg__Trajectory->getFloat("path",row);
	return 0;
} 

int get_CND__hits(int row){
	CND__hits_id = CND__hits->getShort("id",row);
	CND__hits_status = CND__hits->getShort("status",row);
	CND__hits_trkID = CND__hits->getShort("trkID",row);
	CND__hits_sector = CND__hits->getByte("sector",row);
	CND__hits_layer = CND__hits->getByte("layer",row);
	CND__hits_component = CND__hits->getShort("component",row);
	CND__hits_energy = CND__hits->getFloat("energy",row);
	CND__hits_time = CND__hits->getFloat("time",row);
	CND__hits_energy_unc = CND__hits->getFloat("energy_unc",row);
	CND__hits_time_unc = CND__hits->getFloat("time_unc",row);
	CND__hits_x = CND__hits->getFloat("x",row);
	CND__hits_y = CND__hits->getFloat("y",row);
	CND__hits_z = CND__hits->getFloat("z",row);
	CND__hits_x_unc = CND__hits->getFloat("x_unc",row);
	CND__hits_y_unc = CND__hits->getFloat("y_unc",row);
	CND__hits_z_unc = CND__hits->getFloat("z_unc",row);
	CND__hits_tx = CND__hits->getFloat("tx",row);
	CND__hits_ty = CND__hits->getFloat("ty",row);
	CND__hits_tz = CND__hits->getFloat("tz",row);
	CND__hits_tlength = CND__hits->getFloat("tlength",row);
	CND__hits_pathlength = CND__hits->getFloat("pathlength",row);
	CND__hits_indexLadc = CND__hits->getShort("indexLadc",row);
	CND__hits_indexRadc = CND__hits->getShort("indexRadc",row);
	CND__hits_indexLtdc = CND__hits->getShort("indexLtdc",row);
	CND__hits_indexRtdc = CND__hits->getShort("indexRtdc",row);
	return 0;
} 

int InitBanks(){
	if (fFactory->hasSchema("RF::tdc"))
		RF__tdc = new hipo::bank(fFactory->getSchema("RF::tdc"));
	if (fFactory->hasSchema("FTCAL::clusters"))
		FTCAL__clusters = new hipo::bank(fFactory->getSchema("FTCAL::clusters"));
	if (fFactory->hasSchema("RAW::scaler"))
		RAW__scaler = new hipo::bank(fFactory->getSchema("RAW::scaler"));
	if (fFactory->hasSchema("BAND::adc"))
		BAND__adc = new hipo::bank(fFactory->getSchema("BAND::adc"));
	if (fFactory->hasSchema("RUN::config"))
		RUN__config = new hipo::bank(fFactory->getSchema("RUN::config"));
	if (fFactory->hasSchema("TimeBasedTrkg::TBSegments"))
		TimeBasedTrkg__TBSegments = new hipo::bank(fFactory->getSchema("TimeBasedTrkg::TBSegments"));
	if (fFactory->hasSchema("REC::Calorimeter"))
		REC__Calorimeter = new hipo::bank(fFactory->getSchema("REC::Calorimeter"));
	if (fFactory->hasSchema("REC::CovMat"))
		REC__CovMat = new hipo::bank(fFactory->getSchema("REC::CovMat"));
	if (fFactory->hasSchema("RAW::epics"))
		RAW__epics = new hipo::bank(fFactory->getSchema("RAW::epics"));
	if (fFactory->hasSchema("FTHODO::clusters"))
		FTHODO__clusters = new hipo::bank(fFactory->getSchema("FTHODO::clusters"));
	if (fFactory->hasSchema("RUN::scaler"))
		RUN__scaler = new hipo::bank(fFactory->getSchema("RUN::scaler"));
	if (fFactory->hasSchema("BAND::hits"))
		BAND__hits = new hipo::bank(fFactory->getSchema("BAND::hits"));
	if (fFactory->hasSchema("ECAL::clusters"))
		ECAL__clusters = new hipo::bank(fFactory->getSchema("ECAL::clusters"));
	if (fFactory->hasSchema("FT::particles"))
		FT__particles = new hipo::bank(fFactory->getSchema("FT::particles"));
	if (fFactory->hasSchema("REC::Track"))
		REC__Track = new hipo::bank(fFactory->getSchema("REC::Track"));
	if (fFactory->hasSchema("TimeBasedTrkg::TBCrosses"))
		TimeBasedTrkg__TBCrosses = new hipo::bank(fFactory->getSchema("TimeBasedTrkg::TBCrosses"));
	if (fFactory->hasSchema("FTCAL::adc"))
		FTCAL__adc = new hipo::bank(fFactory->getSchema("FTCAL::adc"));
	if (fFactory->hasSchema("CND::adc"))
		CND__adc = new hipo::bank(fFactory->getSchema("CND::adc"));
	if (fFactory->hasSchema("FTOF::hits"))
		FTOF__hits = new hipo::bank(fFactory->getSchema("FTOF::hits"));
	if (fFactory->hasSchema("REC::ForwardTagger"))
		REC__ForwardTagger = new hipo::bank(fFactory->getSchema("REC::ForwardTagger"));
	if (fFactory->hasSchema("TimeBasedTrkg::TBSegmentTrajectory"))
		TimeBasedTrkg__TBSegmentTrajectory = new hipo::bank(fFactory->getSchema("TimeBasedTrkg::TBSegmentTrajectory"));
	if (fFactory->hasSchema("CTOF::tdc"))
		CTOF__tdc = new hipo::bank(fFactory->getSchema("CTOF::tdc"));
	if (fFactory->hasSchema("REC::Cherenkov"))
		REC__Cherenkov = new hipo::bank(fFactory->getSchema("REC::Cherenkov"));
	if (fFactory->hasSchema("FTHODO::hits"))
		FTHODO__hits = new hipo::bank(fFactory->getSchema("FTHODO::hits"));
	if (fFactory->hasSchema("RECFT::Event"))
		RECFT__Event = new hipo::bank(fFactory->getSchema("RECFT::Event"));
	if (fFactory->hasSchema("FTOF::adc"))
		FTOF__adc = new hipo::bank(fFactory->getSchema("FTOF::adc"));
	if (fFactory->hasSchema("MC::Lund"))
		MC__Lund = new hipo::bank(fFactory->getSchema("MC::Lund"));
	if (fFactory->hasSchema("CTOF::adc"))
		CTOF__adc = new hipo::bank(fFactory->getSchema("CTOF::adc"));
	if (fFactory->hasSchema("MC::Header"))
		MC__Header = new hipo::bank(fFactory->getSchema("MC::Header"));
	if (fFactory->hasSchema("HEL::online"))
		HEL__online = new hipo::bank(fFactory->getSchema("HEL::online"));
	if (fFactory->hasSchema("REC::Event"))
		REC__Event = new hipo::bank(fFactory->getSchema("REC::Event"));
	if (fFactory->hasSchema("REC::Particle"))
		REC__Particle = new hipo::bank(fFactory->getSchema("REC::Particle"));
	if (fFactory->hasSchema("REC::Traj"))
		REC__Traj = new hipo::bank(fFactory->getSchema("REC::Traj"));
	if (fFactory->hasSchema("FTOF::tdc"))
		FTOF__tdc = new hipo::bank(fFactory->getSchema("FTOF::tdc"));
	if (fFactory->hasSchema("RICH::hits"))
		RICH__hits = new hipo::bank(fFactory->getSchema("RICH::hits"));
	if (fFactory->hasSchema("MC::True"))
		MC__True = new hipo::bank(fFactory->getSchema("MC::True"));
	if (fFactory->hasSchema("FTCAL::hits"))
		FTCAL__hits = new hipo::bank(fFactory->getSchema("FTCAL::hits"));
	if (fFactory->hasSchema("MC::Event"))
		MC__Event = new hipo::bank(fFactory->getSchema("MC::Event"));
	if (fFactory->hasSchema("BAND::tdc"))
		BAND__tdc = new hipo::bank(fFactory->getSchema("BAND::tdc"));
	if (fFactory->hasSchema("RF::adc"))
		RF__adc = new hipo::bank(fFactory->getSchema("RF::adc"));
	if (fFactory->hasSchema("REC::Scintillator"))
		REC__Scintillator = new hipo::bank(fFactory->getSchema("REC::Scintillator"));
	if (fFactory->hasSchema("ECAL::peaks"))
		ECAL__peaks = new hipo::bank(fFactory->getSchema("ECAL::peaks"));
	if (fFactory->hasSchema("MC::Particle"))
		MC__Particle = new hipo::bank(fFactory->getSchema("MC::Particle"));
	if (fFactory->hasSchema("ECAL::tdc"))
		ECAL__tdc = new hipo::bank(fFactory->getSchema("ECAL::tdc"));
	if (fFactory->hasSchema("RICH::tdc"))
		RICH__tdc = new hipo::bank(fFactory->getSchema("RICH::tdc"));
	if (fFactory->hasSchema("LTCC::clusters"))
		LTCC__clusters = new hipo::bank(fFactory->getSchema("LTCC::clusters"));
	if (fFactory->hasSchema("RICH::hadrons"))
		RICH__hadrons = new hipo::bank(fFactory->getSchema("RICH::hadrons"));
	if (fFactory->hasSchema("FTHODO::adc"))
		FTHODO__adc = new hipo::bank(fFactory->getSchema("FTHODO::adc"));
	if (fFactory->hasSchema("HTCC::rec"))
		HTCC__rec = new hipo::bank(fFactory->getSchema("HTCC::rec"));
	if (fFactory->hasSchema("RUN::trigger"))
		RUN__trigger = new hipo::bank(fFactory->getSchema("RUN::trigger"));
	if (fFactory->hasSchema("ECAL::adc"))
		ECAL__adc = new hipo::bank(fFactory->getSchema("ECAL::adc"));
	if (fFactory->hasSchema("ECAL::calib"))
		ECAL__calib = new hipo::bank(fFactory->getSchema("ECAL::calib"));
	if (fFactory->hasSchema("RUN::rf"))
		RUN__rf = new hipo::bank(fFactory->getSchema("RUN::rf"));
	if (fFactory->hasSchema("LTCC::adc"))
		LTCC__adc = new hipo::bank(fFactory->getSchema("LTCC::adc"));
	if (fFactory->hasSchema("TimeBasedTrkg::TBHits"))
		TimeBasedTrkg__TBHits = new hipo::bank(fFactory->getSchema("TimeBasedTrkg::TBHits"));
	if (fFactory->hasSchema("HTCC::adc"))
		HTCC__adc = new hipo::bank(fFactory->getSchema("HTCC::adc"));
	if (fFactory->hasSchema("CTOF::hits"))
		CTOF__hits = new hipo::bank(fFactory->getSchema("CTOF::hits"));
	if (fFactory->hasSchema("CND::tdc"))
		CND__tdc = new hipo::bank(fFactory->getSchema("CND::tdc"));
	if (fFactory->hasSchema("CVTRec::Tracks"))
		CVTRec__Tracks = new hipo::bank(fFactory->getSchema("CVTRec::Tracks"));
	if (fFactory->hasSchema("RICH::photons"))
		RICH__photons = new hipo::bank(fFactory->getSchema("RICH::photons"));
	if (fFactory->hasSchema("RECFT::Particle"))
		RECFT__Particle = new hipo::bank(fFactory->getSchema("RECFT::Particle"));
	if (fFactory->hasSchema("HEL::flip"))
		HEL__flip = new hipo::bank(fFactory->getSchema("HEL::flip"));
	if (fFactory->hasSchema("TimeBasedTrkg::TBTracks"))
		TimeBasedTrkg__TBTracks = new hipo::bank(fFactory->getSchema("TimeBasedTrkg::TBTracks"));
	if (fFactory->hasSchema("TimeBasedTrkg::Trajectory"))
		TimeBasedTrkg__Trajectory = new hipo::bank(fFactory->getSchema("TimeBasedTrkg::Trajectory"));
	if (fFactory->hasSchema("CND::hits"))
		CND__hits = new hipo::bank(fFactory->getSchema("CND::hits"));

	return 1;
}

int FillBanks(){
	if (fFactory->hasSchema("RF::tdc"))
		 fEvent->getStructure(*RF__tdc);
	if (fFactory->hasSchema("FTCAL::clusters"))
		 fEvent->getStructure(*FTCAL__clusters);
	if (fFactory->hasSchema("RAW::scaler"))
		 fEvent->getStructure(*RAW__scaler);
	if (fFactory->hasSchema("BAND::adc"))
		 fEvent->getStructure(*BAND__adc);
	if (fFactory->hasSchema("RUN::config"))
		 fEvent->getStructure(*RUN__config);
	if (fFactory->hasSchema("TimeBasedTrkg::TBSegments"))
		 fEvent->getStructure(*TimeBasedTrkg__TBSegments);
	if (fFactory->hasSchema("REC::Calorimeter"))
		 fEvent->getStructure(*REC__Calorimeter);
	if (fFactory->hasSchema("REC::CovMat"))
		 fEvent->getStructure(*REC__CovMat);
	if (fFactory->hasSchema("RAW::epics"))
		 fEvent->getStructure(*RAW__epics);
	if (fFactory->hasSchema("FTHODO::clusters"))
		 fEvent->getStructure(*FTHODO__clusters);
	if (fFactory->hasSchema("RUN::scaler"))
		 fEvent->getStructure(*RUN__scaler);
	if (fFactory->hasSchema("BAND::hits"))
		 fEvent->getStructure(*BAND__hits);
	if (fFactory->hasSchema("ECAL::clusters"))
		 fEvent->getStructure(*ECAL__clusters);
	if (fFactory->hasSchema("FT::particles"))
		 fEvent->getStructure(*FT__particles);
	if (fFactory->hasSchema("REC::Track"))
		 fEvent->getStructure(*REC__Track);
	if (fFactory->hasSchema("TimeBasedTrkg::TBCrosses"))
		 fEvent->getStructure(*TimeBasedTrkg__TBCrosses);
	if (fFactory->hasSchema("FTCAL::adc"))
		 fEvent->getStructure(*FTCAL__adc);
	if (fFactory->hasSchema("CND::adc"))
		 fEvent->getStructure(*CND__adc);
	if (fFactory->hasSchema("FTOF::hits"))
		 fEvent->getStructure(*FTOF__hits);
	if (fFactory->hasSchema("REC::ForwardTagger"))
		 fEvent->getStructure(*REC__ForwardTagger);
	if (fFactory->hasSchema("TimeBasedTrkg::TBSegmentTrajectory"))
		 fEvent->getStructure(*TimeBasedTrkg__TBSegmentTrajectory);
	if (fFactory->hasSchema("CTOF::tdc"))
		 fEvent->getStructure(*CTOF__tdc);
	if (fFactory->hasSchema("REC::Cherenkov"))
		 fEvent->getStructure(*REC__Cherenkov);
	if (fFactory->hasSchema("FTHODO::hits"))
		 fEvent->getStructure(*FTHODO__hits);
	if (fFactory->hasSchema("RECFT::Event"))
		 fEvent->getStructure(*RECFT__Event);
	if (fFactory->hasSchema("FTOF::adc"))
		 fEvent->getStructure(*FTOF__adc);
	if (fFactory->hasSchema("MC::Lund"))
		 fEvent->getStructure(*MC__Lund);
	if (fFactory->hasSchema("CTOF::adc"))
		 fEvent->getStructure(*CTOF__adc);
	if (fFactory->hasSchema("MC::Header"))
		 fEvent->getStructure(*MC__Header);
	if (fFactory->hasSchema("HEL::online"))
		 fEvent->getStructure(*HEL__online);
	if (fFactory->hasSchema("REC::Event"))
		 fEvent->getStructure(*REC__Event);
	if (fFactory->hasSchema("REC::Particle"))
		 fEvent->getStructure(*REC__Particle);
	if (fFactory->hasSchema("REC::Traj"))
		 fEvent->getStructure(*REC__Traj);
	if (fFactory->hasSchema("FTOF::tdc"))
		 fEvent->getStructure(*FTOF__tdc);
	if (fFactory->hasSchema("RICH::hits"))
		 fEvent->getStructure(*RICH__hits);
	if (fFactory->hasSchema("MC::True"))
		 fEvent->getStructure(*MC__True);
	if (fFactory->hasSchema("FTCAL::hits"))
		 fEvent->getStructure(*FTCAL__hits);
	if (fFactory->hasSchema("MC::Event"))
		 fEvent->getStructure(*MC__Event);
	if (fFactory->hasSchema("BAND::tdc"))
		 fEvent->getStructure(*BAND__tdc);
	if (fFactory->hasSchema("RF::adc"))
		 fEvent->getStructure(*RF__adc);
	if (fFactory->hasSchema("REC::Scintillator"))
		 fEvent->getStructure(*REC__Scintillator);
	if (fFactory->hasSchema("ECAL::peaks"))
		 fEvent->getStructure(*ECAL__peaks);
	if (fFactory->hasSchema("MC::Particle"))
		 fEvent->getStructure(*MC__Particle);
	if (fFactory->hasSchema("ECAL::tdc"))
		 fEvent->getStructure(*ECAL__tdc);
	if (fFactory->hasSchema("RICH::tdc"))
		 fEvent->getStructure(*RICH__tdc);
	if (fFactory->hasSchema("LTCC::clusters"))
		 fEvent->getStructure(*LTCC__clusters);
	if (fFactory->hasSchema("RICH::hadrons"))
		 fEvent->getStructure(*RICH__hadrons);
	if (fFactory->hasSchema("FTHODO::adc"))
		 fEvent->getStructure(*FTHODO__adc);
	if (fFactory->hasSchema("HTCC::rec"))
		 fEvent->getStructure(*HTCC__rec);
	if (fFactory->hasSchema("RUN::trigger"))
		 fEvent->getStructure(*RUN__trigger);
	if (fFactory->hasSchema("ECAL::adc"))
		 fEvent->getStructure(*ECAL__adc);
	if (fFactory->hasSchema("ECAL::calib"))
		 fEvent->getStructure(*ECAL__calib);
	if (fFactory->hasSchema("RUN::rf"))
		 fEvent->getStructure(*RUN__rf);
	if (fFactory->hasSchema("LTCC::adc"))
		 fEvent->getStructure(*LTCC__adc);
	if (fFactory->hasSchema("TimeBasedTrkg::TBHits"))
		 fEvent->getStructure(*TimeBasedTrkg__TBHits);
	if (fFactory->hasSchema("HTCC::adc"))
		 fEvent->getStructure(*HTCC__adc);
	if (fFactory->hasSchema("CTOF::hits"))
		 fEvent->getStructure(*CTOF__hits);
	if (fFactory->hasSchema("CND::tdc"))
		 fEvent->getStructure(*CND__tdc);
	if (fFactory->hasSchema("CVTRec::Tracks"))
		 fEvent->getStructure(*CVTRec__Tracks);
	if (fFactory->hasSchema("RICH::photons"))
		 fEvent->getStructure(*RICH__photons);
	if (fFactory->hasSchema("RECFT::Particle"))
		 fEvent->getStructure(*RECFT__Particle);
	if (fFactory->hasSchema("HEL::flip"))
		 fEvent->getStructure(*HEL__flip);
	if (fFactory->hasSchema("TimeBasedTrkg::TBTracks"))
		 fEvent->getStructure(*TimeBasedTrkg__TBTracks);
	if (fFactory->hasSchema("TimeBasedTrkg::Trajectory"))
		 fEvent->getStructure(*TimeBasedTrkg__Trajectory);
	if (fFactory->hasSchema("CND::hits"))
		 fEvent->getStructure(*CND__hits);

	return 1;
}

