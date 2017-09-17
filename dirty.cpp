# include <fstream>
# include <algorithm>
# include <vector>
using namespace std;
ifstream f("dirty.in");
ofstream g("dirty.out");
vector <int> v[100005];
int i,n,m,x,y,copii,maxx,VV;
int ap[100005],minn[100005],niv[100005],sol[100005];
void DFS (int k, int nivel, int tata)
{
    int comp=1;
    ap[k]=1; niv[k]=nivel; minn[k]=nivel;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (v[k][i]!=tata)
        {
            if (! ap[v[k][i]])
            {
                if (k==1) ++copii;
                DFS (v[k][i], nivel+1, k);
                minn[k]=min(minn[k], minn[v[k][i]]);
                if (minn[v[k][i]]>=nivel) ++comp;
            }
            else minn[k]=min(minn[k],niv[v[k][i]]);
        }
    }
    if (k==1)
    {
        if (copii>maxx) maxx=copii, VV=1, sol[1]=1;
            else if (copii==maxx) sol[++VV]=1;
    }
    else {
             if (comp>maxx) maxx=comp, VV=1, sol[1]=k;
                else if (comp==maxx) sol[++VV]=k;
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
    DFS (1,1,0);
    sort (sol+1,sol+VV+1);
    g<<maxx<<" "<<VV<<"\n";
    for (i=1; i<=VV; ++i)
        g<<sol[i]<<" ";
    return 0;
}
