# include <fstream>
# include <vector>
# define NR 200005
using namespace std;
ifstream f("tree.in");
ofstream g("tree.out");
vector <int> v[NR];
int i,j,n,m,k,nrsol,x,S,ap[NR],ok;
void DFS (int k)
{
    int nr=0;
    for (int i=0; i<v[k].size(); ++i)
    {
        DFS (v[k][i]);
        if (! ap[v[k][i]]) ++nr;
    }

    if (nr>1) nrsol=nrsol+nr-1, ap[k]=1;
    if (k==S && nr==1) ++nrsol;
    if (k==S && nr==0) ++nrsol;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>x;
        if (x==0) S=i;
        else v[x].push_back(i);
    }
    DFS(S);
    nrsol=nrsol*2-1;

    if (n==0) nrsol=0;
    g<<nrsol<<"\n";

    return 0;
}
