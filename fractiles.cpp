# include <bits/stdc++.h>
using namespace std;
int testCASE,KK,c,s,i,number;
int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&testCASE);
    while(testCASE > 0) {
        --testCASE; ++number;
        scanf("%d%d%d", &KK, &c, &s);
        printf("Case #%d: ",number);
        for(i=1; i<=s; ++i)
            printf("%d ",i);
        printf("\n");
    }
    return 0;
}
