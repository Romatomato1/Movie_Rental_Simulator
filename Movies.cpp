//
// Created by roman on 5/23/2022.
//

#include <sstream>
#include "Movies.h"
#include <iostream>
#include <array>
#include <vector>
using namespace std; 


Movies::Movies() {

 
}

Comedy Movies::getComedyMovie(string title, int yearReleased) {

       for (int i=0;i<MAX;i++){
           if (comedyVector[i].getTitle()==title && comedyVector[i].getYearReleased()==yearReleased){
               return comedyVector[i];
           }
       }

       return Comedy( 0,"" ,"", 0);
   }

   
Classic Movies::getClassicMovie(string majorActorReleaseDate){

       for (int i=0;i<MAX;i++){
           //needs to be refined input string needs to be parsed
           if (classicVector[i].getActorFirstName()==majorActorReleaseDate){
               return classicVector[i];
           }
       }

       return Classic( 0,"" ,"", "");
   }

Drama Movies::getDramaMovie(string title, string director){

        for (int i=0;i<MAX;i++){
           if (dramaVector[i].getTitle()==title && dramaVector[i].getDirector==director){
               return dramaVector[i];
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
            
            
            comedyVector.push_back(Comedy(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
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
                    
                    
            classicVector.push_back(Classic(stoi(result.at(0)),result.at(1),result.at(2),result.at(3)));
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
                result.push_back(substring);
                    }
                    
                    
            dramaVector.push_back(Drama(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
            return true;

        }

        else {

            cout << "error not valid movie type" << endl;
            return false;

        }

    }


  string Movies::displayMovies(){
        string classicString;
        string dramaString;
        string comedyString;

        for (int i=0;i<comedyVector.size();i++){
            comedyString+comedyVector[i];
            
        }

         for (int i=0;i<dramaVector.size();i++){
            dramaString+dramaVector[i];
            
        }

        for (int i=0;i<classicString.size();i++){
            classicString+classicVector[i];
        
        }
       

       return comedyString + "/n" + dramaString + "\n" + classicString ; 
    }


   bool Movies::isInStock(Genre movie){
        
        if (movie.getMovieType()=='F'){

            for (int i=0;i<MAX;i++){

               if (comedyVector[i].gettitle()==movie.getTitle() && comedyVector[i].getDirector()==movie.getDirector() 
               //&& comedyArray[i].getReleaseYear()==movie.getReleaseYear()

                ){

                   if (comedyVector[i].getStock()>0){
                       return true; 
                   }

                   
               }

            }

            return false; 

        }

        else if (movie.getMovieType()=='D') {
            
            for (int i=0;i<MAX;i++){
               if (dramaVector[i].gettitle()==movie.getTitle() && dramaVector[i].getDirector()==movie.getDirector() 
               //&& dramaArray[i].getReleaseYear()==movie.getReleaseYear()
               ){
                   if (dramaVector[i])
                   return true;
               }
            }

            return false; 
        }

        else {

            for (int i=0;i<MAX;i++){
               if (classicVector[i].getTitle()==movie.getTitle() && classicVector[i].getDirector()==movie.getDirector()
               //&& classicArray[i].getReleaseYear()==movie.getReleaseYear()
               ){
                   if (classicVector[i].getStock()>0){
                       return true;
                   }
               }
            }

            return false;
        }

    }
  




