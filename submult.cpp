# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
vector <int> v[1005];
ifstream f("submult.in");
ofstream g("submult.out");
int i,j,n,m,S,nr,nr1,nr2,a[12],maxx,VV,o;
void back (int k)
{
    if (k==11)
    {
        v[S].push_back(nr);
    }
    else
    {
        //nu il iau
        back(k+1);

        //il iau
        S+=a[k]; nr=nr+(1<<(k-1));
        back(k+1);
        S-=a[k]; nr=nr-(1<<(k-1));
    }
}
int main ()
{
    for (i=1; i<=10; ++i)
        f>>a[i];

    back (1);

    for (i=1; i<=1000; ++i)
    {
        if (v[i].size())
        {
            for (j=0; j<v[i].size(); ++j)
                for (o=j+1; o<v[i].size(); ++o)
                    if ((v[i][j] & v[i][o])==0)
                    {
                        ++VV; maxx=i; nr1=v[i][j]; nr2=v[i][o];
                    }
        }
    }
    g<<VV<<" "<<maxx<<"\n";
    for (i=11; i>=0; --i)
        if (nr1&(1<<i)) g<<a[i+1]<<" ";
    g<<"\n";
    for (i=11; i>=0; --i)
        if (nr2&(1<<i)) g<<a[i+1]<<" ";
    g<<"\n";

    return 0;
}
