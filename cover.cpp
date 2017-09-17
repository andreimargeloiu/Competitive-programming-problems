# include <bits/stdc++.h>
# define NR 1000005
using namespace std;
deque <int> d;
struct elem {
    int ci, cs;
}a[100005];
bool cmp (elem x, elem y) {
    if (x.cs!=y.cs) return x.cs < y.cs;
               else return x.ci > y.ci;
}
int i,j,n,m,last,VV,L,minn;
int C[NR], cost[NR];
int main ()
{
    freopen ("cover.in", "r", stdin);
    freopen ("cover.out", "w", stdout);
    scanf ("%d%d", &n, &L);
    for (i=1; i<=L; ++i)
        scanf("%d", &cost[i]);

    for (i=1; i<=n; ++i)
        scanf ("%d%d", &a[i].ci, &a[i].cs);
    sort (a+1, a+n+1, cmp);
    last=0;
    for (i=1; i<=n; ++i)
        if (last < a[i].ci) {// nu e redundatn
            a[++VV]=a[i];
            last=a[i].ci;
        }

    // C[i]-costul minim pentru a aveam toate intervalele sfarsit inainte de i luate
    //      si punctul i
    d.push_back(0); last=0;
    for (i=1; i<=L; ++i) {
        C[i]=cost[i] + C[d.front()];

        // bagam acest cost in deque
        while (! d.empty () && C[i] <= C[d.back()])
            d.pop_back();
        d.push_back(i);

        while (a[last+1].cs==i) ++last; //daca aici de termina un interval

        while (! d.empty() && d.front() < a[last].ci)
            d.pop_front();
    }
    minn=C[a[VV].cs];
    for (i=a[VV].ci; i<=a[VV].cs; ++i)
        minn=min(minn, C[i]);
    printf ("%d\n", minn);

    return 0;
}
