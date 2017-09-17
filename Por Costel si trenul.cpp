# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("trenul.in");
ofstream g("trenul.out");
int n,m,tip,sus,jos,unu,doi,i;
int main ()
{
    f>>n>>m; sus=1; jos=n/2;

    for (i=1; i<=m; ++i) {
        f>>tip;
        if (tip==2) {
            g<<2*jos-1<<" "<<2*jos<<"\n";
            --jos;
        }
        else if (tip==1)
        {
            if (unu==0) {unu=1; g<<2*sus-1<<"\n";}
            else if (doi==0) {doi=1; g<<2*sus<<"\n";}

            if (unu==1 && doi==1) {
                unu=0; doi=0;
                ++sus;
            }
        }
        else if (tip==3)
        {
            if (unu==0 && doi==0) {
                g<<2*sus-1<<" "<<2*sus<<" "<<2*sus+1<<"\n";

                unu=1; doi=0; ++sus;
                continue;
            }
            if (unu==0) {
                g<<2*sus-1<<" "<<2*sus+1<<" "<<2*sus+2<<"\n";

                unu=0; doi=0; sus+=2;
                continue;
            }
            if (doi==0) {
                g<<2*sus<<" "<<2*sus+1<<" "<<2*sus+2<<"\n";

                unu=0; doi=0; sus+=2;
                continue;
            }
        }
    }

    return 0;
}
