#ifndef __c5_JointSpaceControl_Manuf_MCP_h__
#define __c5_JointSpaceControl_Manuf_MCP_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c5_ResolvedFunctionInfo
#define typedef_c5_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c5_ResolvedFunctionInfo;

#endif                                 /*typedef_c5_ResolvedFunctionInfo*/

#ifndef typedef_SFc5_JointSpaceControl_Manuf_MCPInstanceStruct
#define typedef_SFc5_JointSpaceControl_Manuf_MCPInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_JointSpaceControl_Manuf_MCP;
} SFc5_JointSpaceControl_Manuf_MCPInstanceStruct;

#endif                                 /*typedef_SFc5_JointSpaceControl_Manuf_MCPInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_JointSpaceControl_Manuf_MCP_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_JointSpaceControl_Manuf_MCP_get_check_sum(mxArray *plhs[]);
extern void c5_JointSpaceControl_Manuf_MCP_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
