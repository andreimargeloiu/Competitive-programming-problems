//# include <fstream>
# include <algorithm>
# include <cstring>
# include <iostream>
using namespace std;
//ifstream cin("test.in");
//ofstream cout("test.out");
int i,j,n,nr,x,l;
char mici[100][20], ch, s[105];
int main ()
{
    cin.getline(s+1, 100); l=strlen(s+1);
    x=s[1]-'0';
    if (l>1) x=x*10+s[2]-'0';

    strcpy(mici[0], "zero");
    strcpy(mici[1], "one");
    strcpy(mici[2], "two");
    strcpy(mici[3], "three");
    strcpy(mici[4], "four");
    strcpy(mici[5], "five");
    strcpy(mici[6], "six");
    strcpy(mici[7], "seven");
    strcpy(mici[8], "eight");
    strcpy(mici[9], "nine");
    strcpy(mici[10], "ten");
    strcpy(mici[11], "eleven");
    strcpy(mici[12], "twelve");
    strcpy(mici[13], "thirteen");
    strcpy(mici[14], "fourteen");
    strcpy(mici[15], "fifteen");
    strcpy(mici[16], "sixteen");
    strcpy(mici[17], "seventeen");
    strcpy(mici[18], "eighteen");
    strcpy(mici[19], "nineteen");
    strcpy(mici[20], "twenty");
    strcpy(mici[30], "thirty");
    strcpy(mici[40], "forty");
    strcpy(mici[50], "fifty");
    strcpy(mici[60], "sixty");
    strcpy(mici[70], "seventy");
    strcpy(mici[80], "eighty");
    strcpy(mici[90], "ninety");

    if (x<=20) cout<<mici[x]<<"\n";
    else {
            if (x%10==0) cout<<mici[x]<<"\n";
            else {
                     cout<<mici[x-x%10]<<"-"<<mici[x%10]<<"\n";
                 }
         }

    return 0;
}
