# include <iostream>
# include <algorithm>
using namespace std;
int  i,j,n,k,I,J,Inst,VV,maxx,minn,sol[10000],a[10000];
int main ()
{
    cin>>n>>k;
    for (i=1; i<=n; ++i)
        cin>>a[i];
    if (n==1)
    {
        cout<<"0 0\n";
        return 0;
    }
    for (i=1; i<=k; ++i)
    {
        minn=a[1]; I=1; maxx=0;
        for (j=1; j<=n; ++j)
        {
            if (a[j]<minn) minn=a[j], I=j;
            if (a[j]>maxx) maxx=a[j], J=j;
        }
        if (minn<maxx)
        {
            --a[J]; ++a[I];
            sol[++VV]=J; sol[++VV]=I;
        }
        minn=a[1]; maxx=0;
        for (j=1; j<=n; ++j)
        {
            if (a[j]<minn) minn=a[j], I=j;
            if (a[j]>maxx) maxx=a[j], J=j;
        }
        Inst=maxx-minn;
        if (Inst==0) break;
    }
    cout<<Inst<<" "<<VV/2<<"\n";
    for (i=1; i<=VV-1; i+=2)
        cout<<sol[i]<<" "<<sol[i+1]<<"\n";
    return 0;
}
