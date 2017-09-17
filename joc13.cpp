# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,x,poz1,poz2,scor1,scor2;
int a[1045];
int next (int now, int P)
{
    now+=P;
    if (now>n) now=now-n;
    return now;
}
void afisare (int k)
{
    printf ("%d\n", k);
    printf ("%d %d\n", poz1, scor1);
    printf ("%d %d\n", poz2, scor2);
}
int main ()
{
    freopen ("joc13.in", "r", stdin);
    freopen ("joc13.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);
    scanf ("%d", &m);
    poz1=poz2=1;
    for (i=1; i<=m; ++i)
    {
        scanf ("%d", &x);
        if (i%2==1) //primul jucator
        {
            poz1=next(poz1, x);
            if (poz1==1 && scor1!=0) {++scor1; afisare (1); return 0;}
            if (a[poz1]==0 || (poz1==poz2 && poz1!=1)) {poz1=1, scor1=0; continue;}
            if (a[poz1]==1) {++scor1; continue;}
            if (a[poz1]==10) {scor1+=10; continue;}
        }
        else { //al doilea jucator
                poz2=next(poz2, x);
                if (poz2==1 && scor2!=0) {++scor2; afisare (2); return 0;}
                if (a[poz2]==0 || (poz1==poz2 && poz1!=1)) {poz2=1, scor2=0; continue;}
                if (a[poz2]==1) {++scor2; continue;}
                if (a[poz2]==10) {scor2+=10; continue;}
             }
    }
    if (scor1>scor2) {afisare (1); return 0;}
    if (scor1<scor2) {afisare (2); return 0;}
    if (scor1==scor2 && poz1>=poz2) afisare (1);
        else afisare (2);

    return 0;
}
