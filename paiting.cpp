# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("painting.in");
ofstream g("painting.out");
vector <int> v[NR];
int i,j,n,m,x,y,K;
int col[NR], timp[NR];
void DFS (int k, int tata, int C, int T)
{
    if (timp[k]>T) C=col[k], T=timp[k];
    col[k]=C;

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata) DFS (v[k][i], k, C, T);
}
int main ()
{
    f>>n>>K;
    for (i=1; i<=n; ++i)
        col[i]=1;
    for (i=1; i<n; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=K; ++i)
    {
        f>>x>>y;
        col[x]=y; timp[x]=i;
    }
    DFS (1, 0, 1, 0);

    for (i=1; i<=n; ++i)
        g<<col[i]<<" ";
    g<<"\n";

    return 0;
}
