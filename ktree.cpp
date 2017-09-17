# include <fstream>
# include <algorithm>
# include <vector>
# define NR 105
# define inf 999999999
using namespace std;
ifstream f("ktree.in");
ofstream g("ktree.out");
struct elem {
    int y, cost;
}E;
vector <elem> v[NR];
int i,j,n,m,x,y,k,t,K,VV,cost;
int D[2*NR][NR][NR], A[NR][NR], euler[2*NR], start[NR], stop[NR], copii[NR], minn[NR][NR];
int taie[NR];
void DFS (int k, int tata, int C) {
    euler[++VV]=k; start[k]=VV;

    A[k][0]=0; copii[k]=1; taie[k]=C;

    for (int i=0; i<v[k].size(); ++i) {
        if (v[k][i].y==tata) continue;

        DFS (v[k][i].y, k, v[k][i].cost);
        copii[k]+=copii[v[k][i].y];
    }

    for (int i=0; i<v[k].size(); ++i) {
        if (v[k][i].y==tata) continue;
        int urm=v[k][i].y, cost=v[k][i].cost;

        // le iei de la fiu
        for (int j=copii[k]; j>=1; --j)
            for (int o=j; o>=0; --o) // cati iei proprii
                A[k][j]=min (A[k][j], A[k][o] + A[urm][j-o]);


        for (int j=copii[k]; j>=1; --j)
            A[k][j]=min (A[k][j], A[k][j-1] + cost); // o tai pe asta
    }

    euler[++VV]=k; stop[k]=VV;
}
void init () {
    int i,j,k;

    for (i=1; i<=2*n; ++i)
        for (j=0; j<=n; ++j)
            for (k=0; k<=n; ++k)
                D[i][j][k]=inf;

    for (i=1; i<=n; ++i)
        for (j=0; j<=n; ++j)
            A[i][j]=inf;
}
int main ()
{
    f>>n>>m>>K;
    for (i=1; i<n; ++i) {
        f>>x>>y>>cost; E.cost=cost;
        E.y=y; v[x].push_back(E);

        E.y=x; v[y].push_back(E);
    }
    init ();
    // A[i][j] - costul minim pentru a taia j muchii din arborele lui i
    DFS (1, 0, 0);
    // DP[i][j][k] - costul minim pentru a avea j noduri inaccesibile din nodul 1
    //               si sa fi taiat k muchii

    D[1][0][0]=0;
    for (i=1; i<=2*n; ++i) { //fiecare pozitie euler
        x=euler[i];

        // nu stergem nimic
        for (j=0; j<=n; ++j)
            for (k=0; k<=m; ++k)
                D[i+1][j][k]=min(D[i+1][j][k], D[i][j][k]);

        if (start[x]==i) { // il stergem
            // D[pozitia finala a lui T in parcurgere + 1][j + nr de noduri din subarborele T][k + nrs],
            // unde nrs ia valori de la 1 la M.

            for (j=0; j<=n; ++j)
                for (k=0; k<=m; ++k)
                    minn[j][k]=inf;

            for (j=0; j<=n; ++j) { // fiecare numar de noduri inaccesibile
                for (k=0; k<=m; ++k) // fiecare numar de muchii tataie
                    for (t=0; t<=copii[x]; ++t)
                        minn[j + copii[x]][k + t + 1]=min(minn[j + copii[x]][k + t + 1], taie[x] + D[i][j][k] + A[x][t]);
            }

            for (j=0; j<=n; ++j)
                for (k=0; k<=m; ++k)
                    D[stop[x]+1][j][k]=min(D[stop[x]+1][j][k], minn[j][k]);
        }
    }
    if (K > n-m || D[2*n][n-K][m]==inf) g<<"-1\n";
    else g<<D[2*n][n-K][m]<<"\n";

    return 0;
}
