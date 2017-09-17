# include <fstream>
# include <iostream>
# include <algorithm>
# define NR 50005
using namespace std;
ifstream f("div7.in");
ofstream g("div7.out");
int i,j,n,m,maxx,r;
long long S[NR], a[NR];
int R[10];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>a[i];
        S[i]=S[i-1] + a[i];


        r=S[i]%7LL;
        if (R[r]) maxx=max(maxx, i-R[r]);
        else R[r]=i;
    }
    g<<maxx<<"\n";


    return 0;
}
