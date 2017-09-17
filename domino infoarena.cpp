# include <fstream>
# include <vector>
# include <stack>
# include <queue>
using namespace std;
ifstream f("domino.in");
ofstream g("domino.out");
queue <int> q;
struct elem
{
    int e, nr;
}E;
struct piesa
{
    int nr,rot;
}P;
vector <elem> v[15];
vector <piesa> p[15][15];
stack <int> st;
int i,j,n,m,x,y,nrelem,nrsol,nrviz,ok,v1,v2,nrimpar,k,q1,q2;
int sol[50009],viz[50009],ap[50009],nr[15];
void BFS()
{
    int i,k;
    q.push(x);
    ap[x]=1; ++nrviz;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
            if (!ap[v[k][i].e]) {
                                    q.push(v[k][i].e);
                                    ap[v[k][i].e]=1; ++nrviz;
                                }
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>x>>y;
        E.e=y; E.nr=i;
        v[x].push_back(E);
        E.e=x; E.nr=i;
        v[y].push_back(E);

        int rot=0;
        if (x>y) rot=1, swap(x,y);
        P.nr=i; P.rot=rot;
        p[x][y].push_back(P);
    }
    ok=1;
    BFS();
    for (i=0; i<=9; ++i)
        if (v[i].size()!=0) ++nrelem;
    if (nrviz!=nrelem) ok=0;
    v1=-1; v2=-1; nrimpar=0;
    for (i=0; i<=9; ++i)
        if (v[i].size()%2==1) ++nrimpar;
    if (nrimpar!=0 && nrimpar!=2) ok=0;
    g<<ok<<"\n";
    if (!ok) return 0;
    if (nrimpar==2)
    {
        for (i=0; i<=9; ++i)
            if (v[i].size()%2==1)
            {
                if (v1==-1) v1=i;
                    else v2=i;
            }

    }
    if (nrimpar==0)
    {
        for (i=0; i<=9; ++i)
            if (ap[i]==1 && v[i].size()%2==0) v1=i;
    }
        st.push(v1);
        while (! st.empty())
        {
            k=st.top();
            while (v[k].size()!=0 && viz[v[k][v[k].size()-1].nr]==1)
                v[k].pop_back();
            if (v[k].size()==0)
            {
                sol[++nrsol]=k;
                st.pop();
                continue;
            }
            st.push(v[k][v[k].size()-1].e);
            viz[v[k][v[k].size()-1].nr]=1;
        }
        for (i=1; i<=n; ++i)//n+1 varfuri
        {
            int rot=0;
            q1=sol[i]; q2=sol[i+1];
            if (q1>q2) rot=1, swap(q1,q2);
            g<<p[q1][q2][p[q1][q2].size()-1].nr<<" ";
            if (rot==0) g<<p[q1][q2][p[q1][q2].size()-1].rot<<"\n";
                else {
                         if (p[q1][q2][p[q1][q2].size()-1].rot==0) g<<"1\n";
                            else g<<"0\n";
                     }
            p[q1][q2].pop_back();
        }
    return 0;
}
