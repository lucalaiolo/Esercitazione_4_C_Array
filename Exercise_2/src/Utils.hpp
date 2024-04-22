#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// ImportData reads the input data
// inputFilePath: path name of the input file
// n: size of vectors w and r
// w: array such that w[i] represents the fraction of S invested in i-th asset
// r: array such that r[i] represents the rate of return of the i-th asset
// returns the result of the reading, true is success, false is error
bool importData(const string& inputFilePath,
                size_t& n,
                double& S,
                double*& w,
                double*& r);

// finalValue computes the final value of the whole portfolio
// n: size of vectors w and r
// w: array such that w[i] represents the fraction of S invested in i-th asset
// r: array such that r[i] represents the rate of return of the i-th asset
double finalValue(const size_t&n,
                  const double& S,
                  const double* const& w,
                  const double* const& r);


// exportResult exports the results to an output file
// outputFilePath: path name of the output file
// n: size of vectors w and r
// w: array such that w[i] represents the fraction of S invested in i-th asset
// r: array such that r[i] represents the rate of return of the i-th asset
// finalValue: the final value of the whole portfolio
// returns the result of the export, true is success, false is error
bool exportResult(const string& outputFilePath,
                  const size_t& n,
                  const double& S,
                  const double* const& w,
                  const double* const& r,
                  const double& finalValue);


// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string arrayToString(const size_t& n,
                     const double* const& v);
