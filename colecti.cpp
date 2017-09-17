# include <fstream>
# include <algorithm>
# include <cstring>
# include <vector>
# define MOD 666013
# define NR 1<<17
# define SS 1<<18
using namespace std;
ifstream f("colectie.in");
ofstream g("colectie.out");
struct elem {
    int cif[10], biti;
}E;
vector <elem> v[MOD];
int i,j,n,m,N,nrc,totalCif,minn=999,AUX,unu,doi;
int cifra[20], S[20], DP[20][20][20], necCif[20], numar[20];
int nrBiti[SS+5], sol[50], aux[50], C[50][50];
void dinamica () {
    // fac numarul de cifre necesare pentru a face
    // DP[i][j][k] - numarul de cifre  k  pentru a face toate
    //               numerele de i cifre, unde prima cifra e j
    int i, j, k, o, var=N, nr=1, start, put=1;

    for (i=1; i<=9; ++i) { // numar cifre
        if (i>1) nr*=10;
        for (j=0; j<=9; ++j) { // cifra
            DP[i][j][j]+=nr;
            for (k=0; k<=9; ++k) //fiecare cifra de numarat
                for (o=0; o<=9; ++o)
                    DP[i][j][k] += DP[i-1][o][k];
        }
    }

    while (var) { ++nrc; var/=10; }

    var=N;
    for (i=1; i<=nrc; ++i) {
        cifra[nrc-i+1]=var%10;
        var/=10;
    }
    for (i=nrc; i>=1; --i) {
        if (i!=nrc) put=put*10;
        numar[i]=numar[i+1] + cifra[i]*put;
    }

    for (i=1; i<nrc; ++i)
        for (j=1; j<=9; ++j)
            for (k=0; k<=9; ++k) {
                necCif[k]+=DP[i][j][k];
                totalCif+=DP[i][j][k];
            }

    for (i=1; i<=nrc; ++i) {//iau fiecare cifre in parte
        if (i==1) start=1;
             else start=0;

        if (i==nrc) {
            for (j=0; j<=cifra[i]; ++j)
                ++necCif[j], ++totalCif;
        }
        else {
            necCif[cifra[i]]+=numar[i+1]+1;
            totalCif+=numar[i+1]+1;

            for (j=start; j<cifra[i]; ++j) { //fiecare cifra mai mica
                for (k=0; k<=9; ++k) {// fiecare cifra de numarat
                    necCif[k]+=DP[nrc-i+1][j][k];
                    totalCif+=DP[nrc-i+1][j][k];
                }
            }
        }
    }
}
void biti () {
    for (int i=1; i<=SS; ++i)
        for (int j=0; j<=16; ++j)
            if (i & (1<<j)) ++nrBiti[i];
}
void BACK (int k, int stop) {
    if (k==stop+1) {

        if (k==n+1) { // a doua grupa
            int H=0;

            for (int i=0; i<=9; ++i)
                E.cif[i]=aux[i], H+=aux[i];

            E.biti=AUX; v[H%MOD].push_back(E);
        }
        else { // prima grupa
            int suma=0;
            for (i=0; i<=9; ++i) suma+=aux[i];

            int T=totalCif - suma;
            if (T>=0) {
                T=T%MOD;
                for (int i=0; i<v[T].size(); ++i) {
                    //verificam
                    int ok=1;
                    for (int j=0; j<=9 && ok; ++j) // numar cifrele
                        if (aux[j] + v[T][i].cif[j] != necCif[j]) ok=0;

                    if (ok && nrBiti[AUX] + nrBiti[v[T][i].biti] < minn) {
                        minn=0;
                        for (int j=1; j<=(n+1)/2; ++j) {
                            if (AUX & (1<<j)) sol[++minn]=j;              // grupa 1
                            if (v[T][i].biti & (1<<j)) sol[++minn]=unu+j; // grupa 2
                        }
                    }
                }
            }
        }
    }
    else {
        BACK (k+1, stop); // nu il iau

        // il iau
        for (int i=0; i<=9; ++i)
            aux[i]+=C[k][i];
        if (k<=unu) AUX+=(1<<k);
               else AUX+=(1<<(k-unu));

        BACK(k+1, stop);

        for (int i=0; i<=9; ++i)
            aux[i]-=C[k][i];
        if (k<=unu) AUX-=(1<<k);
           else AUX-=(1<<(k-unu));
    }
}
int main ()
{
    f>>n>>N;
    dinamica ();
    //g<<totalCif<<"\n";
    biti ();
    for (i=1; i<=n; ++i)
        for (j=0; j<=9; ++j)
            f>>C[i][j];

    unu=n/2; doi=n-unu;

    v[0].push_back(E);
    memset (aux, 0, sizeof(aux)); AUX=0;
    BACK (unu+1, n);
    memset (aux, 0, sizeof(aux)); AUX=0;
    BACK (1, unu);

    if (minn) {
        g<<"1\n"<<minn<<"\n";

        sort (sol+1, sol+minn+1);
        for (i=1; i<=minn; ++i) g<<sol[i]<<" ";
        g<<"\n";
    } else g<<"0\n";

    return 0;
}
