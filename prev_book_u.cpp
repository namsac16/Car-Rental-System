#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <conio.h>

using namespace std;

void check_previous(string user)
{
    system("cls");
    vector<vector<string>> data1;
    vector<string> data2;
    string details, uname, car, ddate, adate, fare;
    ifstream ifs("Booking.txt", ios :: in);
    while(getline(ifs, details))
    {
        data2.clear();
        stringstream ss(details);
        getline(ss, uname, '/');
        getline(ss, car, '/');
        getline(ss, ddate, '/');
        getline(ss, adate, '/');
        getline(ss, fare, '/');
        if(uname == user)
        {
            data2.push_back(uname);
            data2.push_back(car);
            data2.push_back(ddate);
            data2.push_back(adate);
            data2.push_back(fare);
            data1.push_back(data2);
        }
    }
    ifs.close();
    cout<<"USER : "<<user<<"\n";
    for(int j = 0; j<data1.size(); j++)
    {
        cout<<j+1<<"."<<"Car Booked: "<<data1[j][1]<<"\n";
        cout<<"  Departure Date: "<<data1[j][2]<<"\n  Arrival Date: "<<data1[j][3]<<"\n";
        cout<<"  Fare Generated: Rs. "<<data1[j][4]<<"\n";
    }
    getch();
}


/*int main()
{
    check_previous();
    return 0;
}*/