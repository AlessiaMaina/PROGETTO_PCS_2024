#include <vector>
#include <iostream>
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
