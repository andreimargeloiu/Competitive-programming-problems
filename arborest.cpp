# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("arborest.in");
ofstream g("arborest.out");
vector <int> v[NR];
struct elem {
    int k, niv;
}st[NR];
bool cmp (elem x, elem y) {
    return x.niv > y.niv;
}

int VV, ci, cs, mij, sol, n, K, i, nr;
int ap[NR], aux[NR], T[NR];
void DFSinit (int k, int niv) {
    ++VV; st[VV].niv=niv; st[VV].k=k;
    for (auto &x: v[k])
        DFSinit (x, niv+1);
}
void umple (int k) {
    ap[k]=1;

    for (auto &x: v[k])
        if (! ap[x]) umple (x);
}
int numara (int K) {
    int sol=0, tata;
    memset (ap, 0, sizeof(ap));

    for (int i=1; i<=VV; ++i) {
        if (st[i].niv <= K) break;
        if (! ap[st[i].k]) {
            tata=st[i].k;
            for (int j=1; j<K; ++j)
                tata=T[tata];

            umple (tata);
            ++sol;
        }
    }

    return sol;
}
int main ()
{
    f>>n>>K;
    for (i=2; i<=n; ++i) {
        f>>T[i];
        v[T[i]].push_back(i);
    }

    DFSinit(1, 0); sort (st+1, st+VV+1, cmp);
    ci=1; cs=n;
    while (ci<=cs) {
        mij=(ci+cs)/2;
        nr=numara (mij);

        if (nr<=K) cs=mij-1, sol=mij;
              else ci=mij+1;
    }
    g<<sol<<"\n";

    return 0;
}
