# include <bits/stdc++.h>
# define NR 40005
using namespace std;
ifstream f("farey.in");
ofstream g("farey.out");
struct elem {
    int a, b;
    double rap;
}aux[NR];
bool cmp (elem x, elem y) {
    return x.rap < y.rap;
}

int i,j,n,m,a,VV,X,nrAux,nr,IND,ci,cs,mij,K;
int dp[NR];

int numara (int X) {
    int sol=0;
    double A, Aintreg;
    memset (dp, 0, sizeof(dp));

    for (int i=1; i<=n; ++i) {
        A=(double)X * i / n;
        Aintreg=floor(A);

        if (A==Aintreg) --Aintreg;
        dp[i]+=Aintreg;
        sol+=dp[i];

        for (int j=2; i*j<=n; ++j)
            dp[i*j]-=dp[i];
    }
    return sol;
}
int cmmdc (int a, int b) {
    int R;
    while (b) {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
int main ()
{
    f>>n>>K;

    ci=1; cs=n; //caut X
    while (ci<=cs) {
        mij=(ci+cs)/2;
        nr=numara(mij);
        if (nr < K) ci=mij+1, X=mij, nrAux=nr;
               else cs=mij-1;
    }

    //vrem sa vedem daca fractiile cu numitorul i
    //pot avea un numarator si sa fie cuprinse intre X/n si (X+1)/n
    for (i=1; i<=n; ++i) {
        a=ceil((double)X*i/n);
        if (cmmdc (a, i)!=1) continue;
        if ((double)a/i > (double)(X+1)/n) continue;

        ++VV;
        aux[VV].a=a; aux[VV].b=i; aux[VV].rap=(double)a/i;
    }
    IND=K-nrAux;
    nth_element (aux+1, aux+IND, aux+VV+1, cmp);
    g<<aux[IND].a<<" "<<aux[IND].b<<"\n";

    return 0;
}
