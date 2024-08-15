//==============================================
// Name:           Glenn Parreno
// Student Number: 115 814 196
// Email:          geparreno@myseneca.ca
// Section:        IPC144 NDD
// Date:           July 15
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
    char NL = 'x';
    int value;

    while (NL != '\n')
    {
        scanf("%d%c", &value, &NL);
        if (NL != '\n')
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
    int value;
    do
    {
        value = getInt();
        if (value < min || value > max)
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);

    } while (value < min || value > max);

    return value;
}

// yes function definition goes here:
int yes(void)
{
    char NL = 'x';
    char prompt;
    int num;

    while (NL != '\n')
    {
        scanf("%c%c", &prompt, &NL);
        if (NL != '\n')
        {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
    }
    if (prompt == 'y' || prompt == 'Y')
        num = 1;
    else
        num = 0;

    return num;
}

// menu function definition goes here:
int menu(void)
{
    int menuSelect;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    menuSelect = getIntInRange(0, 6);

    return menuSelect;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
    int menuSelect, option = 0;

    do
    {
        menuSelect = menu();
        switch (menuSelect)
        {
        case 1:
            printf("\n<<< Feature 1 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 2:
            printf("\n<<< Feature 2 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 3:
            printf("\n<<< Feature 3 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 4:
            printf("\n<<< Feature 4 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 5:
            printf("\n<<< Feature 5 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 6:
            printf("\n<<< Feature 6 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            option = yes();
        }
    } while (option != 1);
    printf("\nContact Management System: terminated\n");
}