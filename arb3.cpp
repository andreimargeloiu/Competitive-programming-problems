# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
vector <int> v[NR];
vector <long long> S[NR];
int i,j,n,X,Q;
int T[NR];
long long suma, val[NR], times;
bool cmp (int x, int y) {
    return val[x] > val[y];
}
long long solve (int X, long long times) {
    if (X==1) return times;

    int ci,cs,mij, aux1, aux2;
    long long newTimes, ajung;

    ajung=val[X] - times;

    ci=0; cs=v[T[X]].size()-1;
    // caut suma
    while (ci<=cs) {
        mij=(ci+cs)/2;
        if (val[v[T[X]][mij]]>=ajung) ci=mij+1, aux1=mij;
                                 else cs=mij-1;

    }
    ci=0; cs=v[T[X]].size()-1;
    while (ci<=cs) {
        mij=(ci+cs)/2;
        if (val[v[T[X]][mij]]>=val[X]) ci=mij+1, aux2=mij;
                                  else cs=mij-1;

    }
    newTimes=S[T[X]][aux1] - (ajung)*(aux1+1) - (aux1-aux2);

    return solve (T[X], newTimes);
}
int main ()
{
    freopen ("arb3.in", "r", stdin);
    freopen ("arb3.out", "w", stdout);
    scanf ("%d%d", &n, &Q);
    for (i=2; i<=n; ++i) {
        scanf ("%d", &T[i]);
        v[T[i]].push_back(i);
    }

    for (i=1; i<=n; ++i)
        scanf ("%d", &val[i]);

    for (i=1; i<=n; ++i) {
        sort (v[i].begin(), v[i].end(), cmp);
        suma=0;
        for (j=0; j<v[i].size(); ++j) {
            suma+=val[v[i][j]];
            S[i].push_back(suma);
        }
    }

    for (i=1; i<=Q; ++i) {
        scanf ("%d%d", &X, &times);
        printf ("%d\n", solve (X, times));
    }

    return 0;
}
