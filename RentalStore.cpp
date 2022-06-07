
// ------------------------------------------------ RentalStore.cpp -----------------------------------------------------
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

#include "RentalStore.h"

//------------------------------------RentalStore-----------------------------------------------------
//The constructor will call a readfile helper method for each file that is given in a strict order of
//customer file, transaction file, and movie file. This will also initialize the variables for the
//Movies object and HashTable of Customers. We will call to read customers first to fill our customer base
//then call to read movies to fill the movie catalog, and finally call to read commands to load the queue.
//@param - 3 string files that represent the customer file, transaction file, and movie file in that
//strict order.
//@return - No direct return from a constructor.
// ---------------------------------------------------------------------------------------------------
RentalStore::RentalStore(ifstream &customer, ifstream &transaction, ifstream &movie) {
    customers = HashTable();
    catelog = Movies();

    readCustomer(customer);
    readTransaction(transaction);
    readMovie(movie);
}

//------------------------------------processTransactions---------------------------------------------
//This is a method that will be called in our main to process the transactions that are stored within
//the queue. Depending on the case (what the transaction is), it will handle it accordingly. This method
//calls helper methods historyHelper for H case, inventoryHelper for I case, borrowHelper for B case,
//returnHelper for R case, and badCommandHelper for any other cases. This method will also pop everything
//off the transaction queue and then put it on a temporary one so that this method can be called again.
//@param - N/A.
//@return - void.
//----------------------------------------------------------------------------------------------------
void RentalStore::processTransactions() {
    queue<string> tempQueue;
    while(!transaction.empty()){
        string action = transaction.front();
        transaction.pop();
        tempQueue.push(action);
        char actionLetter = action[0];

        switch(actionLetter){
            case 'H':
                historyHelper(action);
                break;
            case 'I':
                inventoryHelper(action);
                break;
            case 'B':
                borrowHelper(action);
                break;
            case 'R':
                returnHelper(action);
                break;
            default:
                badCommandHelper(action);
        }
    }
    transaction = tempQueue;
}

//------------------------------------display---------------------------------------------------------
//This is a method that will be called in our main to display the transaction history for all customers
//and the current movies and their stock. It will achieve this by calling the display methods of the Movies
//object, catelog, and of the HashTable object, customers.
//@param - N/A.
//@return - void.
//----------------------------------------------------------------------------------------------------
void RentalStore::display() const {
    cout << catelog.displayMovies();
    cout << customers.display();
}

//------------------------------------readCustomer-----------------------------------------------------
//This helper method will parse through the customer file to figure out the id and customer name for
//each customer. When we read a line, it will be split into the respective variables, initialized into
//the customer class, and added to the hash table.
//@param - ifstream of customer file.
//@return - void.
//-----------------------------------------------------------------------------------------------------
void RentalStore::readCustomer(ifstream &customerFile) {
    string customerLine;
    getline(customerFile, customerLine);
    while(customerFile.good()){
        if(!customerLine.empty()){
            int id = stoi(customerLine.substr(0, 4));
            customerLine = customerLine.substr(customerLine.find(' ') + 1, customerLine.size());
            string lName = customerLine.substr(0, customerLine.find(' '));
            customerLine = customerLine.substr(customerLine.find(' ') + 1);
            string fName = customerLine.substr(0, customerLine.find(' '));
            customers.addValue(new Customer(fName, lName, id));
        }
        getline(customerFile, customerLine);
    }
}

//------------------------------------readMovie-----------------------------------------------------
//This helper method will parse through the movie file to find what genre it is and then add that
//movie into the movie object we have in the class. The Movie class itself will do the rest of the
//work once we pass the movie string to it.
//@param - ifstream of customer file.
//@return - void.
//-----------------------------------------------------------------------------------------------------
void RentalStore::readMovie(ifstream &movieFile) {
    string movieLine;
    getline(movieFile, movieLine);
    while(movieFile.good()){
        if(!movieLine.empty()){
            catelog.addMovie(movieLine);
        }
        getline(movieFile, movieLine);
    }
}

