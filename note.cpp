# include <fstream>
# include <algorithm>
# include <vector>
# define NR 1025
using namespace std;
ifstream f("note.in");
ofstream g("note.out");
int i,j,n,m,nr,x;
int mat[NR][NR], a[NR];
bool ap[NR][105];
int minim (int a, int b, int c)
{
    return min(a, min(b, c));
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            f>>x;
            ap[j][x]=1;
        }
    f>>nr;
    for (i=1; i<=nr; ++i)
        f>>a[i];

    //mat[i][j] - numarul minim de mutari necesare pentru a transforma primele
    //            i note din solfegiu in j note din portative
    for (i=1; i<=m; ++i)
        mat[0][i]=mat[i][0]=i;

    for (i=1; i<=nr; ++i)
    {
        for (j=1; j<=m; ++j)
            if (ap[j][a[i]]==1) mat[i][j]=mat[i-1][j-1];
            else {
                     mat[i][j]=minim (mat[i-1][j]+1, mat[i][j-1]+1, mat[i-1][j-1]+1);
                 }
    }
    g<<mat[nr][m];


    return 0;
}
