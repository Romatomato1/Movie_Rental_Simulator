//
// Created by roman on 5/20/2022.
//

#include "Customer.h"

Customer::Customer(string firstName, string lastName, int idNumber){
    setLastName(lastName);
    setFirstName(firstName);
    setIdNumber(idNumber);
}


bool Customer::operator==(const Customer &user) const {
    return this->idNumber==user.getIdNumber();
}

int Customer::getIdNumber() const {
    return idNumber;
}

string Customer::getFirstName() const {
    return firstName;
}

string Customer::getLastName() const {
    return lastName;
}

void Customer::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Customer::setLastName(string lastName) {
    this->lastName = lastName;
}

void Customer::setIdNumber(int idNumber) {
    this->idNumber = idNumber;
}

void Customer::addTransaction(string transaction) {
    transactions.push_back(transaction);
}

string Customer::display() {
    string result = "";
    result += firstName + " " + lastName+" Number: " + idNumber + "Transactions:\n";
    for(string transaction:transactions) {

    }
}
