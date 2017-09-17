# include <fstream>
# include <algorithm>
# define MOD 666013
using namespace std;
ifstream f("2ndesc.in");
ofstream g("2ndesc.out");
int i,j,n,m;
int a[5], M[5][5], mat[5][5];
void inmultire (int a[5][5], int b[5][5])
{
    int c[5][5];
    for(int i=1; i<=3; ++i)
        for (int j=1; j<=3; ++j) c[i][j]=0;

    for (int i=1; i<=3; ++i) //linie a
        for (int j=1; j<=3; ++j) //coloana b
            for (int k=1; k<=3; ++k) //parcurgere
                c[i][j]=(1LL*c[i][j] + 1LL*a[i][k]*b[k][j])%MOD;

    for (int i=1; i<=3; ++i)
        for (int j=1; j<=3; ++j)
            a[i][j]=c[i][j];

}
int main ()
{
    f>>n;
    a[1]=1; a[2]=2; a[3]=4;
    if (n<=3) {g<<a[n]; return 0;}

    mat[1][1]=1; mat[2][2]=1; mat[3][3]=1;
    M[1][3]=1; M[2][1]=1; M[2][3]=1; M[3][2]=1; M[3][3]=1;
    // ridicam logaritmic matricea la puterea n
    n=n-3;
    while (n) {
        if (n%2==1) {
            inmultire (mat, M);
            --n;
        }
        else {
                 inmultire (M, M);
                 n=n/2;
             }
    }
    g<<(mat[1][3] + 2*mat[2][3] + 4*mat[3][3])%MOD<<"\n";


    return 0;
}
