#include <fstream>

using namespace std;

int main()
{
   ifstream f("random.in");
   ofstream cout("random.out");
   int n;
   f>>n;
    if (n == 1982) cout<<"Robert Tarjan";
     if (n == 1986) cout<<"Leslie Valiant";
      if (n == 1990) cout<<"Alexander Razborov";
       if (n == 1994) cout<<"Avi Wigderson";
        if (n == 1998) cout<<"Peter Shor";
         if (n == 2002) cout<<"Madhu Sudan";
          if (n == 2006) cout<<"Jon Kleinberg";
           if (n == 2010) cout<<"Daniel Spielman";
            if (n == 2014) cout<<"Subhash Khot";
    return 0;
}
