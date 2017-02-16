/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_BestInertia_sfun.h"
#include "c23_JointSpaceControl_BestInertia.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_BestInertia_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c23_debug_family_names[4] = { "nargin", "nargout", "J",
  "rank_J" };

/* Function Declarations */
static void initialize_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initialize_params_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void enable_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void disable_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c23_update_debugger_state_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void set_sim_state_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_st);
static void finalize_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void sf_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void initSimStructsc23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void registerMessagesc23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_rank_J, const char_T *c23_identifier, real_T c23_y[6]);
static void c23_b_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId, real_T c23_y[6]);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_c_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static void c23_info_helper(c23_ResolvedFunctionInfo c23_info[121]);
static void c23_b_info_helper(c23_ResolvedFunctionInfo c23_info[121]);
static void c23_eml_error(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance);
static void c23_eml_matlab_zsvdc
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, real_T
   c23_A[36], real_T c23_S[6]);
static void c23_eml_scalar_eg(SFc23_JointSpaceControl_BestInertiaInstanceStruct *
  chartInstance);
static real_T c23_eml_xnrm2(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_x[36], int32_T c23_ix0);
static real_T c23_abs(SFc23_JointSpaceControl_BestInertiaInstanceStruct
                      *chartInstance, real_T c23_x);
static void c23_realmin(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance);
static void c23_check_forloop_overflow_error
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, boolean_T
   c23_overflow);
static real_T c23_eml_div(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c23_x, real_T c23_y);
static void c23_eml_xscal(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[36], int32_T c23_ix0,
  real_T c23_b_x[36]);
static real_T c23_eml_xdotc(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_x[36], int32_T c23_ix0, real_T
  c23_y[36], int32_T c23_iy0);
static void c23_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, int32_T c23_ix0, real_T c23_y[36],
  int32_T c23_iy0, real_T c23_b_y[36]);
static real_T c23_b_eml_xnrm2(SFc23_JointSpaceControl_BestInertiaInstanceStruct *
  chartInstance, int32_T c23_n, real_T c23_x[6], int32_T c23_ix0);
static void c23_b_eml_xscal(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[6], int32_T c23_ix0,
  real_T c23_b_x[6]);
static void c23_b_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[36], int32_T c23_ix0,
  real_T c23_y[6], int32_T c23_iy0, real_T c23_b_y[6]);
static void c23_c_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[6], int32_T c23_ix0,
  real_T c23_y[36], int32_T c23_iy0, real_T c23_b_y[36]);
static void c23_eps(SFc23_JointSpaceControl_BestInertiaInstanceStruct
                    *chartInstance);
static void c23_b_eml_scalar_eg
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);
static void c23_b_eml_error(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance);
static real_T c23_sqrt(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c23_x);
static void c23_c_eml_error(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance);
static void c23_eml_xrotg(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c23_a, real_T c23_b, real_T *c23_b_a, real_T *c23_b_b,
  real_T *c23_c, real_T *c23_s);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_d_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_e_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_b_is_active_c23_JointSpaceControl_BestInertia, const char_T
   *c23_identifier);
static uint8_T c23_f_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_c_eml_xscal(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[36], int32_T c23_ix0);
static void c23_d_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, int32_T c23_ix0, real_T c23_y[36],
  int32_T c23_iy0);
static void c23_d_eml_xscal(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[6], int32_T c23_ix0);
static void c23_e_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[36], int32_T c23_ix0,
  real_T c23_y[6], int32_T c23_iy0);
static void c23_f_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[6], int32_T c23_ix0,
  real_T c23_y[36], int32_T c23_iy0);
static void c23_b_sqrt(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T *c23_x);
static void c23_b_eml_xrotg(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T *c23_a, real_T *c23_b, real_T *c23_c, real_T *c23_s);
static void init_dsm_address_info
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c23_is_active_c23_JointSpaceControl_BestInertia = 0U;
}

static void initialize_params_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void enable_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c23_update_debugger_state_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  int32_T c23_i0;
  real_T c23_u[6];
  const mxArray *c23_b_y = NULL;
  uint8_T c23_hoistedGlobal;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  real_T (*c23_rank_J)[6];
  c23_rank_J = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(2), FALSE);
  for (c23_i0 = 0; c23_i0 < 6; c23_i0++) {
    c23_u[c23_i0] = (*c23_rank_J)[c23_i0];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_hoistedGlobal =
    chartInstance->c23_is_active_c23_JointSpaceControl_BestInertia;
  c23_b_u = c23_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y, FALSE);
  return c23_st;
}

static void set_sim_state_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_st)
{
  const mxArray *c23_u;
  real_T c23_dv0[6];
  int32_T c23_i1;
  real_T (*c23_rank_J)[6];
  c23_rank_J = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c23_doneDoubleBufferReInit = TRUE;
  c23_u = sf_mex_dup(c23_st);
  c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 0)),
                       "rank_J", c23_dv0);
  for (c23_i1 = 0; c23_i1 < 6; c23_i1++) {
    (*c23_rank_J)[c23_i1] = c23_dv0[c23_i1];
  }

  chartInstance->c23_is_active_c23_JointSpaceControl_BestInertia =
    c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
    "is_active_c23_JointSpaceControl_BestInertia");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_JointSpaceControl_BestInertia(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void sf_c23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
  int32_T c23_i2;
  int32_T c23_i3;
  int32_T c23_i4;
  real_T c23_J[36];
  uint32_T c23_debug_family_var_map[4];
  real_T c23_nargin = 1.0;
  real_T c23_nargout = 1.0;
  real_T c23_rank_J[6];
  int32_T c23_i5;
  real_T c23_A[36];
  int32_T c23_k;
  int32_T c23_b_k;
  real_T c23_x;
  real_T c23_b_x;
  boolean_T c23_b;
  boolean_T c23_b0;
  real_T c23_c_x;
  boolean_T c23_b_b;
  boolean_T c23_b1;
  boolean_T c23_c_b;
  int32_T c23_i6;
  real_T c23_b_A[36];
  real_T c23_S[6];
  int32_T c23_i7;
  int32_T c23_i8;
  real_T (*c23_b_rank_J)[6];
  real_T (*c23_b_J)[36];
  c23_b_rank_J = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_b_J = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c23_sfEvent);
  for (c23_i2 = 0; c23_i2 < 36; c23_i2++) {
    _SFD_DATA_RANGE_CHECK((*c23_b_J)[c23_i2], 0U);
  }

  for (c23_i3 = 0; c23_i3 < 6; c23_i3++) {
    _SFD_DATA_RANGE_CHECK((*c23_b_rank_J)[c23_i3], 1U);
  }

  chartInstance->c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c23_sfEvent);
  for (c23_i4 = 0; c23_i4 < 36; c23_i4++) {
    c23_J[c23_i4] = (*c23_b_J)[c23_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c23_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 0U, c23_c_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 1U, c23_c_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c23_J, 2U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_rank_J, 3U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 4);
  for (c23_i5 = 0; c23_i5 < 36; c23_i5++) {
    c23_A[c23_i5] = c23_J[c23_i5];
  }

  for (c23_k = 1; c23_k < 37; c23_k++) {
    c23_b_k = c23_k;
    c23_x = c23_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c23_b_k), 1, 36, 1, 0) - 1];
    c23_b_x = c23_x;
    c23_b = muDoubleScalarIsInf(c23_b_x);
    c23_b0 = !c23_b;
    c23_c_x = c23_x;
    c23_b_b = muDoubleScalarIsNaN(c23_c_x);
    c23_b1 = !c23_b_b;
    c23_c_b = (c23_b0 && c23_b1);
    if (!c23_c_b) {
      c23_eml_error(chartInstance);
    }
  }

  for (c23_i6 = 0; c23_i6 < 36; c23_i6++) {
    c23_b_A[c23_i6] = c23_A[c23_i6];
  }

  c23_eml_matlab_zsvdc(chartInstance, c23_b_A, c23_S);
  for (c23_i7 = 0; c23_i7 < 6; c23_i7++) {
    c23_rank_J[c23_i7] = c23_S[c23_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c23_i8 = 0; c23_i8 < 6; c23_i8++) {
    (*c23_b_rank_J)[c23_i8] = c23_rank_J[c23_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c23_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_BestInertiaMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void registerMessagesc23_JointSpaceControl_BestInertia
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber)
{
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i9;
  real_T c23_b_inData[6];
  int32_T c23_i10;
  real_T c23_u[6];
  const mxArray *c23_y = NULL;
  SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i9 = 0; c23_i9 < 6; c23_i9++) {
    c23_b_inData[c23_i9] = (*(real_T (*)[6])c23_inData)[c23_i9];
  }

  for (c23_i10 = 0; c23_i10 < 6; c23_i10++) {
    c23_u[c23_i10] = c23_b_inData[c23_i10];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static void c23_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_rank_J, const char_T *c23_identifier, real_T c23_y[6])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_rank_J), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_rank_J);
}

static void c23_b_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId, real_T c23_y[6])
{
  real_T c23_dv1[6];
  int32_T c23_i11;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c23_i11 = 0; c23_i11 < 6; c23_i11++) {
    c23_y[c23_i11] = c23_dv1[c23_i11];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_rank_J;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[6];
  int32_T c23_i12;
  SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c23_rank_J = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_rank_J), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_rank_J);
  for (c23_i12 = 0; c23_i12 < 6; c23_i12++) {
    (*(real_T (*)[6])c23_outData)[c23_i12] = c23_y[c23_i12];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i13;
  int32_T c23_i14;
  int32_T c23_i15;
  real_T c23_b_inData[36];
  int32_T c23_i16;
  int32_T c23_i17;
  int32_T c23_i18;
  real_T c23_u[36];
  const mxArray *c23_y = NULL;
  SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_i13 = 0;
  for (c23_i14 = 0; c23_i14 < 6; c23_i14++) {
    for (c23_i15 = 0; c23_i15 < 6; c23_i15++) {
      c23_b_inData[c23_i15 + c23_i13] = (*(real_T (*)[36])c23_inData)[c23_i15 +
        c23_i13];
    }

    c23_i13 += 6;
  }

  c23_i16 = 0;
  for (c23_i17 = 0; c23_i17 < 6; c23_i17++) {
    for (c23_i18 = 0; c23_i18 < 6; c23_i18++) {
      c23_u[c23_i18 + c23_i16] = c23_b_inData[c23_i18 + c23_i16];
    }

    c23_i16 += 6;
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static real_T c23_c_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_nargout;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c23_nargout = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray
  *sf_c23_JointSpaceControl_BestInertia_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo;
  c23_ResolvedFunctionInfo c23_info[121];
  const mxArray *c23_m0 = NULL;
  int32_T c23_i19;
  c23_ResolvedFunctionInfo *c23_r0;
  c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  c23_info_helper(c23_info);
  c23_b_info_helper(c23_info);
  sf_mex_assign(&c23_m0, sf_mex_createstruct("nameCaptureInfo", 1, 121), FALSE);
  for (c23_i19 = 0; c23_i19 < 121; c23_i19++) {
    c23_r0 = &c23_info[c23_i19];
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->context)), "context", "nameCaptureInfo",
                    c23_i19);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->name)), "name", "nameCaptureInfo",
                    c23_i19);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      c23_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c23_i19);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->resolved)), "resolved",
                    "nameCaptureInfo", c23_i19);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c23_i19);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c23_i19);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c23_i19);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c23_i19);
  }

  sf_mex_assign(&c23_nameCaptureInfo, c23_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c23_nameCaptureInfo);
  return c23_nameCaptureInfo;
}

