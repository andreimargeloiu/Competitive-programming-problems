# include <bits/stdc++.h>
# define NR 250000
using namespace std;
//ifstream f("test.in");
//ofstream g("test.out");
struct elem {
    int nr, poz;
}RMQmax[20][NR], RMQminST[20][NR], RMQminDR[20][NR];

int i,j,n,m,Lmax,ci,cs,nrQ;
int lg[NR], a[NR];
void logaritmi() {
    for (int i=2; i<=n; ++i)
        lg[i]=lg[i/2]+1;
}
int pozMax (int ci, int cs) {
    int log=lg[cs-ci+1];

    if (RMQmax[log][ci].nr >= RMQmax[log][cs-(1<<log)+1].nr) return RMQmax[log][ci].poz;
                                                        else return RMQmax[log][cs-(1<<log)+1].poz;
}
int pozMinST (int ci, int cs) {
    int log=lg[cs-ci+1];

    if (RMQminST[log][ci].nr <= RMQminST[log][cs-(1<<log)+1].nr) return RMQminST[log][ci].poz;
                                                            else return RMQminST[log][cs-(1<<log)+1].poz;
}
int pozMinDR (int ci, int cs) {
    int log=lg[cs-ci+1];

    if (RMQminDR[log][ci].nr < RMQminDR[log][cs-(1<<log)+1].nr) return RMQminDR[log][ci].poz;
                                                           else return RMQminDR[log][cs-(1<<log)+1].poz;
}
void query (int ci, int cs) {
    if (cs-ci+1<=Lmax) return;
    int paux, sol, pant, ciVAR, csVAR, pozMAX, ant;
    vector <int> v;

    v.push_back(ci); pant=ci; ant=0;
    while (1 && pant<=cs) {
        pozMAX=pozMax(pant, cs);

        if (a[pozMAX] < ant) break;
        else { // e tot maxim
            v.push_back(pozMAX);
            pant=pozMAX+1; ant=a[pozMAX];
        }
    }
    v.push_back(cs);

    for (int i=0; i<v.size()-2; ++i) {
         //fac cautare binara in stanga
        ciVAR=v[i]; pozMAX=v[i+1]; csVAR=v[i+2];

        sol=pozMinST(ci, pozMAX);
        Lmax=max(Lmax, pozMAX - sol+1);

        //fac cautare binara in dreapta
        sol=pozMinDR(pozMAX, cs);
        Lmax=max(Lmax, sol - pozMAX+1);

        if (ciVAR < pozMAX) query (ciVAR, pozMAX-1);
        if (pozMAX < csVAR) query (pozMAX+1, csVAR);
    }
    v.clear();
}
int main ()
{
    cin>>n; logaritmi ();
    for (i=1; i<=n; ++i) {
        cin>>a[i];
        RMQminST[0][i].nr=a[i];
        RMQminST[0][i].poz=i;

        RMQminDR[0][i].nr=a[i];
        RMQminDR[0][i].poz=i;

        RMQmax[0][i].nr=a[i];
        RMQmax[0][i].poz=i;
    }
    for (i=1; i<=lg[n]; ++i)
        for (j=1; j<=n-(1<<i)+1; ++j) {
            if (RMQminST[i-1][j].nr <= RMQminST[i-1][j+(1<<(i-1))].nr) RMQminST[i][j]=RMQminST[i-1][j];
                                                                  else RMQminST[i][j]=RMQminST[i-1][j+(1<<(i-1))];
            if (RMQminDR[i-1][j].nr < RMQminDR[i-1][j+(1<<(i-1))].nr) RMQminDR[i][j]=RMQminDR[i-1][j];
                                                                 else RMQminDR[i][j]=RMQminDR[i-1][j+(1<<(i-1))];


            if (RMQmax[i-1][j].nr >= RMQmax[i-1][j+(1<<(i-1))].nr) RMQmax[i][j]=RMQmax[i-1][j];
                                                              else RMQmax[i][j]=RMQmax[i-1][j+(1<<(i-1))];
        }

    cin>>nrQ;
    for (i=1; i<=nrQ; ++i) {
        cin>>ci>>cs; Lmax=1;

        query (ci, cs);

        cout<<Lmax<<"\n";
    }

    return 0;
}
