#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double x;
    int sum=0;

    cin >> x;

    do
    {
        x=x/2;
        sum+=1;
    }

    while (x >= 2);

    cout << sum;
}