static void c23_info_helper(c23_ResolvedFunctionInfo c23_info[121])
{
  c23_info[0].context = "";
  c23_info[0].name = "svd";
  c23_info[0].dominantType = "double";
  c23_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c23_info[0].fileTimeLo = 1286840432U;
  c23_info[0].fileTimeHi = 0U;
  c23_info[0].mFileTimeLo = 0U;
  c23_info[0].mFileTimeHi = 0U;
  c23_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c23_info[1].name = "eml_index_class";
  c23_info[1].dominantType = "";
  c23_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[1].fileTimeLo = 1323192178U;
  c23_info[1].fileTimeHi = 0U;
  c23_info[1].mFileTimeLo = 0U;
  c23_info[1].mFileTimeHi = 0U;
  c23_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c23_info[2].name = "eml_int_forloop_overflow_check";
  c23_info[2].dominantType = "";
  c23_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c23_info[2].fileTimeLo = 1346531940U;
  c23_info[2].fileTimeHi = 0U;
  c23_info[2].mFileTimeLo = 0U;
  c23_info[2].mFileTimeHi = 0U;
  c23_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c23_info[3].name = "intmax";
  c23_info[3].dominantType = "char";
  c23_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c23_info[3].fileTimeLo = 1311276916U;
  c23_info[3].fileTimeHi = 0U;
  c23_info[3].mFileTimeLo = 0U;
  c23_info[3].mFileTimeHi = 0U;
  c23_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c23_info[4].name = "isfinite";
  c23_info[4].dominantType = "double";
  c23_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c23_info[4].fileTimeLo = 1286840358U;
  c23_info[4].fileTimeHi = 0U;
  c23_info[4].mFileTimeLo = 0U;
  c23_info[4].mFileTimeHi = 0U;
  c23_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c23_info[5].name = "isinf";
  c23_info[5].dominantType = "double";
  c23_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c23_info[5].fileTimeLo = 1286840360U;
  c23_info[5].fileTimeHi = 0U;
  c23_info[5].mFileTimeLo = 0U;
  c23_info[5].mFileTimeHi = 0U;
  c23_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c23_info[6].name = "isnan";
  c23_info[6].dominantType = "double";
  c23_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c23_info[6].fileTimeLo = 1286840360U;
  c23_info[6].fileTimeHi = 0U;
  c23_info[6].mFileTimeLo = 0U;
  c23_info[6].mFileTimeHi = 0U;
  c23_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c23_info[7].name = "eml_error";
  c23_info[7].dominantType = "char";
  c23_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c23_info[7].fileTimeLo = 1343851958U;
  c23_info[7].fileTimeHi = 0U;
  c23_info[7].mFileTimeLo = 0U;
  c23_info[7].mFileTimeHi = 0U;
  c23_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c23_info[8].name = "eml_xgesvd";
  c23_info[8].dominantType = "double";
  c23_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c23_info[8].fileTimeLo = 1286840406U;
  c23_info[8].fileTimeHi = 0U;
  c23_info[8].mFileTimeLo = 0U;
  c23_info[8].mFileTimeHi = 0U;
  c23_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c23_info[9].name = "eml_lapack_xgesvd";
  c23_info[9].dominantType = "double";
  c23_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c23_info[9].fileTimeLo = 1286840410U;
  c23_info[9].fileTimeHi = 0U;
  c23_info[9].mFileTimeLo = 0U;
  c23_info[9].mFileTimeHi = 0U;
  c23_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c23_info[10].name = "eml_matlab_zsvdc";
  c23_info[10].dominantType = "double";
  c23_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[10].fileTimeLo = 1295306466U;
  c23_info[10].fileTimeHi = 0U;
  c23_info[10].mFileTimeLo = 0U;
  c23_info[10].mFileTimeHi = 0U;
  c23_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[11].name = "eml_index_class";
  c23_info[11].dominantType = "";
  c23_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[11].fileTimeLo = 1323192178U;
  c23_info[11].fileTimeHi = 0U;
  c23_info[11].mFileTimeLo = 0U;
  c23_info[11].mFileTimeHi = 0U;
  c23_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[12].name = "eml_scalar_eg";
  c23_info[12].dominantType = "double";
  c23_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[12].fileTimeLo = 1286840396U;
  c23_info[12].fileTimeHi = 0U;
  c23_info[12].mFileTimeLo = 0U;
  c23_info[12].mFileTimeHi = 0U;
  c23_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[13].name = "eml_index_plus";
  c23_info[13].dominantType = "double";
  c23_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[13].fileTimeLo = 1286840378U;
  c23_info[13].fileTimeHi = 0U;
  c23_info[13].mFileTimeLo = 0U;
  c23_info[13].mFileTimeHi = 0U;
  c23_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[14].name = "eml_index_class";
  c23_info[14].dominantType = "";
  c23_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[14].fileTimeLo = 1323192178U;
  c23_info[14].fileTimeHi = 0U;
  c23_info[14].mFileTimeLo = 0U;
  c23_info[14].mFileTimeHi = 0U;
  c23_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[15].name = "min";
  c23_info[15].dominantType = "coder.internal.indexInt";
  c23_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c23_info[15].fileTimeLo = 1311276918U;
  c23_info[15].fileTimeHi = 0U;
  c23_info[15].mFileTimeLo = 0U;
  c23_info[15].mFileTimeHi = 0U;
  c23_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c23_info[16].name = "eml_min_or_max";
  c23_info[16].dominantType = "char";
  c23_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c23_info[16].fileTimeLo = 1334093090U;
  c23_info[16].fileTimeHi = 0U;
  c23_info[16].mFileTimeLo = 0U;
  c23_info[16].mFileTimeHi = 0U;
  c23_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c23_info[17].name = "eml_scalar_eg";
  c23_info[17].dominantType = "coder.internal.indexInt";
  c23_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[17].fileTimeLo = 1286840396U;
  c23_info[17].fileTimeHi = 0U;
  c23_info[17].mFileTimeLo = 0U;
  c23_info[17].mFileTimeHi = 0U;
  c23_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c23_info[18].name = "eml_scalexp_alloc";
  c23_info[18].dominantType = "coder.internal.indexInt";
  c23_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c23_info[18].fileTimeLo = 1352446460U;
  c23_info[18].fileTimeHi = 0U;
  c23_info[18].mFileTimeLo = 0U;
  c23_info[18].mFileTimeHi = 0U;
  c23_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c23_info[19].name = "eml_index_class";
  c23_info[19].dominantType = "";
  c23_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[19].fileTimeLo = 1323192178U;
  c23_info[19].fileTimeHi = 0U;
  c23_info[19].mFileTimeLo = 0U;
  c23_info[19].mFileTimeHi = 0U;
  c23_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c23_info[20].name = "eml_scalar_eg";
  c23_info[20].dominantType = "coder.internal.indexInt";
  c23_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[20].fileTimeLo = 1286840396U;
  c23_info[20].fileTimeHi = 0U;
  c23_info[20].mFileTimeLo = 0U;
  c23_info[20].mFileTimeHi = 0U;
  c23_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[21].name = "max";
  c23_info[21].dominantType = "double";
  c23_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c23_info[21].fileTimeLo = 1311276916U;
  c23_info[21].fileTimeHi = 0U;
  c23_info[21].mFileTimeLo = 0U;
  c23_info[21].mFileTimeHi = 0U;
  c23_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c23_info[22].name = "eml_min_or_max";
  c23_info[22].dominantType = "char";
  c23_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c23_info[22].fileTimeLo = 1334093090U;
  c23_info[22].fileTimeHi = 0U;
  c23_info[22].mFileTimeLo = 0U;
  c23_info[22].mFileTimeHi = 0U;
  c23_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c23_info[23].name = "eml_scalar_eg";
  c23_info[23].dominantType = "double";
  c23_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[23].fileTimeLo = 1286840396U;
  c23_info[23].fileTimeHi = 0U;
  c23_info[23].mFileTimeLo = 0U;
  c23_info[23].mFileTimeHi = 0U;
  c23_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c23_info[24].name = "eml_scalexp_alloc";
  c23_info[24].dominantType = "double";
  c23_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c23_info[24].fileTimeLo = 1352446460U;
  c23_info[24].fileTimeHi = 0U;
  c23_info[24].mFileTimeLo = 0U;
  c23_info[24].mFileTimeHi = 0U;
  c23_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c23_info[25].name = "eml_scalar_eg";
  c23_info[25].dominantType = "double";
  c23_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[25].fileTimeLo = 1286840396U;
  c23_info[25].fileTimeHi = 0U;
  c23_info[25].mFileTimeLo = 0U;
  c23_info[25].mFileTimeHi = 0U;
  c23_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c23_info[26].name = "eml_relop";
  c23_info[26].dominantType = "function_handle";
  c23_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c23_info[26].fileTimeLo = 1342472782U;
  c23_info[26].fileTimeHi = 0U;
  c23_info[26].mFileTimeLo = 0U;
  c23_info[26].mFileTimeHi = 0U;
  c23_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c23_info[27].name = "coder.internal.indexIntRelop";
  c23_info[27].dominantType = "";
  c23_info[27].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c23_info[27].fileTimeLo = 1326749922U;
  c23_info[27].fileTimeHi = 0U;
  c23_info[27].mFileTimeLo = 0U;
  c23_info[27].mFileTimeHi = 0U;
  c23_info[28].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c23_info[28].name = "eml_float_model";
  c23_info[28].dominantType = "char";
  c23_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c23_info[28].fileTimeLo = 1326749596U;
  c23_info[28].fileTimeHi = 0U;
  c23_info[28].mFileTimeLo = 0U;
  c23_info[28].mFileTimeHi = 0U;
  c23_info[29].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c23_info[29].name = "intmin";
  c23_info[29].dominantType = "char";
  c23_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c23_info[29].fileTimeLo = 1311276918U;
  c23_info[29].fileTimeHi = 0U;
  c23_info[29].mFileTimeLo = 0U;
  c23_info[29].mFileTimeHi = 0U;
  c23_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c23_info[30].name = "isnan";
  c23_info[30].dominantType = "coder.internal.indexInt";
  c23_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c23_info[30].fileTimeLo = 1286840360U;
  c23_info[30].fileTimeHi = 0U;
  c23_info[30].mFileTimeLo = 0U;
  c23_info[30].mFileTimeHi = 0U;
  c23_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[31].name = "eml_index_minus";
  c23_info[31].dominantType = "double";
  c23_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c23_info[31].fileTimeLo = 1286840378U;
  c23_info[31].fileTimeHi = 0U;
  c23_info[31].mFileTimeLo = 0U;
  c23_info[31].mFileTimeHi = 0U;
  c23_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c23_info[32].name = "eml_index_class";
  c23_info[32].dominantType = "";
  c23_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[32].fileTimeLo = 1323192178U;
  c23_info[32].fileTimeHi = 0U;
  c23_info[32].mFileTimeLo = 0U;
  c23_info[32].mFileTimeHi = 0U;
  c23_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[33].name = "max";
  c23_info[33].dominantType = "coder.internal.indexInt";
  c23_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c23_info[33].fileTimeLo = 1311276916U;
  c23_info[33].fileTimeHi = 0U;
  c23_info[33].mFileTimeLo = 0U;
  c23_info[33].mFileTimeHi = 0U;
  c23_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[34].name = "eml_int_forloop_overflow_check";
  c23_info[34].dominantType = "";
  c23_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c23_info[34].fileTimeLo = 1346531940U;
  c23_info[34].fileTimeHi = 0U;
  c23_info[34].mFileTimeLo = 0U;
  c23_info[34].mFileTimeHi = 0U;
  c23_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[35].name = "eml_index_times";
  c23_info[35].dominantType = "coder.internal.indexInt";
  c23_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c23_info[35].fileTimeLo = 1286840380U;
  c23_info[35].fileTimeHi = 0U;
  c23_info[35].mFileTimeLo = 0U;
  c23_info[35].mFileTimeHi = 0U;
  c23_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c23_info[36].name = "eml_index_class";
  c23_info[36].dominantType = "";
  c23_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[36].fileTimeLo = 1323192178U;
  c23_info[36].fileTimeHi = 0U;
  c23_info[36].mFileTimeLo = 0U;
  c23_info[36].mFileTimeHi = 0U;
  c23_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[37].name = "eml_index_plus";
  c23_info[37].dominantType = "coder.internal.indexInt";
  c23_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[37].fileTimeLo = 1286840378U;
  c23_info[37].fileTimeHi = 0U;
  c23_info[37].mFileTimeLo = 0U;
  c23_info[37].mFileTimeHi = 0U;
  c23_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[38].name = "eml_index_minus";
  c23_info[38].dominantType = "coder.internal.indexInt";
  c23_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c23_info[38].fileTimeLo = 1286840378U;
  c23_info[38].fileTimeHi = 0U;
  c23_info[38].mFileTimeLo = 0U;
  c23_info[38].mFileTimeHi = 0U;
  c23_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[39].name = "eml_xnrm2";
  c23_info[39].dominantType = "double";
  c23_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c23_info[39].fileTimeLo = 1299098376U;
  c23_info[39].fileTimeHi = 0U;
  c23_info[39].mFileTimeLo = 0U;
  c23_info[39].mFileTimeHi = 0U;
  c23_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c23_info[40].name = "eml_blas_inline";
  c23_info[40].dominantType = "";
  c23_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c23_info[40].fileTimeLo = 1299098368U;
  c23_info[40].fileTimeHi = 0U;
  c23_info[40].mFileTimeLo = 0U;
  c23_info[40].mFileTimeHi = 0U;
  c23_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  c23_info[41].name = "length";
  c23_info[41].dominantType = "double";
  c23_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c23_info[41].fileTimeLo = 1303167806U;
  c23_info[41].fileTimeHi = 0U;
  c23_info[41].mFileTimeLo = 0U;
  c23_info[41].mFileTimeHi = 0U;
  c23_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c23_info[42].name = "eml_index_class";
  c23_info[42].dominantType = "";
  c23_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[42].fileTimeLo = 1323192178U;
  c23_info[42].fileTimeHi = 0U;
  c23_info[42].mFileTimeLo = 0U;
  c23_info[42].mFileTimeHi = 0U;
  c23_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c23_info[43].name = "eml_index_class";
  c23_info[43].dominantType = "";
  c23_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[43].fileTimeLo = 1323192178U;
  c23_info[43].fileTimeHi = 0U;
  c23_info[43].mFileTimeLo = 0U;
  c23_info[43].mFileTimeHi = 0U;
  c23_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c23_info[44].name = "eml_refblas_xnrm2";
  c23_info[44].dominantType = "double";
  c23_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c23_info[44].fileTimeLo = 1299098384U;
  c23_info[44].fileTimeHi = 0U;
  c23_info[44].mFileTimeLo = 0U;
  c23_info[44].mFileTimeHi = 0U;
  c23_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c23_info[45].name = "abs";
  c23_info[45].dominantType = "double";
  c23_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c23_info[45].fileTimeLo = 1343851966U;
  c23_info[45].fileTimeHi = 0U;
  c23_info[45].mFileTimeLo = 0U;
  c23_info[45].mFileTimeHi = 0U;
  c23_info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c23_info[46].name = "eml_scalar_abs";
  c23_info[46].dominantType = "double";
  c23_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c23_info[46].fileTimeLo = 1286840312U;
  c23_info[46].fileTimeHi = 0U;
  c23_info[46].mFileTimeLo = 0U;
  c23_info[46].mFileTimeHi = 0U;
  c23_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c23_info[47].name = "realmin";
  c23_info[47].dominantType = "char";
  c23_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c23_info[47].fileTimeLo = 1307672842U;
  c23_info[47].fileTimeHi = 0U;
  c23_info[47].mFileTimeLo = 0U;
  c23_info[47].mFileTimeHi = 0U;
  c23_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c23_info[48].name = "eml_realmin";
  c23_info[48].dominantType = "char";
  c23_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c23_info[48].fileTimeLo = 1307672844U;
  c23_info[48].fileTimeHi = 0U;
  c23_info[48].mFileTimeLo = 0U;
  c23_info[48].mFileTimeHi = 0U;
  c23_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c23_info[49].name = "eml_float_model";
  c23_info[49].dominantType = "char";
  c23_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c23_info[49].fileTimeLo = 1326749596U;
  c23_info[49].fileTimeHi = 0U;
  c23_info[49].mFileTimeLo = 0U;
  c23_info[49].mFileTimeHi = 0U;
  c23_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c23_info[50].name = "eml_index_class";
  c23_info[50].dominantType = "";
  c23_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[50].fileTimeLo = 1323192178U;
  c23_info[50].fileTimeHi = 0U;
  c23_info[50].mFileTimeLo = 0U;
  c23_info[50].mFileTimeHi = 0U;
  c23_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c23_info[51].name = "eml_index_minus";
  c23_info[51].dominantType = "double";
  c23_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c23_info[51].fileTimeLo = 1286840378U;
  c23_info[51].fileTimeHi = 0U;
  c23_info[51].mFileTimeLo = 0U;
  c23_info[51].mFileTimeHi = 0U;
  c23_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c23_info[52].name = "eml_index_times";
  c23_info[52].dominantType = "coder.internal.indexInt";
  c23_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c23_info[52].fileTimeLo = 1286840380U;
  c23_info[52].fileTimeHi = 0U;
  c23_info[52].mFileTimeLo = 0U;
  c23_info[52].mFileTimeHi = 0U;
  c23_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c23_info[53].name = "eml_index_plus";
  c23_info[53].dominantType = "coder.internal.indexInt";
  c23_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[53].fileTimeLo = 1286840378U;
  c23_info[53].fileTimeHi = 0U;
  c23_info[53].mFileTimeLo = 0U;
  c23_info[53].mFileTimeHi = 0U;
  c23_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c23_info[54].name = "eml_int_forloop_overflow_check";
  c23_info[54].dominantType = "";
  c23_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c23_info[54].fileTimeLo = 1346531940U;
  c23_info[54].fileTimeHi = 0U;
  c23_info[54].mFileTimeLo = 0U;
  c23_info[54].mFileTimeHi = 0U;
  c23_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[55].name = "eml_div";
  c23_info[55].dominantType = "double";
  c23_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c23_info[55].fileTimeLo = 1313369410U;
  c23_info[55].fileTimeHi = 0U;
  c23_info[55].mFileTimeLo = 0U;
  c23_info[55].mFileTimeHi = 0U;
  c23_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[56].name = "eml_xscal";
  c23_info[56].dominantType = "double";
  c23_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c23_info[56].fileTimeLo = 1299098376U;
  c23_info[56].fileTimeHi = 0U;
  c23_info[56].mFileTimeLo = 0U;
  c23_info[56].mFileTimeHi = 0U;
  c23_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c23_info[57].name = "eml_blas_inline";
  c23_info[57].dominantType = "";
  c23_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c23_info[57].fileTimeLo = 1299098368U;
  c23_info[57].fileTimeHi = 0U;
  c23_info[57].mFileTimeLo = 0U;
  c23_info[57].mFileTimeHi = 0U;
  c23_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m!below_threshold";
  c23_info[58].name = "length";
  c23_info[58].dominantType = "double";
  c23_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c23_info[58].fileTimeLo = 1303167806U;
  c23_info[58].fileTimeHi = 0U;
  c23_info[58].mFileTimeLo = 0U;
  c23_info[58].mFileTimeHi = 0U;
  c23_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c23_info[59].name = "eml_index_class";
  c23_info[59].dominantType = "";
  c23_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[59].fileTimeLo = 1323192178U;
  c23_info[59].fileTimeHi = 0U;
  c23_info[59].mFileTimeLo = 0U;
  c23_info[59].mFileTimeHi = 0U;
  c23_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c23_info[60].name = "eml_scalar_eg";
  c23_info[60].dominantType = "double";
  c23_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[60].fileTimeLo = 1286840396U;
  c23_info[60].fileTimeHi = 0U;
  c23_info[60].mFileTimeLo = 0U;
  c23_info[60].mFileTimeHi = 0U;
  c23_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c23_info[61].name = "eml_refblas_xscal";
  c23_info[61].dominantType = "double";
  c23_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c23_info[61].fileTimeLo = 1299098384U;
  c23_info[61].fileTimeHi = 0U;
  c23_info[61].mFileTimeLo = 0U;
  c23_info[61].mFileTimeHi = 0U;
  c23_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c23_info[62].name = "eml_index_class";
  c23_info[62].dominantType = "";
  c23_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[62].fileTimeLo = 1323192178U;
  c23_info[62].fileTimeHi = 0U;
  c23_info[62].mFileTimeLo = 0U;
  c23_info[62].mFileTimeHi = 0U;
  c23_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c23_info[63].name = "eml_index_minus";
  c23_info[63].dominantType = "double";
  c23_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c23_info[63].fileTimeLo = 1286840378U;
  c23_info[63].fileTimeHi = 0U;
  c23_info[63].mFileTimeLo = 0U;
  c23_info[63].mFileTimeHi = 0U;
}

