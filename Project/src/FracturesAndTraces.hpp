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
    map<unsigned int, MatrixXd> VerticesOfFractures = {};               // Matrice contenente i vertici
    double defaultTolerance = numeric_limits<double>::epsilon();        // Epsilon di macchina, in questo caso e' la tolleranza di default
    double toleranceArea = (1./2)*pow(defaultTolerance, 2);             // Tolleranza di default applicata all'area

    // Definizione delle TRACCE
    unsigned int NumberOfTraces = 0;                                    // Numero delle tracce identificate
    unsigned int TraceId = 0;                                           // Identificatori delle tracce
    map<unsigned int, array<unsigned int, 2>> FractureIds;              // Array: dimensione fissata
    map<unsigned int, Matrix<double, 3, 2>> VerticesOfTraces = {};      // Coordinate 3D dei 2 vertici che identificano la traccia (punto di inizio e punto di fine)

    // Definizione delle tracce PASSANTI e NON-PASSANTI
    map<unsigned int, bool> Tips;
    vector<list<unsigned int>> PassingTraces = {};                      // Vettore che contiene una lista contenente le tracce Passanti (ordinate per lunghezza)
    vector<list<unsigned int>> NonPassingTraces = {};                   // Vettore che contiene una lista contenente le tracce NON Passanti (ordinate per lunghezza)
    vector<double> Length = {};                                         // Vettore che contiene la lunghezza tracce
};


// IMPORT SPOSTATO IN IMPORT AND EXPORT
// bool importListFracture(const string& filename, DFN& fracture);

// ANCORA DA SISTEMARE

// bool areClose(unsigned int FractureId1, unsigned int FractureId2);

// void outputFile(Traces& TR, Fractures& FR);

// double distanceSquared(Fractures& mesh, array<double,3> P1, array<double,3> P2);

}
