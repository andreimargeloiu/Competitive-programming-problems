# include <bits/stdc++.h>
# define mp make_pair
# define f first
# define s second
# define LB(p) ((-p)&p)
# define NR 100005
using namespace std;
ifstream f("galerie.in");
ofstream g("galerie.out");
vector <pair <int, int> > baga[NR];
vector <int> scoate[NR];
struct elem {
    int cs, k, ind;
}E;
vector <elem> Q[NR];
int i,j,n,m,k,ci,cs,T,VV,cost;
int AIB[NR];
long long sol[3*NR];
void up (int poz, int cost) {
    for (int i=poz; i<=n; i+=LB(i))
        AIB[i]+=cost;
}
int qr (int poz) {
    int sol=0;
    for (int i=poz; i>=1; i-=LB(i))
        sol+=AIB[i];
    return sol;
}
int main ()
{
    f>>n>>m>>T;
    for (i=1; i<=m; ++i) {
        f>>ci>>cs>>cost;
        if (ci>cs) swap(ci, cs);
        baga[ci].push_back(mp(cs, cost));
        scoate[cs].push_back(cost);
    }
    for (i=1; i<=T; ++i) {
        f>>ci>>cs>>E.k;
        if (ci>cs) swap(ci, cs);
        E.cs=cs; E.ind=i;
        Q[ci].push_back(E);
    }
    for (i=1; i<=n; ++i) {
        for (auto &x: baga[i])
            up (x.f, x.s);
        for (auto &x: Q[i])
            if (x.k < x.cs - i) sol[x.ind]=1LL * (qr(n)-qr(x.cs-1))*(x.cs-i-x.k);
            else sol[x.ind]=0;
        for (auto &x: scoate[i])
            up (i, x);
    }
    for (i=1; i<=T; ++i)
        g<<sol[i]<<"\n";
    return 0;
}
