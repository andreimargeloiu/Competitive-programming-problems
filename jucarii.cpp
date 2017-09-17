# include <fstream>
# include <cstring>
using namespace std;
ifstream f("jucarii.in");
ofstream g("jucarii.out");
int i,j,n,K,p,nr,st[100],ap[100],val[12],maxx,ok;
void back (int k)
{
    if (ok) return;
    if (k==n+1)
    {
        maxx=0; memset (val,0,sizeof(val));
        for (int i=1; i<=n; ++i)
            for (int j=i+1; j<=n; ++j)
                if (st[j]>st[i]) val[j]=max(val[i]+1,val[j]),maxx=max(maxx,val[j]);
        if (maxx+1>=K)
        {
            if (p==1)
            {
                for (int i=1; i<=n; ++i)
                    g<<st[i]<<" ";
                g<<"\n";
                ok=1;
            }
            else --p;
        }
    }
    else
    {
        for (int i=1; i<=n; ++i)
            if (! ap[i])
            {
                ap[i]=1; st[k]=i;
                back(k+1);
                ap[i]=0;
            }
    }
}
int main ()
{
    f>>n>>K>>p;
    back (1);

    return 0;
}
