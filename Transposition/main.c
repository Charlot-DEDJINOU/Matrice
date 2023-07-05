#include<stdio.h>
void main()
{
    int i,j,n,p;
        scanf("%d %d",&n,&p);
    int matrice[p][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<p; j++)
          scanf("%d",&matrice[j][i]);
    }
    printf("\n");
    for(i=0; i<p; i++)
    {
        for(j=0; j<n; j++)
                printf("  %d",matrice[i][j]);
    printf("\n");
    }
}
