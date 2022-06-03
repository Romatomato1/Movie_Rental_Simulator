//
// Created by roman on 5/20/2022.
//

#include "Comedy.h"
#include <iostream>
#include <string>
using namespace std;

Comedy::Comedy(int stock, string director, string title, int releaseYear) :Genre(stock,director,title) {
    releaseYear=releaseYear;
    
}

int Comedy::getYearReleased(){
    return yearReleased;

}

string Comedy::display(){
       
      

        string retTitle = getTitle();
       string retStock = to_string(getStock());
       string retDirector= getDirector();
       string retYear = to_string(getYearReleased());

       return retTitle + retStock + retDirector + retYear;
       }

void setYearReleased(int releaseYear){
    releaseYear=releaseYear; 


}