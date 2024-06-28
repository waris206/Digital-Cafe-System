#include "color.h"

#include <iostream>
#include<windows.h>
// Function to mark text in bold red color
void markRed() {
    std::cout << "\033[1;31m";  // Set color to bold red
}

// Function to mark text in bold green color
void markGreen() {
    std::cout << "\033[1;32m";  // Set color to bold green
}

// Function to mark text in bold yellow color
void markYellow() {
    std::cout << "\033[1;33m";  // Set color to bold yellow
}

// Function to mark text in bold blue color
void markBlue() {
    std::cout << "\033[1;34m";  // Set color to bold blue
}

// Function to mark text in bold magenta color
void markMagenta() {
    std::cout << "\033[1;35m";  // Set color to bold magenta
}

// Function to mark text in bold cyan color
void markCyan() {
    std::cout << "\033[1;36m";  // Set color to bold cyan
}

// Function to reset text color
void resetColor() {
    std::cout << "\033[0m";  // Reset color to default
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printCentered(std::string text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int textWidth = text.length();
    int spaces = (screenWidth - textWidth) / 2;
    std::cout << std::string(spaces, ' ') << text;
}
 void show(){
     // Colors: 1 = Blue, 2 = Green, 3 = Cyan, 4 = Red, 5 = Magenta, 6 = Yellow, 7 = White
    int colors[] = {1, 2, 3, 4, 5, 6, 7};
    int numColors = sizeof(colors) / sizeof(colors[0]);

    std::string welcomeArt = 
    "\t\t\t\t\t\t\t   ___            \t\t\t\t          ___  \n"
    "\t\t\t\t\t\t\t  (o o)           \t\t\t\t         (o o) \n"
    "\t\t\t\t\t\t\t  ( V ) \t\tWelcome to CDS \t\t\t ( V )\n"
    "\t\t\t\t\t\t\t---m-m----------------------------------------------------m-m----\n";
    

    for (int i = 0; i < welcomeArt.length(); ++i) {
        if (welcomeArt[i] != '\n') {
            setColor(colors[i % numColors]); // Cycle through colors
            std::cout << welcomeArt[i];
        } else {
            std::cout << std::endl;
        }
        Sleep(20); // Pause for a moment (in milliseconds)
    }

    std::cout << std::endl;
    setColor(7); // Reset color to default
 }
// Function to mark text in bold red color


void showadmin(){
      int colors[] = {1, 2, 3, 4, 5, 6, 7};
    int numColors = sizeof(colors) / sizeof(colors[0]);

    std::string welcomeArt = 
        "\t\t\t\t\t ^ ^                      \n"
        "\t\t\t\t\t(O,O)                     \n"
        "\t\t\t\t\t(   )   Welcome ADMIN      \n"
        "\t\t\t\t\t-\"-\"----------------------\n";

    for (int i = 0; i < welcomeArt.length(); ++i) {
        if (welcomeArt[i] != '\n') {
            setColor(colors[i % numColors]); // Cycle through colors
            std::cout << welcomeArt[i];
        } else {
            std::cout << std::endl;
        }
        Sleep(15); // Pause for a moment (in milliseconds)
    }
}

void showemployee(){
     int colors[] = {1, 2, 3, 4, 5, 6, 7};
    int numColors = sizeof(colors) / sizeof(colors[0]);

    std::string welcomeArt = 
        "\t\t\t\t\t ^ ^                      \n"
        "\t\t\t\t\t(O,O)                     \n"
        "\t\t\t\t\t(   )   Welcome Employee    \n"
        "\t\t\t\t\t-\"-\"----------------------\n";

    for (int i = 0; i < welcomeArt.length(); ++i) {
        if (welcomeArt[i] != '\n') {
            setColor(colors[i % numColors]); // Cycle through colors
            std::cout << welcomeArt[i];
        } else {
            std::cout << std::endl;
        }
        Sleep(15); // Pause for a moment (in milliseconds)
    }
}
 void showstudent(){
     int colors[] = {1, 2, 3, 4, 5, 6, 7};
    int numColors = sizeof(colors) / sizeof(colors[0]);

    std::string welcomeArt = 
        "\t\t\t\t\t ^ ^                      \n"
        "\t\t\t\t\t(O,O)                     \n"
        "\t\t\t\t\t(   )   Welcome Student/staff    \n"
        "\t\t\t\t\t-\"-\"---------------------------\n";

    for (int i = 0; i < welcomeArt.length(); ++i) {
        if (welcomeArt[i] != '\n') {
            setColor(colors[i % numColors]); // Cycle through colors
            std::cout << welcomeArt[i];
        } else {
            std::cout << std::endl;
        }
        Sleep(15); // Pause for a moment (in milliseconds)
    }
}
 