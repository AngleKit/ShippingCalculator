// ShippingCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>;
#include <fstream>;
#include <iomanip>;
#include <string>;
#include <algorithm>;
#include "windows.h";

using namespace std;
const string OUTFILENAME = "Order.txt";

const int FRAGILE = 2;
const int OVER150 = 0;

// To USA
const int USLESS50 = 6;
const int US50TO100 = 9;
const int US100TO150 = 12;

// To Canada
const int CALESS50 = 8;
const int CA50TO100 = 12;
const int CA100TO150 = 15;

// To Australia
const int AULESS50 = 10;
const int AU50TO100 = 14;
const int AU100TO150 = 17;

int main()
{
    
    ofstream fOutStream;
    // open output file, check if opened
    fOutStream.open(OUTFILENAME);
    if (!fOutStream)
    {
        cout << "ERROR: file was unable to be open" << endl;
        return 1;
    }

    // Header
    cout << setw(58) << setfill('.') << "." << endl;
    string title = "ITCS 2530 - Programming Assignement for week #3 ";
    cout << title << endl;
    cout << setw(58) << "." << endl << endl;

    // initalize varaibles
    string Item;
    char AnsFragile;
    int ExtraPrice;
    float Ordertotal;
    float ShipPrices;
    string Dest;

    // prompt user
    string s0 = "Please enter the item name (no spaces)";
    cout << left  << s0 << setw(19) << right << "." << ":" << endl;
    cin >> Item;

    string s1 = "Is the item fragile? (y=yes/n=no)";
    cout << left << s1 << setw(24) << right << "." << ":" << endl;
    cin >> AnsFragile;
    

    // caluate fragile shipping cost
    if (AnsFragile == 'y')
        ExtraPrice = FRAGILE;
    else if (AnsFragile == 'n')
        ExtraPrice = 0;
    else
    {
        cout << endl;
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 1;
    }

    string s3 = "Please enter your total";
    cout << left << s3 << setw(34) << right << "." << ":" << endl;
    cin >> Ordertotal;

    string s4 = "Please enter destination. (usa/can/aus)";
    cout << left << s4 << setw(18) << right << "." << ":" << endl;
    cin >> Dest; 
    cout << endl;

    // caluate shipping cost
    if (Dest == "usa")
    {
        if (Ordertotal <= 50) // chart given did not give value for if order price is $50
            ShipPrices = USLESS50;
        else if (Ordertotal > 50 && Ordertotal <= 100)
            ShipPrices = US50TO100;
        else if (Ordertotal > 100 && Ordertotal <= 150)
            ShipPrices = US100TO150;
        else
            ShipPrices = OVER150;
    }
    else if (Dest == "can")
    {
        if (Ordertotal <= 50) // chart given did not give value for if order price is $50
            ShipPrices = CALESS50;
        else if (Ordertotal > 50 && Ordertotal <= 100)
            ShipPrices = CA50TO100;
        else if (Ordertotal > 100 && Ordertotal <= 150)
            ShipPrices = CA100TO150;
        else
            ShipPrices = OVER150;
    }
    else if (Dest == "aus")
    {
        if (Ordertotal <= 50) // chart given did not give value for if order price is $50
            ShipPrices = AULESS50;
        else if (Ordertotal > 50 && Ordertotal <= 100)
            ShipPrices = AU50TO100;
        else if (Ordertotal > 100 && Ordertotal <= 150)
            ShipPrices = AU100TO150;
        else
            ShipPrices = OVER150;
    }
    else
    {
        cout << endl;
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 1;
    }
         
    // Output statments and data
     string ans0 = "Your item is"; 
     transform(Item.begin(), Item.end(), Item.begin(), std::toupper);
     fOutStream << left << left << ans0 << ":" << Item << endl;  
     cout << left << ans0 << setw(30) << right << "." << Item << endl;   

     string ans1 = "Your shipping cost is";
     cout << fixed << setprecision(2);
     fOutStream << left << ans1 << ":" << "$" << ShipPrices + ExtraPrice << endl;
     cout << left << ans1 << setw(21) << right << "." << "$" << ShipPrices + ExtraPrice << endl;

     string ans2 = "You are shipping to";
     transform(Dest.begin(), Dest.end(), Dest.begin(), std::toupper);
     fOutStream << left << ans2 << ":" << Dest << endl;
     cout << left << ans2 << setw(23) << right << "." << Dest << endl; 

     string ans3 = "Your total shipping costs are";
     cout << fixed << setprecision(2);
     // enter data into file
     fOutStream << left << ans3 << ":" << "$" << Ordertotal + ShipPrices + ExtraPrice << endl;
     cout << left << ans3 << setw(13) << right << "." << "$" << Ordertotal + ShipPrices + ExtraPrice << endl << endl;

     cout << right << setw(42) << setfill('-') << "-" << "Thank You!" << endl << endl;
    system("pause");
    return 0;
}