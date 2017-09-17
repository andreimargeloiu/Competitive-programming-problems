#include<fstream>

using namespace std;
ifstream f("secvk.in");

ofstream g("secvk.out");

int n,k,i,j,a[100001],S,maxim,start,suma[100001];
int main()
{
    f>>n;
    f>>k;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
        suma[i]=suma[i-1]+a[i]; // preprocesam suma de a 1 la i
    }

    for(i=1;i<=n-k+1;i++)
    {
        S=suma[i+k-1] - suma[i-1];
        if(S>maxim)
        {
            maxim=S;
            start=i;
        }
    }
    for(i=start;i<=start+k-1;i++)
        g<<a[i]<<" ";

    return 0;
}



