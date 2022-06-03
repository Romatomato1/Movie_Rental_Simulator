//
// Created by roman on 5/20/2022.
//

#include "Customer.h"

bool Customer::operator==(const Customer &user) const {
    return this->idNumber==user.getIdNumber();
}

int Customer::getIdNumber() const {
    return idNumber;
}
