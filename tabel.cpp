# include <fstream>
using namespace std;
ifstream f("tabel.in");
ofstream g("tabel.out");
int i,j,v,l,c,lipsa,n,m,p;
int a[100][100],L[100],C[100];
void linie (int l)
{
    int i,ok=1,s=0,c=0;
    for (i=1; i<m; ++i)
        if (a[l][i]==-1) ok=0,c=i;
            else s+=a[l][i];
    if (ok) {//este elem de pe ultima coloana
                a[l][m]=s;
                --L[l]; --C[m]; --lipsa;
            }
    else {
             a[l][c]=a[l][m]-s;
             --L[l]; --C[c]; --lipsa;
         }
}
void coloana (int c)
{
    int i,ok=1,s=0,l=0;
    for (i=1; i<n; ++i)
        if (a[i][c]==-1) ok=0,l=i;
            else s+=a[i][c];
    if (ok) {
                a[n][c]=s;
                --L[n]; --C[c]; --lipsa;
            }
    else {
             a[l][c]=a[n][c]-s;
             --L[l]; --C[c]; --lipsa;
         }
}
void rezolva()
{
    int i;
    while (lipsa)
    {
        //verificam liniile
        for (i=1; i<=n; ++i)
            if (L[i]==1) linie(i);
        for (i=1; i<=m; ++i)
            if (C[i]==1) coloana(i);
    }
}
int main ()
{
    f>>n>>m>>p;

    lipsa=n*m;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            a[i][j]=-1;
    for (i=1; i<=n; ++i)
        L[i]=m;
    for (i=1; i<=m; ++i)
        C[i]=n;

    for (i=1; i<=p; ++i)
    {
        f>>l>>c>>v;
        a[l][c]=v;
        --L[l]; --C[c]; --lipsa;
    }
    rezolva();
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            g<<a[i][j]<<" ";
        g<<"\n";
    }
    return 0;
}
