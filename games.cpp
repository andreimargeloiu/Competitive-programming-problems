# include <iostream>
# include <algorithm>
using namespace std;
int i,j,n,a[2500],VV,nr;
int main ()
{
    cin>>n;
    for (i=1; i<=n; ++i)
        cin>>a[i];
    sort (a+1, a+n+1);

    VV=1; nr=a[n];
    for (i=1; i<n; ++i)
        if (a[i]<=nr) ++VV, nr=nr-a[i];

    cout<<VV<<"\n";

    return 0;
}
