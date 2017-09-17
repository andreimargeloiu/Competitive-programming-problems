# include <fstream>
using namespace std;
ifstream f("efort.in");
ofstream g("efort.out");
int i,j,n,m,K,x,dist;
long long fib[20000],VV;
void fibonacci ()
{
    int k=1;
    fib[0]=1; fib[1]=2;
    while (fib[k]+fib[k-1]<2000000000)
        fib[++k]=fib[k-1]+fib[k-2];
}
int main ()
{
    f>>n>>K;
    fibonacci ();
    for (i=1; i<=n; ++i)
    {
        f>>x;
        dist+=x;
        if (dist>=K)
        {
            VV=VV+K;
            for (j=1; j<=dist-K; ++j)
                VV+=fib[j];
            dist=0;
        }
    }
    g<<VV+dist<<"\n";


    return 0;
}
