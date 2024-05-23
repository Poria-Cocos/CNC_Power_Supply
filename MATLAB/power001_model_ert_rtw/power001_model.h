/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: power001_model.h
 *
 * Code generated for Simulink model 'power001_model'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu May 16 19:06:20 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_power001_model_h_
#define RTW_HEADER_power001_model_h_
#ifndef power001_model_COMMON_INCLUDES_
#define power001_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* power001_model_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Filter_DSTATE;              /* '<S30>/Filter' */
  real32_T Integrator_DSTATE;          /* '<S35>/Integrator' */
  real32_T Filter_DSTATE_m;            /* '<S79>/Filter' */
  real32_T Integrator_DSTATE_n;        /* '<S84>/Integrator' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T state;                      /* '<Root>/state' */
  real32_T v_tgt;                      /* '<Root>/v_tgt' */
  real32_T v_val;                      /* '<Root>/v_val' */
  real32_T i_tgt;                      /* '<Root>/i_tgt' */
  real32_T i_val;                      /* '<Root>/i_val' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T v_period_out;               /* '<Root>/v_period_out' */
  real32_T i_period_out;               /* '<Root>/i_period_out' */
} ExtY;

/* Parameters (default storage) */
struct P_ {
  real32_T kd_i;                       /* Variable: kd_i
                                        * Referenced by: '<S29>/Derivative Gain'
                                        */
  real32_T kd_v;                       /* Variable: kd_v
                                        * Referenced by: '<S78>/Derivative Gain'
                                        */
  real32_T ki_i;                       /* Variable: ki_i
                                        * Referenced by: '<S32>/Integral Gain'
                                        */
  real32_T ki_v;                       /* Variable: ki_v
                                        * Referenced by: '<S81>/Integral Gain'
                                        */
  real32_T kp_i;                       /* Variable: kp_i
                                        * Referenced by: '<S40>/Proportional Gain'
                                        */
  real32_T kp_v;                       /* Variable: kp_v
                                        * Referenced by: '<S89>/Proportional Gain'
                                        */
  real32_T period_max;                 /* Variable: period_max
                                        * Referenced by:
                                        *   '<S1>/Saturation'
                                        *   '<S2>/Saturation'
                                        */
  real32_T v_in;                       /* Variable: v_in
                                        * Referenced by:
                                        *   '<S1>/Saturation'
                                        *   '<S2>/Saturation'
                                        */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Block parameters (default storage) */
extern P rtP;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void power001_model_initialize(void);
extern void power001_model_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'power001_model'
 * '<S1>'   : 'power001_model/cc'
 * '<S2>'   : 'power001_model/cv'
 * '<S3>'   : 'power001_model/cc/PID Controller'
 * '<S4>'   : 'power001_model/cc/PID Controller/Anti-windup'
 * '<S5>'   : 'power001_model/cc/PID Controller/D Gain'
 * '<S6>'   : 'power001_model/cc/PID Controller/Filter'
 * '<S7>'   : 'power001_model/cc/PID Controller/Filter ICs'
 * '<S8>'   : 'power001_model/cc/PID Controller/I Gain'
 * '<S9>'   : 'power001_model/cc/PID Controller/Ideal P Gain'
 * '<S10>'  : 'power001_model/cc/PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'power001_model/cc/PID Controller/Integrator'
 * '<S12>'  : 'power001_model/cc/PID Controller/Integrator ICs'
 * '<S13>'  : 'power001_model/cc/PID Controller/N Copy'
 * '<S14>'  : 'power001_model/cc/PID Controller/N Gain'
 * '<S15>'  : 'power001_model/cc/PID Controller/P Copy'
 * '<S16>'  : 'power001_model/cc/PID Controller/Parallel P Gain'
 * '<S17>'  : 'power001_model/cc/PID Controller/Reset Signal'
 * '<S18>'  : 'power001_model/cc/PID Controller/Saturation'
 * '<S19>'  : 'power001_model/cc/PID Controller/Saturation Fdbk'
 * '<S20>'  : 'power001_model/cc/PID Controller/Sum'
 * '<S21>'  : 'power001_model/cc/PID Controller/Sum Fdbk'
 * '<S22>'  : 'power001_model/cc/PID Controller/Tracking Mode'
 * '<S23>'  : 'power001_model/cc/PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'power001_model/cc/PID Controller/Tsamp - Integral'
 * '<S25>'  : 'power001_model/cc/PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'power001_model/cc/PID Controller/postSat Signal'
 * '<S27>'  : 'power001_model/cc/PID Controller/preSat Signal'
 * '<S28>'  : 'power001_model/cc/PID Controller/Anti-windup/Passthrough'
 * '<S29>'  : 'power001_model/cc/PID Controller/D Gain/Internal Parameters'
 * '<S30>'  : 'power001_model/cc/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S31>'  : 'power001_model/cc/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S32>'  : 'power001_model/cc/PID Controller/I Gain/Internal Parameters'
 * '<S33>'  : 'power001_model/cc/PID Controller/Ideal P Gain/Passthrough'
 * '<S34>'  : 'power001_model/cc/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S35>'  : 'power001_model/cc/PID Controller/Integrator/Discrete'
 * '<S36>'  : 'power001_model/cc/PID Controller/Integrator ICs/Internal IC'
 * '<S37>'  : 'power001_model/cc/PID Controller/N Copy/Disabled'
 * '<S38>'  : 'power001_model/cc/PID Controller/N Gain/Internal Parameters'
 * '<S39>'  : 'power001_model/cc/PID Controller/P Copy/Disabled'
 * '<S40>'  : 'power001_model/cc/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S41>'  : 'power001_model/cc/PID Controller/Reset Signal/Disabled'
 * '<S42>'  : 'power001_model/cc/PID Controller/Saturation/Enabled'
 * '<S43>'  : 'power001_model/cc/PID Controller/Saturation Fdbk/Disabled'
 * '<S44>'  : 'power001_model/cc/PID Controller/Sum/Sum_PID'
 * '<S45>'  : 'power001_model/cc/PID Controller/Sum Fdbk/Disabled'
 * '<S46>'  : 'power001_model/cc/PID Controller/Tracking Mode/Disabled'
 * '<S47>'  : 'power001_model/cc/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S48>'  : 'power001_model/cc/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S49>'  : 'power001_model/cc/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S50>'  : 'power001_model/cc/PID Controller/postSat Signal/Forward_Path'
 * '<S51>'  : 'power001_model/cc/PID Controller/preSat Signal/Forward_Path'
 * '<S52>'  : 'power001_model/cv/PID Controller'
 * '<S53>'  : 'power001_model/cv/PID Controller/Anti-windup'
 * '<S54>'  : 'power001_model/cv/PID Controller/D Gain'
 * '<S55>'  : 'power001_model/cv/PID Controller/Filter'
 * '<S56>'  : 'power001_model/cv/PID Controller/Filter ICs'
 * '<S57>'  : 'power001_model/cv/PID Controller/I Gain'
 * '<S58>'  : 'power001_model/cv/PID Controller/Ideal P Gain'
 * '<S59>'  : 'power001_model/cv/PID Controller/Ideal P Gain Fdbk'
 * '<S60>'  : 'power001_model/cv/PID Controller/Integrator'
 * '<S61>'  : 'power001_model/cv/PID Controller/Integrator ICs'
 * '<S62>'  : 'power001_model/cv/PID Controller/N Copy'
 * '<S63>'  : 'power001_model/cv/PID Controller/N Gain'
 * '<S64>'  : 'power001_model/cv/PID Controller/P Copy'
 * '<S65>'  : 'power001_model/cv/PID Controller/Parallel P Gain'
 * '<S66>'  : 'power001_model/cv/PID Controller/Reset Signal'
 * '<S67>'  : 'power001_model/cv/PID Controller/Saturation'
 * '<S68>'  : 'power001_model/cv/PID Controller/Saturation Fdbk'
 * '<S69>'  : 'power001_model/cv/PID Controller/Sum'
 * '<S70>'  : 'power001_model/cv/PID Controller/Sum Fdbk'
 * '<S71>'  : 'power001_model/cv/PID Controller/Tracking Mode'
 * '<S72>'  : 'power001_model/cv/PID Controller/Tracking Mode Sum'
 * '<S73>'  : 'power001_model/cv/PID Controller/Tsamp - Integral'
 * '<S74>'  : 'power001_model/cv/PID Controller/Tsamp - Ngain'
 * '<S75>'  : 'power001_model/cv/PID Controller/postSat Signal'
 * '<S76>'  : 'power001_model/cv/PID Controller/preSat Signal'
 * '<S77>'  : 'power001_model/cv/PID Controller/Anti-windup/Passthrough'
 * '<S78>'  : 'power001_model/cv/PID Controller/D Gain/Internal Parameters'
 * '<S79>'  : 'power001_model/cv/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S80>'  : 'power001_model/cv/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S81>'  : 'power001_model/cv/PID Controller/I Gain/Internal Parameters'
 * '<S82>'  : 'power001_model/cv/PID Controller/Ideal P Gain/Passthrough'
 * '<S83>'  : 'power001_model/cv/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'power001_model/cv/PID Controller/Integrator/Discrete'
 * '<S85>'  : 'power001_model/cv/PID Controller/Integrator ICs/Internal IC'
 * '<S86>'  : 'power001_model/cv/PID Controller/N Copy/Disabled'
 * '<S87>'  : 'power001_model/cv/PID Controller/N Gain/Internal Parameters'
 * '<S88>'  : 'power001_model/cv/PID Controller/P Copy/Disabled'
 * '<S89>'  : 'power001_model/cv/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S90>'  : 'power001_model/cv/PID Controller/Reset Signal/Disabled'
 * '<S91>'  : 'power001_model/cv/PID Controller/Saturation/Enabled'
 * '<S92>'  : 'power001_model/cv/PID Controller/Saturation Fdbk/Disabled'
 * '<S93>'  : 'power001_model/cv/PID Controller/Sum/Sum_PID'
 * '<S94>'  : 'power001_model/cv/PID Controller/Sum Fdbk/Disabled'
 * '<S95>'  : 'power001_model/cv/PID Controller/Tracking Mode/Disabled'
 * '<S96>'  : 'power001_model/cv/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'power001_model/cv/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S98>'  : 'power001_model/cv/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'power001_model/cv/PID Controller/postSat Signal/Forward_Path'
 * '<S100>' : 'power001_model/cv/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_power001_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
