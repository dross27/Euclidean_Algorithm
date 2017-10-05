//****************************************************************************
//  Donjanell Ross
//  MATH 1165
//  9/15/2017
//
//  This program uses the Euclidean Algorithm to get the gcd of two
//  integers of any size (within long int restrictions -4.2 billion to
// + 4.2 billion. 
//****************************************************************************
#include<iostream>
#include<math.h>
using namespace std;

// Function prototypes 
long int EuclideanAlgorithm(long int, long int);
void checkForNegativeValues(long int &, long int &);
void makeTheLargestNumFirst(long int &, long int &);
bool doesNumBDivivideNumA(long int, long int);
void printGDC(long int, long int);

//Main function
int main()
{
    char ans; // holds the users answer
    long int numA, numB; // first and second number in E.A 
    bool isQuitting = false; // handles user quit
    
    
      // Get The two numbers
       cout << "Enter two values to find their GCD (use a space to seperate the two values)\n";
       cin >> numA >> numB; // takes the two numbers the user inputs

       // here I should get the abs value and put the greatest number first

       // Then the first if statement will check if they are multiples or a zero is passed
       // Then use an algo to calculate the gcd of a multiple or a if one arg is zero
            // i.e if they are multiples return the smallest number
       
       // This is to handle if one of values past is 1 and both number are non-zero or -1
       if ((numA != 0 && numB != 0) && (numA == 1 && abs(numB) != 1 || numB == 1 && abs(numA) != 1))
       {
           cout << "The GCD(" << numA << "," << numB << ")" << " = 1 \n";
       }

       else 
       {                                                                  // also check is b does not divived a
           printGDC(numA, numB);
       }
        
   
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

//****************************************************************************
// printGDC
// This function prints the GDC
//****************************************************************************

void printGDC(long int numA, long int numB)
{
    cout << "The GCD(" << numA << "," << numB << ")" << " = "
        << EuclideanAlgorithm(numA, numB) << endl;  // Prints the value of the gcd
}