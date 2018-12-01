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
 *  @file    testPID.cpp
 *
 *  @author  Kapil Rawal
 *
 *  @copyright BSD License
 *
 *  @brief   Unit test
 *
 *  @section DESCRIPTION
 *
 *  This programs implements Unit test to test PID class by mocking 
 *  Parameters class
 */


#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <iostream>
#include <memory>
#include "PID.h"
#include "Parameters.h"
using ::testing::Return;
using ::testing::AtLeast;
/**
 * @brief Mock of class Parameters
 */
class MockParameters : public Parameters {
 public:
  MOCK_METHOD0(getKP, double());
  MOCK_METHOD0(getKD, double());
  MOCK_METHOD0(getKI, double());
};

/**
 * @brief Checking using GMOCK if object methods are called. 
 */
TEST(PIDTest,Test) {
  MockParameters param;
  /// Expect call to KP at least once
  EXPECT_CALL(param, getKP()).Times(AtLeast(1));
  /// Expect call to KD at least once
  EXPECT_CALL(param, getKD()).Times(AtLeast(1));
  /// Expect call to KI at least once
  EXPECT_CALL(param, getKI()).Times(AtLeast(1));
  PID pid(&param);
  pid.computePID(1,2);
}

/**
 * @brief Checking if computePID is working by using GMOCK.
 */
TEST(PIDTest, adjustvalue) {
 MockParameters param;
  /// Calling KP once 
  EXPECT_CALL(param, getKP())  
      .Times(1).WillRepeatedly(Return(2));
  /// Calling KD once
  EXPECT_CALL(param, getKI())  
      .Times(1).WillRepeatedly(Return(1));
  /// Calling KI once
  EXPECT_CALL(param, getKD())  
      .Times(1).WillRepeatedly(Return(0.1));
  PID instPID(&param);
EXPECT_NEAR(-3.5, instPID.computePID(1, 2),0.5);
}
