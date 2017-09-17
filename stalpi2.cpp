# include <cstdio>
# include <algorithm>
# define inf 999999999
# include <deque>
# define Nmax 51
# define Dmax 10001
using namespace std;
deque <int> deq;
int i,j,n,m,x,y,mij,ci,cs,EF,sol;
int d[Dmax], a[Nmax][Dmax];

int verif (int D)
{
    int i,j,ok=1;

    for (i=1; i<=n; ++i)
        for (j=0; j<=d[n]; ++j)
            a[i][j]=inf;
    a[1][0]=0;

    //a[i][j] = efortul minim ca sa mutam primii i stalpi, iar cel de-al i-lea
    //          sa fie la distanta j, si intre ei sa nu fie mai mult de D

    for (i=2; i<=n; ++i)
    {
        deq.clear();
        for (j=0; j<=d[n]; ++j)
        {
            while (! deq.empty() && a[i-1][deq.back()] >= a[i-1][j]) //palmasele
                 deq.pop_back();

            deq.push_back(j);

            if (! deq.empty() && j-deq.front()>D) //expiratele
                 deq.pop_front();

            if (j>d[i] + D)
            {
                j+=0;
            }
            int x=deq.front();
            a[i][j]=abs(d[i]-j) + a[i-1][deq.front()];
        }
    }

    if (a[n][d[n]]<=EF) return 1;
                   else return 0;

}
int main ()
{
    freopen ("stalpi1.in", "r", stdin);
    freopen ("stalpi1.out", "w", stdout);
    scanf ("%d%d", &n, &EF);

    for (i=2; i<=n; ++i)
        scanf ("%d", &d[i]);

    ci=1; cs=d[n];
    while (ci<=cs) //caut binar distanta
    {
        mij=(ci+cs)/2;
        if (verif (mij)) cs=mij-1, sol=mij;
                   else  ci=mij+1;
    }

    printf ("%d\n", sol);

    return 0;
}
