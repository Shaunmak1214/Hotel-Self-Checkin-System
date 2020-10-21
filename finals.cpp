/******************************
Name : Mak Yen Wei
Id : 1181203334
Section : TC02
Title : Hotel
*****************************/

//including library
#include<iomanip>
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<regex>
#include<stdio.h> 
#include<stdlib.h> 

//namespace declaration
using namespace std;

//Declared Base Class
class Hotel {

    protected:
    string fileName, name, codeNumber, roomNumber;

    public:
    //default constructor
    Hotel() {}

    //virtual function declration
    virtual void roomChecking() {}

};

//Declared Derived Class
class roomCheck: public Hotel {

    private:
    string line, fileCode;
    int counter = 0;
    int codeNF = 1;
    int ignore;

    public:
    //constructor
    roomCheck() {

        //declaration of filename that we will use later on
        fileName = "rooms.txt";

    }

    //this function is to check whether the user had made a reservation or not
    void roomChecking() {

        cout << "\n===== Hotel Room Checking =====" << endl;

        cout << "Your Name :";
        //Clear system buffer 
        fflush(stdin);
        getline(cin, name);

        cout << "\n\nGood Day, " << name << endl;
        cout << "=========================" << endl;

        cout << "\n\n********************************************************************************************" << endl;
        cout << "* Please key in the (5-digit) code number we had sent earlier right after your reservation *" << endl;
        cout << "********************************************************************************************" << endl;

        cout << "Code Number :";
        getline(cin, codeNumber);

        ifstream fcheck;
        fcheck.open(fileName, ios::in);

            //Get line from file
            while(getline(fcheck, line)){

                //counter increment is to skip the first 3 lines of the txt file which is the header part
                if(counter++ > 2) {

                    //extract data from code column only
                    //string.substr function is used to extract specific data in line
                    //regex_replace is use to remove whitespace
                    fileCode = regex_replace(line.substr(1, 5),regex("\\s"),"");

                        //Comparison of input and the data found in file
                        if(fileCode == codeNumber) {

                            roomNumber = regex_replace(line.substr(7, 10),regex("\\s"),"");
                            cout << "\n\n****************************************" << endl;
                            cout << "Your room number will be : " << roomNumber << endl;
                            cout << "****************************************" << endl;
                            cout << "\nCheck In Successfull" << endl;
                            cout << "Have a nice day" << endl;
                            codeNF = 0;
            
                        }

                }

            }

            if(codeNF != 0){

                cout << "Code Not Found" << endl;

            }

        fcheck.close();

    }

};

class roomCount: public Hotel {

    //private data members declaration
    private:
    //Initialize of virtual function
    Hotel *roomChecking = new roomCheck;

    public:
    void roomCounting(int roomCount) {
 
        cout << "\n\nChecking for Room Number " << roomCount+1 << endl;
        //Calling of virtual function
        roomChecking -> roomChecking();

    }

};

int main() {

    int rooms;

    cout << "\n\n===============================================" << endl;
    cout << " WELCOME TO THE XXX HOTEL SELF CHECK-IN SYSTEM " << endl;
    cout << "===============================================" << endl;
    //Get user input
    cout << "\nHow many rooms you had reserved ?";
    cin >> rooms;

    //dynamic array allocation for Roomcount Object
    roomCount* rcount = new roomCount [rooms];

        if(rooms > 0) {

            for(int i = 0; i < rooms ; i ++){

                rcount[i].roomCounting(i);

            }

        }else {

            cout << "Input cannot be a negative number" << endl;
            cout << "Have a nice day" << endl;

            //Deleting of dynamic array allocation for Roomcount Object
            delete[] rcount;
            return 0;

        }

    //Deleting of dynamic array allocation for Roomcount Object
    delete[] rcount;
    return 0;

}