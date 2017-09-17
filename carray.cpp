# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 530005
using namespace std;
vector <int> v[NR];
int i,j,n,m,x,y,Q,ai,bi;
long long a[25000], H[NR], nr;
bool ap[NR];
void numara (int k) {
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i) {
        if (! ap[v[k][i]]) numara (v[k][i]);
        H[k]+=H[v[k][i]];
    }
}
void query (int k, long long nr) {
    if (H[k]==1) {
        printf ("%d\n", a[k]);
    }
    else {
             if (nr<=H[v[k][0]]) query (v[k][0], nr);
                            else query (v[k][1], nr-H[v[k][0]]);
         }
}
int main ()
{
    freopen ("carray.in", "r", stdin);
    freopen ("carray.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &Q);
    for (i=1; i<=n; ++i) {
        scanf ("%d", &a[i]);
        H[i]=1; ap[i]=1;
    }
    for (i=n+1; i<=n+m; ++i) {
        scanf ("%d%d", &ai, &bi);
        v[i].push_back(ai);
        v[i].push_back(bi);
    }
    //numaram
    for (i=n+1; i<=n+m; ++i)
        if (! ap[i]) numara (i);

    for (i=1; i<=Q; ++i) {
        scanf ("%d%lld", &x, &nr);
        query (x, nr);
    }

    return 0;
}
