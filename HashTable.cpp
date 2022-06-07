// ------------------------------------------------ HashTable.cpp-------------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B
// 5/20/2022
// 6/7/2022
// ---------------------------------------------------------------------------------------------------------------------
// This class is going to be a hash table that will store customer objects. It will have a hash function that will take
// the customer's id and does the mod by the MAXSIZE to find the hash value and where it will be on the hash table.This
// iteration of the hash table will be using the open hash method where duplicate hash values will be handled through.
// a linked list.
// ---------------------------------------------------------------------------------------------------------------------
// Assumes that the customers being stored have the correct syntax regarding name size and id size.
// ---------------------------------------------------------------------------------------------------------------------

#include "HashTable.h"

//------------------------------------HashTable Default Constructor-----------------------------------------------------
//This is the default constructor that will set the MAXSIZE varible to 101 when called without a
//parameter. After this, the constructor will initializae an array of linked lists with a size of whatever
//the MAXSIZE is. The size will be intialized to zero and each index in the array will be set to null.
//@param - N/A
//@return - No direct return from a constructor.
// ---------------------------------------------------------------------------------------------------------------------
HashTable::HashTable() {

}

//------------------------------------HashTable Destructor--------------------------------------------------------------
//The destructor will delete every new linked list created for each index of the array we allocated.
//@param - N/A.
//@return - void.
//----------------------------------------------------------------------------------------------------------------------
HashTable::~HashTable() {
    for(const auto& list: hashTable){
        for(auto customer: list){
            delete customer;
        }
    }
}

//------------------------------------addValue--------------------------------------------------------------------------
//This method will add the customer to value into the parameter. It will achieve this by calling the
//private hashify method to convert the associated customer key to an index in the array. It will be
//added to the Customer linked list that is equal to the hash value created from hashify.
//@param - Customer pointer that will be added to hash table.
//@return - Returns true if added.
//----------------------------------------------------------------------------------------------------------------------
bool HashTable::addValue(Customer* user) {
    if (!contains(user->getIdNumber())) {
        int hashCode = hashify(user->getIdNumber());
        hashTable[hashCode].push_back(user);
        return true;
    }
    return false;
}

//------------------------------------Hashify---------------------------------------------------------------------------
//This helper method will be called by various methods when the hash function needs to be performed.
//The hash function will essentially do the integer parameter mod the MAXSIZE.
//@param - Takes in an integer representing the id.
//@return - Returns the hash value which will be used as the index in the hash table array.
//----------------------------------------------------------------------------------------------------------------------
int HashTable::hashify(int id) const {
    return id%MAX_SIZE;
}

//------------------------------------contains--------------------------------------------------------------------------
//This helper method will be called to prevent duplicates in the Hash Table.
//@param - user - Customer object to be checked
//@return - boolean if in the Hash Table
//----------------------------------------------------------------------------------------------------------------------
bool HashTable::contains(int id) const{
    for(int i = 0; i < MAX_SIZE; i++){
        list<Customer*> linkedList = hashTable[i];
        for(const auto& currentCustomer : linkedList)
        {
            if (id == currentCustomer->getIdNumber()){
                return true;
            }
        }
    }
    return false;
}

//------------------------------------getValue--------------------------------------------------------------------------
//This method will return the customer object that is associated with the integer that is in the parameter.
//@param - Integer representing customer id.
//@return - Return the Customer object that is associated with id.
//----------------------------------------------------------------------------------------------------------------------
Customer* HashTable::getValue(int id) const {
    for(const auto& list: hashTable){
        for(const auto& currentCustomer : list)
        {
            if (id == currentCustomer->getIdNumber()){
                return currentCustomer;
            }
        }
    }
    return nullptr;
}

//-----------------------------------display------------------------------------------------------------------------
//This will display all the customers' data likely formatted as firstname, lastname, and id number.
//@param - N/A.
//@return - String
// -----------------------------------------------------------------------------------------------------------------
string HashTable::display() const{
    string result;
    for(const auto& list: hashTable){
        for(auto customer: list){
            result += "\nRental history for " + customer->getFirstName() + " " + customer->getLastName() + ":\n";
            if(customer->display().empty()){
                result += "No history\n";
            }
            else{
                result += customer->display();
            }
        }
    }
    return result;
}

