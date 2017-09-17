# include <bits/stdc++.h>
# define NR 100
# define MOD 30211
using namespace std;
ifstream f("carry.in");
ofstream g("carry.out");
int st[NR], a[NR], i,j,SOL,n,K;
char s[NR];
int verifica () {
    int sol=0, t=0;
    for (int i=n; i>=1; --i) {
        t=t + st[i] + a[i];
        t=t/10;
        if (t) ++sol;
    }
    if (sol==K) ++SOL;
}
void back (int k) {
    if (k==n+1) {
        verifica ();
    } else {
        int start;
        if (k==1) start=1;
             else start=0;

        for (int i=start; i<=9; ++i) {
            st[k]=i;
            back(k+1);
        }
    }
}
int main ()
{
    f>>n>>K; f.get();
    f.getline (s+1, NR);
    for (i=1; i<=n; ++i)
        a[i]=s[i]-'0';

    back(1);
    g<<SOL%MOD<<"\n";

    return 0;
}
