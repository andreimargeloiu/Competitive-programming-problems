# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define inf 999999999
using namespace std;
ifstream f("pm2.in");
ofstream g("pm2.out");
vector <int> v[105];
queue <int> q;
int i,j,n,k,VV,var;
int minn[105],maxx[105],timp[105],in[105],out[105];
void BF ()
{
    while (! q.empty())
    {
        k=q.front(); q.pop();
        VV=max(VV, minn[k]+timp[k]);
        for (i=0; i<v[k].size(); ++i)
        {
            --in[v[k][i]];
            if (minn[v[k][i]]>minn[k]+timp[k]) minn[v[k][i]]=minn[k]+timp[k];

            if (in[v[k][i]]==0) q.push(v[k][i]);
        }
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>timp[i];
    for (i=1; i<=n; ++i)
    {
        f>>k; minn[i]=inf;
        for (j=1; j<=k; ++j)
        {
            f>>var; ++in[i]; ++out[var];
            v[var].push_back(i);
        }
    }
    for (i=1; i<=n; ++i)
        if (in[i]==0) q.push(i), minn[i]=0;

    BF ();
    g<<VV<<"\n";
    for (i=1; i<=n; ++i)
        g<<minn[i]<<" "<<maxx[i]<<"\n";

    return 0;
}
