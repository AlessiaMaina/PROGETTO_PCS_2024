#pragma once

#include <FracturesAndTraces.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <array>
#include <vector>
#include <algorithm>

namespace DiscreteAndFractureNetworkLibrary
{
bool importListFractures(const std::string& inputFilePath, DFN& fracture);
}
