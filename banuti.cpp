# include <bits/stdc++.h>
# define INF 1e9 + 5
# define NR 50005
using namespace std;
ifstream f("banuti.in");
ofstream g("banuti.out");
struct elem2 {
    int nr, rest;
}st[NR];
queue <int> q;
int i,j,n,m,minn,VV,sol;
int a[NR], rest[NR], M[NR], luat[NR], minim[NR];

void resturi () {
    for (int i=1; i<=2*minn; ++i)
        rest[i]=i%minn;
}
void Djikstra () {
    int X, k, Xurm, kurm;
    minim[0]=M[0]; luat[0]=1;
    for (int i=1; i<minn; ++i) {
        luat[i]=0; minim[i]=M[i];
    }
    q.push(0);
    while (! q.empty()) {
        k=q.front(); q.pop();
        for (int i=1; i<=VV; ++i) {
            Xurm=minim[k] + st[i].nr;
            kurm=rest[k + st[i].rest];
            if (! luat[kurm] && Xurm < minim[kurm]) {
                minim[kurm]=Xurm;
            }
        }
        int MINN=INF, I;
        for (int i=0; i<minn; ++i) {
            if (! luat[i] && minim[i]<MINN)
                MINN=minim[i], I=i;
        }
        if (MINN!=INF) {
            luat[I]=1;
            q.push(I);
        }
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];
    sort (a+1, a+n+1);

    minn=a[1]; resturi ();
    for (i=0; i<minn; ++i) M[i]=INF;

    for (i=1; i<=n; ++i)
        M[a[i]%minn]=min(M[a[i]%minn], a[i]);

    for (i=0; i<minn; ++i)
        if (M[i]!=INF) {
            ++VV;
            st[VV].nr=M[i]; st[VV].rest=i;
        }

    Djikstra ();
    sol=0;
    for (i=0; i<minn; ++i)
        sol=max(sol, minim[i]);

    if (sol==INF) g<<"-1\n";
             else g<<sol-minn<<"\n";

    return 0;
}
