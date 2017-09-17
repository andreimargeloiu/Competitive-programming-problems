# include <fstream>
# include <queue>
using namespace std;
ifstream f("ziduri.in");
ofstream g("ziduri.out");
struct elem
{
    short l,c;
}x,y;
queue <elem> q;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int i,j,n,p,var;
int dir[105][105][4],spart[105][105],cost[105][105];
void lee ()
{
    int i,j,la,ca,lv,cv;
    while (!q.empty())
    {
        x=q.front (); q.pop();
        la=x.l; ca=x.c;
        for (i=0; i<4; ++i)
        {
            lv=la+dx[i]; cv=ca+dy[i];
            if (cost[lv][cv])
            {
                if (!dir[la][ca][i])
                {
                    if (cost[la][ca]+1<cost[lv][cv] || (cost[la][ca]+1==cost[lv][cv] && spart[la][ca]<spart[lv][cv]))
                    {
                        cost[lv][cv]=cost[la][ca]+1; spart[lv][cv]=spart[la][ca];
                        y.l=lv; y.c=cv;
                        q.push(y);
                    }
                }
                else {
                         if (cost[la][ca]+p<cost[lv][cv] || (cost[la][ca]+p==cost[lv][cv] && spart[la][ca]+1<spart[lv][cv]))
                         {
                            cost[lv][cv]=cost[la][ca]+p; spart[lv][cv]=spart[la][ca]+1;
                            y.l=lv; y.c=cv;
                            q.push(y);
                         }
                     }
            }
        }
    }
}
int main ()
{
    f>>n>>p;
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            f>>var;
            if (var>=8) var-=8, dir[i][j][0]=1;
            if (var>=4) var-=4, dir[i][j][1]=1;
            if (var>=2) var-=2, dir[i][j][2]=1;
            if (var>=1) var-=1, dir[i][j][3]=1;
            cost[i][j]=99999999;
        }
    }
    cost[1][1]=0; x.l=1; x.c=1;
    q.push(x);
    lee();
    g<<cost[n][n]<<"\n"<<spart[n][n]<<"\n";
    return 0;
}
