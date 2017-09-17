# include <iostream>
# include <algorithm>
using namespace std;
int a[5],minn,VV;
int verificare ()
{
    if (a[1]+a[2]+a[3]<3) return 0;
    if (a[1]+a[2]+a[3]==a[3]) return 0;
    if (a[1]!=a[2] || a[1]!=a[3] || a[2]!=a[3]) return 1;
    return 0;
}
int main()
{
    cin>>a[1]>>a[2]>>a[3];
    sort (a+1,a+3+1);
    while (verificare())
    {
        minn=min(a[2]-a[1],(a[3]-a[1])/2);
        minn=max(minn,1);
        a[2]=a[2]-minn; a[3]=a[3]-minn*2;
        VV+=minn;
        sort (a+1,a+3+1);
    }
    VV+=a[1];
    cout<<VV<<"\n";
    return 0;
}
