#include "ImportExport.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

namespace DiscreteAndFractureNetworkLibrary
{

bool importListFractures(const string& inputFilePath, DFN& fracture)
{
    ifstream file(inputFilePath);

    if (!file.is_open()) {
        cerr << "ATTENTION: Input File open failed!" << endl;
        return false;
    }

    string header;
    getline(file, header);                      // Lettura della riga header, ovvero "# Number of Fractures"

    string line;
    getline(file, line);
    //int NumberOfFractures = stoi(line);

    istringstream iss(line);
    int NumberOfFractures;
    if (!(iss >> NumberOfFractures))
    {
        cerr << "ERROR: impossible convert string into integer!" << endl;
        return false;
    }

    for (int i = 0; i < NumberOfFractures; ++i)
    {
        getline(file, line);                    // Lettura della riga "# FractureId; NumVertices"
        stringstream converter(line);
        char del;
        int FractureId, NumVertices;
        converter >> del >> FractureId >> del >> NumVertices;

        fracture.FractureId = FractureId;

        vector<DFN> fractures;
        vector<vector<double>> Vertices(3, vector<double>(NumVertices));

        getline(file, line);
        for (int j = 0; j < NumVertices; ++j)
        {
            getline(file, line);
            stringstream ss(line);
            for (int k = 0; k < 3; ++k) {
                ss >> Vertices[k][j];
                ss.ignore();
            }
        }
        fractures.push_back(fracture);
    }

    file.close();
    return true;
}


void printFractures(const vector<DFN>& fractures, ostream& output)
{
    output << "Fractures Information:" << endl;
    for (const auto& fracture : fractures)
    {
        output << "Fracture ID: " << fracture.FractureId << endl;
        output << "Number of Vertices: " << fracture.VerticesOfFractures.size() << endl;
        output << "Vertices:" << endl;
        for (const auto& vertex : fracture.VerticesOfFractures)
        {
            output << "    (";
            for (size_t i = 0; i < vertex.size(); ++i)
            {
                output << vertex[i];
                if (i != vertex.size() - 1)
                {
                    output << ", ";
                }
            }
            output << ")" << endl;
        }
    }
}


}

