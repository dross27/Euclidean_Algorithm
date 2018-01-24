
//  This program uses the Euclidean Algorithm to get the gcd of two
//  integers of any size (within long int restrictions -4.2 billion to
// + 4.2 billion.
//****************************************************************************

#include<iostream>
#include<gtest/gtest.h>

using namespace std;

// Function prototypes 
long int EuclideanAlgorithm(long int, long int);
void     checkForNegativeValues(long int &, long int &);
void     makeTheLargestNumFirst(long int &, long int &);

//*****************************************************************************
//
//Main function
//*****************************************************************************
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    long int numA, numB; // first and second number in E.A 
    long int originalA, originalB; // Keeps the original values
    
    // Get The two numbers from the user to compute GCD 
    cout << "Enter two values to find their GCD (use a space between numbers)\n";

    cin >> numA >> numB; // takes the two numbers the user inputs

    // Keeps the original values of the two numbers
    originalA = numA;
    originalB = numB;

    // if values are negative, convert to positive 
    checkForNegativeValues(numA, numB);

    // Makes the first number the largest   
    makeTheLargestNumFirst(numA, numB);

    // Handles if either number is zero. 
    if (numA == 0 || numB == 0)
    {
        if (numA != numB) // if only one number is 0, returns abs of other num
        {
            cout << "The GCD(" << originalA << "," << originalB << ")" << " = "
                << numA << endl;
        }

        else // both numbers are zero, thus DNE
        {
            cout << "The GCD(" << originalA << "," << originalB << ")" << " = "
                << "DNE\n";
        }
    }

    // handles if the numbers are multiples 
    else if (numA % numB == 0)
    {
         
        cout << "The GCD(" << originalA << "," << originalB << ")" << " = " 
            << numB << endl; // when multiples, gcd is the smallest of the two
    }
    // All other numbers use the Euclidean Algorithm to compute GCD
    else 
    {                                                              
        cout << "The GCD(" << originalA << "," << originalB << ")" << " = "
             << EuclideanAlgorithm(numA,numB) << endl;
    }
     
    return RUN_ALL_TESTS();
}

//****************************************************************************
// EuclideanAlgorithm calculates the gcd using the
// Euclidean Algorithm
//****************************************************************************
long int EuclideanAlgorithm(long int numA, long int numB)
{
    long int q, r, previousRemainder;

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

