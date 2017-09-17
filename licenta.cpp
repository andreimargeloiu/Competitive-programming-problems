# include <fstream>
# include <algorithm>
# define NR 100005
using namespace std;
ifstream f("licenta.in");
ofstream g("licenta.out");
struct elem {
    int x, y;
}a[NR], b[NR];
bool cmp (elem x, elem y) {
    if (x.x>y.x) return 0;
    else if (x.x==y.x && x.y>=y.y) return 0;
    else return 1;
}
int i,j,n,m,K,ci,ok1,ok2;
int main ()
{
    f>>K;
    f>>n; for (i=1; i<=n; ++i) f>>a[i].x>>a[i].y;
    f>>m; for (i=1; i<=m; ++i) f>>b[i].x>>b[i].y;

    sort (a+1, a+n+1, cmp);
    sort (b+1, b+m+1, cmp);

    ci=1; ok1=-1;
    for (i=1; i<=n && ok1==-1; ++i) { // decanul else inclus in intervalele Mirunei
        while (b[ci].x < a[i].x && ci<=m) ++ci;

        while (b[ci].x < a[i].y && ci<=m)
        {
            if (min(a[i].y, b[ci].y) - b[ci].x >= K) {ok1=b[ci].x; break;}
            ++ci;
        }
    }
    if (ok1>=0) {g<<ok1<<" "<<ok1+K<<"\n"; return 0;}


    ci=1; ok2=-1;
    for (i=1; i<=m && ok2==-1; ++i) { // decanul else inclus in intervalele Mirunei
        while (a[ci].x < b[i].x && ci<=n) ++ci;

        while (a[ci].x < b[i].y && ci<=n)
        {
            if (min(b[i].y, a[ci].y) - a[ci].x >= K) {ok2=a[ci].x; break;}
            ++ci;
        }
    }
    if (ok2>=0) {g<<ok2<<" "<<ok2+K<<"\n"; return 0;}

    g<<"-1\n";


    return 0;
}
