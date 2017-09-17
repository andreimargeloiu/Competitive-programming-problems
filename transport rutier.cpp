# include <fstream>
# include <algorithm>
# include <vector>
# define NR 50005
using namespace std;
ifstream f("rutier.in");
ofstream g("rutier.out");
struct elem
{
    int y, i;
}E;
vector <elem> v[NR];
int i,j,n,m,x,y,X,Y,maxx,I,cost,cnou;
int ap[NR], T[NR], M[NR], niv[NR], C[NR];
long long COST;
void DFS (int k, int tata, int nivel, int I)
{
    ap[k]=1; niv[k]=nivel; T[k]=tata; M[k]=I;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i].y]) DFS (v[k][i].y, k, nivel+1, v[k][i].i);
}
int main ()
{
    f>>n;
    for (i=2; i<=n; ++i)
    {
        f>>x>>cost; E.i=i; C[i]=cost; COST+=cost;
        E.y=x; v[i].push_back(E);
        E.y=i; v[x].push_back(E);
    }
    DFS (1, 0, 1, 0);

    f>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>cnou;

        X=x; Y=y; maxx=0;
        while (niv[X]>niv[Y])
        {
            if (C[M[X]]>maxx) maxx=C[M[X]], I=M[X];
            X=T[X];
        }
        while (niv[Y]>niv[X])
        {
            if (C[M[Y]]>maxx) maxx=C[M[Y]], I=M[Y];
            Y=T[Y];
        }
        while (X!=Y)
        {
            if (C[M[X]]>maxx) maxx=C[M[X]], I=M[X];
            if (C[M[Y]]>maxx) maxx=C[M[Y]], I=M[Y];
            X=T[X]; Y=T[Y];
        }
        if (maxx>cnou)//daca se actualizeaza suma
        {
            COST=COST-maxx+cnou;
            C[I]=cnou;
        }
        g<<COST<<"\n";
    }


    return 0;
}