//------------------------------------readTransactions-----------------------------------------------------
//This helper method will parse through the commands file to issue transactions that will be added to a
//queue. Each line of the file will be a string variable in the queue to help make the transactions
//flow in the right order and get the history of the transactions too.
//@param - ifstream of customer file.
//@return - void.
//-----------------------------------------------------------------------------------------------------
void RentalStore::readTransaction(ifstream &transactionFile) {
    string transactionLine;
    getline(transactionFile, transactionLine);
    while(transactionFile.good()){
        if(!transactionLine.empty()){
            transaction.push(transactionLine);
        }
        getline(transactionFile, transactionLine);
    }
}

//------------------------------------inventoryHelper-----------------------------------------------------
//This helper method will be called when an 'I' command is called in the transaction queue and processes this command.
//The inventory command will print all the available movies and their respective stock at our rental store.
//The order will be comedy, drama, and then classic movies.
//@param - string parsed from file.
//@return - void.
//-----------------------------------------------------------------------------------------------------
void RentalStore::inventoryHelper(string inventoryString) {
    cout << catelog.displayMovies();
}

//------------------------------------historyHelper-----------------------------------------------------
//This helper method will be called when an 'H' command is called in the transaction queue and processes this command.
//The history command will print the history of the current transactions done by a customer in latest to the earliest order.
//Prints error messages when there is no history available or the customer doesn't exist.
//@param - string parsed from file.
//@return - void.
//-----------------------------------------------------------------------------------------------------
void RentalStore::historyHelper(string historyString) {
    string id = historyString.substr(historyString.find(' ') + 1, 4);
    Customer *currentCustomer = customers.getValue(stoi(id));
    if(currentCustomer != nullptr){
        cout << "Rental history for " << currentCustomer->getFirstName() << " " << currentCustomer->getLastName() << ":" << endl;
        string customerHistory = customers.getValue(stoi(id))->display();
        if(customerHistory.empty()){
            cout << "No history" << endl;
        }
        else{
            cout << customerHistory << endl;
        }
    }
    else{
        cout << "Cannot get the history of the customer with id " << id << " because they do not exist in our system" << endl;
    }
}

//------------------------------------borrowHelper-----------------------------------------------------
//This helper method will be called when an "B" command is called in the transaction queue and processes this command.
//The borrow command will reduce the stock of the movie borrowed by one and put the transaction on the
//associated customer account. It won't happen if the stock is 0 or if the movie or customer doesn't exist.
//An error message will be output if the customer doesn't exist, if the movie doesn't exist, or if the stock is empty.
//@param - string parsed from file.
//@return - void.
//-----------------------------------------------------------------------------------------------------
void RentalStore::borrowHelper(string borrowString) {
    string id = borrowString.substr(borrowString.find(' ') + 1, 4);
    Customer *currentCustomer = customers.getValue(stoi(id));
    if(currentCustomer == nullptr){
        cout << "The customer with id " << id << " doesn't exist, so the borrow can't happen" << endl;
        return;
    }
    borrowString = borrowString.substr(7);
    if(borrowString[0] != 'D'){
        cout << "The customer with id " << id << " is trying to borrow a media type we don't carry" << endl;
        return;
    }
    borrowString = borrowString.substr(2, borrowString.size());
    char genre = borrowString[0];
    borrowString = borrowString.substr(borrowString.find(' ') + 1);
    switch(genre){
        case 'F': {
            string title = borrowString.substr(0, borrowString.find(','));
            borrowString = borrowString.substr(borrowString.find(',') + 1);
            string year = borrowString.substr(1);
            Comedy *movie = catelog.getComedyMovie(title, stoi(year));
            if (movie == nullptr || movie->getStock() <= 0) {
                cout << "The customer with id " << id << " is trying to borrow a media type we don't carry or are out of stock of" << endl;
            }
            else {
                currentCustomer->addTransaction('B',movie->getTitle());
                movie->borrowMovie();
            }
            break;
        }
        case 'D': {
            string director = borrowString.substr(0, borrowString.find(','));
            borrowString = borrowString.substr(borrowString.find(',') + 2);
            string title = borrowString.substr(0, borrowString.find(','));
            Drama *movie = catelog.getDramaMovie(title, director);
            if (movie == nullptr || movie->getStock() <= 0) {
                cout << "The customer with id " << id << " is trying to borrow a drama movie we don't carry or are out of stock of" << endl;
            }
            else {
                currentCustomer->addTransaction('B',movie->getTitle());
                movie->borrowMovie();
            }
            break;
        }
        case 'C': {
            Classic *movie = catelog.getClassicMovie(borrowString);
            if (movie == nullptr || movie->getStock() <= 0) {
                cout << "The customer with id " << id << " is trying to borrow a classic movie we don't carry or are out of stock of" << endl;
            } else {
                currentCustomer->addTransaction('B',movie->getTitle());
                movie->borrowMovie();
            }
            break;
        }
        default:
            cout << "The customer with id " << id << " is trying to borrow a genre of movie we don't carry" << endl;
            return;
    }

}

