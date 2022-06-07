//
// Created by roman on 5/23/2022.
//

#include <sstream>
#include "Movies.h"
#include <iostream>
#include <array>
#include <vector>
using namespace std;

//------------------------------------Movie-----------------------------------------------------------
//The movie constructor will initialize all of the genre arrays.
//@param - N/A.
//@return - void.
//----------------------------------------------------------------------------------------------------
Movies::Movies() {
 
}

//------------------------------------~Movie-----------------------------------------------------------
//The movie destructor that will delete all new instances of genres
//@param - N/A.
//@return - void.
//----------------------------------------------------------------------------------------------------
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

//------------------------------------getComedyMovie--------------------------------------------------
//Retrieves a comedy movie from array based title and year released
//@param title:Title of the Movie
//@param yearReleased: the year that the comedy movie was released
//@return - Returns a comedy movie object.
//----------------------------------------------------------------------------------------------------
Comedy* Movies::getComedyMovie(string title, int yearReleased) {

       for (int i=0;i<comedyVector.size();i++){
           if (comedyVector[i]->getTitle()==title && comedyVector[i]->getYearReleased()==yearReleased){
               return comedyVector[i];
           }
       }

       return nullptr;
   }

//------------------------------------getClassicMovie-------------------------------------------------
//Retrieves a movie based on a major actor and releases data as one string as the formatting is easier
//that way
//@param majorActorReleaseDate: The major actor in the movie and the release data in the same string
//@return - Returns a drama movie object
//----------------------------------------------------------------------------------------------------
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

//------------------------------------getDramaMovie--------------------------------------------------
//Retrieves a drama movie from array based title and director.
//@param title:Title of the Movie
//@param Director: the director of the drama movie
//@return - Returns a drama movie object.
//----------------------------------------------------------------------------------------------------
Drama* Movies::getDramaMovie(string title, string director){

        for (int i=0;i<dramaVector.size();i++){
           if (dramaVector[i]->getTitle()==title && dramaVector[i]->getDirector()==director){
               return dramaVector[i];
           }
        }

       return nullptr;
    }

//------------------------------------addMovie--------------------------------------------------------
//Adds a movie to the appropriate array based on what type of movie it is
//that way.
//@param data: String containing all the information about the movie to be parsed and added
//@return bool- true if successful, false if it failed
//----------------------------------------------------------------------------------------------------
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

//------------------------------------displayMovies---------------------------------------------------
//Displays all the movies in precedent order
//@param N/A
//@return A formatted string containing all the movies in inventory in precedent order
//----------------------------------------------------------------------------------------------------
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

   
  




