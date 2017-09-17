# include <bits/stdc++.h>
# define NR 1005
using namespace std;
ifstream f("mosia.in");
ofstream g("mosia.out");
struct elem {
    int x, y, d;
}a[NR];
bool cmp (elem x, elem y) {
    int dx1, dy1, dx2, dy2;
    dx1=x.x - a[1].x;
    dy1=x.y - a[1].y;

    dx2=y.x - a[1].x;
    dy2=y.y - a[1].y;

    if (dy1*dx2 != dy2*dx1) return dy1*dx2 < dy2*dx1;
    else {
        if (x.x != y.x) return x.x < y.x;
                   else return x.y > y.y;
    }
}
int i,j,n,m,x,y,VV,poz;
int E[NR], st[NR];
long double dp[NR], maxx;

int det (elem a, elem b, elem c) {
    return a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y - b.x*a.y;
}
void infasuratoare () {
    st[++VV]=1; st[++VV]=2;
    for (int i=3; i<=n; ++i) {
        while (VV>=2 && det (a[st[VV-1]], a[st[VV]], a[i])<0)
            --VV;
        st[++VV]=i;
    }
}

long double dist (elem x, elem y) {
    return sqrt((double)((x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y)));
}
long double dinamica (int start, int stop) {
    memset (dp, 0, sizeof(dp));
    long double V=0;
    for (int i=start; i<=stop; ++i) {
        V=dist(a[E[i-1]], a[E[i+1]]) * a[E[i]].d / 2;
        dp[i]=max(dp[i-1], dp[i-2] + V);
    }
    return dp[stop];
}
int main ()
{
    f>>n; poz=1;
    for (i=1; i<=n; ++i) {
        f>>a[i].x>>a[i].y>>a[i].d;
        if (a[i].y < a[poz].y) poz=i;
        else if (a[i].y==a[poz].y && a[i].x < a[poz].x) poz=i;
    }

    swap(a[1], a[poz]);
    sort (a+2, a+n+1, cmp);

    infasuratoare ();

    for (i=1; i<=VV; ++i)
        E[i]=i;

    E[0]=VV; E[VV+1]=1;
    maxx=dinamica (2, VV);
    maxx=max(maxx, dinamica (1, VV-1));
    g<<fixed<<setprecision(7)<<maxx<<"\n";
    return 0;
}
