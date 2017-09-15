//****************************************************************************
//  Donjanell Ross
//  MATH 1165
//  9/15/2017
//
//  This program uses the Euclidean Algorithm to get gcd of two
//  numbers
//****************************************************************************
#include<iostream>
using namespace std;

// Function prototypes 
long int EuclideanAlgorithm(long int, long int);
void checkForNegativeValues(long int &, long int &);
void makeTheLargestNumFirst(long int &, long int &);
bool doesNumBDivivideNumA(long int, long int);

int main()
{
    char ans; // holds the users answer
    long int numA, numB; // first and second number in E.A 
    bool isQuiting = false; // handles 
    
    do
    {  // Get The two numbers
       cout << "Enter two values to find their GCD (use a space to seperate the two values)\n";
       cin >> numA >> numB; // takes the two numbers the user inputs
      
       if ((numA != 0 && numB != 0) && !doesNumBDivivideNumA(numA, numB)) // check to make sure the number are not 0
       {                                                                  // also check is b does not divived a
           cout << "The GCD(" << numA << "," << numB << ")" << " = "
               << EuclideanAlgorithm(numA, numB) << endl;
       }
       else
           cout << "number(s) can not be zero and/or b cannot divide a.\n";

       cout << "To continue press any key. to quit press q\n";
       cin >> ans;

       if (ans == 'q' || ans == 'Q') // Allows the user to quit
           isQuiting = true;
      
    } while (!isQuiting);
   
    return 0;
}

//****************************************************************************
// EuclideanAlgorithm calculates the gcd using the
// Euclidean Algorithm
//****************************************************************************
long int EuclideanAlgorithm(long int numA, long int numB)
{
    long int q, r, previousRemainder;

    checkForNegativeValues(numA, numB);

    makeTheLargestNumFirst(numA, numB);

    do // Euclidean Algorithm calculation 
    {
        q = numA / numB; 
        r = numA % numB;

        if (r != 0)
            previousRemainder = r;

        numA = numB;
        numB = r;
       
    } while (r != 0);
    
    return  previousRemainder;
}

//****************************************************************************
// checkForNegativeValues
// This function makes the values postive if they are negative
//****************************************************************************
void checkForNegativeValues(long int &numA, long int &numB) 
{
    numA = numA > 0 ? numA : -numA;
    numB = numB > 0 ? numB : -numB;
}

//****************************************************************************
// makeTheLargestNumFirst
// This function make the largest value numA and the value numB
//****************************************************************************
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

//****************************************************************************
// doesNumBDivideNumA
// This function check to see if b divides a
//****************************************************************************
bool doesNumBDivivideNumA(long int numA, long int numB)
{
    checkForNegativeValues(numA, numB);
    makeTheLargestNumFirst(numA, numB);

    if (numA % numB == 0)
        return true;
    else
        return false;
}