# include <fstream>
# include <algorithm>
# define N 55
# define NR 505
using namespace std;
ifstream f("calatorie.in");
ofstream g("calatorie.out");
int i,j,n,nk,hk,t,o;
long long minn, X, a[N][NR], inf;
int main ()
{
    f>>t; inf=625e10;
    for (o=1; o<=t; ++o)
    {
        for (i=0; i<N; ++i)
            for (j=0; j<NR; ++j)
                a[i][j]=inf;

        //a[i][j] = numarul de minute parcule cu viteza normala pana la i folosind
        //          exact j minute superviteza
        f>>n; --n;
        if (n==0) {g<<"Consumul minim = 0.\n"; continue;}
        f>>nk>>hk;
        a[1][0]=nk; a[1][hk]=0;
        for (i=2; i<=n; ++i)
        {
            f>>nk>>hk;
            for (j=0; j<NR; ++j)
            {
                if (a[i-1][j]!=inf)
                {
                    a[i][j]=a[i-1][j]+nk;
                }
                if (j>=hk) a[i][j]=min(a[i][j], a[i-1][j-hk]);
            }
        }
        minn=inf;
        for (i=0; i<NR; ++i)
        {
            if (a[n][i]!=inf)
            {
                X=i; X=X*X; X=X*X;
                minn=min(minn, X+a[n][i]);
            }
        }
        g<<"Consumul minim = "<<minn<<".\n";
    }
    return 0;
}
