// ------------- CODE -------------
#include <iostream>
#include <limits>

using namespace std;

const string PROMPT = "Enter an integer: ";
const string ERROR_MESSAGE = "Invalid input. Please enter an integer.\n";
const string REVERSED_INT_LABEL = " reversed is: ";

// Function prototypes (if any)

// If the input is 12345, the function should return 54321
int reverseDigit(int num1);

// The value of reverseDigit(5600, 7008) is 65, 8007
void reverseDigit(int &num2, int &num3);

int getInt(string prompt = "", string error_message = "");
void printReversedInt(int n1, int reversedInt);
void printReversedValues(int num2, int num3, int reversedNum2, int reversedNum3);

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char* argv[]) {
    int n1 = 0;
    int n1Reversed = 0;
    int n2 = 0;
    int n2Reversed = 0;
    int n3 = 0;
    int n3Reversed = 0;

    n1 = getInt(PROMPT, ERROR_MESSAGE);
    n1Reversed = reverseDigit(n1);
    cout << endl;
    printReversedInt(n1, n1Reversed);

    n2 = getInt(PROMPT, ERROR_MESSAGE);
    n3 = getInt(PROMPT, ERROR_MESSAGE);
    n2Reversed = n2;
    n3Reversed = n3;
    reverseDigit(n2Reversed, n3Reversed);
    cout << endl;
    printReversedValues(n2, n3, n2Reversed, n3Reversed);
  
    return 0;
}

// If the input is 12345, the function should return 54321
int reverseDigit(int num1) {
    // Credit to github copilot for the implementation of this function
    int reversedNum = 0;
    while (num1 > 0) {
        int digit = num1 % 10; // Get the last digit
        reversedNum = reversedNum * 10 + digit; // Append the digit to the reversed number
        num1 /= 10; // Remove the last digit
    }
    return reversedNum;

    // Alternative implementation using string manipulation
    // string numStr = to_string(num1);
    // reverse(numStr.begin(), numStr.end());
    // return stoi(numStr);

    // Another way using stringstream
    // stringstream ss;
    // ss << num1;
    // string numStr = ss.str();
    // ss.str("");
    // for(char c : numStr) {
    //     ss << c;
    // }
    // int reversedNum = 0;
    // ss >> reversedNum;
    // return reversedNum;
}

// The value of reverseDigit(5600, 7008) is 65, 8007
void reverseDigit(int &num2, int &num3) {
    num2 = reverseDigit(num2);
    num3 = reverseDigit(num3);
}

// Function implementations (if any)
void printReversedInt(int n1, int reversedInt) {
    cout << n1 << REVERSED_INT_LABEL << reversedInt << endl;
}

void printReversedValues(int num2, int num3, int reversedNum2, int reversedNum3) {
    cout << "The value of reverseDigit(" 
         << num2 << ", " << num3 << ") is "
         << reversedNum2 << ", " << reversedNum3 << endl;
}


int getInt(string prompt, string error_message) {
    int n = 0;
    bool valid = false;
    while(!valid) {
        if(prompt.size() > 0) {
            cout << prompt;
        }
        cin >> n;
        if(cin){
            valid = true;
        } else {
            cin.clear();
            // https://en.cppreference.com/w/cpp/header/limits.html
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // https://en.cppreference.com/w/cpp/types/numeric_limits.html
            // https://en.cppreference.com/w/cpp/io/streamsize.html
            // https://en.cppreference.com/w/cpp/types/numeric_limits/max.html
            if(error_message.size() > 0) {
                cout << error_message;
            }
        }
    }
    return n;
}
