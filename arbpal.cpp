# include <fstream>
# include <vector>
# include <algorithm>
# include <cstring>
# include <bitset>
using namespace std;
ifstream f("arbpal.in");
ofstream g("arbpal.out");
bitset <5005> ap[5005];
vector <int> v[5005];
int i,j,n,m,x,y;
int nr[5005];
long long VV;
char ch;
void DFS (int x, int y, int xant, int yant)
{
    int i,j;
    if (v[x].size()==0 || v[y].size()==0) return;
    for (i=0; i<v[x].size(); ++i)
        for (j=0; j<v[y].size(); ++j)
        {
            if (nr[v[x][i]]==nr[v[y][j]] && ap[v[x][i]][v[y][j]]==0)
                if (v[x][i]!=v[y][j] && v[x][i]!=xant && v[y][j]!=yant)
                {
                    ++VV;
                    ap[v[x][i]][v[y][j]]=1; ap[v[y][j]][v[x][i]]=1;
                    DFS(v[x][i],v[y][j],x,y);
                }
        }
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
    f.get();
    for (i=1; i<=n; ++i)
    {
        f>>ch; f.get();
        nr[i]=ch-'a'+1;
    }
    for (i=1; i<=n; ++i)
    {
        ap[i][i]=1;
        DFS(i,i,0,0);
    }
    //duble
    for (i=1; i<=n; ++i)
    {
        for (j=0; j<v[i].size(); ++j)
        {
            if (! ap[i][v[i][j]] && nr[v[i][j]]==nr[i])
            {
                ++VV;
                ap[i][v[i][j]]=1; ap[v[i][j]][i]=1;
                DFS(i,v[i][j],v[i][j],i);
            }
        }
    }
    g<<2*VV+n<<"\n";
    return 0;
}
