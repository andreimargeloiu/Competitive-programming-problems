# include <fstream>
# include <vector>
# include <algorithm>
# define NR 100005
# define inf 999999999
using namespace std;
ifstream f("lca.in");
ofstream g("lca.out");
vector <int> v[NR];
struct elem
{
    int k, niv;
}st[2*NR], a[20][2*NR];

int i,j,n,m,x,y,Q,VV,I,CI,CS,minn,POZ,S;
int poz[NR], lg[2*NR];

void DFS (int k, int niv)
{
    st[++VV].k=k; st[VV].niv=niv;
    poz[k]=VV;

    for (int i=0; i<v[k].size(); ++i)
    {
        DFS (v[k][i], niv+1);
        st[++VV].k=k; st[VV].niv=niv;
    }
}
int main ()
{
    f>>n>>Q;
    for (i=2; i<=n; ++i)
    {
        f>>x;
        v[x].push_back(i);
    }
    DFS(1, 0);

    //RMQ
    for (i=2; i<=VV; ++i)
        lg[i]=lg[i/2]+1;

    for (i=1; i<=VV; ++i)
        a[0][i]=st[i];

    for (i=1; i<=lg[VV]; ++i)
        for (j=1; j<=VV - (1<<(i-1)); ++j)
        {
            if (a[i-1][j].niv < a[i-1][j+(1<<(i-1))].niv) a[i][j]=a[i-1][j];
                                                     else a[i][j]=a[i-1][j+(1<<(i-1))];
        }

    for (i=1; i<=Q; ++i)
    {
        f>>x>>y;
        CI=min(poz[x], poz[y]); CS=max(poz[x], poz[y]);

        int k=lg[CS-CI+1];
        if (a[k][CI].niv<a[k][CS-(1<<k)+1].niv) g<<a[k][CI].k<<"\n";
                                           else g<<a[k][CS-(1<<k)+1].k<<"\n";
    }



    return 0;
}
