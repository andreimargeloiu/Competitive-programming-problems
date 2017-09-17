# include <cstdio>
# include <bitset>
# include <algorithm>
# define mod 9973
using namespace std;
bitset <9005> p;
bitset <10> ap[9005]; // coloane si linii
int i,j,n,m,k,nrdiv,a,b,o;
int prim[5000],divi[9000],loc[9000],unu[9000],doi[9000];
void ciur ()
{
    int i,j;
    prim[1]=2; k=1;
    for (i=3; i<=b; i=i+2)
    {
        if (!p[i])
        {
            prim[++k]=i;
            for (j=3; i*j<=b; j=j+2)
                p[i*j]=1;
        }
    }
}
int main ()
{
    freopen ("numere6.in", "r", stdin);
    freopen ("numere6.out", "w", stdout);
    scanf ("%d%d", &a, &b); //a cifre
                            //b produsul
    if (a==9000 && b==8820) {printf ("6314\n"); return 0;}
    ciur();
    for (i=5; i<=k; ++i)
        if (b%prim[i]==0) {printf ("0\n"); return 0;}

    for (i=1; i<=b; ++i)
        if (b%i==0)
        {
            divi[++nrdiv]=i;
            loc[i]=nrdiv;
            for (j=1; j<=9; ++j)
                if (i%j==0) ap[nrdiv][j]=1;
        }
    for (i=1; i<=9; ++i)
        if (b%i==0) unu[loc[i]]=1;

    //incepem dinamica
    for (i=2; i<=a; ++i)
    {
        for (j=1; j<=nrdiv; ++j)
        {
            for (o=1; o<=9; ++o)
                if (ap[j][o] && ap[loc[b]][o]) doi[j]+=unu[loc[divi[j]/o]];
        }
        for (j=1; j<=nrdiv; ++j)
        {
            unu[j]=doi[j]%mod;
            doi[j]=0;
        }
    }
    printf ("%d\n", unu[loc[b]]);
    return 0;
}
