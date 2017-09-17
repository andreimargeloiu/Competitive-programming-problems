# include <fstream>
# include <algorithm>
# include <vector>
# define NR 250005
# define inf 999999999
using namespace std;
ifstream f("arb4.in");
ofstream g("arb4.out");
struct elem
{
    int niv, k;
}a[20][4*NR], st[4*NR];
struct elem2
{
    int x, y, cost, i;
}lat[NR];
bool cmp (elem2 x, elem2 y)
{
    if (x.cost>=y.cost) return 0;
                   else return 1;
}
struct elem3
{
    int y, i;
}E, T[NR];
vector <elem3> v[NR];
struct solutie
{
    int val, i;
}sol[NR];


int i,j,n,m,x,y,LCA,cost,VV,L,l,CI,CS;
int niv[NR], lg[2*NR], poz[2*NR];

void DFS (int k, int tata, int nivel, int I)
{
    T[k].y=tata; T[k].i=I; niv[k]=nivel;

    //LCA
    st[++VV].niv=nivel; st[VV].k=k;
    poz[k]=VV;

    for (int i=0; i<v[k].size(); ++i)
        if (! poz[v[k][i].y]) {
            DFS (v[k][i].y, k, nivel+1, v[k][i].i);
            st[++VV].niv=nivel; st[VV].k=k;
        }
}

void Lca ()
{
    int i,j;
    for (i=2; i<=VV; ++i)
        lg[i]=lg[i/2]+1;

    //facem LCA
    DFS (0, 0, 1, 0);
    for (i=1; i<=VV; ++i)
        a[0][i]=st[i];

    for (i=1; i<=lg[VV]; ++i) {
        for (j=1; j<=VV-(1<<i)+1; ++j)
            if (a[i-1][j].niv < a[i-1][j+(1<<(i-1))].niv) a[i][j]=a[i-1][j];
                                                    else  a[i][j]=a[i-1][j+(1<<(i-1))];
    }
}

void urca (int k, int cost, int LCA, int I)
{
    while (niv[k] > niv[LCA])
    {
        if (sol[T[k].i].val > cost) {
            sol[T[k].i].val=cost;
            sol[T[k].i].i=I;
        }
        k=T[k].y;
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<n; ++i) {
        f>>x>>y>>cost; E.i=i-1;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }

    Lca ();

    //muchii suplimentare
    for (i=n; i<=m; ++i) {
        f>>lat[i-n+1].x>>lat[i-n+1].y>>lat[i-n+1].cost;
        lat[i-n+1].i=i-1;
    }
    L=m-n+1;
    sort (lat+1, lat+L+1, cmp);


    for (i=0; i<n-1; ++i) //initializam solutia
        sol[i].val=inf;

    //incepem rezolvarea problemei
    for (i=1; i<=L; ++i) {
        x=lat[i].x; y=lat[i].y; cost=lat[i].cost;
        CI=min(poz[x], poz[y]); CS=max(poz[x], poz[y]);

        l=lg[CS-CI+1];

        if (a[l][CI].niv < a[l][CS-(1<<l)+1].niv) LCA=a[l][CI].k;
                                            else  LCA=a[l][CS-(1<<l)+1].k;

        //urcam din x in sus
        urca (x, cost, LCA, lat[i].i);

        urca (y, cost, LCA, lat[i].i);
    }

    for (i=0; i<n-1; ++i)
        if (sol[i].val!=inf) g<<sol[i].i<<"\n";
                        else g<<"-1\n";

    return 0;
}
