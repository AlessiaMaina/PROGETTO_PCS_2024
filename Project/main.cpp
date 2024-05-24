#include <vector>
<<<<<<< HEAD
#include <iostream>
#include <string>
#include <Eigen/Eigen>
=======
<<<<<<< HEAD
#include <iostream>
=======
#include <string>
#include <Eigen/Eigen>
>>>>>>> 506ab04155fa68449e9942548ea9ebad59b34af8
>>>>>>> 97dc8a319b0f0a593e154e3be4be48de265f4cb4
#include "FracturesAndTraces.hpp"
#include "ImportExport.hpp"

using namespace DiscreteAndFractureNetworkLibrary;
using namespace std;
using namespace DiscreteAndFractureNetworkLibrary;

<<<<<<< HEAD
int main()
{
=======
int main() {
>>>>>>> 97dc8a319b0f0a593e154e3be4be48de265f4cb4
    vector<DFN> fractures;
    DFN fracture;

    string filepath = "./FR3_data.txt";

<<<<<<< HEAD
    if (!importListFractures(filepath, fracture))
    {
        cout << "ATTENTION: Error reading the fracture file!" << endl;
        return 1;
    }

    // Output
=======
    if (!importListFractures(filepath, fracture)) {
        cout << "Errore nella lettura del file di fratture." << endl;
        return 1;
    }

    // Output per scopi di test
>>>>>>> 97dc8a319b0f0a593e154e3be4be48de265f4cb4
    cout << "Fracture ID: " << fracture.FractureId << endl;
    //cout << "Number of Vertices: " << fracture.NumVertices.cols() << endl;
    cout << "Vertices:\n" << fracture.NumVertices << endl;

<<<<<<< HEAD
    // Aggiungere la frattura al vettore di fratture
    fractures.push_back(fracture);

    // Chiamata alla funzione per stampare le informazioni sulle fratture
    printFractures(fractures, cout);

=======
>>>>>>> 97dc8a319b0f0a593e154e3be4be48de265f4cb4
    return 0;
}
