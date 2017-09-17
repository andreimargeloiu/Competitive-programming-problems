# include <fstream>
using namespace std;
ifstream f("distante.in");
ofstream g("distante.out");
int i,j,n,m,x,y,c,o,ok,t,S;
int dist[50005];
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n>>m>>S; ok=1;
        for (i=1; i<=n; ++i)
            f>>dist[i];
        for (i=1; i<=m; ++i)
        {
            f>>x>>y>>c;
            if (dist[x]+c<dist[y] || dist[y]+c<dist[x]) ok=0;
        }
        if (dist[S]) ok=0;
        if (ok) g<<"DA\n";
           else g<<"NU\n";
    }


    return 0;
}
