#include <stdio.h>
#include <stdlib.h>

void permute(float tab[],int b,int n,int* signe)
{
    int s=1,i,j,tem,k;
    if(tab[b*(n+1)-n-1]==0)
    {
        for(i=b*(n+1); i<n*n; i+=n)
        {
            s+=tab[i-1];
            if(tab[i-1]!=0)
            {
                for(j=n*(b-1)+1,k=0; j<=b*n; k++,j++)
                {
                    tem=tab[j-1];
                    tab[j-1]=tab[i-b+k];
                    tab[i-b+k]=tem;
                }
                i=n*n;
            }
        }
    }
    if(s==1)
    {
        *signe=*signe+0;
    }
    else
    {
        *signe=*signe+1;
    }
}
int det()
{
    int i,j,n,k,m,signe=0 ;
    float a,det=1;
    scanf("%d",&n);
    float tab[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f",&tab[i][j]);
        }
    }
        for(i=0; i<n; i++)
        {
            permute(tab,i+1,n,&signe);
            for(j=i+1; j<n; j++)
            {
                if(tab[j][i]!=0)
                {
                    a=-1*tab[j][i]/tab[i][i];
                    for(k=0; k<n; k++)
                    {
                        tab[j][k]+=a*tab[i][k];
                    }
                }
            }
        }
        for(i=0; i<n; i++)
        {
            det*=tab[i][i];
        }
        if(det==0)
        {
          printf("det=%f",det);
        }
        else if(signe%2==0)
        {
            printf("det=%f",det);
        }
        else
        {
            printf("det=%f",-1*det);
        }
    return 0;
}
int main()
{
  det();
}


