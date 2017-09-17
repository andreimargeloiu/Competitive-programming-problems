# include <iostream>
# include <algorithm>
# define NR 2005
using namespace std;
int i,j,n,m,X,aux,i2,j2;
int a[NR][NR];
int main () {
    cin>>n>>m>>X;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j) {
            cin>>aux;
            for (i2=1; i2<=X; ++i2)
                for (j2=1; j2<=X; ++j2)
                    a[(i-1)*X+i2][(j-1)*X+j2]=aux;
        }

    for (i=1; i<=n*X; ++i) {
        for (j=1; j<=m*X; ++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
