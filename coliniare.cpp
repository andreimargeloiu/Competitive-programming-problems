# include <fstream>
# include <algorithm>
# define refz 500
# define ref 100
using namespace std;
ifstream f("coliniare.in");
ofstream g("coliniare.out");
short hash[205][205][1005];
struct elem
{
    int x,y;
}v[1005];
int i,j,n,m,x,y,z,xa,ya,xb,yb,a,b,maxx,p1,p2;
int imp[205][205];
int cmmdc (int a, int b)
{
    int R=0;
    while (b!=0)
    {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
void procesare ()
{
    int i,j;
    for (i=-50; i<=50; ++i)
        for (j=-50; j<=50; ++j)
            imp[ref+i][ref+j]=cmmdc(i,j);
}
int main ()
{
    procesare();

    f>>n;
    for (i=1; i<=n; ++i)
        f>>v[i].x>>v[i].y;

    for (a=1; a<=n; ++a)
    {
        for (b=a+1; b<=n; ++b)
            if (a!=b)
            {
                xa=v[a].x; xb=v[b].x;
                ya=v[a].y; yb=v[b].y;

                p1=yb-ya; p2=xb-xa;

                int var=imp[ref+p1][ref+p2];
                p1/=var; p2/=var;

                x=ref+p1;
                y=ref-p2;
                z=refz+xa*p1-ya*p2;

                ++hash[x][y][z];
                if (maxx<hash[x][y][z]) maxx=hash[x][y][z];
            }
    }
    for (i=1; i<=50; ++i)
        if ((i-1)*i/2==maxx) {maxx=i; break;}

    g<<maxx<<"\n";

    return 0;
}
