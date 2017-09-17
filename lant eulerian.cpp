# include <fstream>
# include <vector>
# include <stack>
using namespace std;
ifstream f("le.in");
ofstream g("le.out");
struct elem
{
    int e,nr;
}E;
stack <int> st;
vector <elem> v[100];
int i,j,n,m,x,y,k;
int ap[100];
int main ()
{
    f>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        E.e=y; E.nr=i;
        v[x].push_back(E);
        E.e=x; E.nr=i;
        v[y].push_back(E);
    }
    st.push(1);
    while (! st.empty())
    {
        k=st.top();
        while (v[k].size() && ap[v[k][v[k].size()-1].nr]==1)
            v[k].pop_back();
        if (v[k].size()==0)
        {
            g<<k<<" ";
            st.pop();
            continue;
        }
        ap[v[k][v[k].size()-1].nr]=1;
        st.push(v[k][v[k].size()-1].e);
    }
    return 0;
}
