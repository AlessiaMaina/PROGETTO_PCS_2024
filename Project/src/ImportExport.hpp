#pragma once
#include <FracturesAndTraces.hpp>
#include <iostream>
#include <Eigen/Eigen>
#include <vector>
#include <array>
#include <string>

using namespace std;
using namespace Eigen;
using namespace DiscreteAndFractureNetworkLibrary;


bool importListFractures(const string& inputFilePath, DFN& fracture);
void printFractures();
void printTraces();



