# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 10005
# define mp make_pair
using namespace std;
ifstream f("ciob.in");
ofstream g("ciob.out");
vector <int> v[NR];
vector <pair <int, int> > graf[NR];
queue <int> q;
int i,j,n,m,x,y,S,sursa,L,VV,maxx,k1,k2,dir,cost,D[NR],sol[NR];
int cpy[NR], var[NR], drum[NR], poz[NR], second[NR], ap[NR], coada[NR];
void copiaza (int X) {
    sursa=S; maxx=X;
    for (int i=1; i<=maxx; ++i)
        cpy[i]=var[i];
}
void taie (int k, int tata) {
    drum[++VV]=k; poz[k]=VV;

    for (int i=0; i<v[k].size(); ++i)
        if (ap[v[k][i]] && v[k][i]!=tata)
            taie (v[k][i], k);
}
void preprocesare () {
    f>>n;
    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    f>>m;
    for (j=1; j<=m; ++j) {
        f>>S;
        f>>k1;
        for (i=1; i<=k1; ++i) {
            f>>var[i]; f>>x;
            if (var[i]!=S) second[j]=var[i];
        }
        f>>k2;
        for (i=1; i<=k2; ++i) {
            f>>var[k1 + i]; f>>x;
            if (var[k1 + i]!=S) second[j]=var[k1 + i];
        }

        if (k1+k2 > maxx)
           copiaza (k1+k2);
    }
    // avem frumul de lungime maxima pana acum
    // trebuie sa il "taiam" din graf
    for (i=1; i<=maxx; ++i)
        ap[cpy[i]]=1;
    taie (sursa, 0); // acum avem drumul intins de la dreapta la stanga
}
void BF () {
    int urm, cost, i,k ;
    while (! q.empty()) {
        k=q.front (); q.pop();
        coada[k]=0;

        for (int i=0; i<graf[k].size(); ++i) {
            urm=graf[k][i].first;  cost=graf[k][i].second;

            if (D[urm] > D[k] + cost) {
                D[urm] = D[k] + cost;
                if (! coada[urm]) {
                    q.push(urm);
                    coada[urm]=1;
                }
            }
        }
    }
}
int main ()
{
    preprocesare ();

    // incepem sa facem graful
    f.close ();
    ifstream f("ciob.in");
    f>>n;
    for (i=1; i<n; ++i)
        f>>x>>y;

    f>>m;
    for (j=1; j<=m; ++j) {
        f>>S;
        if (second[j]<S) dir=-1;
                    else dir=1;

        f>>k1; //poate decola
        for (i=1; i<=k1; ++i) {
            f>>x; f>>cost;
            if (dir==1) graf[poz[x]].push_back(mp(poz[S]-1, -cost));
                   else graf[poz[S]-1].push_back(mp(poz[x], cost-1));
        }
        f>>k2; //nu poate decola
        for (i=1; i<=k2; ++i) {
            f>>x; f>>cost;
            if (dir==1) graf[poz[S]].push_back(mp(poz[x]-1, -cost));
                   else graf[poz[x]-1].push_back(mp(poz[S], cost-1));
        }
    }

    for (i=0; i<=maxx; ++i) {
        q.push(i);
        coada[i]=1;
    }
    BF ();

    for (i=1; i<=maxx; ++i)
        sol[drum[i]]=D[i] - D[i-1];
    for (i=1; i<=n; ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
