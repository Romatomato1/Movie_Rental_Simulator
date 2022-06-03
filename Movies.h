// ------------------------------------------------ Movies.h ----------------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/23/2022
// 5/24/2022
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will contain all movie information in it. 
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------


#ifndef ASSIGNMENT_4_MOVIES_H
#define ASSIGNMENT_4_MOVIES_H

#include <string>
#include <vector>
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "Genre.h"

using namespace std;

class Movies {
public:
    
  //------------------------------------Movie-----------------------------------------------------------
  //The movie constructor will initialize all of the genre arrays.
  //@param - N/A.
  //@return - void.
  //----------------------------------------------------------------------------------------------------
  Movies();
  
  //------------------------------------getComedyMovie--------------------------------------------------
  //Retrieves a comedy movie from array based title and year released
  //@param title:Title of the Movie
  //@param yearReleased: the year that the comedy movie was released
  //@return - Returns a comedy movie object. 
  //----------------------------------------------------------------------------------------------------
  Comedy getComedyMovie(string title, int yearReleased);
  
  //------------------------------------getDramaMovie--------------------------------------------------
  //Retrieves a drama movie from array based title and director. 
  //@param title:Title of the Movie
  //@param Director: the director of the drama movie
  //@return - Returns a drama movie object. 
  //----------------------------------------------------------------------------------------------------
  Drama getDramaMovie(string title, string director);
  
  //------------------------------------getClassicMovie-------------------------------------------------
  //Retrieves a movie based on a major actor and releases data as one string as the formatting is easier
  //that way
  //@param majorActorReleaseDate: The major actor in the movie and the release data in the same string 
  //@return - Returns a drama movie object
  //----------------------------------------------------------------------------------------------------
  Classic getClassicMovie(string majorActorReleaseDate);
  
  //------------------------------------addMovie--------------------------------------------------------
  //Adds a movie to the appropriate array based on what type of movie it is
  //that way.
  //@param data: String containing all the information about the movie to be parsed and added 
  //@return bool- true if successful, false if it failed 
  //----------------------------------------------------------------------------------------------------
  bool addMovie(string data);
  
  //------------------------------------displayMovies---------------------------------------------------
  //Displays all the movies in precedent order
  //@param N/A
  //@return A formatted string containing all the movies in inventory in precedent order
  //----------------------------------------------------------------------------------------------------
  string displayMovies();
  
  //------------------------------------isInStock-------------------------------------------------------
  //Returns a bool based on if the specific movie is in stock. 
  //@param Genre object to be compared
  //@return Returns true if the movie is in stock, returns false if out of stock 
  //----------------------------------------------------------------------------------------------------
  bool isInStock(Genre movie);

    //Constant size
   static int const MAX = 101;
private:

  vector<Comedy> comedyVector;
  vector<Drama> dramaVector;
  vector<Classic> classicVector;




  
};


#endif //ASSIGNMENT_4_MOVIES_H
