#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include "irreductible.h"

using namespace std;

class Matrix
{
public:

    Matrix(int M, int N,string c_name,int c_type);
    ~Matrix();

    double **mat;
    int rows;
    int cols;
    string name;
    int type;
    const static int as_matrix=1;
    const static int as_vector=2;

    void draw();
    void full();
};

#endif // MATRICE_H_INCLUDED
