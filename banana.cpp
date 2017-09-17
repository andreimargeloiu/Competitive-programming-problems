# include <fstream>
# include <vector>
# include <algorithm>
# define mod 7019
using namespace std;
ifstream f("banana.in");
ofstream g("banana.out");
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
struct elem
{
    int x,y,i;
}E,c[16005];
vector <elem> v[mod];
vector <int> a[16005];
int i,j,n,m,x,y,k,VV,rez,Q,o;
int ap[16005],sol[16005];
void DFS (int k)
{
    ap[k]=1; ++VV;
    for (int i=0; i<a[k].size(); ++i)
        if (! ap[a[k][i]]) DFS(a[k][i]);
}
int main ()
{
    int n,nr,x,y,lv,cv;
    f>>n>>k;
    for (i=1; i<=n; ++i)
    {
        f>>E.x>>E.y; E.i=i;
        c[i].x=E.x; c[i].y=E.y;
        nr=(E.x*n+E.y)%mod;
        v[nr].push_back(E);
    }
    for (i=1; i<=n; ++i)
    {
        for (j=0; j<4; ++j)
        {
            lv=c[i].x+dx[j]; cv=c[i].y+dy[j];
            nr=(lv*n+cv)%mod;
            for (o=0; o<v[nr].size(); ++o)
            {
                if (v[nr][o].x==lv && v[nr][o].y==cv)
                {
                    a[i].push_back(v[nr][o].i);
                    a[v[nr][o].i].push_back(i);
                    break;
                }
            }
        }
    }
    for (i=1; i<=n; ++i)
    {
        if (! ap[i])
        {
            VV=0;
            DFS (i);
            sol[++Q]=VV;
        }
    }
    sort (sol+1, sol+Q+1);
    for (i=Q; i>=Q-k+1; --i)
        rez+=sol[i];
    g<<rez<<"\n";

    return 0;
}
