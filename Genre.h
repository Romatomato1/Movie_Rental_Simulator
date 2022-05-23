// ------------------------------------------------ Genre.h -------------------------------------------------------
- 
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/18/2022
// 5/23/2022 
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our movie types and genres. It is the parent class for Comedy,Classics, 
// and Drama
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------


#ifndef ASSIGNMENT_4_GENRE_H
#define ASSIGNMENT_4_GENRE_H

class Genre {
public:
  //------------------------------------Genre-----------------------------------------------------------
  //This constructor creates a genre of movie. It initializes the director, stock and year released. 
  //The constructor is also inherited from the subclasses.
  //@param stock- int that represents the number of the specific movie that is in inventory
  //@param director- the director of the film
  //@param release year- the release year of the film 
  //@return Has no return
  //----------------------------------------------------------------------------------------------------
  Genre(int stock, string director, string releaseYear);
  
  //------------------------------------getStock---------------------------------------------------------
  //Retrieves the int that represents the stock of a movie.
  //@param Has no parameters
  //@return returns an int representing the stock
  //----------------------------------------------------------------------------------------------------
  int getStock();
  
  //------------------------------------getDirector---------------------------------------------------------
  //This getterd retrieves the string that represents the director of a movie.
  //@param Has no parameters
  //@return returns a string that represents the director of a movie. 
  //----------------------------------------------------------------------------------------------------
  string getDirector();
  
  //------------------------------------getTitle---------------------------------------------------------
  //This getterd retrieves the string that represents the title of a movie.
  //@param Has no parameters
  //@return returns a string that represents the title of a movie. 
  //----------------------------------------------------------------------------------------------------
  string getTitle();
private:
  //Class Fields
  
  //The live stock of each movie
  int stock;
    
  //The director of the movie
  string director;
    
  //The title of the movie
  string title;
    
  //------------------------------------setStock---------------------------------------------------------
  //Sets the stock of a movie to the passed in int
  //@param stock - int that says how many copies of a movie that the movie has
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  void setStock(int stock);
    
  //------------------------------------setDirector---------------------------------------------------------
  //Sets the director of a movie to the passed in string
  //@param director- String that represents director
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  void setDirector(string director); 
    
  //------------------------------------setTitle---------------------------------------------------------
  //Sets the title of a movie to the passed in string
  //@param title- String that represents title
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  void setTitle(string title);   
};


#endif //ASSIGNMENT_4_GENRE_H
