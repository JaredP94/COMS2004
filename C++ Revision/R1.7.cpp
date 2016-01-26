#include <iostream>

using namespace std;

int main()
{
    int x, sum=0;

    cin >> x;

    for(int i=0; i<x; i++)
    {
        sum+=i;
    }

    cout << sum << endl;

return 0;
}
