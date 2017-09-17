# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("meciul.in");
ofstream g("meciul.out");
int i,j,n,m,o,t,x,y;
int echipa[NR];
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        memset (echipa, 0, sizeof(NR));
        f>>n>>m;

        for (i=1; i<=m; ++i)
        {
            f>>x>>y;
            if (x==y) {g<<"NO\n"; continue;}
            if (echipa[x]==0 && echipa[y]==0)//daca nu sunt selectate
            {
                echipa[x]=1; echipa[y]=2;
                g<<"YES\n";
                continue;
            }
            if (echipa[x]==echipa[y]) //daca sunt in aceiasi echipa
            {
                g<<"NO\n";
                continue;
            }
            if (echipa[x]+echipa[y]==3) //daca sunt in echipe diferite
            {
                g<<"YES\n";
                continue;
            }
            if (echipa[x] || echipa[y])
            {
                if (echipa[x])
                {
                    echipa[y]=3-echipa[x];
                    g<<"YES\n";
                    continue;
                }
                else
                {
                    echipa[x]=3-echipa[y];
                    g<<"YES\n";
                    continue;
                }
            }
        }
    }
    return 0;
}
