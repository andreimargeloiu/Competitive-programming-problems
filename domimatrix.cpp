//# include <fstream>
# include <algorithm>
# include <iostream>
# define NR 105
using namespace std;
//ifstream cin("domimatrix.in");
//ofstream cout("domimatrix.out");
int i,j,n,m,x,y,VV,N;
int  mat[NR][NR], a[NR*NR];
int main ()
{
    cin>>n; N=n*n;
    for (i=1; i<=N; ++i)
        cin>>a[i];

    sort (a+1, a+N+1);
    VV=N+1;
    for (i=1; i<=n; ++i)
        mat[i][i]=a[--VV];

    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            if (i!=j) mat[i][j]=a[--VV];


    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
            cout<<mat[i][j]<<" ";

        cout<<"\n";
    }



    return 0;
}
