#include <iostream>
#include <fstream>

using namespace std;

class Car{
    protected:
        string model_name;
        string company;
        string car_number;
        string model;
        int seats;
    public:
        string ret_mod()
        {
            return model;
        }
        friend ofstream &operator <<(ofstream &ofs, Car &c);
};

ofstream &operator <<(ofstream &ofs, Car &c)
{
    ofs<<c.company<<"/"<<c.model_name<<"/"<<c.car_number<<"/"<<c.model<<"/"<<c.seats<<endl;
    return ofs;
}

class HatchBack : public Car{
    public:
        HatchBack(string name, string comp, string num, int s = 5)
        {
            model_name = name;
            company = comp;
            car_number = num;
            model = "Hatchback";
            seats = s;
        }
};

class Sedan : public Car{
    public:
        Sedan(string name, string comp, string num, int s = 5)
        {
            model_name = name;
            company = comp;
            car_number = num;
            model = "Sedan";
            seats = s;
        }
};

class MUV : public Car{
    public:
        MUV(string name, string comp, string num, int s = 8)
        {
            model_name = name;
            company = comp;
            car_number = num;
            model = "Multi-Utility Vehicle (MUV)";
            seats = s;
        }
};

class SUV : public Car{
    public:
        SUV(string name, string comp, string num, int s = 8)
        {
            model_name = name;
            company = comp;
            car_number = num;
            model = "Sports-Utility Vehicle (SUV)";
            seats = s;
        }
};

class Misc : public Car{
    public:
        Misc(string name, string comp, string num, string m, int s)
        {
            model_name = name;
            company = comp;
            car_number = num;
            model = m;
            seats = s;
        }
};

void input_car()
{
    int n, seats;
    char ch;
    string name, number, company;
    system("cls");
    cout<<"CAR ENTRY PORTAL\n";
    cout<<"1. Hatchback\n";
    cout<<"2. Sedan\n";
    cout<<"3. MUV\n";
    cout<<"4. SUV\n";
    cout<<"5. Traveller\n";
    cout<<"6. Bus\n";
    cout<<"Select Car Model:";
    cin>>n;
    system("cls");
    cin.ignore();
    cout<<"Enter Car's Company: ";
    getline(cin, company);
    cout<<"Enter Car's Model Name: ";
    getline(cin, name);
    cout<<"Enter Car's Number: ";
    getline(cin, number);
    cout<<"Enter Car's Seating Capacity: ";
    cin>>seats;
    ofstream out("Cars.txt", ios :: app);
    switch(n)
    {
        case 1:
        {
            HatchBack C(name, company, number, seats);
            out<<C;
            break;
        }
        case 2:
        {
            Sedan C(name, company, number, seats);
            out<<C;
            break;
        }
        case 3:
        {
            MUV C(name, company, number, seats);
            out<<C;
            break;
        }
        case 4:
        {
            SUV C(name, company, number, seats);
            out<<C;
            break;
        }
        case 5:
        {
            string model = "Traveller";
            Misc C(name, company, number, model, seats);
            out<<C;
            break;
        }
        case 6:
        {
            string model = "Bus";
            Misc C(name, company, number, model, seats);
            out<<C;
            break;
        }
    }
    out.close();
}

/*int main()
{
    char ch = 'y';
    while(ch == 'y')
    {
        system("cls");
        input_car();
        cout<<"Do you want to add more Cars(y/n): ";
        cin>>ch;
        ch = tolower(ch);
    }
    return 0;
}*/