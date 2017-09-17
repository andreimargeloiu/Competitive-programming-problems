# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 10005
# define MOD 30313
using namespace std;
ifstream f("cifru5.in");
ofstream g("cifru5.out");
int i,j,n,m,l,L,act,nou,k,sol;
int ap[10], apMIN[10], M[10], a[10][NR], S[10][NR], C[3][NR];
char s[NR];
void combinari (int n) {
    C[nou][0]=1; C[nou][n]=1;
    if (n>1) {
        for (int i=1; i<n; ++i) {
            C[nou][i]=C[act][i-1] + C[act][i];
            C[nou][i]%=MOD;
        }
    }
}
int main ()
{
    f>>n; f.get(); for (i=1; i<=9; ++i) apMIN[i]=INFINITY;
    for (i=1; i<=n; ++i) {
        f.getline (s+1, NR); l=strlen(s+1);
        memset (ap, 0, sizeof(ap));
        for (j=1; j<=l; ++j)
            ++ap[s[j]-'0'];
        for (j=1; j<=9; ++j)
            apMIN[j]=min(apMIN[j], ap[j]);
    }
    for (i=1; i<=9; ++i)
        M[i]=M[i-1] + apMIN[i];
    L=M[9];
    // a[i][j] - numarul de moduri de a face siruri de lungime j, iar ultimul numar e i
    act=0;
    for (j=1; j<=L; ++j) { // fiecare lungime
        nou=1-act; combinari (j);

        for (i=1; i<=9; ++i) { //fiecare numar
            S[i][j]=S[i-1][j];
            if (M[i]>=j && apMIN[i]) { //daca va ajunge vreodata la lungimea asta
                if (apMIN[i] >= j) ++a[i][j]; //daca pot sa umplu doar cu el
                for (k=1; k<=min(j, apMIN[i]); ++k) { //cate pot pun din el
                    a[i][j]+=S[i-1][j-k]*C[nou][k];
                    a[i][j]%=MOD;
                }
                sol=(sol + a[i][j])%MOD;
            }
            S[i][j]=(S[i][j] + a[i][j])%MOD;
        }

        act=nou;
    }
    g<<sol<<"\n";


    return 0;
}
