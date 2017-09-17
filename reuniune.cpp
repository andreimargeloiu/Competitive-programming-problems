# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("reuniune.in");
ofstream g("reuniune.out");
int i,x1,x2,y,y2;
struct elem
{
    long long x1,x2,y,y2;
}a[5];
long long A,P,xst,xdr,ysus,yjos;
int main ()
{
    for (i=1; i<=3; ++i)
    {
        f>>x1>>y>>x2>>y2;
        a[i].x1=min(x1,x2); a[i].y=max(y,y2);
        a[i].x2=max(x1,x2); a[i].y2=min(y,y2);
        P+=2*(a[i].x2-a[i].x1)+2*(a[i].y-a[i].y2);
        A+=(a[i].x2-a[i].x1)*(a[i].y-a[i].y2);
    }
    //scad 1*2
    xst=max(a[1].x1,a[2].x1); xdr=min(a[1].x2,a[2].x2);
    ysus=min(a[1].y,a[2].y); yjos=max(a[1].y2,a[2].y2);
    if (xst<=xdr && yjos<=ysus)
    {
        P=P-2*(xdr-xst)-2*(ysus-yjos);
        A=A-(xdr-xst)*(ysus-yjos);
    }
    //adun 1*2*3
    xst=max(xst,a[3].x1); xdr=min(xdr,a[3].x2);
    ysus=min(ysus,a[3].y); yjos=max(yjos,a[2].y2);
    if (xst<=xdr && yjos<=ysus)
    {
        P=P+2*(xdr-xst)+2*(ysus-yjos);
        A=A+(xdr-xst)*(ysus-yjos);
    }
    //scad 1*3
    xst=max(a[1].x1,a[3].x1); xdr=min(a[1].x2,a[3].x2);
    ysus=min(a[1].y,a[3].y); yjos=max(a[1].y2,a[3].y2);
    if (xst<=xdr && yjos<=ysus)
    {
        P=P-2*(xdr-xst)-2*(ysus-yjos);
        A=A-(xdr-xst)*(ysus-yjos);
    }
    //scad 2*3
    xst=max(a[2].x1,a[3].x1); xdr=min(a[2].x2,a[3].x2);
    ysus=min(a[2].y,a[3].y); yjos=max(a[2].y2,a[3].y2);
    if (xst<=xdr && yjos<=ysus)
    {
        P=P-2*(xdr-xst)-2*(ysus-yjos);
        A=A-(xdr-xst)*(ysus-yjos);
    }
    g<<A<<" "<<P<<"\n";
    return 0;
}
