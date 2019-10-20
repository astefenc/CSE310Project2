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
#include "prime.cc"
using namespace std;

bool isPrime(int filesSize);
int findPrime(int sizeHash);
int hashFunction(int key,int hashsize);

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
                //cout<<stormEventArray[lineCounter-1].event_id<<" "<<stormEventArray[lineCounter-1].state<<endl;

                int yearNum;
                istringstream iss2 (tempA[2]);
                iss2 >> yearNum;
                stormEventArray[lineCounter-1].year = yearNum;
                //cout<<stormEventArray[lineCounter-1].year<<endl;

                strcpy(stormEventArray[lineCounter-1].month_name,tempA[3].c_str());
                //cout<<stormEventArray[lineCounter-1].month_name<<endl;

                strcpy(stormEventArray[lineCounter-1].event_type,tempA[4].c_str());
                //cout<<stormEventArray[lineCounter-1].event_type<<endl;

                char czType = tempA[5][0];
                stormEventArray[lineCounter-1].cz_type = czType;
                //cout<<stormEventArray[lineCounter-1].cz_type<<endl;

                strcpy(stormEventArray[lineCounter-1].cz_name,tempA[6].c_str());
                //cout<<stormEventArray[lineCounter-1].cz_type<<" "<<stormEventArray[lineCounter-1].cz_name<<endl;

                int injDirect;
                istringstream issD (tempA[7]);
                issD >> injDirect;
                stormEventArray[lineCounter-1].injuries_direct = injDirect;
                //cout<<stormEventArray[lineCounter-1].injuries_direct<<endl;

                int injInDirect;
                istringstream issI (tempA[8]);
                issI >> injInDirect;
                stormEventArray[lineCounter-1].injuries_indirect = injInDirect;
                //cout<<stormEventArray[lineCounter-1].injuries_indirect<<endl;

                int deathD;
                istringstream issDeath (tempA[9]);
                issDeath >> deathD;
                stormEventArray[lineCounter-1].deaths_direct = deathD;
                //cout<<stormEventArray[lineCounter-1].deaths_direct<<endl;

                int deathIn;
                istringstream issInDeath (tempA[10]);
                issInDeath >> deathIn;
                stormEventArray[lineCounter-1].deaths_indirect = deathIn;
                //cout<<stormEventArray[lineCounter-1].deaths_indirect<<endl;

                int propDamage;
                istringstream issDamage (tempA[11]);
                issDamage >> propDamage;
                stormEventArray[lineCounter-1].damage_property = propDamage;

                int cropDamage;
                istringstream issCrop (tempA[12]);
                issCrop >> cropDamage;
                stormEventArray[lineCounter-1].damage_property = cropDamage;

                strcpy(stormEventArray[lineCounter-1].tor_f_scale,tempA[13].c_str());
                //cout<<stormEventArray[lineCounter-1].tor_f_scale<<endl;

                stormEventArray[lineCounter-1].f = NULL;
                lineCounter++;
            }
        }
        yearToStruct[yearCount].events = stormEventArray;
        yearCount++; //go to next year
    }
    
    //create hash table size
    int sizeHash;
    yearCount = 0;
    while(yearCount<numberOfYears)
    {
        sizeHash = sizeHash + fileLength[yearCount];
        yearCount++;
    }
    
    int sizeHashPrime = findPrime(sizeHash);
    //cout<<sizeHash;

    //creating hash
    hash_table_entry *hashPtr[sizeHashPrime];
    for(int pos=0;pos<sizeHashPrime;pos++)
    {
        hashPtr[pos] = NULL;
    }

    //fatalities
    yearCount=0;
    
    
}
int hashFunction(int key,int hashsize)
{
    return key % hashsize;
}

int findPrime(int hashSize)
{
    hashSize = 2 * hashSize;
    bool isPrime = false;
    while(isPrime !=  true)
    {
        hashSize++;
        isPrime = TestForPrime(hashSize);
    }
    return hashSize;

}