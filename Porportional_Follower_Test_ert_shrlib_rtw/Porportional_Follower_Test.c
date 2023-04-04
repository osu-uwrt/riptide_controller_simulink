/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Porportional_Follower_Test.c
 *
 * Code generated for Simulink model 'Porportional_Follower_Test'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr  3 12:52:26 2023
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Porportional_Follower_Test.h"

/* External inputs (root inport signals with default storage) */
ExtU_Porportional_Follower_Te_T Porportional_Follower_Test_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Porportional_Follower_Te_T Porportional_Follower_Test_Y;

/* Real-time model */
static RT_MODEL_Porportional_Followe_T Porportional_Follower_Test_M_;
RT_MODEL_Porportional_Followe_T *const Porportional_Follower_Test_M =
  &Porportional_Follower_Test_M_;

/* Model step function */
void Porportional_Follower_Test_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Porportional_Follower_Test' */
  /* Outport: '<Root>/Follower' incorporates:
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/Signal'
   */
  Porportional_Follower_Test_Y.Follower = 5.0 *
    Porportional_Follower_Test_U.Signal;

  /* End of Outputs for SubSystem: '<Root>/Porportional_Follower_Test' */
}

/* Model initialize function */
void Porportional_Follower_Test_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Porportional_Follower_Test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
