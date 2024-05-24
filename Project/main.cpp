#include <vector>
#include <iostream>
#include <string>
#include <Eigen/Eigen>
#include "FracturesAndTraces.hpp"
#include "ImportExport.hpp"

using namespace std;
using namespace DiscreteAndFractureNetworkLibrary;

int main()
{
    vector<DFN> fractures;
    DFN fracture;

    string filepath = "./FR3_data.txt";

    if (!importListFractures(filepath, fracture))
    {
        cout << "ATTENTION: Error reading the fracture file!" << endl;
        return 1;
    }

    // Output
    cout << "Fracture ID: " << fracture.FractureId << endl;
    //cout << "Number of Vertices: " << fracture.NumVertices.cols() << endl;
    cout << "Vertices:\n" << fracture.NumVertices << endl;

    // Aggiungere la frattura al vettore di fratture
    fractures.push_back(fracture);

    // Chiamata alla funzione per stampare le informazioni sulle fratture
    printFractures(fractures, cout);

    return 0;
}
