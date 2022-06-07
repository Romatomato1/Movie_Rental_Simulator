//
// Created by roman on 5/20/2022.
//

#include "Comedy.h"
#include <iostream>
#include <string>
using namespace std;

Comedy::Comedy(int stock, string director, string title, int releaseYear) :Genre(stock,director,title) {
    setYearReleased(releaseYear);
}

int Comedy::getYearReleased() const{
    return yearReleased;

}

string Comedy::display(){
       return getTitle() + " " + getDirector() +" "+ to_string(getYearReleased()) + " " + to_string(getStock());
}

void Comedy::setYearReleased(int releaseYear){
    yearReleased=releaseYear;


}