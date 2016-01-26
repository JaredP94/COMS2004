#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    long n;
    long m;

    cin >> m;

    cin >> n;

    if (m%n == 0)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

return 0;
}
