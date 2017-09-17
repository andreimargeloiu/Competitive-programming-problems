# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("easyvect.in");
ofstream g("easyvect.out");
struct elem {
    int i, val;
    long long sol;
}Q[NR];
bool cmp (elem x, elem y) {
    if ((x.val & 1) == (y.val & 1)) return x.val < y.val; //aceiasi paritate
                               else return (x.val & 1) < (y.val & 1);
}
bool cmp2 (elem x, elem y) {
    return x.i < y.i;
}
int i,j,n,m,x,y,T,nrQ;
int X[NR];
long long S[NR];

long long calc (int poz, int t) {
    long long sol=S[poz];
    t=t-(poz-1);
    if (t<0) return 0;
    sol=sol + 1LL*X[poz-1]*((t+1)/2) + 1LL*X[poz]*(t/2);

    return sol;
}
// rezolv queriurile Qst - Qdr, iar pozitia maxima de afla intre ci - cs
void rezolva (int Qst, int Qdr, int ci, int cs) {
    if (Qst > Qdr) return;

    int I;
    long long maxx=0, var=0;
    int mij=(Qst + Qdr)/2;
    for (int i=ci; i<=cs; ++i) { // fac brute pe fiecare pozitie
        var=calc(i, Q[mij].val);

        if (var > maxx) maxx=var, I=i;
    }
    Q[mij].sol=maxx;

    rezolva (Qst, mij-1, ci, I);
    rezolva (mij+1, Qdr, I, cs);
}
int main ()
{
    f>>T;
    while (T--) {
        f>>n>>nrQ;
        for (i=1; i<=n; ++i) {
            f>>X[i];
            S[i]=S[i-1] + X[i];
        }
        for (i=1; i<=nrQ; ++i) {
            f>>Q[i].val;
            Q[i].sol=0;
            Q[i].i=i;
        }
        sort (Q+1, Q+nrQ+1, cmp); // parele prima data
        for (i=1; i<=nrQ+1; ++i)
            if (Q[i].val & 1 || i==nrQ+1) {
                rezolva (1, i-1, 2, n);
                rezolva (i, nrQ, 2, n);
                break;
            }

        sort (Q+1, Q+nrQ+1, cmp2);
        for (i=1; i<=nrQ; ++i)
            g<<Q[i].sol<<"\n";
    }

    return 0;
}
