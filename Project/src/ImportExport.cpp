#include <FracturesAndTraces.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
using namespace Eigen;


namespace DiscreteAndFractureNetworkLibrary
{

bool importListFractures(const string& inputFilePath, DFN& fracture)
{
    ifstream file(inputFilePath);
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "ATTENTION: Input File open failed!" << endl;
        return false;
    }

    string line;
    getline(file, line);                     // Lettura di "# Number of Fractures"

    int NumberOfFractures = stoi(line);

    for (int i = 0; i < NumberOfFractures; ++i)
    {
        istringstream converter(line);
        getline(file, line);
        int FractureId, NumVertices;
        char del = ';';
        converter >> del >> FractureId >> del >> NumVertices;

        fracture.FractureId = FractureId;

        vector<DFN> fractures;
        vector<vector<double>> Vertices(3, vector<double>(NumVertices));

        getline(file, line);
        for (int j = 0; j < NumVertices; ++j)
        {
            getline(file, line);
            stringstream ss(line);
            for (int k = 0; k < 3; ++k)
            {
                ss >> Vertices[k][j];
                ss.ignore();
            }
        }
        fractures.push_back(fracture);
    }


    file.close();
    return true;
}


}
