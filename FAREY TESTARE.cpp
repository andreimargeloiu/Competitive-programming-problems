# include <bits/stdc++.h>
# define NR 5000005
using namespace std;
ifstream f("farey.in");
ofstream g("farey.out");
struct elem {
    int a, b;
    double rap;
}a[NR];
bool cmp (elem x, elem y) {
    return x.rap < y.rap;
}
int i,j,n,m,VV,K;

int cmmdc (int a, int b) {
    int R=0;
    while (b) {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
int main ()
{
    f>>n>>K;
    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j) {
            if (cmmdc (i, j)==1) {
                ++VV;
                a[VV].a=i; a[VV].b=j;
                a[VV].rap=(double)i / j;
            }
        }
    sort (a+1, a+VV+1, cmp);
    g<<a[K].a<<" "<<a[K].b<<"\n";

    return 0;
}
