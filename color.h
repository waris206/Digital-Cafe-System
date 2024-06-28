#ifndef COLOR_H
#define COLOR_H
#include<string>
// Function declarations
extern void markRed();
extern void markGreen();
extern void markYellow();
extern void markBlue();
extern void markMagenta();
extern void markCyan();
extern void resetColor();


void setColor(int color);
void printCentered(std::string text);
void show();
void showadmin();
void showemployee();
void showstudent();
#endif // _H
