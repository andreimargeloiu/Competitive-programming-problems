#include<cmath>
#include<fstream>
#include<algorithm>
#define NMAX 3000
#define PI 3.141592653589
using namespace std;
struct cuib
{
    int xA,xB,yA,yB;
    int r,t;
}v[NMAX];
int n,Max;
int l[NMAX];
double aria(cuib p)
{
    if (p.t==0)
        return (p.xB-p.xA) * (p.yB-p.yA);
    return p.r*p.r*PI;
}

int cmp(cuib i,cuib j)
{
    return aria(i)>aria(j);
}

double dist(int x1, int y11, int x2, int y2)
{
    return sqrt((double)(x2-x1)*(x2-x1) + (y2-y11)*(y2-y11));
}

int verif(int i, int j)
{

    if (v[i].t==0 && v[j].t ==0)
    //doua dreptunghiuri
        return v[j].xA <= v[i].xA && v[i].xB <= v[j].xB && v[j].yA <= v[i].yA && v[i].yB <=v[j].yB;

    if (v[i].t ==1 && v[j].t ==1)
    //doua cercuri
        return dist(v[i].xA,v[i].yA, v[j].xA, v[j].yA) + v[i].r <= v[j].r;

    if (v[i].t ==1 && v[j].t ==0)
    //cerc dreptunghi
        return v[j].xA <= v[i].xA-v[i].r && v[i].xA+v[i].r <= v[j].xB && v[j].yA <= v[i].yA-v[i].r && v[i].yA+v[i].r <=v[j].yB;

    //dreptunghi cerc
    return dist(v[j].xA, v[j].yA, v[i].xA, v[i].yA) <= v[j].r && dist(v[j].xA, v[j].yA, v[i].xA, v[i].yB) <= v[j].r &&
        dist(v[j].xA, v[j].yA, v[i].xB, v[i].yB) <= v[j].r && dist(v[j].xA, v[j].yA, v[i].xB, v[i].yA) <= v[j].r;
}

int main() {
    ifstream f("cuiburi.in");
    ofstream g("cuiburi.out");
    f>>n;
    for (int i=1;i<=n;++i)
    {
        f>>v[i].t;
        if (v[i].t==0) f>>v[i].xA>>v[i].yA>>v[i].xB>>v[i].yB;
            else f>>v[i].xA>>v[i].yA>>v[i].r;
    }
    sort(v+1,v+n+1,cmp);
    for (int i=1;i<=n;++i)
    {
        l[i]=1;
        for (int j=1;j<i;++j)
            if (verif(i,j) && l[j]+1>l[i])
                {
                    l[i]=l[j]+1;
                    if (l[i]>Max) Max=l[i];
                }
    }

    g<<Max;
    return 0;
}
