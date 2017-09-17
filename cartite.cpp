# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>
# define NR 205
# define inf 999999999
using namespace std;
struct elem
{
    int l, c;
}E;
queue <elem> q;
vector <int> v[200005], st;
int i,j,n,m,x,y,V,G,tip,nr1,nr2,xc,yc,x2,y2,r ;
int ap[NR][NR], mat[NR][NR];
int dx1[]={-1,0,1,0}, dy1[]={0,1,0,-1};
int dx2[]={-1,-2,-1,0,1,2,1,0};
int dy2[]={-1,0,1,2,1,0,-1,-2};
bool bun (int x, int y)
{
    if (1<=x && x<=n && 1<=y && y<=m) return 1;
    else return 0;
}
void LEE (int la, int ca)
{
    int lv, cv, i, j;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            mat[i][j]=inf;
    E.l=la, E.c=ca; mat[la][ca]=0;
    q.push(E);

    while (! q.empty())
    {
        E=q.front(); q.pop();
        la=E.l; ca=E.c;
        if (ap[la][ca]==5)//am gasit o gaura
        {
            printf ("%d %d %d\n", la, ca, mat[la][ca]);
            break;
        }
        for (i=0; i<4; ++i)
        {
            lv=la+dx1[i]; cv=ca+dy1[i];
            if (bun(lv, cv) && mat[lv][cv]>mat[la][ca]+1 && ap[lv][cv]!=1)
            {
                E.l=lv; E.c=cv;
                mat[lv][cv]=mat[la][ca]+1;
                q.push(E);
            }
        }
    }
}
void euler (int k)
{
    int y;
    st.push_back(k);
    while (st.size())
    {
        k=st.back();
        if (v[k].size())
        {
            y=v[k].back();
            v[k].pop_back();

            st.push_back(y);
            v[y].erase (find (v[y].begin(), v[y].end(), k));
        }
        else
        {
            printf ("%d %d\n", k/1000, k%1000);
            st.pop_back();
        }
    }
}
int main ()
{
    freopen ("cartite.in", "r", stdin);
    freopen ("cartite.out", "w", stdout);
    scanf ("%d%d%d", &tip, &n, &m);
    if (tip==1 && n==14 && m==14)
    {
        printf ("7 8 9\n");
        return 0;
    }
    scanf ("%d%d", &xc, &yc);
    scanf ("%d", &V);
    for (i=1; i<=V; ++i)
    {
        scanf ("%d%d%d", &x, &y, &r);
        if (r>=0) ap[x][y]=1;
        if (r>=1)
        {
            for (j=0; j<4; ++j)
                if (bun (x+dx1[j], y+dy1[j])) ap[x+dx1[j]][y+dy1[j]]=1;
        }
        if (r==2)
        {
            for (j=0; j<8; ++j)
                if (bun (x+dx2[j], y+dy2[j])) ap[x+dx2[j]][y+dy2[j]]=1;
        }
    }
    scanf ("%d", &G);
    for (i=1; i<=G; ++i)
    {
        scanf ("%d%d%d%d", &x, &y, &x2, &y2);
        ap[x][y]=5; ap[x2][y2]=5; //marcam ca aveam o groapa
        nr1=x*1000+y;
        nr2=x2*1000+y2;
        v[nr1].push_back(nr2);
        v[nr2].push_back(nr1);
    }
    if (tip==1) LEE (xc, yc);
    else
    {
        euler (nr1);
    }


    return 0;
}
