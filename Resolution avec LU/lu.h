#ifndef LU_H_INCLUDED
#define LU_H_INCLUDED

#include "matrice.h"
class LU_decomp
{
public:

    LU_decomp(int taille);
    ~LU_decomp();

    int N=4 ;
    Matrix *U;
    Matrix *L;
    Matrix *y;
    Matrix *x;
    Matrix *mk;

    void find_decomposition(Matrix &A);
    void forward_substitution(Matrix &b);
    void backward_substitution();
    int multiply (Matrix *m1, Matrix *m2, Matrix *y);
};


#endif // LU_H_INCLUDED
