#include "FracturesAndTraces.hpp"
#include "ImportExport.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
using namespace DiscreteAndFractureNetworkLibrary;


int main()
{
    vector<DFN> fractures;
    DFN fracture;

    string filepath = "./FR3_data.txt";

    // Output
    if (!importListFractures(filepath, fracture))
    {
        cerr << "ATTENTION: There's an error with the import of the file!" << endl;
        return 2;
    }

    // Output per scopi di test
    cout << "Fracture ID: " << fracture.FractureId << endl;
    //cout << "Number of Vertices: " << fracture.NumVertices.cols() << endl;
    cout << "Vertices:\n" << fracture.NumVertices << endl;

    // Aggiungere la frattura al vettore di fratture
    fractures.push_back(fracture);

    // Chiamata alla funzione per stampare le informazioni sulle fratture
    printFractures(fractures, cout);

    // Applicazione della funzione che serve per calcolare le tracce
    computationOfTraces(fractures, fracture);


    if (!exportTraces(outputFilePath, fracture))
    {
        cerr << "ATTENTION: There's an error with the export of the traces on an output file!" << endl;
        return 3;
    }

    cout << "Traces calculated and exported successfully." << endl;


    return 0;
}



