# include <bits/stdc++.h>
# define NR 1000005
# define LB(p) (p & (-p))
using namespace std;
ifstream f("permsort.in");
ofstream g("permsort.out");
int i,j,n,m,x;
int poz[NR], AIB[NR];
long long sol;
void update (int poz) {
    for (int i=poz; i<=n; i+=LB(i))
        ++AIB[i];
}
int sum (int poz) {
    int sol=0;
    for (int i=poz; i>=1; i-=LB(i))
        sol+=AIB[i];
    return sol;
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>x; poz[x]=i;
    }

    for (i=1; i<=n; ++i) {
        if (poz[i] > poz[i-1])
            sol=sol + (poz[i] - poz[i-1]) - (sum(poz[i]) - sum(poz[i-1]));
        else
            {
                sol=sol + n-(poz[i-1] - poz[i]) - (sum(poz[i])+ (i-1) - sum(poz[i-1]));
            }
        update (poz[i]);
    }
    g<<sol<<"\n";

    return 0;
}
