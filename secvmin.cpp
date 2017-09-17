# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("secvmin.in");
ofstream g("secvmin.out");
int i,j,n,m,P,sol,x;
int poz[10*NR], a[NR], OK[10*NR];
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>a[i];

    for (i=1; i<=m; ++i) {
        f>>x; poz[x]=i;
    }
    sol=999999;
    for (i=1; i<=n; ++i) {
        P=poz[a[i]];
        if (P) {
            if (P==1)
                 OK[P]=max(OK[P], i);
            else OK[P]=max(OK[P], OK[P-1]);

            if (P==m && OK[P])
                sol=min(sol, i - OK[P]+1);
        }
    }
    if (sol==999999) g<<"-1\n";
                else g<<sol<<"\n";

    return 0;
}
