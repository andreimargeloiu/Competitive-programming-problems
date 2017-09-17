# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,x,y,VV,S,nr,o,q,lv,cv,rez,I,la,ca,Vact;
int a[65005], mat[60][60][60];
int dx[]={0,0,1,1};
int dy[]={0,1,0,1};
int main ()
{
    freopen ("suma4.in", "r", stdin);
    freopen ("suma4.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);

    for (i=1; i<=60; ++i)
    {
        if (i*(i+1)*(2*i+1)/6==n) {VV=i; break;}
    }
    rez=n-VV*VV;
    for (i=1; i<=VV; ++i)
        for (j=1; j<=VV; ++j)
        {
            nr=rez+(i-1)*VV+j;
            mat[i][j][VV]=a[nr];
        }
    for (q=VV-1; q>=1; --q)
    {
        rez=rez-q*q;
        for (i=1; i<=q; ++i)
            for (j=1; j<=q; ++j)
            {
                nr=rez+(i-1)*q+j;
                for (o=0; o<4; ++o)
                {
                    lv=i+dx[o]; cv=j+dy[o];
                    if (mat[i][j][q]==0 || mat[lv][cv][q+1]+a[nr]<mat[i][j][q])
                        mat[i][j][q]=mat[lv][cv][q+1]+a[nr];
                }
            }
    }
    printf ("%d %d\n1 ", VV, mat[1][1][1]);
    la=1; ca=1; Vact=1; rez=0;
    while (Vact<VV)
    {
        nr=rez+(la-1)*Vact+ca;
        for (o=0; o<4; ++o)
        {
            lv=la+dx[o]; cv=ca+dy[o];
            if (mat[la][ca][Vact]-a[nr]==mat[lv][cv][Vact+1])
            {
                rez+=Vact*Vact;
                ++Vact; la=lv; ca=cv;
                nr=rez+(la-1)*Vact+ca;
                printf ("%d ", nr);
                break;
            }
        }
    }
    return 0;
}
