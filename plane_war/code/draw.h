#ifndef _DRAW_H_
#define _DRAW_H_

#define ENEMY_SIZE 5
#define PLANE_SIZE 7
#define BULLET_SIZE 2

typedef struct Frame  
{  
    COORD position[2];  
    int flag;  
}Frame;

class Draw {
public:
	void setPos(int i, int j);
	void hideCursor();
	void drawRow(int y, int x1, int x2, char ch);
	void drawCol(int x, int y1, int y2, char ch);
	void drawFrame(COORD a, COORD  b, char row, char col);
	void drawFrame(int x1, int y1, int x2, int y2, char row, char col);
	void drawFrame(Frame frame, char row, char col);

	int drawMenu();
	void drawPlaying();
};


class Plane {
private:
	
public:
	Plane();
	void drawPlane();
	COORD plane[PLANE_SIZE];
};

class Bullet {
private:
	
public:
	Bullet();
	void createBullet(COORD pos);
	void drawBullet();
	COORD bullet[BULLET_SIZE];
};

class Enemy {
private:
	
public:
	Enemy();
	COORD enemy[ENEMY_SIZE];
	void drawEnemy();
	void createEnemy(COORD arr[]);
	
};


#endif