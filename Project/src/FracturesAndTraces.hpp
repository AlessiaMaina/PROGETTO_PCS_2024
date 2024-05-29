#pragma once
#include <iostream>
#include <Eigen/Eigen>
#include <vector>
#include <array>

using namespace std;
using namespace Eigen;

namespace DiscreteAndFractureNetworkLibrary
{

struct DFN
{
    // Definizione delle FRATTURE
    unsigned int NumberOfFractures = 0;                                 // Numero delle fratture identificate
    unsigned int FractureId = 0;                                        // Identificatori delle fratture
    unsigned int NumVertices = 0;                                       // Numero dei vertici
    vector <Vector3d> VerticesOfFractures = {};                         // Vettore contenente le coordinate dei vertici della frattura
    double defaultTolerance = numeric_limits<double>::epsilon();        // Epsilon di macchina, in questo caso e' la tolleranza di default

    // Definizione delle TRACCE
    unsigned int NumberOfTraces = 0;                                    // Numero delle tracce identificate
    unsigned int TraceId = 0;                                           // Identificatori delle tracce
    map<unsigned int, array<unsigned int, 2>> FractureIds;              // Array: dimensione fissata
    map<unsigned int, Matrix<double, 3, 2>> VerticesOfTraces = {};      // Coordinate 3D dei 2 vertici che identificano la traccia (punto di inizio e punto di fine)

    // Definizione delle tracce PASSANTI e NON-PASSANTI
    map<unsigned int, bool> Tips;
    vector<list<unsigned int>> PassingTraces = {};                      // Vettore che contiene una lista contenente le tracce Passanti (ordinate per lunghezza)
    vector<list<unsigned int>> NOPassingTraces = {};                    // Vettore che contiene una lista contenente le tracce NON Passanti (ordinate per lunghezza)
    vector<double> Length = {};                                         // Vettore che contiene la lunghezza tracce
};

bool testFractures(double defaultTolerance);

void computationOfTraces(vector<DFN>& fractures, DFN& fracture);
bool testTraces(double defaultTolerance);



}
