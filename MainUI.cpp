#include "MAINUI.h"
#include<iostream>
using namespace std;

char MainUI :: inputChoice(){
    char choice ;
    cin >> choice;
    choice = toupper(choice);
    return choice;
}

void MainUI::DisplayMenu(){
    cout << "***********************************\n";
    cout << "Welcome to vole machine simulator\n";
    cout << "\n Please choose an option: \n \n";
    cout << "A- load a file program\n";
    cout << "B- Execute the program\n";
    cout << "C- Display the machine's state\n";
    cout << "D- Set a position to start from\n";
    cout << "E- Exit\n";
}

char MainUI ::DisplayandInputDriever(){
    char choice;
    DisplayMenu();
    choice = inputChoice();
    return choice;
}

string MainUI ::inputFileName(){
    string filename;
    cout << "Please enter the file name\n"; 
    cin >> ws;
    getline(cin, filename);
    return filename;
}

int MainUI :: InputCounterPosition(){
    int cp;
    cout << "Please enter a position to start from: ";
    cin >> cp;
    return cp;
}

void MainUI ::mainuiDriver(){
    char choice;
    do{
        choice = DisplayandInputDriever();
        if (choice == 'A'){
            string filename = inputFileName();
            machine.loadProgramFile(filename);
            if(machine.getloadedprogram()) cout << "File loaded successfully\n";
        }
        else if (choice == 'B'){
            if(!machine.executeProgram()) cout << "Please load a file to execute\n";
        }
        else if (choice == 'C'){
            machine.outputState();
        }
        else if ( choice == 'D'){
            int cp = InputCounterPosition();
        }
        else if(choice == 'E'){
            cout << "THANK YOU!!!";
            exit(0);
        }
        else if(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E') cout << "INVALID CHOICE!\n";
    }while(choice != 'E');
}