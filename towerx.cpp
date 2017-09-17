# include <bits/stdc++.h>
# define NR 10005
using namespace std;
ifstream f("towerx.in");
ofstream g("towerx.out");
int i,j,n,m,ok,last,act,nou;
int poz[2][NR], sol[NR], Poz[NR];
int main ()
{
    f>>n;
    act=0; nou=1;
    for (i=1; i<=n; ++i) {
        poz[nou][1]=1;
        for (j=2; j<=i; ++j) {
            poz[nou][j] = poz[nou][j-1] + poz[act][j-1];
            if (poz[nou][j] > i ) poz[nou][j]-=i;
        }
        Poz[i]=poz[nou][i];
        swap (act, nou);
    }
    last=0;
    for (i=n; i>=1; --i) {
        ok=0;
        while (Poz[i]) {
            ++last; if (last==n+1) last=1;
            if (! sol[last]) --Poz[i];
        }
        sol[last]=i;
    }
    for (i=1; i<=n; ++i)
        g<<sol[i]<<" ";
    g<<"\n";



    return 0;
}
