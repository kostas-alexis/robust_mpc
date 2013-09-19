/* Include files */

#include "Robust_MPC_Library_sfun.h"
#include "Robust_MPC_Library_sfun_debug_macros.h"
#include "c1_AQlLBmJ8kFX9hRboHTKSCD_Robust_MPC_Library.h"
#include "c1_IFys0ySoH5H7B0jKpOd2xE_Robust_MPC_Library.h"
#include "c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Robust_MPC_LibraryMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Robust_MPC_Library_initializer(void)
{
}

void Robust_MPC_Library_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Robust_MPC_Library_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    if (!strcmp(specsCksum, "AQlLBmJ8kFX9hRboHTKSCD")) {
      c1_AQlLBmJ8kFX9hRboHTKSCD_Robust_MPC_Library_method_dispatcher
        (simstructPtr, method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "IFys0ySoH5H7B0jKpOd2xE")) {
      c1_IFys0ySoH5H7B0jKpOd2xE_Robust_MPC_Library_method_dispatcher
        (simstructPtr, method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "odDQxWyHCJ9QpdLAdfN9OE")) {
      c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_method_dispatcher
        (simstructPtr, method, data);
      return 1;
    }

    return 0;
  }

  return 0;
}

unsigned int sf_Robust_MPC_Library_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if (!strcmp(machineName,"Robust_MPC_Library")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(518608728U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1753938888U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2376921560U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1788781471U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 1:
            {
              extern void
                sf_c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_get_check_sum
                (mxArray *plhs[]);
              sf_c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_get_check_sum(plhs);
              break;
            }

           default:
            ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
          }
        } else {
          return 0;
        }
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Robust_MPC_Library_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "kWwG3BNNb7kHpHAVfvDPqC") == 0) {
          extern mxArray
            *sf_c1_AQlLBmJ8kFX9hRboHTKSCD_Robust_MPC_Library_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_AQlLBmJ8kFX9hRboHTKSCD_Robust_MPC_Library_get_autoinheritance_info
            ();
          break;
        }

        if (strcmp(aiChksum, "LDmWFXfajAEnpZAgG2QySH") == 0) {
          extern mxArray
            *sf_c1_IFys0ySoH5H7B0jKpOd2xE_Robust_MPC_Library_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_IFys0ySoH5H7B0jKpOd2xE_Robust_MPC_Library_get_autoinheritance_info
            ();
          break;
        }

        if (strcmp(aiChksum, "xGfTni6EH5QlQP13tPFaUF") == 0) {
          extern mxArray
            *sf_c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Robust_MPC_Library_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Robust_MPC_Library_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "AQlLBmJ8kFX9hRboHTKSCD") == 0) {
          extern mxArray
            *sf_c1_AQlLBmJ8kFX9hRboHTKSCD_Robust_MPC_Library_third_party_uses_info
            (void);
          plhs[0] =
            sf_c1_AQlLBmJ8kFX9hRboHTKSCD_Robust_MPC_Library_third_party_uses_info
            ();
          break;
        }

        if (strcmp(tpChksum, "IFys0ySoH5H7B0jKpOd2xE") == 0) {
          extern mxArray
            *sf_c1_IFys0ySoH5H7B0jKpOd2xE_Robust_MPC_Library_third_party_uses_info
            (void);
          plhs[0] =
            sf_c1_IFys0ySoH5H7B0jKpOd2xE_Robust_MPC_Library_third_party_uses_info
            ();
          break;
        }

        if (strcmp(tpChksum, "odDQxWyHCJ9QpdLAdfN9OE") == 0) {
          extern mxArray
            *sf_c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_third_party_uses_info
            (void);
          plhs[0] =
            sf_c1_odDQxWyHCJ9QpdLAdfN9OE_Robust_MPC_Library_third_party_uses_info
            ();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Robust_MPC_Library_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Robust_MPC_LibraryMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Robust_MPC_Library","sfun",1,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Robust_MPC_LibraryMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Robust_MPC_LibraryMachineNumber_,0);
}

void Robust_MPC_Library_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Robust_MPC_Library_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Robust_MPC_Library", "ASLquad_onboardRobustMPC");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Robust_MPC_Library_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
