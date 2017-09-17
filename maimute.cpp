# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("maimute.in");
ofstream g("maimute.out");
vector <int> v[NR];
int i,j,n,m,x,y,VV;
int first[NR], last[NR];
void DFS (int k, int tata)
{
    first[k]=++VV;
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata) DFS (v[k][i], k);
    last[k]=++VV;
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
    DFS (1, 0);
    f>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        // x > y || x<y
        if ((first[x]<first[y] && first[y]<last[x]) || (first[y]<first[x] && first[x]<last[y]))
            g<<"DA\n";
        else g<<"NU\n";
    }


    return 0;
}
