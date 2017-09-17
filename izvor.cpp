# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("izvor.in");
ofstream g("izvor.out");
vector <int> v[100];
int i,j,n,m,p,q,x,y,var,pasi,nrsol,IZVOR;
int ap[100], poteca[100][100], izvor[100][100];
void DFS (int k)
{
    ++pasi; ap[k]=1;
    if (pasi==m)
    {
        if (poteca[q][k] && IZVOR) ++nrsol;
    }
    else {
             for (int i=0; i<v[k].size(); ++i)
             {
                 if (!ap[v[k][i]])
                 {
                     if (izvor[k][v[k][i]]) ++IZVOR;
                     DFS(v[k][i]);
                     if (izvor[k][v[k][i]]) --IZVOR;
                 }
             }
         }
    --pasi; ap[k]=0;
}
int main ()
{
    f>>n>>p>>m;
    for (i=1; i<=p; ++i)
    {
        f>>x>>y>>var;
        if (!poteca[x][y])
        {
            poteca[x][y]=1; poteca[y][x]=1;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if (var)
        {
            izvor[x][y]=1; izvor[y][x]=1;
        }
    }
    for (q=1; q<=n; ++q)
        if (v[q].size()>1) DFS (q);
    g<<nrsol<<"\n";
    return 0;
}
