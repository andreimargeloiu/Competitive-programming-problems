# include <fstream>
# include <queue>
# include <algorithm>
using namespace std;
ifstream f("kdrum.in");
ofstream g("kdrum.out");
struct elem
{
    int l, c, var;
}E;
queue <elem> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int i,j,n,m,k,P,newP,VV,la,ca,lv,cv,xi,yi,xf,yf;
int a[55][55],divizor[205],poz[12005];
short ap[55][55][200];
bool valid (int x, int y)
{
    if (x<1 || x>n || y<1 || y>n) return 0;
        else return 1;
}
int cmmdc (int a, int b)
{
    int R;
    while (b)
    {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
int main ()
{
    f>>n>>m>>k;
    f>>xi>>yi>>xf>>yf;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            f>>a[i][j];
    for (i=1; i<=k; ++i)
        if (k%i==0)
        {
            divizor[++VV]=i;
            poz[i]=VV;
        }
    ap[xi][yi][cmmdc(k,a[xi][yi])]=1;
    E.l=xi; E.c=yi; E.var=poz[cmmdc(k,a[xi][yi])];
    q.push(E);
    while (! q.empty())
    {
        E=q.front(); q.pop();
        la=E.l; ca=E.c; P=E.var;
        for (i=0; i<4; ++i)
        {
            lv=la+dx[i]; cv=ca+dy[i];
            if (valid(lv,cv) && a[lv][cv])
            {
                newP=cmmdc(a[lv][cv]*divizor[P],k);
                if (! ap[lv][cv][poz[newP]])
                {
                    ap[lv][cv][poz[newP]]=ap[la][ca][P]+1;
                    E.l=lv; E.c=cv; E.var=poz[newP];
                    q.push(E);
                }
            }
        }
    }
    g<<ap[xf][yf][poz[k]]<<"\n";

    return 0;
}
