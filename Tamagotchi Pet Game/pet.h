#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pet
{
public:
    Pet();
    Pet(string, string, int);

    void setpetName(string );
    void setpetOrigin(string );
    void setpetAge(int );
    void setPetOverAllLevel(int );
    void setRandomValues();

    string getPetName();
    string getPetOrgin();
    int getPetAge();
    int getOverAllLevel();
    
    virtual void playWithPet(char ){};
    void nextHour();
    virtual void feedPet(char ){};
    virtual void petSleeps(char ){};
    virtual void trainPet(char ){};
    
    void petDescription();
    void levelBelowZero(int &, int);
    void levelAbove(int &, int);
    string petStatus();
    string ascii(int );
    string typeOfPet(char );
    
    void loadPetOptions();
    void newPetLevel();
    
    int getHungry(){return hungry;}
    int getSleepy(){return sleepy;}
    int getBored(){return bored;}
    int getHappieness(){return happyness;}
    int getTrain(){return train;}

    void setHungry(int _hungry){hungry = _hungry;}
    void setSleepy(int _sleepy){sleepy = _sleepy;}
    void setBored(int _bored){bored = _bored;}
    void setHappieness(int _happyness){happyness = _happyness;}
    void setTrain(int _train){train = _train;}
    
protected:
    int hungry;
    int sleepy;
    int bored;
    int happyness;
    int _time;
    int train;

private:
    string petName;
    string petOrigin;
    int petAge;
    int petOverAllLevel;
};

#endif