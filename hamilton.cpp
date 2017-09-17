# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 20
# define inf 999999999
using namespace std;
ifstream f("hamilton.in");
ofstream g("hamilton.out");
struct elem
{
    int y, cost;
}E;
vector <elem> v[NR];
struct elem2
{
    int k, act;
}F;
queue <elem2> q;
int i,j,n,m,x,y,cost,next,k,act,minn,urm;
int C[18][1<<18], drum[NR][NR];
bool ap[18][1<<18];
void hamilton ()
{
    int i, next, final=(1<<n)-1;
    F.k=0; F.act=1; q.push(F);

    while (! q.empty())
    {
        F=q.front(); q.pop();
        k=F.k; act=F.act;
        ap[k][act]=0;

        if (C[k][act]<minn)
        {
            if (act==(1<<n)-1 && drum[k][0]) minn=min(minn, C[k][act]+drum[k][0]);
        }else continue;

        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i].y; cost=v[k][i].cost;
            if (((1<<urm) & act)==0) //verificam daca acest drum contine pe urm
            {
                next=act+(1<<urm);
                if (C[urm][next]==0 || C[urm][next]>C[k][act]+cost)
                {
                    C[urm][next]=C[k][act]+cost;
                    if (! ap[urm][next])
                    {
                        ap[urm][next]=1;
                        F.k=urm; F.act=next;
                        q.push(F);
                    }
                }
            }
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>E.y>>E.cost;
        v[x].push_back(E);
        drum[x][E.y]=E.cost;
    }

    minn=inf;
    hamilton ();

    if (minn==inf) g<<"Nu exista solutie\n";
              else g<<minn<<"\n";

    return 0;
}
