#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <conio.h>

using namespace std;

void book_car(string model)
{
    int i = 0;
    string details, name, company, num, mod, seats;
    char ch;
    vector<vector<string>> out;
    ifstream ifs("Cars.txt", ios :: in);
    cout<<"Cars Available for "<<model<<" are:\n";
    while(getline(ifs, details))
    {
        stringstream ss(details);
        getline(ss, company, '/');
        getline(ss, name, '/');
        getline(ss, num, '/');
        getline(ss, mod, '/');
        getline(ss, seats, '/');
        /*while(getline(ss, s, delim))
            out[i].push_back(s);
        i++;*/
        if(model == mod)
            cout<<company<<" "<<name<<"\n";
    }
    /*for(int j = 0; j<out.size(); j++)
    {
        for(int k = 0; k<out[j].size(); k++)
        {
            cout<<out[j][k]<<"\t";
        }
        cout<<"\n";
    }*/
    ifs.close();
    getch();
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