//
// Created by roman on 5/18/2022.
//

#include "RentalStore.h"

RentalStore::RentalStore(ifstream &customer, ifstream &transaction, ifstream &movie) {
    customers = HashTable();
    catelog = Movies();

    readCustomer(customer);
    readTransaction(transaction);
    readMovie(movie);
}

RentalStore::~RentalStore() {

}

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
}

void RentalStore::display() const {
    cout << catelog.displayMovies();
    cout << customers.display();
}

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

void RentalStore::inventoryHelper(string inventoryString) {
    cout << catelog.displayMovies();
}

void RentalStore::historyHelper(string historyString) {
    string id = historyString.substr(historyString.find(' ') + 1, 4);
    Customer *currentCustomer = customers.getValue(stoi(id));
    if(currentCustomer->getIdNumber() != 0){
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

void RentalStore::borrowHelper(string borrowString) {
    string id = borrowString.substr(borrowString.find(' ') + 1, 4);
    Customer *currentCustomer = customers.getValue(stoi(id));
    if(currentCustomer->getIdNumber() == 0){
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
            if (movie->getStock() <= 0) {
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
            if (movie->getStock() <= 0) {
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
            if (movie->getStock() <= 0) {
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

void RentalStore::returnHelper(string returnString) {
    string id = returnString.substr(returnString.find(' ') + 1, 4);
    Customer *currentCustomer = customers.getValue(stoi(id));
    if(currentCustomer->getIdNumber() == 0){
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
            if (movie->getTitle().empty()) {
                cout << "The customer with id " << id << " is trying to return a media type we don't carry" << endl;
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
            if (movie->getTitle().empty()) {
                cout << "The customer with id " << id << " is trying to return a media type we don't carry" << endl;
            }
            else {
                currentCustomer->addTransaction('R',movie->getTitle());
                movie->returnMovie();
            }
            break;
        }
        case 'C': {
            Classic *movie = catelog.getClassicMovie(returnString);
            if (movie->getTitle().empty()) {
                cout << "The customer with id " << id << " is trying to return a media type we don't carry" << endl;
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

void RentalStore::badCommandHelper(string badString) {
    cout << "The transaction being attempted, " << badString[0] << ", doesn't exist" << endl;
}

