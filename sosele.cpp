# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 20005
using namespace std;
vector <int> v[NR];
int i,j,n,m,x,y,conexe,pericol,N;
int niv[NR], minn[NR], ap[NR];
void DFS (int k, int nivel, int tata)
{
    ap[k]=1; niv[k]=nivel; minn[k]=nivel;
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata)
        {
            if (! ap[v[k][i]])
            {
                DFS (v[k][i], nivel+1, k);
                if (minn[v[k][i]]>nivel)
                {
                    ++pericol; //un nou drum ce trebuie supravegheat
                }
                minn[k]=min(minn[k], minn[v[k][i]]);
            }
            else minn[k]=min(minn[k], niv[v[k][i]]);
        }
}
int main ()
{
    freopen ("sosele.in", "r", stdin);
    freopen ("sosele.out", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (i=1; i<=n; ++i)
        if (! ap[i])
        {
            ++conexe;
            DFS (i, 1, 0);
        }
    printf ("%d\n%d\n", conexe-1, pericol);

    return 0;
}
