# include <cstdio>
using namespace std;
int i,j,n,nrlit,poz,x;
int a[100],prod[100],ap[100];
void procesare ()
{
    int i;
    prod[0]=1;
    for (i=1; i<=nrlit; ++i)
        prod[i]=prod[i-1]*nrlit;
}
int main ()
{
    freopen ("triburi1.in", "r", stdin);
    freopen ("triburi1.out", "w", stdout);
    scanf ("%d%d%d", &n, &nrlit, &poz);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &x);
        ap[x]=1;
    }
    procesare();

    //sa facem numarul
    for (i=1; i<nrlit; ++i)
    {
        if (poz%prod[nrlit-i]==0) a[i]=(poz-1)/(prod[nrlit-i]);
        else a[i]=poz/(prod[nrlit-i]);
        poz-=a[i]*prod[nrlit-i];
        ++a[i];
    }
    a[nrlit]=poz;

    for (i=1; i<=30; ++i)
    {
        if (ap[i])
        {
            for (j=1; j<=nrlit; ++j)
                printf ("%c", (char)(i+a[j]+'A'-2));
            printf ("\n");
        }
    }
    return 0;
}
