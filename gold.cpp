#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("gold.in");
ofstream fout("gold.out");
struct punct
{
    int x,y,nr;
} v[1028];
int n,k,sol,gr1,gr2;
int cadran(punct A)
{
    if (A.y>v[0].y)
    {
        if (A.x>v[0].x) return 1;
        else return 2;
    }
    else
    {
        if (A.x<v[0].x) return 3;
        else return 4;
    }
}
int det(punct A, punct B, punct C)
{
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
bool cmpx(punct A, punct B)
{
    if (A.x!=B.x) return A.x<B.x;
             else return A.y>B.y;
}
bool cmpdet(punct A, punct B)
{
    int c1=cadran(A), c2=cadran(B);
    if ((c1&1)!=(c2&1))
    {
        if (c1&1) return false;
             else return true;
    }
    if (A.x==v[0].x) return true;
    if (B.x==v[0].x) return false;
    if (c1==c2)
        return det(v[0],A,B)>0;
    else
        return det(v[0],A,B)<0;
}
int main()
{
    int i,j;
    fin>>n>>k;
    for (i=1; i<=n; ++i)
        fin>>v[i].nr;
    for (i=1; i<=n; ++i)
        fin>>v[i].x>>v[i].y;

    sort(v+1, v+n+1, cmpx); // X- cresc,  Y- descresc

    for (i=1; i<=n; ++i)
    {
        gr1=gr2=0;
        for (j=1; j<i; ++j) gr1+=v[j].nr;
        for (j=i+1; j<=n; ++j) gr2+=v[j].nr;
        v[0]=v[i], v[i]=v[1], v[1]=v[0];
        sort(v+2, v+n+1, cmpdet);
        for (j=2;j<=n;++j)
        {
            if (cmpx(v[1],v[j]))
            {
                gr2-=v[j].nr;
                if (-k<=gr2-gr1 && gr2-gr1<=k) ++sol;
                gr1+=v[j].nr;
            }
            else
            {
                gr1-=v[j].nr;
                if (-k<=gr2-gr1 && gr2-gr1<=k) ++sol;
                gr2+=v[j].nr;
            }
        }
        sort(v+1,v+n+1,cmpx);
    }
    fout<<sol/2<<"\n";
    return 0;
}
