#include <iostream>
using namespace std;

bool out = false;

void func(int n, int start)
{
      for (int i = start; i * i <= n; ++i) {
            if (n % i == 0) {
                  if (out)
                        cout << '*';
                  out = true;
                  cout << i;
                  func(n / i, i);
                  return;
            }
      }
      if (out)
            cout << '*';
      out = true;
      cout << n ;
      return;
}

int main()
{
      int n;
      cin >> n;
      cout << n << '=';
      func(n, 2);
      cout << endl;
      return 0;
}