# include <fstream>
# include <vector>
# include <cstring>
# include <algorithm>
using namespace std;
ifstream f("plan.in");
ofstream g("plan.out");
vector <int> v[300], vt[300], componenta[300], tare[300], tareT[300];
int i,j,n,m,x,y,VV,GA,GV,nrx,nry,o,ok,vx,vy,R,Q,adaos;
int ap[300],st[300],drum[300][300],grupa[300],X[300],Y[300],in[300],out[300],luatX[300],luatY[300];
struct elem
{
    int x, y;
}G[300];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
    st[++VV]=k;
}
void DFSt (int k)
{
    ap[k]=0; componenta[VV].push_back(k); grupa[k]=VV;
    for (int i=0; i<vt[k].size(); ++i)
        if (ap[vt[k][i]]) DFSt (vt[k][i]);
}
void DFSsearch (int k)
{
    for (int i=0; i<tareT[k].size() && ok; ++i)
    {
        if (!in[tareT[k][i]] && !luatX[tareT[k][i]]) {ok=0; R=tareT[k][i]; luatX[R]=1; break;}
        DFSsearch(tareT[k][i]);
    }
}
void desc()
{
    int i,j;
    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS(i);
    VV=0;
    for (i=n; i>=1; --i)
        if (ap[st[i]]==1)
        {
            ++VV;
            DFSt(st[i]);
        }
    /*for (i=1; i<=VV; ++i)
    {
        for (j=0; j<componenta[i].size(); ++j)
            g<<componenta[i][j]<<" ";
        g<<"\n";
    }*/
}
void drumuri ()
{
    int i,j;
    for (i=1; i<=n; ++i)
    {
        GA=grupa[i];
        for (j=0; j<v[i].size(); ++j)
        {
            GV=grupa[v[i][j]];
            drum[GA][GV]=1;
        }
    }
    //fac arcele dintre comp tare conexe
    for (i=1; i<=VV; ++i)
        for (j=1; j<=VV; ++j)
            if (i!=j && drum[i][j])
            {
                tare[i].push_back(j);
                tareT[j].push_back(i);
                ++out[i]; ++in[j];
            }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        if (x==y) continue;
        v[x].push_back(y);
        vt[y].push_back(x);
    }
    desc ();//descompunere tare conexe

    if (VV<=1)
    {
        g<<"0\n";
        return 0;
    }
    //X- cu in=0;
    //Y- cu out=0;

    drumuri ();//fac drumurile intre componentale tare conexe

    //le partitionez in multimi
    for (i=1; i<=VV; ++i)
    {
        if (in[i]==0) X[++nrx]=i, vx=i;
        if (out[i]==0) Y[++nry]=i, vy=i;
    }

    adaos=0;
    for (o=1; o<=min(nrx,nry)+adaos; ++o)
    {
        R=0; ok=1;
        DFSsearch (Y[o]);
        if (R!=0)
        {
            ++Q;
            G[Q].y=Y[o]; G[Q].x=R;
            luatY[Y[o]]=1;
        }
        else ++adaos;
    }

    //incepe afisarea
    g<<max(nrx, nry)<<"\n";
    for (i=1; i<min(nrx,nry); ++i)
    {
        g<<componenta[G[i].y][0]<<" "<<componenta[G[i+1].x][0]<<"\n";
    }
    g<<componenta[G[min(nrx,nry)].y][0]<<" "<<componenta[G[1].x][0]<<"\n";

    if (nrx>nry)
    {
        for (i=nry+1; i<=nrx; ++i)
        {
            for (j=1; j<=nrx; ++j)
            {
                if (!luatX[X[j]])
                {
                    luatX[X[j]]=1;
                    g<<componenta[vy][0]<<" "<<componenta[X[j]][0]<<"\n";
                    break;
                }
            }
        }
    }
    else
    {
        for (i=nrx+1; i<=nry; ++i)
        {
            for (j=1; j<=nry; ++j)
            {
                if (!luatY[Y[j]])
                {
                    luatY[Y[j]]=1;
                    g<<componenta[Y[j]][0]<<" "<<componenta[vx][0]<<"\n";
                    break;
                }
            }
        }
    }

    return 0;
}
