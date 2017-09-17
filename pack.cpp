# include <cstdio>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 505
# define INF 999999999
using namespace std;
struct elem {
    int x, y, z;
}cutie[NR], obiect[NR];
vector <int> v[NR];
int i,j,n,m,x,y,sol,ci,cs,mij;
int ap[NR], M1[NR], M2[NR];
void muchie (int I, int J, int dif)
{
    int x, y, z, X, Y, Z, maxx=INF;
    //avem 6 posibilitati
    x=obiect[I].x; y=obiect[I].y; z=obiect[I].z;
    X=cutie[J].x; Y=cutie[J].y; Z=cutie[J].z;

    if (x<=X && y<=Y && z<=Z) maxx=min(maxx, max(X-x, max(Y-y, Z-z)));
    if (x<=X && y<=Z && z<=Y) maxx=min(maxx, max(X-x, max(Z-y, Y-z)));
    if (x<=Y && y<=X && z<=Z) maxx=min(maxx, max(Y-x, max(X-y, Z-z)));
    if (x<=Y && y<=Z && z<=X) maxx=min(maxx, max(Y-x, max(Z-y, X-z)));
    if (x<=Z && y<=X && z<=Y) maxx=min(maxx, max(Z-x, max(X-y, Y-z)));
    if (x<=Z && y<=Y && z<=X) maxx=min(maxx, max(Z-x, max(Y-y, X-z)));

    if (maxx<=dif) v[I].push_back(J);
}
void FormeazaGraf (int dif)
{
    for (int i=1; i<=n; ++i) v[i].clear();
    memset (M1, 0, sizeof(M1));
    memset (M2, 0, sizeof(M2));

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            muchie (i, j, dif);
}
int match (int k)
{
    if (ap[k]) return 0;
    ap[k]=1;

    for (int i=0; i<v[k].size(); ++i)
        if (! M2[v[k][i]] || match(M2[v[k][i]])) {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    return 0;
}
bool solutie ()
{
    int cuplate=1;
    while (cuplate)
    {
        memset (ap, 0, sizeof(ap));
        cuplate=0;
        for (int i=1; i<=n; ++i)
            if (! M1[i]) cuplate+=match(i);
    }

    for (int i=1; i<=n; ++i)
        if (! M1[i]) return 0;

    return 1;
}
int main ()
{
    freopen ("pack.in", "r", stdin);
    freopen ("pack.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d%d%d", &obiect[i].x, &obiect[i].y, &obiect[i].z);

    scanf ("%d", &m);
    for (i=1; i<=m; ++i)
        scanf ("%d%d%d", &cutie[i].x, &cutie[i].y, &cutie[i].z);

    //incepem cautarea binara

    ci=0; cs=1000;
    while (ci<=cs) {
        mij=(ci+cs)/2;

        FormeazaGraf (mij);

        if (solutie()) sol=mij, cs=mij-1;
                  else ci=mij+1;
    }

    //avem solutie sol
    if (! sol) printf ("-1\n");
    else {
             printf ("%d\n", sol);
             FormeazaGraf (sol);
             sol=solutie();

             for (i=1; i<=n; ++i)
                 printf ("%d %d\n", i, M1[i]);
         }

    return 0;
}
