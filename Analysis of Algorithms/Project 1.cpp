#include <iostream>         //Import required libraries
#include <cstdlib>
#include <ctime>

using namespace std;

int bruteForce(int array[], const int& arraySize);      //Declaration of functions

int maxSubArray (int array[], const int& arraySize);

int kadane_Algorithm(int array[], const int& arraySize);

int main()
{
    int maxBF, maxDC, maxKD;            //Initialisation of variables
    clock_t t1, t2, t3;                 //Variables to be used in clock() functions
    int arraySize1 = 1;
    double t1InMSEC, t2InMSEC, t3InMSEC;

    cout << "Input Size" << '\t' << "Brute Force" << '\t' << "Divide and Conquer" << '\t' << "Kadane's Algorithm" << '\t' << endl;  //Output column formatting

    while (arraySize1 <= 30000)     //Ensures that array is within testing bounds
    {
        int* array = new int [arraySize1];      //Allocate array to dynamic memory for better performance

        for (int i = 0; i < arraySize1; i++)    //Loop to fill array with random values within specified range
        {
            array[i] = rand()% 100 + (-50);
        }

        t1 = clock();                                           //Call each sorting function, and measure the tame it takes to return the max sub-array
        maxBF = bruteForce(array, arraySize1);
        t1 = clock() - t1;
        t1InMSEC = (t1)/(double) CLOCKS_PER_SEC * 1000.00;      //Time taken is converted to miliseconds

        t2 = clock();
        maxDC = maxSubArray(array, arraySize1);
        t2 = clock() - t2;
        t2InMSEC = (t2)/(double) CLOCKS_PER_SEC * 1000.00;

        t3 = clock();
        maxKD = kadane_Algorithm(array, arraySize1);
        t3 = clock() - t3;
        t3InMSEC = (t3)/(double) CLOCKS_PER_SEC * 1000.00;


        cout << arraySize1 << '\t' << '\t' << t1InMSEC << '\t' << '\t' << t2InMSEC << '\t' << '\t' << '\t' << t3InMSEC << endl; //Output algorithm times in formatted columns
        arraySize1 = arraySize1 + 100;
        delete [] array;            //Delete dynamic memory where array was allocated
    }
    return 0;
}

int bruteForce(int array[], const int& arraySize)       //Brute Force algorithm definition
{
		int MaxSum = array[0];

		for (int i = 1; i < arraySize; i++)         //Loop to compare against every other element
		{
			int tempSum = 0;
			int j = i;
			while (j>=0)
			{
				tempSum += array[j];
				if (tempSum > MaxSum)
				{
					MaxSum = tempSum;
				}
				j--;
			}
		}
	return MaxSum;
}

int maxSubArray (int array[], const int& arraySize)         //Divide and conquer algorithm definition
{                                                           //Breaks up array into many smaller arrays and compares their max sums
  int leftSubArray = 0;
  int rightSubArray = 0;
  int leftSubArraySum = -50;
  int rightSubArraySum = -50;
  int sum = 0;
  if (arraySize == 1)
    return array[0];

  else
  {

    int midPosition = arraySize/2;
    leftSubArray = maxSubArray(array, midPosition);
    rightSubArray = maxSubArray(array, (arraySize - midPosition));


    for (int j = midPosition; j < arraySize; j++)
    {
      sum = sum + array[j];
      if (sum > rightSubArraySum)
        rightSubArraySum = sum;
    }
    sum = 0;

    for (int k = (midPosition - 1); k >= 0; k--)
    {
      sum = sum + array[k];
      if (sum > leftSubArraySum)
        leftSubArraySum = sum;
    }

  }
  int maxSubArraySum = 0;

  if (leftSubArraySum > rightSubArraySum)
  {
    maxSubArraySum = leftSubArraySum;
  }

  else
    maxSubArraySum = rightSubArraySum;

  return max(maxSubArraySum, (leftSubArraySum + rightSubArraySum));     //Return bigger value
}

int kadane_Algorithm(int array[], const int& arraySize)          //Kadane's algorithm definition
{
    int maxsofar=0, maxending=0, i;

    for (i=0; i < arraySize; i++)
    {
        maxending += array[i];

        if (maxending < 0)          //Resets max sum if it's negative
        {
            maxending = 0 ;
        }

        if (maxsofar < maxending)
        {
            maxsofar = maxending;
        }
    }
return maxending;
}

