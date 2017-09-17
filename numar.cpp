# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,VV,maxx,nr,ci,cs,mij,sol;
int a[105];
long long prod;
struct elem
{
    int nr, prod;
}E,numitor[10005];
void back(int k)
{
    if (k<=n)
    {
        if (k==n)
        {
            VV+=0;
        }
        //nu il iau
        back(k+1);
        //il iau
        prod=prod*a[k];
        if (prod<=maxx)
        {
            ++nr;
            numitor[++VV].nr=nr; numitor[VV].prod=prod;
            back(k+1);
            --nr;
        }
        prod=prod/a[k];
    }
}
int numarare (int k)
{
    int R=0;
    for (int i=1; i<=VV; ++i)
    {
        if (numitor[i].nr%2==1) R+=k/numitor[i].prod;
            else R-=k/numitor[i].prod;
    }
    return R;
}
int main ()
{
    freopen ("numar2.in", "r", stdin);
    freopen ("numar2.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);
    maxx=m*a[1]; prod=1;
    back(1);
    //coutarea binara
    ci=1; cs=maxx;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (numarare(mij)>=m) cs=mij-1,sol=mij;
           else ci=mij+1;
    }

    printf ("%d\n", sol);
    return 0;
}
