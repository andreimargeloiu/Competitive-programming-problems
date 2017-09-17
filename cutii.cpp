# include <fstream>
# include <algorithm>
# define NR 4000
# define LB(p) ((p)&(-p))
using namespace std;
ifstream f("cutii.in");
ofstream g("cutii.out");
struct elem {
    int x,y,z;
}a[NR];
bool cmp (elem x, elem y) {
    if (x.z >= y.z) return 0;
               else return 1;
}
int i,j,n,m,x,solutie,maxx,T;
int AIB[NR][NR];
int query (int X, int Y) {
    int maxx=0;
    for (int i=X; i>=1; i-=LB(i))
        for (int j=Y; j>=1; j-=LB(j))
            maxx=max(maxx, AIB[i][j]);
    return maxx;
}
void update (int X, int Y, int val) {
    for (int i=X; i<=n; i+=LB(i))
        for (int j=Y; j<=n; j+=LB(j))
            AIB[i][j]=max(AIB[i][j], val);
}
void clean ()
{
    for (int o=1; o<=n; ++o)
        for (int i=a[o].x; i<=n; i+=LB(i))
            for (int j=a[o].y; j<=n; j+=LB(j))
                AIB[i][j]=0;
}
int main ()
{
    f>>n>>T;
    for (int t=1; t<=T; ++t) {
        for (i=1; i<=n; ++i)
            f>>a[i].x>>a[i].y>>a[i].z;
        sort (a+1, a+n+1, cmp);
        solutie=0;
        for (i=1; i<=n; ++i) {
            maxx=query (a[i].x, a[i].y);
            update (a[i].x, a[i].y, maxx+1);
            solutie=max(solutie, maxx+1);
        }

        clean ();
        g<<solutie<<"\n";
    }

    return 0;
}
