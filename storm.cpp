//Alyssa Stefencavage
#include <string>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "defn.h"
#include <fstream>
#include <sstream>
#include <string>
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
        //struct annual_storms newYear; //create an annual storm

        yearToStruct[yearCount].year=0; //set it to zero 
        yearToStruct[yearCount].events = NULL; //

        yearToStruct[yearCount].year = yearAsInt[yearCount];
    
        struct storm_event stormEventArray[fileLength[yearCount]];
        string fileName = "details-"+givenYear[yearCount]+".csv"; //set the file name equal to that year
        ifstream fin(fileName);//open file 
        string fileInput; //get input
        int lineCounter = 0;
        string comma = ""; //to skip the commas
        
        while(getline(fin,fileInput)) //read the input
        {
            if(lineCounter==0)
            {
                lineCounter++;

            }
            else
            {
                stringstream stringstr(fileInput);
                string tempA[14];
                string tempS="";

                for(int i=0;i<14;i++)
                {
                    getline(stringstr,tempS,',');

                    tempA[i]=tempS;
                }
                
                int num;
                istringstream iss (tempA[0]);
                iss >> num;
                stormEventArray[lineCounter-1].event_id = num;
                strcpy(stormEventArray[lineCounter-1].state,tempA[1].c_str());
                cout<<stormEventArray[lineCounter-1].event_id<<" "<<stormEventArray[lineCounter-1].state<<endl;
                lineCounter++;
            }
           

        }
        yearToStruct[yearCount].events = stormEventArray;
        //yearToStruct[yearCount] = newYear;
        yearCount++; //go to next year
    }
    
    
    


    
    
    
    
    
    
    

}