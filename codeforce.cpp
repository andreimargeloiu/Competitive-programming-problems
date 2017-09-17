# include <iostream>
# include <algorithm>
using namespace std;
int i,j,n,VV;
int a[5005];
int main ()
{
    cin>>n;
    if (n==3)
    {
        cout<<"2\n1 3\n";
    }
    else if (n==2)
    {
        cout<<"1\n1\n";
    }
    else if (n==4)
    {
        cout<<"4\n3 1 4 2\n";
    }
    else
    {
        for (i=1; i<=n; i+=2)
            a[++VV]=i;
        for (i=2; i<=n; i+=2)
            a[++VV]=i;
        cout<<VV<<"\n";
        for (i=1; i<=VV; ++i)
            cout<<a[i]<<" ";
        cout<<"\n";
    }


    return 0;
}
