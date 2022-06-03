//
// Created by roman on 5/18/2022.
//
//
#include "Genre.h"


Genre::Genre(int stock,string director, string releaseYear){
    char movieType;
    stock=stock;
    director=director;
    title=title;
}

int Genre::getStock(){
    return stock;
}
string Genre::getDirector(){
    return director;

}

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
      stock=stock;
  }
    
  //------------------------------------setDirector---------------------------------------------------------
  //Sets the director of a movie to the passed in string
  //@param director- String that represents director
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  void Genre::setDirector(string director){
      director=director;
  }
    
  //------------------------------------setTitle---------------------------------------------------------
  //Sets the title of a movie to the passed in string
  //@param title- String that represents title
  //@return No return value
  //----------------------------------------------------------------------------------------------------
  void Genre::setTitle(string title){
    title=title;     
}