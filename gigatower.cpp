#include <iostream>
# include <algorithm>
using namespace std;
int ok,gapdan,n,VV;
int main()
{
    cin>>n;
    ok=1;
    gapdan=n;

    while (ok)
    {
        ++VV; ++n;
        gapdan=max(n,-n);
        while (gapdan)
        {
            if (gapdan%10==8)
            {
                cout<<VV<<"\n";
                return 0;
            }
            gapdan=gapdan/10;
        }
    }
    return 0;
}
