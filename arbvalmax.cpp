# include <algorithm>
# include <vector>
# include <cstdio>
# include <cstring>
# define NR 300005
using namespace std;
vector <int> v[NR];
int i,j,n,m,x,y;
int sursa[NR], trup[NR], max1[NR], val[NR], maxfara[NR], T[NR];
// max1[i] - maximul din subarborele lui i,
// sursa[i] - maximul de la sursa la i
void DFS (int k, int tata) {
    int urm; max1[k]=val[k];
    sursa[k]=max(sursa[tata], val[k]);

    for (int i=0; i<v[k].size(); ++i) {
        urm=v[k][i];
        if (urm!=tata) {
            DFS (urm, k);
            max1[k]=max(max1[k], max1[urm]);
        }
    }
}
void maxim (int k, int tata, int MAXact) {
    int urm,M1=0, M2=0;
    trup[k]=MAXact;

    for (int i=0; i<v[k].size(); ++i) {
        urm=v[k][i]; if (urm==tata) continue;
        if (max1[urm] > M1) M2=M1, M1=max1[urm];
        else if (max1[urm] > M2) M2=max1[urm];
    }

    maxfara[k]=M1;
    for (int i=0; i<v[k].size(); ++i) {
        urm=v[k][i]; if (urm==tata) continue;
        if (max1[urm]!=M1) maxim (urm, k, max(MAXact, M1));
                      else maxim (urm, k, max(MAXact, M2));
     }
}
int main ()
{
    freopen ("arbvalmax.in", "r", stdin);
    freopen ("arbvalmax.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=2; i<=n; ++i) {
        scanf ("%d", &x); T[i]=x;

        v[x].push_back(i);
        v[i].push_back(x);
    }
    for (i=1; i<=n; ++i)
        scanf ("%d", &val[i]);
    DFS (1, 0);
    maxim (1, 0, 0);

    for (i=1; i<=m; ++i) {
        scanf ("%d%d", &x, &y);
        printf ("%d\n", max(maxfara[y], max(trup[y], sursa[T[x]])));
    }

    return 0;
}
