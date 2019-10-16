//Alyssa Stefencavage
#include <string>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "defn.h"
#include <fstream>
using namespace std;

int main()
{
    string input;
    cin >> input;//reading in the line
    int numberOfYears = input[0] - '0'; //converting first to amount of years
   
    int yearCount = 0;
    string givenYear[numberOfYears]; //get the years into integers
    while(yearCount<numberOfYears) //grab the year values
    {
        cin>>givenYear[yearCount];
        yearCount++;
    }

    int fileLength[numberOfYears];//get the length of each file
    yearCount = 0; //make count 0 again
    while(yearCount<numberOfYears) //while the count is less
    {
        string fileName = "details-"+givenYear[yearCount]+".csv"; //set the file name equal to that year
        ifstream fin(fileName);//open file 
        string fileInput; //get input
        fileLength[yearCount] = 0; //set the file length equal to zero
        getline(fin,fileInput); //skip the first line
        while(getline(fin,fileInput)) //read the input
        {
            fileLength[yearCount]++; //increment the length
        }
        yearCount++; //go to next year
    }

    //convert the value of year to int
    yearCount = 0;
    int yearAsInt[numberOfYears];
    while(yearCount<numberOfYears)
    {
        yearAsInt[yearCount] = stoi(givenYear[yearCount]);
        yearCount++;
    }

    struct annual_storms yearToStruct[numberOfYears]; //creating amount of annual storms for amount of years
    
    yearCount = 0; //set count to zero
    while(yearCount<numberOfYears)
    {
        struct annual_storms newYear; //create an annual storm
        newYear.year=0; //set it to zero 
        newYear.events = NULL; //

        newYear.year = yearAsInt[yearCount];
    
        struct storm_event stormEventArray[fileLength[yearCount]];
        string fileName = "details-"+givenYear[yearCount]+".csv"; //set the file name equal to that year
        ifstream fin(fileName);//open file 
        string fileInput; //get input
        int lineCounter = 0;
        string comma = ""; //to skip the commas
        getline(fin,fileInput); //skip the first line
        while(getline(fin,fileInput)) //read the input
        {
            struct storm_event newEvent;
            fin>>newEvent.event_id;
            fin>>comma;
            fin>>newEvent.state;
            fin>>comma;
            fin>>newEvent.year;
            fin>>comma;
            fin>>newEvent.month_name;
            fin>>comma;
            fin>>newEvent.event_type;
            fin>>comma;
            fin>>newEvent.cz_type;
            fin>>comma;
            fin>>newEvent.cz_name;
            fin>>comma;
            fin>>newEvent.injuries_direct;
            fin>>comma;
            fin>>newEvent.injuries_indirect;
            fin>>comma;
            fin>>newEvent.damage_property;
            fin>>comma;
            fin>>newEvent.damage_crops;
            fin>>comma;
            fin>>newEvent.tor_f_scale;
            newEvent.f=NULL; //setting linked list to null
            stormEventArray[lineCounter] = newEvent;
        }
        
        newYear.events = stormEventArray;
        yearToStruct[yearCount] = newYear;
        yearCount++; //go to next year
    }

    


    
    
    
    
    
    
    

}