//------------------------------------returnHelper-----------------------------------------------------
//This helper method will be called when an "R" command is called in the transaction queue and processes this command.
//The return command will reduce the stock of the movie returned by one and put the transaction on the
//associated customer account. It won't happen if the movie or customer doesn't exist or if the movie was never borrowed first.
//An error message will be output if the customer doesn't exist or if the movie doesn't exist.
//@param - string parsed from file.
//@return - void.
//-----------------------------------------------------------------------------------------------------
void RentalStore::returnHelper(string returnString) {
    string id = returnString.substr(returnString.find(' ') + 1, 4);
    Customer *currentCustomer = customers.getValue(stoi(id));
    if(currentCustomer == nullptr){
        cout << "The customer with id " << id << " doesn't exist, so the borrow can't happen" << endl;
        return;
    }
    returnString = returnString.substr(7);
    if(returnString[0] != 'D'){
        cout << "The customer with id " << id << " is trying to borrow a media type we don't carry" << endl;
        return;
    }
    returnString = returnString.substr(2, returnString.size());
    char genre = returnString[0];
    returnString = returnString.substr(returnString.find(' ') + 1);
    switch(genre){
        case 'F': {
            string title = returnString.substr(0, returnString.find(','));
            returnString = returnString.substr(returnString.find(',') + 1);
            string year = returnString;
            Comedy *movie = catelog.getComedyMovie(title, stoi(year));
            if (movie == nullptr || !currentCustomer->isBorrowed(movie->getTitle())) {
                cout << "The customer with id " << id << " is trying to return a media type we don't carry or they haven't borrowed the movie yet" << endl;
            }
            else {
                currentCustomer->addTransaction('R',movie->getTitle());
                movie->returnMovie();
            }
            break;
        }
        case 'D': {
            string director = returnString.substr(0, returnString.find(','));
            returnString = returnString.substr(returnString.find(',') + 1);
            string title = returnString.substr(0, returnString.find(','));
            Drama *movie = catelog.getDramaMovie(title, director);
            if (movie == nullptr || !currentCustomer->isBorrowed(movie->getTitle())) {
                cout << "The customer with id " << id << " is trying to return a media type we don't carry or they haven't borrowed the movie yet" << endl;
            }
            else {
                currentCustomer->addTransaction('R',movie->getTitle());
                movie->returnMovie();
            }
            break;
        }
        case 'C': {
            Classic *movie = catelog.getClassicMovie(returnString);
            if (movie == nullptr || !currentCustomer->isBorrowed(movie->getTitle())) {
                cout << "The customer with id " << id << " is trying to return a media type we don't carry or they haven't borrowed the movie yet" << endl;
            } else {
                currentCustomer->addTransaction('R',movie->getTitle());
                movie->returnMovie();
            }
            break;
        }
        default:
            cout << "The customer with id " << id << " is trying to borrow a genre of movie we don't carry" << endl;
            return;
    }
}

//------------------------------------badCommandHelper-----------------------------------------------------
//This helper method will be called when any command besides the implemented ones are called. This will
//print out an error message for invalid action code.
//@param - string parsed from file.
//@return - void.
//-----------------------------------------------------------------------------------------------------
void RentalStore::badCommandHelper(string badString) {
    cout << "The transaction being attempted, " << badString[0] << ", doesn't exist" << endl;
}

