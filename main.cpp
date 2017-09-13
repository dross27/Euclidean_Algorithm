#include<iostream>
using namespace std;

long int EuclideanAlgorithm(long int, long int);
void checkForNegativeValues(long int &, long int &);
void makeTheLargestNumFirst(long int &, long int &);

int main()
{
    char ans;
    long int numA, numB;
    
    do
    {  
       cout << "Enter two values to find their GCD (use a space to seperate the two values)\n";
       cin >> numA >> numB;
      
       if (numA != 0 && numB != 0)
           cout << "The GCD(" << numA  << "," << numB << ")" << " = " 
          << EuclideanAlgorithm(60, 900) << endl;
       else
           cout << "number(s) can not be zero\n";

       cout << "to continue press any key. to quit press q\n";
       cin >> ans;
      
    } while (ans != 'q' || ans != 'Q');
   
    system("pause");

    return 0;
}
long int EuclideanAlgorithm(long int numA, long int numB)
{
    long int q, r, previousRemainder;

    checkForNegativeValues(numA, numB);

    makeTheLargestNumFirst(numA, numB);

    do
    {
        q = numA / numB; // have an issue here, need to figure out a way to avoid divide by zero
        r = numA % numB;

        if (r != 0)
            previousRemainder = r;

        numA = numB;
        numB = r;

    } while (r != 0);
    
    return  previousRemainder;
}

void checkForNegativeValues(long int &numA, long int &numB) 
{
    numA = numA > 0 ? numA : -numA;
    numB = numB > 0 ? numB : -numB;
}

void makeTheLargestNumFirst(long int &numA, long int &numB)
{
    if (numB > numA)
    {
        long int temp;
        temp = numA;
        numA = numB;
        numB = temp;
    }
}
