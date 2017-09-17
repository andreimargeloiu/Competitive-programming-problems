# include <algorithm>
# include <fstream>
# include <vector>
# define NR 100005
# define inf 999999999
using namespace std;
ifstream f("ecluze.in");
ofstream g("ecluze.out");
int i,j,n,m,Inou,I,VV,minn,minn2;
int a[NR], ap[NR], cost[NR], var[NR];
void procesare ()
{
    for (i=1; i<=NR; ++i)
        if (ap[i]) {++VV; ap[i]=VV;}

    for (i=1; i<=n; ++i)
        a[i]=ap[a[i]];
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        ap[a[i]]=1;
    }
    procesare ();

    for (i=1; i<=VV; ++i)
        cost[i]=inf;

    cost[a[1]]=0; minn=0; var[++I]=a[1];
    // cost[i]=costul minim de a aduce pozitia la costul i
    for (i=2; i<=n; ++i)
    {
        minn2=inf;
        if (cost[a[i]]==inf) var[++I]=a[i];
        for (j=1; j<=I; ++j)
        {
            if (a[i]==var[j]) //aduc ant la valoarea actuala
                cost[var[j]]=min(minn+1, cost[var[j]]);
            else //mut actuala la alta valoare
                ++cost[var[j]];
            minn2=min(minn2, cost[var[j]]);
        }
        Inou=0;
        for (j=1; j<=I; ++j)
            if (cost[var[j]]==minn2) var[++Inou]=var[j];
                                else cost[var[j]]=inf;
        I=Inou; minn=minn2;
    }

    g<<minn<<"\n";

    return 0;
}
