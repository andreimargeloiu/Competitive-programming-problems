# include <fstream>
# include <algorithm>
# include <iostream>
# define NR 30
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
struct elem {
    int nr, party;
}a[NR];
bool cmp (elem x, elem y) {
    return x.nr < y.nr;
}
int i,j,n,m,cnt,T;
int main ()
{
    f>>T; int cnt=0;
    while (T--) {
        ++cnt;
        f>>n;
        for (int i=1; i<=n; ++i) {
            f>>a[i].nr; a[i].party='A' + i - 1;
        }
        sort (a+1, a+n+1, cmp);

        g<<"Case #"<<cnt<<": ";

        while (a[n].nr > a[n-1].nr) {
            g<<(char)(a[n].party)<<" ";
            --a[n].nr;
        }

        for (int i=1; i<=n-2; ++i) {
            while (a[i].nr) {
                g<<(char)(a[i].party)<<" ";
                --a[i].nr;
            }
        }

        while (a[n].nr) {
            g<<(char)(a[n].party)<<(char)(a[n-1].party)<<" ";
            --a[n].nr;
        }

        g<<"\n";
    }

    return 0;
}
