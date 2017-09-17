# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("bilete.in");
ofstream g("bilete.out");
int i,n,K,nr[10],x,y,patrate,ok,NR,NR2;
int ap[1000000],st[5];
void back (int k)
{
    int i;
    if (k==K+1)
    {
        NR=0; NR2=0;
        for (i=1; i<=K; ++i)
        {
            x=(st[i]-1)/n+1; y=(st[i]-1)%n+1;
            NR=NR*10+x; NR=NR*10+y;
            nr[i]=x*10+(n-y+1);
        }
        sort (nr+1,nr+K+1);
        for (i=1; i<=K; ++i)
            NR2=NR2*100+nr[i];

        ap[min(NR,NR2)]=1;
    }
    else
    {
        for (i=st[k-1]+1; i<=patrate+k-K; ++i)
        {
            st[k]=i;
            back(k+1);
        }
    }
}
int main ()
{
    f>>n>>K;
    patrate=n*n;
    back(1);
    for (i=1; i<=1000000; ++i)
        if (ap[i]) g<<i<<"\n";
    return 0;
}
