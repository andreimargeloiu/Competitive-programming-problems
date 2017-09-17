# include <bits/stdc++.h>
# define NR 200005
using namespace std;
ifstream f("reborn.in");
ofstream g("reborn.out");
vector <int> baga[NR];
int i,j,n,m,Q,x,y,ci,cs,sol;
int lg[NR], rmq[20][2*NR];
void logaritmi () {
    for (int i=2; i<=m; ++i)
        lg[i]=lg[i/2]+1;
}
int main ()
{
    f>>n>>m>>Q; logaritmi ();
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        baga[x].push_back(y);
    }

    for (i=1; i<=n; ++i) {
        rmq[0][i]=i;
        for (auto &x: baga[i])
            rmq[0][i]=max(rmq[0][i], x);
        rmq[0][i]=max(rmq[0][i], rmq[0][i-1]);
    }

    for(i=1; i<=lg[m]; ++i)
        for (j=1; j<=n; ++j)
            rmq[i][j]=max(rmq[i-1][j], rmq[i-1][rmq[i-1][j]]);

    //incepem sa facem query-urile
    for (i=1; i<=Q; ++i) {
        f>>ci>>cs; if (ci > cs) swap(ci, cs);
        if (ci==cs) {
            g<<"0\n";
            continue;
        }
        sol=0;

        for (j=lg[m]; j>=0; --j) {
            if (rmq[j][ci] < cs) {
                sol+=(1<<j);
                ci=rmq[j][ci];
            }
        }
        if (rmq[0][ci] >= cs) ++sol;
                         else sol=-1;
        g<<sol<<"\n";
    }

    return 0;
}
