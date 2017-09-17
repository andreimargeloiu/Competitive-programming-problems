# include <bitset>
# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 2005
# define TT 1005
# define inf 999999999
using namespace std;
vector <int> v[NR];
int i,j,n,m,x,y,T;
int pot[NR][NR+TT], Tmin[NR][NR+TT], var[NR], tmax[NR], rezerva[NR];

void init () {
    for (int i=1; i<=n; ++i)
        for (int t=0; t<=T; ++t)
            Tmin[i][t]=inf;
}
bool verifica (int k, int ci, int cs) {
    for (int i=ci; i<=cs; ++i)
        if (pot[k][i] > var[i-ci+1]) return 0;
    return 1;
}
void copiaza (int k) {
    for (int i=0; i<v[k].size(); ++i)
        rezerva[v[k][i]]=tmax[v[k][i]];
}
void restaureaza (int k) {
    for (int i=0; i<v[k].size(); ++i)
        tmax[v[k][i]]=rezerva[v[k][i]];
}
void DFS (int k, int tata) {
    // Tmin[i][j] - timpul minim pentru care tot subarborele lui i a
    //              primit mesajul pe care i l-a primit in momentul j

    // tmax[i] - momentul de timp maxim pentru care mesajul se trimite pana la Ttest
    int i,j,t,VV,ci,cs,nrfii,CI,CS,MIJ,cix,csx,urm,mij,ok,potCI,potCS,Q;
    if (v[k].size()==1 && tata!=0) { // e frunza
        for (i=0; i<=n+T; ++i)
            Tmin[k][i]=i;
    }
    else {
        for (j=0; j<v[k].size(); ++j)
            if (v[k][j]!=tata) DFS (v[k][j], k);

        nrfii=v[k].size();
        // 0
        potCI=1; potCS=nrfii-1;

        CI=0; CS=n+T;
        while (CI<=CS) { // caut binar timpul
            MIJ=(CI+CS)/2; VV=0;

            //fac tmax pentru fii
            for (i=0; i<v[k].size(); ++i) {
                cix=0; csx=n+T; urm=v[k][i];
                if (urm==tata) continue;
                tmax[urm]=-1;
                while (cix<=csx) { // caut binar tmax
                    mij=(cix + csx)/2;
                    if (Tmin[urm][1+mij] <= MIJ) cix=mij+1, tmax[urm]=mij, copiaza (k);
                                            else csx=mij-1;
                }
                var[++VV]=tmax[urm];
            }
            sort (var+1, var+VV+1);
            if (verifica (k, potCI, potCS)) CS=MIJ-1, Tmin[k][0]=MIJ;
                                       else CI=MIJ+1;
        }

        restaureaza (k);
        // 1 - T
        for (t=1; t<=n+T; ++t) {
            if (t>T+1) {Tmin[k][t]=1+Tmin[k][t-1]; continue;}

            //update la timpii POT
            if (pot[k][potCI]<t) {
                ++potCI; ++potCS;
                if (potCS > pot[k][0]) return;
            }

            ok=0;
            for (j=Tmin[k][t-1]; j<=n+T && !ok; ++j) {
                VV=0;
                for (i=0; i<v[k].size(); ++i) {
                    urm=v[k][i]; if (urm==tata) continue;
                    while (Tmin[urm][1+tmax[urm]+1] <= j)
                        ++tmax[urm];
                    var[++VV]=tmax[urm];
                }
                sort (var+1, var+VV+1);
                Tmin[k][t]=j;
                ok=verifica (k, potCI, potCS);
            }
        }
    }
}
int main ()
{
    freopen ("tcast.in", "r", stdin);
    freopen ("tcast.out", "w", stdout);
    scanf ("%d%d", &n, &T);
    init (); v[1].push_back(0);
    for (i=1; i<n; ++i) {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i) {
        for (j=0; j<T; ++j) {
            scanf ("%d", &x);
            if (x==0) pot[i][++pot[i][0]]=j;
        }
        for (int o=T; o<=T+n; ++o)
            pot[i][++pot[i][0]]=o;
    }

    DFS (1, 0);
    printf ("%d\n", Tmin[1][0]);

    return 0;
}
