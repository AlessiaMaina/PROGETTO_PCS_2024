#pragma once
#include <FracturesAndTraces.hpp>
#include <iostream>
#include <Eigen/Eigen>
#include <vector>
#include <array>

using namespace std;
using namespace Eigen;
using namespace DiscreteAndFractureNetworkLibrary;


bool importListFracture(const string& filename, DFN& fracture);
