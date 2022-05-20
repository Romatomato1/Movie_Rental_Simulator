// ------------------------------------------------ RentalStore.h -------------------------------------------------------
- 
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 5/20/2022 
// --------------------------------------------------------------------------------------------------------------------
// vThis is the class that will represent our movie rental store. As such, it will include the catalog of movies through
// a Movie object, a HashTable of Customer objects to store who has an account at the rental store, and a queue of strings
// to represent transactions done at the rental store.  
// -------------------------------------------------------------------------------------------------------------------- 
// Assumes that files are entered in the correct order.
// --------------------------------------------------------------------------------------------------------------------

#ifndef ASSIGNMENT_4_RENTALSTORE_H
#define ASSIGNMENT_4_RENTALSTORE_H
#include "HashTable.h"
using namespace std;
class RentalStore {
public:
    //------------------------------------RentalStore-----------------------------------------------------
    //The constructor will call a readfile helper method for each file that is given in a strict order of 
    //customer file, transaction file, and movie file. This will also initialize the variables for the 
    //Movie object, HashTable of Customers, and the queue of strings for transactions. We will call to read
    //customers first to fill our customer base, then call to read movies to fill the movie catalog, and 
    //finally call to read commands to make transactions with the data that is now being held. 
    //@param - 3 string files that represent the customer file, transaction file, and movie file in that strict order. 
    //@return - No direct return from a constructor. 
    // ---------------------------------------------------------------------------------------------------
    RentalStore();
private:
    struct Customer {
        string firstName;
        string lastName;
        int id;
    };
};


#endif //ASSIGNMENT_4_RENTALSTORE_H
