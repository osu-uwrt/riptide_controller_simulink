/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Porportional_Follower_Test.c
 *
 * Code generated for Simulink model 'Porportional_Follower_Test'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Mar 27 12:18:47 2023
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Porportional_Follower_Test.h"
#include "rtwtypes.h"
#include "Porportional_Follower_Test_private.h"

/* Block signals (default storage) */
B_Porportional_Follower_Test_T Porportional_Follower_Test_B;

/* Block states (default storage) */
DW_Porportional_Follower_Test_T Porportional_Follower_Test_DW;

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
  real_T rtb_Subtract_f;

  /* Outputs for Atomic SubSystem: '<Root>/Porportional_Follower_Test' */
  /* Clock: '<S2>/Clock' */
  Porportional_Follower_Test_B.Clock = Porportional_Follower_Test_M->Timing.t[0];

  /* Sum: '<S2>/Subtract' incorporates:
   *  Memory: '<S2>/Memory2'
   */
  rtb_Subtract_f = Porportional_Follower_Test_B.Clock -
    Porportional_Follower_Test_DW.Memory2_PreviousInput;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/P'
   *  Inport: '<Root>/Signal'
   *  Memory: '<S1>/Previous Velocity'
   *  Product: '<S1>/Acceleration'
   *  Product: '<S1>/Delta Velocity'
   *  Sum: '<S1>/Subtract'
   */
  Porportional_Follower_Test_B.Add = (Porportional_Follower_Test_U.Signal -
    Porportional_Follower_Test_DW.PreviousSignalValue_PreviousInp) * 3.0 *
    rtb_Subtract_f +
    Porportional_Follower_Test_DW.PreviousVelocity_PreviousInput;

  /* Sum: '<S1>/Add1' incorporates:
   *  Product: '<S1>/Delta Position'
   */
  Porportional_Follower_Test_B.Add1 = rtb_Subtract_f *
    Porportional_Follower_Test_B.Add +
    Porportional_Follower_Test_DW.PreviousSignalValue_PreviousInp;

  /* End of Outputs for SubSystem: '<Root>/Porportional_Follower_Test' */

  /* Outport: '<Root>/Follower' */
  Porportional_Follower_Test_Y.Follower = Porportional_Follower_Test_B.Add1;

  /* Update for Atomic SubSystem: '<Root>/Porportional_Follower_Test' */
  /* Update for Memory: '<S1>/Previous Signal Value' */
  Porportional_Follower_Test_DW.PreviousSignalValue_PreviousInp =
    Porportional_Follower_Test_B.Add1;

  /* Update for Memory: '<S2>/Memory2' */
  Porportional_Follower_Test_DW.Memory2_PreviousInput =
    Porportional_Follower_Test_B.Clock;

  /* Update for Memory: '<S1>/Previous Velocity' */
  Porportional_Follower_Test_DW.PreviousVelocity_PreviousInput =
    Porportional_Follower_Test_B.Add;

  /* End of Update for SubSystem: '<Root>/Porportional_Follower_Test' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Porportional_Follower_Test_M->Timing.t[0] =
    ((time_T)(++Porportional_Follower_Test_M->Timing.clockTick0)) *
    Porportional_Follower_Test_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Porportional_Follower_Test_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Porportional_Follower_Test_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Porportional_Follower_Test_M->solverInfo,
                          &Porportional_Follower_Test_M->Timing.simTimeStep);
    rtsiSetTPtr(&Porportional_Follower_Test_M->solverInfo, &rtmGetTPtr
                (Porportional_Follower_Test_M));
    rtsiSetStepSizePtr(&Porportional_Follower_Test_M->solverInfo,
                       &Porportional_Follower_Test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Porportional_Follower_Test_M->solverInfo,
                          (&rtmGetErrorStatus(Porportional_Follower_Test_M)));
    rtsiSetRTModelPtr(&Porportional_Follower_Test_M->solverInfo,
                      Porportional_Follower_Test_M);
  }

  rtsiSetSimTimeStep(&Porportional_Follower_Test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Porportional_Follower_Test_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(Porportional_Follower_Test_M,
             &Porportional_Follower_Test_M->Timing.tArray[0]);
  Porportional_Follower_Test_M->Timing.stepSize0 = 0.1;
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
