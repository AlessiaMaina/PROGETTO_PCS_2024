#pragma once

#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;


namespace PolygonalLibrary
{

struct PolygonalMesh
{
    // Definizione delle Celle 0D
    unsigned int NumberOfCell0Ds = 0;
    std::vector<unsigned int> Cell0DIds = {};
    std::vector<Vector2d> CordinatesOfCell0Ds = {};
    std::map<unsigned int, list<unsigned int>> MarkerOfCell0Ds = {};

    // Definizione delle Celle 1D
    unsigned int NumberOfCell1Ds = 0;
    std::vector<unsigned int> Cell1DIds = {};
    std::vector<Vector2i> VerticesOfCell1Ds = {};
    std::map<unsigned int, list<unsigned int>> MarkerOfCell1Ds = {};

    // Definizione delle Celle 2D
    unsigned int NumberOfCell2Ds = 0;
    std::vector<unsigned int> Cell2DIds = {};
    std::vector<vector<unsigned int>> VerticesOfCell2Ds = {};
    std::vector<vector<unsigned int>> EdgesOfCell2Ds = {};
    std::map<unsigned int, list<unsigned int>> MarkerOfCell2Ds = {};
};

}
