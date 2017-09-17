# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("ecuatie.in");
ofstream g("ecuatie.out");
int i,j,n,m,a,b,A,B,R,x,y,z;
int st[5];
void back (int k)
{
    if (k==4)
    {
        x=st[1]; y=st[2]; z=st[3];
        if (B*(x*y+x*z+y*z)==A*x*y*z)
        {
            g<<st[1]<<" "<<st[2]<<" "<<st[3]<<"\n";
        }
    }
    else
    {
        for (int i=st[k-1]; i<=100; ++i)
        {
            st[k]=i;
            back(k+1);
            st[k]=0;
        }
    }
}
int main ()
{
    f>>a>>b; A=a; B=b;

    st[0]=1;
    back(1);

    return 0;
}
