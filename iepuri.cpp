# include <fstream>
# include <vector>
# include <cstring>
# define MOD 30011
using namespace std;
ifstream f("iepuri.in");
ofstream g("iepuri.out");
vector <int> v[105];
int i,j,n,m,K,x,y,VV,R;
int in[105], suma[105], a[105][105];
void DFS (int k)
{
    int i,j;
    if (v[k].size()==0)
    {
        for (i=1; i<=K; ++i)
            a[k][i]=1;
    }
    else
    {
        for (i=0; i<v[k].size(); ++i)
            DFS (v[k][i]);

        memset(suma, 0, sizeof(suma));

        for (i=K-1; i>=1; --i)
        {
            int S=1;
            for (j=0; j<v[k].size(); ++j)
            {
                suma[j]+=a[v[k][j]][i+1];
                if (suma[j]>=MOD) suma[j]%=MOD;

                S=S*suma[j];
                if (S>=MOD) S%=MOD;
            }
            a[k][i]=S;
        }
    }
}
int main ()
{
    f>>n>>K;
    for (i=1; i<n; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        ++in[y];
    }
    for (i=1; i<=n; ++i)
        if (! in[i]) R=i;

    DFS (R);
    for (i=1; i<=K; ++i)
        VV+=a[R][i];
    g<<VV%MOD<<"\n";

    return 0;
}
