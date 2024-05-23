/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: power001_model.c
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
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void power001_model_step(void)
{
  real32_T rtb_FilterCoefficient_f;
  real32_T rtb_Sum_j;
  real32_T u0;
  real32_T u1;
  real32_T u2;

  /* SwitchCase: '<Root>/Switch Case' incorporates:
   *  Inport: '<Root>/state'
   */
  switch ((int32_T)rtU.state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/cv' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Sum: '<S2>/Sum' incorporates:
     *  Inport: '<Root>/v_tgt'
     *  Inport: '<Root>/v_val'
     */
    rtb_Sum_j = rtU.v_tgt - rtU.v_val;

    /* Gain: '<S87>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S79>/Filter'
     *  Gain: '<S78>/Derivative Gain'
     *  Sum: '<S79>/SumD'
     */
    rtb_FilterCoefficient_f = (rtP.kd_v * rtb_Sum_j - rtDW.Filter_DSTATE_m) *
      100.0F;

    /* Sum: '<S93>/Sum' incorporates:
     *  DiscreteIntegrator: '<S84>/Integrator'
     *  Gain: '<S89>/Proportional Gain'
     */
    u0 = (rtP.kp_v * rtb_Sum_j + rtDW.Integrator_DSTATE_n) +
      rtb_FilterCoefficient_f;

    /* Saturate: '<S91>/Saturation' */
    if (u0 > 24480.0F) {
      u0 = 24480.0F;
    } else if (u0 < 0.0F) {
      u0 = 0.0F;
    }

    /* End of Saturate: '<S91>/Saturation' */

    /* Saturate: '<S2>/Saturation' */
    u1 = rtP.period_max * 0.01F;
    u2 = (12000.0F / (rtP.v_in + 12000.0F) + 0.1F) * rtP.period_max;
    if (u0 > u2) {
      /* Outport: '<Root>/v_period_out' */
      rtY.v_period_out = u2;
    } else if (u0 < u1) {
      /* Outport: '<Root>/v_period_out' */
      rtY.v_period_out = u1;
    } else {
      /* Outport: '<Root>/v_period_out' */
      rtY.v_period_out = u0;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Update for DiscreteIntegrator: '<S79>/Filter' */
    rtDW.Filter_DSTATE_m += 0.001F * rtb_FilterCoefficient_f;

    /* Update for DiscreteIntegrator: '<S84>/Integrator' incorporates:
     *  Gain: '<S81>/Integral Gain'
     */
    rtDW.Integrator_DSTATE_n += rtP.ki_v * rtb_Sum_j * 0.001F;

    /* End of Outputs for SubSystem: '<Root>/cv' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<Root>/cc' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Sum: '<S1>/Sum' incorporates:
     *  Inport: '<Root>/i_tgt'
     *  Inport: '<Root>/i_val'
     */
    rtb_Sum_j = rtU.i_tgt - rtU.i_val;

    /* Gain: '<S38>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S30>/Filter'
     *  Gain: '<S29>/Derivative Gain'
     *  Sum: '<S30>/SumD'
     */
    rtb_FilterCoefficient_f = (rtP.kd_i * rtb_Sum_j - rtDW.Filter_DSTATE) *
      100.0F;

    /* Sum: '<S44>/Sum' incorporates:
     *  DiscreteIntegrator: '<S35>/Integrator'
     *  Gain: '<S40>/Proportional Gain'
     */
    u0 = (rtP.kp_i * rtb_Sum_j + rtDW.Integrator_DSTATE) +
      rtb_FilterCoefficient_f;

    /* Saturate: '<S42>/Saturation' */
    if (u0 > 24480.0F) {
      u0 = 24480.0F;
    } else if (u0 < 0.0F) {
      u0 = 0.0F;
    }

    /* End of Saturate: '<S42>/Saturation' */

    /* Saturate: '<S1>/Saturation' */
    u1 = rtP.period_max * 0.01F;
    u2 = (12000.0F / (rtP.v_in + 12000.0F) + 0.1F) * rtP.period_max;
    if (u0 > u2) {
      /* Outport: '<Root>/i_period_out' */
      rtY.i_period_out = u2;
    } else if (u0 < u1) {
      /* Outport: '<Root>/i_period_out' */
      rtY.i_period_out = u1;
    } else {
      /* Outport: '<Root>/i_period_out' */
      rtY.i_period_out = u0;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Update for DiscreteIntegrator: '<S30>/Filter' */
    rtDW.Filter_DSTATE += 0.001F * rtb_FilterCoefficient_f;

    /* Update for DiscreteIntegrator: '<S35>/Integrator' incorporates:
     *  Gain: '<S32>/Integral Gain'
     */
    rtDW.Integrator_DSTATE += rtP.ki_i * rtb_Sum_j * 0.001F;

    /* End of Outputs for SubSystem: '<Root>/cc' */
    break;
  }

  /* End of SwitchCase: '<Root>/Switch Case' */
}

/* Model initialize function */
void power001_model_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
