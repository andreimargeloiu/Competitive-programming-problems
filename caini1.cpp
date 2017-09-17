# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
# include <cstring>
# define inf 999999999
# define NR 25005
using namespace std;
vector <int> v[15];
queue <int> q;
ifstream f("caini.in");
ofstream g("caini.out");
int i,j,n,m,nrcaini,k,k1,maxx,VV,x,y,cati,locuri,t,nr,start, Start1, Start0, MAX, Mal, NEXT;
int st[100], valid[NR], dusmani[NR], D[NR], B1[15], B0[15];
void configuratii (int k)
{
    if (k==n+1)
    {
        maxx=max(maxx, nrcaini);
        int nr=0;
        for (int i=1; i<=n; ++i)
            nr=nr + st[i]*(1<<i);

        valid[++VV]=nr;
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
        if (nr & (1<<i)) S[i]=1;
                    else S[i]=0;
}
//trebuie sa facem dinamica, astfel incat sa tinem minte in dist[i] - distanta pana la configuratia i, care
//este pe partea opusa malului unde e Seful
int BFS (int locuri)
{
    int i,j,S,S2,ACT,URM,k,k1;
    for (i=0; i<NR-5; ++i) D[i]=inf;

    q.push(Start0); D[Start0]=0;

    while (! q.empty())
    {
        k=q.front(); q.pop();

        Mal=1-(k%10); ACT=MAX ^ (k/10); biti(ACT, B0);

        for (i=1; i<=VV; ++i) {
            URM=valid[i]; biti(URM, B1); NEXT=URM*10+Mal;

            if (D[NEXT] > D[k] + 1) {

                int T=0;

                for (int j=1; j<=n; ++j) {
                    if (B0[j] && !B1[j]) ++T;
                    if (B1[j] && !B0[j]) {T=inf; break;}
                }

                if (T<locuri) {
                    D[NEXT]=D[k] + 1;
                    q.push(NEXT);
                }
            }
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
    //facem configuratiile valide ale unui mal unde nu se afla Seful
    configuratii (1); sort (valid+1, valid+VV+1);

    Start0=1;
    Start1=0;

    MAX=(1<<(n+1))-2;

    BFS(n-maxx+1);
    if (D[Start1]!=inf) g<<n-maxx+1<<" "<<D[Start1]<<"\n";
    else
    {
        BFS(n-maxx+2);
        g<<n-maxx+2<<" "<<D[Start1]<<"\n";
    }

    return 0;
}
