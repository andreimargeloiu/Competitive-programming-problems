# include <bits/stdc++.h>
# define NR 100005
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
vector <pair <int, int> > v[NR];
vector <int> st;
int i,j,n,m,x,y,aparitii,impar,nrsol;
int luat[5*NR], ap[NR], sol[5*NR], grad[NR];

void DFS (int k) {
    ap[k]=1; ++aparitii;
    for (auto &x: v[k])
        if (! ap[x.f]) DFS(x.f);
}
void euler () {
    st.push_back(1);
    while (st.size()) {
        int k=st.back();
        while (v[k].size() && luat[v[k].back().s])
            v[k].pop_back();

        if (! v[k].size()) {
            sol[++nrsol]=k;
            st.pop_back();
            continue;
        }

        st.push_back(v[k].back().f);
        luat[v[k].back().s]=1;
    }
}
int main ()
{
    f>>n>>m;
    for (int i=1; i<=m; ++i) {
        f>>x>>y;
        v[x].push_back(mp(y,i)); ++grad[x];
        v[y].push_back(mp(x,i)); ++grad[y];
    }
    DFS (1);
    for (i=1; i<=n; ++i)
        if (grad[i]%2==1) ++impar;

    if (impar || aparitii!=n) {
        g<<"-1\n";
        return 0;
    }

    euler();
    for (int i=1; i<nrsol; ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
