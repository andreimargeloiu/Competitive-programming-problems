# include <fstream>
# include <vector>
# include <iomanip>
# include <algorithm>
# define inf 999999999
# define NR 4500
using namespace std;
ifstream f("statie.in");
ofstream g("statie.out");
struct elem
{
    int nr;
    double suma;
}a[NR];
int i,j,n,m,x,y,pers,VV;
int P[50];
double medie, mat[10][1<<11];
double make_suma (double k)
{
    if (k<0) return -k;
        else return k;
}

void PD ()
{
    int i,j,k, stop=(1<<(pers+1))-1;

    for (i=1; i<=n; ++i)
        for (j=0; j<=stop; ++j)
            mat[i][j]=inf;

    for (j=1; j<=VV; ++j)
        mat[1][a[j].nr]=a[j].suma;

    //a[i][j] - costul minim ca sa ajungi in i folosind j oameni
    for (i=1; i<n; ++i)
        for (j=0; j<=stop; ++j)
        {
            for (k=1; k<=VV; ++k)
            {
                if ((a[k].nr & j)==0)
                {
                    if (mat[i+1][a[k].nr + j] > mat[i][j] + a[k].suma)
                    {
                        mat[i+1][a[k].nr + j] = mat[i][j] + a[k].suma;
                    }
                }
            }
        }
}
int main ()
{
    f>>n>>pers;
    for (i=1; i<=pers; ++i)
    { f>>P[i]; medie+=P[i]; }

    medie/=n;
    a[++VV].nr=0; a[VV].suma=medie;

    for (i=1; i<=pers; ++i)
    {
        a[++VV].nr=(1<<i); a[VV].suma=make_suma(medie - P[i]);
        for (j=i+1; j<=pers; ++j)
        {
            a[++VV].nr=(1<<i) + (1<<j); a[VV].suma=make_suma(medie - P[i] - P[j]);
        }
    }

    PD ();

    g<<fixed<<setprecision(3)<<mat[n][(1<<pers+1)-2];

    return 0;
}
