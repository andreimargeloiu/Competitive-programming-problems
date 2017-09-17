# include <fstream>
# include <cstring>
# include <vector>
# include <queue>
using namespace std;
ifstream f("muzeu.in");
ofstream g("muzeu.out");
struct elem
{
    short l,c;
}x;
queue <elem> q;
vector <elem> v[65000];
int a[252][252],NR[252][252];
int i,j,n,lv,cv,o;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char s[310];
bool ap[65000];
void bfs ()
{
    int la,ca,lv,cv,i,nr;
    elem x,y;
    while (! q.empty())
    {
        x=q.front(); q.pop ();
        la=x.l; ca=x.c;
        nr=(la-1)*n+ca;
        ap[nr]=1;
        for (i=0; i<v[nr].size(); ++i)
        {
            lv=v[nr][i].l; cv=v[nr][i].c;
            if (NR[lv][cv]>NR[la][ca]+1)
            {
                NR[lv][cv]=NR[la][ca]+1;
                ap[(v[nr][i].l-1)*n+v[nr][i].c]=1;
                y.l=lv; y.c=cv;
                q.push(y);
            }
        }
    }
}
int main ()
{
    f>>n; f.get ();
    for (i=1; i<=n; ++i)
    {
        f.getline (s+1,300);
        for (j=1; j<=n; ++j)
        {
            NR[i][j]=999999;
            if (s[j]=='.') a[i][j]=1;
               else if (s[j]=='P')
               {
                  a[i][j]=2;
                  x.l=i; x.c=j;
                  q.push(x);
                  NR[i][j]=0;
               }
        }
    }
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
        {
            for (o=0; o<4; ++o)
            {
                lv=i+dx[o]; cv=j+dy[o];
                if (a[lv][cv]==1)
                {
                    x.l=lv; x.c=cv;
                    v[(i-1)*n+j].push_back(x);
                }
            }
        }

    bfs ();

    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            if (a[i][j]==0) g<<"-2 ";
            else if (NR[i][j]==999999) g<<"-1 ";
            else g<<NR[i][j]<<" ";
        }
        g<<"\n";
    }

    return 0;
}
