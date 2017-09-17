# include <fstream>
# include <iostream>
# include <algorithm>
# include <cstring>
# define NR 1000005
using namespace std;
//ifstream f("paplova.in");
//ofstream g("paplova.out");
int i,j,n,m,I,scot;
int ap[NR];
long long X, S;
int main ()
{
    cin>>n>>X;
    if (1LL*(n-1)*(n-2)/2<X) {
        cout<<"-1\n";
        return 0;
    }

    for (i=1; i<=n && S<X; ++i) {
        S+=i; I=i;
    }
    scot=S-X;

    cout<<I+1<<" "; ap[I+1]=1;
    for (i=I; i>=1; --i) {
        if (i==scot) continue;
        else {
            ap[I+1-i]=1;
            cout<<I+1-i<<" ";
        }
    }

    for (i=n; i>=1; --i)
        if (! ap[i]) cout<<i<<" ";

    return 0;
}
