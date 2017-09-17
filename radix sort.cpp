# include <bits/stdc++.h>
# define NR 10000005
using namespace std;
ifstream f("radixsort.in");
ofstream g("radixsort.out");
queue <int> Q[1<<8];
int i,j,n,m,VV,A,B,C,biti,U;
int v[NR];
int mask = (1<<8)-1;
int main ()
{
    f>>n>>A>>B>>C;
    v[1]=B;
    for (i=2; i<=n; ++i)
        v[i]=(1LL * A * v[i-1] + B) % C;

    for (biti=0; biti<32; biti+=8) {
        for (i=1; i<=n; ++i) {
            U = (v[i] >> biti) & mask;
            Q[U].push(v[i]);
        }
        VV=0;
        for (i=0; i<(1<<8); ++i) {
            while (! Q[i].empty()) {
                v[++VV]=Q[i].front();
                Q[i].pop();
            }
        }
    }
    for (i=1; i<=n; i+=10)
        g<<v[i]<<" ";
    g<"\n";

    return 0;
}
