# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 1005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,n,m,x,y;
char s[NR];
int main ()
{

    while (f.getline (s, NR)) {
        g<<s;
        if (s[0]=='#') g<<"\n";
                  else g<<" ";
    }

    return 0;
}
