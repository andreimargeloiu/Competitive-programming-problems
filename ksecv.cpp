# include <cstdio>
# include <vector>
# include <algorithm>
# define NR 100005
using namespace std;
vector <int> v;
int i,j,n,m,x,y,VV,maxx,K,ci,cs;
int a[NR];
void avansare (int k)
{
    while (v.size()<K && VV<n) {
        if (a[VV+1]<=a[k]) ++VV;
        else {
                 ++VV;
                 v.push_back((-1)*a[VV]);
                 push_heap(v.begin(), v.end());
             }
    }
    while (VV<n && a[VV+1]<=a[k]) ++VV;
}
int main ()
{
    freopen ("ksecv.in", "r", stdin);
    freopen ("ksecv.out", "w", stdout);
    scanf ("%d%d", &n, &K);

    for (i=1; i<=n; ++i) scanf ("%d", &a[i]);

    VV=1; avansare (1); ci=1; cs=VV; maxx=VV;

    for (i=2; i<=n; ++i) {
        if (a[i]>a[i-1]) {
            while (v.size() && (-1)*v[0] <= a[i]) {
                pop_heap(v.begin(), v.end());
                v.pop_back();
            }
            avansare (i);
        }
        if (maxx < VV-i+1) ci=i, cs=VV, maxx=VV-i+1;
    }
    printf ("%d %d\n", ci, cs);

    return 0;
}
