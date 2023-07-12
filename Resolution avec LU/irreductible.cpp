#include "irreductible.h"

void Irreductible::forme_irreductible(double nombre)
{
    int dem = 1 ;
    double num = nombre ;

    if(nombre == 0.125)
        std::cout<<nombre ;

    while(static_cast<int>(num) - num != 0)
    {
        dem++ ;
        num += nombre ;
    }

    num = static_cast<int>(num) ;

    if(dem != 1)
        std::cout<<num<<"/"<<dem<<"\t" ;
    else
        std::cout<<num<<"\t" ;
}

