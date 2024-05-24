#include <vector>
<<<<<<< HEAD
#include <iostream>
=======
#include <string>
#include <Eigen/Eigen>
>>>>>>> 506ab04155fa68449e9942548ea9ebad59b34af8
#include "FracturesAndTraces.hpp"
#include "ImportExport.hpp"

using namespace DiscreteAndFractureNetworkLibrary;
using namespace std;

int main() {
    vector<DFN> fractures;
    DFN fracture;

    string filepath = "./FR3_data.txt";

    if (!importListFractures(filepath, fracture)) {
        cout << "Errore nella lettura del file di fratture." << endl;
        return 1;
    }

    // Output per scopi di test
    cout << "Fracture ID: " << fracture.FractureId << endl;
    //cout << "Number of Vertices: " << fracture.NumVertices.cols() << endl;
    cout << "Vertices:\n" << fracture.NumVertices << endl;

    return 0;
}
