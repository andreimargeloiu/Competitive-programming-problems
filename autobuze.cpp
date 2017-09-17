# include <fstream>
# include <algorithm>
# include <map>
# include <vector>
using namespace std;
ifstream f("autobuze.in");
ofstream g("autobuze.out");
vector <int> v[50005];
int x,n,sol,maxx,nr,VV,var;
int a[50005];
bool ap[50005];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (! ap[v[k][i]]) DFS (v[k][i]);
    }
}
int main ()
{
    map <int,int> m;
    int i,j;
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        m.insert(std::pair<int,int>(a[i],i));
        maxx=max(maxx, a[i]);
    }
    sol=n;
    for (i=1; i<=n; ++i)
    {
        if (maxx/a[i]>=n)
        {
            for (j=1; j<=n; ++j)
            {
                if (a[i]%a[j]==0 || a[j]%a[i]==0)
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        else
        {
            nr=a[i];
            for (j=2; j<=n && nr<=maxx; ++j)
            {
                nr+=a[i];
                if (m.find(nr)!=m.end())
                {
                    v[i].push_back(m.find(nr)->second);
                    v[m.find(nr)->second].push_back(i);
                }
            }
        }
    }
    for (i=1; i<=n; ++i)
    {
        if (! ap[i])
        {
            ++VV;
            DFS (i);
        }
    }
    g<<VV<<"\n";
    return 0;
}
