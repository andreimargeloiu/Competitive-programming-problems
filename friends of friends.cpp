# include <fstream>
# include <vector>
# include <algorithm>
# include <cstring>
# include <queue>
using namespace std;
ifstream f("fof.in");
ofstream g("fof.out");
vector <int> v[1005];
queue <int> q;
int i,j,n,m,x,y,VV;
int NR[1005],ap[1005],sol[1005];
bool cmp (int x, int y)
{
    if (NR[x]<NR[y]) return 0;
       else if (NR[x]==NR[y] && x>=y) return 0;
            else return 1;
}
void BFS (int k)
{
    int i;
    ap[k]=0;
    q.push(k);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        if (ap[k]==2) sol[++VV]=k;
        for (i=0; i<v[k].size(); ++i)
        {
            if (ap[k]+1<ap[v[k][i]])
            {
                ap[v[k][i]]=ap[k]+1;
                NR[v[k][i]]=1;
                q.push(v[k][i]);
            }
            else if (ap[k]+1==ap[v[k][i]]) ++NR[v[k][i]];
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
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            NR[j]=0;
            ap[j]=999999;
        }
        VV=0;
        BFS (i);
        sort (sol+1, sol+VV+1, cmp);
        for (j=1; j<=VV; ++j)
            g<<sol[j]<<" ";
        g<<"\n";
    }

    return 0;
}
