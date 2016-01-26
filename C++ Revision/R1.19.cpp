#include <iostream>
#include <cstdlib>

using namespace std;

int IsPower2 (long long int x)
{
    return ((x != 0) && !(x & (x - 1)));
}

int main()
{
    long long int i;
    int j;

    cin >> i;

    j = IsPower2(i);

    if (j == 1)
    {
        cout << "true";
    }

    else
    {
        cout << "false";
    }

    return 0;
}
