# include <bits/stdc++.h>
# define NR 1005
using namespace std;
ifstream f("fp.in");
ofstream g("fp.out");
struct solutie {
    int i,j,k;
}aux[NR], sol[NR];
int i,j,n,m,T,cnt,VV,S1,S2,S3,K,maxx,luate;
int ap[40][40], st[NR], vect[NR];
void init_ap () {
    for (int i=1; i<=S1+S2+S3; ++i)
        for (int j=1; j<=S1+S2+S3; ++j)
            ap[i][j]=0;
}
int main ()
{
    srand(time(0));
    f>>T; int cnt=0;
    while (T--) {
        f>>S1>>S2>>S3>>K;   ++cnt; VV=0; maxx=0;

        for (int i=1; i<=S1; ++i)
            for (int j=S1+1; j<=S1+S2; ++j)
                for (int k=S1+S2+1; k<=S1+S2+S3; ++k) {
                    ++VV;
                    aux[VV].i=i; aux[VV].j=j; aux[VV].k=k;
                }

        for (int i=1; i<=VV; ++i)
            vect[i]=i;

        for (int i=1; i<=50000; ++i) { //fac shuffle de cateva ori si verific maximul
            random_shuffle (vect+1, vect+VV+1);
            init_ap(); luate=0;

            for (int j=1; j<=VV; ++j) {
                if (ap[aux[j].i][aux[j].j]<K && ap[aux[j].i][aux[j].k]<K && ap[aux[j].j][aux[j].k]<K) {
                    ++ap[aux[j].i][aux[j].j];
                    ++ap[aux[j].i][aux[j].k];
                    ++ap[aux[j].j][aux[j].k];
                    st[++luate] = j;
                    if (luate > maxx) {
                        maxx=luate;
                        for (int k=1; k<=luate; ++k)
                            sol[k]=aux[st[k]];
                    }
                }
            }
        }

        g<<"Case #"<<cnt<<": "<<maxx<<"\n";
        for (int i=1; i<=maxx; ++i)
            g<<sol[i].i<<" "<<sol[i].j-S1<<" "<<sol[i].k-S1-S2<<"\n";
    }

    return 0;
}
