# include <fstream>
# include <algorithm>
# define inf 999999999
# define NR 2005
using namespace std;
ifstream f("profit.in");
ofstream g("profit.out");
int i,j,n,minn;
int Da[NR], Db[NR], Ca[NR], Cb[NR], H[NR], a[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>H[i]; a[i]=H[i];
    }
    sort (a+1, a+n+1);

    // mat[i][j] - costul minim ca sa ajungi la stalpul i si sa-l faci de inaltime j,
    //             iar toate anterioarele sa fie mai mici/mari

    //primul element
    for (i=1; i<=n; ++i)
    {
        Da[i]=Ca[i]=abs(H[1]-a[i]);
    }

    for (i=2; i<=n; ++i)
    {
        //crescator
        minn=inf;
        for (j=1; j<=n; ++j)
        {
            minn=min (minn, Ca[j]);
            Cb[j]=abs(H[i] - a[j]) + minn;
        }

        minn=inf;
        for (j=n; j>=1; --j)
        {
            minn=min (minn, Da[j]);
            Db[j]=abs(H[i] - a[j]) + minn;
        }

        for (j=1; j<=n; ++j)
        {
            Ca[j]=Cb[j]; Cb[j]=0;
            Da[j]=Db[j]; Db[j]=0;
        }
    }
    minn=inf;
    for (i=1; i<=n; ++i)
        minn=min (minn, min(Ca[i], Da[i]));

    g<<minn<<"\n";

    return 0;
}
