# include <bits/stdc++.h>
# define NR 305
using namespace std;
ifstream f("gauss.in");
ofstream g("gauss.out");
int i,j,n,m,k;
double A[NR][NR], sol[NR];
double EPS=0.00000001;
int main ()
{
    f>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m+1; ++j)
            f>>A[i][j];

    i=1; j=1;
    while (i<=n && j<=m) {
        for (k=i; k<=n; ++k)
            if (-EPS>A[k][j] || A[k][j]>EPS)
                break;

        if (k==n+1) { //variabila libera
            ++j;
            continue;
        }

        // inversez liniile
        if (k!=i) {
            for (int c=1; c<=m+1; ++c)
                swap(A[i][c], A[k][c]);
        }

        //fac termenul 1
        for (int l=j+1; l<=m+1; ++l)
            A[i][l]=A[i][l] / A[i][j];
        A[i][j]=1;

        //scad din celelalte
        for (int l=i+1; l<=n; ++l) {
            for (int c=j+1; c<=m+1; ++c) {
                A[l][c]-=A[i][c] * A[l][j];
            }
            A[l][j]=0;
        }
        ++i; ++j;
    }
    for (int i=n; i>=1; --i) {
        for (int j=1; j<=m+1; ++j) {
            if (-EPS>A[i][j] || A[i][j]>EPS) {
                if (j==m+1) {
                    g<<"Imposibil\n";
                    return 0;
                }
                sol[j]=A[i][m+1];
                for (int k=j+1; k<=m; ++k)
                    sol[j]=sol[j] - sol[k]*A[i][k];

                break;
            }
        }
    }
    for (int i=1; i<=m; ++i)
        g<<fixed<<setprecision(8)<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
