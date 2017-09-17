# include <bits/stdc++.h>
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int i,j,n,m,mask,mask1;
void descompune (int k) {
    for (int i=5; i>=0; --i)
        if (k & (1<<i)) g<<"1";
                   else g<<"0";
    g<<"\n";
}
int main ()
{
    f>>mask;
    descompune(mask); g<<"\n";
    for(mask1=mask; mask1; mask1=(mask1-1)&(mask))
        descompune(mask1);


    return 0;
}
