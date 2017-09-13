#include<iostream>
using namespace std;

long int EuclideanAlgorithm(long int, long int);
void checkForNegativeValues(long int &, long int &);
void makeTheLargestNumFirst(long int &, long int &);

int main()
{
    cout << "GCD: "<< EuclideanAlgorithm(36,90) << endl;
    
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
        q = numA / numB; 
        r = numA % numB;

        if (r != 0)
            previousRemainder = r;

        numA = numB;
        numB = r;

    } while (r != 0);
    
    return previousRemainder;

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
