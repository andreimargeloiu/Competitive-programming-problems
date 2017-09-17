# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
vector <int> v[1005];
int i,j,o,n,m,VV,ok,K,x,y;
int ap[1005][1005];
int main ()
{
    freopen ("exam.in", "r", stdin);
    freopen ("exam.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        ap[x][y]=1;
        ap[y][x]=1;
    }
    for (i=1; i<=n; ++i)
    {
        ok=1;
        for (j=1; j<=VV; ++j)
        {
            K=1;
            for (o=0; o<v[j].size(); ++o)
               if (ap[i][v[j][o]]) {K=0; break;}
            if (K) {v[j].push_back(i); ok=0; break;}
        }
        if (ok) v[++VV].push_back(i);
    }
    printf ("%d\n", VV);

    return 0;
}
