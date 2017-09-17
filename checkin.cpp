# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("checkin.in");
ofstream g("checkin.out");
int i,j,n,m,ci,cs,mij,mini,minn,VV,S,copii,bagaje,ok;
int a[1005], b[1005], var[1005];
int verificare (int timp)
{
    int i;
    VV=0; S=0;
    for (i=1; i<=n; ++i)
        if (timp>b[i]) var[++VV]=(timp-b[i])/a[i];

    sort (var+1,var+VV+1);
    for (i=VV; i>=max(1,VV-copii+1); --i)
        S+=var[i];
    if (S>=bagaje) return 1;
        else return 0;
}
int main ()
{
    f>>n; mini=1000000;
    for (i=1; i<=n; ++i)
    {
        f>>a[i]>>b[i];
        mini=min(mini,b[i]);
    }
    f>>copii>>bagaje;
    copii=min(copii,n);
    if (bagaje==0)
    {
        g<<mini<<"\n";
        return 0;
    }
    ci=1; cs=bagaje*a[1]+b[1];
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (verificare(mij)) minn=mij, cs=mij-1;
           else ci=mij+1;
    }
    g<<minn<<"\n";

    return 0;
}
