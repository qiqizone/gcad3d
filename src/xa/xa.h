// include with deactivated extern in "../xa/xa.c"
// needs #include "../ut/ut_geo.h"    (Point)


/// debug-print (see AP_deb_stat())
#ifdef DEB
#define printd if(AP_stat.debStat) AP_deb_print
#else
#define printd if(0) printf
#endif



/// \code
/// sysStat    1=starting (GUI up); 2=initialize done (openGL up);
/// errStat    0=Ok, no Error
/// errLn      SourceLineNr where Error occured
/// batch      0=interaktiv, 1=Batchmode.
/// texture    0=no, hardware does not accept textures; 1=Yes, Ok.
/// build      Compile,Linker not checked/not available; 1=available.
/// comp       Compile plugins off; 1=on.
/// APP_stat   0=mainActive; 1=<APP_act_nam> (plugin) active.
/// TUT_stat   ScreeCast on=1  off=0
/// subtyp     0=VRML1, 1=VRML2
/// jntStat    0=unInitilized, 1=open  (DBFile <tmp>/joints)
/// debStat    0=normal (debug off); 1=debug_ON
/// tstDllStat 0=normal (OFF); 1=testdll_ON
/// mdl_modified   UNUSED
/// mdl_box_valid  AP_mdlbox_invalid_ck - 0=valid, 1=void,invalid
/// iActStat   0=normal, 1=Interactivity_ON
/// cadIniM    CAD - init - mainFunction
/// cadIniS    CAD - init - subFunction
/// \endcode
typedef struct {int errLn; short sysStat, errStat;
                unsigned  batch:1,
                          texture:1,
                          build:1,
                          APP_stat:1,
                          TUT_stat:1,
                          jntStat:1,
                          debStat:1,
                          iActStat:1,
                          tstDllStat:1,
                          mdl_modified:1,
                          mdl_box_valid:1,
                          comp:1,
                          uuBits:20;
                char      cadIniM, cadIniS, subtyp;}           AP_STAT;


/// \code
/// applicationObjectNames - displayed in selectionList - used by plugins.
/// see PLU_appNamTab_set
/// \endcode
typedef struct {char* oNam; int oTyp;}                         APP_OBJ_NAM;



//================================================================
// defined in ../xa/xa.c (with extern invalidated)
extern char AP_mod_dir[128];      // directory of active model, with '/' at end
extern char AP_mod_fnam[128];     // active Modelname - without path
extern char AP_mod_ftyp[32];      // filetyp of active model
extern char AP_mod_sym[64];       // symbolic directory for OPEN (no '/' at end)
  // AP_mod_iftyp: integer-filetyp of active model; eg Mtyp_DXF
extern char AP_mod_iftyp;         // integer-filetyp - eg Mtyp_Gcad|Mtyp_DXF ..
extern char AP_modact_nam[128];   // name of the active submodel; def="" (main)
                                  //   not set in runmode.
extern Point AP_box_pm1, AP_box_pm2;  // box around mainmodel

// extern char AP_dir_save[128];     // directory for SAVE
// extern char AP_sym_save[64];      // symbolic directory for SAVE

extern char AP_dir_prg[128];      // directory for programs
extern char AP_sym_prg[64];       // symbolic directory for programs

extern char AP_errText[128];      // errortext for minor errors
extern char AP_printer[80];       // Printer
extern char AP_editor[80];        // TextEditor
extern char AP_lang[4];           // en or de

extern int  APP_act_typ;          // type of APP_act_nam: 0=none;
                                  // 1=applic. 2=process 3=plugin 4=remote;
                                  // APP       PRC       PLU      RPC
extern char APP_act_nam[128];     // name of last script- or plugin-program
extern char APP_act_proc[128];    // name of processor (dll)
extern long APP_dli_start;        // first free dli (last dli of core-obj's)

extern FILE *AP_deb_fp;           ///< debug-file-pointer

/// \brief progress of Start
/// \code
///   1 starting
///   2 initialyze done
///  65 Batch, else interactive.
/// \endcode
extern AP_STAT AP_stat;



//================================================================
  int AP_defaults_write ();
 long AP_cre_defHdr (int typ, int istart);
  int AP_Init0 ();
  int AP_Init1 ();
  int AP_search_init ();
  // int AP_search_obj (char *bufIn);
  // int AP_search_def (char *cbuf);
  int AP_Print0 (int mode,char* cmd,int irot,char* off,char* scl);
  int AP_PrintWrHex (FILE *fpo,unsigned char *dat,int ilen,int gray);
  int AP_defaults_read ();

  char AP_typChar_typ (int typ);
  int APED_oid_dbo__ (char *buf, int typ, long ind);

  // int AP_appr (char *obj, char *ref, double tol, double lmin, int mode);

  int AP_obj_del0    ();
  // int AP_obj_del1    ();
  // int AP_obj_del2    (int lNr, char *tx1, int mode);
  // int AP_obj_analyze (int typ, long ind);

  int AP_get_lNr  ();
  int AP_set_lNr  (int lNr);

  // long AP_lNr_get ();
  // int  AP_lNr_set (long lNr);

  // int AP_colSel (ColRGB *cSel);  // ColRGB!

  char* AP_Get_ConstPl_Z (int typ);
  // int AP_GetObj    (ObjG* o1, long dli);
  int AP_APT_clean ();

  // AP_STAT AP_stat__ (AP_STAT *newStat);
  int AP_errStat_set (int stat);
  int AP_errStat_get ();

// nur temp:
  // void GR_tmpSym (int typ, Point *pt1); // Point !



//=================== EOF ==============================
