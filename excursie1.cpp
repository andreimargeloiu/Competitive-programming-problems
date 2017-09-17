# include <cstdio>
using namespace std;
int i,j,n,VV,gr1[50000], gr2[50000], gr3[50000],v1,v2,v3;
void afisare ()
{
    int i;
    printf ("DA\n");
    for (i=1; i<=v1; ++i)
        printf ("%d ", gr1[i]);
    printf ("\n");
    for (i=1; i<=v2; ++i)
        printf ("%d ", gr2[i]);
    printf ("\n");
    for (i=1; i<=v3; ++i)
        printf ("%d ", gr3[i]);
    printf ("\n");
}
void procesare (int k)
{
    n-=k; VV=k;
    for (i=1; i<=n/6; ++i)
    {
        gr1[++v1]=++VV;
        gr2[++v2]=++VV;
        gr3[++v3]=++VV;
        gr3[++v3]=++VV;
        gr2[++v2]=++VV;
        gr1[++v1]=++VV;
    }
}
int main ()
{
    freopen ("excursie1.in", "r", stdin);
    freopen ("excursie1.out", "w", stdout);
    scanf ("%d", &n);
    if (n<5 || n*(n+1)/2%3!=0)
    {
        printf ("NU\n");
        return 0;
    }
    if (n==5 || (n-5)%6==0)
    {

        gr1[++v1]=5;
        gr2[++v2]=2; gr2[++v2]=3;
        gr3[++v3]=1; gr3[++v3]=4;
        procesare (5);
        afisare ();
        return 0;
    }
    if (n==6 || (n-6)%6==0)
    {
        gr1[++v1]=2; gr1[++v1]=5;
        gr2[++v2]=3; gr2[++v2]=4;
        gr3[++v3]=1; gr3[++v3]=6;
        procesare (6);
        afisare ();
        return 0;
    }
    if (n==8 || (n-8)%6==0)
    {
        gr1[++v1]=1; gr1[++v1]=2; gr1[++v1]=3; gr1[++v1]=6;
        gr2[++v2]=5; gr2[++v2]=7;
        gr3[++v3]=4; gr3[++v3]=8;
        procesare (8);
        afisare ();
        return 0;
    }
    if (n==9 || (n-9)%6==0)
    {
        gr1[++v1]=1; gr1[++v1]=2; gr1[++v1]=3; gr1[++v1]=4; gr1[++v1]=5;
        gr2[++v2]=7; gr2[++v2]=8;
        gr3[++v3]=6; gr3[++v3]=9;
        procesare (9);
        afisare ();
        return 0;
    }
    printf ("NU\n");
    return 0;
}
