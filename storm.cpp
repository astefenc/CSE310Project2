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
    
    struct storm_event stormEventArray[numberOfYears]; //create amount of arrays for input given
    yearCount = 0; //make count 0 again
    while(yearCount<numberOfYears) //while the count is less
    {
        string fileName = "details-"+givenYear[yearCount]+".csv"; //set the file name equal to that year
        ifstream fin(fileName);//open file 
        string fileInput; //get input
        getline(fin,fileInput); //skip the first line
        while(! fin.eof()) //read the input
        {
            fin>>stormEventArray[yearCount].event_id;
            fin>>stormEventArray[yearCount].state;
            fin>>stormEventArray[yearCount].year;
            fin>>stormEventArray[yearCount].month_name;
            fin>>stormEventArray[yearCount].event_type;
            fin>>stormEventArray[yearCount].cz_type;
            fin>>stormEventArray[yearCount].cz_name;
            fin>>stormEventArray[yearCount].injuries_direct;
            fin>>stormEventArray[yearCount].injuries_indirect;
            fin>>stormEventArray[yearCount].deaths_direct;
            fin>>stormEventArray[yearCount].deaths_indirect;
            fin>>stormEventArray[yearCount].damage_property;
            fin>>stormEventArray[yearCount].damage_crops;
            fin>>stormEventArray[yearCount].tor_f_scale;
        }
        yearCount++; //go to next year
    }

    cout<<stormEventArray[0].state[0]<<endl;

    
    
    
    
    
    
    

}