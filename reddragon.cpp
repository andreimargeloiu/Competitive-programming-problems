# include <bits/stdc++.h>
# define NR 100005
using namespace std;
//ifstream f("test.in");
//ofstream g("test.out");
struct elem {
    int val, poz;
}a[NR];
bool cmp (elem x, elem y) {
    return x.val > y.val;
}

int maxx,i,j,n;
int lg[NR];

void logaritmi () {
    for (int i=2; i<=n; ++i)
        lg[i]=lg[i/2]+1;
}
int suma (int i, int j) {
    return a[i].val + a[j].val - lg[abs(a[i].poz - a[j].poz)];
}
int main ()
{
    cin>>n; logaritmi ();
    for (i=1; i<=n; ++i) {
        cin>>a[i].val; a[i].poz=i;
    }
    sort (a+1, a+n+1, cmp);

    maxx=suma (1, 2);

    for (i=1; i<=n; ++i) {
        for (j=i+1; j<=n && maxx-suma(i, j) <= 20; ++j) {
            maxx=max(maxx, suma(i, j));
        }
    }
    cout<<maxx<<"\n";

    return 0;
}
