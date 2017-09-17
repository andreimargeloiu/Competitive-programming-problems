# include <fstream>
# include <algorithm>
# include <cstring>
# define LB(p) ((-p)&p)
# define NR 505
# define MOD 666013
using namespace std;
ifstream f("pedefe.in");
ofstream g("pedefe.out");
int i,N,M,P,act,nou,j,k,sss,SOL;
int Saib[3][NR], S[3][NR], S1[NR], S2[NR], S3[NR];

int suma (int aib[], int poz) {
    int i, sol=0;
    for (int i=poz; i>=1; i-=LB(i)) {
        sol=sol+aib[i];
        if (sol>=MOD) sol-=MOD;
    }
    return sol;
}
void update (int aib[], int val, int poz) {
    int i;
    for (i=poz; i<=500; i+=LB(i)) {
        aib[i]+=val;
        if (aib[i]>=MOD) aib[i]-=MOD;
    }
}
int main ()
{
    f>>N>>M>>P;
    for (i=1; i<=N; ++i) f>>S1[i];
    for (i=1; i<=M; ++i) f>>S2[i];
    for (i=1; i<=P; ++i) f>>S3[i];

    // S[k][q] - suma de la pasurile anterioare lui i pana la pozitia q

    act=0;
    for (k=1; k<=P; ++k) {
        nou=1-act; memset (S[nou], 0, sizeof(S[nou]));
        for (i=1; i<=N; ++i) {
            memset (Saib[nou], 0, sizeof(Saib[nou]));
            for (j=1; j<=M; ++j) {
                if (S1[i]==S2[j]) {

                    if (S1[i]==S3[k])  {
                        sss=suma(Saib[act], S1[i]);
                        if (k==1) ++sss;
                    }
                    else sss=suma(Saib[nou], S1[i]);

                    if (k==P) {
                        SOL+=sss;
                        if (SOL>=MOD) SOL-=MOD;
                    }

                    S[nou][j]+=sss; if (S[nou][j]>=MOD) S[nou][j]-=MOD;
                }
                update (Saib[nou], S[act][j], S1[i]);
            }
        }
        act=nou;
    }
    g<<SOL<<"\n";


    return 0;
}
