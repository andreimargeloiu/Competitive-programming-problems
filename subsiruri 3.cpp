# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define MOD 666013
# define LB(p) ((-p)&p)
# define NR 1000005
using namespace std;
ifstream f("subsiruri3.in");
ofstream g("subsiruri3.out");
int i,j,n,m,x,y,ci,cs,T,K,VV;
int a[NR], cp[NR];
int AIB[NR];
int cb (int k)
{
    // imi trebuie prima >=k
    int ci=1, cs=VV, mij, sol=1;
    while (ci<=cs){
        mij=(ci+cs)/2;
        if (k<=a[mij]) cs=mij-1, sol=mij;
                  else ci=mij+1;
    }
    return sol;
}
void etalonare ()
{
    a[0]=-5; sort (a+1, a+n+1);
    for (int i=1; i<=n; ++i)
        if (a[i]!=a[i-1]) a[++VV]=a[i];
}
void adauga (int poz, int val){
    for (int i=poz; i<=n; i+=LB(i)) {
        AIB[i]+=val;
        if (AIB[i]>=MOD) AIB[i]-=MOD;
    }
}
int numara (int poz){
    int sol=0;
    for (int i=poz; i>=1; i-=LB(i)) {
        sol+=AIB[i];
        if (sol>=MOD) sol-=MOD;
    }
    return sol;
}
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t) {
        memset (AIB, 0, sizeof(AIB));
        memset (a, 0, sizeof(a)); VV=0;
        memset (cp, 0, sizeof(cp));
        f>>n>>K;
        for (i=1; i<=n; ++i) {
            f>>a[i]; cp[i]=a[i];
        }
        etalonare ();

        for (i=1; i<=n; ++i) {
            ci=cb(cp[i]-K);
            cs=cb(cp[i]);

            adauga(cs, (1LL+numara(cs)-numara(ci-1)+MOD)%MOD);
        }
        g<<numara(n)<<"\n";
    }


    return 0;
}
