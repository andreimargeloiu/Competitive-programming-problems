# include <cstdio>
# include <algorithm>
# include <deque>
# define NR 100005
using namespace std;
int i,j,n,m,x,y,K;
long long S[NR], SS[NR], a[NR][14], nr[NR];
long long suma (int I, int J, int ant) {
    long long S=0;

    S=a[J][ant] + (SS[I] -
}
int main ()
{
    freopen ("leaves.in", "r", stdin);
    freopen ("leaves.out", "w", stdout);

    scanf ("%d%d", &n, &K);

    // S[i]-  suma elementelor 1 - i
    // SS[i]- suma triunghiulara a elementelor

    for (i=1; i<=n; ++i) scanf ("%d", &nr[i]);


    for (i=n; i>=1; --i) {
        S[i]=S[i+1] + nr[i];
        SS[i]=SS[i+1] + S[i];
        a[i][1]=SS[i];
    }
    cs=n;
    for (j=2; j<=K; ++j) pentru fiecare gramada
        for (i=n; i>=1; --i) {//fiecare pozitie
            // actualizam cs
            while (i<=cs) {
                if (suma(i, cs-1, j-1) <= suma(i, cs)) --cs;
            }
        }


    return 0;
}
