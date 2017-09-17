# include <fstream>
# include <algorithm>
# include <cstring>
# include <bitset>
# define MAX 35000
# define NR 1005
using namespace std;
ifstream f("nk.in");
ofstream g("nk.out");
struct elem
{
    int x, ap;
}v[NR][20];
int i,j,n,m,T,k,K,sol,N,unu,maxx;
int prim[MAX], a[NR], L[NR], pot[NR][NR], st[NR];
long long S;
bitset <MAX+5> ap;
void ciur ()
{
    prim[++k]=2;
    for (int i=3; i<=MAX; i+=2)
    {
        if (! ap[i])
        {
            prim[++k]=i;
            for (j=3; i*j<=MAX; j+=2)
                ap[i*j]=1;
        }
    }
}
void back (int k)
{
    if (k==K+1)
    {
        if (S==a[maxx]) ++sol;
    }
    else {
             for (int i=st[k-1]+1; i<=maxx; ++i)
             {// pp ca luam a[i];
                 if (pot[i][maxx]) //daca sunt compatibili
                 {
                     S=S*a[i]; st[k]=i;

                     if (S<=a[maxx]) back (k+1);

                     S=S/a[i]; st[k]=0;
                 }
             }
         }
}
void init ()
{
    memset (a, 0, sizeof(a));
    memset (L, 0, sizeof(L));
    sol=0; unu=0; n=0;
    for (int i=1; i<=N; ++i)
    {
        for (j=1; j<=18; ++j)
            v[i][j].x=v[i][j].ap=0;
    }
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j)
            pot[i][j]=0;
}
int main ()
{
    ciur ();

    f>>T; S=1;
    for (int t=1; t<=T; ++t)
    {
        f>>N>>K; init ();

        for (i=1; i<=N; ++i)
        {
            f>>a[i];
            if (a[i]==0) unu=1;
        }

        if (K==1)
        {
            g<<N<<"\n";
            continue;
        }



        sol=unu;
        sort (a+1, a+N+1);

        for (i=1; i<=N; ++i)
            if (a[i]!=a[i-1]) a[++n]=a[i];


        for (i=1; i<=n; ++i) // descompun in factori primi
        {
            int nr=a[i];
            for (j=1; j<=k && nr!=1; ++j)
                if (nr % prim[j]==0)
                {
                    int w=0;
                    while (nr % prim[j]==0)
                        ++w, nr/=prim[j];

                    v[i][++L[i]].x=prim[j]; v[i][L[i]].ap=w;
                }
        }

        if (a[1]==1)
        for (i=2; i<=n; ++i)
            pot[1][i]=1;

        for (i=1; i<=n; ++i) //ferific daca sunt compatibili
            for (j=i; j<=n; ++j)
            {
                int ok=1;

                for (int k1=1; k1<=L[i] && ok; ++k1)
                {
                    int ok1=0;
                    for (int k2=1; k2<=L[j]; ++k2)
                        if (v[i][k1].x==v[j][k2].x)
                        {
                            if (v[i][k1].ap<=v[j][k2].ap) ok1=1;
                                                     else ok1=0;
                        }
                    if (! ok1) ok=0;
                }

                pot[i][j]=ok;
            }

        /*for (i=1; i<=n; ++i)
        {
            for (j=1; j<=n; ++j)
                g<<pot[i][j]<<" ";

            g<<"\n";
        }*/

        for (i=K; i<=n; ++i)
        {
            maxx=i; back (1);
        }
        g<<sol<<"\n";
    }

    return 0;
}
