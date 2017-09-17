# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
struct elem
{
    int y, nr;
}E;
vector <elem> v[50005];
vector <int> st;
int i,j,n,m,x,y,M,ok,R;
int grad[50005], win[100005], ap[50005], luat[100005];
void euler (int k)
{
    int y,nr;
    st.push_back(k);
    while (st.size())
    {
        k=st.back(); ap[k]=1;
        while (v[k].size() && luat[v[k][v[k].size()-1].nr]==1)
            v[k].pop_back();
        if (! v[k].size())
        {
            st.pop_back();
            continue;
        }
        luat[v[k][v[k].size()-1].nr]=1;
        st.push_back(v[k][v[k].size()-1].y);
        win[v[k][v[k].size()-1].nr]=v[k][v[k].size()-1].y;
    }
}
int main ()
{
    freopen ("fotbal2.in", "r", stdin);
    freopen ("fotbal2.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        ++grad[x]; ++grad[y];
        E.y=y; E.nr=i;
        v[x].push_back(E);
        E.y=x; E.nr=i;
        v[y].push_back(E);
    }
    R=n+1; ok=1; M=m;
    for (i=1; i<=n; ++i)
        if (grad[i]%2==1)
        {
            ok=0;
            E.y=R; E.nr=++M;
            v[i].push_back(E);
            E.y=i; E.nr=M;
            v[R].push_back(E);
        }
    for (i=1; i<=n; ++i)
    {
        if (! ap[i]) euler(i);
    }
    if (ok) printf ("0\n");
       else printf ("2\n");
    for (i=1; i<=m; ++i)
        printf ("%d\n", win[i]);
    return 0;
}
