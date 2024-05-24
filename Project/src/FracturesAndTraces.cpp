#include "FracturesAndTraces.hpp"
#include "ImportExport.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
using namespace Eigen;
using namespace DiscreteAndFractureNetworkLibrary;


bool checkFractures(const vector<DFN>& fractures, double defaultTolerance)
{
    // Implementazione del test delle fratture
    // Controllo del numero di vertici e della distanza tra i vertici
    for (const auto& fracture : fractures)
    {
        if (fracture.VerticesOfFractures.size() < 3)
        {
            cerr << "ERROR: Fracture with ID " << fracture.FractureId << " has less than 3 vertices!" << endl;
            return false;
        }

        for (size_t i = 1; i < fracture.VerticesOfFractures.size(); ++i)
        {
            const Vector3d& currentVertex = fracture.VerticesOfFractures[i];
            const Vector3d& previousVertex = fracture.VerticesOfFractures[i - 1];
            double distance = (currentVertex - previousVertex).norm();
            if (distance < defaultTolerance * defaultTolerance)
            {
                cerr << "ERROR: Distance between vertices of fracture " << fracture.FractureId << " is greater than the default tolerance!" << endl;
                return false;
            }
        }
    }
}
