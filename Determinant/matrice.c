int permute(int tab[],int b,int n)
{
    int s,i,j,tem;
    for(i=b*(n+1); i<n*n; i+=n)
    {
        s+=tab[i-1];
        if(tab[i-1]!=0)
        {
            for(j=n(b-1)+1; j<=b*n; j++)
            {
                tem=tab[j-1];
                tab[j-1]=tab[i-b];
                tab[i-b]=tem;
            }
            i=n*n;
        }
    }
    if(s==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
