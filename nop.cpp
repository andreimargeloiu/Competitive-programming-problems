# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 105
using namespace std;
ifstream f("nop.in");
ofstream g("nop.out");
int i,j,n,m,x,y,VV,T,t,l,c;
int sol[NR][NR], var[NR];
int main ()
{
    f>>T;
    for (t=1; t<=T; ++t) {
        f>>x; VV=0;
        //descompun in biti
        while (x) {
            var[++VV]=x%2;
            x=x/2;
        }

        sol[1][1]=sol[1][2]=sol[1][3]=t;
        l=1; c=3;
        for (i=VV-1; i>=1; --i) {
            if (! var[i]) {
                sol[l][c+1]=sol[l+1][c]=sol[l+1][c+1]=t;
                ++l; ++c;
            }
            else {
            sol[l+1][c]=sol[l+1][c+1]=sol[l+2][c]=sol[l+2][c+1]=t;
            l+=2; ++c;
                for (j=1; j<=c; ++j)
                    sol[l][j]=t;
            }
        }
        g<<l<<" "<<c<<"\n";
        for (i=1; i<=l; ++i) {
            sol[i][1]=t;
            for (j=1; j<=c; ++j)
                if (sol[i][j]==t) g<<"1";
                             else g<<"0";
            g<<"\n";
        }
    }

    return 0;
}
