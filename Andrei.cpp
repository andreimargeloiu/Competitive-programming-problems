# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("andrei.in");
ofstream g("andrei.out");
struct elem
{
    int y, col;
}E;
vector <elem> v[100005];
vector <int> visited;
int i,j,n,m,x,y;
int VV[100005], uz[100005];
int DFS(int k, int tip)
{
    int i,nod,col;
    if(uz[k])
    {
        if(VV[k]!=tip) return 0;
        return 1;
    }
    visited.push_back(k); uz[k]=1; VV[k]=tip;
    for(i=0; i<v[k].size(); ++i)
    {
        nod=v[k][i].y; col=v[k][i].col;
        if(col==0 && tip==0) { if(! DFS(nod, 1)) return 0; }
        if(col==1 && tip==1) { if(! DFS(nod, 0)) return 0; }
        if(col==2)           { if(! DFS(nod, tip)) return 0; }
    }
    return 1;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>E.col;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    for(i=1; i<=n; ++i)
        if(!uz[i])
        {
            if(! DFS(i, 0))
            {
                for (int o=0; o<visited.size(); ++o) uz[visited[o]]=0;
                DFS(i, 1);
            }
        }

    for(i=1; i<=n; ++i)
        g<<VV[i]<<" ";

    return 0;
}
