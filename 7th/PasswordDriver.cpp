/*File Name: PasswordDriver.cpp
 
 Author: Shane Fleming
 Date: 03/11/16
 Assignment Number: 4
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Password Manager, contains int main(), driver for Manager*/

#include <iostream>
#include "PasswordManager.h"
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;
PasswordManager manager;

string loadPasswordFromFile()
{
    fin.open("password.txt");
    string loadPass = "test";
    if (fin >> loadPass)
    {
        return loadPass;}
    else
    {
        loadPass = DEFAULT_PASSWORD;
        cout << endl << "No password.txt found, your default password "
        << "is \"abc123@@@\""<< endl;
        manager.setNewPassword(loadPass);
        loadPass = manager.encrypted;
        return loadPass;
    }
    
}

void savePasswordToFile(PasswordManager manager)
{
    fout.open("password.txt");
    fout << manager.getEncryptedPassword() << endl;
}

int main ()
{
    char userChoice;
    string tempPassword;
    
    manager.encrypted = loadPasswordFromFile();
    
    do
    {
        cout << endl << "Password Utilities:" << endl
        << "A. Change Password" << endl
        << "B. Validate Password" << endl
        << "C. Quit" << endl
        << "Enter your choice: ";
        
        cin >> userChoice;
        
        switch (userChoice)
        {
            case 'a':
            case 'A':
                cout << endl << "Must be at least 8 characters long and "
                << "contain at least three out of the following." << endl
                << "  - Uppercase letters" << endl
                << "  - Lowercase letters" << endl
                << "  - Numbers" << endl
                << "  - Symbols" << endl;
                
                cout << "Please Enter New Password: ";
                
                cin >> tempPassword;
                
                manager.setNewPassword(tempPassword);
                
                break;
                
            case 'b':
            case 'B':
                cout << "Please enter your password: ";
                cin >> tempPassword;
                
                if(manager.validatePassword(tempPassword))
                {
                    cout << endl << "Your password is correct." << endl;
                }
                else
                {
                    cout << endl << "Your password is incorrect." << endl;
                }
                
                break;
                
            case 'c':
            case 'C':
                savePasswordToFile(manager.getEncryptedPassword());
                cout << endl << "Terminating program..." << endl << endl;
                return 0;
                
            default:
                cout << "Error Please Try Again" << endl;
        }
    }
    while(true);
    
    return 0;
}