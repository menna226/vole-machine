// MainUI.h
#ifndef MAINUI_H
#define MAINUI_H

#include <string>
#include "Machine.h"

class MainUI {
private:
    Machine machine;                // The machine simulator containing CPU and Memory
    bool enterFileOrInstructions;    // Indicates if the program is loaded from a file or manually entered

public:
    // constructor
    // MainUI();
    // Displays the menu to the user
    void DisplayMenu();

    // Prompts user to enter the filename and loads instructions from it
    std::string inputFileName();

    // Prompts user to make a choice from the menu
    char inputChoice();

    char DisplayandInputDriever();

    void mainuiDriver();

    int InputCounterPosition();
};

#endif