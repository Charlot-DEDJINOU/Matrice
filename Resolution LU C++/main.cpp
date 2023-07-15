#include <iostream>
#include "matrice.h"
#include "lu.h"
#include "irreductible.h"

using namespace std;

int main()
{

    cout << "\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n";
    cout << "\t#                                                                                         #\n";
    cout << "\t#                          RESOLUTION D'UN SYSTEME D'EQUATION                             #\n";
    cout << "\t#                                                                                         #\n";
    cout << "\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n\n";

    int N ;
    cout<<"Entrez le rang de la matrice A : " ;
    cin>>N ;

    cout<<endl<<"=================== Remplissage de la matrice A ===================="<<endl<<endl;
    Matrix A(N,N,"A",Matrix::as_matrix);
    A.full();

    cout<<endl<<"=================== Remplissage du vector B ===================="<<endl<<endl;
    Matrix b(N,1,"b",Matrix::as_vector);
    b.full();

    LU_decomp lu_decomp(N);

    lu_decomp.find_decomposition(A);
    lu_decomp.forward_substitution(b);
    lu_decomp.backward_substitution();

    A.draw();
    b.draw();
    lu_decomp.L->draw();
    lu_decomp.U->draw();
    lu_decomp.x->draw();

    return 0;
}
