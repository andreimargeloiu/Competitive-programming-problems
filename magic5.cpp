# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 55
# define inf 999999999
using namespace std;
ifstream f("magic5.in");
ofstream g("magic5.out");
struct elem
{
    int y, C, F;
}E;
vector <elem> v[NR*NR];
queue <int> q;
int i,j,n,m,x,y,VV,S,D,lv,cv,nod,flux,nrsol,I;
int unu[NR][NR], doi[NR][NR], T[NR*NR], L[NR*NR], col[NR*NR], sol[NR*NR];
char s[NR], a[NR][NR];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool bun (int x, int y)
{
    if (1<=x && x<=n && 1<=y && y<=m) return 1;
                                else  return 0;
}
void muchie (int x, int y, int cap)
{
    E.y=y; E.C=cap; E.F=0;
    v[x].push_back(E);
}
bool BFS ()
{
    int i,k, ok=0;
    memset (T, 0, sizeof(T));
    T[S]=-1; q.push(S);

    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            int urm=v[k][i].y, C=v[k][i].C, F=v[k][i].F;
            if (T[urm]==0 && C>F)
            {
                if (urm==D) ok=1;
                else {
                         T[urm]=k;
                         q.push(urm);
                     }
            }
        }
    }

    return ok;
}
int main ()
{
    f>>n>>m; f.get();
    for (i=1; i<=n; ++i)
    {
        f.getline(s+1, NR);
        for (j=1; j<=m; ++j)
            a[i][j]=s[j];
    }

    // unu - intrare
    // doi -iesire

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i][j]!='x')
            {
                L[VV+1]=i; col[VV+1]=j;
                if (a[i][j]=='M') unu[i][j]=++VV, S=VV;
                if (a[i][j]=='T') unu[i][j]=++VV, D=VV;
                if (a[i][j]=='.') unu[i][j]=++VV;
                if (a[i][j]=='*')
                {
                    unu[i][j]=++VV; doi[i][j]=++VV;
                    L[VV]=i; col[VV]=j;

                    muchie (unu[i][j], doi[i][j], 1);
                    muchie (doi[i][j], unu[i][j], 0);
                }
            }

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            if (a[i][j]!='x')
                for (int o=0; o<4; ++o)
                {
                    lv=i+dx[o]; cv=j+dy[o];
                    if (bun(lv, cv) && a[lv][cv]!='x')
                    {
                        if (a[i][j]=='*') // e loc transformabil
                        {
                            if (a[lv][cv]=='*') //nod dublu
                            {
                                muchie (doi[i][j], unu[lv][cv], inf);
                            }
                            else //un singur nod
                            {
                                muchie (doi[i][j], unu[lv][cv], inf);;
                            }
                        }
                        else { //nod normal
                                 if (a[lv][cv]=='*') //nod dublu
                                 {
                                     muchie (unu[i][j], unu[lv][cv], inf);
                                 }
                                 else //un singur nod
                                 {
                                     muchie (unu[i][j], unu[lv][cv], inf);
                                 }
                             }
                    }
                }
        }

    //fluxul

    while (BFS ())
    {
        for (int i=0; i<v[D].size(); ++i)
        {
            int ant=v[D][i].y, C, F;

            for (int o=0; o<v[ant].size(); ++o)
                if (v[ant][o].y==D)
                {
                    C=v[ant][o].C; F=v[ant][o].F;
                    break;
                }

            if (T[ant]!=0 && C>F)
            {
                int minn=inf;
                T[D]=ant;

                for (nod=D; nod!=S; nod=T[nod])
                {
                    for (int o=0; o<v[T[nod]].size(); ++o)
                        if (v[T[nod]][o].y==nod)
                        {
                            if (minn>v[T[nod]][o].C-v[T[nod]][o].F)
                                minn=v[T[nod]][o].C-v[T[nod]][o].F, I=T[nod];
                            break;
                        }
                }

                if (minn!=1) continue;

                flux+=minn;
                sol[++nrsol]=I;

                for (nod=D; nod!=S; nod=T[nod])
                {
                    for (int o=0; o<v[T[nod]].size(); ++o)
                        if (v[T[nod]][o].y==nod)
                        {
                            v[T[nod]][o].F+=minn;
                            break;
                        }
                    for (int o=0; o<v[nod].size(); ++o)
                        if (v[T[nod]][o].y==T[nod])
                        {
                            v[T[nod]][o].F-=minn;
                            break;
                        }
                }
            }
        }
    }
    g<<flux<<"\n";

    for (i=1; i<=nrsol; ++i)
    g<<L[sol[i]]<<" "<<col[sol[i]]<<"\n";

    /*for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            g<<unu[i][j]<<" ";
        g<<"\n";
    }

     g<<"\n";

    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            g<<doi[i][j]<<" ";
        g<<"\n";
    }

    for (i=1; i<=VV; ++i)
    {
        g<<i<<"  :  ";
        for (j=0; j<v[i].size(); ++j)
            g<<v[i][j].y<<" "<<v[i][j].C<<" , ";

        g<<"\n";
    }*/


    return 0;
}
