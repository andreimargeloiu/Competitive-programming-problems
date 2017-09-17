# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 105
using namespace std;
ifstream f("piete.in");
ofstream g("piete.out");
int i,j,n,m,S,q,k,pret,dif,VV,maxx,maxim,final;
int p[NR][NR], G[NR];
int main ()
{
    f>>n>>m>>S>>final;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            f>>p[i][j];
    while (S<final)
    {
        maxim=0;
        for (i=1; i<=n; ++i)// a
            for (j=1; j<=n; ++j) // b
            {
                if (i==j) continue;
                memset(G, 0, sizeof(G)); maxx=0;
                for (k=1; k<=m; ++k) //fiecare produs
                {
                    if (p[i][k]<p[j][k] && p[i][k]<=S) //daca pot face un profit
                    {
                        dif=p[j][k]-p[i][k]; pret=p[i][k];
                        for (q=S-pret; q>=1; --q)
                            if (G[q] && G[q]+dif>G[q+pret]) G[q+pret]=G[q]+dif;
                        G[pret]=max(G[pret], dif);
                    }
                }
                //caut profitul maxim
                for (q=1; q<=S; ++q)
                    maxx=max(maxx, G[q]);
                maxim=max(maxim, maxx);
            }
        if (maxim==0)
        {
            g<<"-1\n";
            return 0;
        }
        S+=maxim; ++VV;
    }
    g<<VV<<"\n";

    return 0;
}
