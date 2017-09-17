# include <cstdio>
# include <vector>
# include <cstring>
# include <algorithm>
# define NR 10005
using namespace std;
vector <int> v[NR];
int i,j,n,m,cuplate,sol,x,y;
int M1[NR], M2[NR], ap[NR], SL[NR], SR[NR];
int match (int k)
{
    int i;
    if (ap[k]) return 0;
    ap[k]=1;
    for (i=0; i<v[k].size(); ++i)
        if (! M2[v[k][i]])
        {
            M1[k]=v[k][i]; M2[v[k][i]]=k;
            SL[k] = 1;
            return 1;
        }

    for (i=0; i<v[k].size(); ++i)
        if (match(M2[v[k][i]]))
        {
             M1[k]=v[k][i]; M2[v[k][i]]=k;
             SL[k] = 1;
             return 1;
        }
    return 0;
}
void support(int k)
{
    for(int i=0; i<v[k].size(); ++i)
        if(! SR[v[k][i]])
        {
            SR[v[k][i]] = 1;
            SL[M2[v[k][i]]] = 0;
            support(M2[v[k][i]]);
        }
}
int main ()
{
    freopen ("felinare.in", "r", stdin);
    freopen ("felinare.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
    }

    cuplate=1;
    while (cuplate)
    {
        cuplate=0;
        memset (ap, 0, sizeof(ap));
        for (i=1; i<=n; ++i)
            if (!M1[i]) cuplate+=match(i);
    }
    for (i=1; i<=n; ++i) if (M1[i]) ++sol;
    printf("%d\n", 2*n - sol);

    for(i=1; i<=n; ++i)
        if(!SL[i]) support(i);

    for(i=1; i<=n; ++i)
        printf("%d\n",3-SL[i]-2*SR[i]);

    return 0;
}
