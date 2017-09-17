# include <fstream>
# include <queue>
# include <vector>
# include <bitset>
# define inf 999999999
using namespace std;
ifstream f("zmeu2.in");
ofstream g("zmeu2.out");
vector <short> v[205];
struct elem
{
    short nod, timp, capete;
}E;
queue <elem> q;
struct elem2
{
    short timp, cap;
}a[205];
int i,j,n,m,x,y,k,p,minn,T,C,cap,suma,VV;
bitset <205> ap[205];
void BF (int k)
{
    int i; minn=inf;

    E.nod=1; E.timp=a[1].timp; E.capete=cap-a[1].cap;

    q.push(E);
    while (! q.empty())
    {
        E=q.front(); q.pop();
        k=E.nod; T=E.timp; C=E.capete;
        if (k==p && T<minn) minn=T;
        for (i=0; i<v[k].size(); ++i)
        {
            if (C-a[v[k][i]].cap>0)
            {
                E.nod=v[k][i]; E.timp=T+a[v[k][i]].timp; E.capete=C-a[v[k][i]].cap;

                if (E.timp>=minn || E.timp>suma) continue;
                else
                {
                    ++VV;
                    if (VV>p*p-k) break;
                    q.push(E);
                }
            }
        }
    }
}
int main ()
{
    f>>cap>>p>>k;
    for (i=1; i<=p; ++i)
    {
        f>>a[i].timp>>a[i].cap;
        suma+=a[i].timp;
    }

    for (i=1; i<=k; ++i)
    {
        f>>x>>y;
        ap[x][y]=1;
    }
    for (i=1; i<p; ++i)
    {
        for (j=2; j<=p; ++j)
        {
            if (ap[i][j]) continue;
            if (i==j) continue;
            if (i==1 && j==p) continue;
            v[i].push_back(j);
        }
    }
    BF (1);
    if (minn==inf) g<<"-1\n";
       else g<<minn<<"\n";
    return 0;
}
