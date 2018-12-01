# PID Implementation using GoogleMock
[![Build Status](https://travis-ci.org/krawal19/PIDcontroller.svg?branch=master)](https://travis-ci.org/krawal19/PIDcontroller)  [![Coverage Status](https://coveralls.io/repos/github/krawal19/PIDcontroller/badge.svg?branch=master)](https://coveralls.io/github/krawal19/PIDcontroller?branch=master) [![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---
## Author
Kapil Rawal [GitHub](https://github.com/krawal19).

## Overview
Changes made to basic PID Implementation to incorporate googlemock framework with:
- cmake
- googletest
- googlemock
- Travis CL
- Coveralls

## Changes made for adding GoogleMock
- A virtual class named Parameters is implemented. This class will get the Parameters for the PID class.
- The Parameters class is consumed inside the PID class to get the values of gains kP, kD, kI.
- get and set functions were removed from the main code and there functionality was added to another class named Parameters.
- A mock class is made to test the Parameters class, the method to be mocked is given in MOCK_METHOD() format.
- Test which include googlemock are PIDTest:Test and PIDTest:adjustvalue,  the first test checks if the function Parameters is called at least once in the PID class and the second test checks the computePID by checking if the values are passed to get Parameters.
- Return values are already specified in the getparameters class.

## Installation
To install GoogleMock run the command given below in the terminal.
```
$  sudo apt-get install -y google-mock
```

## Standard install via command-line
```
$ git clone -b GMock_Extra_Credit_Kapil https://github.com/krawal19/PIDcontroller.git
$ cd <path to repository>
$ mkdir build
$ cd build
$ cmake ..
$ make
```
## To run the Test
After building the project.
```
$ cd <path to repository>/build
$ ./test/cpp-test
```
Output observed is shown below:
```
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from PIDTest
[ RUN      ] PIDTest.Test
[       OK ] PIDTest.Test (1 ms)
[ RUN      ] PIDTest.adjustvalue
[       OK ] PIDTest.adjustvalue (0 ms)
[----------] 2 tests from PIDTest (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.
```

## To run the program
Follow the below command to run the program
```
$ cd <path to repository>/build
$ ./app/PID-app
```
## Run cpplint
Run the below command in main workspace:
```
$ cpplint $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )
```

## Run cppcheck
Run the below command in main workspace:
```
$ cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```
