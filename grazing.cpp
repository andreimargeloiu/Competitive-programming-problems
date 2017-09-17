# include <fstream>
# include <vector>
# include <cstring>
# define NR 305
# define NC 305
# define baza 1000
using namespace std;
ifstream f("grazing.in");
ofstream g("grazing.out");
vector <int> SOL;
int i,j,n,m;
int sol[NC], dp[NR][NC], var[NC], aux[NC];

void inmultire (int c[], int K, int a[]) {
    c[0]=a[0]; int t=0;
    for (int i=1; i<=c[0]; ++i) {
        t=t + a[i]*K;
        c[i]=t%baza;
        t/=baza;
    }
    while (t) c[++c[0]]=t%baza, t/=baza;
}
void aduna (int c[], int a[]) {
    c[0]=max(a[0], c[0]); int t=0;
    for (int i=1; i<=c[0]; ++i) {
        t=t + c[i] + a[i];
        c[i]=t%baza;
        t=t/baza;
    }
    while (t) c[++c[0]]=t%baza, t/=baza;
}
void impartire (int a[], int imp) {
    int R=0;
    for (int i=a[0]; i>=1; --i) {
        R=R*baza + a[i];
        a[i]=R/imp;
        R=R%imp;
    }
    while (a[0] && a[a[0]]==0) {a[a[0]]=0; --a[0];}
}

void afisare (int X[]) {
    SOL.clear();
    for (int i=1; i<=X[0]; ++i) {
        int var=X[i];

        if (i==X[0]) {
            while (var) {
                SOL.push_back(var%10);
                var/=10;
            }
        } else {
            for (int j=1; j<=3; ++j) {
                SOL.push_back(var%10);
                var/=10;
            }
        }
    }
    for (int i=SOL.size()-1; i>=0; --i)
        g<<SOL[i];
    g<<"\n";
}
int main ()
{
    f>>n;
    dp[0][0]=1; dp[0][1]=1;
    for (i=1; i<=n; ++i) {
        //inmultesc pentru a face aranjamentele
        memset (var, 0, sizeof(var));
        memset (aux, 0, sizeof(aux));
        aduna (dp[i], dp[i-1]); //nod izolat

        for (j=2; j<=i; ++j) { // lanturi
            inmultire (dp[i-j], i-1, dp[i-j]);

            memset(aux, 0, sizeof(aux));
            inmultire (aux, j, dp[i-j]);

            //if (i==14) {g<<j<<" * "; afisare(dp[i-j]); g<<" = "; afisare(aux);}

            aduna (var, aux);
           // if (i==14) {g<<"var "; afisare(var);}

            if (j>3 && j%3) aduna (var, dp[i-j]);
        }

        impartire (var, 2);
        aduna (dp[i], var);
    }

    afisare (dp[n]);

    return 0;
}
