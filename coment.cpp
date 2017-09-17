# include <fstream>
# include <vector>
# include <cstring>
using namespace std;
ifstream f("coment.in");
ofstream g("coment.out");
vector <int> v[105];
int ap[105],stiva[105];
int i,j,n,m,x,y,st,ok;
void DFS (int k)
{
    int i;
    if (!ok)
    {
        ap[k]=1; stiva[++st]=k;
        if (st==n) ok=1;
        for (i=0; i<v[k].size() && !ok; ++i)
            if (ap[v[k][i]]==0) DFS(v[k][i]);
        --st; ap[k]=0;
    }
}
int main ()
{
    f>>n;
    while (f>>x>>y)
        v[x].push_back(y);

    ok=0;
    DFS(1);
    for (i=1; i<=n; ++i)
        g<<stiva[i]<<" ";
    g<<"\n";
    return 0;
}
