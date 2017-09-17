# include <fstream>
# include <algorithm>
# define NR 1000005
using namespace std;
ifstream f("compact2.in");
ofstream g("compact2.out");
int i,j,n,m,x,y,maxx;
int CI[NR], CS[NR], jos[NR], sus[NR];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>x;

        CI[x]=1; jos[x]=x;
        CS[x]=1; sus[x]=x;

        if (CI[x+1]) {CI[x]=CI[x+1]+1; ++CS[jos[x+1]];
                      jos[x]=jos[x+1]; sus[jos[x+1]]=x;}

        if (CS[x-1]) {CS[x]=CS[x-1]+1; ++CI[sus[x-1]];
                      sus[x]=sus[x-1]; jos[sus[x-1]]=x;}

        maxx=max(maxx, CI[x]);
        maxx=max(maxx, CS[x]);
    }

    g<<maxx<<"\n";


    return 0;
}
