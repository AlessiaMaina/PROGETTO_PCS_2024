#pragma once

#include <FracturesAndTraces.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <array>
#include <string>

using namespace std;
using namespace Eigen;
using namespace DiscreteAndFractureNetworkLibrary;


bool importListFractures(const string& inputFilePath, DFN& fracture);
void printFractures(const vector<DFN>& fractures, ostream& outputFile);

bool exportTraces(const string& outputFilePath, const DFN& fracture);
void printTraces();

