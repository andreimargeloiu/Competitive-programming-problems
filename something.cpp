# include <fstream>
# include <vector>
using namespace std;
ifstream f("something.in");
ofstream g("something.out");
vector <int> v[100005];
int i,j,n,m,VV,ok,Start,Stop,x,y;
int ap[100005],culoare[100005],T[100005],ciclu[100005];
void DFS (int k, int tata)
{
    if (ok)
    {
        ap[k]=1;
        T[k]=tata;
        for (int i=0; i<v[k].size() && ok; ++i)
        {
            if (v[k][i]!=tata)
            {
                if (! ap[v[k][i]])  DFS (v[k][i],k);
                else {
                          ok=0;
                          Start=k; Stop=v[k][i];
                     }
            }
        }
    }
}
void umplere (int k, int cul)
{
    culoare[k]=cul;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (! culoare[v[k][i]])
        {
            umplere (v[k][i], cul);
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ok=1;
    DFS (1,0);
    ciclu[++VV]=Start;
    if (ok)
    {
        g<<"-1\n";
        return 0;
    }
    while (T[Start]!=Stop)
    {
        ciclu[++VV]=T[Start];
        Start=T[Start];
    }
    ciclu[++VV]=Stop;
    culoare[ciclu[1]]=1;
    culoare[ciclu[2]]=2;
    for (i=3; i<=VV; ++i)
        culoare[ciclu[i]]=3;
    for (i=1; i<=VV; ++i)
    {
        umplere(ciclu[i], culoare[ciclu[i]]);
    }
    for (i=1; i<=n; ++i)
        g<<culoare[i]<<" ";
    g<<"\n";
    return 0;
}