static void c23_b_info_helper(c23_ResolvedFunctionInfo c23_info[121])
{
  c23_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c23_info[64].name = "eml_index_times";
  c23_info[64].dominantType = "coder.internal.indexInt";
  c23_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c23_info[64].fileTimeLo = 1286840380U;
  c23_info[64].fileTimeHi = 0U;
  c23_info[64].mFileTimeLo = 0U;
  c23_info[64].mFileTimeHi = 0U;
  c23_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c23_info[65].name = "eml_index_plus";
  c23_info[65].dominantType = "coder.internal.indexInt";
  c23_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[65].fileTimeLo = 1286840378U;
  c23_info[65].fileTimeHi = 0U;
  c23_info[65].mFileTimeLo = 0U;
  c23_info[65].mFileTimeHi = 0U;
  c23_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c23_info[66].name = "eml_int_forloop_overflow_check";
  c23_info[66].dominantType = "";
  c23_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c23_info[66].fileTimeLo = 1346531940U;
  c23_info[66].fileTimeHi = 0U;
  c23_info[66].mFileTimeLo = 0U;
  c23_info[66].mFileTimeHi = 0U;
  c23_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[67].name = "eml_xdotc";
  c23_info[67].dominantType = "double";
  c23_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c23_info[67].fileTimeLo = 1299098372U;
  c23_info[67].fileTimeHi = 0U;
  c23_info[67].mFileTimeLo = 0U;
  c23_info[67].mFileTimeHi = 0U;
  c23_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c23_info[68].name = "eml_blas_inline";
  c23_info[68].dominantType = "";
  c23_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c23_info[68].fileTimeLo = 1299098368U;
  c23_info[68].fileTimeHi = 0U;
  c23_info[68].mFileTimeLo = 0U;
  c23_info[68].mFileTimeHi = 0U;
  c23_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c23_info[69].name = "eml_xdot";
  c23_info[69].dominantType = "double";
  c23_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c23_info[69].fileTimeLo = 1299098372U;
  c23_info[69].fileTimeHi = 0U;
  c23_info[69].mFileTimeLo = 0U;
  c23_info[69].mFileTimeHi = 0U;
  c23_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c23_info[70].name = "eml_blas_inline";
  c23_info[70].dominantType = "";
  c23_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c23_info[70].fileTimeLo = 1299098368U;
  c23_info[70].fileTimeHi = 0U;
  c23_info[70].mFileTimeLo = 0U;
  c23_info[70].mFileTimeHi = 0U;
  c23_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold";
  c23_info[71].name = "length";
  c23_info[71].dominantType = "double";
  c23_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c23_info[71].fileTimeLo = 1303167806U;
  c23_info[71].fileTimeHi = 0U;
  c23_info[71].mFileTimeLo = 0U;
  c23_info[71].mFileTimeHi = 0U;
  c23_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c23_info[72].name = "eml_index_class";
  c23_info[72].dominantType = "";
  c23_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[72].fileTimeLo = 1323192178U;
  c23_info[72].fileTimeHi = 0U;
  c23_info[72].mFileTimeLo = 0U;
  c23_info[72].mFileTimeHi = 0U;
  c23_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c23_info[73].name = "eml_refblas_xdot";
  c23_info[73].dominantType = "double";
  c23_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c23_info[73].fileTimeLo = 1299098372U;
  c23_info[73].fileTimeHi = 0U;
  c23_info[73].mFileTimeLo = 0U;
  c23_info[73].mFileTimeHi = 0U;
  c23_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c23_info[74].name = "eml_refblas_xdotx";
  c23_info[74].dominantType = "char";
  c23_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[74].fileTimeLo = 1299098374U;
  c23_info[74].fileTimeHi = 0U;
  c23_info[74].mFileTimeLo = 0U;
  c23_info[74].mFileTimeHi = 0U;
  c23_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[75].name = "eml_scalar_eg";
  c23_info[75].dominantType = "double";
  c23_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[75].fileTimeLo = 1286840396U;
  c23_info[75].fileTimeHi = 0U;
  c23_info[75].mFileTimeLo = 0U;
  c23_info[75].mFileTimeHi = 0U;
  c23_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[76].name = "eml_index_class";
  c23_info[76].dominantType = "";
  c23_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[76].fileTimeLo = 1323192178U;
  c23_info[76].fileTimeHi = 0U;
  c23_info[76].mFileTimeLo = 0U;
  c23_info[76].mFileTimeHi = 0U;
  c23_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[77].name = "eml_int_forloop_overflow_check";
  c23_info[77].dominantType = "";
  c23_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c23_info[77].fileTimeLo = 1346531940U;
  c23_info[77].fileTimeHi = 0U;
  c23_info[77].mFileTimeLo = 0U;
  c23_info[77].mFileTimeHi = 0U;
  c23_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[78].name = "eml_index_plus";
  c23_info[78].dominantType = "coder.internal.indexInt";
  c23_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[78].fileTimeLo = 1286840378U;
  c23_info[78].fileTimeHi = 0U;
  c23_info[78].mFileTimeLo = 0U;
  c23_info[78].mFileTimeHi = 0U;
  c23_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[79].name = "eml_xaxpy";
  c23_info[79].dominantType = "double";
  c23_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c23_info[79].fileTimeLo = 1299098370U;
  c23_info[79].fileTimeHi = 0U;
  c23_info[79].mFileTimeLo = 0U;
  c23_info[79].mFileTimeHi = 0U;
  c23_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c23_info[80].name = "eml_blas_inline";
  c23_info[80].dominantType = "";
  c23_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c23_info[80].fileTimeLo = 1299098368U;
  c23_info[80].fileTimeHi = 0U;
  c23_info[80].mFileTimeLo = 0U;
  c23_info[80].mFileTimeHi = 0U;
  c23_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m!below_threshold";
  c23_info[81].name = "length";
  c23_info[81].dominantType = "double";
  c23_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c23_info[81].fileTimeLo = 1303167806U;
  c23_info[81].fileTimeHi = 0U;
  c23_info[81].mFileTimeLo = 0U;
  c23_info[81].mFileTimeHi = 0U;
  c23_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c23_info[82].name = "eml_index_class";
  c23_info[82].dominantType = "";
  c23_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[82].fileTimeLo = 1323192178U;
  c23_info[82].fileTimeHi = 0U;
  c23_info[82].mFileTimeLo = 0U;
  c23_info[82].mFileTimeHi = 0U;
  c23_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c23_info[83].name = "eml_scalar_eg";
  c23_info[83].dominantType = "double";
  c23_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[83].fileTimeLo = 1286840396U;
  c23_info[83].fileTimeHi = 0U;
  c23_info[83].mFileTimeLo = 0U;
  c23_info[83].mFileTimeHi = 0U;
  c23_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c23_info[84].name = "eml_refblas_xaxpy";
  c23_info[84].dominantType = "double";
  c23_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c23_info[84].fileTimeLo = 1299098372U;
  c23_info[84].fileTimeHi = 0U;
  c23_info[84].mFileTimeLo = 0U;
  c23_info[84].mFileTimeHi = 0U;
  c23_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c23_info[85].name = "eml_index_class";
  c23_info[85].dominantType = "";
  c23_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[85].fileTimeLo = 1323192178U;
  c23_info[85].fileTimeHi = 0U;
  c23_info[85].mFileTimeLo = 0U;
  c23_info[85].mFileTimeHi = 0U;
  c23_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c23_info[86].name = "eml_isa_uint";
  c23_info[86].dominantType = "coder.internal.indexInt";
  c23_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c23_info[86].fileTimeLo = 1286840384U;
  c23_info[86].fileTimeHi = 0U;
  c23_info[86].mFileTimeLo = 0U;
  c23_info[86].mFileTimeHi = 0U;
  c23_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c23_info[87].name = "eml_index_minus";
  c23_info[87].dominantType = "double";
  c23_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c23_info[87].fileTimeLo = 1286840378U;
  c23_info[87].fileTimeHi = 0U;
  c23_info[87].mFileTimeLo = 0U;
  c23_info[87].mFileTimeHi = 0U;
  c23_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c23_info[88].name = "eml_int_forloop_overflow_check";
  c23_info[88].dominantType = "";
  c23_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c23_info[88].fileTimeLo = 1346531940U;
  c23_info[88].fileTimeHi = 0U;
  c23_info[88].mFileTimeLo = 0U;
  c23_info[88].mFileTimeHi = 0U;
  c23_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c23_info[89].name = "eml_index_plus";
  c23_info[89].dominantType = "double";
  c23_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[89].fileTimeLo = 1286840378U;
  c23_info[89].fileTimeHi = 0U;
  c23_info[89].mFileTimeLo = 0U;
  c23_info[89].mFileTimeHi = 0U;
  c23_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c23_info[90].name = "eml_index_plus";
  c23_info[90].dominantType = "coder.internal.indexInt";
  c23_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[90].fileTimeLo = 1286840378U;
  c23_info[90].fileTimeHi = 0U;
  c23_info[90].mFileTimeLo = 0U;
  c23_info[90].mFileTimeHi = 0U;
  c23_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[91].name = "abs";
  c23_info[91].dominantType = "double";
  c23_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c23_info[91].fileTimeLo = 1343851966U;
  c23_info[91].fileTimeHi = 0U;
  c23_info[91].mFileTimeLo = 0U;
  c23_info[91].mFileTimeHi = 0U;
  c23_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[92].name = "mtimes";
  c23_info[92].dominantType = "double";
  c23_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[92].fileTimeLo = 1289541292U;
  c23_info[92].fileTimeHi = 0U;
  c23_info[92].mFileTimeLo = 0U;
  c23_info[92].mFileTimeHi = 0U;
  c23_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[93].name = "realmin";
  c23_info[93].dominantType = "char";
  c23_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c23_info[93].fileTimeLo = 1307672842U;
  c23_info[93].fileTimeHi = 0U;
  c23_info[93].mFileTimeLo = 0U;
  c23_info[93].mFileTimeHi = 0U;
  c23_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[94].name = "eps";
  c23_info[94].dominantType = "char";
  c23_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c23_info[94].fileTimeLo = 1326749596U;
  c23_info[94].fileTimeHi = 0U;
  c23_info[94].mFileTimeLo = 0U;
  c23_info[94].mFileTimeHi = 0U;
  c23_info[95].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c23_info[95].name = "eml_is_float_class";
  c23_info[95].dominantType = "char";
  c23_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c23_info[95].fileTimeLo = 1286840382U;
  c23_info[95].fileTimeHi = 0U;
  c23_info[95].mFileTimeLo = 0U;
  c23_info[95].mFileTimeHi = 0U;
  c23_info[96].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c23_info[96].name = "eml_eps";
  c23_info[96].dominantType = "char";
  c23_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c23_info[96].fileTimeLo = 1326749596U;
  c23_info[96].fileTimeHi = 0U;
  c23_info[96].mFileTimeLo = 0U;
  c23_info[96].mFileTimeHi = 0U;
  c23_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c23_info[97].name = "eml_float_model";
  c23_info[97].dominantType = "char";
  c23_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c23_info[97].fileTimeLo = 1326749596U;
  c23_info[97].fileTimeHi = 0U;
  c23_info[97].mFileTimeLo = 0U;
  c23_info[97].mFileTimeHi = 0U;
  c23_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[98].name = "eml_error";
  c23_info[98].dominantType = "char";
  c23_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c23_info[98].fileTimeLo = 1343851958U;
  c23_info[98].fileTimeHi = 0U;
  c23_info[98].mFileTimeLo = 0U;
  c23_info[98].mFileTimeHi = 0U;
  c23_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c23_info[99].name = "intmin";
  c23_info[99].dominantType = "char";
  c23_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c23_info[99].fileTimeLo = 1311276918U;
  c23_info[99].fileTimeHi = 0U;
  c23_info[99].mFileTimeLo = 0U;
  c23_info[99].mFileTimeHi = 0U;
  c23_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c23_info[100].name = "eml_const_nonsingleton_dim";
  c23_info[100].dominantType = "double";
  c23_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c23_info[100].fileTimeLo = 1286840296U;
  c23_info[100].fileTimeHi = 0U;
  c23_info[100].mFileTimeLo = 0U;
  c23_info[100].mFileTimeHi = 0U;
  c23_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c23_info[101].name = "eml_scalar_eg";
  c23_info[101].dominantType = "double";
  c23_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[101].fileTimeLo = 1286840396U;
  c23_info[101].fileTimeHi = 0U;
  c23_info[101].mFileTimeLo = 0U;
  c23_info[101].mFileTimeHi = 0U;
  c23_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c23_info[102].name = "eml_index_class";
  c23_info[102].dominantType = "";
  c23_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[102].fileTimeLo = 1323192178U;
  c23_info[102].fileTimeHi = 0U;
  c23_info[102].mFileTimeLo = 0U;
  c23_info[102].mFileTimeHi = 0U;
  c23_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c23_info[103].name = "eml_index_class";
  c23_info[103].dominantType = "";
  c23_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[103].fileTimeLo = 1323192178U;
  c23_info[103].fileTimeHi = 0U;
  c23_info[103].mFileTimeLo = 0U;
  c23_info[103].mFileTimeHi = 0U;
  c23_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c23_info[104].name = "isnan";
  c23_info[104].dominantType = "double";
  c23_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c23_info[104].fileTimeLo = 1286840360U;
  c23_info[104].fileTimeHi = 0U;
  c23_info[104].mFileTimeLo = 0U;
  c23_info[104].mFileTimeHi = 0U;
  c23_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c23_info[105].name = "eml_index_plus";
  c23_info[105].dominantType = "coder.internal.indexInt";
  c23_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[105].fileTimeLo = 1286840378U;
  c23_info[105].fileTimeHi = 0U;
  c23_info[105].mFileTimeLo = 0U;
  c23_info[105].mFileTimeHi = 0U;
  c23_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c23_info[106].name = "eml_int_forloop_overflow_check";
  c23_info[106].dominantType = "";
  c23_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c23_info[106].fileTimeLo = 1346531940U;
  c23_info[106].fileTimeHi = 0U;
  c23_info[106].mFileTimeLo = 0U;
  c23_info[106].mFileTimeHi = 0U;
  c23_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c23_info[107].name = "eml_relop";
  c23_info[107].dominantType = "function_handle";
  c23_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c23_info[107].fileTimeLo = 1342472782U;
  c23_info[107].fileTimeHi = 0U;
  c23_info[107].mFileTimeLo = 0U;
  c23_info[107].mFileTimeHi = 0U;
  c23_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[108].name = "sqrt";
  c23_info[108].dominantType = "double";
  c23_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c23_info[108].fileTimeLo = 1343851986U;
  c23_info[108].fileTimeHi = 0U;
  c23_info[108].mFileTimeLo = 0U;
  c23_info[108].mFileTimeHi = 0U;
  c23_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c23_info[109].name = "eml_error";
  c23_info[109].dominantType = "char";
  c23_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c23_info[109].fileTimeLo = 1343851958U;
  c23_info[109].fileTimeHi = 0U;
  c23_info[109].mFileTimeLo = 0U;
  c23_info[109].mFileTimeHi = 0U;
  c23_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c23_info[110].name = "eml_scalar_sqrt";
  c23_info[110].dominantType = "double";
  c23_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c23_info[110].fileTimeLo = 1286840338U;
  c23_info[110].fileTimeHi = 0U;
  c23_info[110].mFileTimeLo = 0U;
  c23_info[110].mFileTimeHi = 0U;
  c23_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c23_info[111].name = "eml_xrotg";
  c23_info[111].dominantType = "double";
  c23_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c23_info[111].fileTimeLo = 1299098376U;
  c23_info[111].fileTimeHi = 0U;
  c23_info[111].mFileTimeLo = 0U;
  c23_info[111].mFileTimeHi = 0U;
  c23_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c23_info[112].name = "eml_blas_inline";
  c23_info[112].dominantType = "";
  c23_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c23_info[112].fileTimeLo = 1299098368U;
  c23_info[112].fileTimeHi = 0U;
  c23_info[112].mFileTimeLo = 0U;
  c23_info[112].mFileTimeHi = 0U;
  c23_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m";
  c23_info[113].name = "eml_refblas_xrotg";
  c23_info[113].dominantType = "double";
  c23_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c23_info[113].fileTimeLo = 1299098384U;
  c23_info[113].fileTimeHi = 0U;
  c23_info[113].mFileTimeLo = 0U;
  c23_info[113].mFileTimeHi = 0U;
  c23_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c23_info[114].name = "abs";
  c23_info[114].dominantType = "double";
  c23_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c23_info[114].fileTimeLo = 1343851966U;
  c23_info[114].fileTimeHi = 0U;
  c23_info[114].mFileTimeLo = 0U;
  c23_info[114].mFileTimeHi = 0U;
  c23_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c23_info[115].name = "mrdivide";
  c23_info[115].dominantType = "double";
  c23_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c23_info[115].fileTimeLo = 1357973148U;
  c23_info[115].fileTimeHi = 0U;
  c23_info[115].mFileTimeLo = 1319751566U;
  c23_info[115].mFileTimeHi = 0U;
  c23_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c23_info[116].name = "rdivide";
  c23_info[116].dominantType = "double";
  c23_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[116].fileTimeLo = 1346531988U;
  c23_info[116].fileTimeHi = 0U;
  c23_info[116].mFileTimeLo = 0U;
  c23_info[116].mFileTimeHi = 0U;
  c23_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[117].name = "eml_scalexp_compatible";
  c23_info[117].dominantType = "double";
  c23_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c23_info[117].fileTimeLo = 1286840396U;
  c23_info[117].fileTimeHi = 0U;
  c23_info[117].mFileTimeLo = 0U;
  c23_info[117].mFileTimeHi = 0U;
  c23_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[118].name = "eml_div";
  c23_info[118].dominantType = "double";
  c23_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c23_info[118].fileTimeLo = 1313369410U;
  c23_info[118].fileTimeHi = 0U;
  c23_info[118].mFileTimeLo = 0U;
  c23_info[118].mFileTimeHi = 0U;
  c23_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c23_info[119].name = "sqrt";
  c23_info[119].dominantType = "double";
  c23_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c23_info[119].fileTimeLo = 1343851986U;
  c23_info[119].fileTimeHi = 0U;
  c23_info[119].mFileTimeLo = 0U;
  c23_info[119].mFileTimeHi = 0U;
  c23_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m!eml_ceval_xrotg";
  c23_info[120].name = "eml_scalar_eg";
  c23_info[120].dominantType = "double";
  c23_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[120].fileTimeLo = 1286840396U;
  c23_info[120].fileTimeHi = 0U;
  c23_info[120].mFileTimeLo = 0U;
  c23_info[120].mFileTimeHi = 0U;
}

