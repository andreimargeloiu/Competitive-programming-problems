# include <fstream>
# include <algorithm>
# define N_Max 2100000
using namespace std;
ifstream f("sume.in");
ofstream g("sume.out");
int nr[N_Max+5],a[50005];
long long k,NR;
int n,maxx,ci,cs,mij,var,sol;
int main ()
{
    f>>n>>k;
    int i,j;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        ++nr[a[i]];
        if (a[i]>maxx) maxx=a[i];
    }
    sort (a+1,a+n+1);
    for (i=1; i<=N_Max; ++i)
        nr[i]+=nr[i-1];

    ci=1; cs=2*maxx;
    while (ci<=cs)
    {
        mij=(ci+cs)/2; NR=0;
        for (i=1; i<=n && a[i]<=mij; ++i)
            NR=NR+nr[mij-a[i]];
        if (NR>=k) cs=mij-1,sol=mij;
            else ci=mij+1;
    }
   g<<sol<<"\n";
    return 0;
}
