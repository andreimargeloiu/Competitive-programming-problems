# include <bits/stdc++.h>
using namespace std;
long long ci, cs, dif, i;
long long cmmdc (long long a, long long b) {
    long long R;
    while (b!=0) {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
int main ()
{
    cin>>ci>>cs;

    for (dif=cs-ci; dif>=1; --dif) {
        for (i=ci; i+dif<=cs; ++i) {
            if (cmmdc(i, i+dif)==1) {
                cout<<dif+1<<"\n";
                return 0;
            }
        }
    }

    return 0;
}
