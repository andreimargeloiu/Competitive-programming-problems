# include <cstdio>
# include <algorithm>
# define NR 1505
using namespace std;
struct elem
{
    int nr, dist;
}sol[NR*3];
bool cmp (elem x, elem y)
{
    if (x.dist>=y.dist) return 0;
                   else return 1;
}
int i,j,n,m,x,y,VV,nrelem;
bool ap[NR*NR], mat[NR][NR];
int a[NR][NR], X[NR*NR], Y[NR*NR];
char tmp[NR*75];
void sterge (int x, int y)
{
    int i,j;

    //dreapta - sus
    for (i=x-1; i>=1; --i)
    {
        if (mat[i][y+1]) break;
        for (j=y+1; j<=m; ++j)
        {
            if (mat[i][j]) break;
            mat[i][j]=1; ap[a[i][j]]=1;
        }
    }

    //stanga - sus
    for (i=x+1; i<=n; ++i)
    {
        if (mat[i][y-1]) break;
        for (j=y-1; j>=1; --j)
        {
            if (mat[i][j]) break;
            mat[i][j]=1; ap[a[i][j]]=1;
        }
    }
}
int main ()
{
    freopen ("bemo.in", "r", stdin);
    freopen ("bemo.out", "w", stdout);

	freopen("bemo.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for (int i =1; i<= n; i++)
    {
        fgets(tmp, 65536, stdin);
        char *p = tmp;
        for (int j = 1; j <= m; j++)
        {
            int val = 0;
            for (; '0' <= *p && *p <= '9'; p++)
            {
                val = val * 10 + *p - '0';
            }
            for (; '0' > *p || *p > '9'; p++);
        	a[i][j] = val;
			X[a[i][j]] = i;
			Y[a[i][j]] = j;
        }
    }




    nrelem=n*m;
    for (i=1; i<=nrelem; ++i)
        if (! ap[i])
        {
            sol[++VV].nr=i; sol[VV].dist=X[i] + Y[i];
            sterge (X[i], Y[i]);
        }

    sort (sol+1, sol+VV+1, cmp);
    for (i=1; i<=VV; ++i)
        printf ("%d ", sol[i].nr);
    printf ("\n");


    return 0;
}
