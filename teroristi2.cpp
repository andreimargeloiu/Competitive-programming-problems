# include <fstream>
# include <algorithm>
# include <queue>
# define NR 4010000
using namespace std;
ifstream f("teroristi2.in");
ofstream g("teroristi2.out");
struct elem
{
    int x, y;
}a[150*150];
queue <int> q;
int i,j,n,k,m,mod,x,y,K;
int nr[NR], in[NR], nec[NR], luat[150];
bool ap[NR];
void BFSgapdan ()
{
    int i,urm;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=1; i<=K; ++i)
        {
            if (((1<<i) & k)==0) //daca nu apare in stare
            {
                if ((nec[i] & k)==nec[i])
                {
                    urm=k+(1<<i);

                    nr[urm]=(nr[urm]+nr[k])%mod;

                    if (! ap[urm])
                    {
                        ap[urm]=1;
                        q.push(urm);
                    }
                }
            }
        }
    }
}
int main ()
{
    f>>n>>m>>mod;
    for (i=1; i<=m; ++i)
    {
        f>>a[i].x>>a[i].y;
        luat[a[i].x]=luat[a[i].y]=1;
    }
    for (i=1; i<=n; ++i)
        if (luat[i]) {++K; luat[i]=K;}

    for (i=1; i<=m; ++i)
    {
        int x=a[i].x, y=a[i].y;
        nec[luat[y]]+=(1<<luat[x]); ++in[luat[y]];
    }

    for (i=1; i<=n; ++i)
        if (luat[i] && ! in[luat[i]])
        {
            nr[(1<<luat[i])]=1;
            q.push((1<<luat[i]));
        }
    BFSgapdan();

    int VV=K+1, sol=nr[(1<<(K+1))-2];

    for (i=1; i<=n-K; ++i)
    {
        sol=1LL*sol*VV%mod;
        ++VV;
    }
    g<<sol<<"\n";


    return 0;
}
