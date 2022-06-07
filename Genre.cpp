// ------------------------------------------------ Genre.cpp -----------------------------------------------------------
// Krishna Langille, Jacob Tea, Roman Gofman CSS 343 Section B 
// 5/18/2022
// 5/24/2022
// --------------------------------------------------------------------------------------------------------------------
// This is the class that will represent our movie types and genres. It is the parent class for Comedy,Classics, 
// and Drama
// -------------------------------------------------------------------------------------------------------------------- 
// No assumptions.
// --------------------------------------------------------------------------------------------------------------------
#include "Genre.h"

//------------------------------------Genre-----------------------------------------------------------
//This constructor creates a genre of movie. It initializes the director, stock and year released. 
//The constructor is also inherited from the subclasses.
//@param stock- int that represents the number of the specific movie that is in inventory
//@param director- the director of the film
//@param release year- the release year of the film 
//@return Has no return
//----------------------------------------------------------------------------------------------------
Genre::Genre(int stock,string director, string title){
    char movieType;
    setStock(stock);
    setDirector(director);
    setTitle(title);
}


//------------------------------------getStock---------------------------------------------------------
//Retrieves the int that represents the stock of a movie.
//@param Has no parameters
//@return returns an int representing the stock
//----------------------------------------------------------------------------------------------------
int Genre::getStock(){
    return stock;
}

//------------------------------------getDirector---------------------------------------------------------
//This getterd retrieves the string that represents the director of a movie.
//@param Has no parameters
//@return returns a string that represents the director of a movie. 
//---------------------------------------------------------------------------------------------------- 
string Genre::getDirector(){
    return director;

}

//------------------------------------getTitle---------------------------------------------------------
//This getterd retrieves the string that represents the title of a movie.
//@param Has no parameters
//@return returns a string that represents the title of a movie. 
//----------------------------------------------------------------------------------------------------
string Genre::getTitle(){
    return title;
}

char Genre::getMovieType(){
    return movieGenre;
}


//------------------------------------setStock---------------------------------------------------------
  //Sets the stock of a movie to the passed in int
  //@param stock - int that says how many copies of a movie that the movie has
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  void Genre::setStock(int stock){
      this->stock=stock;
  }
    
  //------------------------------------setDirector---------------------------------------------------------
  //Sets the director of a movie to the passed in string
  //@param director- String that represents director
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  void Genre::setDirector(string director){
      this->director=director;
  }
    
  //------------------------------------setTitle---------------------------------------------------------
  //Sets the title of a movie to the passed in string
  //@param title- String that represents title
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  void Genre::setTitle(string title){
    this->title=title;
}

//------------------------------------borrowMovie---------------------------------------------------------
//this decrements the stock of a movie by one
//@param Has no parameters
//@return nothing
//----------------------------------------------------------------------------------------------------
  void borrowMovie();
void Genre::borrowMovie() {
    stock--;
}

//------------------------------------returnMovie---------------------------------------------------------
//This increments the stock of a movie by 
//@param Has no parameters
//@return nothing
//----------------------------------------------------------------------------------------------------
void Genre::returnMovie() {
    stock++;
}

