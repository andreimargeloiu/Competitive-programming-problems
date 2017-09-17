# include <bits/stdc++.h>
# define NR 20005
using namespace std;
ifstream f("delay.in");
ofstream g("delay.out");
vector <int> v[NR];
struct elem {
    int nod, niv;
}RMQ[20][4*NR];

int i,j,n,m,pA,pB,pLca,lca,tip,A,B,VV,valNEW,x,y,dif,nod,Q,pTata;
int ARB[10*NR], suma[NR], val[NR], start[NR], stop[NR], lg[4*NR], T[NR];

void DFS (int k, int tata, int niv) {
    suma[k]=suma[tata] + val[k]; T[k]=tata;

    ++VV; start[k]=VV;
    RMQ[0][VV].nod=k; RMQ[0][VV].niv=niv;
    for (auto &x: v[k]) {
        if (x!=tata) {
            DFS (x, k, niv+1);
            ++VV; RMQ[0][VV].nod=k; RMQ[0][VV].niv=niv;
        }
    }
    stop[k]=VV;
}
void logaritmi () {
    for (int i=2; i<=VV; ++i)
        lg[i]=lg[i/2] + 1;
}
void update (int nod, int ci, int cs, int CI, int CS, int X) {
    if (CI<=ci && cs<=CS) ARB[nod]+=X;
    else {
        int mij=(ci+cs)/2;
        if (CI<=mij) update (2*nod, ci, mij, CI, CS, X);
        if (mij<CS) update (2*nod+1, mij+1, cs, CI, CS, X);
    }
}
void query (int nod, int ci, int cs, int X, int &adunat) {
    if (ci<=X && X<=cs) adunat+=ARB[nod];
    if (ci==cs || X==0) return;

    int mij=(ci + cs)/2;
    if (X<=mij) query (2*nod, ci, mij, X, adunat);
          else query (2*nod+1, mij+1, cs, X, adunat);
}
int LCA (int A, int B) {
    int CI=min(start[A], start[B]), CS=max(start[A], start[B]);
    int log=lg[CS - CI + 1];
    if (RMQ[log][CI].niv < RMQ[log][CS-(1<<log)+1].niv) return RMQ[log][CI].nod;
                                                  else  return RMQ[log][CS-(1<<log)+1].nod;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>val[i];

    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    DFS (1, 0, 0); logaritmi ();

    for (i=1; i<=lg[VV]; ++i)
        for (j=1; j<=VV-(1<<(i-1))+1; ++j)
            if (RMQ[i-1][j].niv < RMQ[i-1][j+(1<<(i-1))].niv) RMQ[i][j]=RMQ[i-1][j];
                                                         else RMQ[i][j]=RMQ[i-1][j+(1<<(i-1))];
    f>>Q;
    for (i=1; i<=Q; ++i) {
        f>>tip;
        if (tip==1) { //modifica
            f>>nod>>valNEW;
            dif=valNEW - val[nod];
            update (1, 1, VV, start[nod], stop[nod], dif);
            val[nod]=valNEW;
        } else {
            f>>A>>B;
            lca=LCA (A, B);

            pA=0; query (1, 1, VV, start[A], pA);
            pB=0; query (1, 1, VV, start[B], pB);
            pLca=0; query (1, 1, VV, start[lca], pLca);
            pTata=0; query (1, 1, VV, start[T[lca]], pTata);

            g<<(suma[A]+pA) + (suma[B]+pB) - (suma[lca]+pLca) - (suma[T[lca]]+pTata)<<"\n";
        }
    }


    return 0;
}
