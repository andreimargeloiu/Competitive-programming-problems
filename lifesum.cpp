# include <fstream>
// # include <iostream>
# include <algorithm>
# define NR 100
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
struct elem {
    int x, y;
}V[NR];
int i,j,n,m,x,y,T,nrelem,MOD,L,N,X,len[NR];
long long S;
long long ap[NR][NR], F[NR][NR], M[NR][NR], c[NR][NR];
void init (int X)
{
    for (int i=0; i<=X; ++i)
        for (int j=0; j<=X; ++j)
           M[i][j]=0, ap[i][j]=0;
    for (int i=1; i<=X; ++i)
        F[i][1]=0, len[i]=0;
}
void inmultire (long long a[][NR], long long b[][NR], int la, int ca, int lb, int cb)
{
    int lc=lb, cc=cb;
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j) {
            c[i][j]=0;
            for (int k=1; k<=ca; ++k)
                c[i][j]=(c[i][j] + (1LL*a[i][k]*b[k][j])%MOD)%MOD;
        }
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j)
            b[i][j]=c[i][j];
}
int putere (int N)
{
    while (N>0) {
        if (N%2==1) {
            inmultire (M, F, nrelem, nrelem, nrelem, 1);
            --N;
        }
        else {
            inmultire (M, M, nrelem, nrelem, nrelem, nrelem);
            N=N/2;
        }
    }
}
int main ()
{
    while (cin>>n) {
        cin>>MOD>>L;

        if (n==0 && MOD==0 && L==0) break;

        init (95); nrelem=0; N=n; // numar cate elemente sunt
        for (i=1; i<=2*n-1; ++i) {
            for (j=1; j<=N; ++j) {
                cin>>X; //cout<<X<<" ";
                F[++nrelem][1]=X;

                V[nrelem].x=i; V[nrelem].y=j;
                ap[i][j]=nrelem;
            }
            len[i]=N;
            if (i<n) ++N;
                else --N;
        }
        //formam matricea
        for (int I=1; I<=nrelem; ++I) {
            M[I][I]=1;
            i=V[I].x; j=V[I].y;
            // stanga - dreapta
            if (ap[i][j-1]) M[I][ap[i][j-1]]=1;
            if (ap[i][j+1]) M[I][ap[i][j+1]]=1;

            if (i<n) {
                if (ap[i-1][j-1]) M[I][ap[i-1][j-1]]=1;
                if (ap[i-1][j]) M[I][ap[i-1][j]]=1;
                if (ap[i+1][j]) M[I][ap[i+1][j]]=1;
                if (ap[i+1][j+1]) M[I][ap[i+1][j+1]]=1;
            }
            else if (i==n) {
                if (ap[i-1][j-1]) M[I][ap[i-1][j-1]]=1;
                if (ap[i-1][j]) M[I][ap[i-1][j]]=1;
                if (ap[i+1][j-1]) M[I][ap[i+1][j-1]]=1;
                if (ap[i+1][j]) M[I][ap[i+1][j]]=1;
            }
            else {
                if (ap[i-1][j]) M[I][ap[i-1][j]]=1;
                if (ap[i-1][j+1]) M[I][ap[i-1][j+1]]=1;
                if (ap[i+1][j-1]) M[I][ap[i+1][j-1]]=1;
                if (ap[i+1][j]) M[I][ap[i+1][j]]=1;
            }
        }
        putere (L); S=0;
        for (i=1; i<=nrelem; ++i)
        {
            S=S+F[i][1];
        }
        ++T; cout<<"Case "<<T<<": "<<S<<"\n";
    }

    return 0;
}
