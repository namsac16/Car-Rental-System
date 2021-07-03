#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <conio.h>

using namespace std;

void book_car(string model)
{
    int i = 0;
    vector<vector<string>> data1;
    vector<string> data2;
    string details, name, company, num, mod, seats;
    ifstream ifs("Cars.txt", ios :: in);
    while(getline(ifs, details))
    {
        data2.clear();
        stringstream ss(details);
        getline(ss, company, '/');
        getline(ss, name, '/');
        getline(ss, num, '/');
        getline(ss, mod, '/');
        getline(ss, seats, '/');
        if(mod == model)
        {
            data2.push_back(company);
            data2.push_back(name);
            data2.push_back(num);
            data2.push_back(mod);
            data2.push_back(seats);
            data1.push_back(data2);
        }
        //if(model == mod)
        //{
            //cout<<company<<" "<<name<<"\n";
            //for(int j = 0; j<5; j++)
            //    cout<<data2[j]<<" ";
            //cout<<endl;
            // data[i][0] = company;
            // data[i][1] = name;
            // data[i][2] = num;
            // data[i][3] = mod;
            // data[i][4] = seats;
            //cout<<i+1<<". "<<data[i][0]<<" "<<data[i][1]<<"\n";
            //i++;
        //}
    }
    ifs.close();
    
    int n;
    char ans = 'n';
    while(tolower(ans) != 'y')
    {
        system("cls");
        cout<<"Cars Available for "<<model<<" are:\n";
        for(int j = 0; j<data1.size(); j++)
            cout<<j+1<<". "<<data1[j][0]<<" "<<data1[j][1]<<"\n";
        cout<<"Select Car: ";
        cin>>n;
        n--;
        cout<<"Your Selected Model of Car is: ";
        cout<<data1[n][0]<<" "<<data1[n][1]<<"\n";
        cout<<"Details of Car:\n";
        cout<<"Car Number: "<<data1[n][2]<<"\t"<<"Seating Capacity: "<<data1[n][4]<<"\n";
        cout<<"Confirm Car?(y/n): ";
        cin>>ans;
    }

    int dd1, dd2, mm1, mm2, yy1, yy2;
    cout<<"Car Confirmed!!!\n";
    cout<<"Press any Key for Date Booking.";
    getch();
    while(1)
    {
        system("cls");
        cout<<"Enter Date on which Car is Required: (Seperated date by spaces as dd mm yyyy): "; 
        cin>>dd1>>mm1>>yy1;
        cout<<"Enter Date till which Car is Required: (Seperated date by spaces as dd mm yyyy): "; 
        cin>>dd2>>mm2>>yy2;
        if(yy2 > yy1)
            break;
        else if(yy2 == yy1)
        {
            if(mm2 > mm1)
                break;
            else if(mm2 == mm1)
            {
                if(dd2 > dd1)
                    break;
            }
        }
        cout<<"There is a Problem with dates. Please press any key to re-enter!";
        getch();
    }
}

/*int main()
{
    cout<<"Enter Model: ";
    string model;
    cin>>model;
    book_car(model);
    getch();
    return 0;
}*/