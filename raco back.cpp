# include <bits/stdc++.h>
using namespace std;
ifstream f("raco.in");
ofstream g("raco.out");
int sol, st[100], VV, a[100], n, MOD, i;
long long suma;
void back (int k) {
    if (st[k-1]<=n) {
        if (st[k-1]>0 && (int)(suma%MOD)==0) ++sol;

        for (int i=st[k-1]+1; i<=n; ++i) {
            suma+=a[i]; st[k]=i;
            back(k+1);
            suma-=a[i]; st[k]=0;
        }

    }
}
int main ()
{
    f>>n>>MOD;
    for (i=1; i<=n; ++i)
        f>>a[i];

    back (1);
    g<<sol<<"\n";

    return 0;
}