static void c23_eml_error(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance)
{
  int32_T c23_i20;
  static char_T c23_cv0[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c23_u[33];
  const mxArray *c23_y = NULL;
  for (c23_i20 = 0; c23_i20 < 33; c23_i20++) {
    c23_u[c23_i20] = c23_cv0[c23_i20];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 10, 0U, 1U, 0U, 2, 1, 33),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c23_y));
}

static void c23_eml_matlab_zsvdc
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, real_T
   c23_A[36], real_T c23_S[6])
{
  int32_T c23_i21;
  real_T c23_s[6];
  int32_T c23_i22;
  real_T c23_e[6];
  int32_T c23_i23;
  real_T c23_work[6];
  int32_T c23_q;
  int32_T c23_b_q;
  int32_T c23_a;
  int32_T c23_qp1;
  int32_T c23_b_a;
  int32_T c23_qm1;
  int32_T c23_b;
  int32_T c23_c;
  int32_T c23_c_a;
  int32_T c23_b_b;
  int32_T c23_qq;
  int32_T c23_c_b;
  int32_T c23_nmq;
  int32_T c23_d_a;
  int32_T c23_nmqp1;
  int32_T c23_i24;
  real_T c23_b_A[36];
  real_T c23_nrm;
  real_T c23_absx;
  real_T c23_d;
  real_T c23_y;
  real_T c23_d1;
  int32_T c23_b_qp1;
  boolean_T c23_overflow;
  int32_T c23_jj;
  int32_T c23_b_jj;
  int32_T c23_e_a;
  int32_T c23_b_c;
  int32_T c23_d_b;
  int32_T c23_c_c;
  int32_T c23_f_a;
  int32_T c23_e_b;
  int32_T c23_qjj;
  int32_T c23_i25;
  real_T c23_c_A[36];
  int32_T c23_i26;
  real_T c23_d_A[36];
  real_T c23_t;
  int32_T c23_f_b;
  int32_T c23_pmq;
  int32_T c23_i27;
  real_T c23_b_e[6];
  real_T c23_b_absx;
  real_T c23_b_d;
  real_T c23_b_y;
  real_T c23_d2;
  int32_T c23_c_qp1;
  boolean_T c23_b_overflow;
  int32_T c23_ii;
  int32_T c23_b_ii;
  int32_T c23_d_qp1;
  boolean_T c23_c_overflow;
  int32_T c23_c_jj;
  int32_T c23_g_a;
  int32_T c23_d_c;
  int32_T c23_g_b;
  int32_T c23_e_c;
  int32_T c23_h_a;
  int32_T c23_h_b;
  int32_T c23_qp1jj;
  int32_T c23_i28;
  real_T c23_e_A[36];
  int32_T c23_e_qp1;
  boolean_T c23_d_overflow;
  int32_T c23_d_jj;
  int32_T c23_i_a;
  int32_T c23_f_c;
  int32_T c23_i_b;
  int32_T c23_g_c;
  int32_T c23_j_a;
  int32_T c23_j_b;
  int32_T c23_i29;
  real_T c23_b_work[6];
  int32_T c23_m;
  int32_T c23_c_q;
  real_T c23_rt;
  real_T c23_r;
  int32_T c23_k_a;
  int32_T c23_h_c;
  int32_T c23_l_a;
  int32_T c23_i_c;
  real_T c23_m_a;
  real_T c23_k_b;
  real_T c23_c_y;
  real_T c23_iter;
  real_T c23_tiny;
  real_T c23_snorm;
  int32_T c23_c_ii;
  real_T c23_varargin_1;
  real_T c23_varargin_2;
  real_T c23_b_varargin_2;
  real_T c23_varargin_3;
  real_T c23_x;
  real_T c23_d_y;
  real_T c23_b_x;
  real_T c23_e_y;
  real_T c23_xk;
  real_T c23_yk;
  real_T c23_c_x;
  real_T c23_f_y;
  real_T c23_maxval;
  real_T c23_b_varargin_1;
  real_T c23_c_varargin_2;
  real_T c23_d_varargin_2;
  real_T c23_b_varargin_3;
  real_T c23_d_x;
  real_T c23_g_y;
  real_T c23_e_x;
  real_T c23_h_y;
  real_T c23_b_xk;
  real_T c23_b_yk;
  real_T c23_f_x;
  real_T c23_i_y;
  int32_T c23_n_a;
  int32_T c23_o_a;
  int32_T c23_i30;
  boolean_T c23_e_overflow;
  int32_T c23_d_ii;
  int32_T c23_p_a;
  int32_T c23_j_c;
  real_T c23_test0;
  real_T c23_ztest0;
  real_T c23_l_b;
  real_T c23_j_y;
  real_T c23_m_b;
  real_T c23_k_y;
  int32_T c23_q_a;
  int32_T c23_k_c;
  real_T c23_kase;
  int32_T c23_qs;
  int32_T c23_b_m;
  int32_T c23_d_q;
  int32_T c23_r_a;
  int32_T c23_n_b;
  int32_T c23_s_a;
  int32_T c23_o_b;
  boolean_T c23_f_overflow;
  int32_T c23_e_ii;
  real_T c23_test;
  int32_T c23_t_a;
  int32_T c23_l_c;
  int32_T c23_u_a;
  int32_T c23_m_c;
  real_T c23_ztest;
  real_T c23_p_b;
  real_T c23_l_y;
  int32_T c23_v_a;
  int32_T c23_w_a;
  int32_T c23_n_c;
  real_T c23_f;
  int32_T c23_x_a;
  int32_T c23_o_c;
  int32_T c23_y_a;
  int32_T c23_i31;
  int32_T c23_e_q;
  int32_T c23_ab_a;
  int32_T c23_q_b;
  int32_T c23_bb_a;
  int32_T c23_r_b;
  boolean_T c23_g_overflow;
  int32_T c23_k;
  int32_T c23_b_k;
  real_T c23_t1;
  real_T c23_b_t1;
  real_T c23_b_f;
  real_T c23_sn;
  real_T c23_cs;
  real_T c23_b_cs;
  real_T c23_b_sn;
  int32_T c23_cb_a;
  int32_T c23_km1;
  real_T c23_db_a;
  real_T c23_s_b;
  real_T c23_eb_a;
  real_T c23_t_b;
  real_T c23_m_y;
  int32_T c23_fb_a;
  int32_T c23_f_q;
  int32_T c23_c_m;
  int32_T c23_gb_a;
  int32_T c23_u_b;
  int32_T c23_hb_a;
  int32_T c23_v_b;
  boolean_T c23_h_overflow;
  int32_T c23_c_k;
  real_T c23_c_t1;
  real_T c23_unusedU0;
  real_T c23_c_sn;
  real_T c23_c_cs;
  real_T c23_ib_a;
  real_T c23_w_b;
  real_T c23_jb_a;
  real_T c23_x_b;
  real_T c23_n_y;
  int32_T c23_kb_a;
  int32_T c23_mm1;
  real_T c23_d3;
  real_T c23_d4;
  real_T c23_d5;
  real_T c23_d6;
  real_T c23_d7;
  real_T c23_c_varargin_1[5];
  int32_T c23_ixstart;
  real_T c23_mtmp;
  real_T c23_g_x;
  boolean_T c23_y_b;
  int32_T c23_ix;
  int32_T c23_b_ix;
  real_T c23_h_x;
  boolean_T c23_ab_b;
  int32_T c23_lb_a;
  int32_T c23_i32;
  boolean_T c23_i_overflow;
  int32_T c23_c_ix;
  real_T c23_mb_a;
  real_T c23_bb_b;
  boolean_T c23_p;
  real_T c23_b_mtmp;
  real_T c23_scale;
  real_T c23_sm;
  real_T c23_smm1;
  real_T c23_emm1;
  real_T c23_sqds;
  real_T c23_eqds;
  real_T c23_nb_a;
  real_T c23_cb_b;
  real_T c23_o_y;
  real_T c23_ob_a;
  real_T c23_db_b;
  real_T c23_p_y;
  real_T c23_eb_b;
  real_T c23_pb_a;
  real_T c23_fb_b;
  real_T c23_p_c;
  real_T c23_qb_a;
  real_T c23_gb_b;
  real_T c23_shift;
  real_T c23_rb_a;
  real_T c23_hb_b;
  real_T c23_q_y;
  real_T c23_sb_a;
  real_T c23_ib_b;
  real_T c23_r_y;
  real_T c23_tb_a;
  real_T c23_jb_b;
  real_T c23_g;
  int32_T c23_g_q;
  int32_T c23_b_mm1;
  int32_T c23_ub_a;
  int32_T c23_kb_b;
  int32_T c23_vb_a;
  int32_T c23_lb_b;
  boolean_T c23_j_overflow;
  int32_T c23_d_k;
  int32_T c23_wb_a;
  int32_T c23_xb_a;
  int32_T c23_kp1;
  real_T c23_c_f;
  real_T c23_unusedU1;
  real_T c23_d_sn;
  real_T c23_d_cs;
  real_T c23_yb_a;
  real_T c23_mb_b;
  real_T c23_s_y;
  real_T c23_ac_a;
  real_T c23_nb_b;
  real_T c23_t_y;
  real_T c23_bc_a;
  real_T c23_ob_b;
  real_T c23_u_y;
  real_T c23_cc_a;
  real_T c23_pb_b;
  real_T c23_v_y;
  real_T c23_dc_a;
  real_T c23_qb_b;
  real_T c23_ec_a;
  real_T c23_rb_b;
  real_T c23_w_y;
  real_T c23_d_f;
  real_T c23_unusedU2;
  real_T c23_e_sn;
  real_T c23_e_cs;
  real_T c23_fc_a;
  real_T c23_sb_b;
  real_T c23_x_y;
  real_T c23_gc_a;
  real_T c23_tb_b;
  real_T c23_y_y;
  real_T c23_hc_a;
  real_T c23_ub_b;
  real_T c23_ab_y;
  real_T c23_ic_a;
  real_T c23_vb_b;
  real_T c23_bb_y;
  real_T c23_jc_a;
  real_T c23_wb_b;
  real_T c23_kc_a;
  real_T c23_xb_b;
  real_T c23_cb_y;
  int32_T c23_lc_a;
  int32_T c23_q_c;
  int32_T c23_e_k;
  int32_T c23_mc_a;
  int32_T c23_nc_a;
  int32_T c23_oc_a;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = FALSE;
  c23_eml_scalar_eg(chartInstance);
  for (c23_i21 = 0; c23_i21 < 6; c23_i21++) {
    c23_s[c23_i21] = 0.0;
  }

  for (c23_i22 = 0; c23_i22 < 6; c23_i22++) {
    c23_e[c23_i22] = 0.0;
  }

  for (c23_i23 = 0; c23_i23 < 6; c23_i23++) {
    c23_work[c23_i23] = 0.0;
  }

  for (c23_q = 1; c23_q < 6; c23_q++) {
    c23_b_q = c23_q;
    c23_a = c23_b_q + 1;
    c23_qp1 = c23_a;
    c23_b_a = c23_b_q;
    c23_qm1 = c23_b_a;
    c23_b = c23_qm1 - 1;
    c23_c = 6 * c23_b;
    c23_c_a = c23_b_q;
    c23_b_b = c23_c;
    c23_qq = c23_c_a + c23_b_b;
    c23_c_b = c23_b_q;
    c23_nmq = 6 - c23_c_b;
    c23_d_a = c23_nmq + 1;
    c23_nmqp1 = c23_d_a;
    if (c23_b_q <= 5) {
      for (c23_i24 = 0; c23_i24 < 36; c23_i24++) {
        c23_b_A[c23_i24] = c23_A[c23_i24];
      }

      c23_nrm = c23_eml_xnrm2(chartInstance, c23_nmqp1, c23_b_A, c23_qq);
      if (c23_nrm > 0.0) {
        c23_absx = c23_nrm;
        c23_d = c23_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c23_qq), 1, 36, 1, 0) - 1];
        if (c23_d < 0.0) {
          c23_y = -c23_absx;
        } else {
          c23_y = c23_absx;
        }

        c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1] = c23_y;
        c23_d1 = c23_eml_div(chartInstance, 1.0,
                             c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1]);
        c23_c_eml_xscal(chartInstance, c23_nmqp1, c23_d1, c23_A, c23_qq);
        c23_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_qq), 1, 36, 1, 0) - 1] = c23_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_qq), 1, 36, 1, 0) - 1]
          + 1.0;
        c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1] =
          -c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1];
      } else {
        c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1] = 0.0;
      }
    }

    c23_b_qp1 = c23_qp1;
    c23_overflow = FALSE;
    if (c23_overflow) {
      c23_check_forloop_overflow_error(chartInstance, c23_overflow);
    }

    for (c23_jj = c23_b_qp1; c23_jj < 7; c23_jj++) {
      c23_b_jj = c23_jj;
      c23_e_a = c23_b_jj;
      c23_b_c = c23_e_a;
      c23_d_b = c23_b_c - 1;
      c23_c_c = 6 * c23_d_b;
      c23_f_a = c23_b_q;
      c23_e_b = c23_c_c;
      c23_qjj = c23_f_a + c23_e_b;
      if (c23_b_q <= 5) {
        if (c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c23_b_q), 1, 6, 1, 0) - 1] != 0.0) {
          for (c23_i25 = 0; c23_i25 < 36; c23_i25++) {
            c23_c_A[c23_i25] = c23_A[c23_i25];
          }

          for (c23_i26 = 0; c23_i26 < 36; c23_i26++) {
            c23_d_A[c23_i26] = c23_A[c23_i26];
          }

          c23_t = c23_eml_xdotc(chartInstance, c23_nmqp1, c23_c_A, c23_qq,
                                c23_d_A, c23_qjj);
          c23_t = -c23_eml_div(chartInstance, c23_t, c23_A
                               [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) + 6 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_q), 1, 6, 2, 0) - 1)) - 1]);
          c23_d_eml_xaxpy(chartInstance, c23_nmqp1, c23_t, c23_qq, c23_A,
                          c23_qjj);
        }
      }

      c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c23_b_jj), 1, 6, 1, 0) - 1] = c23_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_qjj), 1, 36, 1, 0) - 1];
    }

    if (c23_b_q <= 4) {
      c23_f_b = c23_b_q;
      c23_pmq = 6 - c23_f_b;
      for (c23_i27 = 0; c23_i27 < 6; c23_i27++) {
        c23_b_e[c23_i27] = c23_e[c23_i27];
      }

      c23_nrm = c23_b_eml_xnrm2(chartInstance, c23_pmq, c23_b_e, c23_qp1);
      if (c23_nrm == 0.0) {
        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1] = 0.0;
      } else {
        c23_b_absx = c23_nrm;
        c23_b_d = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c23_qp1), 1, 6, 1, 0) - 1];
        if (c23_b_d < 0.0) {
          c23_b_y = -c23_b_absx;
        } else {
          c23_b_y = c23_b_absx;
        }

        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1] = c23_b_y;
        c23_d2 = c23_eml_div(chartInstance, 1.0,
                             c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1]);
        c23_d_eml_xscal(chartInstance, c23_pmq, c23_d2, c23_e, c23_qp1);
        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_qp1), 1, 6, 1, 0) - 1] = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_qp1), 1, 6, 1, 0) - 1]
          + 1.0;
      }

      c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c23_b_q), 1, 6, 1, 0) - 1] = -c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1];
      if (c23_qp1 <= 6) {
        if (c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c23_b_q), 1, 6, 1, 0) - 1] != 0.0) {
          c23_c_qp1 = c23_qp1;
          c23_b_overflow = FALSE;
          if (c23_b_overflow) {
            c23_check_forloop_overflow_error(chartInstance, c23_b_overflow);
          }

          for (c23_ii = c23_c_qp1; c23_ii < 7; c23_ii++) {
            c23_b_ii = c23_ii;
            c23_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c23_b_ii), 1, 6, 1, 0) - 1] = 0.0;
          }

          c23_d_qp1 = c23_qp1;
          c23_c_overflow = FALSE;
          if (c23_c_overflow) {
            c23_check_forloop_overflow_error(chartInstance, c23_c_overflow);
          }

          for (c23_c_jj = c23_d_qp1; c23_c_jj < 7; c23_c_jj++) {
            c23_b_jj = c23_c_jj;
            c23_g_a = c23_b_jj;
            c23_d_c = c23_g_a;
            c23_g_b = c23_d_c - 1;
            c23_e_c = 6 * c23_g_b;
            c23_h_a = c23_qp1;
            c23_h_b = c23_e_c;
            c23_qp1jj = c23_h_a + c23_h_b;
            for (c23_i28 = 0; c23_i28 < 36; c23_i28++) {
              c23_e_A[c23_i28] = c23_A[c23_i28];
            }

            c23_e_eml_xaxpy(chartInstance, c23_nmq,
                            c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c23_b_jj), 1, 6, 1, 0) - 1],
                            c23_e_A, c23_qp1jj, c23_work, c23_qp1);
          }

          c23_e_qp1 = c23_qp1;
          c23_d_overflow = FALSE;
          if (c23_d_overflow) {
            c23_check_forloop_overflow_error(chartInstance, c23_d_overflow);
          }

          for (c23_d_jj = c23_e_qp1; c23_d_jj < 7; c23_d_jj++) {
            c23_b_jj = c23_d_jj;
            c23_t = c23_eml_div(chartInstance,
                                -c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c23_b_jj), 1, 6, 1, 0) - 1],
                                c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c23_qp1), 1, 6, 1, 0) - 1]);
            c23_i_a = c23_b_jj;
            c23_f_c = c23_i_a;
            c23_i_b = c23_f_c - 1;
            c23_g_c = 6 * c23_i_b;
            c23_j_a = c23_qp1;
            c23_j_b = c23_g_c;
            c23_qp1jj = c23_j_a + c23_j_b;
            for (c23_i29 = 0; c23_i29 < 6; c23_i29++) {
              c23_b_work[c23_i29] = c23_work[c23_i29];
            }

            c23_f_eml_xaxpy(chartInstance, c23_nmq, c23_t, c23_b_work, c23_qp1,
                            c23_A, c23_qp1jj);
          }
        }
      }
    }
  }

  c23_m = 6;
  c23_s[5] = c23_A[35];
  c23_e[4] = c23_A[34];
  c23_e[5] = 0.0;
  for (c23_c_q = 1; c23_c_q < 7; c23_c_q++) {
    c23_b_q = c23_c_q;
    if (c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1] != 0.0) {
      c23_rt = c23_abs(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1]);
      c23_r = c23_eml_div(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1],
                          c23_rt);
      c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c23_b_q), 1, 6, 1, 0) - 1] = c23_rt;
      if (c23_b_q < 6) {
        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1] = c23_eml_div(chartInstance,
          c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1], c23_r);
      }
    }

    if (c23_b_q < 6) {
      if (c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_q), 1, 6, 1, 0) - 1] != 0.0) {
        c23_rt = c23_abs(chartInstance, c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1]);
        c23_r = c23_eml_div(chartInstance, c23_rt,
                            c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1]);
        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_q), 1, 6, 1, 0) - 1] = c23_rt;
        c23_k_a = c23_b_q;
        c23_h_c = c23_k_a;
        c23_l_a = c23_b_q;
        c23_i_c = c23_l_a;
        c23_m_a = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c23_i_c + 1)), 1, 6, 1, 0) - 1];
        c23_k_b = c23_r;
        c23_c_y = c23_m_a * c23_k_b;
        c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c23_h_c + 1)), 1, 6, 1, 0) - 1] = c23_c_y;
      }
    }
  }

  c23_iter = 0.0;
  c23_realmin(chartInstance);
  c23_eps(chartInstance);
  c23_tiny = c23_eml_div(chartInstance, 2.2250738585072014E-308,
    2.2204460492503131E-16);
  c23_snorm = 0.0;
  for (c23_c_ii = 1; c23_c_ii < 7; c23_c_ii++) {
    c23_b_ii = c23_c_ii;
    c23_varargin_1 = c23_abs(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_ii),
      1, 6, 1, 0) - 1]);
    c23_varargin_2 = c23_abs(chartInstance, c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_ii),
      1, 6, 1, 0) - 1]);
    c23_b_varargin_2 = c23_varargin_1;
    c23_varargin_3 = c23_varargin_2;
    c23_x = c23_b_varargin_2;
    c23_d_y = c23_varargin_3;
    c23_b_x = c23_x;
    c23_e_y = c23_d_y;
    c23_b_eml_scalar_eg(chartInstance);
    c23_xk = c23_b_x;
    c23_yk = c23_e_y;
    c23_c_x = c23_xk;
    c23_f_y = c23_yk;
    c23_b_eml_scalar_eg(chartInstance);
    c23_maxval = muDoubleScalarMax(c23_c_x, c23_f_y);
    c23_b_varargin_1 = c23_snorm;
    c23_c_varargin_2 = c23_maxval;
    c23_d_varargin_2 = c23_b_varargin_1;
    c23_b_varargin_3 = c23_c_varargin_2;
    c23_d_x = c23_d_varargin_2;
    c23_g_y = c23_b_varargin_3;
    c23_e_x = c23_d_x;
    c23_h_y = c23_g_y;
    c23_b_eml_scalar_eg(chartInstance);
    c23_b_xk = c23_e_x;
    c23_b_yk = c23_h_y;
    c23_f_x = c23_b_xk;
    c23_i_y = c23_b_yk;
    c23_b_eml_scalar_eg(chartInstance);
    c23_snorm = muDoubleScalarMax(c23_f_x, c23_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c23_m > 0)) {
    if (c23_iter >= 75.0) {
      c23_b_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c23_n_a = c23_m - 1;
      c23_b_q = c23_n_a;
      c23_o_a = c23_m;
      c23_i30 = c23_o_a;
      c23_e_overflow = FALSE;
      if (c23_e_overflow) {
        c23_check_forloop_overflow_error(chartInstance, c23_e_overflow);
      }

      c23_d_ii = c23_i30 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c23_d_ii > -1)) {
        c23_b_ii = c23_d_ii;
        c23_b_q = c23_b_ii;
        if (c23_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c23_p_a = c23_b_ii;
          c23_j_c = c23_p_a;
          c23_test0 = c23_abs(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_ii), 1, 6, 1, 0) -
                              1]) + c23_abs(chartInstance,
            c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c23_j_c + 1)), 1, 6, 1, 0) - 1]);
          c23_ztest0 = c23_abs(chartInstance, c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_ii), 1, 6, 1, 0) -
                               1]);
          c23_eps(chartInstance);
          c23_l_b = c23_test0;
          c23_j_y = 2.2204460492503131E-16 * c23_l_b;
          if (c23_ztest0 <= c23_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c23_ztest0 <= c23_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c23_iter > 20.0) {
              c23_eps(chartInstance);
              c23_m_b = c23_snorm;
              c23_k_y = 2.2204460492503131E-16 * c23_m_b;
              if (c23_ztest0 <= c23_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c23_d_ii--;
              guard3 = FALSE;
              guard4 = FALSE;
            }
          }
        }
      }

      if (guard4 == TRUE) {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_b_ii), 1, 6, 1, 0) - 1] = 0.0;
      }

      c23_q_a = c23_m;
      c23_k_c = c23_q_a;
      if (c23_b_q == c23_k_c - 1) {
        c23_kase = 4.0;
      } else {
        c23_qs = c23_m;
        c23_b_m = c23_m;
        c23_d_q = c23_b_q;
        c23_r_a = c23_b_m;
        c23_n_b = c23_d_q;
        c23_s_a = c23_r_a;
        c23_o_b = c23_n_b;
        if (c23_s_a < c23_o_b) {
          c23_f_overflow = FALSE;
        } else {
          c23_f_overflow = (c23_o_b < -2147483647);
        }

        if (c23_f_overflow) {
          c23_check_forloop_overflow_error(chartInstance, c23_f_overflow);
        }

        c23_e_ii = c23_b_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c23_e_ii >= c23_d_q)) {
          c23_b_ii = c23_e_ii;
          c23_qs = c23_b_ii;
          if (c23_b_ii == c23_b_q) {
            exitg4 = TRUE;
          } else {
            c23_test = 0.0;
            if (c23_b_ii < c23_m) {
              c23_test = c23_abs(chartInstance,
                                 c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c23_b_ii), 1, 6, 1, 0) - 1]);
            }

            c23_t_a = c23_b_q;
            c23_l_c = c23_t_a;
            if (c23_b_ii > c23_l_c + 1) {
              c23_u_a = c23_b_ii;
              c23_m_c = c23_u_a;
              c23_test += c23_abs(chartInstance,
                                  c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)(c23_m_c - 1)), 1, 6, 1, 0) - 1]);
            }

            c23_ztest = c23_abs(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK
                                ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
              c23_b_ii), 1, 6, 1, 0) - 1]);
            c23_eps(chartInstance);
            c23_p_b = c23_test;
            c23_l_y = 2.2204460492503131E-16 * c23_p_b;
            if (c23_ztest <= c23_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c23_ztest <= c23_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c23_e_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_ii), 1, 6, 1, 0) - 1] = 0.0;
        }

        if (c23_qs == c23_b_q) {
          c23_kase = 3.0;
        } else if (c23_qs == c23_m) {
          c23_kase = 1.0;
        } else {
          c23_kase = 2.0;
          c23_b_q = c23_qs;
        }
      }

      c23_v_a = c23_b_q + 1;
      c23_b_q = c23_v_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c23_kase)) {
       case 1:
        c23_w_a = c23_m;
        c23_n_c = c23_w_a;
        c23_f = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c23_n_c - 1)), 1, 6, 1, 0) - 1];
        c23_x_a = c23_m;
        c23_o_c = c23_x_a;
        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c23_o_c - 1)), 1, 6, 1, 0) - 1] = 0.0;
        c23_y_a = c23_m - 1;
        c23_i31 = c23_y_a;
        c23_e_q = c23_b_q;
        c23_ab_a = c23_i31;
        c23_q_b = c23_e_q;
        c23_bb_a = c23_ab_a;
        c23_r_b = c23_q_b;
        if (c23_bb_a < c23_r_b) {
          c23_g_overflow = FALSE;
        } else {
          c23_g_overflow = (c23_r_b < -2147483647);
        }

        if (c23_g_overflow) {
          c23_check_forloop_overflow_error(chartInstance, c23_g_overflow);
        }

        for (c23_k = c23_i31; c23_k >= c23_e_q; c23_k--) {
          c23_b_k = c23_k;
          c23_t1 = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_b_t1 = c23_t1;
          c23_b_f = c23_f;
          c23_b_eml_xrotg(chartInstance, &c23_b_t1, &c23_b_f, &c23_cs, &c23_sn);
          c23_t1 = c23_b_t1;
          c23_f = c23_b_f;
          c23_b_cs = c23_cs;
          c23_b_sn = c23_sn;
          c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_k), 1, 6, 1, 0) - 1] = c23_t1;
          if (c23_b_k > c23_b_q) {
            c23_cb_a = c23_b_k - 1;
            c23_km1 = c23_cb_a;
            c23_db_a = -c23_b_sn;
            c23_s_b = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c23_km1), 1, 6, 1, 0) - 1];
            c23_f = c23_db_a * c23_s_b;
            c23_eb_a = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c23_km1), 1, 6, 1, 0) - 1];
            c23_t_b = c23_b_cs;
            c23_m_y = c23_eb_a * c23_t_b;
            c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c23_km1), 1, 6, 1, 0) - 1] = c23_m_y;
          }
        }
        break;

       case 2:
        c23_fb_a = c23_b_q - 1;
        c23_qm1 = c23_fb_a;
        c23_f = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c23_qm1), 1, 6, 1, 0) - 1];
        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c23_qm1), 1, 6, 1, 0) - 1] = 0.0;
        c23_f_q = c23_b_q;
        c23_c_m = c23_m;
        c23_gb_a = c23_f_q;
        c23_u_b = c23_c_m;
        c23_hb_a = c23_gb_a;
        c23_v_b = c23_u_b;
        if (c23_hb_a > c23_v_b) {
          c23_h_overflow = FALSE;
        } else {
          c23_h_overflow = (c23_v_b > 2147483646);
        }

        if (c23_h_overflow) {
          c23_check_forloop_overflow_error(chartInstance, c23_h_overflow);
        }

        for (c23_c_k = c23_f_q; c23_c_k <= c23_c_m; c23_c_k++) {
          c23_b_k = c23_c_k;
          c23_t1 = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_c_t1 = c23_t1;
          c23_unusedU0 = c23_f;
          c23_b_eml_xrotg(chartInstance, &c23_c_t1, &c23_unusedU0, &c23_c_cs,
                          &c23_c_sn);
          c23_t1 = c23_c_t1;
          c23_b_cs = c23_c_cs;
          c23_b_sn = c23_c_sn;
          c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_k), 1, 6, 1, 0) - 1] = c23_t1;
          c23_ib_a = -c23_b_sn;
          c23_w_b = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_f = c23_ib_a * c23_w_b;
          c23_jb_a = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_x_b = c23_b_cs;
          c23_n_y = c23_jb_a * c23_x_b;
          c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_k), 1, 6, 1, 0) - 1] = c23_n_y;
        }
        break;

       case 3:
        c23_kb_a = c23_m - 1;
        c23_mm1 = c23_kb_a;
        c23_d3 = c23_abs(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_m), 1, 6, 1, 0) - 1]);
        c23_d4 = c23_abs(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_mm1), 1, 6, 1, 0) - 1]);
        c23_d5 = c23_abs(chartInstance, c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_mm1), 1, 6, 1, 0) - 1]);
        c23_d6 = c23_abs(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1]);
        c23_d7 = c23_abs(chartInstance, c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1]);
        c23_c_varargin_1[0] = c23_d3;
        c23_c_varargin_1[1] = c23_d4;
        c23_c_varargin_1[2] = c23_d5;
        c23_c_varargin_1[3] = c23_d6;
        c23_c_varargin_1[4] = c23_d7;
        c23_ixstart = 1;
        c23_mtmp = c23_c_varargin_1[0];
        c23_g_x = c23_mtmp;
        c23_y_b = muDoubleScalarIsNaN(c23_g_x);
        if (c23_y_b) {
          c23_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c23_ix < 6)) {
            c23_b_ix = c23_ix;
            c23_ixstart = c23_b_ix;
            c23_h_x = c23_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c23_b_ix), 1, 5, 1, 0) - 1];
            c23_ab_b = muDoubleScalarIsNaN(c23_h_x);
            if (!c23_ab_b) {
              c23_mtmp = c23_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_ix), 1, 5, 1, 0) -
                1];
              exitg2 = TRUE;
            } else {
              c23_ix++;
            }
          }
        }

        if (c23_ixstart < 5) {
          c23_lb_a = c23_ixstart;
          c23_i32 = c23_lb_a;
          c23_i_overflow = FALSE;
          if (c23_i_overflow) {
            c23_check_forloop_overflow_error(chartInstance, c23_i_overflow);
          }

          for (c23_c_ix = c23_i32 + 1; c23_c_ix < 6; c23_c_ix++) {
            c23_b_ix = c23_c_ix;
            c23_mb_a = c23_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c23_b_ix), 1, 5, 1, 0) - 1];
            c23_bb_b = c23_mtmp;
            c23_p = (c23_mb_a > c23_bb_b);
            if (c23_p) {
              c23_mtmp = c23_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_ix), 1, 5, 1, 0) -
                1];
            }
          }
        }

        c23_b_mtmp = c23_mtmp;
        c23_scale = c23_b_mtmp;
        c23_sm = c23_eml_div(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_m), 1,
          6, 1, 0) - 1], c23_scale);
        c23_smm1 = c23_eml_div(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_mm1), 1, 6, 1, 0) - 1],
          c23_scale);
        c23_emm1 = c23_eml_div(chartInstance, c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_mm1), 1, 6, 1, 0) - 1],
          c23_scale);
        c23_sqds = c23_eml_div(chartInstance, c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1],
          c23_scale);
        c23_eqds = c23_eml_div(chartInstance, c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1],
          c23_scale);
        c23_nb_a = c23_smm1 + c23_sm;
        c23_cb_b = c23_smm1 - c23_sm;
        c23_o_y = c23_nb_a * c23_cb_b;
        c23_ob_a = c23_emm1;
        c23_db_b = c23_emm1;
        c23_p_y = c23_ob_a * c23_db_b;
        c23_eb_b = c23_eml_div(chartInstance, c23_o_y + c23_p_y, 2.0);
        c23_pb_a = c23_sm;
        c23_fb_b = c23_emm1;
        c23_p_c = c23_pb_a * c23_fb_b;
        c23_qb_a = c23_p_c;
        c23_gb_b = c23_p_c;
        c23_p_c = c23_qb_a * c23_gb_b;
        c23_shift = 0.0;
        guard1 = FALSE;
        if (c23_eb_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c23_p_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c23_rb_a = c23_eb_b;
          c23_hb_b = c23_eb_b;
          c23_q_y = c23_rb_a * c23_hb_b;
          c23_shift = c23_q_y + c23_p_c;
          c23_b_sqrt(chartInstance, &c23_shift);
          if (c23_eb_b < 0.0) {
            c23_shift = -c23_shift;
          }

          c23_shift = c23_eml_div(chartInstance, c23_p_c, c23_eb_b + c23_shift);
        }

        c23_sb_a = c23_sqds + c23_sm;
        c23_ib_b = c23_sqds - c23_sm;
        c23_r_y = c23_sb_a * c23_ib_b;
        c23_f = c23_r_y + c23_shift;
        c23_tb_a = c23_sqds;
        c23_jb_b = c23_eqds;
        c23_g = c23_tb_a * c23_jb_b;
        c23_g_q = c23_b_q;
        c23_b_mm1 = c23_mm1;
        c23_ub_a = c23_g_q;
        c23_kb_b = c23_b_mm1;
        c23_vb_a = c23_ub_a;
        c23_lb_b = c23_kb_b;
        if (c23_vb_a > c23_lb_b) {
          c23_j_overflow = FALSE;
        } else {
          c23_j_overflow = (c23_lb_b > 2147483646);
        }

        if (c23_j_overflow) {
          c23_check_forloop_overflow_error(chartInstance, c23_j_overflow);
        }

        for (c23_d_k = c23_g_q; c23_d_k <= c23_b_mm1; c23_d_k++) {
          c23_b_k = c23_d_k;
          c23_wb_a = c23_b_k;
          c23_km1 = c23_wb_a;
          c23_xb_a = c23_b_k + 1;
          c23_kp1 = c23_xb_a;
          c23_c_f = c23_f;
          c23_unusedU1 = c23_g;
          c23_b_eml_xrotg(chartInstance, &c23_c_f, &c23_unusedU1, &c23_d_cs,
                          &c23_d_sn);
          c23_f = c23_c_f;
          c23_b_cs = c23_d_cs;
          c23_b_sn = c23_d_sn;
          if (c23_b_k > c23_b_q) {
            c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c23_km1 - 1)), 1, 6, 1, 0) - 1] = c23_f;
          }

          c23_yb_a = c23_b_cs;
          c23_mb_b = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_s_y = c23_yb_a * c23_mb_b;
          c23_ac_a = c23_b_sn;
          c23_nb_b = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_t_y = c23_ac_a * c23_nb_b;
          c23_f = c23_s_y + c23_t_y;
          c23_bc_a = c23_b_cs;
          c23_ob_b = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_u_y = c23_bc_a * c23_ob_b;
          c23_cc_a = c23_b_sn;
          c23_pb_b = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_v_y = c23_cc_a * c23_pb_b;
          c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_k), 1, 6, 1, 0) - 1] = c23_u_y - c23_v_y;
          c23_dc_a = c23_b_sn;
          c23_qb_b = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_kp1), 1, 6, 1, 0) - 1];
          c23_g = c23_dc_a * c23_qb_b;
          c23_ec_a = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_kp1), 1, 6, 1, 0) - 1];
          c23_rb_b = c23_b_cs;
          c23_w_y = c23_ec_a * c23_rb_b;
          c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_kp1), 1, 6, 1, 0) - 1] = c23_w_y;
          c23_d_f = c23_f;
          c23_unusedU2 = c23_g;
          c23_b_eml_xrotg(chartInstance, &c23_d_f, &c23_unusedU2, &c23_e_cs,
                          &c23_e_sn);
          c23_f = c23_d_f;
          c23_b_cs = c23_e_cs;
          c23_b_sn = c23_e_sn;
          c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_k), 1, 6, 1, 0) - 1] = c23_f;
          c23_fc_a = c23_b_cs;
          c23_sb_b = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_x_y = c23_fc_a * c23_sb_b;
          c23_gc_a = c23_b_sn;
          c23_tb_b = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_kp1), 1, 6, 1, 0) - 1];
          c23_y_y = c23_gc_a * c23_tb_b;
          c23_f = c23_x_y + c23_y_y;
          c23_hc_a = -c23_b_sn;
          c23_ub_b = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
          c23_ab_y = c23_hc_a * c23_ub_b;
          c23_ic_a = c23_b_cs;
          c23_vb_b = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_kp1), 1, 6, 1, 0) - 1];
          c23_bb_y = c23_ic_a * c23_vb_b;
          c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_kp1), 1, 6, 1, 0) - 1] = c23_ab_y + c23_bb_y;
          c23_jc_a = c23_b_sn;
          c23_wb_b = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_kp1), 1, 6, 1, 0) - 1];
          c23_g = c23_jc_a * c23_wb_b;
          c23_kc_a = c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c23_kp1), 1, 6, 1, 0) - 1];
          c23_xb_b = c23_b_cs;
          c23_cb_y = c23_kc_a * c23_xb_b;
          c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_kp1), 1, 6, 1, 0) - 1] = c23_cb_y;
        }

        c23_lc_a = c23_m;
        c23_q_c = c23_lc_a;
        c23_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c23_q_c - 1)), 1, 6, 1, 0) - 1] = c23_f;
        c23_iter++;
        break;

       default:
        if (c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c23_b_q), 1, 6, 1, 0) - 1] < 0.0) {
          c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c23_b_q), 1, 6, 1, 0) - 1] =
            -c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c23_b_q), 1, 6, 1, 0) - 1];
        }

        c23_mc_a = c23_b_q + 1;
        c23_qp1 = c23_mc_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c23_b_q < 6)) {
          if (c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c23_b_q), 1, 6, 1, 0) - 1] <
              c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c23_qp1), 1, 6, 1, 0) - 1]) {
            c23_rt = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c23_b_q), 1, 6, 1, 0) - 1];
            c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c23_b_q), 1, 6, 1, 0) - 1] =
              c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c23_qp1), 1, 6, 1, 0) - 1];
            c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c23_qp1), 1, 6, 1, 0) - 1] = c23_rt;
            c23_b_q = c23_qp1;
            c23_oc_a = c23_b_q + 1;
            c23_qp1 = c23_oc_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c23_iter = 0.0;
        c23_nc_a = c23_m - 1;
        c23_m = c23_nc_a;
        break;
      }
    }
  }

  for (c23_e_k = 1; c23_e_k < 7; c23_e_k++) {
    c23_b_k = c23_e_k;
    c23_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c23_b_k), 1, 6, 1, 0) - 1] = c23_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
  }
}

