# include <fstream>
# include <algorithm>
# include <queue>
# define NR 105
# define inf 999999999
using namespace std;
ifstream f("waterlogic.in");
ofstream g("waterlogic.out");
struct elem
{
    int x,y,z;
}E,F;
queue <elem> q;
int X,Y,Z,xf,yf,zf,x,y,z,n,i,j,k,A,B,C;
int pasi[NR][NR][NR];
void adauga (int a, int b, int c)
{
    if (pasi[a][b][c]>pasi[x][y][z]+1)
    {
        pasi[a][b][c]=pasi[x][y][z]+1;

        F.x=a; F.y=b; F.z=c; q.push(F);
    }
}
void BFS ()
{
    int m;
    pasi[0][0][0]=0;
    while (! q.empty())
    {
        E=q.front(); q.pop ();
        x=E.x; y=E.y; z=E.z;

        // umplem
        if (x<X) adauga (X, y, z);
        if (y<Y) adauga (x, Y, z);
        if (z<Z) adauga (x, y, Z);

        //golim
        if (x>0) adauga (0, y, z);
        if (y>0) adauga (x, 0, z);
        if (z>0) adauga (x, y, 0);

        //mutam dintr-un pahar
        if (x)
        {
            if (y<Y) {m=min(x, Y-y); adauga (x-m, y+m, z);}
            if (z<Z) {m=min(x, Z-z); adauga (x-m, y, z+m);}
        }
        if (y)
        {
            if (x<X) {m=min(y, X-x); adauga (x+m, y-m, z);}
            if (z<Z) {m=min(y, Z-z); adauga (x, y-m, z+m);}
        }
        if (z)
        {
            if (x<X) {m=min(z, X-x); adauga (x+m, y, z-m);}
            if (y<Y) {m=min(z, Y-y); adauga (x, y+m, z-m);}
        }
    }
}
int main ()
{
    f>>n;
    if (n==1) f>>X>>xf;
    if (n==2) f>>X>>Y>>xf>>yf;
    if (n==3) f>>X>>Y>>Z>>xf>>yf>>zf;

    E.x=0; E.y=0; E.z=0; q.push(E);

    //init
    for (i=0; i<=100; ++i)
        for (j=0; j<=100; ++j)
            for (k=0; k<=100; ++k)
                pasi[i][j][k]=inf;
    BFS ();

    if (pasi[xf][yf][zf]!=inf) g<<pasi[xf][yf][zf]<<"\n";
                          else g<<"-1\n";

    return 0;
}
