// ------------------------------------------------ Customer.h -------------------------------------------------------
- 
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 5/23/2022 
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our Customer and all the data and transactions associated with a customer.
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef ASSIGNMENT_4_CUSTOMER_H
#define ASSIGNMENT_4_CUSTOMER_H


class Customer {
public:
    //------------------------------------Customer-----------------------------------------------------
    //This is the class that will represent our customer objects. As such it will include their first and last names and their ID number.
    //A customer object just stores the information about the customer and contains basic methods. 
    //This class will also store 2 arrays of strings that will represent what a particular customer has borrowed and returned from the rental store.
    //This will be useful information to have when printing out information about customers. 

    //@param - 3 string files that represent the customer file, transaction file, and movie file in that 
    //strict order. 
    //@return - No direct return from a constructor. 
    // ---------------------------------------------------------------------------------------------------
  
  //Customer constructor will call the associated mutators to set the parameters to their respective variables. 
  Customer(string fName, string lName, int ID) {
    
  }
    
    //------------------------------------getName -----------------------------------------------------
    //It will retrieve the string variable associated with the first name variable
    //@param - N/A.
    //@return - string associated with first name.
    // ---------------------------------------------------------------------------------------------------

  getName() {
    
  }
    
  
    //------------------------------------getLastName -----------------------------------------------------
    //It will retrieve the string variable associated with the last name variable
    //@param - N/A.
    //@return - string associated with first name.
    // ---------------------------------------------------------------------------------------------------
  getlastName()
    
    //------------------------------------getIdNumber -----------------------------------------------------
    //It will retrieve the int variable associated with the user ID
    //@param - N/A.
    //@return - string associated ID number.
    // ---------------------------------------------------------------------------------------------------
    
  getIdNumber()
    
    //-----------------------------------Display------------------------------------------------------------
    //IThis will display all the customer data likely formatted as firstname, lastname, and id number. 

    //@param - N/A.
    //@return - Void
    // -----------------------------------------------------------------------------------------------------
  display()
private:
  
  setFirstName()
  setLastName()
  setIdNumber
  //Class Fields
    
  string firstName;
  string lastName;
  int idNumber;
  string borrowed[];
  string returned[];
};


#endif //ASSIGNMENT_4_CUSTOMER_H
