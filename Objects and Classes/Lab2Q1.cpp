#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int i;
    string x;
    vector<string> MyVec(100);

    for (i=0; i<=10; i++){
        getline(cin,x);
        if (x == "EXIT") break;
        MyVec[i]=x;
    }

    for (int j=i; j>=0; j--){
        cout << MyVec[j] << endl;
    }

return 0;
}
