# include <fstream>
# include <cstring>
# include <queue>
# define inf 999999999
using namespace std;
ifstream f("semafoare.in");
ofstream g("semafoare.out");
struct elem
{
    int x, y;
}E;
queue <elem> q;
int i,j,n,m,x,y,X,Y,NR;
int nr[200],dir[10],real[10],t[10][10],a[1005][1005],cost[1005][1005];
char s[1005],ch;
int dx[]={0,-1,0,1,0}, dy[]={0,0,1,0,-1};
void init()
{
    nr['N']=1; nr['E']=2; nr['S']=3; nr['V']=4;
    dir[1]=3; dir[2]=4; dir[3]=1; dir[4]=2;

    real[1]=1; real[2]=2; real[3]=3; real[4]=4; real[5]=1; real[6]=2; real[7]=3; real[8]=4;

    t[1][1]=0; t[1][2]=1; t[1][3]=2; t[1][4]=3;
    t[2][1]=3; t[2][2]=0; t[2][3]=1; t[2][4]=2;
    t[3][1]=2; t[3][2]=3; t[3][3]=0; t[3][4]=1;
    t[4][1]=1; t[4][2]=2; t[4][3]=3; t[4][4]=0;
}
bool intern (int x, int y)
{
    if (x<1 || x>n || y<1 || y>m) return 0;
        else return 1;
}
int timp (int x, int y, int tact, int k) //timpul si directia din care vin
{
    int act;
    act=real[a[x][y]+tact%4];
    return t[act][k]; //cat timp dureaa sa devina din act in k
}
void lee (int la, int ca)
{
    int lv,cv,i,T;
    cost[la][ca]=timp(la,ca,0,NR);
    for (i=1; i<=4; ++i)
        if (i!=NR)
        {
            lv=la+dx[i]; cv=ca+dy[i];
            if (intern(lv,cv) && cost[lv][cv]>cost[la][ca]+1+timp(lv,cv,cost[la][ca]+1,dir[i]));
            {
                cost[lv][cv]=cost[la][ca]+1+timp(lv,cv,cost[la][ca]+1,dir[i]);
                E.x=lv; E.y=cv;
                q.push(E);
            }
        }
    while (! q.empty())
    {
        E=q.front(); q.pop();
        la=E.x; ca=E.y;
        for (i=1; i<=4; ++i)
        {
            lv=la+dx[i]; cv=ca+dy[i];
            if (lv==X && cv==Y)
            {
                if (cost[lv][cv]>cost[la][ca]+1) cost[lv][cv]=cost[la][ca]+1;
            }
            else
            if (intern(lv,cv) && cost[lv][cv]>cost[la][ca]+1+timp(lv,cv,cost[la][ca]+1,dir[i]))
            {
                cost[lv][cv]=cost[la][ca]+1+timp(lv,cv,cost[la][ca]+1,dir[i]);
                E.x=lv; E.y=cv;
                if (cost[lv][cv]<cost[X][Y]) q.push(E);
            }
        }
    }
}
int main ()
{
    init();

    f>>n>>m; ++n; ++m;
    f>>x>>y; f.get(); f>>ch; NR=nr[ch]; ++x; ++y;
    f>>X>>Y; ++X; ++Y; f.get();
    for (i=1; i<=n; ++i)
    {
        f.getline(s, 1005);
        for (j=0; j<m; ++j)
        {
            cost[i][j+1]=inf;
            a[i][j+1]=nr[s[j]];
        }
    }
    lee (x,y);
    g<<cost[X][Y]<<"\n";
    return 0;
}
