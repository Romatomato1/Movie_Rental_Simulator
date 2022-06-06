//
// Created by roman on 5/20/2022.
//

#include "Classic.h"
#include <sstream>
#include <vector>

//------------------------------------Classic---------------------------------------------------------
  //Constructor for comedy class
  //@param stock - int that says how many copies of a movie that the movie has
  //@param director - the director of the movie
  //@param title - title of the Movie
  //@param majorActorReleaseDate - The major actor in the movie and the release data in the same string 
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  Classic::Classic(int stock,string director,string title, string majorActorReleaseDate) : Genre(stock,director,title){
      vector<string> result;
      stringstream ss(majorActorReleaseDate);
      string temp;

      while (ss>>temp)
      {

          result.push_back(temp);

      }

      actorFirstName = result[0];
      actorLastName = result[1];
      releaseDateMonth = stoi(result[2]);
      releaseDateYear = stoi(result[3]);

  }
  
  //------------------------------------getActorFirstName-----------------------------------------------
  //Retrieves the actor's first name
  //@param N/A
  //@return string representing actor's first name
  //----------------------------------------------------------------------------------------------------
  string Classic::getActorFirstName(){
      return actorFirstName;

  }
  
  //------------------------------------getActorLastName-----------------------------------------------
  //Retrieves the actor's last name
  //@param N/A
  //@return string representing actor's last name
  //----------------------------------------------------------------------------------------------------
  string Classic::getActorLastName(){
      return actorLastName;
  }
    
  //------------------------------------getReleaseDateMonth--------------------------------------------
  //Retrieves the month the movie was released
  //@param N/A
  //@return int representing the month the movie was released
  //----------------------------------------------------------------------------------------------------
  int Classic::getReleaseDateMonth(){
      return releaseDateMonth;
  }
    
  //------------------------------------getReleaseDateYear--------------------------------------------
  //Retrieves the year the movie was released
  //@param N/A
  //@return int representing the year the movie was released
  //----------------------------------------------------------------------------------------------------
  int Classic::getReleaseDateYear(){
      return releaseDateYear;
  }
  
  //------------------------------------display---------------------------------------------------------
  //Displays all fields in for this movie
  //@param N/A
  //@return A formatted string containing all the movies in inventory in precedent order
  //----------------------------------------------------------------------------------------------------
  string Classic::display(){
      
       string retTitle = getTitle();
       string retStock = to_string(getStock());
       string retDirector= getDirector();
       string retMonth = to_string(getReleaseDateMonth());
       string retYear = to_string(getReleaseDateYear());

       return retTitle + retStock + retDirector + retMonth + retYear;
  }