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


bool testFractures(const vector<DFN>& fractures, double defaultTolerance)
{
    // Implementazione del test delle fratture
    // Controllo del numero di vertici e della distanza tra i vertici
    for (const auto& fracture : fractures)
    {
        // TEST 1 FRATTURE: i vertici NON devono essere inferiori a 3, altrimenti la frattura NON esiste
        if (fracture.VerticesOfFractures.size() < 3)
        {
            cerr << "ATTENTION: Fracture with ID " << fracture.FractureId << " has less than 3 vertices. This is impossible!" << endl;
            return false;
        }

        // TEST 2 FRATTURE: i lati delle fratture NON devono avere lunghezza nulla
        for (size_t i = 0; i < fracture.VerticesOfFractures.size() - 1; ++i)
        {
            // Si opta per eliminare la radice quadrata, in quanto è molto costosa in termini computazionali
            const Vector3d& standardVert = fracture.VerticesOfFractures[i];
            const Vector3d& previousVert = fracture.VerticesOfFractures[i - 1];
            Vector3d singleEdge = previousVert - standardVert;

            // Calcolo della distanza euclidea al quadrato (squared) tra 2 vertici
            double distanceSquared = singleEdge[0]*singleEdge[0] + singleEdge[1]*singleEdge[1] + singleEdge[2]*singleEdge[2];

            // Confronto della distanza al quadrato con la tolleranza per ogni edge, quindi risulta essere tolleranza*tolleranza
            if (distanceSquared < defaultTolerance * defaultTolerance)
            {
                cerr << "ATTENTION: Fracture has sides of zero lenght. This is impossible!" << endl;
                return false;
            }
        }
    }
}


void computationOfTraces(vector<DFN>& fractures, DFN& fracture)
{
    unsigned int traceId = 1;
    for (size_t i = 0; i < fractures.size(); ++i)
    {
        for (size_t j = i + 1; j < fractures.size(); ++j)
        {
            const DFN& fracture1 = fractures[i];
            const DFN& fracture2 = fractures[j];
            for (const Vector3d& vec1 : fracture1.VerticesOfFractures)
            {
                for (const Vector3d& vec2 : fracture2.VerticesOfFractures)
                {
                    if ((vec1 - vec2).norm() < fracture.defaultTolerance)
                    {
                        fracture.FractureIds[traceId] = {fracture1.FractureId, fracture2.FractureId};
                        fracture.VerticesOfTraces[traceId] << vec1, vec2;
                        traceId++;
                    }
                }
            }
        }
    }
    fracture.NumberOfTraces = traceId - 1;   // Indica il numero effettivo di tracce trovate
}


bool testTraces()
{

}


