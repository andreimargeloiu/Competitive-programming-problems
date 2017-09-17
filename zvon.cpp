# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("zvon.in");
ofstream g("zvon.out");
vector <int> v[NR];
int i,j,n,m,o,t,x,y;
int ap[NR], timp[NR];
bool cmp (int a, int b)
{
    if (timp[a]<=timp[b]) return 0;
                     else return 1;
}
void DFS (int k)
{
    for (int i=0; i<v[k].size(); ++i)
        DFS (v[k][i]);

    sort (v[k].begin(), v[k].end(), cmp);
    for (int i=0; i<v[k].size(); ++i)
        timp[k]=max(timp[k], timp[v[k][i]]+i+1);
}
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n; v[n].clear(); timp[n]=0;

        for (i=1; i<n; ++i)
        {
            timp[i]=0; v[i].clear ();

            f>>x>>y;
            v[x].push_back(y);
        }
        DFS (1);
        g<<timp[1]<<"\n";
    }

    return 0;
}
