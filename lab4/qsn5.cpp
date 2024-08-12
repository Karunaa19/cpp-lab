/* 5. class Inventory 
{
      private:
       int quant;              // number on hand
            int reorder;           // reorder quantity
            double price;               // price per unit
            char* descrip; // description of item
  public:
      Inventory (int q, int r, double p, char* d)
 {  // initialize data members }
            ~Inventory()
 { //release dynamically allocated memory}
            void print();
 };
 //
 // first derived class 
//
 class Auto : public Inventory 
{
        char * manufacturer;
  public:
      Auto (int q, int r, double p, char * d, char *  man) 
{ //initialize base and derive members }
 }
        ~Auto()
 {}
        void print();
 };
 //
 // Second derived class  
//
 class Transmission : public Inventory 
{
        char * vendor;
  public:
        Transmission (int q, int r, double p, char * d, char * ven)
 {}
 ~ Transmission (){}
        void print();
        };
 a. Write a main () function that creates an instance object of Auto called Car, which has the
 following initial data: there is a quantity of five(5) on inventory, and two(2) on reorder;
 the price per unit is $15,545.91, and the description is that of the car obtained from the
 Toyota. Initialize the object Car, and print out all its vital facts.
 
 b. A Transmission is purchased from Aztec Inc., and must be inventoried. There are 25 of
 them, with 10 more on reorder. Their price is $1789.98. Instantiate and initialize an
 object for Transmission, and provide the same information.*/
//hierarchical 
 #include <iostream>
#include <cstring>

using namespace std;

class Inventory 
{
private:
    int quant;          
    int reorder;         
    double price;       
    char* descrip;        

public:
    Inventory(int q, int r, double p, const char* d)
        : quant(q), reorder(r), price(p)
    {
        descrip = new char[strlen(d) + 1];
        strcpy(descrip, d);
    }

    virtual ~Inventory()
    {
        delete[] descrip;
    }

    virtual void print()
    {
        cout << "Quantity: " << quant << endl;
        cout << "Reorder Quantity: " << reorder << endl;
        cout << "Price per Unit: $" << price << endl;
        cout << "Description: " << descrip << endl;
    }
};

class Auto : public Inventory 
{
private:
    char* manufacturer;

public:
    Auto(int q, int r, double p, const char* d, const char* man)
        : Inventory(q, r, p, d)
    {
        manufacturer = new char[strlen(man) + 1];
        strcpy(manufacturer, man);
    }

    ~Auto()
    {
        delete[] manufacturer;
    }

    void print() override
    {
        Inventory::print();
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Transmission : public Inventory 
{
private:
    char* vendor;

public:
    Transmission(int q, int r, double p, const char* d, const char* ven)
        : Inventory(q, r, p, d)
    {
        vendor = new char[strlen(ven) + 1];
        strcpy(vendor, ven);
    }

    ~Transmission()
    {
        delete[] vendor;
    }

    void print() override
    {
        Inventory::print();
        cout << "Vendor: " << vendor << endl;
    }
};

int main()
{
    Auto Car(5, 2, 15545.91, "Toyota", "Toyota Inc.");
    Transmission trans(25, 10, 1789.98, "Transmission for car", "Aztec Inc.");

    cout << "Car details:" << endl;
    Car.print();

    cout << "\nTransmission details:" << endl;
    trans.print();

    return 0;
}

