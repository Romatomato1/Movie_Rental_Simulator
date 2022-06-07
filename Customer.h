// ------------------------------------------------ Customer.h --------------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B
// 5/20/2022
// 6/7/2022
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our Customer and all the data and transactions associated with a customer.
// --------------------------------------------------------------------------------------------------------------------
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------
#ifndef ASSIGNMENT_4_CUSTOMER_H
#define ASSIGNMENT_4_CUSTOMER_H

#include <string>
#include <array>
#include <vector>

using namespace std;

class Customer {
public:
    //Size of HashArray
    static int const MAX = 1000;

    //------------------------------------Customer----------------------------------------------------------------------
    //This is the class that will represent our customer objects. As such it will include their first and last names and
    //their ID number.A customer object just stores the information about the customer and contains basic methods.This
    //class will also store 2 arrays of strings that will represent what a particular customer has borrowed and returned
    //from the rental store. This will be useful information to have when printing out information about customers.
    //@param - 3 string files that represent the customer file, transaction file, and movie file in that
    //strict order.
    //@return - No direct return from a constructor.
    // -----------------------------------------------------------------------------------------------------------------
    Customer(string firstName, string lastName, int idNumber);

    //------------------------------------getFirstName -----------------------------------------------------------------
    //It will retrieve the string variable associated with the first name variable
    //@param - N/A.
    //@return - string associated with first name.
    // -----------------------------------------------------------------------------------------------------------------
    string getFirstName()const;


    //------------------------------------getLastName ------------------------------------------------------------------
    //It will retrieve the string variable associated with the last name variable
    //@param - N/A.
    //@return - string associated with first name.
    // -----------------------------------------------------------------------------------------------------------------
    string getLastName()const;

    //------------------------------------getIdNumber ------------------------------------------------------------------
    //It will retrieve the int variable associated with the user ID
    //@param - N/A.
    //@return - string associated ID number.
    // -----------------------------------------------------------------------------------------------------------------
    int getIdNumber()const;

    //-----------------------------------addTransaction-----------------------------------------------------------------
    //This will add a transaction to the list for a customer object
    //@param - The string representing the transaction
    //@return - N/A
    // -----------------------------------------------------------------------------------------------------------------
    void addTransaction(char action, const string& title);

    //-----------------------------------display------------------------------------------------------------------------
    //This will display all the customer data likely formatted as firstname, lastname, and id number.
    //@param - N/A.
    //@return - String
    // -----------------------------------------------------------------------------------------------------------------
    string display();

    //-----------------------------------operator==---------------------------------------------------------------------
    //Equality operator for Customer.
    //@param - Customer object
    //@return - Boolean if equal
    // -----------------------------------------------------------------------------------------------------------------
    bool operator== (const Customer &user)const;
private:
    //-----------------------------------setFirstName-------------------------------------------------------------------
    //This is a private method that will be used to properly set the variable of first name.
    //This may include making sure it is the proper length (less than 25 chars) and properly formatted.
    //@param - takes a string first name.
    //@return - void.
    // -----------------------------------------------------------------------------------------------------------------
    void setFirstName(string firstName);

    //-----------------------------------setLastName--------------------------------------------------------------------
    //This is a private method that will be used to properly set the variable of last name.
    //This may include making sure it is the proper length (less than 25 chars) and properly formatted.
    //@param - takes a string last name.
    //@return - void.
    // -----------------------------------------------------------------------------------------------------------------
    void setLastName(string lastName);

    //-----------------------------------SetIdName----------------------------------------------------------------------
    //This is a private method that will be used to properly set the variable of first name.
    //This may include making sure it is the proper length (less than 25 chars) and properly formatted.
    //@param - takes a string first name.
    //@return - void.
    // -----------------------------------------------------------------------------------------------------------------
    void setIdNumber(int idNumber);

    //Class Fields
    string firstName;
    string lastName;
    int idNumber;
    vector<string> transactions;
};

#endif