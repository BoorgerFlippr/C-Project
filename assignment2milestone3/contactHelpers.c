//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
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

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1)
    {
        phoneNum = getInt();
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{

}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contacts contacts[], int size)
{

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{

}


// addContact:
// Put empty function definition below:
void addContacts(struct Contact contacts[], int size)
{

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contacts contacts[], int size)
{

}