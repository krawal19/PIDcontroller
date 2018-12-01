/**
 *
 * BSD 3-Clause License
 * Copyright (c) 2018, Kapil Rawal.
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  @copyright (c) BSD
 *
 *  @file    PID.h
 *
 *  @author  Kapil Rawal
 *
 *  @copyright BSD License
 *
 *  @brief   PID controller header file
 *
 *  @section DESCRIPTION
 *
 *  Definition and implementation of the PID class
 */


#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

#include <iostream>
#include "Parameters.h"
/**
 * @brief Implementation of PID controller
 */
class PID {

 private:

  Parameters* parameter;
  /**
   * @brief kp proportional gain
   */
  float kP;

  /**
   * @brief kd derivative gain
   */
  float kD;

  /**
   * @brief ki interal gain
   */
  float kI;

  /**
   * @brief dT time constant
   */
  float dT;

  /**
   * @brief previous error term
   */
  float prevErr;

 
public:
  
  /**
   *  @brief   Constructor
   */
  explicit PID(Parameters* param) : parameter(param){
    dT=1.5;
   prevErr=0;
   iterr= 0;
    kP = 0.0;
    kD = 0.0;
    kI = 0.0; 
}
  float iterr;

  /**
   * @brief default destructor
   */
  ~PID();


  /**
   * @brief sets the kD gain value according to the passed value
   * 
   * @param setpoint velocity
   * 
   * @param current velocity
   * 
   * @return float value of computed PID
   */
   float computePID(float, float);
 
  /**
   * @brief gets the parameters kP, kD, kI
   */
   void getParameters();
};


#endif // INCLUDE_PID_H_ 
