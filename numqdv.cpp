# include <fstream>
// # include <iostream>
# include <algorithm>
# include <cstring>
# define NR 150
# define MOD 4242
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int i,j,m,x,y,l,T,ch,C,linii,k,v1,v2;
int ap[NR], mask[NR], M[NR][NR], F[NR][NR], c[NR][NR];
char s[20000],chr;
long long n;
void init () {
    for (int i=1; i<=NR-5; ++i) {
        memset(M[i], 0, sizeof(M[i]));
        F[i][1]=0;
    }
    memset (ap, 0 , sizeof(ap));
    memset (mask, 0, sizeof(mask));
}
void inmultire (int a[][NR], int b[][NR], int la, int ca, int lb, int cb)
{
    int lc=lb, cc=cb;
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j) {
            c[i][j]=0;
            for (int k=1; k<=ca; ++k)
                c[i][j]=c[i][j] + a[i][k]*b[k][j];

                if (c[i][j]>=MOD) c[i][j]%=MOD;
        }
    for (int i=1; i<=lc; ++i)
        for (int j=1; j<=cc; ++j)
            b[i][j]=c[i][j];
}
int putere (long long N)
{
    int suma=0;
    while (N>0) {
        if (N%2==1) {
            inmultire (M, F, linii, linii, linii, 1);
            --N;
        }
        else {
            inmultire (M, M, linii, linii, linii, linii);
            N=N/2;
        }
    }
   for (int i=1; i<=linii; ++i)
       suma+=F[i][1];
   return suma%MOD;
}
int main ()
{
    cin>>T;
    for (int t=1; t<=T; ++t) {
        cin>>n>>C; cin.get(); init();
        cin.getline (s+1, 20000); l=strlen(s+1);

        for (i=1; i<=l; ++i) {
            ch=s[i]-'A'; mask[ch]=0;
            for (j=0; j<C; ++j)
                if (ap[j]) mask[ch]=mask[ch] + (1<<j);
            ap[ch]=1;
        }
        linii=(1<<C)-1;

        //cu o litera
        for (i=0; i<C; ++i)
            F[(1<<i)][1]=1;

        // sa facem si matricea M
        for (i=1; i<=linii; ++i) // pentru fiecare combinatie din F
            for (k=0; k<C; ++k) //fiecare litera
                if (i & (1<<k)) // daca aceasta litera se afla in combinatie
                {
                    v1=i; //cu el
                    v2=i-(1<<k); //fara el

                    for (j=1; j<=linii; ++j) //fiecare combinatie din M
                    {
                        if ((mask[k] & j)==0 && (j==v1 || j==v2))
                            ++M[i][j];
                    }
                }

        cout<<putere (n-1)<<"\n";
    }



    return 0;
}
