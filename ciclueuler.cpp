# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
vector <int> v[NR], st;
int i,j,x,y,n,m;
int ap[NR];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
}
void euler ()
{
    while (st.size())
    {
        int k=st.back();
        if (v[k].size())
        {
            int y=v[k].back();
            v[k].pop_back();
            st.push_back(y);

            v[y].erase(find(v[y].begin(), v[y].end(), k));
        }
        else {
                 g<<k<<" ";
                 st.pop_back();
             }
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
    DFS (1);
    for (i=1; i<=n; ++i)
        if (v[i].size()%2==1 || !ap[i])
        {
            g<<"-1\n";
            return 0;
        }

    st.push_back(1);
    euler ();

    return 0;
}
