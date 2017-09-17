# include <fstream>
# include <algorithm>
# define NR 100005
using namespace std;
ifstream f("permutare2.in");
ofstream g("permutare2.out");
int i,j,n,m,x,ci,cs,mij,sus,jos;
int ap[2*NR];
long long Ssus,Sjos,stanga[2*NR], dreapta[2*NR], minn;
int main ()
{
    f>>m>>n;
    for (i=1; i<=m; ++i)
        f>>x;

    ap[0]=1;
    for (i=2; i<=n; ++i)
    {
        f>>x;
        ++ap[x];
    }

    for (i=0; i<m; ++i)
        ap[i+m]=ap[i];

    mij=(m+1)/2;
    ci=mij-1; cs=m-mij;

    int stop=2*m-1-cs;

    for (i=0; i<=2*m+1; ++i)
    {
        Sjos+=jos; stanga[i]=Sjos;
        jos+=ap[i];

        if (i>=ci)
        {
            Sjos-=ap[i-ci]*ci;
            jos-=ap[i-ci];
        }
    }

    for (i=2*m-1; i>=0; --i)
    {
        Ssus+=sus; dreapta[i]=Ssus;
        sus+=ap[i];

        if (i<=stop)
        {
            Ssus-=ap[i+cs]*cs;
            sus-=ap[i+cs];
        }
    }

    minn=1LL<<60;
    for (i=ci; i<=stop; ++i)
        minn=min(minn, stanga[i]+dreapta[i]);


    g<<minn<<"\n";


    return 0;
}
