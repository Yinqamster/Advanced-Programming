#include<iostream>  
#include<windows.h>  
#include<conio.h>  
#include<time.h>  
#include<string>  
using namespace std;
#include "draw.h"

void Draw::setPos(int i, int j) {            //设置光标位置
	COORD pos={i, j};
	HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out, pos);
}

void Draw::hideCursor() {                    //隐藏光标  
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};   
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);  
}
 
void Draw::drawRow(int y, int x1, int x2, char ch) {         //把第y行，[x1, x2) 之间的坐标填充为 ch 
    setPos(x1,y);  
    for(int i = 0; i <= (x2-x1); i++)  
        cout<<ch;  
}

void Draw::drawCol(int x, int y1, int y2, char ch) {         //把第x列，[y1, y2] 之间的坐标填充为 ch 
    int y=y1;  
    while(y!=y2+1) {  
        setPos(x, y);  
        cout<<ch;  
        y++;  
    }  
}

//左上角坐标、右下角坐标、用row填充行、用col填充列  
void Draw::drawFrame(COORD a, COORD  b, char row, char col) {  
    drawRow(a.Y, a.X+1, b.X-1, row);  
    drawRow(b.Y, a.X+1, b.X-1, row);  
    drawCol(a.X, a.Y+1, b.Y-1, col);  
    drawCol(b.X, a.Y+1, b.Y-1, col);  
}  
  
void Draw::drawFrame(int x1, int y1, int x2, int y2, char row, char col) {
    COORD a={x1, y1};  
    COORD b={x2, y2};  
    drawFrame(a, b, row, col);  
}  
  
void Draw::drawFrame(Frame frame, char row, char col) {
    COORD a = frame.position[0];  
    COORD b = frame.position[1];  
    drawFrame(a, b, row, col);  
}

int Draw::drawMenu() {  
    setPos(65, 1);  
    cout<<"P l a n e  W a r";  
    drawRow(3, 0, 149, '-');  
    drawRow(5, 0, 149, '-');  
    setPos(60, 4);  
    cout<<(char)24<<"和"<<(char)25<<"选择， Enter确定";  
    setPos(60, 11);  
    cout<<"关卡1  难度系数："<<(char)3;  
    setPos(60, 13);  
    cout<<"关卡2  难度系数："<<(char)3<<(char)3;  
    drawRow(20, 0, 149, '-');  
    drawRow(22, 0, 149, '-');  
    int j=11;  
    setPos(57, j);  
    cout<<">>";  
  
    while(1)  {
		if( _kbhit() ) {     
            char x=_getch();  
            switch (x) {
			case 72 :  {     
				if( j == 13) {  
					setPos(57, j);  
					cout<<"　";  
					j = 11;  
					setPos(57, j);  
					cout<<">>";  
				}  
				break;  
			}  
            case 80 : {     
				if( j == 11 ) {  
					setPos(57, j);  
					cout<<"　";          
					j = 13;  
					setPos(57, j);  
					cout<<">>";  
				}  
				break;  
			}  
            case 13 : {     
                if (j == 11) return 1;  
                else return 2;  
            }  
            }  
        }  
    }  
}

void Draw::drawPlaying() {
	drawFrame(0, 0, 119, 39, '-', '|');//    draw map frame
    drawFrame(119, 0, 149, 6, '-', '|');//        draw goal frame
    drawFrame(119, 6, 149, 12, '-', '|');//        draw enemy is shooted frame
    drawFrame(119, 12, 149, 18, '-', '|');//   draw score frame
    drawFrame(119, 18, 149, 32, '-', '|');//  draw operate frame
	drawFrame(119, 32, 149, 39, '-', '|');
    setPos(122, 3);
    cout<<"目标：";
    setPos(122, 9);
    cout<<"已击落敌机：";
	setPos(122, 15);
	cout<<"得分：";
    setPos(122,21);
    cout<<"操作方式：";
    setPos(122,23);
    cout<<"  "<<(char)24<<","<<(char)25<<","<<(char)27<<","<<(char)26<<" 控制战机移动。";
	setPos(122,25);
	cout<<"  Space发射子弹。";
    setPos(122,27);
    cout<<"  p 暂停游戏。";
    setPos(122,29);
    cout<<"  e 退出游戏。";
}


Plane::Plane() {
	COORD init = {60, 36};
	plane[0].Y = init.Y;
	plane[6].Y = init.Y + 2;
	for (int i = 1; i < 6; i++) {
		plane[i].Y = init.Y + 1;
	}
	plane[0].X = plane[3].X = plane[6].X = init.X;
	plane[1].X = init.X - 2;
	plane[2].X = init.X - 1;
	plane[4].X = init.X + 1;
	plane[5].X = init.X + 2;
}

void Plane::drawPlane() {
	Draw draw;
	for (int i = 0; i < PLANE_SIZE; i++) {
		draw.setPos(plane[i].X, plane[i].Y);
		if (i == 0) {
			cout<<(char)65;
		}
		else if (i == 1) {
			cout<<(char)47;
		}
		else if (i == 5) {
			cout<<(char)92;
		}
		else if (i == 6) {
			cout<<(char)30;
		}
		else {
			cout<<(char)79;
		}
	}
//	cout<<endl<<endl;
}

Enemy::Enemy() {
	int x = rand()%114 + 3;
	COORD init = {x, 1};
	for (int i = 0; i < 3; i++) {
		enemy[i].X = init.X;
		enemy[i].Y = init.Y + i;
	}
	enemy[3].X = init.X - 1;
	enemy[3].Y = init.Y + 1;
	enemy[4].X = init.X + 1;
	enemy[4].Y = init.Y + 1;
}

void Enemy::createEnemy(COORD arr[]) {
	int x = rand()%114 + 3;
	COORD init = {x, 1};
	for (int i = 0; i < 3; i++) {
		arr[i].X = init.X;
		arr[i].Y = init.Y + i;
	}
	arr[3].X = init.X - 1;
	arr[3].Y = init.Y + 1;
	arr[4].X = init.X + 1;
	arr[4].Y = init.Y + 1;
}

void Enemy::drawEnemy() {
	Draw draw;
	for (int i = 0; i < ENEMY_SIZE; i++) {
		draw.setPos(enemy[i].X, enemy[i].Y);
		if (i == 0) {
			cout<<(char)31;
		}
		else if (i == 2) {
			cout<<"*";
		}
		else {
			cout<<"X";
		}
	}
//	cout<<endl;
}

Bullet::Bullet() {
	for (int i = 0; i < BULLET_SIZE; i++)
		bullet[i].X = -1;
}

void Bullet::createBullet(COORD pos) {
	bullet[1].X = bullet[0].X = pos.X;
	bullet[1].Y = pos.Y - 1;
	bullet[0].Y = pos.Y - 2;
}

void Bullet::drawBullet() {
	Draw draw;
	draw.setPos(bullet[0].X, bullet[0].Y);
	cout<<(char)30;
	draw.setPos(bullet[1].X, bullet[1].Y);
	cout<<(char)72;
}