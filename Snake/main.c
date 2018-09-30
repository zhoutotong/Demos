#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "chaintable.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define WIDTH  66
#define HEIGHT 34

ChainTable *snake;

void flashScreen(char(*screen)[WIDTH + 1], int x, int y)
{
	int i = 0, j = 0;
	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			if(i == 0 || i == HEIGHT - 1){
				screen[i][j] = '-';
			}else if(j == 0 || j == WIDTH - 1){
				screen[i][j] = '|';
			}else
			{
				screen[i][j] = ' ';
			}
		}
		screen[i][WIDTH] = '\n';
	}
	screen[HEIGHT - 1][WIDTH] = 0;

	Node *pnode = snake->head;
	i = 0;
	while(pnode->next != NULL)
	{
		x = pnode->data.x;
		y = pnode->data.y;
		pnode = pnode->next;
		if(i == 0){
			screen[y + 1][2 * x + 1] = 'A';//0x01;
		}else{
			screen[y + 1][2 * x + 1] = '[';//0x01;
		}
		i++;
		screen[y + 1][2 * x + 2] = ']';		
	}


}
void moveDown();
void moveLeft();
void moveRight();
void moveUp();
int main(int argc, char *argv[]) {
	char screen[HEIGHT][WIDTH + 1] = {};
    int i = 0, j = 0;
	Point pos;
	snake = initializationChainTable();

    for(i = 0; i < 8; i++)
	{
		pos.x = 10;
		pos.y = 10 - i;
		addDataToTail(snake, &pos);
	}

    for(i = 0; i < 8; i++)
	{
		moveDown();
		system("cls");
		flashScreen(screen, 10, 10);
		printf("%s", screen);
		sleep(2);
	}

	for(i = 0; i < 8; i++)
	{
		moveRight();
		system("cls");
		flashScreen(screen, 10, 10);
		printf("%s", screen);
		sleep(2);
	}

	for(i = 0; i < 8; i++)
	{
		moveUp();
		system("cls");
		flashScreen(screen, 10, 10);
		printf("%s", screen);
		sleep(2);
	}

	for(i = 0; i < 8; i++)
	{
		moveLeft();
		system("cls");
		flashScreen(screen, 10, 10);
		printf("%s", screen);
		sleep(2);
	}
    for(i = 0; i < 32; i++)
    {
    	for(j = 0; j < 32; j++)
    	{
    		system("cls");
    		flashScreen(screen, 10, 10);
    		printf("%s", screen);
    		sleep(20);
		}
	}
	return 0;
}

void moveDown()
{
	DataSet pos;
	Node *pnode = snake->head;
	pos.x = pnode->data.x;
	pos.y = pnode->data.y + 1;
	addDataToHead(snake, &pos);
	deleteNodeFromTail(snake);
}

void moveRight()
{
	DataSet pos;
	Node *pnode = snake->head;
	pos.x = pnode->data.x + 1;
	pos.y = pnode->data.y;
	addDataToHead(snake, &pos);
	deleteNodeFromTail(snake);
}

void moveLeft()
{
	DataSet pos;
	Node *pnode = snake->head;
	pos.x = pnode->data.x - 1;
	pos.y = pnode->data.y;
	addDataToHead(snake, &pos);
	deleteNodeFromTail(snake);
}

void moveUp()
{
	DataSet pos;
	Node *pnode = snake->head;
	pos.x = pnode->data.x;
	pos.y = pnode->data.y - 1;
	addDataToHead(snake, &pos);
	deleteNodeFromTail(snake);
}