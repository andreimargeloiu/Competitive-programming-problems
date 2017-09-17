# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 200005
# define Q 200000
using namespace std;
ifstream f("fsb.in");
ofstream g("fsb.out");
int i,j,n,m,VV,S,l;
int ap[2*NR];
char s[NR];
int main ()
{
    f>>l; f.get();
    f.getline(s+1, NR);
    for (i=1; i<=l; ++i)
    {
        if (s[i]=='1') ++S;
        else --S;

        ++ap[Q+S];
    }
    VV=ap[Q];
    for (i=1; i<=2*Q; ++i)
        VV=VV+ap[i]*(ap[i]-1)/2;

    g<<VV<<"\n";

    return 0;
}
