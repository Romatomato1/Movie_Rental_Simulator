
// ------------------------------------------------ RentalStore.h -----------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 6/7/2022
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our movie rental store. As such, it will include the catalog of movies through
// a Movie object, a HashTable of Customer objects to store who has an account at the rental store, and a queue of strings
// to represent transactions done at the rental store.  
// -------------------------------------------------------------------------------------------------------------------- 
// Assumes that files are entered in the correct order.
// --------------------------------------------------------------------------------------------------------------------

#ifndef ASSIGNMENT_4_RENTALSTORE_H
#define ASSIGNMENT_4_RENTALSTORE_H
#include "HashTable.h"
#include "Customer.h"
#include "Movies.h"
#include <queue>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
class RentalStore {
public:
    //------------------------------------RentalStore-----------------------------------------------------
    //The constructor will call a readfile helper method for each file that is given in a strict order of
    //customer file, transaction file, and movie file. This will also initialize the variables for the
    //Movies object and HashTable of Customers. We will call to read customers first to fill our customer base
    //then call to read movies to fill the movie catalog, and finally call to read commands to load the queue.
    //@param - 3 string files that represent the customer file, transaction file, and movie file in that
    //strict order.
    //@return - No direct return from a constructor.
    // ---------------------------------------------------------------------------------------------------
    RentalStore(ifstream &customer, ifstream &transaction, ifstream &movie);

    //------------------------------------processTransactions---------------------------------------------
    //This is a method that will be called in our main to process the transactions that are stored within
    //the queue. Depending on the case (what the transaction is), it will handle it accordingly. This method
    //calls helper methods historyHelper for H case, inventoryHelper for I case, borrowHelper for B case,
    //returnHelper for R case, and badCommandHelper for any other cases. This method will also pop everything
    //off the transaction queue and then put it on a temporary one so that this method can be called again.
    //@param - N/A.
    //@return - void.
    //----------------------------------------------------------------------------------------------------
    void processTransactions();

    //------------------------------------display---------------------------------------------------------
    //This is a method that will be called in our main to display the transaction history for all customers
    //and the current movies and their stock. It will achieve this by calling the display methods of the Movies
    //object, catelog, and of the HashTable object, customers.
    //@param - N/A.
    //@return - void.
    //----------------------------------------------------------------------------------------------------
    void display() const;
    
private:
    //Fields
    
    //Constainer for customer information
    HashTable customers;

    //Container for transactions
    queue<string> transaction;

    //Container for movie information as well as genre specifications
    Movies catelog;
    
    //Helper Methods

    //------------------------------------readCustomer-----------------------------------------------------
    //This helper method will parse through the customer file to figure out the id and customer name for
    //each customer. When we read a line, it will be split into the respective variables, initialized into
    //the customer class, and added to the hash table.
    //@param - ifstream of customer file.
    //@return - void.
    //-----------------------------------------------------------------------------------------------------
    void readCustomer(ifstream &customerFile);

    //------------------------------------readMovie-----------------------------------------------------
    //This helper method will parse through the movie file to find what genre it is and then add that
    //movie into the movie object we have in the class. The Movie class itself will do the rest of the
    //work once we pass the movie string to it.
    //@param - ifstream of customer file.
    //@return - void.
    //-----------------------------------------------------------------------------------------------------
    void readMovie(ifstream &movieFile);

    //------------------------------------readTransactions-----------------------------------------------------
    //This helper method will parse through the commands file to issue transactions that will be added to a
    //queue. Each line of the file will be a string variable in the queue to help make the transactions
    //flow in the right order and get the history of the transactions too.
    //@param - ifstream of customer file.
    //@return - void.
    //-----------------------------------------------------------------------------------------------------
    void readTransaction(ifstream &transactionFile);

    //------------------------------------inventoryHelper-----------------------------------------------------
    //This helper method will be called when an 'I' command is called in the transaction queue and processes this command.
    //The inventory command will print all the available movies and their respective stock at our rental store.
    //The order will be comedy, drama, and then classic movies.
    //@param - string parsed from file.
    //@return - void.
    //-----------------------------------------------------------------------------------------------------
    void inventoryHelper(string inventoryString);

    //------------------------------------historyHelper-----------------------------------------------------
    //This helper method will be called when an 'H' command is called in the transaction queue and processes this command.
    //The history command will print the history of the current transactions done by a customer in latest to the earliest order.
    //Prints error messages when there is no history available or the customer doesn't exist.
    //@param - string parsed from file.
    //@return - void.
    //-----------------------------------------------------------------------------------------------------
    void historyHelper(string historyString);

    //------------------------------------borrowHelper-----------------------------------------------------
    //This helper method will be called when an "B" command is called in the transaction queue and processes this command.
    //The borrow command will reduce the stock of the movie borrowed by one and put the transaction on the
    //associated customer account. It won't happen if the stock is 0 or if the movie or customer doesn't exist.
    //An error message will be output if the customer doesn't exist, if the movie doesn't exist, or if the stock is empty.
    //@param - string parsed from file.
    //@return - void.
    //-----------------------------------------------------------------------------------------------------
    void borrowHelper(string borrowString);

    //------------------------------------returnHelper-----------------------------------------------------
    //This helper method will be called when an "R" command is called in the transaction queue and processes this command.
    //The return command will reduce the stock of the movie returned by one and put the transaction on the
    //associated customer account. It won't happen if the movie or customer doesn't exist or if the movie was never borrowed first.
    //An error message will be output if the customer doesn't exist or if the movie doesn't exist.
    //@param - string parsed from file.
    //@return - void.
    //-----------------------------------------------------------------------------------------------------
    void returnHelper(string returnString);

    //------------------------------------badCommandHelper-----------------------------------------------------
    //This helper method will be called when any command besides the implemented ones are called. This will
    //print out an error message for invalid action code.
    //@param - string parsed from file.
    //@return - void.
    //-----------------------------------------------------------------------------------------------------
    void badCommandHelper(string badString);

};


#endif //ASSIGNMENT_4_RENTALSTORE_H
