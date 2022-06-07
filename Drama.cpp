// ------------------------------------------------ Drama.h -----------------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 6/7/2022
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our Drama movie type. It inherits from Genre.
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------


#include "Drama.h"


//------------------------------------Drama-------------------------------------------------------------
  //Constructor for drama class
  //@param stock - int that says how many copies of a movie that the movie has
  //@param director - the director of the movie
  //@param title - title of the Movie
  //@param releaseYear - int year the movie was released
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  Drama::Drama(int stock,string director,string title,int releaseYear) : Genre(stock,director,title){
    setYearReleased(releaseYear);
  }
  
  //------------------------------------getYearReleased-------------------------------------------------
  //Retrieves the year the movie was released
  //@param N/A
  //@return int year the movie was released
  //----------------------------------------------------------------------------------------------------
  int Drama::getYearReleased(){
      return yearReleased;
  }
  
  //------------------------------------display---------------------------------------------------------
  //Displays all fields in for this movie
  //@param N/A
  //@return A formatted string containing all the movies in inventory in precedent order
  //----------------------------------------------------------------------------------------------------
  string Drama::display(){
      return getTitle() + " " + getDirector() +" "+ to_string(getYearReleased()) + " " + to_string(getStock());
  }

  
  //------------------------------------setYearReleased-------------------------------------------------
  //Changes the year the movie was released
  //@param int year the movie was released
  //@return No release year
  //----------------------------------------------------------------------------------------------------
  void Drama::setYearReleased(int releaseYear){
      yearReleased=releaseYear;
  }