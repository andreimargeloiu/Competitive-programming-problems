# include <fstream>
# include <algorithm>
# define NR 50
using namespace std;
ifstream f("gard3.in");
ofstream g("gard3.out");
int i,j,n,m,k,q,l;
int a[NR][NR], C[NR][NR];
void combinari ()
{
    int i,j;
    for (i=1; i<=n; ++i)
    {
        C[i][0]=C[i][i]=1;
        for (j=1; j<i; ++j)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
}
int main ()
{
    f>>n>>k; --k;
    //a[i][j] - numarul de moduri de a face j regiuni din i noduri,
    //          astfel incat sa fie o muchie in nodul i
    combinari ();

    for (i=1; i<=n; ++i) a[i][0]=1;
    a[3][1]=1;
    for (i=4; i<=n; ++i) //fiecare nod actual
    {
        if (i==n)
        {
            for (j=1; j<=i-3; ++j)
                a[i][j]=C[n-3][j];
        }
        else
        {
            for (j=1; j<=i-2; ++j)
                a[i][j]=C[i-2][j];
        }

        for (q=i-2; q>=1; --q) //fiecare nod anterior
            for (j=2; j<=k; ++j) //fiecare suma posibila
                for (l=1; l<j; ++l) // fiecare suma actuala
                {
                    a[i][j]=a[i][j]+a[i-q+1][l]*a[q][j-l];
                }
    }
    int S=0;
    for (i=1; i<=n; ++i)
        S+=a[i][k];
    g<<S;

    return 0;
}
