# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100000
using namespace std;
ifstream f("concurs.in");
ofstream g("concurs.out");
vector <int> v[NR];
int i,j,n,m,x,y,VV,Q,CI,CS, R;
int poz[NR], val[NR], lg[NR*2], ap[NR];
struct elem
{
    int k, niv;
}st[NR*2], rmq[20][4*NR];
struct soll
{
    int x, y, val;
}SOL;
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
void solutie (int val, int x, int y)
{
    if (SOL.val==-1) SOL.val=val, SOL.x=x, SOL.y=y;
    else {
             if (val>SOL.val) SOL.val=val, SOL.x=x, SOL.y=y;
             else if (val==SOL.val)
             {
                 if(x<SOL.x) SOL.val=val, SOL.x=x, SOL.y=y;
                 else if (x==SOL.x && y<SOL.y) SOL.val=val, SOL.x=x, SOL.y=y;
             }
         }
}
int main ()
{
    f>>n>>Q;
    for (i=1; i<=n; ++i)
        f>>val[i];

    for (i=1; i<n; ++i)
    {
        f>>x>>y;
        ap[y]=1;
        v[x].push_back(y);
    }
    for (i=1; i<=n; ++i)
        if (!ap[i]) R=i;
    DFS (R, 0);

    for (i=2; i<=VV; ++i)
        lg[i]=lg[i/2] + 1;

    //facem RMQ
    for (i=1; i<=VV; ++i)
        rmq[0][i]=st[i];

    for (i=1; i<=lg[VV]; ++i)
    {
        for (j=1; j<=VV-(1<<(i-1)); ++j)
        {
            if (rmq[i-1][j].niv < rmq[i-1][j+(1<<(i-1))].niv) rmq[i][j]=rmq[i-1][j];
                                                         else rmq[i][j]=rmq[i-1][j+(1<<(i-1))];
        }
    }

    SOL.val=-1;
    for (i=1; i<=Q; ++i)
    {
        f>>x>>y;
        CI=min(poz[x], poz[y]); CS=max(poz[x], poz[y]);

        int k=lg[CS-CI+1];
        if (rmq[k][CI].niv<rmq[k][CS-(1<<k)+1].niv) solutie (val[rmq[k][CI].k], x, y);
                                               else solutie (val[rmq[k][CS-(1<<k)+1].k], x, y);
    }
    g<<SOL.val<<" "<<SOL.x<<" "<<SOL.y<<"\n";

    return 0;
}
