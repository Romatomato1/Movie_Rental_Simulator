// ------------------------------------------------ Genre.h -------------------------------------------------------
- 
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/20/2022
// 5/23/2022 
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our Comedy movie type. It inherits from Genre.
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------


#ifndef ASSIGNMENT_4_COMEDY_H
#define ASSIGNMENT_4_COMEDY_H


class Comedy: public Genre {
public:
  //------------------------------------Comedy---------------------------------------------------------
  //Constructor for comedy class
  //@param stock - int that says how many copies of a movie that the movie has
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  Comedy(int stock,string director,string title,string releaseYear);
private:
  //Class Fields
  
  //the year the comedy movie was released
  int yearReleased;
};


#endif //ASSIGNMENT_4_COMEDY_H
