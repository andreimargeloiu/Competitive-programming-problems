# include <fstream>
# include <iomanip>
# include <algorithm>
using namespace std;
ifstream f("scara2.in");
ofstream g("scara2.out");
int i,j,n,m,p,hact,H;
int st[100],ap[100],solmin[100];
double sol[100],minn;
double efort ()
{
    int i,j;
    double var,S;
    for (i=1; i<=n; ++i)
    {
        var=sol[i-1]+st[i];
        S=st[i];
        for (j=i-1; j>=1 && S+st[j]<=m; --j)
        {
            S+=st[j];
            var=min(var,sol[j-1]+S/(i-j+1)+p);
        }
        sol[i]=var;
    }
    return sol[n];
}
void back (int k)
{
    if (k==n+1)
    {
        if (hact==H)
        {
            double ef;
            ef=efort();
            if (ef<minn && minn-ef>0.001)
            {
                minn=ef;
                for (int i=1; i<=n; ++i)
                    solmin[i]=st[i];
            }
        }
    }
    else
    {
        for (int i=1; i<=m && hact+i<=H; ++i)
        {
            if (ap[i]) continue;
            st[k]=i; hact+=i; ap[i]=1;
            back(k+1);
            st[k]=0; hact-=i; ap[i]=0;
        }
    }
}
int main ()
{
    f>>H>>n>>m>>p;
    minn=H*m;
    back(1);
    g<<fixed<<setprecision(2)<<minn<<"\n";
    for (i=1; i<=n; ++i)
        g<<solmin[i]<<" ";
    g<<"\n";
    return 0;
}
