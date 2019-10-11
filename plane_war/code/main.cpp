#include <iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
using namespace std;
#include "draw.h"
#include "game.h"




int main() {
	srand((int)time(0));    //Ëæ»úÖÖ×Ó  
	Draw draw;
	Game g;
	draw.hideCursor();
    int a = draw.drawMenu();
	g.speed = a;
	system("cls");  
	draw.drawPlaying();
	g.play();
//	game.speed = a;
//	system("pause");
//	cout<<game.speed<<endl;
}