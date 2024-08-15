//==============================================
// Name:           Glenn Parreno
// Student Number: 115 814 196
// Email:          geparreno@myseneca.ca
// Section:        IPC 144 NDD
// Date:           July 26
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#include "contactHelpers.h"
#include "contacts.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXCONTACTS 5

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

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

    struct Contact contacts[MAXCONTACTS] =
    {
        {
         {"Rick", {'\0'}, "Grimes"},
         {11, "Trailer Park", 0, "A7A 2J2", "King City" },
         {"4161112222", "4162223333", "4163334444"}
        },

        {
         {"Maggie", "R.", "Greene"},
         {55, "Hightop House", 0, "A9A 3K3", "Bolton" },
         {"9051112222", "9052223333", "9053334444"}
        },

        {
         {"Morgan", "A.", "Jones"},
         {77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
         {"7051112222", "7052223333", "7053334444"}
        },

        {
         {"Sasha", {'\0'}, "Williams"},
         {55, "Hightop House", 0, "A9A 3K3", "Bolton" },
         {"9052223333", "9052223333", "9054445555"}
        },
    };

    do
    {
        menuSelect = menu();
        switch (menuSelect)
        {
        case 1:
            printf("\n");
            //printf("\n<<< Feature 1 is unavailable >>>\n\n");
            displayContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 2:
            printf("\n");
            //printf("\n<<< Feature 2 is unavailable >>>\n\n");
            addContacts(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 3:
            printf("\n");
            //printf("\n<<< Feature 3 is unavailable >>>\n\n");
            updateContact(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 4:
            printf("\n");
            //printf("\n<<< Feature 4 is unavailable >>>\n\n");
            deleteContact(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 5:
            printf("\n");
            //printf("\n<<< Feature 5 is unavailable >>>\n\n");
            searchContacts(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 6:
            printf("\n");
            printf("<<< Feature sort is unavailable >>>\n\n");
            //sortContacts(contacts, MAXCONTACTS);
            printf("\n");
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
    int getInput = 1, i;

    do
    {
        scanf("%s", phoneNum);
        while (getInput != 0)
        {
            for (i = 0; i < strlen(phoneNum); i++)
            {
                if (isdigit(phoneNum[i]) == 0)
                {
                    printf("Enter a 10-digit phone number: ");
                    scanf("%s", phoneNum);
                    break;
                }
                else
                {
                    getInput = 0;
                }
            }
        }

        if (strlen(phoneNum) != 10)
            printf("Enter a 10-digit phone number: ");
        clearKeyboard();

    } while (strlen(phoneNum) != 10);
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i, compare, found = -1;
    for (i = 0; i < size; i++)
    {
        compare = strcmp(contacts[i].numbers.cell, cellNum);
        if (compare == 0)
        {
            found = i;
            break;
        }
    }
    return found;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
    printf(" %s ", contact->name.firstName);
    if (strlen(contact->name.middleInitial) != 0)
    {
        printf("%s ", contact->name.middleInitial);
    }
    printf("%s\n", contact->name.lastName);
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0)
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    int i, valid = 0;
    displayContactHeader();
    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) != 0)
        {
            displayContact(&contacts[i]);
            valid++;
        }
    }
    displayContactFooter(valid);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    char search[11];
    int found;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(search);
    found = findContactIndex(contacts, size, search);
    if (found == -1)
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    else
    {
        displayContact(&contacts[found]);
        printf("\n");
    }

}


// addContact:
// Put empty function definition below:
void addContacts(struct Contact contacts[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) == 0)
            break;
    }
    if (i == size)
    {
        printf("*** ERROR: The contact list is full! ***\n");
    }
    else
    {
        getContact(&contacts[i]);
        printf("--- New contact added! ---\n");
    }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
    char phoneNum[11];
    int found, prompt;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    found = findContactIndex(contacts, size, phoneNum);
    if (found == -1)
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    else
    {
        printf("Contact found:\n");
        displayContact(&contacts[found]);
        printf("\n");

        printf("Do you want to update the name? (y or n): ");
        prompt = yes();
        if (prompt == 1)
            getName(&contacts[found].name);

        printf("Do you want to update the address? (y or n): ");
        prompt = yes();
        if (prompt == 1)
            getAddress(&contacts[found].address);

        printf("Do you want to update the numbers? (y or n): ");
        prompt = yes();
        if (prompt == 1)
            getNumbers(&contacts[found].numbers);

        printf("--- Contact Updated ---\n");
    }
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
    char phoneNum[11];
    int found, prompt;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    found = findContactIndex(contacts, size, phoneNum);
    if (found == -1)
    {
        printf("*** Contact NOT FOUND *** \n");
    }
    else
    {
        printf("Contact found:\n");
        displayContact(&contacts[found]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        prompt = yes();
        if (prompt == 1)
        {
            contacts[found].numbers.cell[0] = '\0';
            contacts[found].numbers.business[0] = '\0';
            contacts[found].numbers.home[0] = '\0';
            printf("--- Contact deleted! ---\n");
        }

    }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{

}