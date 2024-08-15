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


#include "contacts.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);

// getIntInRange:
// Put function prototype below:
int getIntInRange(int min, int max);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);



// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact[], int, const char[]);


// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact*);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact[], int);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact[], int);

// addContact:
// put function prototype here:
void addContacts(struct Contact[], int);

// updateContact:
// put function prototype here:
void updateContact(struct Contact[], int);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact[], int);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact[], int);
