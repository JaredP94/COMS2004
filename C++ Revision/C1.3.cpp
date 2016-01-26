#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
      int x, y;
      vector<int> myVec;
      string status = "true";

      cin >> x;

      for (int i = 0; i < x; i++)
      {
          cin >> y;
          myVec.push_back(y);
      }

      for (int m = 0; m < myVec.size(); m++)
      {
          for (int n = 0; n < myVec.size(); n++)
          {
              if (m != n && myVec[m] == myVec[n])
              {
                  status = "false";
              }
          }
      }

      cout << status;

      return 0;
}

