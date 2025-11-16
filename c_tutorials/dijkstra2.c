/**
 * A simple, menu-driven calculator program in C.
 * This program demonstrates the use of functions, switch statements,
 * loops, and basic error handling.
 *
 * To compile (on Linux/macOS): gcc calculator.c -o calculator -lm
 * (The "-lm" is required to link the math library for the pow() function)
 */

#include <stdio.h>
#include <math.h> // For pow() function

// --- Function Prototypes ---
// These tell the compiler what functions to expect later in the file.

/**
 * @brief Displays the calculator's main menu.
 */
void displayMenu(void);

/**
 * @brief Adds two double-precision numbers.
 * @param a The first number.
 * @param b The second number.
 * @return The sum (a + b).
 */
double add(double a, double b);

/**
 * @brief Subtracts the second number from the first.
 * @param a The first number (minuend).
 * @param b The second number (subtrahend).
 * @return The difference (a - b).
 */
double subtract(double a, double b);

/**
 * @brief Multiplies two double-precision numbers.
 * @param a The first number.
 * @param b The second number.
 * @return The product (a * b).
 */
double multiply(double a, double b);

/**
 * @brief Divides the first number by the second.
 * Note: Division-by-zero check is handled in main().
 * @param a The numerator.
 * @param b The denominator.
 * @return The quotient (a / b).
 */
double divide(double a, double b);

/**
 * @brief Calculates the modulus (remainder) of two integers.
 * Note: Modulus-by-zero check is handled in main().
 * @param a The dividend.
 * @param b The divisor.
 * @return The remainder (a % b).
 */
int myModulus(int a, int b);

/**
 * @brief Raises a base number to the power of an exponent.
 * @param base The base number.
 * @param exp The exponent.
 * @return The result (base ^ exp).
 */
double exponentiation(double base, double exp);

// --- Main Function ---
// The program's execution begins here.
int main() {
    int choice;
    double num1, num2, result;
    int intNum1, intNum2, intResult; // Specific variables for integer-only modulus

    // The main program loop. Repeats until the user chooses to exit.
    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");

        // Check if the input is a valid integer
        if (scanf("%d", &choice) != 1) {
            // If input is not an integer (e.g., 'a', 'hello')
            printf("Invalid input. Please enter a number (1-7).\n\n");
            
            // Clear the input buffer to prevent an infinite loop
            // This reads and discards all characters up to the next newline
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            
            continue; // Skip the rest of the loop and show the menu again
        }

        // Handle cases 1-6 where we need numbers
        if (choice >= 1 && choice <= 6) {
            if (choice == 5) {
                // --- Special Case: Modulus (Integers) ---
                printf("Enter the first integer (dividend): ");
                scanf("%d", &intNum1);
                printf("Enter the second integer (divisor): ");
                scanf("%d", &intNum2);
            } else if (choice == 6) {
                // --- Special Case: Exponentiation (Base & Exp) ---
                printf("Enter the base number: ");
                scanf("%lf", &num1);
                printf("Enter the exponent: ");
                scanf("%lf", &num2);
            } else {
                // --- Standard Cases: Add, Sub, Mul, Div ---
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
            }
        }

        // Use a switch statement to select the correct operation
        switch (choice) {
            case 1: // Addition
                result = add(num1, num2);
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2: // Subtraction
                result = subtract(num1, num2);
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3: // Multiplication
                result = multiply(num1, num2);
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4: // Division
                // Error handling: Check for division by zero
                if (num2 == 0) {
                    printf("Error: Cannot divide by zero.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 5: // Modulus
                // Error handling: Check for modulus by zero
                if (intNum2 == 0) {
                    printf("Error: Cannot perform modulus by zero.\n");
                } else {
                    intResult = myModulus(intNum1, intNum2);
                    printf("Result: %d %% %d = %d\n", intNum1, intNum2, intResult);
                }
                break;

            case 6: // Exponentiation
                result = exponentiation(num1, num2);
                printf("Result: %.2f ^ %.2f = %.2f\n", num1, num2, result);
                break;

            case 7: // Exit
                printf("Exiting calculator. Goodbye!\n");
                return 0; // Exits the main function, ending the program

            default:
                printf("Invalid choice. Please select an option from 1 to 7.\n");
                break;
        }
        printf("\n"); // Add a newline for better readability before the loop repeats
    }

    return 0; // Technically unreachable due to the while(1) loop and case 7
}

// --- Function Definitions (Implementations) ---

void displayMenu(void) {
    printf("--- Simple Calculator Menu ---\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%) (Integers Only)\n");
    printf("6. Exponentiation (^)\n");
    printf("7. Exit\n");
    printf("------------------------------\n");
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    // The check for b==0 is done in main() for a better user experience
    return a / b;
}

int myModulus(int a, int b) {
    // The check for b==0 is done in main()
    return a % b;
}

double exponentiation(double base, double exp) {
    // pow() is from the math.h library
    return pow(base, exp);
}