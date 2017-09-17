# include <cstdio>
# include <vector>
using namespace std;
vector <int> v[100005];
int i,j,n,m,frunze,cicluri,mutari,nod,inceput,sfarsit;
int ap[100005], a[100005], copie[100005], gi[100005];
int main ()
{
    freopen ("telefon.in", "r", stdin);
    freopen ("telefon.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &a[i]);
        copie[i]=a[i];
        ++gi[a[i]];
    }
    //unesc bucatile fara cicluri
    for (i=1; i<=n; ++i)
    {
        if (! ap[i] && ! gi[i])
        {
            ++frunze;
            nod=i; ap[i]=1;
            while (! ap[a[nod]])
            {
                nod=a[nod];
                ap[nod]=1;
            }
            if (inceput==0) inceput=i;
            if (sfarsit==0) sfarsit=nod;

            a[nod]=inceput;
            inceput=i;
        }
    }
    //unesc ciclurile
    for (i=1; i<=n; ++i)
    {
        if (! ap[i])
        {
            ++cicluri;
            nod=i; ap[i]=1;
            while (! ap[a[nod]])
            {
                nod=a[nod];
                ap[nod]=1;
            }
            if (inceput==0) inceput=i;
            if (sfarsit==0) sfarsit=nod;

            a[nod]=inceput;
            inceput=i;
        }
    }
    a[sfarsit]=inceput;
    if (frunze==0 && cicluri==1) printf ("0\n");
    else {
             mutari=frunze+cicluri;
             printf ("%d\n", mutari);
             for (i=1; i<=n; ++i)
             {
                 if (a[i]!=copie[i]) printf ("%d %d\n", i, a[i]);
             }
         }

    return 0;
}
