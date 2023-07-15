#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

const int as_matrix = 1;
const int as_vector = 2;

void draw(double matrice[][MAX_SIZE], int rows, int cols, const char* c_name, int c_type)
{
	int i , j ;
	
    if (c_type == as_matrix)
    {
        printf("\n==================== Matrix %s:====================\n\n", c_name);

        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (matrice[i][j] < 10e-13 && matrice[i][j] > -10e-13)
                    matrice[i][j] = 0;

                printf("%11.3f", matrice[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else if (c_type == as_vector)
    {
        printf("\n=================== Vector %s: ===================\n", c_name);

        for (i = 0; i < rows; i++)
        {
            if (matrice[i][0] < 10e-13 && matrice[i][0] > -10e-13)
                matrice[i][0] = 0;

            printf("%11.3f\n", matrice[i][0]);
        }
        printf("\n");
    }
}

void fullMatrix(double matrice[][MAX_SIZE], int rows, int cols , int c_type)
{
	int i , j ;
	
    if (c_type == as_matrix)
    {
        for (i = 0; i < rows; i++)
        {
            printf("Entrer la ligne %d de la matrice : ", i + 1);
            for (j = 0; j < cols; j++)
                scanf("%lf", &matrice[i][j]);
        }
    }
    else if (c_type == as_vector)
    {
        printf("\nEntrer la matrice B : ") ;
        for (i = 0; i < rows; i++)
                scanf("%lf", &matrice[i][0]);
    }
}

void multiply(double m1[][MAX_SIZE], double m2[][MAX_SIZE], double y[][MAX_SIZE], int size)
{
    double suma;
    int i , j , k ;
    
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            suma = 0;
            for (k = 0; k < size; k++)
                suma += m1[i][k] * m2[k][j];

            y[i][j] = suma;
        }
    }
}

void findDecomposition(double A[][MAX_SIZE], double L[][MAX_SIZE], double U[][MAX_SIZE], int size)
{
	int i , j , i1 ,k , j1;
	
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
                L[i][j] = 1;
            else
                L[i][j] = 0;
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            U[i][j] = A[i][j];
    }

    double mk[MAX_SIZE][MAX_SIZE];
    for (i = 0; i < size; i++)
    {
        for (i1 = 0; i1 < size; i1++)
        {
            for (j1 = 0; j1 < size; j1++)
                mk[i1][j1] = 0;

            mk[i1][i1] = 1;
        }

        for (k = i + 1; k < size; k++)
            mk[k][i] = -U[k][i] / U[i][i];

        multiply(mk, U, U, size);

        for (k = i + 1; k < size; k++)
            mk[k][i] = -mk[k][i];

        multiply(L, mk, L, size);
    }
}

void forwardSubstitution(double L[][MAX_SIZE], double b[][MAX_SIZE], double y[][MAX_SIZE], int size)
{
	int i , j;
    double suma;
    for (i = 0; i < size; i++)
    {
        suma = 0;
        for (j = 0; j < i; j++)
            suma += L[i][j] * y[j][0];

        y[i][0] = (b[i][0] - suma) / L[i][i];
    }
}

void backwardSubstitution(double U[][MAX_SIZE], double y[][MAX_SIZE], double x[][MAX_SIZE], int size)
{
    double suma;
    int i , j ;
    
    for (i = size - 1; i >= 0; i--)
    {
        suma = 0;
        for (j = size - 1; j > i; j--)
            suma += U[i][j] * x[j][0];

        x[i][0] = (y[i][0] - suma) / U[i][i];
    }
}

int main()
{
    printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n");
    printf("\t#                                                                                       #\n");
    printf("\t#                          RESOLUTION D'UN SYSTEME D'EQUATION                           #\n");
    printf("\t#                                                                                       #\n");
    printf("\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n\n");

    int choix = 0 ;
    do
    {
        int size;
        printf("\nEntrez la taille de la matrice : ");
        scanf("%d", &size);

        double A[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], L[MAX_SIZE][MAX_SIZE], U[MAX_SIZE][MAX_SIZE], y[MAX_SIZE][MAX_SIZE], x[MAX_SIZE][MAX_SIZE];

        printf("\n\n=================== Remplissage de la matrice A ====================\n\n");
        fullMatrix(A, size, size , as_matrix);

        printf("\n=================== Remplissage du vecteur B ====================\n");
        fullMatrix(b, size, 1 , as_vector);

        findDecomposition(A, L, U, size);
        forwardSubstitution(L, b, y, size);
        backwardSubstitution(U, y, x, size);

        draw(A, size, size, "A", as_matrix);
        draw(b, size, 1, "b", as_vector);
        draw(L, size, size, "L", as_matrix);
        draw(U, size, size, "U", as_matrix);
        draw(x, size, 1, "x", as_vector);

        printf("\n=============== Voulez vous continuer ? 1-Oui 2-Non : ") ;
        scanf("%d",&choix) ;
    }
    while(choix == 1) ;

    return 0;
}
