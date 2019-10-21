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
void insertKey(struct hash_table_entry **T,int k,int hashLength);

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

    //cout<<fileLength[0]<<endl;
    //convert the value of year to int
    yearCount = 0;
    int yearAsInt[numberOfYears];
    while(yearCount<numberOfYears)
    {
        yearAsInt[yearCount] = stoi(givenYear[yearCount]);
        yearCount++;
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
    int testcount;

    //creating hash
    
    struct hash_table_entry *hashPtr[sizeHashPrime];
    for(int pos=0;pos<sizeHashPrime;pos++)
    {   
        hashPtr[pos] = NULL;
    }
   
    
    
    
    struct annual_storms yearToStruct[numberOfYears]; //creating amount of annual storms for amount of years

    int hashPosition = 0;
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

                //hashing
                // struct hash_table_entry *newEntry = new hash_table_entry;
                // newEntry->event_id=num;
                // newEntry->year=yearNum;
                // newEntry->event_index=hashFunction(num,sizeHashPrime);
                // hashPtr[hashPosition]->event_id=num;
                // cout<<hashPtr[hashPosition]<<endl;
                // hashPosition++;
                //cout<<newEntry->event_id<<endl;
                //struct hash_table_entry **toInsert = &newEntry;
                //insertKey(toInsert,num,sizeHashPrime);


            }
        }
        yearToStruct[yearCount].events = stormEventArray;
        yearCount++; //go to next year
    }
    
    
 

    //fatalities length
    yearCount=0;
    int fileLengthFatal[numberOfYears];
    while(yearCount<numberOfYears)
    {
        string fileName = "fatalities-"+givenYear[yearCount]+".csv"; //set the file name equal to that year
        ifstream fin(fileName);//open file 
        string fileInput; //get input
        fileLengthFatal[yearCount] = 0; //set the file length equal to zero
        getline(fin,fileInput); //skip the first line
        while(getline(fin,fileInput)) //read the input
        {
            fileLengthFatal[yearCount]++; //increment the length
        }
        yearCount++; //go to next year
    }

    //fatalities length
    yearCount=0;
    while(yearCount<numberOfYears)
    {
        string fileName = "fatalities-"+givenYear[yearCount]+".csv"; //set the file name equal to that year
        ifstream fin(fileName);//open file 
        string fileInput; //get input
        int fatalFileCount = 0;
        struct fatality_event fatalEventArray[fileLengthFatal[yearCount]];
        getline(fin,fileInput); //skip the first line
        while(getline(fin,fileInput)) //read the input
        {
            stringstream readLine(fileInput);
            string fatalEvents[7];
            string readIn = "";
            for(int i=0;i<7;i++)
            {
                getline(readLine,readIn,',');
                fatalEvents[i] = readIn;
            }
            
            fatalEventArray[fatalFileCount].fatality_id = stoi(fatalEvents[0]);
            //cout<<fatalEventArray[fatalFileCount].fatality_id<<endl;

            fatalEventArray[fatalFileCount].event_id = stoi(fatalEvents[1]);
            //cout<<fatalEventArray[fatalFileCount].event_id<<endl;

            char fType;
            istringstream fChar(fatalEvents[2]);
            fChar >> fType;
            fatalEventArray[fatalFileCount].fatality_type = fType;
            //cout<<fatalEventArray[fatalFileCount].fatality_type<<endl;

            char fDate;
            istringstream fCharDate(fatalEvents[3]);
            fCharDate >> fDate;
            strcpy(fatalEventArray[fatalFileCount].fatality_date,fatalEvents[3].c_str());   
            //cout<<fatalEventArray[fatalFileCount].fatality_date<<endl;

            //cout<<fatalEvents[4]<<endl;
            int fAge;
            istringstream fIntAge(fatalEvents[4]);
            fIntAge >> fAge;
            fatalEventArray[fatalFileCount].fatality_age = fAge;
            //cout<<fatalEventArray[fatalFileCount].fatality_age<<endl;


            fatalFileCount++;
        }
        yearCount++; //go to next year
    }

 
}
void insertKey(struct hash_table_entry **T,int k,int hashLength)
{
    struct hash_table_entry *newNode = new struct hash_table_entry;
    newNode->event_id = k;

    int hashIndex = hashFunction(k,hashLength);
    struct hash_table_entry *head = T[hashIndex];
    if(head == NULL)
    {
        newNode->next=NULL;
    }
    else
    {
        newNode->next=head;
    }
    T[hashIndex] = newNode;
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

// int findEvent(struct hash_table_entry **T,int eventID,int hashSize)
// {
//     bool foundKey = false;
//     int hashIndex = hashFunction(eventID,hashSize);
//     struct hash_table_entry *currentPtr;
//     currentPtr = T[hashIndex];
//     while(currentPtr != NULL && !foundKey)
//     {
//         if(currentPtr->event_id==eventID)
//         {
//             foundKey=true;

//         }
//         else
//         {
//             currentPtr = currentPtr->next;
//         }
        
//     }

    
// }