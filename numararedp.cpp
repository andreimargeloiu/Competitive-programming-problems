// # include <iostream>
# include <fstream>
# include <algorithm>
# include <cstring>
# include <cmath>
# define NR 200
using namespace std;
ifstream cin("numararedp.in");
ofstream cout("numararedp.out");
int i,j,n,m;
int prim[NR], cifra[NR];
long long dp[20][NR], S[20][NR], a, b, X, VV, nrsol;
void prime ()
{
    for (int i=2; i<=190; ++i) {
        int ok=1;
        int var=sqrt((double)(i));
        for (int j=2; j<=var && ok; ++j)
            if (i%j==0) ok=0;
        prim[i]=ok;
    }
}
void dinamica () {
    // dp[i][j] - numarul de moduri de a face numere de i cifre cu suma j
    int i,j,o;
    for (i=1; i<=9; ++i) {
        dp[1][i]=1;
        S[1][i]=1;
    }
    S[1][0]=1;

    for (i=2; i<=19; ++i) {
        for (j=1; j<=9*i; ++j) {
            for (o=0; o<=9; ++o)
                if (j-o>=1) dp[i][j]+=dp[i-1][j-o];
            S[i][j]=S[i-1][j] + dp[i][j];
        }
        S[i][0]=1;
    }
}
long long numara (long long X) {
    long long suma=0, VV=0;
    int i,j,o,start;

    //descompun in cifre
    memset (cifra, 0, sizeof(cifra));
    while (X>0) {
        cifra[++VV]=X%10;
        X=X/10;
    }
    // toate cu mai putine cifre
    for (j=1; j<=9*(VV-1); ++j)
        if (prim[j]) suma+=S[VV-1][j];

    int SC=0;
    for (i=VV; i>=1; --i) {
        if (i==1) {
            for (j=0; j<=cifra[i]; ++j)
                if (prim[SC+j]) ++suma;
        }
        else {
            if (i==VV) start=1;
                  else start=0;
            for (j=start; j<cifra[i]; ++j) { // pt fiecare posbilitate pt cifra asta
                for (o=0; o<=9*(i-1); ++o)
                    if (prim[j+o+SC]) suma+=S[i-1][o];
            }
            SC+=cifra[i];
        }
    }

    return suma;
}
int main()
{
    cin>>a>>b;
    if (a>b) swap(a, b);
    prime ();
    dinamica ();

    cout<<numara(b) - numara(a-1)<<"\n";

    /*for (i=a; i<=b; ++i)
    {
        X=i; VV=0;
        while (X>0) {
            VV+=(X%10);
            X=X/10;
        }
        if (prim[VV]) ++nrsol;
    }
    cout<<nrsol<<"\n";*/


    return 0;
}
