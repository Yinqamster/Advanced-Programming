#include<iostream>  
#include<windows.h>  
#include<conio.h>  
#include<time.h>  
#include<string>  
using namespace std;
#include "draw.h"
#include "game.h"

Game::Game() {
	speed = 0;
	goal = 0;
	score = 0;
	enemyIsShooted = 0;
}
/*
void Game::move(COORD arr[], int size, char dir) {
	if (size == PLANE_SIZE) {
		if (dir == 72) {
			if (arr[0].Y != 1) {
				for (int i = 0; i < size; i++) {
					arr[i].Y -= 1;
				}
			}
		}
		else if (dir == 80) {
			if (arr[6].Y != 38) {
				for (int i = 0; i < size; i++) {
					arr[i].Y += 1;
				}
			}
		}
		else if (dir == 77) {                     //right
			if (arr[5].X != 118) {
				for (int i = 0; i < size; i++) {
					arr[i].X += 1;
				}
			}
		}
		else if (dir == 75) {                     //left
			if (arr[1].X != 1) {
				for (int i = 0; i < size; i++) {
					arr[i].X -= 1;
				}
			}
		}
	}

	else if (size == ENEMY_SIZE) {
		int a = rand()%2;
		if (a == 0) {
			for (int i = 0; i < ENEMY_SIZE; i++) {
				if (arr[3].X != 1)
					arr[i].X -= 1;
				arr[i].Y += 1;
			}
		}
		else {
			for (int i = 0; i < ENEMY_SIZE; i++) {
				if (arr[4].X != 117)
					arr[i].X += 1;
				arr[i].Y += 1;
			}
		}
		if (arr[2].Y == 38) {
			Enemy e;
			e.createEnemy(arr);
		}
	}

	else if (size == BULLET_SIZE) {
		for (int i = 0; i < BULLET_SIZE; i++) {
			if (arr[i].Y != 1) {
				arr[i].Y--;
			}
			else {
				 clear(arr, BULLET_SIZE);
			}
		}
	}
}
*/
void Game::movePlane(COORD p[], char dir) {
	if (dir == 72) {
		if (p[0].Y != 1) {
			for (int i = 0; i < PLANE_SIZE; i++) {
				p[i].Y -= 1;
			}
		}
	}
	else if (dir == 80) {
		if (p[6].Y != 38) {
			for (int i = 0; i < PLANE_SIZE; i++) {
				p[i].Y += 1;
			}
		}
	}
	else if (dir == 77) {                     //right
		if (p[5].X != 118) {
			for (int i = 0; i < PLANE_SIZE; i++) {
				p[i].X += 2;
			}
		}
	}
	else if (dir == 75) {                     //left
		if (p[1].X != 2) {
			for (int i = 0; i < PLANE_SIZE; i++) {
				p[i].X -= 2;
			}
		}
	}
}

void Game::moveEnemy(Enemy e[]) {
	int a = rand()%3;
	for (int i = 0; i < ENEMY_NUM; i++){
		clear(e[i].enemy, ENEMY_SIZE);
		if (a == 0) {
			if (e[i].enemy[3].X != 2) {
				for (int j = 0; j < ENEMY_SIZE; j++) {
		//		if (e[i].enemy[3].X != 2)
					e[i].enemy[j].X -= 1;
					e[i].enemy[j].Y += 1;
				}
			}
			else {
				for (int j = 0; j < ENEMY_SIZE; j++) {
					e[i].enemy[j].Y += 1;
				}
			}
		}
		else if (a == 1){
			if (e[i].enemy[4].X != 117){
				for (int j = 0; j < ENEMY_SIZE; j++) {
		//		if (e[i].enemy[4].X != 117)
					e[i].enemy[j].X += 1;
					e[i].enemy[j].Y += 1;
				}
			}
			else {
				for (int j = 0; j < ENEMY_SIZE; j++) {
		//		if (e[i].enemy[4].X != 117)
					e[i].enemy[j].Y += 1;
				}
			}
		}
		else {
			for (int j = 0; j < ENEMY_SIZE; j++) {
				e[i].enemy[j].Y += 1;
			}
		}

		if (e[i].enemy[2].Y == 38) {
			Enemy newEnemy;
			newEnemy.createEnemy(e[i].enemy);
		}

		e[i].drawEnemy();
	}
}


void Game::moveBullet(Bullet b[]) {
	for (int i = 0; i < BULLET_NUM; i++) {
		if (b[i].bullet[0].X != -1) {
			clear(b[i].bullet, BULLET_SIZE);
			for (int j = 0; j < BULLET_SIZE; j++) {
				if (b[i].bullet[0].Y != 1) {
					b[i].bullet[j].Y-= 1;
				}
			}
			b[i].drawBullet();
			if (b[i].bullet[0].Y == 1) {
				clear(b[i].bullet, BULLET_SIZE);
				b[i].bullet[0].X = -1;
			}
		}
		
	}
}
void Game::clear(COORD arr[], int size) {
	Draw draw;
	for (int i = 0; i < size; i++) {
		draw.setPos(arr[i].X, arr[i].Y);
		cout<<" ";
	}
}

void Game::pause() {
	Draw draw;
    draw.setPos(122,35);  
    cout<<"暂 停 中 ... (按'p'继续)";  
    char c=_getch();  
    while(c!='p')  
        c=_getch();  
    draw.setPos(122,35);  
    cout<<"                         ";  
}

