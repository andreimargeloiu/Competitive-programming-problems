# include <fstream>
# include <algorithm>
# define NR 6000
# include <cstring>
using namespace std;
ifstream f("ssce.in");
ofstream g("ssce.out");
int i,j,n,m,maxx,K,B,stop,x,nr,u,X,ok,VV;
int C, sol[NR], var[NR], p[10], ap[10], Q[NR];
int bun (int X) {
    int minn=10, nrc=-1, maxx=0;
    memset (ap, 0, sizeof(ap));
    do {
        ap[++nrc]=X%10;
        X/=10;
    } while (X);

    nrc=B-1;
    for (int i=0; i<=nrc; ++i) {
        minn=min(minn, ap[i]);
        maxx=max(maxx, ap[i]);
    }

    if (maxx-minn > K) return -1; // nu se poate
    else {
        for (int i=nrc; i>=0; --i) {
            X=X*10 + (ap[i]-minn);
        }
        return X;
    }
}
void init () {
    p[0]=1; stop=0;

    for (int i=1; i<=K; ++i) {
        p[i]=p[i-1] * 10;
    }
    for (i=0; i<B; ++i)
        stop=stop*10 + K;
}
void BACK (int k, int nr)
{
    if (k==B) Q[++VV]=nr;
    else {
        for (int i=0; i<=K; ++i)
            BACK (k+1, nr*10 + i);
    }
}
int main ()
{
    f>>n>>B>>K;

    // a[faza][cod]=numarul maxim de NR pe care le-am folosit
    //              pentru a ajunge la faza FAZA si codul COD

    BACK (0, 0);

    init ();

    sol[0]=1;
    for (i=1; i<=n; ++i) {
        f>>x; nr=0;
        do {
            u=x%10;
            nr=nr + p[u];
            x=x/10;
        } while (x);
        for (j=1; j<=VV; ++j) var[Q[j]]=0;
        for (j=1; j<=VV; ++j) {
            C=bun(Q[j]+nr);

            if (sol[Q[j]] && C!=-1) {

                var[C]=sol[Q[j]] + 1;
            }
        }
        for (j=1; j<=VV; ++j) sol[Q[j]]=max(sol[Q[j]], var[Q[j]]);
    }
    g<<sol[0]-1<<"\n";

    return 0;
}
