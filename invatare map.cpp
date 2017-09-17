
#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
  // Compare (<) function not required since it is built into string class.
  // else declaration would comparison function in multimap definition.
  // i.e. multimap<string, int, compare> m;

  multimap<string, int> m;

  m.insert(pair<string, int>("a", 1));
  m.insert(pair<string, int>("c", 2));
  m.insert(pair<string, int>("b", 3));
  m.insert(pair<string, int>("b", 4));
  m.insert(pair<string, int>("a", 5));
  m.insert(pair<string, int>("b", 6));

  cout << "Number of elements with key a: " << m.count("a") << endl;
  cout << "Number of elements with key b: " << m.count("b") << endl;
  cout << "Number of elements with key c: " << m.count("c") << endl;

  cout << "Elements in m: " << endl;
  for (multimap<string, int>::iterator it = m.begin();
       it != m.end();
       ++it)
   {
       cout << "  [" << (*it).first << ", " << (*it).second << "]" << endl;
   }

   pair<multimap<string, int>::iterator, multimap<string, int>::iterator> ppp;

   // equal_range(b) returns pair<iterator,iterator> representing the range
   // of element with key b
   ppp = m.equal_range("b");

   // Loop through range of maps of key "b"
   cout << endl << "Range of \"b\" elements:" << endl;
   for (multimap<string, int>::iterator it2 = ppp.first;
       it2 != ppp.second;
       ++it2)
       {
           cout << "  [" << (*it2).first << ", " << (*it2).second << "]" << endl;
       }

// Can't do this (??)
//   cout << ppp.first << endl;
//   cout << ppp.second << endl;

   m.clear();
}
