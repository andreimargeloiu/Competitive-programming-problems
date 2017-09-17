# include <bits/stdc++.h>
# define NR 1005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int T, test, K, n, st[NR];
double P[NR], YES[NR], NO[NR], sol;
void BACK (int k) {
    if (k==K+1) {
        double aux=0;
        // aici am selectat exact K
        for (int i=1; i<=(1<<K)-1; ++i) {
            int biti=0; double yes=1, no=1;
            for (int bit=0; bit<K; ++bit)
                if (i & (1<<bit)) ++biti;

            if (biti==K/2) {
                for (int bit=0; bit<K; ++bit) {
                    if ((1<<bit) & i) yes*=YES[st[bit+1]];
                                else  no*=NO[st[bit+1]];
                }
                aux+=(yes * no);
            }
        }

        if (aux > sol) sol=aux;
    } else {
        for (int i=st[k-1]+1; i<=n; ++i) {
            st[k]=i;
            BACK(k+1);
            st[k]=0;
        }
    }
}
int main ()
{
    f>>T;
    while (T--) {
        ++test; g<<"Case #"<<test<<": ";

        f>>n>>K;
        for (int i=1; i<=n; ++i) {
            f>>YES[i];
            NO[i]=1.0 - YES[i];
        }
        sol=0;
        BACK (1);

        g<<fixed<<setprecision(7)<<sol<<"\n";

    }

    return 0;
}
