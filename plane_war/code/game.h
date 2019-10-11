#ifndef _GAME_H_
#define _GAME_H_

#define ENEMY_NUM 8
#define BULLET_NUM 100

class Game {
private:
	int goal;
	int score;
	int enemyIsShooted;
public:
	int speed;
	Game();
	void movePlane(COORD p[], char dir);
	int planeShooted(Plane p, Enemy e[]);
	void enemyShooted(Enemy e[], Bullet b[]);
	void moveEnemy(Enemy e[]);
	void moveBullet(Bullet b[]);
	void clear(COORD arr[], int size);
	void pause();
	void play();
	void gameOver();
	void gameWin();
	void printScore();
};

#endif