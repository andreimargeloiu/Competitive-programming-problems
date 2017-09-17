# include <fstream>
using namespace std;
ifstream f("romane.in");
ofstream g("romane.out");
int i,j,n,p,v[10];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        p=i;
        while (p)
        {
          if (p>=100 && p<=400)
            {
               v[5]=v[5]+1;
               p=p-100;
            }
          if (p>=90 && p<=99)
            {
               v[5]=v[5]+1;
               v[3]=v[3]+1;
               p=p-90;
            }
          if (p>=50 && p<=89)
            {
               v[4]=v[4]+1;
               p=p-50;
            }
          if (p>=40 && p<=49)
            {
               v[4]=v[4]+1;
               v[3]=v[3]+1;
               p=p-40;
            }
          if (p>=10 && p<=39)
            {
               v[3]=v[3]+1;
               p=p-10;
            }
          if (p==9)
            {
               v[3]=v[3]+1;
               v[1]=v[1]+1;
               p=p-9;
            }
          if (p>=5 && p<=8)
            {
               v[2]=v[2]+1;
               p=p-5;
            }
          if(p==4)
            {
               v[2]=v[2]+1;
               v[1]=v[1]+1;
               p=p-4;
            }
          if (p>=1 && p<=3)
            {
               v[1]=v[1]+1;
               p=p-1  ;
            }
        }
    }
    for (i=1; i<=5; ++i)
        g<<v[i]<<" ";
    g<<"\n";

    return 0;
}
