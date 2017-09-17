# include <cstdio>
# include <algorithm>
# define NR 300005
# define inf 999999999
using namespace std;
struct elem {
    int x, y, z;
}a[NR];
int i,j,n,m,x,y,m1,m2,M1,M2,min1,min2,max1,max2,maxx,I,J,s1,s2,s3,M;
void solutie (int min1, int max1, int m1, int M1)
{
    if (min1 + max1 > maxx) maxx=min1 + max1, I=m1, J=M1;
    else if (min1 + max1==maxx && (m1<I || (m1==I && M1<J)))
         I=m1, J=M1;
}
int main ()
{
    freopen ("stelar.in", "r", stdin);
    freopen ("stelar.out", "w", stdout);

    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d%d%d", &a[i].x, &a[i].y, &a[i].z);

    for (s1=-1; s1<=1; s1+=2)
        for (s2=-1; s2<=1; s2+=2)
            for (s3=-1; s3<=1; s3+=2) {
                max1=-inf; max2=-inf; min1=-inf; min2=-inf;
                for (i=1; i<=n; ++i) {
                    m=s1*a[i].x + s2*a[i].y + s3*a[i].z;
                    M=-(s1*a[i].y + s2*a[i].z + s3*a[i].x);

                    if (m>min1) min2=min1, m2=m1, min1=m, m1=i;
                    else if (m>min2) min2=m, m2=i;

                    if (M>max1) max2=max1, M2=M1, max1=M, M1=i;
                    else if (M>max2) max2=M, M2=i;
                }

                // vedem daca e maxim general
                if (m1!=M1) solutie (min1, max1, m1, M1);
                if (m1!=M2) solutie (min1, max2, m1, M2);
                if (m2!=M1) solutie (min2, max1, m2, M1);
                if (m2!=M2) solutie (min2, max2, m2, M2);
            }
    printf ("%d %d\n", I, J);

    return 0;
}
