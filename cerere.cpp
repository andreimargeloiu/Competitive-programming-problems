# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("cerere.in");
ofstream g("cerere.out");
vector <int> v[NR];
int i,j,n,m,x,y,S,VV;
int st[NR], sol[NR], ki[NR], in[NR];
void DFS (int k)
{
    st[++VV]=k;
    if (ki[k]==0) sol[k]=0;
             else sol[k]=1+sol[st[VV-ki[k]]];
    for (int i=0; i<v[k].size(); ++i)
        DFS(v[k][i]);
    --VV;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>ki[i];
    for (i=1; i<n; ++i)
    {
        f>>x>>y; v[x].push_back(y);
        ++in[y];
    }
    for (i=1; i<=n; ++i)
        if (!in[i]) {S=i; break;}

    DFS (S);

    for (i=1; i<=n; ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
