/* Include files */

#include <stddef.h>
#include "blas.h"
#include "TTR_RobustMPC_RTmdl_sfun.h"
#include "c3_TTR_RobustMPC_RTmdl.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "TTR_RobustMPC_RTmdl_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[6] = { "i", "nargin", "nargout",
  "u_ctrl", "U_bounds", "u_ctrl_out" };

/* Function Declarations */
static void initialize_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance);
static void initialize_params_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance);
static void enable_c3_TTR_RobustMPC_RTmdl(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance);
static void disable_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance);
static void set_sim_state_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance);
static void sf_c3_TTR_RobustMPC_RTmdl(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance);
static void initSimStructsc3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance);
static void registerMessagesc3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_u_ctrl_out, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[14]);
static void c3_eml_scalar_eg(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_TTR_RobustMPC_RTmdl, const
  char_T *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_TTR_RobustMPC_RTmdl = 0U;
}

static void initialize_params_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance)
{
}

static void enable_c3_TTR_RobustMPC_RTmdl(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_u_ctrl_out;
  c3_u_ctrl_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  c3_hoistedGlobal = *c3_u_ctrl_out;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_TTR_RobustMPC_RTmdl;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_u_ctrl_out;
  c3_u_ctrl_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_u_ctrl_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "u_ctrl_out");
  chartInstance->c3_is_active_c3_TTR_RobustMPC_RTmdl = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_TTR_RobustMPC_RTmdl");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_TTR_RobustMPC_RTmdl(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance)
{
}

static void sf_c3_TTR_RobustMPC_RTmdl(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  real_T c3_hoistedGlobal;
  real_T c3_u_ctrl;
  int32_T c3_i1;
  real_T c3_U_bounds[2];
  uint32_T c3_debug_family_var_map[6];
  real_T c3_i;
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  real_T c3_u_ctrl_out;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_b_varargin_2;
  real_T c3_varargin_3;
  real_T c3_x;
  real_T c3_y;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_xk;
  real_T c3_yk;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_b_varargin_1;
  real_T c3_c_varargin_2;
  real_T c3_d_varargin_2;
  real_T c3_b_varargin_3;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_b_xk;
  real_T c3_b_yk;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T *c3_b_u_ctrl;
  real_T *c3_b_u_ctrl_out;
  real_T (*c3_b_U_bounds)[2];
  c3_b_U_bounds = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_u_ctrl_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_u_ctrl = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_u_ctrl, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_u_ctrl_out, 1U);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_U_bounds)[c3_i0], 2U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_u_ctrl;
  c3_u_ctrl = c3_hoistedGlobal;
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    c3_U_bounds[c3_i1] = (*c3_b_U_bounds)[c3_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_i, 0U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_u_ctrl, 3U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_U_bounds, 4U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u_ctrl_out, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_u_ctrl_out = c3_u_ctrl;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  CV_EML_IF(0, 1, 0, FALSE);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_i = 1.0;
  CV_EML_FOR(0, 1, 0, 1);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_varargin_1 = c3_u_ctrl;
  c3_varargin_2 = c3_U_bounds[0];
  c3_b_varargin_2 = c3_varargin_1;
  c3_varargin_3 = c3_varargin_2;
  c3_x = c3_b_varargin_2;
  c3_y = c3_varargin_3;
  c3_b_x = c3_x;
  c3_b_y = c3_y;
  c3_eml_scalar_eg(chartInstance);
  c3_xk = c3_b_x;
  c3_yk = c3_b_y;
  c3_c_x = c3_xk;
  c3_c_y = c3_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_u_ctrl_out = muDoubleScalarMax(c3_c_x, c3_c_y);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_b_varargin_1 = c3_u_ctrl;
  c3_c_varargin_2 = c3_U_bounds[1];
  c3_d_varargin_2 = c3_b_varargin_1;
  c3_b_varargin_3 = c3_c_varargin_2;
  c3_d_x = c3_d_varargin_2;
  c3_d_y = c3_b_varargin_3;
  c3_e_x = c3_d_x;
  c3_e_y = c3_d_y;
  c3_eml_scalar_eg(chartInstance);
  c3_b_xk = c3_e_x;
  c3_b_yk = c3_e_y;
  c3_f_x = c3_b_xk;
  c3_f_y = c3_b_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_u_ctrl_out = muDoubleScalarMin(c3_f_x, c3_f_y);
  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_u_ctrl_out = c3_u_ctrl_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_TTR_RobustMPC_RTmdlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance)
{
}

