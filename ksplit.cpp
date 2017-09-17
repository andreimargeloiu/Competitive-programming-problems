# include <cstdio>
# include <algorithm>
# include <cstdlib>
# define elem 100005
using namespace std;
int i,j,n,m,cap1,cap2,maxelem,nrelem;
long long Smax,Smin,var,maxx;
int a[elem];
struct element
{
    int nr;
    long long val;
}minnladr[elem],maxxladr[elem],minnlast[elem],maxxlast[elem];
int main ()
{
    freopen ("ksplit.in", "r", stdin);
    freopen ("ksplit.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);
    //maximul si minimul la stanga
    Smax=0; cap1=0; Smin=0; cap2=0;
    for (i=1; i<=n; ++i)
    {
        //pt maxim
        if (Smax+a[i]>=a[i]) Smax+=a[i],++cap1;
           else Smax=a[i],cap1=1;
        maxxlast[i].nr=cap1;
        maxxlast[i].val=Smax;
        //pt minim
        if (Smin+a[i]<=a[i]) Smin+=a[i],++cap2;
            else Smin=a[i],cap2=1;
        minnlast[i].nr=cap2;
        minnlast[i].val=Smin;
    }
    //maximul si minimul la dreapta
    Smax=0; cap1=0; Smin=0; cap2=0;
    for (i=n; i>=1; --i)
    {
        //pt maxim
        if (Smax+a[i]>=a[i]) Smax+=a[i],++cap1;
           else Smax=a[i],cap1=1;
        maxxladr[i].nr=cap1;
        maxxladr[i].val=Smax;
        //pt minim
        if (Smin+a[i]<=a[i]) Smin+=a[i],++cap2;
            else Smin=a[i],cap2=1;
        minnladr[i].nr=cap2;
        minnladr[i].val=Smin;
    }
    for (i=1; i<n; ++i)
    {
        var=abs(maxxlast[i].val-minnladr[i+1].val);
        nrelem=maxxlast[i].nr+minnladr[i+1].nr;
        if (var>maxx) maxx=var,maxelem=nrelem;
           else if (var==maxx && nrelem>maxelem) maxelem=nrelem;

        var=abs(minnlast[i].val-maxxladr[i+1].val);
        nrelem=minnlast[i].nr+maxxladr[i+1].nr;
        if (var>maxx) maxx=var,maxelem=nrelem;
           else if (var==maxx && nrelem>maxelem) maxelem=nrelem;
    }
    printf ("%lld\n%d\n", maxx, maxelem);


    return 0;
}
