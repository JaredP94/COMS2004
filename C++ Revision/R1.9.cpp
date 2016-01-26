#include <iostream>
using namespace std;

void printArray(int** A, int m, int n)
{
	for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
			cout << A[i][j] << ' ';
        }
		cout << endl;
	}
}

int main(void){

    int x,y,z;

    cin >> x;
    cin >> y;

	int** matrix = new int*[x];

	for(int i = 0; i < x; i++)
    {
	    matrix[i] = new int[y];
	}

    for (int m=0; m < x; m++)
    {
        for (int n=0; n < y; n++)
        {
            cin >> z;
            matrix[m][n] = z;
        }
    }

	printArray(matrix, x, y);

	for(int i = 0; i < x; i ++)
    {
		delete [] matrix[i];
	}

	delete [] matrix;

	return 0;
}