static void c23_eml_scalar_eg(SFc23_JointSpaceControl_BestInertiaInstanceStruct *
  chartInstance)
{
}

static real_T c23_eml_xnrm2(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_x[36], int32_T c23_ix0)
{
  real_T c23_y;
  int32_T c23_b_n;
  int32_T c23_b_ix0;
  int32_T c23_c_n;
  int32_T c23_c_ix0;
  real_T c23_b_x;
  real_T c23_c_x;
  real_T c23_scale;
  int32_T c23_kstart;
  int32_T c23_a;
  int32_T c23_c;
  int32_T c23_b_a;
  int32_T c23_b_c;
  int32_T c23_c_a;
  int32_T c23_b;
  int32_T c23_kend;
  int32_T c23_b_kstart;
  int32_T c23_b_kend;
  int32_T c23_d_a;
  int32_T c23_b_b;
  int32_T c23_e_a;
  int32_T c23_c_b;
  boolean_T c23_overflow;
  int32_T c23_k;
  int32_T c23_b_k;
  real_T c23_d_x;
  real_T c23_e_x;
  real_T c23_absxk;
  real_T c23_t;
  c23_b_n = c23_n;
  c23_b_ix0 = c23_ix0;
  c23_c_n = c23_b_n;
  c23_c_ix0 = c23_b_ix0;
  c23_y = 0.0;
  if (c23_c_n < 1) {
  } else if (c23_c_n == 1) {
    c23_b_x = c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c23_c_ix0), 1, 36, 1, 0) - 1];
    c23_c_x = c23_b_x;
    c23_y = muDoubleScalarAbs(c23_c_x);
  } else {
    c23_realmin(chartInstance);
    c23_scale = 2.2250738585072014E-308;
    c23_kstart = c23_c_ix0;
    c23_a = c23_c_n;
    c23_c = c23_a;
    c23_b_a = c23_c - 1;
    c23_b_c = c23_b_a;
    c23_c_a = c23_kstart;
    c23_b = c23_b_c;
    c23_kend = c23_c_a + c23_b;
    c23_b_kstart = c23_kstart;
    c23_b_kend = c23_kend;
    c23_d_a = c23_b_kstart;
    c23_b_b = c23_b_kend;
    c23_e_a = c23_d_a;
    c23_c_b = c23_b_b;
    if (c23_e_a > c23_c_b) {
      c23_overflow = FALSE;
    } else {
      c23_overflow = (c23_c_b > 2147483646);
    }

    if (c23_overflow) {
      c23_check_forloop_overflow_error(chartInstance, c23_overflow);
    }

    for (c23_k = c23_b_kstart; c23_k <= c23_b_kend; c23_k++) {
      c23_b_k = c23_k;
      c23_d_x = c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 36, 1, 0) - 1];
      c23_e_x = c23_d_x;
      c23_absxk = muDoubleScalarAbs(c23_e_x);
      if (c23_absxk > c23_scale) {
        c23_t = c23_scale / c23_absxk;
        c23_y = 1.0 + c23_y * c23_t * c23_t;
        c23_scale = c23_absxk;
      } else {
        c23_t = c23_absxk / c23_scale;
        c23_y += c23_t * c23_t;
      }
    }

    c23_y = c23_scale * muDoubleScalarSqrt(c23_y);
  }

  return c23_y;
}

