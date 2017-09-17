#include<vector>
#include <fstream>
#include<cstdio>
#include<queue>
#define NMAX 100005
#define INF 1000000009
using namespace std;
ifstream f("autobuze2.in");
ofstream g("autobuze2.out");
int n,m,k,i,x,y,lg,ok,j,prim,ant;
int d[NMAX],viz[NMAX];
vector<int>v[NMAX];
queue<int>q;
void BFS()
{
    d[1]=1;
    vector<int>::iterator it;
    q.push(1);
    viz[1]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for (it=v[x].begin();it!=v[x].end();++it)
        {
            if (viz[*it]==0)
            {
                viz[*it]=1;
                q.push(*it);
                d[*it]=d[x]+1;
            }
        }
    }
}
int main()
{
    f>>n>>m;
    for (i=1;i<=m;++i) f>>x>>y;
    f>>k;
    for (i=1;i<=k;++i)
    {
        f>>lg;
        ok=0;
        for (j=1;j<=lg;++j)
        {
            f>>x;
            if (ok==0) prim=x,ok=1,ant=x;
            else
            {
               // v[x].push_back(ant);
                v[ant].push_back(x);
                ant=x;
            }
        }
        v[x].push_back(prim);
    }
    BFS();
    if (d[n]!=0) g<<d[n];
        else g<<"Iesim la un suc?\n";
    return 0;
}
