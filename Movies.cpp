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

Movies::~Movies() {
    for(int i = 0; i < comedyVector.size(); i++){
        delete comedyVector[i];
    }
    for(int i = 0; i < dramaVector.size(); i++){
        delete dramaVector[i];
    }
    for(int i = 0; i < classicVector.size(); i++){
        delete classicVector[i];
    }
}

Comedy* Movies::getComedyMovie(string title, int yearReleased) {

       for (int i=0;i<comedyVector.size();i++){
           if (comedyVector[i]->getTitle()==title && comedyVector[i]->getYearReleased()==yearReleased){
               return comedyVector[i];
           }
       }

       return nullptr;
   }

   
Classic* Movies::getClassicMovie(string majorActorReleaseDate){
        vector<string> result;
        stringstream ss(majorActorReleaseDate);
        string temp;
        while (ss >> temp) {
            result.push_back(temp);
        }
       for (int i=0;i<classicVector.size();i++){
           //needs to be refined input string needs to be parsed
           if (classicVector[i]->getActorFirstName()==result[2]&& classicVector[i]->getActorLastName() == result[3]
                &&classicVector[i]->getReleaseDateMonth() ==stoi(result[0])&&classicVector[i]->getReleaseDateYear() ==stoi(result[1])){
               return classicVector[i];
           }
       }

       return nullptr;
   }

Drama* Movies::getDramaMovie(string title, string director){

        for (int i=0;i<dramaVector.size();i++){
           if (dramaVector[i]->getTitle()==title && dramaVector[i]->getDirector()==director){
               return dramaVector[i];
           }
        }

       return nullptr;
    }


bool Movies::addMovie(string data) {

        stringstream stream(data);
        string movietype;
        stream >> movietype;
    movietype = movietype.substr(0, movietype.find(','));

        if (movietype=="F"){

            vector<string> result;

            while(stream.good()){
                string substring;
                getline(stream, substring, ',');
                substring = substring.substr(1);
                result.push_back(substring);
            }
            
            
            comedyVector.push_back(new Comedy(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
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
                substring = substring.substr(1);
                result.push_back(substring);
                    }
                    
                    
            classicVector.push_back(new Classic(stoi(result.at(0)),result.at(1),result.at(2),result.at(3)));
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
                substring = substring.substr(1);
                result.push_back(substring);
                    }
                    
                    
            dramaVector.push_back(new Drama(stoi(result.at(0)),result.at(1),result.at(2),stoi(result.at(3))));
            return true;

        }

        else {

            cout << "error not valid movie type" << endl;
            return false;

        }

    }


  string Movies::displayMovies() const {
        string classicString;
        string dramaString;
        string comedyString;

        for (int i=0;i<comedyVector.size();i++){
            comedyString += comedyVector[i]->display() + "\n";
            
        }

         for (int i=0;i<dramaVector.size();i++){
             dramaString += dramaVector[i]->display() + "\n";
            
        }

        for (int i=0;i<classicVector.size();i++){
            classicString += classicVector[i]->display() + "\n";
        
        }
       

       return "Comedy Movies:\n" + comedyString + "\n" + "Drama Movies:\n" + dramaString + "\n" + "Classic Movies:\n" + classicString + "\n";
    }


   bool Movies::isInStock(Genre movie){
        
        if (movie.getMovieType()=='F'){

            for (int i=0;i<MAX;i++){

               if (comedyVector[i]->getTitle()==movie.getTitle() && comedyVector[i]->getDirector()==movie.getDirector()
               //&& comedyArray[i].getReleaseYear()==movie.getReleaseYear()

                ){

                   if (comedyVector[i]->getStock()>0){
                       return true; 
                   }

                   
               }

            }

            return false; 

        }

        else if (movie.getMovieType()=='D') {
            
            for (int i=0;i<MAX;i++){
               if (dramaVector[i]->getTitle()==movie.getTitle() && dramaVector[i]->getDirector()==movie.getDirector()
               //&& dramaArray[i].getReleaseYear()==movie.getReleaseYear()
               ){
                   if (dramaVector[i]->getStock()>0){
                   return true;
                }
            }

            return false; 
            }
        }

        else {

            for (int i=0;i<MAX;i++){
               if (classicVector[i]->getTitle()==movie.getTitle() && classicVector[i]->getDirector()==movie.getDirector()
               //&& classicArray[i].getReleaseYear()==movie.getReleaseYear()
               ){
                   if (classicVector[i]->getStock()>0){
                       return true;
                   }
               }
            }

            return false;
        }
        return false;

    }
   
  




