# include <fstream>
using namespace std;
ifstream f("frac.in");
ofstream g("frac.out");
int VV,i,j,nrdiv,nr;
int fact[100005];
long long ci,cs,mij,prod,n,p,var,sol;
struct elem
{
    long long prod;
    int nr;
}E,grup[1000005];
void grupe (int k)
{
    if (k==nrdiv+1)
    {
        if (prod!=1)
        {
            grup[++VV].nr=nr;
            grup[VV].prod=prod;
        }
    }
    else
    {
        //nu il iau
        grupe (k+1);
        //il iau
        prod*=fact[k]; ++nr;
        grupe(k+1);
        prod/=fact[k]; --nr;
    }
}
long long numarare (long long mij)
{
    long long R=0;
    for (int i=1; i<=VV; ++i)
    {
        if (grup[i].nr%2==1) R+=mij/grup[i].prod;
            else R-=mij/grup[i].prod;
    }
    return mij-R;
}
int main ()
{
    f>>n>>p;
    var=n;
    for (i=2; i*i<=var; ++i)
    {
        if (var%i==0)
        {
            fact[++nrdiv]=i;
            while (var%i==0)
                var=var/i;
        }
    }
    if (var!=1) fact[++nrdiv]=var;
    prod=1;
    grupe (1);
    //cautarea binara
    ci=1; cs=1;
    for (i=1; i<=61; ++i)
        cs=cs*2;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (numarare(mij)>=p) sol=mij,cs=mij-1;
            else ci=mij+1;
    }
    g<<sol<<"\n";
    return 0;
}