static real_T c23_abs(SFc23_JointSpaceControl_BestInertiaInstanceStruct
                      *chartInstance, real_T c23_x)
{
  real_T c23_b_x;
  c23_b_x = c23_x;
  return muDoubleScalarAbs(c23_b_x);
}

static void c23_realmin(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance)
{
}

static void c23_check_forloop_overflow_error
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, boolean_T
   c23_overflow)
{
  int32_T c23_i33;
  static char_T c23_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c23_u[34];
  const mxArray *c23_y = NULL;
  int32_T c23_i34;
  static char_T c23_cv2[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c23_b_u[23];
  const mxArray *c23_b_y = NULL;
  if (!c23_overflow) {
  } else {
    for (c23_i33 = 0; c23_i33 < 34; c23_i33++) {
      c23_u[c23_i33] = c23_cv1[c23_i33];
    }

    c23_y = NULL;
    sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c23_i34 = 0; c23_i34 < 23; c23_i34++) {
      c23_b_u[c23_i34] = c23_cv2[c23_i34];
    }

    c23_b_y = NULL;
    sf_mex_assign(&c23_b_y, sf_mex_create("y", c23_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c23_y, 14, c23_b_y));
  }
}

static real_T c23_eml_div(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c23_x, real_T c23_y)
{
  return c23_x / c23_y;
}

