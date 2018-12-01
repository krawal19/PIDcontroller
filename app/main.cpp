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
 *  @file    main.cpp
 *
 *  @author  Kapil Rawal
 *
 *  @copyright BSD License
 *
 *  @brief   PID controller main file
 *
 *  @section DESCRIPTION
 *
 *  This programs implements PID controller
 */

#include <iostream>
#include "PID.h"
#include "Parameters.h"

using std::cin;
using std::cout;
using std::endl;

int main() {  
  /// Paramter object
  Parameters param;
  
  /// velocity control
  PID pidVel(&param);

  float fVal, iVal;
  /// input Target setpoint velocity
  cout << "enter the Target setpoint velocity" << endl;
  cin >> fVal;

  /// input actual velocity
  cout << "enter the actual velocity" << endl;
  cin >> iVal;
  
  /// Computing the PID
  float inc = pidVel.computePID(fVal, iVal);
  cout << " Output : " << inc << endl;

  return 0;
}
