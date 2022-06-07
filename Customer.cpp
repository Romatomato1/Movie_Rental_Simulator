// ------------------------------------------------ Customer.h --------------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B
// 5/20/2022
// 6/7/2022
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our Customer and all the data and transactions associated with a customer.
// --------------------------------------------------------------------------------------------------------------------
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include "Customer.h"

//------------------------------------Customer--------------------------------------------------------------------------
//This is the class that will represent our customer objects. As such it will include their first and last names and
//their ID number.A customer object just stores the information about the customer and contains basic methods.This
//class will also store 2 arrays of strings that will represent what a particular customer has borrowed and returned
//from the rental store. This will be useful information to have when printing out information about customers.
//@param - 3 string files that represent the customer file, transaction file, and movie file in that
//strict order.
//@return - No direct return from a constructor.
// ---------------------------------------------------------------------------------------------------------------------
Customer::Customer(string fName, string lName, int ID) {
    setFirstName(fName);
    setLastName(lName);
    setIdNumber(ID);
    transactions = vector<string>();
}

//-----------------------------------operator==-------------------------------------------------------------------------
//Equality operator for Customer.
//@param - Customer object
//@return - Boolean if equal
// ---------------------------------------------------------------------------------------------------------------------
bool Customer::operator==(const Customer &user) const {
    return this->idNumber == user.getIdNumber();
}

//------------------------------------getIdNumber ----------------------------------------------------------------------
//It will retrieve the int variable associated with the user ID
//@param - N/A.
//@return - string associated ID number.
// ---------------------------------------------------------------------------------------------------------------------
int Customer::getIdNumber() const {
    return idNumber;
}

//------------------------------------getFirstName----------------------------------------------------------------------
//It will retrieve the string variable associated with the first name variable
//@param - N/A.
//@return - string associated with first name.
// ---------------------------------------------------------------------------------------------------------------------
string Customer::getFirstName() const {
    return firstName;
}

//------------------------------------getLastName ----------------------------------------------------------------------
//It will retrieve the string variable associated with the last name variable
//@param - N/A.
//@return - string associated with first name.
// ---------------------------------------------------------------------------------------------------------------------
string Customer::getLastName() const {
    return lastName;
}

//-----------------------------------setFirstName-----------------------------------------------------------------------
//This is a private method that will be used to properly set the variable of first name.
//This may include making sure it is the proper length (less than 25 chars) and properly formatted.
//@param - takes a string first name.
//@return - void.
// ---------------------------------------------------------------------------------------------------------------------
void Customer::setFirstName(string firstName) {
    this->firstName = firstName;
}

//-----------------------------------setLastName------------------------------------------------------------------------
//This is a private method that will be used to properly set the variable of last name.
//This may include making sure it is the proper length (less than 25 chars) and properly formatted.
//@param - takes a string last name.
//@return - void.
// ---------------------------------------------------------------------------------------------------------------------
void Customer::setLastName(string lastName) {
    this->lastName = lastName;
}

//-----------------------------------SetIdName--------------------------------------------------------------------------
//This is a private method that will be used to properly set the variable of first name.
//This may include making sure it is the proper length (less than 25 chars) and properly formatted.
//@param - takes a string first name.
//@return - void.
// ---------------------------------------------------------------------------------------------------------------------
void Customer::setIdNumber(int id) {
    idNumber = id;
}

//-----------------------------------addTransaction---------------------------------------------------------------------
//This will add a transaction to the list for a customer object
//@param - The string representing the transaction
//@return - N/A
// ---------------------------------------------------------------------------------------------------------------------
void Customer::addTransaction(char action, const string& title) {
    string formattedTransaction;
    if(action == 'B'){
        formattedTransaction = "Borrowed " + title + ".";
    }else{
        formattedTransaction = "Returned " + title + ".";
    }
    transactions.push_back(formattedTransaction);
}

//-----------------------------------Display----------------------------------------------------------------------------
//This will display all the customer data likely formatted as firstname, lastname, and id number.
//@param - N/A.
//@return - String
// ---------------------------------------------------------------------------------------------------------------------
string Customer::display() {
    string result;
    for(const auto& transaction:transactions) {
        result += transaction + "\n";
    }
    return result;
}


