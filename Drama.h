// ------------------------------------------------ Drama.h -----------------------------------------------------------
- 
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 5/23/2022 
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our Drama movie type. It inherits from Genre.
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef ASSIGNMENT_4_DRAMA_H
#define ASSIGNMENT_4_DRAMA_H


class Drama:public Genre {
//------------------------------------Drama-------------------------------------------------------------
  //Constructor for drama class
  //@param stock - int that says how many copies of a movie that the movie has
  //@param director - the director of the movie
  //@param title - title of the Movie
  //@param releaseYear - int year the movie was released
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  Drama(int stock,string director,string title,int releaseYear);
  
  //------------------------------------getYearReleased-------------------------------------------------
  //Retrieves the year the movie was released
  //@param N/A
  //@return int year the movie was released
  //----------------------------------------------------------------------------------------------------
  int getYearReleased();
  
  //------------------------------------display---------------------------------------------------------
  //Displays all fields in for this movie
  //@param N/A
  //@return A formatted string containing all the movies in inventory in precedent order
  //----------------------------------------------------------------------------------------------------
  display();
private:
  //Class Fields
  
  //the year the drama movie was released
  int yearReleased;
  
  //------------------------------------setYearReleased-------------------------------------------------
  //Changes the year the movie was released
  //@param int year the movie was released
  //@return No release year
  //----------------------------------------------------------------------------------------------------
  void setYearReleased(int releaseYear);
};


#endif //ASSIGNMENT_4_DRAMA_H
