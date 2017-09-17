# include <fstream>
# include <algorithm>
# include <cstring>
# include <queue>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("darb.in");
ofstream g("darb.out");
vector <int> v[NR];
int i,j,n,m,S,maxx,x,y;
void DFS (int k, int niv, int tata)
{
    if (niv>maxx)
    {
        S=k;
        maxx=niv;
    }
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata) DFS (v[k][i], niv+1, k);
}
int main ()
{
    f>>n;
    for (i=1; i<n; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1, 1, 0);
    DFS (S, 1, 0);
    g<<maxx<<"\n";

    return 0;
}
