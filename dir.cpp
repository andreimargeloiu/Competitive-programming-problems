# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 9005
using namespace std;
vector <int> v[NR];
int i,j,n,m,maxx,S,VV,x,y;
int sol[NR], in[NR];
void DFS (int k, int niv)
{
    int i;
    if (v[k].size())
    {
        for (i=0; i<v[k].size(); ++i)
            DFS (v[k][i], niv+1);
    }
    else
    {
        maxx=max(maxx, niv);
    }
}
int main ()
{
    freopen ("dir.in", "r", stdin);
    freopen ("dir.out", "w", stdout);

    scanf ("%d", &n);
    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        ++in[y];
    }
    for (i=1; i<=n; ++i)
        if (in[i]==0) {S=i; break;}

    for (i=0; i<v[S].size(); ++i)
    {
        maxx=0;
        DFS (v[S][i], 1);
        sol[++VV]=maxx;
    }
    sort (sol+1, sol+VV+1);
    printf ("%d\n", sol[VV-1]+sol[VV]);

    return 0;
}
