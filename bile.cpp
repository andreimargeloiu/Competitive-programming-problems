# include <fstream>
# include <algorithm>
# define NR 300*300
using namespace std;
ifstream f("bile.in");
ofstream g("bile.out");
int i,j,n,m,Rx,Ry,nr,nrv,lv,cv,maxim;
int R[NR], X[NR], Y[NR], maxx[NR], H[NR];
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};
int numar (int i, int j) {
    return (i-1)*n + j;
}
int radacina (int k) {
    while (k!=R[k]) k=R[k];
    return k;
}
int main ()
{
    f>>n;
    for (i=1; i<=n*n; ++i)
        f>>X[i]>>Y[i];


    for (i=n*n; i>=1; --i) {
        nr=numar(X[i], Y[i]);
        R[nr]=nr; H[nr]=1;
        maxx[i]=maxim;
        maxim=max(maxim, 1);
        for (j=0; j<4; ++j) {
            lv=X[i] + dx[j]; cv=Y[i] + dy[j];
            if (1<=lv && lv<=n && 1<=cv && cv<=n) {
                nrv=numar (lv, cv);
                Rx=radacina(nr);
                Ry=radacina(nrv);

                if (Rx && Ry && Rx!=Ry) {
                    if (H[Rx]>H[Ry]) R[Ry]=Rx, H[Rx]+=H[Ry];
                                else R[Rx]=Ry, H[Ry]+=H[Rx];
                }
                maxim=max(maxim, max(H[Rx], H[Ry]));
            }
        }
    }
    for (i=1; i<=n*n; ++i)
        g<<maxx[i]<<"\n";

    return 0;
}
