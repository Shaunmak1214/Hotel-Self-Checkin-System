/******************************
Name : Mak Yen Wei
Id : 1181203334
Section : TC01
Title : Hotel
*****************************/

#include<iomanip>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>

using namespace std;

//Declared Base Class
class Hotel {

    protected:
    string fileName;
    string name, codeNumber;

    public:


};

class roomCount: public Hotel {

    private:


    public:
    void roomCounting(int roomCount) {
 
        cout << "Checking for Room " << roomCount+1 << endl;

    }

};

class roomCheck: public Hotel {

    private:

    public:
    //constructor
    roomCheck() {

        //declaration of filename that we will use later on
        fileName = "rooms.txt";

    }

    //this function is to check whether the user had made a reservation or not
    void roomChecking() {

        cout << "===== Room Checking =====" << endl;

        cout << "Your Name :" << endl;
        getline(cin, name);

        cout << "Good Day, " << name << endl;
        cout << "=======================" << endl;

        cout << "Please key in the code number we had sent earlier right after your reservation" << endl;
        cout << "Code Number :" << endl;
        cin.ignore();
        getline(cin, codeNumber);



    }

};

int main() {

    Hotel h;
    int rooms;

    cout << "How many rooms you had reserved ?" << endl;
    cin >> rooms; 

    roomCount* rcount = new roomCount [rooms];

        if(rooms > 0) {

            for(int i = 0; i < rooms ; i ++){

                rcount[i].roomCounting(i);

            }

        }else {

            cout << "Input cannot be a negative number" << endl;
            cout << "Have a nice day" << endl;
            delete[] rcount;
            return 0;

        }

    delete[] rcount;
    return 0;

}