//
// Created by roman on 5/23/2022.
//

#include <sstream>
#include "Movies.h"
#include <iostream>
#include <vector>

using namespace std;

Movies() {

  //Array of comedy movies
  array<Comedy,MAX> comedyArray;
    
  //Array of drama movies
  array<Drama,MAX> dramaArray;
    
  //Array of classic movies
  array<Classic,MAX> classicArray;
}

   Comedy getComedyMovie(string title, int yearReleased) {

       for (int i=0;i<MAX;i++){
           if (comedyArray[i].title==title && comedyArray[i].yearReleased==yearReleased){
               return comedyArray[i];
           }
       }

       return Comedy( 0,"" ,"", 0);
   }

   
  Classic getClassicMovie(string majorActorReleaseDate){

       for (int i=0;i<MAX;i++){
           if (classicArray[i].majorActorReleaseDate==majorActorReleaseDate){
               return classicArray[i];
           }
       }

       return Classic( 0,"" ,"", "");
   }

    Drama getDramaMovie(string title, string director){

        for (int i=0;i<MAX;i++){
           if (dramaArray[i].title==title && dramaArray[i].director==director){
               return dramaArray[i];
           }
       }

       return Drama( 0,"" ,"", "");
    }


    bool addMovie(string data) {

        stringstream stream(data);
        string movietype;

        stream >> movietype;

        if (movietype=="F"){

            vector<string> result;

            while(stream.good()){
                string substring;
                getLine(stream, substring, ',');
                result.push_back(substring)
            }
            
            
            comedyArray.add(Comedy(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
            
            
        }

        else if (movietype=="C"){
            //  Classic(int stock,string director,string title, string majorActorReleaseData);
            stringstream stream(data);
            string movietype;

            stream >> movietype;

              

            vector<string> result;

            while(stream.good()){
                string substring;
                getLine(stream, substring, ',');
                result.push_back(substring);
                    }
                    
                    
            classicArray.add(Classic(stoi(result.at(0)),result.at(1),result.at(2),result.at(3)));
                    

        }

        else if (movietype=="D"){
            //  Drama(int stock,string director,string title,int releaseYear);

            stringstream stream(data);
            string movietype;

            stream >> movietype;

            vector<string> result;

            while(stream.good()){
                string substring;
                getLine(stream, substring, ',');
                result.push_back(substring)
                    }
                    
                    
            dramaArray.add(Drama(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));

        }

        else {

            cout << "error not valid movie type" << endl;
            return false;

        }

    }


    string displayMovies(){
        /*
        for (int i=0;i<MAX;i++){
            cout << comedyArray[i].title << " , ";
        }

        for (int k=0;i<MAX;i++){
            cout << dramaArray[i].title << " , ";
        }


        for (int j=0;i<MAX;i++){
            cout << classicArray[i].title << " , ";
        }
        */

       return " "; 
    }


    bool isInStock(Genre movie){
        if (movie.getTitle()==){

            for (int i=0;i<MAX;i++){

               if (comedyArray[i].gettitle()==movie.getTitle() && comedyArray[i].getDirector()==movie.getDirector() 
               //&& comedyArray[i].getReleaseYear()==movie.getReleaseYear()

                ){

                   if (comedyArray[i].getStock()>0){
                       return true; 
                   }

                   
               }

            }

            return false; 

        }

        else if (movie.getTitle()==drama.getTitle()) {
            
            for (int i=0;i<MAX;i++){
               if (dramaArray[i].gettitle()==movie.getTitle() && dramaArray[i].getDirector()==movie.getDirector() 
               //&& dramaArray[i].getReleaseYear()==movie.getReleaseYear()
               ){
                   if (dramaArray[i])
                   return true;
               }
            }

            return false; 
        }

        else {

            for (int i=0;i<MAX;i++){
               if (classicArray[i].getTitle()==movie.getTitle() && classicArray[i].getDirector()==movie.getDirector()
               //&& classicArray[i].getReleaseYear()==movie.getReleaseYear()
               ){
                   if (classicArray[i].getStock()>0){
                       return true;
                   }
               }
            }

            return false;
        }

    }
  




