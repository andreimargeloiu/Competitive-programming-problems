# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;
ifstream f("pcb.in");
ofstream g("pcb.out");
queue <int> q;
vector <int> v[100005];
int i,j,n,m,x,y,X;
int ap[100005];
void BFS (int k)
{
    int i;
    q.push(k);
    while (! q.empty())
    {
        k=q.front (); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (ap[v[k][i]]==0)
            {
                ap[v[k][i]]=ap[k]+1;
                q.push(v[k][i]);
            }
        }
    }
}
int main ()
{
    f>>n>>m>>X; ++X;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y+1);
        v[y+1].push_back(x);
    }
    BFS (1);
    if (! ap[X]) g<<"-1\n";
        else g<<ap[X]<<"\n";
    return 0;
}
