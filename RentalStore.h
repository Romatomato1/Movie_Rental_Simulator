// ------------------------------------------------ RentalStore.h -------------------------------------------------------
- 
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 5/20/2022 
// --------------------------------------------------------------------------------------------------------------------
// Rental store reads in all the data from three files in a set order. It then goes on to store said data in 
// data sets. It contains methods that will process transactions as they come out of the queue and record data.    
// -------------------------------------------------------------------------------------------------------------------- 
// Assumes that files are entered in the correct order.
// --------------------------------------------------------------------------------------------------------------------

#ifndef ASSIGNMENT_4_RENTALSTORE_H
#define ASSIGNMENT_4_RENTALSTORE_H
#include "HashTable.h"
using namespace std;
class RentalStore {
public:
private:
    struct Customer {
        string firstName;
        string lastName;
        int id;
    };
};


#endif //ASSIGNMENT_4_RENTALSTORE_H