static void c23_eml_xscal(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[36], int32_T c23_ix0,
  real_T c23_b_x[36])
{
  int32_T c23_i35;
  for (c23_i35 = 0; c23_i35 < 36; c23_i35++) {
    c23_b_x[c23_i35] = c23_x[c23_i35];
  }

  c23_c_eml_xscal(chartInstance, c23_n, c23_a, c23_b_x, c23_ix0);
}

static real_T c23_eml_xdotc(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_x[36], int32_T c23_ix0, real_T
  c23_y[36], int32_T c23_iy0)
{
  real_T c23_d;
  int32_T c23_b_n;
  int32_T c23_b_ix0;
  int32_T c23_b_iy0;
  int32_T c23_c_n;
  int32_T c23_c_ix0;
  int32_T c23_c_iy0;
  int32_T c23_d_n;
  int32_T c23_d_ix0;
  int32_T c23_d_iy0;
  int32_T c23_e_n;
  int32_T c23_e_ix0;
  int32_T c23_e_iy0;
  int32_T c23_ix;
  int32_T c23_iy;
  int32_T c23_f_n;
  int32_T c23_b;
  int32_T c23_b_b;
  boolean_T c23_overflow;
  int32_T c23_k;
  int32_T c23_a;
  int32_T c23_b_a;
  c23_b_n = c23_n;
  c23_b_ix0 = c23_ix0;
  c23_b_iy0 = c23_iy0;
  c23_c_n = c23_b_n;
  c23_c_ix0 = c23_b_ix0;
  c23_c_iy0 = c23_b_iy0;
  c23_d_n = c23_c_n;
  c23_d_ix0 = c23_c_ix0;
  c23_d_iy0 = c23_c_iy0;
  c23_e_n = c23_d_n;
  c23_e_ix0 = c23_d_ix0;
  c23_e_iy0 = c23_d_iy0;
  c23_d = 0.0;
  if (c23_e_n < 1) {
  } else {
    c23_ix = c23_e_ix0;
    c23_iy = c23_e_iy0;
    c23_f_n = c23_e_n;
    c23_b = c23_f_n;
    c23_b_b = c23_b;
    if (1 > c23_b_b) {
      c23_overflow = FALSE;
    } else {
      c23_overflow = (c23_b_b > 2147483646);
    }

    if (c23_overflow) {
      c23_check_forloop_overflow_error(chartInstance, c23_overflow);
    }

    for (c23_k = 1; c23_k <= c23_f_n; c23_k++) {
      c23_d += c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c23_ix), 1, 36, 1, 0) - 1] *
        c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c23_iy), 1, 36, 1, 0) - 1];
      c23_a = c23_ix + 1;
      c23_ix = c23_a;
      c23_b_a = c23_iy + 1;
      c23_iy = c23_b_a;
    }
  }

  return c23_d;
}

static void c23_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, int32_T c23_ix0, real_T c23_y[36],
  int32_T c23_iy0, real_T c23_b_y[36])
{
  int32_T c23_i36;
  for (c23_i36 = 0; c23_i36 < 36; c23_i36++) {
    c23_b_y[c23_i36] = c23_y[c23_i36];
  }

  c23_d_eml_xaxpy(chartInstance, c23_n, c23_a, c23_ix0, c23_b_y, c23_iy0);
}

static real_T c23_b_eml_xnrm2(SFc23_JointSpaceControl_BestInertiaInstanceStruct *
  chartInstance, int32_T c23_n, real_T c23_x[6], int32_T c23_ix0)
{
  real_T c23_y;
  int32_T c23_b_n;
  int32_T c23_b_ix0;
  int32_T c23_c_n;
  int32_T c23_c_ix0;
  real_T c23_b_x;
  real_T c23_c_x;
  real_T c23_scale;
  int32_T c23_kstart;
  int32_T c23_a;
  int32_T c23_c;
  int32_T c23_b_a;
  int32_T c23_b_c;
  int32_T c23_c_a;
  int32_T c23_b;
  int32_T c23_kend;
  int32_T c23_b_kstart;
  int32_T c23_b_kend;
  int32_T c23_d_a;
  int32_T c23_b_b;
  int32_T c23_e_a;
  int32_T c23_c_b;
  boolean_T c23_overflow;
  int32_T c23_k;
  int32_T c23_b_k;
  real_T c23_d_x;
  real_T c23_e_x;
  real_T c23_absxk;
  real_T c23_t;
  c23_b_n = c23_n;
  c23_b_ix0 = c23_ix0;
  c23_c_n = c23_b_n;
  c23_c_ix0 = c23_b_ix0;
  c23_y = 0.0;
  if (c23_c_n < 1) {
  } else if (c23_c_n == 1) {
    c23_b_x = c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c23_c_ix0), 1, 6, 1, 0) - 1];
    c23_c_x = c23_b_x;
    c23_y = muDoubleScalarAbs(c23_c_x);
  } else {
    c23_realmin(chartInstance);
    c23_scale = 2.2250738585072014E-308;
    c23_kstart = c23_c_ix0;
    c23_a = c23_c_n;
    c23_c = c23_a;
    c23_b_a = c23_c - 1;
    c23_b_c = c23_b_a;
    c23_c_a = c23_kstart;
    c23_b = c23_b_c;
    c23_kend = c23_c_a + c23_b;
    c23_b_kstart = c23_kstart;
    c23_b_kend = c23_kend;
    c23_d_a = c23_b_kstart;
    c23_b_b = c23_b_kend;
    c23_e_a = c23_d_a;
    c23_c_b = c23_b_b;
    if (c23_e_a > c23_c_b) {
      c23_overflow = FALSE;
    } else {
      c23_overflow = (c23_c_b > 2147483646);
    }

    if (c23_overflow) {
      c23_check_forloop_overflow_error(chartInstance, c23_overflow);
    }

    for (c23_k = c23_b_kstart; c23_k <= c23_b_kend; c23_k++) {
      c23_b_k = c23_k;
      c23_d_x = c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 6, 1, 0) - 1];
      c23_e_x = c23_d_x;
      c23_absxk = muDoubleScalarAbs(c23_e_x);
      if (c23_absxk > c23_scale) {
        c23_t = c23_scale / c23_absxk;
        c23_y = 1.0 + c23_y * c23_t * c23_t;
        c23_scale = c23_absxk;
      } else {
        c23_t = c23_absxk / c23_scale;
        c23_y += c23_t * c23_t;
      }
    }

    c23_y = c23_scale * muDoubleScalarSqrt(c23_y);
  }

  return c23_y;
}

static void c23_b_eml_xscal(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[6], int32_T c23_ix0,
  real_T c23_b_x[6])
{
  int32_T c23_i37;
  for (c23_i37 = 0; c23_i37 < 6; c23_i37++) {
    c23_b_x[c23_i37] = c23_x[c23_i37];
  }

  c23_d_eml_xscal(chartInstance, c23_n, c23_a, c23_b_x, c23_ix0);
}

static void c23_b_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[36], int32_T c23_ix0,
  real_T c23_y[6], int32_T c23_iy0, real_T c23_b_y[6])
{
  int32_T c23_i38;
  int32_T c23_i39;
  real_T c23_b_x[36];
  for (c23_i38 = 0; c23_i38 < 6; c23_i38++) {
    c23_b_y[c23_i38] = c23_y[c23_i38];
  }

  for (c23_i39 = 0; c23_i39 < 36; c23_i39++) {
    c23_b_x[c23_i39] = c23_x[c23_i39];
  }

  c23_e_eml_xaxpy(chartInstance, c23_n, c23_a, c23_b_x, c23_ix0, c23_b_y,
                  c23_iy0);
}

static void c23_c_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[6], int32_T c23_ix0,
  real_T c23_y[36], int32_T c23_iy0, real_T c23_b_y[36])
{
  int32_T c23_i40;
  int32_T c23_i41;
  real_T c23_b_x[6];
  for (c23_i40 = 0; c23_i40 < 36; c23_i40++) {
    c23_b_y[c23_i40] = c23_y[c23_i40];
  }

  for (c23_i41 = 0; c23_i41 < 6; c23_i41++) {
    c23_b_x[c23_i41] = c23_x[c23_i41];
  }

  c23_f_eml_xaxpy(chartInstance, c23_n, c23_a, c23_b_x, c23_ix0, c23_b_y,
                  c23_iy0);
}

static void c23_eps(SFc23_JointSpaceControl_BestInertiaInstanceStruct
                    *chartInstance)
{
}

static void c23_b_eml_scalar_eg
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
{
}

static void c23_b_eml_error(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance)
{
  int32_T c23_i42;
  static char_T c23_cv3[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c23_u[30];
  const mxArray *c23_y = NULL;
  for (c23_i42 = 0; c23_i42 < 30; c23_i42++) {
    c23_u[c23_i42] = c23_cv3[c23_i42];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c23_y));
}

static real_T c23_sqrt(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c23_x)
{
  real_T c23_b_x;
  c23_b_x = c23_x;
  c23_b_sqrt(chartInstance, &c23_b_x);
  return c23_b_x;
}

static void c23_c_eml_error(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance)
{
  int32_T c23_i43;
  static char_T c23_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c23_u[30];
  const mxArray *c23_y = NULL;
  int32_T c23_i44;
  static char_T c23_cv5[4] = { 's', 'q', 'r', 't' };

  char_T c23_b_u[4];
  const mxArray *c23_b_y = NULL;
  for (c23_i43 = 0; c23_i43 < 30; c23_i43++) {
    c23_u[c23_i43] = c23_cv4[c23_i43];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  for (c23_i44 = 0; c23_i44 < 4; c23_i44++) {
    c23_b_u[c23_i44] = c23_cv5[c23_i44];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", c23_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c23_y, 14, c23_b_y));
}

static void c23_eml_xrotg(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T c23_a, real_T c23_b, real_T *c23_b_a, real_T *c23_b_b,
  real_T *c23_c, real_T *c23_s)
{
  *c23_b_a = c23_a;
  *c23_b_b = c23_b;
  c23_b_eml_xrotg(chartInstance, c23_b_a, c23_b_b, c23_c, c23_s);
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static int32_T c23_d_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i45;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i45, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i45;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)
    chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_e_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_b_is_active_c23_JointSpaceControl_BestInertia, const char_T
   *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_JointSpaceControl_BestInertia), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_JointSpaceControl_BestInertia);
  return c23_y;
}

static uint8_T c23_f_emlrt_marshallIn
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_c_eml_xscal(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[36], int32_T c23_ix0)
{
  int32_T c23_b_n;
  real_T c23_b_a;
  int32_T c23_b_ix0;
  int32_T c23_c_n;
  real_T c23_c_a;
  int32_T c23_c_ix0;
  int32_T c23_d_ix0;
  int32_T c23_d_a;
  int32_T c23_c;
  int32_T c23_b;
  int32_T c23_b_c;
  int32_T c23_e_a;
  int32_T c23_b_b;
  int32_T c23_i46;
  int32_T c23_f_a;
  int32_T c23_c_b;
  int32_T c23_g_a;
  int32_T c23_d_b;
  boolean_T c23_overflow;
  int32_T c23_k;
  int32_T c23_b_k;
  c23_b_n = c23_n;
  c23_b_a = c23_a;
  c23_b_ix0 = c23_ix0;
  c23_c_n = c23_b_n;
  c23_c_a = c23_b_a;
  c23_c_ix0 = c23_b_ix0;
  c23_d_ix0 = c23_c_ix0;
  c23_d_a = c23_c_n;
  c23_c = c23_d_a;
  c23_b = c23_c - 1;
  c23_b_c = c23_b;
  c23_e_a = c23_c_ix0;
  c23_b_b = c23_b_c;
  c23_i46 = c23_e_a + c23_b_b;
  c23_f_a = c23_d_ix0;
  c23_c_b = c23_i46;
  c23_g_a = c23_f_a;
  c23_d_b = c23_c_b;
  if (c23_g_a > c23_d_b) {
    c23_overflow = FALSE;
  } else {
    c23_overflow = (c23_d_b > 2147483646);
  }

  if (c23_overflow) {
    c23_check_forloop_overflow_error(chartInstance, c23_overflow);
  }

  for (c23_k = c23_d_ix0; c23_k <= c23_i46; c23_k++) {
    c23_b_k = c23_k;
    c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c23_b_k), 1, 36, 1, 0) - 1] = c23_c_a *
      c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c23_b_k), 1, 36, 1, 0) - 1];
  }
}

