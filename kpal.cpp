# include <bits/stdc++.h>
# define NR 1000005
# define sqrtU 10005
using namespace std;
ifstream f("kpal.in");
ofstream g("kpal.out");
int i,j,n,m,ci,cs,VV,St,Dr,baza,Q,K;
long long maxx=100000000, aux[NR];
int var[100], st[100];
bool verifica (int baza, int NC, int MINUS) {
    int L=2*NC - MINUS;
    long long sol=0;
    // pun si cealalta jumate
    for (int i=1; i<=NC; ++i)
        var[i]=var[L-i+1]=st[i];

    for (int i=1; i<=L; ++i)
        sol=1LL * baza * sol + var[i];

    if (sol > maxx) return 0;
    else {
        aux[++VV]=sol;
        return 1;
    }
}
void BACK (int baza, int NC, int V) {
    verifica (baza, NC-1, 0); //par

    int start;
    if (NC==1) start=1;
          else start=0;

    for (int i=start; i<baza; ++i) { //impar
        st[NC]=i;
        if (! verifica (baza, NC, 1))
            break;
    }

    for (int i=start; i<baza; ++i) {
        int nextV=V * baza + i;
        if (nextV > sqrtU) break;

        st[NC]=i;
        BACK(baza, NC+1, nextV);
    }
}
int cb (int numar) {
    int ci=1, cs=VV, mij=0, sol=0;
    while (ci<=cs) {
        mij=(ci+cs)/2;
        if (numar < aux[mij]) cs=mij-1;
                         else ci=mij+1, sol=mij;
    }
    return sol;
}
void normalizare () {
    int VV2=0;
    sort (aux+1, aux+VV+1);

    for (int i=1; i<=VV; ++i)
        if (aux[i]!=aux[i-1]) aux[++VV2]=aux[i];

    VV=VV2;
}
int main ()
{
    f>>K; aux[0]=-1; aux[++VV]=0;
    for (i=1; i<=K; ++i) {
        f>>baza;
        BACK (baza, 1, 0);
    }
    normalizare ();
    f>>Q; //g<<VV<<"\n";
    for (i=1; i<=Q; ++i) {
        f>>St>>Dr;
        ci=cb(St-1);
        cs=cb(Dr);

        g<<cs-ci<<"\n";
    }

    return 0;
}
