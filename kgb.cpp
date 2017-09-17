# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 5000
# define mil 1000005
using namespace std;
vector <int> v[NR], sol[NR];
struct elem
{
    int ci, cs;
}st[mil];
int i,j,n,m,x,y,nrsol,VV,X,Y,C;
int ap[NR], T[NR], niv[NR], minn[NR], critic[NR];
void DFS (int k, int tata, int nivel)
{
    ap[k]=1; T[k]=tata; niv[k]=nivel; minn[k]=nivel;

    for (int i=0; i<v[k].size(); ++i) {
        if (v[k][i]!=tata) {
            if (! ap[v[k][i]]) { // daca e un fiu
                st[++VV].ci=k; st[VV].cs=v[k][i];

                DFS (v[k][i], k, nivel+1);

                if (minn[v[k][i]]>=nivel) { //inca o componenta conexa
                    ++nrsol; sol[nrsol].push_back(k); critic[++C]=k;

                    while (st[VV].ci!=k) {
                        sol[nrsol].push_back(st[VV].cs);
                        --VV;
                    }

                    sol[nrsol].push_back(st[VV].cs); --VV;
                }

                minn[k]=min(minn[k], minn[v[k][i]]);
            }
            else minn[k]=min(minn[k], niv[v[k][i]]);
        }
    }
}

int main ()
{
    freopen ("kgb.in", "r", stdin);
    freopen ("kgb.out", "w", stdout);

    scanf ("%d", &n);
    while (scanf ("%d %d", &x, &y)) {
        if (x==X & Y==y) break;

        v[x].push_back(y);
        v[y].push_back(x);

        X=x; Y=y;
    }

    for (i=0; i<=n; ++i)
        if (! ap[i]) DFS (i, i, 1);

    if (nrsol==0) printf ("KGB este forte\n");
    else {
        printf ("KGB nu este forte\n");

        sort (critic+1, critic+C+1); critic[0]=-1;

        for (i=1; i<=C; ++i)
            if (critic[i]!=critic[i-1]) printf ("%d ", critic[i]);

        printf ("\n%d\n", nrsol);

        for (i=1; i<=nrsol; ++i) {
           sort (sol[i].begin(), sol[i].end());
           for (j=0; j<sol[i].size(); ++j)
                printf ("%d ", sol[i][j]);
            printf ("\n");
        }
    }




    return 0;
}
