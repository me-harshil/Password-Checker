/*****************************************************************************
                Program to check the validity of a Password
******************************************************************************/

// Header Files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

// Global Function Declaration
void isValid();
void reason(int[10]);
void again();

// Main Function
int main()
{

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tWelcome to Password Checker\n\n\n\n\n\n\n\n\n\n\t\t\tPress any key to continue...");
    getch();
    isValid(); // Function call
    return 0;
}

void isValid()
{
    system("cls"); // Clear the output screen
    // Variable Declaration
    char password[20];
    int r[10] = {0}, length_of_password, i;
    /* Array r is initialize to 0

       r[0] = 0. If index 0 has value 0 than password length is between 8 to 15 otherwise not.
       r[1] = 0. If index 1 has value 0 than password does not have any space otherwise password contain space.
       r[2] = 0. If index 2 has value 0 than password contain at least one uppercase letter(A-Z) otherwise not.
       r[3] = 0. If index 3 has value 0 than password contain at least one lowercase letter(a-z) otherwise not.
       r[4] = 0. If index 4 has value 0 than password contain at least one digit(0-9) otherwise not.
       r[5] = 0. If index 5 has value 0 than password contain at least one special characters from !,@,#,$,& and *.
       */
    // Print Instruction
    printf("\n\n\n\t\t Password checker basically checks if the password is valid or not\n\t\t based on password policies mention below:\n\n");
    printf("\t\t 1) Password length should be between 8 to 15 characters\n");
    printf("\t\t 2) Password should not contain any space\n");
    printf("\t\t 3) Password should contain at least one digit(0-9)\n");
    printf("\t\t 4) Password should contain at least one lowercase letter(a-z)\n");
    printf("\t\t 5) Password should contain at least one uppercase letter(A-Z)\n");
    printf("\t\t 6) Password should contain at least one special character\n\t\t    ( ~ ` ! @ # $ % ^ & * ( ) _ - + = { [ } ] | : ; < , > / )\n");

    printf("\n\n\n\n\t\t Enter a password: ");
    fflush(stdin);
    gets(password);                        // Take input
    length_of_password = strlen(password); // Find length of entered password

    // Contidion to check if password length is 8 to 15 or not
    if (!(length_of_password >= 8 && length_of_password <= 15))
        r[0] = 1; // If password length are not 8 to 15 than index 0 is any non zero number

    // Loop to check password contain space or not
    for (i = 0; i < length_of_password; i++)
    {
        if (password[i] == ' ')
        {
            r[1] = 1; // If password contain space than index 1 is any non zero number
            break;    // Break the loop because password contain at space
        }
    }

    // Loop to check password has Uppercase letter or not
    for (i = 0; i < length_of_password; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            r[2] = 0; // If password has Uppercase letter than index 2 is zero
            break;    // Break the loop because password contain at least one uppercase letter
        }
        else
            r[2] = 1; // If password don't have any uppercase letter than index 2 is any non zero number
    }

    // Loop to check password has Lowercase letter or not
    for (i = 0; i < length_of_password; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            r[3] = 0; // If password has Lowercase letter than index 3 is zero
            break;    // Break the loop because password contain at least one lowercase letter
        }
        else
            r[3] = 1; // If password don't have any lowercase letter than index 3 is any non zero number
    }

    // Loop to check password contain digit or not
    for (i = 0; i < length_of_password; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            r[4] = 0; // If password has any digit (0-9) than index 4 is zero
            break;    // Break the loop because password contain at least one digit
        }
        else
            r[4] = 1; // If password don't have any digit than index 4 is any non zero number
    }

    // Loop to check password contain special character or not
    for (i = 0; i < length_of_password; i++)
    {
        // Special Characters: ~`!@#$%^&*()_-+={[}]|\:;"'<,>.?/
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '+' || password[i] == '-' || password[i] == '/' || password[i] == '~' || password[i] == '`' || password[i] == '^' || password[i] == '(' || password[i] == ')' || password[i] == '_' || password[i] == '=' || password[i] == '{' || password[i] == '[' || password[i] == ']' || password[i] == '}' || password[i] == '|' || password[i] == '<' || password[i] == '>')
        {
            r[5] = 0; // If password contain special character than index 5 is zero
            break;    // Break the loop because password contain at least one special character
        }
        else
            r[5] = 1; // If password don't have any special character than index 5 is any non zero number
    }

    reason(r); // Call a funtion and pass an array
}

void reason(int a[10])
{
    // Declare Variable
    int i, flag = 0; // flag variable for check password is valid or not

    // Loop for check password is valid or not
    for (i = 0; i < 10; i++)
    {
        if (a[i] != 0)
        {
            flag = 1; // If any element of an array is non zero than flag is any non zero number and password is invalid
            break;    // Break the loop because password is invalid
        }
    }

    if (flag == 0) // If flag = 0 than password is valid
        printf("\n\n\t\t Your Password is Valid.\n");
    else // If flag is any non zero number than password is invalid
    {
        i = 0;
        printf("\n\n\t\t Your Password is invalid.");
        // Print reasons why password is invalid
        printf("\n\t\t And here's why password is invalid:\n\n");
        if (a[0] != 0)
            printf("\t\t %d) Password length is not between 8 to 15.\n", ++i);
        if (a[1] != 0)
            printf("\t\t %d) Password contain space.\n", ++i);
        if (a[2] != 0)
            printf("\t\t %d) Password does not contain any uppercase letter(A-Z).\n", ++i);
        if (a[3] != 0)
            printf("\t\t %d) Password does not contain any lowercase letter(a-z).\n", ++i);
        if (a[4] != 0)
            printf("\t\t %d) Password does not contain any digit(0-9).\n", ++i);
        if (a[5] != 0)
            printf("\t\t %d) Password does not contain any special characters from\n\t\t  ~ ` ! @ # $ % ^ & * ( ) _ - + = { [ } ] | : ; < , > / .\n", ++i);
    }
    again(); // Call a function
}

void again()
{
    char c;
    printf("\n\n\t\t Enter 1 for check your password and enter any key for exit...");
    c = getch();
    if (c == '1')
        isValid(); // Call a fucntion
    else
    {
        system("cls"); // Clear the output screen
        printf("\n\n\n\n\n\n\n\n\n\n\t\t Thank you for using password checker...");
        getch();
        exit(0); // Exit the program with return value 0
    }
}
