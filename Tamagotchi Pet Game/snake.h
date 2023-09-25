#ifndef SNAKE_H
#define SNAKE_H

#include "pet.h"

class Snake :public Pet
{
public:
    Snake();
    Snake(string, string, string, string, int, int, int,int);
    ~Snake();

    void petDescription();
    void playWithPet(char);
    void feedPet(char );
    void petSleeps(char );
    void trainPet(char );

    char loadSnakePlayOptions();
    char loadSnakeFoodOptions();
    char loadSnakeNapOptions();
    char loadSnakeTrainOptions();

    void snakeSpeedofPlay(char );

    void setSnakeSkinColor(string );
    void setSnakeEyeColor(string );
    void setSnakeLength(int );
    void setSnakeHertz(int );
    void setSnakeSpeed(int );

    string getSnakeSkinColor();
    string getsnakeEyeColor();
    int getSnakeLength();
    int getSnakeHertz();
    int getSnakeSpeed();
    
private:
    string snakeSkinColor;
    string snakeEyeColor;
    int snakeLength;
    int snakeHertz;
    int snakeSpeed;
};

#endif