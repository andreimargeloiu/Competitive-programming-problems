# include <fstream>
# include <algorithm>
# define NR 100005
# define LB(p) ((-p)&p)
# define MOD 666013
using namespace std;
ifstream f("distincte.in");
ofstream g("distincte.out");
struct elem {
    int x, y, i, sol;
}Q[NR];
bool cmp (elem x, elem y) { return x.y > y.y; }
bool cmp2 (elem x, elem y) { return x.i < y.i; }
struct elem2 {
    int x, urm, i;
}a[NR];
bool cmp3 (elem2 x, elem2 y) { return x.urm > y.urm; }

int i,j,n,m,VV,K;
int AIB[NR], urm[NR];

void update (int poz, int val) {
    for (int i=poz; i<=n; i+=LB(i)) {
        AIB[i]+=val;
        AIB[i]%=MOD;
    }
}
int query (int poz) {
    int sol=0;
    for (int i=poz; i>=1; i-=LB(i)) {
        sol+=AIB[i];
        sol%=MOD;
    }
    return sol;
}
int main ()
{
    f>>n>>K>>m;
    for (i=1; i<=n; ++i) {
        f>>a[i].x; a[i].i=i;
    }
    for (i=1; i<=K; ++i) urm[i]=n+1;
    for (i=n; i>=1; --i) {
        a[i].urm=urm[a[i].x];
        urm[a[i].x]=i;
    }

    sort (a+1, a+n+1, cmp3);

    for (i=1; i<=m; ++i) {
        f>>Q[i].x>>Q[i].y;
        Q[i].i=i;
    }
    sort (Q+1, Q+m+1, cmp);

    for (i=1; i<=m; ++i) {
        while (VV<n && a[VV+1].urm > Q[i].y) {
            ++VV;
            update (a[VV].i, a[VV].x);
        }

        Q[i].sol=(query (Q[i].y) - query (Q[i].x - 1)+MOD)%MOD;
    }

    sort (Q+1, Q+m+1, cmp2);
    for (i=1; i<=m; ++i)
        g<<Q[i].sol<<"\n";

    return 0;
}
