# include <fstream>
# include <cstring>
# define NR 2005
using namespace std;
ifstream f("fold.in");
ofstream g("fold.out");
int i,j,n,m,VV,k,cs,I,K,G,L;
int put[20], nr[255][NR],var[NR];
short biti[1<<17+5];
long long maxx;
void preprocesare ()
{
    int i,j;
    put[0]=1;
    for (i=1; i<=16; ++i)
        put[i]=put[i-1]*2;

    for (i=1; i<=put[16]; ++i)
    {
        int nr=i;
        for (j=16; j>=0; --j)
            if (nr>=put[j]) nr-=put[j], ++biti[i];
    }
}
int main ()
{
    preprocesare ();
    f>>n>>m; cs=m/16+1;
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            f>>var[j];

        for (j=1; j<=cs; ++j)
        {
            K=0; I=(j-1)*16;
            for (k=1; k<=16; ++k)
                if (var[I+k]) K=K+put[k-1];

            nr[i][j]=K;
        }
    }

    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
        {
            G=0;
            for (k=1; k<=cs; ++k)
                G=G + biti[nr[i][k] & nr[j][k]];

            maxx=maxx + 1LL*G*(G-1)/2;
        }

    g<<maxx<<"\n";
    return 0;
}
