# include <cstdio>
# include <vector>
# include <algorithm>
# include <queue>
# include <cstring>
using namespace std;
vector <int> v[1005], sol[50005];
queue <int> q;
int i,j,n,m,X,Y,x,y,st,nrsol,act,D1,D2;
int ap[1005],niv[1005],low[1005],drum1[100005],drum2[100005];
bool cost[1005][1005]; //1 daca muchia este critica
bool uz[1005]; //daca sunt in coada
bool luat[1005][1005]; //1 daca am mai trecut pe muchia aia
struct elem
{
    short x,y;
}stiva[100005],var;
void DFS (short k, short nivel, short parinte)
{
    ap[k]=1; niv[k]=nivel; low[k]=nivel;
    for (int i=0; i<v[k].size(); ++i)
    {
        int ok=0;
        if (v[k][i]!=parinte)
        {
            if (ap[v[k][i]]==0)
            {
               var.x=k; var.y=v[k][i];
               stiva[++st]=var; ok=1;
               DFS (v[k][i], nivel+1, k);
            }
            low[k]=min(low[k], low[v[k][i]]);
            if (low[v[k][i]]>=nivel && ok)
            {
                ++nrsol;
                sol[nrsol].push_back(k);
                while (stiva[st].x!=k)
                {
                    sol[nrsol].push_back(stiva[st].y);
                    --st;
                }
                sol[nrsol].push_back(stiva[st].y);
                --st;
            }
        }
    }
}
void bellmanford ()
{
    int i,k;
    ap[X]=1;
    q.push(X);
    while (! q.empty())
    {
        k=q.front (); q.pop();
        uz[k]=0;
        for (i=0; i<v[k].size(); ++i)
        {
            if (ap[k]+cost[k][v[k][i]]<ap[v[k][i]] || ap[v[k][i]]==0)
            {
                ap[v[k][i]]=ap[k]+cost[k][v[k][i]];
                if (uz[v[k][i]]==0) q.push(v[k][i]), uz[v[k][i]]=1;
            }
        }
    }
}
int main ()
{
    freopen ("trip.in", "r", stdin);
    freopen ("trip.out", "w", stdout);
    scanf ("%d%d", &X, &Y);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(X, 1, 0);
    for (i=1; i<=nrsol; ++i)
    {
        if (sol[i].size()==2)
        {
            cost[sol[i][0]][sol[i][1]]=1;
            cost[sol[i][1]][sol[i][0]]=1;
        }
        /*for (j=0; j<sol[i].size(); ++j)
            printf ("%d ", sol[i][j]);
        printf ("\n");*/
    }
    memset (ap, 0, sizeof(ap));
    bellmanford ();
    if (ap[Y]==0)
    {
        printf ("-1\n");
        return 0;
    }
    printf ("%d\n", ap[Y]-1);

    /*
    //primul drum
    act=Y; drum1[++D1]=act;
    while (act!=X)
    {
        for (i=0; i<v[act].size(); ++i)
        {
            if (ap[v[act][i]]==ap[act]-1)
            {
                drum1[++D1]=v[act][i];
                act=v[act][i];
                break;
            }
            if (ap[v[act][i]]==ap[act] && luat[act][v[act][i]]==0)
            {
                drum1[++D1]=v[act][i];
                luat[act][v[act][i]]=1;
                luat[v[act][i]][act]=1;
                act=v[act][i];
                break;
            }
        }
    }
    //al doilea drum
    act=Y; drum2[++D2]=act;
    while (act!=X)
    {
        for (i=0; i<v[act].size(); ++i)
        {
            if (ap[v[act][i]]==ap[act]-1)
            {
                drum2[++D2]=v[act][i];
                act=v[act][i];
                break;
            }
            if (ap[v[act][i]]==ap[act] && luat[act][v[act][i]]==0)
            {
                drum2[++D2]=v[act][i];
                luat[act][v[act][i]]=1;
                luat[v[act][i]][act]=1;
                act=v[act][i];
                break;
            }
        }
    }
    //afisarea
    for (i=D1; i>=1; --i)
        printf ("%d ", drum1[i]);
    printf ("\n");
    for (i=1; i<=D2; ++i)
        printf ("%d ", drum2[i]);
    printf ("\n");
    */
    return 0;
}
