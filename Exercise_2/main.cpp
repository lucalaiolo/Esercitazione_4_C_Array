#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;
int main()
{
    const string inputFileName = "data.csv";
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double S = 0;
    double V;
    if(!importData(inputFileName, n, S, w, r)) {
        cerr << "Something went wrong with the import." << endl;
        return -1;
    }
    cout << "Import was successful." << endl;
    cout << "S: " << S << ", n: " << n << endl;
    cout << "w: " << arrayToString(n,w) << endl;
    cout << "r: " << arrayToString(n,r) << endl;

    V = finalValue(n,S,w,r);

    const string outputFileName = "result.txt";
    if(!exportResult(outputFileName,n,S,w,r,V)) {
        cerr << "Something went wrong with the export." << endl;
        return -1;
    } else {
        cout << "Export successful." << endl;
    };

    delete [] w;
    delete [] r;

  return 0;
}

