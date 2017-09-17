# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("darb.in");
ofstream g("darb.out");
vector <int> v[NR];
int i,j,n,M,I,x,y;
int ap[NR];
void DFS (int k, int N) {
    ap[k]=1;
    if (N > M) M=N, I=k;
    for (auto &x: v[k])
        if (! ap[x]) DFS (x, N+1);
}
int main ()
{
    f>>n;
    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1, 1); memset (ap, 0, sizeof(ap));
    DFS (I, 1);
    g<<M<<"\n";
    return 0;
}
