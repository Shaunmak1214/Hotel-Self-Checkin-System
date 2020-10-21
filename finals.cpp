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

using namespace std;

class Hotel {

    public:

    Hotel(){



    }

};

int main() {

    string name;
    double roomId, rooms;

    Hotel h;

    cout << "How many rooms you had reserved ?" << endl;
    cin >> rooms;

        if(rooms > 0) {

            cout << "===== Room Checking for Today =====" << endl;

            cout << "Your Name :" << endl;
            getline(cin, name);

            cout << "Room Id :" << endl;
            cin >> roomId;

        }else{

            cout << "Room number cannot be less than 0" << endl;
            return 0;

        }

    return 0;

}