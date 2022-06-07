#include <iostream>
#include "RentalStore.h"
int main() {
    ifstream file1("data4commands.txt");
    ifstream file2("data4customers.txt");
    ifstream file3("data4movies.txt");
    RentalStore store(file2, file1, file3);
    store.processTransactions();
    store.display();
    return 0;
}
