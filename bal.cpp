# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;
ifstream f("bal.in");
ofstream g("bal.out");
vector <int> B[100005],F[100005];
struct elem
{
    int nr,tip;
}E;
queue <elem> q;
int i,j,n,m,x,y,ok,ok2,VV,gasit,k,tip,fata,baiat;
int in[100005],out[100005],M1[100005],M2[100005],ap[200005];

int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        B[x].push_back(y);
        F[y].push_back(x);
        ++out[x]; ++in[y];
    }

    for (i=1; i<=n; ++i)
    {
        if (in[i]==0 || out[i]==0) {g<<"NU\n"; return 0;}
        if (out[i]==1) {E.nr=i; E.tip=1; q.push(E);}
        if (in[i]==1) {E.nr=i; E.tip=2; q.push(E);}
    }
    //filtrarea
    while (! q.empty())
    {
        E=q.front(); q.pop();
        k=E.nr; tip=E.tip; ok=1;
        if (tip==1) //baiat
        {
            ap[k]=1; out[k]=0;
            for (i=0; i<B[k].size(); ++i)
            {
                fata=B[k][i];
                if (!ap[n+fata])
                {
                    in[fata]=0; ap[n+fata]=1;
                    M1[k]=fata; M2[fata]=k;
                    for (j=0; j<F[fata].size(); ++j)
                    {
                        --out[F[fata][j]];
                        if (out[F[fata][j]]==1) {E.nr=F[fata][j]; E.tip=1; q.push(E);}
                    }
                }
                --in[fata];
                if (in[fata]==1 && !ap[n+fata]) {ap[n+fata]=1; E.nr=fata; E.tip=2; q.push(E);}
            }
        }
        if (tip==2) //fata
        {
            ap[n+k]=1; in[k]=0;
            for (i=0; i<F[k].size(); ++i)
            {
                baiat=F[k][i];
                if (!ap[baiat])
                {
                    out[baiat]=0; ap[baiat]=1;
                    M1[baiat]=k; M2[k]=baiat;
                    for (j=0; j<B[baiat].size(); ++j)
                    {
                        --in[B[baiat][j]];
                        if (in[B[baiat][j]]==1) {E.nr=B[baiat][j]; E.tip=2; q.push(E);}
                    }
                }
                --out[baiat];
                if (out[baiat]==1 && !ap[baiat]) {ap[baiat]=1; E.nr=baiat; E.tip=1; q.push(E);}
            }
        }
    }

    for (i=1; i<=2*n; ++i)
        VV+=ap[i];

    if (VV!=2*n) {g<<"NU\n"; return 0;}
    else {
            g<<"DA\n";
            for (i=1; i<=n; ++i)
                g<<M1[i]<<"\n";
        }


    return 0;
}
