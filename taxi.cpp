# include <fstream>
# include <algorithm>
# include <cstring>
using namespace std;
ifstream f("taxi.in");
ofstream g("taxi.out");
struct elem {
    int x, y;
}a, b, sus, jos;
int i,j,n,m,dx,dy,A,B,T,sol;
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t) {
        f>>A>>B>>a.x>>a.y>>b.x>>b.y;

        dx=abs(a.x - b.x); dy=abs(a.y - b.y);
        if(dx==dy && dx==0) {
            g<<(A+1)*(B+1)<<"\n";
            continue;
        }

        if ((dx%2 + dy%2)==1) g<<"0\n";
        else {
            if (b.x < a.x) swap(a, b);
            if (dx==dy) {
                if (b.y < a.y) {
                    sus.x=a.x; sus.y=b.y;
                    jos.x=b.x; jos.y=a.y;

                    sol=0;
                    sol+=(sus.x+1)*(sus.y+1);
                    sol+=(A-jos.x+1)*(B-jos.y+1);
                    sol+=dx-1;
                    g<<sol<<"\n";
                }
                else {
                    sus.x=b.x; sus.y=a.y;
                    jos.x=a.x; jos.y=b.y;

                    sol=0;
                    sol+=(A-sus.x+1)*(sus.y+1);
                    sol+=(B-jos.y+1)*(jos.x+1);
                    sol+=dx-1;
                    g<<sol<<"\n";
                }
            }
            else {
                    if (dx < dy) g<<A+1<<"\n";
                            else g<<B+1<<"\n";
                 }
        }
    }

    return 0;
}
