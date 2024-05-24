#include "ImportExport.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

namespace DiscreteAndFractureNetworkLibrary
{

bool importListFractures(const string& inputFilePath, vector<DFN>& fractures)
{
    ifstream file(inputFilePath);
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "ATTENTION: Input File open failed!" << endl;
        return false;
    }

    string header;
    getline(file, header);              // Lettura di "# Number of Fractures"

    string line;
    getline(file, line);

    istringstream iss(line);
    int NumberOfFractures;
    if (!(iss >> NumberOfFractures))
    {
        cerr << "Error: Failed to convert string to integer!" << endl;
        return false;
    }

    for (int i = 0; i < NumberOfFractures; ++i)
    {
        DFN fracture;
        getline(file, line);            // Lettura di "# FractureId; NumVertices"
        stringstream converter(line);
        char del = ';';
        int FractureId, NumVertices;
        converter >> del >> FractureId >> del >> NumVertices;
        fracture.FractureId = FractureId;
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


void printFractures(const vector<DFN>& fractures, ostream& outputFile)
{
    outputFile << "Fractures Information:" << endl;
    for (const auto& fracture : fractures)
    {
        outputFile << "Fracture ID: " << fracture.FractureId << endl;
        outputFile << "Number of Vertices: " << fracture.VerticesOfFractures.size() << endl;
        outputFile << "Vertices:" << endl;
        for (const auto& vertex : fracture.VerticesOfFractures)
        {
            outputFile << "  ";
            for (size_t i = 0; i < vertex.size(); ++i)
            {
                outputFile << vertex[i];
                if (i != vertex.size() - 1)
                {
                    outputFile << ", ";
                }
            }
            outputFile << "  " << endl;
        }
    }
}

}


