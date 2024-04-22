#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;


bool importData(const string& inputFilePath,
                size_t& n,
                double& S,
                double*& w,
                double*& r)
{
    // open file
    ifstream file;
    file.open(inputFilePath);

    if(file.fail()) {
        return false;
    }

    string line;

    // we now read the value of S
    getline(file,line, ';'); // the char "S" is read
    getline(file, line); // line now contains the value of S
    istringstream convertS;
    convertS.str(line);
    convertS >> S;

    // we now read the value of n
    getline(file,line, ';'); // the char "n" is read
    getline(file, line); // line now contains the value of n
    istringstream convertN;
    convertN.str(line);
    convertN >> n;

    getline(file,line); // we skip the third line

    w = new double[n];
    r = new double[n];

    for(unsigned int i=0; i<n; i++) {
        getline(file,line,';');
        istringstream convertW;
        convertW.str(line);
        convertW >> w[i];

        getline(file,line);
        istringstream convertR;
        convertR.str(line);
        convertR >> r[i];
    }

    return true;

}

double finalValue(const size_t &n, const double &S, const double * const &w, const double * const &r) {
    double V = 0;
    for(unsigned int i=0; i<n; i++) {
        V += (1+r[i])*w[i]*S;
    }
    return V;
}

string arrayToString(const size_t &n, const double * const &v) {
    ostringstream toString;
    toString << "[ ";
    for(unsigned int i=0; i<n; i++)
        toString << v[i] << " ";
    toString << "]";
    return toString.str();
}

bool exportResult(const string &outputFilePath, const size_t &n,const double &S, const double * const &w, const double * const &r, const double &finalValue) {
    ofstream file;
    file.open(outputFilePath);

    if(file.fail()) {
        return false;
    }

    file << fixed << showpoint << setprecision(2) << "S = " << S << ", n = " << n << endl;
    file << "w = " << arrayToString(n,w) << endl;
    file << "r = " << arrayToString(n,r) << endl;
    double rate_of_return = (finalValue/S)-1;
    file << fixed << showpoint << setprecision(4) <<  "Rate of return of the portfolio: " << rate_of_return << endl;
    file << fixed << showpoint << setprecision(2) << "V: " << finalValue << endl;

    return true;
}