static void registerMessagesc3_TTR_RobustMPC_RTmdl
  (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance;
  chartInstance = (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_u_ctrl_out, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_u_ctrl_out),
    &c3_thisId);
  sf_mex_destroy(&c3_u_ctrl_out);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_u_ctrl_out;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance;
  chartInstance = (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *)chartInstanceVoid;
  c3_u_ctrl_out = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_u_ctrl_out),
    &c3_thisId);
  sf_mex_destroy(&c3_u_ctrl_out);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i2;
  real_T c3_b_inData[2];
  int32_T c3_i3;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance;
  chartInstance = (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_b_inData[c3_i2] = (*(real_T (*)[2])c3_inData)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
    c3_u[c3_i3] = c3_b_inData[c3_i3];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_TTR_RobustMPC_RTmdl_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[14];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i4;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c3_i4 = 0; c3_i4 < 14; c3_i4++) {
    c3_r0 = &c3_info[c3_i4];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i4);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[14])
{
  c3_info[0].context = "";
  c3_info[0].name = "length";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[0].fileTimeLo = 1303146206U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "mrdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[1].fileTimeLo = 1357951548U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 1319729966U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[2].name = "rdivide";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].fileTimeLo = 1346510388U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[3].name = "eml_scalexp_compatible";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c3_info[3].fileTimeLo = 1286818796U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[4].name = "eml_div";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[4].fileTimeLo = 1313347810U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "";
  c3_info[5].name = "mtimes";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[5].fileTimeLo = 1289519692U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "";
  c3_info[6].name = "max";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[6].fileTimeLo = 1311255316U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[7].name = "eml_min_or_max";
  c3_info[7].dominantType = "char";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[7].fileTimeLo = 1334071490U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[8].name = "eml_scalar_eg";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[8].fileTimeLo = 1286818796U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[9].name = "eml_scalexp_alloc";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[9].fileTimeLo = 1352424860U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[10].name = "eml_index_class";
  c3_info[10].dominantType = "";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[10].fileTimeLo = 1323170578U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[11].name = "eml_scalar_eg";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[11].fileTimeLo = 1286818796U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "";
  c3_info[12].name = "min";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[12].fileTimeLo = 1311255318U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[13].name = "eml_min_or_max";
  c3_info[13].dominantType = "char";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[13].fileTimeLo = 1334071490U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
}

static void c3_eml_scalar_eg(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance)
{
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance;
  chartInstance = (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i5;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i5, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i5;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance;
  chartInstance = (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_TTR_RobustMPC_RTmdl, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_TTR_RobustMPC_RTmdl), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_TTR_RobustMPC_RTmdl);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_TTR_RobustMPC_RTmdlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_TTR_RobustMPC_RTmdl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1453315185U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1809262045U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(906755268U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2201042218U);
}

mxArray *sf_c3_TTR_RobustMPC_RTmdl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("VVPNWBOOtqWmckFbbcB3AH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_TTR_RobustMPC_RTmdl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_TTR_RobustMPC_RTmdl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_ctrl_out\",},{M[8],M[0],T\"is_active_c3_TTR_RobustMPC_RTmdl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_TTR_RobustMPC_RTmdl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance;
    chartInstance = (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *) ((ChartInfoStruct
      *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _TTR_RobustMPC_RTmdlMachineNumber_,
           3,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_TTR_RobustMPC_RTmdlMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_TTR_RobustMPC_RTmdlMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _TTR_RobustMPC_RTmdlMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u_ctrl");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u_ctrl_out");
          _SFD_SET_DATA_PROPS(2,1,1,0,"U_bounds");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,729);
        _SFD_CV_INIT_EML_IF(0,1,0,333,374,538,724);
        _SFD_CV_INIT_EML_FOR(0,1,0,568,593,720);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c3_u_ctrl;
          real_T *c3_u_ctrl_out;
          real_T (*c3_U_bounds)[2];
          c3_U_bounds = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 1);
          c3_u_ctrl_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_u_ctrl = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_u_ctrl);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_u_ctrl_out);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_U_bounds);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _TTR_RobustMPC_RTmdlMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "huTXx3sJ9CTmNjidVlHAlE";
}

static void sf_opaque_initialize_c3_TTR_RobustMPC_RTmdl(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_TTR_RobustMPC_RTmdl
    ((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*) chartInstanceVar);
  initialize_c3_TTR_RobustMPC_RTmdl((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_TTR_RobustMPC_RTmdl(void *chartInstanceVar)
{
  enable_c3_TTR_RobustMPC_RTmdl((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_TTR_RobustMPC_RTmdl(void *chartInstanceVar)
{
  disable_c3_TTR_RobustMPC_RTmdl((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_TTR_RobustMPC_RTmdl(void *chartInstanceVar)
{
  sf_c3_TTR_RobustMPC_RTmdl((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_TTR_RobustMPC_RTmdl(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_TTR_RobustMPC_RTmdl
    ((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_TTR_RobustMPC_RTmdl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_TTR_RobustMPC_RTmdl(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_TTR_RobustMPC_RTmdl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_TTR_RobustMPC_RTmdl((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_TTR_RobustMPC_RTmdl(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c3_TTR_RobustMPC_RTmdl(S);
}

static void sf_opaque_set_sim_state_c3_TTR_RobustMPC_RTmdl(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_TTR_RobustMPC_RTmdl(S, st);
}

static void sf_opaque_terminate_c3_TTR_RobustMPC_RTmdl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_TTR_RobustMPC_RTmdl_optimization_info();
    }

    finalize_c3_TTR_RobustMPC_RTmdl((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_TTR_RobustMPC_RTmdl((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_TTR_RobustMPC_RTmdl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_TTR_RobustMPC_RTmdl
      ((SFc3_TTR_RobustMPC_RTmdlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_TTR_RobustMPC_RTmdl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_TTR_RobustMPC_RTmdl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(327203133U));
  ssSetChecksum1(S,(2050757433U));
  ssSetChecksum2(S,(1487017182U));
  ssSetChecksum3(S,(2145299566U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_TTR_RobustMPC_RTmdl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_TTR_RobustMPC_RTmdl(SimStruct *S)
{
  SFc3_TTR_RobustMPC_RTmdlInstanceStruct *chartInstance;
  chartInstance = (SFc3_TTR_RobustMPC_RTmdlInstanceStruct *)utMalloc(sizeof
    (SFc3_TTR_RobustMPC_RTmdlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_TTR_RobustMPC_RTmdlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_TTR_RobustMPC_RTmdl;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_TTR_RobustMPC_RTmdl_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_TTR_RobustMPC_RTmdl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_TTR_RobustMPC_RTmdl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_TTR_RobustMPC_RTmdl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_TTR_RobustMPC_RTmdl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
