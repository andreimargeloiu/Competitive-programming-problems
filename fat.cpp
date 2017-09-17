# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 105
using namespace std;
ifstream f("fat.in");
ofstream g("fat.out");
int i,j,n,m,k,l1,l2,l3,VV;
int maxx[NR][NR][NR];
char a[NR], b[NR], c[NR], sol[NR];
int main ()
{
    f.getline (a+1, NR); l1=strlen(a+1);
    f.getline (b+1, NR); l2=strlen(b+1);
    f.getline (c+1, NR); l3=strlen(c+1);

    for (i=1; i<=l1; ++i)
        for (j=1; j<=l2; ++j)
            for (k=1; k<=l3; ++k) {
                //sunt toate 3 egale
                if (a[i]==b[j] && b[j]==c[k]) {maxx[i][j][k]=maxx[i-1][j-1][k-1]+1; continue;}
                //2 egale
                if (a[i]==b[j]) {maxx[i][j][k]=max(maxx[i][j][k-1], maxx[i-1][j-1][k]); continue;}
                if (b[j]==c[k]) {maxx[i][j][k]=max(maxx[i-1][j][k], maxx[i][j-1][k-1]); continue;}
                if (a[i]==c[k]) {maxx[i][j][k]=max(maxx[i][j-1][k], maxx[i-1][j][k-1]); continue;}
                // niciunul egal
                maxx[i][j][k]=max(maxx[i][j-1][k-1], max(maxx[i-1][j][k-1], maxx[i-1][j-1][k]));
            }
    //g<<maxx[l1][l2][l3]<<"\n";

    i=l1; j=l2; k=l3;

    while (i>0 && j>0 && k>0)
    {
        if (a[i]==b[j] && b[j]==c[k]) {
            sol[++VV]=a[i];
            --i; --j; --k;
        }
        else {
                  if (maxx[i-1][j][k]>=maxx[i][j-1][k] && maxx[i-1][j][k]>=maxx[i][j][k-1]) {--i; continue;}
                  if (maxx[i][j-1][k]>=maxx[i-1][j][k] && maxx[i][j-1][k]>=maxx[i][j][k-1]) {--j; continue;}
                  if (maxx[i][j][k-1]>=maxx[i-1][j][k] && maxx[i][j][k-1]>=maxx[i][j-1][k]) {--k; continue;}
             }
    }
    for (i=VV; i>=1; --i)
        g<<(char)sol[i];
    g<<"\n";


    return 0;
}
