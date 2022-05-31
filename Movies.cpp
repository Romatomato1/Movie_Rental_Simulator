//
// Created by roman on 5/23/2022.
//

#include <sstream>
#include "Movies.h"
#include <iostream>

  Movies() {
    comedyArray = array<<Comedy>,MAX>();
    classicArray = array<<Classic>,MAX>();
    dramaArray = array<<Drama>,MAX>();

  }


   Comedy getComedyMovie(string title, int yearReleased) {

       for (int i=0;i<MAX;i++){
           if (comedyArray[i].title==title && comedyArray[i].yearReleased==yearReleased){
               return comedyArray[i];
           }
       }

       return comedy( 0,"" ,"", 0);
   }

   
  Classic getClassicMovie(string majorActorReleaseDate){

       for (int i=0;i<MAX;i++){
           if (classicArray[i].majorActorReleaseDate==majorActorReleaseDate){
               return classicArray[i];
           }
       }

       return classic( 0,"" ,"", "");
   }

    Drama getDramaMovie(string title, string director){

        for (int i=0;i<MAX;i++){
           if (dramaArray[i].title==title && dramaArray[i].director==director){
               return dramaArray[i];
           }
       }

       return drama( 0,"" ,"", "");
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
                result.push_back(substring)
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


    string displayMovies(){
        
        for (int i=0;i<MAX;i++){
            cout << comedyArray[i] << " , ";
        }

        for (int k=0;i<MAX;i++){
            cout << dramaArray[i] << " , ";
        }


        for (int j=0;i<MAX;i++){
            cout << classicArray[i] << " , ";
        }




          }


    bool isInStock(Genre movie){

        
        
    }



        
    }




