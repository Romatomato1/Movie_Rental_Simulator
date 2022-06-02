//
// Created by roman on 5/23/2022.
//

#include <sstream>
#include "Movies.h"
#include <iostream>
#include <array>
#include <vector>


Movies::Movies() {

 
}

Movies::Comedy getComedyMovie(string title, int yearReleased) {

       for (int i=0;i<MAX;i++){
           if (comedyVector[i].title==title && comedyVecctor[i].yearReleased==yearReleased){
               return comedyVector[i];
           }
       }

       return Comedy( 0,"" ,"", 0);
   }

   
Movies::Classic getClassicMovie(string majorActorReleaseDate){

       for (int i=0;i<MAX;i++){
           if (classicVector[i].majorActorReleaseDate==majorActorReleaseDate){
               return classicVector[i];
           }
       }

       return Classic( 0,"" ,"", "");
   }

Movies::Drama getDramaMovie(string title, string director){

        for (int i=0;i<MAX;i++){
           if (dramaVector[i].title==title && dramaVector[i].director==director){
               return dramaVector[i];
           }
       }

       return Drama( 0,"" ,"", "");
    }


 Movies::bool addMovie(string data) {

        stringstream stream(data);
        string movietype;

        stream >> movietype;

        if (movietype=="F"){

            vector<string> result;

            while(stream.good()){
                string substring;
                getline(stream, substring, ',');
                result.push_back(substring);
            }
            
            
            comedyVector.pushback(Comedy(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
            return true;
            
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
                    
                    
            classicVector.pushpack(Classic(stoi(result.at(0)),result.at(1),result.at(2),result.at(3)));
            return true;
                    

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
                    
                    
            dramaVector.pushback(Drama(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
            return true;

        }

        else {

            cout << "error not valid movie type" << endl;
            return false;

        }

    }


    Movies::string displayMovies(){
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


    Movies::bool isInStock(Genre movie){
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
  




