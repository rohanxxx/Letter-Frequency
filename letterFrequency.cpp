//Name: Md Fazle Rabbi
//Professor Vincent Mierlak
//CISC 2000
//HW#4
//letterFrequency.cpp
//Date: 02/14/2020
//counts each letters count from the input file


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

//Global Constants
constexpr int ROW = 26;
constexpr int COLUMNS = 2;
constexpr int COLUMN1 = 0;
constexpr int COLUMN2 = 1;

//Global array
int storeChar[ROW][COLUMNS];

//takes input filestream object & 2D array as parameter
//reads all the character in the inputfile character & increments the count
//pre-conditon: input file successfully opened.
void countChar(ifstream &infile, int storeChar[ROW][COLUMNS]);

//reverse sort the 2D array(largest number first)
//implement sort by bubble sort algorithm
//two parameters: 2d array & size of the array
void reverseSort(int storeChar[ROW][COLUMNS], int size);

//displays the final sorted table of letter frequencies
//this function only displays the letter if it counts  greater than 0;
void display();

int main()
{   
    //declares the file stream object
    ifstream infile;

    //counts the each letters from the file
    countChar(infile, storeChar);
    //sorts the array based on highest count
    reverseSort(storeChar, ROW);
    //outputs the sorted letter frequency
    display();

    return 0;
}

//----------------------------------------------------------------------------
//--------------------------- Func Definition --------------------------------
//----------------------------------------------------------------------------

void countChar(ifstream &infile, int storeChar[ROW][COLUMNS])
{
    //variables
    string fileName;
   
    //prompts the user for file name
    cout <<"Please enter the input file name: ";
    cin >> fileName;
    
    //opens the file
    infile.open(fileName);
    
    //checks if the file is readable or not.
    if(infile.fail())
    {
        cout <<"File open failed for input file."<< endl;
        exit(1);
    }
    
    //closes the file
    infile.close();

    //variables
    int index = 0;
    int lowerCase = 96;
    int upperCase = 64;

    //stores the char count for each char to 2D array
    for(int i = 0; i < ROW; i++)
    {
        char readChar;
        int count = 0;

        lowerCase++;
        upperCase++;

        infile.open(fileName);
        
        while(infile.get(readChar))
        {
            if(readChar == static_cast<char>(lowerCase))
                count++;
            if(readChar == static_cast<char>(upperCase))
                count++;
        }
        
        infile.close();
        
        storeChar[index][COLUMN1] = lowerCase;
        storeChar[index][COLUMN2] = count;

        index++;
    }

    return;
}

void reverseSort(int storeChar[ROW][COLUMNS], int size)
{
    //bubble sort largest number moves towards the left
    for(int i = size-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(storeChar[j][COLUMN2] < storeChar[j+1][COLUMN2])
            {
                //variables
                int column1 = storeChar[j+1][COLUMN1];
                int column2 = storeChar[j+1][COLUMN2];
                
                //switches the whole column based on the char highest count
                storeChar[j+1][COLUMN2] = storeChar[j][COLUMN2];
                storeChar[j+1][COLUMN1] = storeChar[j][COLUMN1];
                
                storeChar[j][COLUMN1] = column1;
                storeChar[j][COLUMN2] = column2;
            }
        }
    }

    return;
}

void display()
{
   for(int i = 0; i < ROW; i++)
   {
       //checks if any letter count < 0 or not
       if(storeChar[i][COLUMN2] > 0)
       {
           char letter = static_cast<char>(storeChar[i][COLUMN1]);
           int count = storeChar[i][COLUMN2];
           cout << letter <<" "<< count << endl;
       }
   }
    return;
}

