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


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

void getName(struct Name* name)
{

    int yesNo;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%[^\n]", name->middleInitial);
        clearKeyboard();
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

void getAddress(struct Address* address)
{
    int yesNo;

    printf("Please enter the contact's street number: ");
    do
    {
        address->streetNumber = getInt();
        if (address->streetNumber < 0)
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
    } while (address->streetNumber < 0);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's apartment number: ");
        do
        {
            address->apartmentNumber = getInt();
            if (address->apartmentNumber < 0)
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
        } while (address->apartmentNumber < 0);
    }

    printf("Please enter the contact's postal code: ");
    scanf("%[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

void getNumbers(struct Numbers* numbers)
{
    int yesNo;
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }
    else
    {
        numbers->home[0] = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else
    {
        numbers->business[0] = '\0';
    }
}

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}