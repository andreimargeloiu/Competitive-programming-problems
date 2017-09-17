# include <bits/stdc++.h>
# define NR 20
using namespace std;
ifstream f("avd.in");
ofstream g("avd.out");
struct elem {
    int y, i;
}E;
vector <elem> v[NR];
int i,j,n,m,N,T,total,stari,x,y,nrsol,VV;
int a[NR][NR], luat[NR], ap[NR], sol[20000][NR], var[20000];
int dinamica (int N) {
    int i,j,q,sol=0;
    //a[i][j] - numarul de moduri de a face suma i, iar j este maxim
    for (i=1; i<=N; ++i)
        for (j=1; j<=N; ++j)
            a[i][j]=0;

    for (i=1; i<=N; ++i) {
        a[i][i]=1;
        for (j=1; j<=N; ++j)
            for (q=j; i+q<=N; ++q)
                a[i+q][q]+=a[i][j];
    }
    for (i=1; i<=N; ++i)
        sol+=a[N][i];
    return sol;
}
void init () {
    nrsol=0; stari=0; VV=0;
    for (int i=1; i<=N; ++i)
        v[i].clear();
}
void DFS (int k, int stare) {
    ++VV; ap[k]=stare;
    for (int i=0; i<v[k].size(); ++i) {
        int urm=v[k][i].y, I=v[k][i].i;
        if (ap[urm]!=stare && !luat[I])
            DFS (urm, stare);
    }
}
void BACK (int k) {
    if (k==N) {
        ++stari; sol[stari][0]=0;
        for (int i=1; i<=N; ++i)
            if (ap[i]!=stari) {
                VV=0;
                DFS (i, stari);
                sol[stari][++sol[stari][0]]=VV;
            }
    }
    else {
        luat[k]=0;
        BACK(k+1);

        luat[k]=1;
        BACK(k+1);
        luat[k]=0;
    }
}
// daca x > y
bool verifica (int x, int y) {
    for (int i=1; i<=sol[x][0]; ++i)
        if (sol[x][i] > sol[y][i]) return 1;
        else if (sol[x][i] < sol[y][i]) return 0;

    return 1;
}
bool cmp (int x, int y) {
    if (sol[x][0] > sol[y][0]) return 0;
    else if (sol[x][0]==sol[y][0] && verifica (x, y)) return 0;
    else return 1;
}
bool diferit (int x, int y) {
    if (sol[x][0] != sol[y][0]) return 1;

    for (int i=1; i<=sol[x][0]; ++i)
        if (sol[x][i] != sol[y][i]) return 1;

    return 0;
}
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t) {
        f>>N; init();
        total=dinamica (N);
        for (i=1; i<N; ++i) {
            f>>x>>y;
            E.y=y; E.i=i; v[x].push_back(E);
            E.y=x; E.i=i; v[y].push_back(E);
        }
        BACK (1);

        for (i=1; i<=stari; ++i) {
            sort (sol[i]+1, sol[i]+sol[i][0]+1);
            var[i]=i;
        }
        sort (var+1, var+stari+1, cmp);

        for (i=1; i<=stari; ++i)
            if (diferit (var[i-1], var[i])) ++nrsol;

        g<<fixed<<setprecision(5)<<((double)(nrsol))/total<<"\n";
    }

    return 0;
}
