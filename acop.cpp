# include <fstream>
# include <algorithm>
# define inf 999999999
using namespace std;
ifstream f("acop.in");
ofstream g("acop.out");
struct elem
{
    int x1,y1,x2,y2;
}a[50];
int i,j,n,m,x,x2,y,y2,VV,X,Y,minim,t,nr;
int st[100],st2[100];
bool cmp (elem x, elem y)
{
    if (x.x1>y.x1) return 0;
       else if (x.x1==y.x1 && x.x2<=y.y2) return 0;
           else return 1;
}
bool cmp2 (int x, int y)
{
    if (a[x].y1>a[y].y1) return 0;
        else if (a[x].y1==a[y].y1 && a[x].y2<=a[y].y2) return 0;
            else return 1;
}
void back (int k, int minn, int maxx)
{
    int maxback=0;
    if (k==n+1)
    {
        if (maxx==X)
        {
            //verificam
            for (int i=1; i<=VV; ++i)
                st2[i]=st[i];
            sort (st2+1,st2+VV+1, cmp2);

            minn=a[st2[1]].y1;
            if (minn!=0) return;
            maxx=a[st2[1]].y2;

            for (int i=2; i<=VV; ++i)
                 if (a[st2[i]].y1<=maxx) maxx=max(maxx,a[st2[i]].y2);
                    else {maxx=0; break;}
            if (maxx<Y) return;
                else {
                         if (VV<minim) minim=VV, nr=1;
                         else if (VV==minim) ++nr;
                     }
        }
    }
    else
    {
        if (VV>minim) return;
        if (minn==inf && a[k].x1>0) return;
        if (a[k].x1<=maxx)
        {
            //nu il iau
            back(k+1,minn,maxx);
            //il iau
            st[++VV]=k;
            if (minn==inf) minn=0;
            back(k+1,minn,max(maxx,a[k].x2));
            --VV;
        }
    }
}
int main ()
{
    f>>t;
    for (i=1; i<=t; ++i)
    {
        f>>X>>Y;
        f>>n;
        for (j=1; j<=n; ++j)
        {
            f>>x>>y>>x2>>y2;
            a[j].x1=min(x,x2); a[j].y1=min(y,y2);
            a[j].x2=max(x,x2); a[j].y2=max(y,y2);
        }
        sort (a+1, a+n+1, cmp);
        minim=inf; nr=0;
        back (1,inf,0);
        if (minim==inf) g<<"-1\n";
        else g<<minim<<" "<<nr<<"\n";
    }
    return 0;
}
