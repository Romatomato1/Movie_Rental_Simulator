// ------------------------------------------------ Comedy.cpp ----------------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 5/23/2022 
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our Comedy movie type. It inherits from Genre.
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------


#include "Comedy.h"
#include <iostream>
#include <string>
using namespace std;

//------------------------------------Comedy---------------------------------------------------------
  //Constructor for comedy class
  //@param stock - int that says how many copies of a movie that the movie has
  //@param director - the director of the movie
  //@param title - title of the Movie
  //@param releaseYear - int year the movie was released
  //@return No return value
  //----------------------------------------------------------------------------------------------------
Comedy::Comedy(int stock, string director, string title, int releaseYear) :Genre(stock,director,title) {
    setYearReleased(releaseYear);
}

//------------------------------------getYearReleased-------------------------------------------------
  //Retrieves the year the movie was released
  //@param N/A
  //@return int year the movie was released
  //----------------------------------------------------------------------------------------------------
int Comedy::getYearReleased() const{
    return yearReleased;

}

//------------------------------------display---------------------------------------------------------
//Displays all fields in for this movie
//@param N/A
//@return A formatted string containing all the movies in inventory in precedent order
//----------------------------------------------------------------------------------------------------
string Comedy::display(){
       return getTitle() + " " + getDirector() +" "+ to_string(getYearReleased()) + " " + to_string(getStock());
}

  
//------------------------------------setYearReleased-------------------------------------------------
//Changes the year the movie was released
//@param int year the movie was released
//@return No release year
//----------------------------------------------------------------------------------------------------
void Comedy::setYearReleased(int releaseYear){
    yearReleased=releaseYear;


}