# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,n,m,T,R,P,S,test,ok,unu,doi,trei,OK;
char sol[NR], aux[NR];
void solutie () {
    if (unu!=0 || doi!=0 || trei!=0) return;

    if (! OK) {
        OK=1;
        for (int i=1; i<=(1<<n); ++i)
            sol[i]=aux[i];
    } else {
        OK=1;
        for (int i=1; i<=(1<<n); ++i)
            if (aux[i]<sol[i]) break;
            else if (aux[i]>sol[i]) return;

        for (int i=1; i<=(1<<n); ++i)
            sol[i]=aux[i];
    }

}
void castiga (int ci, int cs, int k) {
    if (ci==cs) {
        if (k==1) aux[ci]='P', --unu;
        if (k==2) aux[ci]='R', --doi;
        if (k==3) aux[ci]='S', --trei;
    } else {
        int mij=(ci + cs)/2;
        if (k==1) {
            castiga(ci, mij, 1);
            castiga(mij+1, cs, 2);
        }
        if (k==2) {
            castiga(ci, mij, 2);
            castiga(mij+1, cs, 3);
        }
        if (k==3) {
            castiga(ci, mij, 1);
            castiga(mij+1, cs, 3);
        }
    }
}
int main ()
{
    f>>T; int test=0;
    while (T--) {
        f>>n>>R>>P>>S;
        ++test; g<<"Case #"<<test<<": ";

        OK=0;
        doi=R; unu=P; trei=S; castiga(1, (1<<n), 1); solutie();
        doi=R; unu=P; trei=S; castiga(1, (1<<n), 2); solutie();
        doi=R; unu=P; trei=S; castiga(1, (1<<n), 3); solutie();

        if (OK==0) g<<"IMPOSSIBLE\n";
        else {
            for (int i=1; i<=(1<<n); ++i)
                g<<sol[i];
            g<<"\n";
        }
    }

    return 0;
}
