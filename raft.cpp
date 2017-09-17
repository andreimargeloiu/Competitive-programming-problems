# include <fstream>
# include <algorithm>
# define NR 105
# define inf 999999
using namespace std;
ifstream f("raft.in");
ofstream g("raft.out");
int i,j,n,m,x,y,nr,k,ci,cs,minn;
int cost[NR], H[NR];
int maxim (int a, int b, int c)
{
     return max (a, max(b,c));
}
int minim (int a, int b, int c)
{
     return min (a, min(b,c));
}
int main ()
{
    f>>m>>n>>nr;
    for (i=1; i<=nr; ++i)
    {
        f>>y>>x;
        H[y]=max(H[y], x);
    }

    for (i=1; i<=m; ++i)
    {
        cost[i]=minim(cost[i-1]+H[i], cost[i-2]+max(H[i-1], H[i]), cost[i-3]+maxim(H[i-2], H[i-1], H[i]));
    }



    g<<cost[m];

    return 0;
}
