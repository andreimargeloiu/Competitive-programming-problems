# include <fstream>
# include <cmath>
using namespace std;
ifstream f("medii.in");
ofstream g("medii.out");
int i,teza,st[100],VV;
float media, target, S;
void afisare (int k)
{
    ++VV;
    for (int i=1; i<=k; ++i)
        g<<st[i]<<" ";
    g<<"\n";
}
void back (int k)
{
    if (k==11) return ;
    for (int i=st[k-1]; i<=10; ++i)
    {
        st[k]=i;
        if ((S+i)/k<=target)
        {
            S+=i;
            back(k+1);
            S-=i;
        }
        if (abs((S+i)/k-target)<0.01 && k>=3)
        {
            afisare (k);
            break;
        }
        if ((S+i)/k>target) break;
    }
}
int main ()
{
    f>>media>>teza;
    target=(4*media-teza)/3;
    st[0]=1;
    back (1);

    return 0;
}