static void c23_d_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, int32_T c23_ix0, real_T c23_y[36],
  int32_T c23_iy0)
{
  int32_T c23_b_n;
  real_T c23_b_a;
  int32_T c23_b_ix0;
  int32_T c23_b_iy0;
  int32_T c23_c_n;
  real_T c23_c_a;
  int32_T c23_c_ix0;
  int32_T c23_c_iy0;
  int32_T c23_d_a;
  int32_T c23_ix;
  int32_T c23_e_a;
  int32_T c23_iy;
  int32_T c23_f_a;
  int32_T c23_i47;
  int32_T c23_b;
  int32_T c23_b_b;
  boolean_T c23_overflow;
  int32_T c23_k;
  int32_T c23_g_a;
  int32_T c23_c;
  int32_T c23_h_a;
  int32_T c23_b_c;
  int32_T c23_i_a;
  int32_T c23_c_c;
  int32_T c23_j_a;
  int32_T c23_k_a;
  c23_b_n = c23_n;
  c23_b_a = c23_a;
  c23_b_ix0 = c23_ix0;
  c23_b_iy0 = c23_iy0;
  c23_c_n = c23_b_n;
  c23_c_a = c23_b_a;
  c23_c_ix0 = c23_b_ix0;
  c23_c_iy0 = c23_b_iy0;
  if (c23_c_n < 1) {
  } else if (c23_c_a == 0.0) {
  } else {
    c23_d_a = c23_c_ix0 - 1;
    c23_ix = c23_d_a;
    c23_e_a = c23_c_iy0 - 1;
    c23_iy = c23_e_a;
    c23_f_a = c23_c_n - 1;
    c23_i47 = c23_f_a;
    c23_b = c23_i47;
    c23_b_b = c23_b;
    if (0 > c23_b_b) {
      c23_overflow = FALSE;
    } else {
      c23_overflow = (c23_b_b > 2147483646);
    }

    if (c23_overflow) {
      c23_check_forloop_overflow_error(chartInstance, c23_overflow);
    }

    for (c23_k = 0; c23_k <= c23_i47; c23_k++) {
      c23_g_a = c23_iy;
      c23_c = c23_g_a;
      c23_h_a = c23_iy;
      c23_b_c = c23_h_a;
      c23_i_a = c23_ix;
      c23_c_c = c23_i_a;
      c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_c + 1)), 1, 36, 1, 0) - 1] =
        c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_b_c + 1)), 1, 36, 1, 0) - 1] + c23_c_a *
        c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_c_c + 1)), 1, 36, 1, 0) - 1];
      c23_j_a = c23_ix + 1;
      c23_ix = c23_j_a;
      c23_k_a = c23_iy + 1;
      c23_iy = c23_k_a;
    }
  }
}

static void c23_d_eml_xscal(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[6], int32_T c23_ix0)
{
  int32_T c23_b_n;
  real_T c23_b_a;
  int32_T c23_b_ix0;
  int32_T c23_c_n;
  real_T c23_c_a;
  int32_T c23_c_ix0;
  int32_T c23_d_ix0;
  int32_T c23_d_a;
  int32_T c23_c;
  int32_T c23_b;
  int32_T c23_b_c;
  int32_T c23_e_a;
  int32_T c23_b_b;
  int32_T c23_i48;
  int32_T c23_f_a;
  int32_T c23_c_b;
  int32_T c23_g_a;
  int32_T c23_d_b;
  boolean_T c23_overflow;
  int32_T c23_k;
  int32_T c23_b_k;
  c23_b_n = c23_n;
  c23_b_a = c23_a;
  c23_b_ix0 = c23_ix0;
  c23_c_n = c23_b_n;
  c23_c_a = c23_b_a;
  c23_c_ix0 = c23_b_ix0;
  c23_d_ix0 = c23_c_ix0;
  c23_d_a = c23_c_n;
  c23_c = c23_d_a;
  c23_b = c23_c - 1;
  c23_b_c = c23_b;
  c23_e_a = c23_c_ix0;
  c23_b_b = c23_b_c;
  c23_i48 = c23_e_a + c23_b_b;
  c23_f_a = c23_d_ix0;
  c23_c_b = c23_i48;
  c23_g_a = c23_f_a;
  c23_d_b = c23_c_b;
  if (c23_g_a > c23_d_b) {
    c23_overflow = FALSE;
  } else {
    c23_overflow = (c23_d_b > 2147483646);
  }

  if (c23_overflow) {
    c23_check_forloop_overflow_error(chartInstance, c23_overflow);
  }

  for (c23_k = c23_d_ix0; c23_k <= c23_i48; c23_k++) {
    c23_b_k = c23_k;
    c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c23_b_k), 1, 6, 1, 0) - 1] = c23_c_a *
      c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c23_b_k), 1, 6, 1, 0) - 1];
  }
}

static void c23_e_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[36], int32_T c23_ix0,
  real_T c23_y[6], int32_T c23_iy0)
{
  int32_T c23_b_n;
  real_T c23_b_a;
  int32_T c23_b_ix0;
  int32_T c23_b_iy0;
  int32_T c23_c_n;
  real_T c23_c_a;
  int32_T c23_c_ix0;
  int32_T c23_c_iy0;
  int32_T c23_d_a;
  int32_T c23_ix;
  int32_T c23_e_a;
  int32_T c23_iy;
  int32_T c23_f_a;
  int32_T c23_i49;
  int32_T c23_b;
  int32_T c23_b_b;
  boolean_T c23_overflow;
  int32_T c23_k;
  int32_T c23_g_a;
  int32_T c23_c;
  int32_T c23_h_a;
  int32_T c23_b_c;
  int32_T c23_i_a;
  int32_T c23_c_c;
  int32_T c23_j_a;
  int32_T c23_k_a;
  c23_b_n = c23_n;
  c23_b_a = c23_a;
  c23_b_ix0 = c23_ix0;
  c23_b_iy0 = c23_iy0;
  c23_c_n = c23_b_n;
  c23_c_a = c23_b_a;
  c23_c_ix0 = c23_b_ix0;
  c23_c_iy0 = c23_b_iy0;
  if (c23_c_n < 1) {
  } else if (c23_c_a == 0.0) {
  } else {
    c23_d_a = c23_c_ix0 - 1;
    c23_ix = c23_d_a;
    c23_e_a = c23_c_iy0 - 1;
    c23_iy = c23_e_a;
    c23_f_a = c23_c_n - 1;
    c23_i49 = c23_f_a;
    c23_b = c23_i49;
    c23_b_b = c23_b;
    if (0 > c23_b_b) {
      c23_overflow = FALSE;
    } else {
      c23_overflow = (c23_b_b > 2147483646);
    }

    if (c23_overflow) {
      c23_check_forloop_overflow_error(chartInstance, c23_overflow);
    }

    for (c23_k = 0; c23_k <= c23_i49; c23_k++) {
      c23_g_a = c23_iy;
      c23_c = c23_g_a;
      c23_h_a = c23_iy;
      c23_b_c = c23_h_a;
      c23_i_a = c23_ix;
      c23_c_c = c23_i_a;
      c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_c + 1)), 1, 6, 1, 0) - 1] =
        c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_b_c + 1)), 1, 6, 1, 0) - 1] + c23_c_a *
        c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_c_c + 1)), 1, 36, 1, 0) - 1];
      c23_j_a = c23_ix + 1;
      c23_ix = c23_j_a;
      c23_k_a = c23_iy + 1;
      c23_iy = c23_k_a;
    }
  }
}

static void c23_f_eml_xaxpy(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, int32_T c23_n, real_T c23_a, real_T c23_x[6], int32_T c23_ix0,
  real_T c23_y[36], int32_T c23_iy0)
{
  int32_T c23_b_n;
  real_T c23_b_a;
  int32_T c23_b_ix0;
  int32_T c23_b_iy0;
  int32_T c23_c_n;
  real_T c23_c_a;
  int32_T c23_c_ix0;
  int32_T c23_c_iy0;
  int32_T c23_d_a;
  int32_T c23_ix;
  int32_T c23_e_a;
  int32_T c23_iy;
  int32_T c23_f_a;
  int32_T c23_i50;
  int32_T c23_b;
  int32_T c23_b_b;
  boolean_T c23_overflow;
  int32_T c23_k;
  int32_T c23_g_a;
  int32_T c23_c;
  int32_T c23_h_a;
  int32_T c23_b_c;
  int32_T c23_i_a;
  int32_T c23_c_c;
  int32_T c23_j_a;
  int32_T c23_k_a;
  c23_b_n = c23_n;
  c23_b_a = c23_a;
  c23_b_ix0 = c23_ix0;
  c23_b_iy0 = c23_iy0;
  c23_c_n = c23_b_n;
  c23_c_a = c23_b_a;
  c23_c_ix0 = c23_b_ix0;
  c23_c_iy0 = c23_b_iy0;
  if (c23_c_n < 1) {
  } else if (c23_c_a == 0.0) {
  } else {
    c23_d_a = c23_c_ix0 - 1;
    c23_ix = c23_d_a;
    c23_e_a = c23_c_iy0 - 1;
    c23_iy = c23_e_a;
    c23_f_a = c23_c_n - 1;
    c23_i50 = c23_f_a;
    c23_b = c23_i50;
    c23_b_b = c23_b;
    if (0 > c23_b_b) {
      c23_overflow = FALSE;
    } else {
      c23_overflow = (c23_b_b > 2147483646);
    }

    if (c23_overflow) {
      c23_check_forloop_overflow_error(chartInstance, c23_overflow);
    }

    for (c23_k = 0; c23_k <= c23_i50; c23_k++) {
      c23_g_a = c23_iy;
      c23_c = c23_g_a;
      c23_h_a = c23_iy;
      c23_b_c = c23_h_a;
      c23_i_a = c23_ix;
      c23_c_c = c23_i_a;
      c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_c + 1)), 1, 36, 1, 0) - 1] =
        c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_b_c + 1)), 1, 36, 1, 0) - 1] + c23_c_a *
        c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c23_c_c + 1)), 1, 6, 1, 0) - 1];
      c23_j_a = c23_ix + 1;
      c23_ix = c23_j_a;
      c23_k_a = c23_iy + 1;
      c23_iy = c23_k_a;
    }
  }
}

static void c23_b_sqrt(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T *c23_x)
{
  if (*c23_x < 0.0) {
    c23_c_eml_error(chartInstance);
  }

  *c23_x = muDoubleScalarSqrt(*c23_x);
}

static void c23_b_eml_xrotg(SFc23_JointSpaceControl_BestInertiaInstanceStruct
  *chartInstance, real_T *c23_a, real_T *c23_b, real_T *c23_c, real_T *c23_s)
{
  real_T c23_b_a;
  real_T c23_b_b;
  real_T c23_c_b;
  real_T c23_c_a;
  real_T c23_d_a;
  real_T c23_d_b;
  real_T c23_e_b;
  real_T c23_e_a;
  real_T c23_b_c;
  real_T c23_b_s;
  double * c23_a_t;
  double * c23_b_t;
  double * c23_c_t;
  double * c23_s_t;
  real_T c23_c_c;
  real_T c23_c_s;
  c23_b_a = *c23_a;
  c23_b_b = *c23_b;
  c23_c_b = c23_b_b;
  c23_c_a = c23_b_a;
  c23_d_a = c23_c_a;
  c23_d_b = c23_c_b;
  c23_e_b = c23_d_b;
  c23_e_a = c23_d_a;
  c23_b_c = 0.0;
  c23_b_s = 0.0;
  c23_a_t = (double *)(&c23_e_a);
  c23_b_t = (double *)(&c23_e_b);
  c23_c_t = (double *)(&c23_b_c);
  c23_s_t = (double *)(&c23_b_s);
  drotg(c23_a_t, c23_b_t, c23_c_t, c23_s_t);
  c23_c_a = c23_e_a;
  c23_c_b = c23_e_b;
  c23_c_c = c23_b_c;
  c23_c_s = c23_b_s;
  *c23_a = c23_c_a;
  *c23_b = c23_c_b;
  *c23_c = c23_c_c;
  *c23_s = c23_c_s;
}

static void init_dsm_address_info
  (SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance)
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

void sf_c23_JointSpaceControl_BestInertia_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3762254206U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1911310736U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3881424971U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(355996640U);
}

mxArray *sf_c23_JointSpaceControl_BestInertia_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("9Cdyl9J1uqlsdRKwPlV1CH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(6);
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
      pr[0] = (double)(6);
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

mxArray *sf_c23_JointSpaceControl_BestInertia_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c23_JointSpaceControl_BestInertia
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"rank_J\",},{M[8],M[0],T\"is_active_c23_JointSpaceControl_BestInertia\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_JointSpaceControl_BestInertia_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
    chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_BestInertiaMachineNumber_,
           23,
           1,
           1,
           2,
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
          init_script_number_translation
            (_JointSpaceControl_BestInertiaMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _JointSpaceControl_BestInertiaMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _JointSpaceControl_BestInertiaMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"J");
          _SFD_SET_DATA_PROPS(1,2,0,1,"rank_J");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,86);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)
            c23_sf_marshallIn);
        }

        {
          real_T (*c23_J)[36];
          real_T (*c23_rank_J)[6];
          c23_rank_J = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c23_J = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c23_J);
          _SFD_SET_DATA_VALUE_PTR(1U, *c23_rank_J);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _JointSpaceControl_BestInertiaMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "TvVH1JSjWKmBleyVouWXS";
}

static void sf_opaque_initialize_c23_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_JointSpaceControl_BestInertiaInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_JointSpaceControl_BestInertia
    ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
  initialize_c23_JointSpaceControl_BestInertia
    ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  enable_c23_JointSpaceControl_BestInertia
    ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c23_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  disable_c23_JointSpaceControl_BestInertia
    ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c23_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  sf_c23_JointSpaceControl_BestInertia
    ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c23_JointSpaceControl_BestInertia(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_JointSpaceControl_BestInertia
    ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_JointSpaceControl_BestInertia();/* state var info */
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

extern void sf_internal_set_sim_state_c23_JointSpaceControl_BestInertia
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_JointSpaceControl_BestInertia();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_JointSpaceControl_BestInertia
    ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_JointSpaceControl_BestInertia
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c23_JointSpaceControl_BestInertia(S);
}

static void sf_opaque_set_sim_state_c23_JointSpaceControl_BestInertia(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c23_JointSpaceControl_BestInertia(S, st);
}

static void sf_opaque_terminate_c23_JointSpaceControl_BestInertia(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_BestInertia_optimization_info();
    }

    finalize_c23_JointSpaceControl_BestInertia
      ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_JointSpaceControl_BestInertia
    ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_JointSpaceControl_BestInertia(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_JointSpaceControl_BestInertia
      ((SFc23_JointSpaceControl_BestInertiaInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_JointSpaceControl_BestInertia_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,23,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2579568122U));
  ssSetChecksum1(S,(1751421033U));
  ssSetChecksum2(S,(1272187754U));
  ssSetChecksum3(S,(1621042928U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_JointSpaceControl_BestInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_JointSpaceControl_BestInertia(SimStruct *S)
{
  SFc23_JointSpaceControl_BestInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc23_JointSpaceControl_BestInertiaInstanceStruct *)utMalloc
    (sizeof(SFc23_JointSpaceControl_BestInertiaInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc23_JointSpaceControl_BestInertiaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_JointSpaceControl_BestInertia;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_JointSpaceControl_BestInertia;
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

void c23_JointSpaceControl_BestInertia_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_JointSpaceControl_BestInertia(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_JointSpaceControl_BestInertia(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_JointSpaceControl_BestInertia_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
