# include <fstream>
# include <algorithm>
# define LB(p) ((-p)&p)
# define NR 1005
# define MOD 30103
using namespace std;
ifstream f("evantai.in");
ofstream g("evantai.out");
struct elem {
    int ci, cs, suma;
}v[NR*NR];
bool cmp (elem x, elem y) {
    if (x.suma > y.suma) return 0;
    else if (x.suma==y.suma && x.cs - x.ci < y.cs - y.ci) return 0;
    else return 1;
}

int i,j,n,m,x,y,nr,S,sol;
int AIB[NR][NR], a[NR];

int query (int X, int Y) {
    int sol=0;
    for (int i=X; i>=1; i-=LB(i))
        for (int j=Y; j>=1; j-=LB(j)) {
            sol=sol + AIB[i][j];
            if (sol >= MOD) sol-=MOD;
        }
    return sol;
}
void update (int X, int Y, int suma) {
    for (int i=X; i<=1000; i+=LB(i))
        for (int j=Y; j<=1000; j+=LB(j)) {
            AIB[i][j]+=suma;
            if (AIB[i][j] >= MOD) AIB[i][j]-=MOD;
        }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];

    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j) {
            ++nr;
            v[nr].ci=i; v[nr].cs=j; v[nr].suma=a[i]+a[j];
        }
    sort (v+1, v+nr+1, cmp);

    for (i=1; i<=nr; ++i) {
        S=(query (v[i].cs-1, v[i].cs-1) - query (v[i].ci, v[i].cs-1) + MOD)%MOD;

        sol=sol + S + 1;
        if (sol >= MOD) sol-=MOD;

        update (v[i].ci, v[i].cs, S+1);
    }
    g<<sol<<"\n";

    return 0;
}
