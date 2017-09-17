# include <fstream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
ifstream f("dans.in");
ofstream g("dans.out");
vector <int> v[100005],st;
queue <int> q;
int n,m,i,j,viz,v1,v2,nimpar,P,VV,o,t,x,y,dati,nr;
int ap[500005],sol[500005];
void BFS (int k)
{
    int i;
    ap[k]=1;
    q.push(k);
    while (! q.empty())
    {
        ++nr;
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (! ap[v[k][i]])
            {
                ap[v[k][i]]=1;
                q.push(v[k][i]);
            }
        }
    }
}
void euler(int x)
{
    int y;
    st.push_back(x);
    while(st.size())
    {
        x=st.back();
        if(v[x].size())
        {
            y=v[x].back();
            v[x].pop_back();
            st.push_back(y);
            v[y].erase(find(v[y].begin(), v[y].end(), x));
        }
        else
        {
            st.pop_back();
            sol[++VV]=x;
        }
    }
}
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n>>m;
        //curata vectorul
        for (i=1; i<=n; ++i)
            v[i].clear(), ap[i]=0;

        for (i=1; i<=m; ++i)
        {
            f>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        viz=0; VV=0; nimpar=0;
        //numarul impar
        for (i=1; i<=n; ++i)
        {
            if (v[i].size()%2==1)
            {
                ++nimpar;
                if (nimpar==1) v1=i;
                    else if (nimpar==2) v2=i;
            }
        }
        if (nimpar!=0 && nimpar!=2)
        {
            g<<"NU\n";
            continue;
        }
        dati=0;
        //,,conexitatea"
        for (i=1; i<=n; ++i)
            if (! ap[i])
            {
                nr=0;
                BFS(i);
                if (nr>1) ++dati;
            }
        if (dati>1)
        {
            g<<"NU\n";
            continue;
        }
        if (nimpar==0)
        {
            for (i=1; i<=n; ++i)
                if (v[i].size()) {euler (i); break;}
            g<<"DA\n";
            for (i=1; i<=m+1; ++i)
                g<<sol[i]<<" ";
            g<<"\n";
        }
            else if (nimpar==2)
            {
                P=n+1;
                v[P].push_back(v1);
                v[v1].push_back(P);
                v[P].push_back(v2);
                v[v2].push_back(P);
                euler (P);
                g<<"DA\n";
                for (i=2; i<=m+2; ++i)
                    g<<sol[i]<<" ";
                g<<"\n";
            }
    }
    return 0;
}
