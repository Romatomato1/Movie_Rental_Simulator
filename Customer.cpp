//

#include "Customer.h"
Customer::Customer(string fName, string lName, int ID) {
    setFirstName(fName);
    setLastName(lName);
    setIdNumber(ID);
}

bool Customer::operator==(const Customer &user) const {
    return this->idNumber == user.getIdNumber();
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

        void Customer::setIdNumber(int id) {
            idNumber = id;
        }
void Customer::addTransaction(string transaction) {
    transactions.push_back(transaction);
}

string Customer::display() {
    string result = "";
    result += firstName + " " + lastName+" Number: " + to_string(idNumber) + "Transactions:\n";
    for(string transaction:transactions) {

    }
}


