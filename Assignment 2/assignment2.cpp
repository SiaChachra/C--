#include <iostream>
using namespace std;

// Function to check if a number is even or odd and then convert it
void evenOddConverter()
{
    int userInput;

    // Taking input from the user
    cout << "Enter a number: ";
    cin >> userInput;

    // Checking if the input number is even or odd using modulo
    if (userInput % 2 == 0)
    {
        cout << "The input is even" << endl;
        // Convert the even number to an odd number using a formula (e.g., add 5)
        int oddOutput = userInput + 5;
        cout << "The odd output is: " << oddOutput << endl;
    }
    else
    {
        cout << "The input is odd" << endl;
        // Convert the odd number to an even number using a formula (e.g., add 3)
        int evenOutput = userInput + 3;
        cout << "The even output is: " << evenOutput << endl;
    }
}

int main()
{
    // Call the function to execute
    evenOddConverter();
    return 0;
}
