# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 1005
using namespace std;
struct elem
{
    int x, y;
}a[NR*10], b[NR*10];
int i,j,n,m,t,x,y,tip,nra,nrb,vopsite,nr2,ci,cs,mij,sol;
int mat[NR][NR];

int minim (int x, int y, int z)
{
    return min(min(x, y), z);
}
void A (int x, int y, int k)
{
    int I=x, J=y, pasi=-1;
    while (I>0 && J<=n)
    {
        ++pasi;
        if (pasi>mij) break;

        mat[I][J]+=k;
        --I; ++J;
    }
    pasi=0; I=x+1, J=y-1;
    while (I<=n && J>=1)
    {
        ++pasi;
        if (pasi>mij) break;

        mat[I][J]+=k;
        ++I; --J;
    }
}
void B (int x, int y, int k)
{
    int I=x, J=y, pasi=-1;
    while (I>0 && J>0)
    {
        ++pasi;
        if (pasi>mij) break;;
        mat[I][J]+=k;

        --I; --J;
    }
    pasi=0; I=x+1, J=y+1;
    while (I<=n && J<=n)
    {
        ++pasi;
        if (pasi>mij) break;
        mat[I][J]+=k;

        ++I; ++J;
    }
}
void curata ()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            mat[i][j]=0;
}
bool numara ()
{
    int S=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (mat[i][j]==2) ++S;
    if (S>=4)
    {
        /*
        if (S>4)
        {
            for (int i1=1; i1<=n; ++i1)
            {
                for (int j1=1; j1<=n; ++j1)
                    printf ("%d ", mat[i1][j1]);
                printf ("%d\n");
            }
            printf ("%d\n");
        }
        */
        return 1;
    }
    else return 0;
}
int verificare ()
{
    int i1,i2,j1,j2;
    for (i1=1; i1<=nra; ++i1)
    {
        A (a[i1].x, a[i1].y, 1);
        for (i2=i1+1; i2<=nra; ++i2)
        {
            A (a[i2].x, a[i2].y, 1);
            for (j1=1; j1<=nrb; ++j1)
            {
                B (b[j1].x, b[j1].y, 1);

                for (j2=j1+1; j2<=nrb; ++j2)
                {
                    B (b[j2].x, b[j2].y, 1);

                    //verificam
                    if (numara())
                    {
                        //   BONUS

                        /*
                        printf ("la timpul %d, urmatoarele puncte formeaza un dreptunghi (tip1, tip1, tip2, tip2)\n", mij);
                        printf ("%d %d\n%d %d\n%d %d\n%d %d\n\n\n", a[i1].x, a[i1].y, a[i2].x, a[i2].y, b[j1].x, b[j1].y, b[j2].x, b[j2].y);
                        */

                        return 1; //daca sunt 4 puncte cu grad 2
                    }

                    B (b[j2].x, b[j2].y, -1);
                }
                B (b[j1].x, b[j1].y, -1);
            }
            A (a[i2].x, a[i2].y, -1);
        }
        A (a[i1].x, a[i1].y, -1);
    }
    return 0;
}
int main ()
{
    freopen ("robotics.in", "r", stdin);
    freopen ("robotics.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &t);
    //punctul a
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &tip);
        if (tip==1)
        {
            a[++nra].x=x; a[nra].y=y;
            vopsite+=1 + minim (x-1, n-y, t) + minim (n-x, y-1, t);
        }
        if (tip==2)
        {
            b[++nrb].x=x; b[nrb].y=y;
            vopsite+=1 + minim (x-1, y-1, t) + minim (n-x, n-y, t);
        }
    }
    printf ("%d\n", vopsite);

    //punctul b
    ci=1; cs=n;
    while (ci<=cs)
    {
        curata ();
        mij=(ci+cs)/2;
        if (verificare ()) sol=mij, cs=mij-1;
                              else  ci=mij+1;
    }
    printf ("%d\n", sol);

    return 0;
}
