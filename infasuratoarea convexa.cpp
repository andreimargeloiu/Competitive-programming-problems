# include <bits/stdc++.h>
# define NR 120005
using namespace std;
ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");
struct elem {
    double x, y;
}a[NR];
bool cmp (elem x, elem y) {
    double dx1, dx2, dy1, dy2;
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
double det (elem a, elem b, elem c) {
    return a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y - b.x*a.y;
}
int i,j,n,m,VV,I;
int st[NR];

void infasuratoare () {
    st[1]=1; st[2]=2; VV=2;
    for (int i=3; i<=n; ++i) {
        while (VV>=2 && det(a[st[VV-1]], a[st[VV]], a[i])<0)
            --VV;
        st[++VV]=i;
    }
}
int main ()
{
    f>>n; I=1;
    for (i=1; i<=n; ++i) {
        f>>a[i].x>>a[i].y;

        if (a[i].y<a[I].y) I=i;
        else if (a[i].y==a[I].y && a[i].x < a[I].x) I=i;
    }
    swap(a[1], a[I]);
    sort (a+2, a+n+1, cmp);
    infasuratoare ();

    g<<VV<<"\n";
    for (i=VV; i>=1; --i)
        g<<fixed<<setprecision(6)<<a[st[i]].x<<" "<<a[st[i]].y<<"\n";

    return 0;
}
