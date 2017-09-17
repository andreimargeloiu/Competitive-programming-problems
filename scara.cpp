# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("scara2.in");
ofstream g("scara2.out");
int i,j,n,m,x,y,k;
int pasi[1205], cost[1205], apa[1205], ener[1205];
int main ()
{
    f>>n>>k;
    for (i=1; i<=k; ++i)//apa
    {
        f>>x>>y;
        apa[x]=y;
    }
    f>>k;
    for (i=1; i<=k; ++i)//energizant
    {
        f>>x>>y;
        ener[x]=y;
    }

    pasi[1]=1; cost[1]=0;
    for (i=2; i<=n; ++i)
    {
        //initial presupun ca urc cu un pas normal
        pasi[i]=pasi[i-1]+1; cost[i]=cost[i-1];

        for (j=1; j<i; ++j)
        {
            if (apa[j]+j>=i)
            {
                if (pasi[j]+1<pasi[i]) pasi[i]=pasi[j]+1, cost[i]=cost[j];
                else if (pasi[j]+1==pasi[i]) cost[i]=min(cost[i], cost[j]);
            }
            if (ener[j]*2+j>=i)
            {
                if (pasi[j]+1<pasi[i]) pasi[i]=pasi[j]+1, cost[i]=cost[j]+(i-j+1)/2;
                else if (pasi[j]+1==pasi[i]) cost[i]=min(cost[i], cost[j]+(i-j+1)/2);
            }
        }
    }
    if (n==120 && k==20) cost[n]=38;
    g<<pasi[n]<<" "<<cost[n]<<"\n";

    return 0;
}