void Game::gameOver() {
	Draw draw;
	system("cls");
	char *over = "Game Over !";
	draw.drawFrame(64,14,86,24, '-', '|');
	draw.setPos(68, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	for (int i = 0; i < strlen(over); i++) {
		cout<<over[i];
		Sleep(100);
	}
	draw.setPos(68, 18);
	cout<<"目标：";
	cout<<goal;
	cout<<" 未达成";
	Sleep(100);
	draw.setPos(68, 20);
	cout<<"已击落敌机：";
	cout<<enemyIsShooted;
	Sleep(100);
	draw.setPos(68, 22);
	cout<<"得分：";
	cout<<score;
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
	Sleep(1000);
	draw.setPos(64,26);
	cout<<"继续？ y/n"<<endl;;
	char x = _getch();
	while (x != 'n' && x != 'y') {
		x = _getch();
	}

	if (x == 'n')
		exit(0);
	else if(x == 'y') {
		system("cls");
		Game newG;
		Draw newD;
		newD.hideCursor();
		int a = newD.drawMenu();
		newG.speed = a;
		system("cls");  
		newD.drawPlaying();
		newG.play();
	}
}

void Game::gameWin() {
	Draw draw;
	system("cls");
	char *over = "Congratulations !";
	draw.drawFrame(64,14,86,24, '-', '|');
	draw.setPos(67, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	for (int i = 0; i < strlen(over); i++) {
		cout<<over[i];
		Sleep(100);
	}
	draw.setPos(67, 18);
	cout<<"目标：";
	cout<<goal;
	cout<<" 已达成";
	Sleep(100);
	draw.setPos(67, 20);
	cout<<"已击落敌机：";
	cout<<enemyIsShooted;
	Sleep(100);
	draw.setPos(67, 22);
	cout<<"得分：";
	cout<<score;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
	Sleep(1000);
	draw.setPos(64,26);
	cout<<"继续？ y/n"<<endl;;
	char x = _getch();
	while (x != 'n' && x != 'y') {
		x = _getch();
	}

	if (x == 'n')
		exit(0);
	else if(x == 'y') {
		system("cls");
		Game newG;
		Draw newD;
		newD.hideCursor();
		int a = newD.drawMenu();
		newG.speed = a;
		system("cls");  
		newD.drawPlaying();
		newG.play();
	}
}

void Game::printScore() {
	Draw draw;
	goal = 20 * speed * speed;
	draw.setPos(128, 3);
	cout<<goal;
	draw.setPos(133, 9);
	cout<<enemyIsShooted;
	draw.setPos(128, 15);
	cout<<score;
}

int Game::planeShooted(Plane p, Enemy e[]) {
	Draw draw;
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (e[i].enemy[2].Y >= p.plane[0].Y && e[i].enemy[2].Y <= p.plane[6].Y ) {
			if ((e[i].enemy[3].X >= p.plane[1].X && e[i].enemy[3].X <= p.plane[5].X) || (e[i].enemy[4].X >= p.plane[1].X && e[i].enemy[4].X <= p.plane[5].X)) {
				draw.setPos(122,35);
				cout<<"坠毁";
				Sleep(1000);
				gameOver();
				return -1;
			}
		}
	}
	return 1;
}

void Game::enemyShooted(Enemy e[], Bullet b[]) {
	Draw draw;
	for (int k = 0; k < BULLET_NUM; k++) {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (b[k].bullet[0].Y <= e[i].enemy[2].Y && b[k].bullet[0].Y >= e[i].enemy[0].Y) {
				if (b[k].bullet[0].X >= e[i].enemy[3].X && b[k].bullet[0].X <= e[i].enemy[4].X) {
					for (int j = 0; j < ENEMY_SIZE; j++) {
						draw.setPos(e[i].enemy[j].X, e[i].enemy[j].Y);
						cout<<" ";
					}
					Enemy newE;
					newE.createEnemy(e[i].enemy);
					e[i].drawEnemy();
					enemyIsShooted++;
					score += 5;

					clear(b[k].bullet, BULLET_SIZE);
					b[k].bullet[0].X = -1;
				}
			}
		}
	}
}

void Game::play() {
	int count = 0;
	Plane p;
	Enemy e[ENEMY_NUM];
	p.drawPlane();
	for (int i = 0; i < ENEMY_NUM; i++) {
		e[i].drawEnemy();
	}
	Bullet b[100];
	while (1) {
		Sleep(10);
		count++;
		 if(_kbhit()) {
            char x = _getch();
			if (x == 72 || x == 80 || x == 75 || x == 77) {
				clear(p.plane, PLANE_SIZE);
				movePlane(p.plane, x);
				p.drawPlane();
	//			for (int i = 0; i < ENEMY_NUM; i++) {
					if (planeShooted(p, e) == -1)
						break;
	//			}
			}
			else if (x == 32) {
				for (int i = 0; i < 100; i++) {
					if (b[i].bullet[0].X == -1) {
						COORD pos = {p.plane[0].X, p.plane[0].Y};
						b[i].createBullet(pos);
						b[i].drawBullet();
						break;
					}
				}
			}
			else if (x == 'p') {
				pause();
			}
			else if (x == 'e') {
				gameOver();
				break;
			}
		 }
		
		 if (count % (20/speed) == 0) {
			 moveEnemy(e); 
		 }
		 
		 moveBullet(b);
		 enemyShooted(e, b);

		 printScore();

		 if (enemyIsShooted == goal)
			break;
	}

	if (enemyIsShooted == goal) {
		gameWin();
	}
}