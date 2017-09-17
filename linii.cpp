# include <bits/stdc++.h>
# define NR 300005
# define INF 999999999
using namespace std;
ifstream f("linii.in");
ofstream g("linii.out");
struct elem {
    int x, y, st, dr;
}a[NR];
bool cmp (elem x, elem y) {
    if (x.dr==y.dr) return x.st > y.st;
               else return x.dr < y.dr;
}
int i,j,n,m,VV,ci,cs,mij,sol;
int st[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>a[i].x>>a[i].y;
        a[i].st=a[i].x - a[i].y;
        a[i].dr=a[i].x + a[i].y;
    }
    sort (a+1, a+n+1, cmp);
    st[0]=-INF;
    for (i=1; i<=n; ++i) {
        if (st[VV] < a[i].st) st[++VV]=a[i].st;
        else {
            ci=1; cs=VV; sol=0;
            while (ci<=cs) {
                mij=(ci+cs)/2;
                if (a[i].st <= st[mij]) sol=mij, cs=mij-1;
                                   else ci=mij+1;
            }
            st[sol]=a[i].st;
        }
    }

    g<<VV<<"\n";

    return 0;
}
