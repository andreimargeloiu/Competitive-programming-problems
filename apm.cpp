# include <fstream>
# include <algorithm>
# define NR 400005
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
struct elem {
    int x, y, c;
}a[NR];
bool cmp (elem x, elem y) {
    return x.c < y.c;
}
int i,j,n,m,x,y,cost,VV;
int R[NR], H[NR], sol[NR];
int rad (int k) {
    while (R[k]!=k) return rad(R[k]);
    return k;
}
void kruskal () {
    int i,Rx,Ry;
    for (i=1; i<=n; ++i)
        R[i]=i, H[i]=1;

    for (i=1; i<=m; ++i) {
        Rx=rad(a[i].x);
        Ry=rad(a[i].y);

        if (Rx != Ry) {
            sol[++VV]=i;
            cost+=a[i].c;

            if (H[Rx] > H[Ry]) R[Ry]=Rx, H[Rx]+=H[Ry];
                          else R[Rx]=Ry, H[Ry]+=H[Rx];
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
        f>>a[i].x>>a[i].y>>a[i].c;

    sort (a+1, a+m+1, cmp);
    kruskal ();

    g<<cost<<"\n"<<n-1<<"\n";
    for (i=1; i<n; ++i)
        g<<a[sol[i]].x<<" "<<a[sol[i]].y<<"\n";



    return 0;
}
