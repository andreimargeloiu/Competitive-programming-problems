# include <fstream>
using namespace std;
ifstream f("pav.in");
ofstream g("pav.out");
int i,j,n,X,Y,VV;
int a[1005][1005];
int put[15]={0,2,4,8,16,32,64,128,256,512,1024};
int dx[]={0,0,0,1,1};
int dy[]={0,0,1,1,0};
void divide (int l, int c, int lat, int x, int y)
{
    int i,mi,mj;
    if (lat==1)
    {
        ++VV;
        for (i=1; i<=4; ++i)
            if (a[l+dx[i]][c+dy[i]]==0) a[l+dx[i]][c+dy[i]]=VV;
    }
    else
    {
        mi=l+put[lat-1]-1; mj=c+put[lat-1]-1; ++VV;
        if (x<=mi && y<=mj) //cadranul 1
        {
            a[mi][mj+1]=VV; a[mi+1][mj]=VV; a[mi+1][mj+1]=VV;
            divide (l,c,lat-1,x,y); //1
            divide (l,mj+1,lat-1,mi,mj+1); //2
            divide (mi+1,c,lat-1,mi+1,mj); //3
            divide (mi+1,mj+1,lat-1,mi+1,mj+1); //4
        }
        if (x<=mi && y>=mj+1) //cadranul 2
        {
            a[mi][mj]=VV; a[mi+1][mj]=VV; a[mi+1][mj+1]=VV;
            divide (l,c,lat-1,mi,mj); //1
            divide (l,mj+1,lat-1,x,y); //2
            divide (mi+1,c,lat-1,mi+1,mj); //3
            divide (mi+1,mj+1,lat-1,mi+1,mj+1); //4
        }
        if (x>mi && y<=mj) //cadranul 3
        {
            a[mi][mj]=VV; a[mi][mj+1]=VV; a[mi+1][mj+1]=VV;
            divide (l,c,lat-1,mi,mj); //1
            divide (l,mj+1,lat-1,mi,mj+1); //2
            divide (mi+1,c,lat-1,x,y); //3
            divide (mi+1,mj+1,lat-1,mi+1,mj+1); //4
        }
        if (x>mi && y>mj) //cadranul 4
        {
            a[mi][mj]=VV; a[mi][mj+1]=VV; a[mi+1][mj]=VV;
            divide (l,c,lat-1,mi,mj); //1
            divide (l,mj+1,lat-1,mi,mj+1); //2
            divide (mi+1,c,lat-1,mi+1,mj); //3
            divide (mi+1,mj+1,lat-1,x,y); //4
        }
    }
}
int main ()
{
    f>>n;
    f>>X>>Y;
    a[X][Y]=-1;
    divide (1,1,n,X,Y);
    a[X][Y]=0;
    for (i=1; i<=put[n]; ++i)
    {
        for (j=1; j<=put[n]; ++j)
            g<<a[i][j]<<" ";
        g<<"\n";
    }

    return 0;
}
