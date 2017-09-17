# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("sah1.in");
ofstream g("sah1.out");
int i,j,n,m,x,y,VV,Ocup,ocupat,ok,p,acces,maxx,sol;
int a[105][105];
void parcurgere (int x, int y, int dx, int dy)
{
    Ocup=0; ok=0;
    while (a[x][y]==0)
    {
        x+=dx; y+=dy;
        if (a[x][y]==1) {ok=1; break;}
            else if (a[x][y]==0) ++Ocup;
    }
    if (ok) ++VV, ocupat+=Ocup;
}
int main ()
{
    f>>n>>p;
    for (i=1; i<=p; ++i)
    {
        f>>x>>y; ++a[x][y];
    }
    for (i=0; i<=n+1; ++i)
        a[0][i]=a[n+1][i]=a[i][0]=a[i][n+1]=-1;
    acces=n*n-p;
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
            if (a[i][j]==0)
            {
                VV=0; ocupat=1;
                parcurgere (i,j,-1,0); //in sus
                parcurgere (i,j,1,0); //in jos
                parcurgere (i,j,0,-1); //in st
                parcurgere (i,j,0,1); //in dr
                parcurgere (i,j,-1,1); //in dr-sus
                parcurgere (i,j,1,1); //in dr-jos
                parcurgere (i,j,1,-1); //in st-jos
                parcurgere (i,j,-1,-1); //in st-sus
                if (VV==maxx) sol=sol+(acces-ocupat);
                else if (VV>maxx) maxx=VV, sol=acces-ocupat;
            }
    }
    g<<sol<<"\n";
    return 0;
}
