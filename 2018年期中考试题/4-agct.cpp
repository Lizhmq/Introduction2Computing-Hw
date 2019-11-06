#include <cstring>
#include <iostream>
using namespace std;

char s1[256], s2[256];

int main()
{
    int n;
    cin >> n;
    while (n--) {
        cin >> s1;
        int l = strlen(s1);
        for (int i = 0; i < l; ++i) {
            if (s1[i] == 'A')
                s2[i] = 'T';
            else if (s1[i] == 'T')
                s2[i] = 'A';
            else if (s1[i] == 'C')
                s2[i] = 'G';
            else
                s2[i] = 'C';
        }
        s2[l] = '\0';
        cout << s2 << endl;
    }
    return 0;
}