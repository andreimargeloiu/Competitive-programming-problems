# include <bits/stdc++.h>
# define NR 1000005
using namespace std;
ifstream f("calancea.in");
ofstream g("calancea.out");
struct elem {
    int poz, H;
}E;
deque <elem> d;
int i,j,n,m,CI;
long long a[NR], K, costACT, sol;
long long adauga (int poz, int I) {
    long long sol=0;
    while (d.size() && a[poz] >= a[d.front().poz]) {
        sol=sol + (a[poz] - a[d.front().poz]) * d.front().H;
        d.pop_front();
    }
    E.poz=poz;
    if (d.size()==0) E.H=I-poz+1;
                else E.H=d.front().poz - poz;
    d.push_front(E);
    return sol;
}
int main ()
{
    f>>n>>K;

    for (i=1; i<=n; ++i)
        f>>a[i];

    // acum vrem sa vedem cate subsecvente se termina pe pozitia i
    CI=n; costACT+=adauga(CI, n);
    for (i=n; i>=1; --i) {
        while (costACT<=K && CI>=1) { //cat timp mai pot adauga
            --CI;
            costACT+=adauga(CI, i);
        }

        E=d.front();
        if (i==CI) {
            sol+=i;
        }

        sol=sol + (i - CI);
        costACT=costACT - (a[d.back().poz] - a[i]); //scad calancea i
        E=d.back();
        --d.back().H; if (d.back().H==0) d.pop_back();
    }
    g<<sol<<"\n";

    return 0;
}
