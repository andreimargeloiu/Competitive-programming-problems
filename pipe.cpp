# include <fstream>
# include <algorithm>
# include <cstring>
using namespace std;
ifstream f("pipe.in");
ofstream g("pipe.out");
int i,j,n,xi,xf,yi,yf,co,cv,x,X,Y,var=999999,init=32000;
int O[105], V[105], oriz[65000], vert[65000], apo[65000], apv[65000];
char ch;
void verticala ()
{
    int i,j,minn=init, maxx=init;
    for (i=1; i<=64999; ++i)
        vert[i]=var;
    vert[init]=0;
    for (i=1; i<=cv; ++i)
    {
        for (j=minn; j<=maxx; ++j)
        {
            if (vert[j]!=var && apv[j]<i)
            {
                if(vert[j-V[i]]>vert[j]+V[i])
                {
                    apv[j-V[i]]=i;
                    vert[j-V[i]]=vert[j]+V[i];
                    minn=min(minn,j-V[i]);
                }
                if(vert[j+V[i]]>vert[j]+V[i])
                {
                    apv[j+V[i]]=i;
                    vert[j+V[i]]=vert[j]+V[i];
                    maxx=max(maxx,j+V[i]);
                }
            }
        }
    }
}
void orizontala ()
{
    int i,j,minn=init, maxx=init;
    for (i=1; i<=64999; ++i)
        oriz[i]=var;
    oriz[init]=0;
    for (i=1; i<=co; ++i)
    {
        for (j=minn; j<=maxx; ++j)
        {
            if (oriz[j]!=var && apo[j]<i)
            {
                if(oriz[j-O[i]]>oriz[j]+O[i])
                {
                    apo[j-O[i]]<i;
                    oriz[j-O[i]]=oriz[j]+O[i];
                    minn=min(minn,j-O[i]);
                }
                if(oriz[j+O[i]]>oriz[j]+O[i])
                {
                    apo[j+O[i]]=i;
                    oriz[j+O[i]]=oriz[j]+O[i];
                    maxx=max(maxx,j+O[i]);
                }
            }
        }
    }
}
int main ()
{
    f>>n;
    f>>xi>>yi>>xf>>yf;
    for (i=1; i<=n; ++i)
    {
        f>>ch>>x;
        if (ch=='A') O[++co]=x;
           else V[++cv]=x;
    }
    X=xi; Y=yi;
    orizontala ();
    verticala ();
    if (oriz[init+xf-xi]==var || vert[init+yf-yi]==var) g<<"imposibil\n";
        else g<<oriz[init+xf-xi]+vert[init+yf-yi]<<"\n";

    return 0;
}
