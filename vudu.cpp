# include <iostream>
# include <algorithm>
# define NR 1000005
using namespace std;
int i,j,n,m,P;
int a[NR];
long long S, solutie;
int main ()
{
    cin>>n;
    for (i=1; i<=n; ++i)
        cin>>a[i];
    cin>>P;

    for (i=1; i<=n; ++i) {
        S=0;
        for (j=i; j<=n; ++j) {
            S+=a[j];

            if (S / (j-i+1) >= P) ++solutie;
        }
    }
    cout<<solutie<<"\n";

    return 0;
}
