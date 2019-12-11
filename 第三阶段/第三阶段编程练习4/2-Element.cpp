#include <iostream>
using namespace std;

bool judge(int k, int x)
{
      if (x == k)
            return true;
      if (x < k)
            return false;
      if ((x - 1) % 2 == 0 && judge(k, (x - 1) / 2))
            return true;
      if ((x - 1) % 3 == 0 && judge(k, (x - 1) / 3))
            return true;
      return false;
}

int main()
{
      int k, x;
      char c;
      cin >> k >> c >> x;
      cout << (judge(k, x) ? "YES" : "NO") << endl;
      return 0;
}