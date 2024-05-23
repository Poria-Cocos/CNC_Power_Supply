/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: power001_model_data.c
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

#include "power001_model.h"

/* Block parameters (default storage) */
P rtP = {
  /* Variable: kd_i
   * Referenced by: '<S29>/Derivative Gain'
   */
  0.0F,

  /* Variable: kd_v
   * Referenced by: '<S78>/Derivative Gain'
   */
  0.0F,

  /* Variable: ki_i
   * Referenced by: '<S32>/Integral Gain'
   */
  1.0F,

  /* Variable: ki_v
   * Referenced by: '<S81>/Integral Gain'
   */
  1.0F,

  /* Variable: kp_i
   * Referenced by: '<S40>/Proportional Gain'
   */
  0.6F,

  /* Variable: kp_v
   * Referenced by: '<S89>/Proportional Gain'
   */
  0.6F,

  /* Variable: period_max
   * Referenced by:
   *   '<S1>/Saturation'
   *   '<S2>/Saturation'
   */
  27200.0F,

  /* Variable: v_in
   * Referenced by:
   *   '<S1>/Saturation'
   *   '<S2>/Saturation'
   */
  5000.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
