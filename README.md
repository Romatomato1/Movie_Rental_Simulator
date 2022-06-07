# Assignment_4 Segmentation Fault

---------------------------------------------------- READ ME ----------------------------------------------------

This file will detail and outline what our Assignment 4 assumptions and applications are.

Contributions:
Roman: Implementing and integrating Customer an HashTable classes.
Krishna: Implementing and integrating RentalStore Class
Jabob: Implementing and integrating Genre,Movies,Drama,Classic,and Comedy Classes

Overall Debugging: Roman, Krishna, Jacob

Program description:
Works when it runs and No memopry leaks. The program starts out from the Main class which will create a rental store object and give it three inFile parameters. From these parameters it will read in the data and store it apropriately. The Movies are stored in catalog which is a Movie object. In movie there are three vectors that hold the three different genres of movie objects that are created, processed and added into their vecxtors respectively. The three classes Classic,Comedy,Drama all inherit from genre. The next file is the customer file which in RentalStore is read into a HashTable of Customer pointers. The hashtable processes the customer pointers and puts them where they belong in the hash table. It implements open hashing an thus there are no collisions. Finally transactions are put line by line into a queue and processed accordingly when the method process treansaction is called. Finally the program calls the display method and prints out all necessarry details such as customer information.
