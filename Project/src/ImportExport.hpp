#pragma once

#include <FracturesAndTraces.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <array>
<<<<<<< HEAD
#include <string>

using namespace std;
using namespace Eigen;
using namespace DiscreteAndFractureNetworkLibrary;


bool importListFractures(const string& inputFilePath, DFN& fracture);
void printFractures();
void printTraces();



=======
#include <vector>
#include <algorithm>
#include <string>

namespace DiscreteAndFractureNetworkLibrary
{
bool importListFractures(const std::string& inputFilePath, DFN& fracture);
}
>>>>>>> 97dc8a319b0f0a593e154e3be4be48de265f4cb4
