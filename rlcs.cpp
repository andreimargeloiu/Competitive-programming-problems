# include <cstdio>
# include <algorithm>
# include <vector>
# include <cstring>
# define LB(p) ((-p)&p)
# define NR 10005
using namespace std;
vector <int> ap[2*NR];
int n,m,i,j,VV,VV2,x;
int a[NR], b[NR], var[2*NR];
short A[NR], B[NR], B2[NR], maxx;
void normalizare ()
{
    sort (var+1, var+VV+1);
    for (int i=1; i<=VV; ++i)
        if (var[i]!=var[i-1]) var[++VV2]=var[i];

    for (int i=1; i<=n; ++i) a[i]=lower_bound (var+1, var+VV2+1, a[i])-var;
    for (int i=1; i<=m; ++i) {
        b[i]=lower_bound (var+1, var+VV2+1, b[i])-var;
        ap[b[i]].push_back(i);
    }
}
short maxim (int stop)
{
    short maxx=0;
    for (int i=stop; i>=1; i-=LB(i))
        maxx=max(maxx, B[i]);

    return maxx;
}
void update (int start, short val)
{
    for (int i=start; i<=m; i+=LB(i))
        B2[i]=max(B2[i], val);
}
int main ()
{
    freopen ("rlcs.in", "r", stdin);
    freopen ("rlcs.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; ++i) {scanf ("%d", &a[i]); var[++VV]=a[i];}
    for (j=1; j<=m; ++j) {scanf ("%d", &b[j]); var[++VV]=b[j];}

    normalizare ();

    for (i=1; i<=n; ++i) {
        x=a[i]; A[i]=A[i-1];

        memcpy(B2, B, sizeof(B));

        for (j=ap[x].size()-1; j>=0; --j) { //luam fiecare aparitie in B

            maxx=maxim(ap[x][j]-1);
            update (ap[x][j], maxx+1);

            A[i]=max(A[i], (short)(maxx+1));
        }

        memcpy(B, B2, sizeof(B2));
    }
    printf ("%d\n", A[n]);


    return 0;
}
