/**
 *
 * BSD 3-Clause License
 * Copyright (c) 2018, Kapil Rawal
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
 *  @file    Parameters.h
 *
 *  @author  Kapil Rawal
 *
 *  @copyright BSD License
 *
 *  @brief   header file for parameters class
 *
 *  @section DESCRIPTION
 *
 *  This file contains decleration of class parameters
 */

#ifndef INCLUDE_PARAMETERS_H_
#define INCLUDE_PARAMETERS_H_

#include <iostream>


class Parameters{

public:
       

  /**
   *  @brief   Constructor
   */
   Parameters();

  /**
   *  @brief   Destroys the object
   */ 
   virtual ~Parameters(); 

 /**
   *  @brief  Proportional gain of PID controller
   *
   *  
   *  @return value of KP
   */
  virtual double getKP();

 /**
   *  @brief  Differential gain of PID controller
   *
   *  
   *  @return value of KD        
   */
   virtual double getKD();

 /**
   *  @brief  Intergral gain of PID controller
   *
   *  
   *  @return value of KI        
   */
   virtual double getKI();
};

#endif // INCLUDE_PARAMETERS_H_
