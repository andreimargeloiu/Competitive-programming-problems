# include <bits/stdc++.h>
# define NR 100050
using namespace std;
ifstream f("curent.in");
ofstream g("curent.out");
vector <int> v[NR];
struct elem {
    int timp, i, tip;
}Q[NR];
bool cmp (elem x, elem y) {
    return x.timp < y.timp;
}
int i,j,n,m,TIME,VV,nrQ,ind,I;
int ARB[8*NR], T[NR], stins[8*NR], euler[2*NR], first[NR], last[NR];

void DFS (int k, int tata) {
    euler[++VV]=k; first[k]=VV;

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata) DFS (v[k][i], k);

    euler[++VV]=k; last[k]=VV;
}
void init (int nod, int ci, int cs) {
    ARB[nod]=cs-ci+1;
    if (ci!=cs) {
        int mij=(ci + cs)/2;
        if (ci<=mij) init (2*nod, ci, mij);
        if (mij<cs) init (2*nod+1, mij+1, cs);
    }
}
void update (int nod, int ci, int cs, int CI, int CS, int tip) {
    if (CI<=ci && cs<=CS) {
        if (tip==0) ++stins[nod];
               else --stins[nod];
        if (! stins[nod]) {
            if (ci==cs) ARB[nod]=1;
            else {
                ARB[nod]=0;
                if (! stins[2*nod])   ARB[nod]+=ARB[2*nod];
                if (! stins[2*nod+1]) ARB[nod]+=ARB[2*nod+1];
            }
        } else ARB[nod]=0;
    } else {
        int mij=(ci+cs)/2;
        if (CI<=mij) update (2*nod, ci, mij, CI, CS, tip);
        if (mij<CS) update (2*nod+1, mij+1, cs, CI, CS, tip);

        if (! stins[nod]) {
            ARB[nod]=0;
            if (! stins[2*nod])   ARB[nod]+=ARB[2*nod];
            if (! stins[2*nod+1]) ARB[nod]+=ARB[2*nod+1];
        }
        else ARB[nod]=0;
    }
}
int main ()
{
    f>>n;
    for (i=1; i<n; ++i) {
        f>>T[i+1];
        v[i+1].push_back(T[i+1]);
        v[T[i+1]].push_back(i+1);
    }
    DFS (1, 0);

    f>>m;
    for (i=1; i<=m; ++i)
        f>>Q[i].timp>>Q[i].i>>Q[i].tip;

    sort (Q+1, Q+m+1, cmp);

    f>>nrQ; init (1, 1, VV);
    for (i=1; i<=nrQ; ++i) {
        f>>TIME;
        while (Q[I+1].timp<TIME && I<m) {
            ++I; ind=Q[I].i;
            update (1, 1, VV, first[ind], last[ind], Q[I].tip);
        }
        g<<ARB[1]/2<<"\n";
    }

    return 0;
}
