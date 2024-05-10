#include <GeometryLibrary.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
using namespace Eigen;

bool importListFractures(const string& inputFilePath, ...)
{
    ifstream file(inputFilePath);
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "ATTENTION: Input File open failed!" << endl;
        return false;
    }

    string header;
    getline(file, header);          // Skip the 1st line, i.e. "# Number of Fractures"

    string line;
    getline(file, line);

    file.close();
    return true;
}
