# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
vector <int> v[NR], st;
int i,j,n,m,x,y;
int ap[NR];
void euler (int k)
{
    int y;
    st.push_back(k);
    while (st.size())
    {
        k=st.back();
        if (v[k].size())
        {
            y=v[k].back();
            v[k].pop_back();

            v[y].erase (find(v[y].begin (), v[y].end(), k));
            st.push_back(y);
        }
        else
        {
            g<<k<<" ";
            st.pop_back();
        }
    }
}
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
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
    DFS (1);
    for (i=1; i<=n; ++i)
        if (! ap[i] || v[i].size()%2==1)
        {
            g<<"-1\n";
            return 0;
        }
    euler (1);


    return 0;
}
