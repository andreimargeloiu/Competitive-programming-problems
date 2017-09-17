# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");
int i,j,n,m,ci,cs,VV,poz,I,ant,mij,nrsol;
int a[NR], st[NR], L[NR], sol[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];

    for (i=1; i<=n; ++i) {
        if (a[i] > st[VV]) st[++VV]=a[i], L[i]=VV;
        else {
            ci=1; cs=VV;
            while (ci<=cs) {
                mij=(ci + cs)/2;
                if (a[i]<=st[mij]) cs=mij-1, poz=mij;
                            else   ci=mij+1;
            }
            st[poz]=a[i]; L[i]=poz;
        }
    }
    I=VV+1; ant=st[VV]+1;
    for (i=n; i>=1; --i) {
        if (L[i]==I-1 && ant > a[i]) {
            --I; sol[I]=a[i];
            ant=a[i];
        }
    }

    g<<VV<<"\n";
    for (i=1; i<=VV; ++i)
        g<<sol[i]<<" ";

    return 0;
}
