# include <fstream>
# include <vector>
# include <queue>
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
struct elem
{
    int nod, lat;
}E;
vector <elem> v[100005];
vector <int> st;
queue <int> q;
int i,j,n,m,x,y,VV,viz,nimpar;
int ap[500005],luat[500005],sol[500005];
void BFS (int k)
{
    int i;
    ap[k]=1; viz=1;
    q.push(k);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (! ap[v[k][i].nod])
            {
                ++viz;
                ap[v[k][i].nod]=1;
                q.push(v[k][i].nod);
            }
        }
    }
}
void euler (int k)
{
    st.push_back(k);
    while ( st.size())
    {
        k=st.back();
        while (v[k].size() && luat[v[k][v[k].size()-1].lat]==1)
            v[k].pop_back();
        if (! v[k].size())
        {
            sol[++VV]=k;
            st.pop_back();
            continue;
        }
        st.push_back(v[k][v[k].size()-1].nod);
        luat[v[k][v[k].size()-1].lat]=1;
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        E.nod=y; E.nod=i;
        v[x].push_back(E);
        E.nod=x; E.nod=i;
        v[y].push_back(E);
    }
    for (i=1; i<=n; ++i)
        if (v[i].size()%2==1) ++nimpar;
    BFS (1);
    if (viz!=n || nimpar)
    {
        g<<"-1\n";
        return 0;
    }
    euler (1);
    for (i=1; i<=m+1; ++i)
        g<<sol[i]<<" ";
    g<<"\n";
    return 0;
}
