# include <iostream>
# include <fstream>
# include <algorithm>
# define NR 500000
using namespace std;

int i, a[NR], n;
long long A, S;
int main ()
{
    cin>>n>>A;

    for (i=1; i<=n; ++i)
    {
        cin>>a[i]; S=S+a[i];
    }

    if (n==1)
    {
        cout<<a[1]-1<<"\n";
        return 0;
    }

    for (i=1; i<=n; ++i)
    {
        long long nr=0, maxx=0;
        S=S-a[i];

        if (S<A) nr=nr + (A-S-1);

        if (1LL*(n-1+a[i])>A)
        {
            int suma=n-1;
            maxx=A-suma;
            nr=nr + (a[i]-maxx);
        }

        cout<<nr<<" ";
        S=S+a[i];
    }
    cout<<" ";

    return 0;
}
