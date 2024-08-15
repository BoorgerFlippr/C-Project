//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      1
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"


// getName:
void getName(struct Name* name)
{

    char yesNo;

    printf("Please enter the contact's first name: ");
    scanf(" %[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    //scanf("%s%*c", &yesNo); //<--- Incorrect, not a c string, must be a char
    scanf(" %c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %[^\n]%*c", name->middleInitial);
    }

    printf("Please enter the contact's last name: ");
    scanf(" %[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    char yesNo;

    printf("Please enter the contact's street number: ");
    scanf("%d", &address->streetNumber);

    printf("Please enter the contact's street name: ");
    scanf(" %[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf(" %c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's apartment number: ");
        scanf("%d", &address->apartmentNumber);
    }

    printf("Please enter the contact's postal code: ");
    scanf(" %[^\n]%*c", address->postalCode);

    printf("Please enter the contact's city: ");
    scanf(" %[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char yesNo;

    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf(" %c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's cell phone number: ");
        scanf(" %[^\n]%*c", numbers->cell);
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c", &yesNo);

    //if (yesNo == 'y' && yesNo == 'Y') // <-- No! can't be both 'y' AND 'Y' (should be OR ||)
    if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's home phone number: ");
        scanf(" %[^\n]%*c", numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's business phone number: ");
        scanf(" %[^\n]%*c", numbers->business);
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{

}