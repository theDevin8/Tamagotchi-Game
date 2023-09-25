#ifndef MONKEY_H
#define MONKEY_H
#include "pet.h"

class Monkey : public Pet
{
public:
    Monkey();
    Monkey(string, string, string, string, int, int, int, int);
    ~Monkey();
    
    void petDescription();
    void playWithPet(char);
    void feedPet(char );
    void petSleeps(char );
    void trainPet(char );

    char loadMonkeyPlayOptions();
    char loadMonkeyFoodOptions();
    char loadMonkeyNapOptions();
    char loadMonkeyTrainOptions();

    string monkeyWeightofHunger();
    int monkeyofHunger();

    void setMonkeyFurColor(string _furColor){monkeyFurColor = _furColor;}
    void setMonekyEyeColor(string _eyeColor){monkeyEyeColor = _eyeColor;}
    void setMonkeyWeight(int _weight){monkeyWeight = _weight;}
    void setMonkeyHeight(int _height){monkeyHeight = _height;}
    void setMonkeySpeed(int _speed){monkeySpeed = _speed;}

    string getMonkeyFurColor(){return monkeyFurColor;}
    string getMonkeyEyeColor(){return monkeyEyeColor;}
    int getMonkeyWeight(){return monkeyWeight;}
    int getMonkeyHeight(){return monkeyHeight;}
    int getMonkeySpeed(){return monkeySpeed;}

private:
    string monkeyFurColor;
    string monkeyEyeColor;
    int monkeyWeight;
    int monkeyHeight;
    int monkeySpeed;

};

#endif