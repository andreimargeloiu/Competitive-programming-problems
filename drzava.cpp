# include <fstream>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cmath>
# include <iomanip>
# define kk 35
# define NR 100005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
vector <int> v[NR];
struct elem {
    long long x, y, nr;
}a[NR];
int i,j,n,m,x,y,K,VV,VV2,ok;
int AP[kk], S[kk], ap[NR], var[NR];
long double ci, cs, mij, sol;
void muchii (long double ver) {

    for (int i=1; i<=n; ++i)
        v[i].clear();

    for (int i=1; i<=n; ++i)
        for (int j=i+1; j<=n; ++j) {
            long double D=sqrt((long double)((a[i].y - a[j].y)*(a[i].y - a[j].y) + (a[i].x - a[j].x)*(a[i].x - a[j].x)));
            if (D+0.00001 < ver) {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
}
void DFS (int k) {
    var[++VV]=a[k].nr; ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
}
int componente () {
    int ok=0;
    memset (ap, 0, sizeof(ap));
    for (int i=1; i<=n && !ok; ++i) {
        if (! ap[i]) {
            VV=0; DFS (i);

            memset (S, 0, sizeof(S));
            // fac sumele

            for (int j=1; j<=VV; ++j) { //fiecare elem din componenta
                memset (AP, 0, sizeof(AP));
                AP[var[j]]=1;
                for (int o=0; o<=K; ++o)
                    if (S[o]) AP[(o+var[j])%K]=1;

                for (int o=0; o<=K; ++o)
                    S[o]=max(S[o], AP[o]);
            }

            if (AP[0]) ok=1;
        }
    }
    return ok;
}
int main ()
{
    f>>n>>K;
    for (i=1; i<=n; ++i) {
        f>>a[i].x>>a[i].y>>a[i].nr;
        a[i].nr%=K;
    }

    ci=0; cs=100000000;

    while (ci<=cs) {
        mij=(ci+cs)/2;

        muchii (mij);
        ok=componente ();

        if (ok) cs=mij-0.0001, sol=mij;
           else ci=mij+0.0001;
    }

    g<<fixed<<setprecision(3)<<sol<<"\n";

    return 0;
}
