#ifndef DOG_H
#define DOG_H

#include "pet.h"

class Dog : public Pet
{
public:
    Dog();
    Dog(string, string, string, string, int, int, int);
    ~Dog();
    void setDogFurColor(string _furColor);
    void setDogEyeColor(string _eyeColor);
    void setDogHeight(int _height);
    void setDogWeight(int _weight);

    string getDogFurColor();
    string getDogEyeColor();
    int getDogHeight();
    int getDogWeight();
    
    void petDescription();
    void playWithPet(char);
    void feedPet(char );
    void petSleeps(char );
    void trainPet(char );
    
    string dogWeightofHunger();
    int dogWeightHunger();
    
    char loadDogPlayOptions();
    char loadDogFoodOptions(); 
    char loadDogNapOptions();
    char loadDogtrainOptions();


private:
    string furColor;
    string eyeColor;
    int height;
    int weight;

};

#endif