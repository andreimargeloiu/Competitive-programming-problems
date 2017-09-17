# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
ifstream f("arhipelag.in");
ofstream g("arhipelag.out");
vector <int> v[100005];
int i,j,n,m,x,y,VV,nr,t,o,k;
int ap[100005],adunate[100005],ord[100005],arhip[100005];
bool cmp (int x, int y)
{
    if (x<=y) return 0;
        else return 1;
}
void DFS (int k)
{
    ap[k]=1; ++nr;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
}
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n>>m>>k;
        for (i=1; i<=n; ++i)
        {
            ap[i]=0; adunate[i]=0;
            v[i].clear();
        }
        for (i=1; i<=m; ++i)
        {
            f>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for (i=1; i<=k; ++i)
            f>>ord[i];
        VV=0;
        for (i=1; i<=n; ++i)
        {
            if (!ap[i])
            {
                nr=0;
                DFS(i);
                arhip[++VV]=nr;
            }
        }
        sort (arhip+1, arhip+VV+1, cmp);
        for (i=1; i<=VV; ++i)
            adunate[ord[(i-1)%k+1]]+=arhip[i];

        g<<"Case "<<o<<": ";
        for (i=1; i<=k; ++i)
            g<<adunate[i]<<" ";
        g<<"\n";
    }

    return 0;
}
