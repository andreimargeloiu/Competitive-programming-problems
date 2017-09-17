# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
# include <cstring>
# define inf 999999999
# define NR 15005
using namespace std;
vector <int> v[15];
queue <int> q;
ifstream f("caini.in");
ofstream g("caini.out");
int i,j,n,m,nrcaini,k,k1,maxx,VV,x,y,cati,locuri,t,nr,start;
int st[100],valid[NR],dusmani[NR],dist[NR],B1[15], B0[15];
void configuratii (int k)
{
    if (k==n+1)
    {
        maxx=max(maxx, nrcaini);
        int nr=0;
        for (int i=1; i<=n; ++i)
            nr=nr + st[i]*(1<<i);

        if (nr==0) return;

        valid[++VV]=nr*10;
        valid[++VV]=nr*10+1;
    }
    else
    {
        //nu e pe mal
        st[k]=0;
        configuratii(k+1);
        //e pe mal
        if (! dusmani[k])
        {
            for (int i=0; i<v[k].size (); ++i)
                ++dusmani[v[k][i]];

            ++nrcaini; st[k]=1;
            configuratii(k+1);
            --nrcaini; st[k]=0;

            for (int i=0; i<v[k].size (); ++i)
                --dusmani[v[k][i]];
        }
    }
}
void biti (int nr, int S[100])
{
    for (int i=1; i<=n; ++i)
        S[i]=nr%2, nr=nr/2;
}
int BFS (int locuri)
{
    int i,j,S,S2; while (! q.empty()) q.pop();
    for (i=1; i<NR-5; ++i) dist[i]=inf;
    q.push(1); dist[1]=0;
    while (! q.empty())
    {
        k=q.front(); q.pop(); biti(k/10, B0);

        for (i=1; i<=VV; ++i) //iau fiecare configuratie sa verific daca din K pot ajunge in K1
        {
            k1=valid[i]; biti(k1/10, B1);
            if (k%10 == k1%10) continue;

            if (dist[k1] > dist[k]+1)
            {
                cati=0;
                for (j=1; j<=n; ++j)
                {
                    S=k & (1<<j); S2=k1 & (1<<j);
                    if (!S && !S2) {cati=999999; break;}
                    if (S == S2) ++cati;
                }
                if (cati <= locuri)
                {
                    dist[k1]=dist[k]+1;
                    if (k1==0) return dist[k1];
                    q.push(k1);
                }
            }
        }
    }
    return -1;
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
    configuratii (1); sort (valid+1, valid+VV+1);
    t=BFS(n-maxx+1);
    if (t!=-1) g<<n-maxx+1<<" "<<t<<"\n";
        else g<<n-maxx+2<<" "<<BFS(n-maxx+2)<<"\n";

    return 0;
}
