//
// Created by roman on 5/18/2022.
//

#include "HashTable.h"

//------------------------------------HashTable Default Constructor-----------------------------------
//This is the default constructor that will set the MAXSIZE varible to 101 when called without a
//parameter. After this, the constructor will initializae an array of linked lists with a size of whatever
//the MAXSIZE is. The size will be intialized to zero and each index in the array will be set to null.
//@param - N/A
//@return - No direct return from a constructor.
// ---------------------------------------------------------------------------------------------------
HashTable::HashTable() {

}

bool HashTable::addValue(Customer* user) {
    if (!contains(user->getIdNumber())) {
        int hashCode = hashify(user->getIdNumber());
        hashTable[hashCode].push_back(user);
        return true;
    }
    return false;
}

int HashTable::hashify(int id) const {
    return id%MAX_SIZE;
}

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

HashTable::~HashTable() {
    for(const auto& list: hashTable){
        for(auto customer: list){
            delete customer;
        }
    }
}

bool HashTable::removeValue(int id) {
    for(int i = 0; i < MAX_SIZE; i++){
        list<Customer*> linkedList = hashTable[i];
        for(const auto& currentCustomer : linkedList)
        {
            if (id == currentCustomer->getIdNumber()){
                linkedList.remove(currentCustomer);
                return true;
            }
        }
    }
    return false;
}

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

