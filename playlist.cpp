# include <fstream>
using namespace std;
ifstream f("playlist.in");
ofstream g("playlist.out");
int i,j,n,nr,ok,VV,x,y;
int a[50][50],ap[50],sol[50];
void back (int k)
{
    int i;
    if (k==n+1)
    {
        for (i=1; i<=n; ++i)
            g<<sol[i]<<" ";
        g<<"\n";
        ok=1;
    }
    if (!ok)
    {
        for (i=1; i<=n; ++i)
        {
            if (!a[sol[VV]][i] && !ap[i])
            {
                ap[i]=1;
                sol[++VV]=i;
                back (k+1);
                ap[i]=0;
                --VV;
            }
        }
    }
}
int main ()
{
    f>>n>>nr;
    for  (i=1; i<=nr; ++i)
    {
        f>>x>>y;
        a[x][y]=1; a[y][x]=1;
    }
    back (1);

    return 0;
}
