# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 2000005
using namespace std;
ifstream f("x.in");
ofstream g("x.out");
int i,j,n,m,x,y,Q,k,X,Y,L,R;
int Z[NR], st[NR/2], dr[NR/2];
char a[NR], b[NR];
void Zalgorithm ()
{
    int i,j,L=0,R=0;
    for (i=2; i<=m; ++i) {
        if (R<i) {
            L=R=i;
            while (R<=m && b[R-i+1]==b[R]) ++R;
            Z[i]=R-i; R=i+Z[i]-1;
        }
        else {
                 int k=i-L+1;
                 if (Z[k]<R-i+1) Z[i]=Z[k];
                 else {
                         L=i; ++R;
                         while (R<=m && b[R-L+1]==b[R]) ++R;
                         Z[i]=R-i; R=i+Z[i]-1;
                      }
             }
    }
}
int main ()
{
    f>>n>>m>>Q; f.get();
    f.getline (a+1, NR);
    f.getline (b+1, NR);

    b[++m]='0'; strcpy(b+m+1, a+1); m+=n;

    //Z algorithm  - dreapta
    Zalgorithm (); m=m-n;
    for (i=1; i<=n; ++i) dr[i]=Z[i+m];

    for (i=n; i>=1; --i) b[++m]=a[i];
    //Z algorithm -stanga
    Zalgorithm (); m-=n;
    for (i=1; i<=n; ++i) st[i]=Z[m+n-i+1];


    for (i=1; i<=Q; ++i) {
        f>>X>>Y;
        x=min(X, Y);  y=max(X, Y);
        g<<min(st[x-1], dr[y+1])<<"\n";
    }


    return 0;
}
