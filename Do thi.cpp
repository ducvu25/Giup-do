#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include "console.h"

using namespace std;

void TextColor (int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void clrscr(){
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
void gotoXY (int column, int line){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void VeOVuong(int x, int y, int r, int d, int k){
	int i, j;
	if (k != 1){ // Ve duong tren
		gotoXY(x, y); cout << char (201);
		gotoXY(x + d, y); cout << char (187);
	}
	if( k != 2){ // Ve duong duoi
			gotoXY(x, y + r); cout << char (200);
			gotoXY(x + d, y + r); cout << char (188);
	}
	for(i=x + 1; i<x+d; i++){
		if(k != 1)	{
			gotoXY(i, y); cout << char (205);
		}
		if( k != 2){
			gotoXY(i, y + r); cout << char (205);
		}
	}
	for(j=y+1; j<y+r; j++){
			if(k != 3){
				gotoXY(x, j); cout << char (186); // Ben trai
			}
			if(k != 4){
				gotoXY(x+d, j); cout << char (186); // Ben phai
			}
			}
}
void VeMap(int d){
	if(d == 2){
		VeOVuong(35, 14, 2, 55, 0);
		VeOVuong(135, 28, 2, 75, 0);
		VeOVuong(150, 35, 2, 45, 0);
		VeOVuong(20, 6, 33, 15, 0);
		VeOVuong(90, 0, 25, 10, 1);
		VeOVuong(50, 0, 7, 20, 1);
		VeOVuong(55, 25, 20, 20, 2);
		VeOVuong(120, 6, 33, 15, 0);
		VeOVuong(0, 0, 45, 210, 0);
		for(int i=5; i<12; i++){
			gotoXY(0, i); cout << " ";
		}
		gotoXY(0, 5); cout << "=";
		gotoXY(0, 11); cout << "=";
	}
}
int main(){
	getch();
	VeMap(2);
}
