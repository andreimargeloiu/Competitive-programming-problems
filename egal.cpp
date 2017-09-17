# include <bits/stdc++.h>
# include <unordered_map>
# define NR 100005
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("egal.in");
ofstream g("egal.out");
vector <int> v[NR], aux[NR];
unordered_map <int, int> M[NR];
pair <int, int> sol[NR], afis[NR];
int i,j,n,m,x,y;
int val[NR], H[NR], SOL[NR], T[NR];
void DFS (int k, int tata) {
    if (v[k].size()==1) { //daca e frunza
        M[k][val[k]]=1; aux[k].push_back(val[k]); // in hash
        H[k]=1;         T[k]=k;

        sol[k].f=val[k];  sol[k].s=1;
        afis[k].f=val[k]; afis[k].s=1;

    } else {
        int TATA=0, apMax=0, U=0, urm, SOLmax=1<<31;
        for (int i=0; i<v[k].size(); ++i)
            if (v[k][i]!=tata) {
                DFS (v[k][i], k);
                urm=T[v[k][i]];
                if (H[urm] > H[TATA]) TATA=urm;
            }

        SOLmax=sol[TATA].f; apMax=sol[TATA].s;
        for (int i=0; i<v[k].size(); ++i) {
            urm=T[v[k][i]];
            if (v[k][i]!=tata && urm!=TATA) { //trebuie realocat
                for (int j=0; j<aux[urm].size(); ++j) {
                    U=aux[urm][j]; // culoarea
                    ++M[TATA][U]; ++H[TATA]; aux[TATA].push_back(U);

                    if(M[TATA][U] > apMax) apMax=M[TATA][U], SOLmax=U;
                    else if (M[TATA][U]==apMax && SOLmax > U) SOLmax=U;
                }
            }
        }
        ++M[TATA][val[k]]; ++H[TATA]; aux[TATA].push_back(val[k]);
        U=val[k];

        if(M[TATA][U] > apMax) apMax=M[TATA][U], SOLmax=U;
        else if (M[TATA][U]==apMax && SOLmax > U) SOLmax=U;

        sol[TATA].f=SOLmax; sol[TATA].s=apMax;

        T[k]=TATA;
        afis[k].f=SOLmax; afis[k].s=apMax;
    }
}
int main ()
{
    f>>n;
    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i) f>>val[i];

    DFS(1, 0);

    for (i=1; i<=n; ++i)
        g<<afis[i].f<<" "<<afis[i].s<<"\n";

    return 0;
}
