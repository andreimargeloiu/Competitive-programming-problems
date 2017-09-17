# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define inf 999999999
using namespace std;
ifstream f("pm2.in");
ofstream g("pm2.out");
vector <int> v[105],V[105];
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
            if (minn[v[k][i]]<minn[k]+timp[k]) minn[v[k][i]]=minn[k]+timp[k];

            if (in[v[k][i]]==0) q.push(v[k][i]);
        }
    }
}
void maxim ()
{
    int i;
    for (i=1; i<=n; ++i)
        if (out[i]==0) q.push(i);

    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<V[k].size(); ++i)
        {
            --out[V[k][i]];
            if (maxx[V[k][i]]<maxx[k]+timp[k]) maxx[V[k][i]]=maxx[k]+timp[k];

            if (out[V[k][i]]==0) q.push(V[k][i]);
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
        f>>k;
        for (j=1; j<=k; ++j)
        {
            f>>var; ++in[i];
            v[var].push_back(i);
            ++out[var];
            V[i].push_back(var);
        }
    }
    for (i=1; i<=n; ++i)
        if (in[i]==0) q.push(i), minn[i]=0;

    BF ();
    maxim ();
    g<<VV<<"\n";
    for (i=1; i<=n; ++i)
        g<<minn[i]<<" "<<VV-maxx[i]-timp[i]<<"\n";

    return 0;
}
