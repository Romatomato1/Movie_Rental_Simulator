//
// Created by roman on 5/23/2022.
//

#include <sstream>
#include "Movies.h"
#include <iostream>



Movies::Movies() {

}

Comedy Movies::getComedyMovie(string title, int yearReleased) {

       for (int i=0;i<MAX;i++){
           if (comedyMovie[i].getTitle()==title && comedyMovie[i].getYearReleased()==yearReleased){
               return comedyMovie[i];
           }
       }

       return Comedy( 0,"" ,"", 0);
   }

   
Classic Movies::getClassicMovie(string majorActorReleaseDate){

       for (int i=0;i<MAX;i++){
           if (classicMovie[i].getMajorActorReleaseDate()==majorActorReleaseDate){
               return classicMovie[i];
           }
       }

       return Classic( 0,"" ,"", "");
   }

Drama Movies::getDramaMovie(string title, string director){

        for (int i=0;i<MAX;i++){
           if (dramaMovie[i].getTitle()==title && dramaMovie[i].getDirector()==director){
               return dramaMovie[i];
           }
       }

       return Drama( 0,"" ,"", "");
    }

bool Movies::addMovie(string data) {

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
            
            
            comedyMovie.Add(Comedy(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
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
                getline(stream, substring, ',');
                result.push_back(substring);
                    }
                    
                    
            classicMovie.add(Classic(stoi(result.at(0)),result.at(1),result.at(2),result.at(3)));
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
                getline(stream, substring, ',');
                result.push_back(substring)
                    }
                    
                    
            dramaMovie.add(Drama(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
            return true;

        }

        else {

            cout << "error not valid movie type" << endl;
            return false;

        }

    }


    string Movies::displayMovies(){
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


    bool Movies::isInStock(Genre movie){
        if (movie.getTitle()==){

            for (int i=0;i<MAX;i++){

               if (comedyMovie[i].getTitle()==movie.getTitle() && comedyMovie[i].getDirector()==movie.getDirector()
               //&& comedyArray[i].getReleaseYear()==movie.getReleaseYear()

                ){

                   if (comedyMovie[i].getStock()>0){
                       return true; 
                   }

                   
               }

            }

            return false; 

        }

        else if (movie.getTitle()==drama.getTitle()) {
            
            for (int i=0;i<MAX;i++){
               if (dramaMovie[i].getTitle()==movie.getTitle() && dramaMovie[i].getDirector()==movie.getDirector()
               //&& dramaArray[i].getReleaseYear()==movie.getReleaseYear()
               ){
                   if (dramaMovie[i])
                   return true;
               }
            }

            return false; 
        }

        else {

            for (int i=0;i<MAX;i++){
               if (classicMovie[i].getTitle()==movie.getTitle() && classicMovie[i].getDirector()==movie.getDirector()
               //&& classicArray[i].getReleaseYear()==movie.getReleaseYear()
               ){
                   if (classicMovie[i].getStock()>0){
                       return true;
                   }
               }
            }

            return false;
        }

    }
  




