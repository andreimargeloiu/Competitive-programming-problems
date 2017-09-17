# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 1100005
using namespace std;
ifstream f("biti.in");
ofstream g("biti.out");
int i,j,n,m,VV,nr,maxx,ok;
int st[NR], ap[1<<21];
queue <int> q;
void back (int k, int niv)
{
    if (ok) return;
    if (niv==maxx)
    {
        ok=1;
        g<<VV<<"\n";
        for (i=1; i<=VV; ++i)
            g<<st[i];
        g<<"\n";
    }
    else {
             ap[k]=1;

             int nr;
             nr=k*2; //cu 0
             if (nr>=maxx) nr-=maxx;
             if (! ap[nr])
             {
                 st[++VV]=0;
                 back (nr, niv+1);
                 st[VV]=0; --VV;
             }

             nr=k*2+1; //cu 1
             if (nr>=maxx) nr-=maxx;
             if (! ap[nr])
             {
                 st[++VV]=1;
                 back (nr, niv+1);
                 st[VV]=0; --VV;
             }

             ap[k]=0;
         }
}
int main ()
{
    f>>n;
    maxx=(1<<n);
    for (i=1; i<=n; ++i) st[++VV]=0;

    back (0, 1);

    return 0;
}
