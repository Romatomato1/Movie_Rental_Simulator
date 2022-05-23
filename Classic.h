// ------------------------------------------------ Classic.h -------------------------------------------------------
- 
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/23/2022
// 5/23/2022 
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will contain all movie information in it. 
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef ASSIGNMENT_4_CLASSIC_H
#define ASSIGNMENT_4_CLASSIC_H


class Classic: public Genre {
public:
  //------------------------------------Classic---------------------------------------------------------
  //Constructor for comedy class
  //@param stock - int that says how many copies of a movie that the movie has
  //@param director - the director of the movie
  //@param title - title of the Movie
  //@param majorActorReleaseDate - The major actor in the movie and the release data in the same string 
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  Classic(int stock,string director,string title, string majorActorReleaseData);
  
  //------------------------------------getActorFirstName-----------------------------------------------
  //Retrieves the actor's first name
  //@param N/A
  //@return string representing actor's first name
  //----------------------------------------------------------------------------------------------------
  string getActorFirstName();
  
  //------------------------------------getActorLastName-----------------------------------------------
  //Retrieves the actor's last name
  //@param N/A
  //@return string representing actor's last name
  //----------------------------------------------------------------------------------------------------
  string getActorLastName();
    
  //------------------------------------getReleaseDateMonth--------------------------------------------
  //Retrieves the month the movie was released
  //@param N/A
  //@return int representing the month the movie was released
  //----------------------------------------------------------------------------------------------------
  int getReleaseDateMonth();
    
  //------------------------------------getReleaseDateYear--------------------------------------------
  //Retrieves the year the movie was released
  //@param N/A
  //@return int representing the year the movie was released
  //----------------------------------------------------------------------------------------------------
  int getReleaseDateYear();
  
  //------------------------------------display---------------------------------------------------------
  //Displays all fields in for this movie
  //@param N/A
  //@return A formatted string containing all the movies in inventory in precedent order
  //----------------------------------------------------------------------------------------------------
  display();
  
private:
  //Class Fields
  
  //Actor's first name
  string actorFirstName;
    
  //Actor's last name
  string actorLastName;
    
  //The month the movie was released
  int releaseDateMonth;
    
  //The year the movie was released
  int releaseDateYear;
    
  //Helper Methods
  //------------------------------------setActorFirstName-----------------------------------------------
  //Sets the actor's first name
  //@param string representing actor's first name
  //@return N/A
  //----------------------------------------------------------------------------------------------------
  void setActorFirstName(string actorFirstName);
  
  //------------------------------------setActorLastName------------------------------------------------
  //Sets the actor's last name
  //@param string representing actor's last name
  //@return N/A
  //----------------------------------------------------------------------------------------------------
  void setActorLastName(string actorLastName);
    
  //------------------------------------setReleaseDateMonth--------------------------------------------
  //Sets the month the movie was released
  //@param int representing the month the movie was released
  //@return N/A
  //----------------------------------------------------------------------------------------------------
  void setReleaseDateMonth(int releaseDateMonth);
    
  //------------------------------------setReleaseDateYear--------------------------------------------
  //Sets the year the movie was released
  //@param int representing the year the movie was released
  //@return N/A
  //----------------------------------------------------------------------------------------------------
  void setReleaseDateYear(int releaseDateMonth);
};


#endif //ASSIGNMENT_4_CLASSIC_H
