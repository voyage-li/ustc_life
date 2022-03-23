#pragma once
//一些头文件定义
#include <iostream>
#include <fstream>
#include <cstdio>

#include <array>
#include <vector>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>

// Boost library
#include <boost/program_options.hpp>

// Application global variables
extern bool gIsSingleStepMode;
extern bool gIsDetailedMode;
extern std::string gInputFileName;
extern std::string gRegisterStatusFileName;
extern std::string gOutputFileName;
extern int gBeginningAddress;