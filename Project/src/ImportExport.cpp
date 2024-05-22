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
    getline(file, line);                    // Lettura di "# Number of Fractures"

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

    // unsigned int NumberOfFractures = stoi(line);

    // vector<structOfFractures> fractures;
    // char pv;

    // while (NumberOfFractures--)
    // {
    //     structOfFractures fracture;
    //     getline(file, line); // Leggi e scarta la riga "# FractureId; NumVertices"
    //     getline(file, line); // Leggi la riga con l'ID e il numero di vertici
    //     stringstream ss(line);
    //     ss >> fracture.FractureId >> pv >> fracture.NumVertices;

    //     fracture.Vertices.size(3, fracture.NumVertices);

    //     // Leggi i vertici
    //     for (unsigned int i = 0; i < fracture.NumVertices; ++i) {
    //         for (unsigned int j = 0; j < 3; ++j) {
    //             file >> fracture.Vertices(j, i);
    //         }
    //     }

    //     fractures.push_back(fracture);
    // }

    file.close();
    return true;
}


}