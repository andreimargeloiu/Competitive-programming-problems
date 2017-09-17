# include <cstdio>
using namespace std;
int i,j,n,x,timp,VV,nrsol,NR,v;
int st[10],pus[15][15],mat[35][10],ap[15],a[15][15],SOL[50],loc[50];
void back (int niv)
{
   int i,j,ok,var[6],PUS[6];
   if (niv==2*n+1)
   {
       ++nrsol;
       if (nrsol==1)
          for (i=1; i<=2*n; ++i)
              SOL[i]=st[i];
   }
   else
   {
        for (i=st[niv-1]+1; i<=NR; ++i)
        {
            ok=1; st[niv]=i;
            if (ap[niv]==1)//linie
            {
                for (j=1; j<=n; ++j)
                    var[j]=a[loc[niv]][j],PUS[j]=pus[loc[niv]][j];
                for (j=1; j<=n; ++j)
                {
                    if (pus[loc[niv]][j] && a[loc[niv]][j]!=mat[st[niv]][n-j+1]) ok=0;//daca mai e cineva si nu se potriveste
                    if (pus[loc[niv]][j] && a[loc[niv]][j]==mat[st[niv]][n-j+1]) pus[loc[niv]][j]=niv;//se potriveste
                    if (!pus[loc[niv]][j]) a[loc[niv]][j]=mat[st[niv]][n-j+1], pus[loc[niv]][j]=niv;//daca nu e nimeni
                }
                if (ok) back(niv+1);
                for (j=1; j<=n; ++j)
                    a[loc[niv]][j]=var[j],pus[loc[niv]][j]=PUS[j];
            }
            else//coloana
            {
                for (j=1; j<=n; ++j)
                    var[j]=a[j][loc[niv]],PUS[j]=pus[j][loc[niv]];
                for (j=1; j<=n; ++j)
                {
                    if (pus[n-j+1][loc[niv]] && a[n-j+1][loc[niv]]!=mat[st[niv]][j]) ok=0;//daca mai e cineva si nu se potriveste
                    if (pus[n-j+1][loc[niv]] && a[n-j+1][loc[niv]]==mat[st[niv]][j]) pus[n-j+1][loc[niv]]=niv;//se potriveste
                    if (!pus[n-j+1][loc[niv]]) a[n-j+1][loc[niv]]=mat[st[niv]][j], pus[n-j+1][loc[niv]]=niv;//daca nu e nimeni
                }
                if (ok) back(niv+1);
                for (j=1; j<=n; ++j)
                    a[j][loc[niv]]=var[j],pus[j][loc[niv]]=PUS[j];
            }
        }
    }
}
int main ()
{
    freopen ("magic2.in", "r", stdin);
    freopen ("magic2.out", "w", stdout);
    scanf ("%d%d", &x, &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &v);
        ap[v]=1;//linie
        loc[v]=i;
    }
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &v);
        ap[v]=2;//coloana
        loc[v]=i;
    }
    if (n==3) NR=7;
    if (n==4) NR=15;
    if (n==5) NR=31;
    for (i=0; i<=31; ++i)
    {
        int var=0,I=i;
        while (I>0)
        {
            mat[i][++var]=I%2;
            I=I/2;
        }
    }
    st[0]=-1;
    back (1);
    if (x==1) printf ("%d\n", nrsol);
        else {
                 for (i=1; i<=2*n; ++i)
                 {
                     for (j=n; j>=1; --j)
                         if (mat[SOL[i]][j]==0) printf ("1");
                            else printf("9");
                 }
             }

    return 0;
}
