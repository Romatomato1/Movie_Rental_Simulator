// ------------------------------------------------ HashTable.h -------------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 5/24/2022
// --------------------------------------------------------------------------------------------------------------------
// This class is going to be a hash table that will store customer objects. It will have a hash function that will take
// the customer's id and does the mod by the MAXSIZE to find the hash value and where it will be on the hash table.
// This iteration of the hash table will be using the open hash method where duplicate hash values will be handled through
// a linked list.
// -------------------------------------------------------------------------------------------------------------------- 
// Assumes that the customers being stored have the correct syntax regarding name size and id size.
// --------------------------------------------------------------------------------------------------------------------

#ifndef ASSIGNMENT_4_HASHTABLE_H
#define ASSIGNMENT_4_HASHTABLE_H

#include <list>
#include <array>
#include "Customer.h"
using namespace std;
class HashTable {
  public:
    //------------------------------------HashTable Default Constructor-----------------------------------
    //This is the default constructor that will set the MAXSIZE varible to 101 when called without a
    //parameter. After this, the constructor will initializae an array of linked lists with a size of whatever
    //the MAXSIZE is. The size will be intialized to zero and each index in the array will be set to null.
    //@param - N/A
    //@return - No direct return from a constructor. 
    // ---------------------------------------------------------------------------------------------------
    HashTable();
  
    //------------------------------------HashTable Second Constructor------------------------------------
    //This is the second constructor that will take in an integer value that will be set to the MAXSIZE 
    //variable. Same as the default, it will initializae an array of linked lists with a size of whatever
    //the MAXSIZE is. The size will be intialized to zero and each index in the array will be set to null.
    //@param - Integer representing the size.
    //@return - No direct return from a constructor. 
    // ---------------------------------------------------------------------------------------------------
    HashTable(int size);
  
    //------------------------------------HashTable Destructor--------------------------------------------
    //The destructor will delete every new linked list created for each index of the array we allocated.  
    //@param - N/A.
    //@return - void.
    //----------------------------------------------------------------------------------------------------
    ~HashTable();
    
    //------------------------------------getSize---------------------------------------------------------
    //This method will simply return the number of customers inserted into hash table so far.
    //@param - N/A.
    //@return - Return the integer value associated with the size variable.
    //----------------------------------------------------------------------------------------------------
    int getSize() const;
  
    //------------------------------------addValue---------------------------------------------------------
    //This method will add the customer to value into the parameter. It will achieve this by calling the
    //private hashify method to convert the associated customer key to an index in the array. It will be
    //added to the Customer linked list that is equal to the hash value created from hashify. 
    //@param - Customer object that will be added to hash table.
    //@return - Returns true if added.
    //-----------------------------------------------------------------------------------------------------
    bool addValue(Customer user);
  
    //------------------------------------getValue--------------------------------------------------------
    //This method will return the customer object that is associated with the integer that is in the parameter.
    //@param - Integer representing customer id.
    //@return - Return the Customer object that is associated with id. 
    //----------------------------------------------------------------------------------------------------
    Customer getValue(int id) const;
  
    //------------------------------------removeValue---------------------------------------------------------
    //This method will remove the customer object that is associated with the integer parameter. This method will
    // be sure to make the index where removal happened to be a special spot for further indication. 
    //@param - Integer representing customer id.
    //@return - Return true if the removal succeeds.
    //--------------------------------------------------------------------------------------------------------
    bool removeValue(int id);
 
private:
    //Fields
    
    //Maximum size of array that is intialized through the constructor
    static const int MAX_SIZE = 101;
    
    //Represents the number of customers in the hash table currently
    int size;
    
    //Array of linked lists type customer that will be the hashtable
    array<list<Customer>,MAX_SIZE> hashTable;
    
    //Helper Methods
    
    //------------------------------------Hashify-----------------------------------------------------
    //This helper method will be called by various methods when the hash function needs to be performed.
    //The hash function will essentially do the integer parameter mod the MAXSIZE.
    //@param - Takes in an integer representing the id.
    //@return - Returns the hash value which will be used as the index in the hash table array.
    //------------------------------------------------------------------------------------------------
    int Hashify(int id) const;  
};


#endif //ASSIGNMENT_4_HASHTABLE_H
