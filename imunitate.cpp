# include <fstream>
# include <queue>
# include <cstring>
using namespace std;
ifstream f("imunitate.in");
ofstream g("imunitate.out");
queue <int> q;
int i,j,n,m,o,t,x,y,scosi;
long long VV;
int war[1000005], ap[50][50], viz[1000005], doi[20], bits[1000005];
void init ()
{
    int i,j;
    memset(war,0,sizeof(war));
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            ap[i][j]=0;
}
void calc ()
{
    int i,var;
    doi[0]=1;
    for (i=1; i<=19; ++i)
        doi[i]=2*doi[i-1];
    for (i=1; i<=doi[19]; ++i)
    {
        var=i;
        while (var)
        {
            bits[i]+=var%2;
            var=var/2;
        }
    }
}
void BFS (int k)
{
    int i,act,K;
    viz[k]=o;
    q.push(k);
    while (! q.empty())
    {
        K=q.front(); q.pop();
        k=K; act=bits[K]; scosi=0;
        if (act==1) {++VV; continue;}
        for (i=n; i>=1 && k; --i)
        {
            if (k>=doi[i-1])
            {
                k-=doi[i-1];
                if (bits[K & war[i]]>(act-1)/2)
                {
                    ++scosi;
                    if (viz[K-doi[i-1]]!=o)
                    {
                        viz[K-doi[i-1]]=o;
                        q.push(K-doi[i-1]);
                    }
                }
            }
        }
        if (scosi==0)
        {
            ++VV;
        }
    }
}
int main ()
{
    f>>t;
    calc ();
    for (o=1; o<=t; ++o)
    {
        f>>n>>m;
        init ();
        for (i=1; i<=m; ++i)
        {
            f>>x>>y;
            if (! ap[x][y])
            {
                ap[x][y]=1;
                ap[y][x]=1;
                war[x]+=doi[y-1];
                war[y]+=doi[x-1];
            }
        }
        VV=0;
        BFS (doi[n]-1);
        g<<VV<<"\n";
    }

    return 0;
}
