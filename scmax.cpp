# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");
int i,j,n,m,ci,cs,mij,poz,VV, nrsol, I;
int a[NR], L[NR], st[NR], sol[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];

    for (i=1; i<=n; ++i)
    {
        if (a[i]>st[VV]) st[++VV]=a[i], L[i]=VV;
        else {
                 ci=1; cs=VV; poz=VV;
                 while (ci<=cs)
                 {
                     mij=(ci+cs)/2;
                     if (st[mij]<a[i]) ci=mij+1;
                                  else cs=mij-1, poz=mij;
                 }
                 st[poz]=a[i]; L[i]=poz;
             }
    }
    I=n+1; a[I]=st[VV]+1; L[I]=VV+1;
    for (i=n; i>=1; --i)
    {
        if (a[i]<a[I] && L[i]==L[I]-1)
        {
            sol[++nrsol]=a[i];
            I=i;
        }
    }

    g<<VV<<"\n";
    for (i=nrsol; i>=1; --i)
        g<<sol[i]<<" ";


    return 0;
}
