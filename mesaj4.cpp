# include <fstream>
# include <vector>
using namespace std;
ifstream f("mesaj4.in");
ofstream g("mesaj4.out");
vector <int> v[100005];
struct elem
{
    int x,y;
}E;
vector <elem> sol;
int i,j,n,m,x,y,VV;
int ap[100005];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]])
        {
            DFS (v[k][i]);
            E.x=v[k][i]; E.y=k;
            sol.push_back(E); ++VV;
        }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
    if (VV!=n-1) g<<"-1\n";
    else {
              g<<2*n-2<<"\n";
              for (i=0; i<sol.size(); ++i)
                  g<<sol[i].x<<" "<<sol[i].y<<"\n";
              for (i=sol.size()-1; i>=0; --i)
                  g<<sol[i].y<<" "<<sol[i].x<<"\n";
         }

    return 0;
}
