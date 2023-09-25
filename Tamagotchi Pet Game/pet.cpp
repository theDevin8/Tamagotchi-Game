#include "pet.h"

Pet::Pet()
{
    petName = "No name";
    petAge = 0;
    petOrigin = "No origin";
}
Pet::Pet(string _petName, string _petOrgin, int _petAge)
{
    petName = _petName;
    petOrigin = _petOrgin;
    petAge = _petAge;
}

void Pet::setRandomValues()
{
    srand(time(NULL));
    hungry = (rand() % 10) * 10;
    bored = (rand() % 10) * 10;
    happyness = (rand() % 10) * 10;
    sleepy = (rand() % 10) * 10;
    train = (rand() % 10) * 10;
    _time = 0;
}

void Pet::setpetName(string _name)
{
    petName = _name;
}

void Pet::setpetOrigin(string _orgin)
{
    petOrigin = _orgin;
}

void Pet::setpetAge(int age)
{
    petAge = age;
}

string Pet::getPetName()
{
    return petName;
}
string Pet::getPetOrgin()
{
    return petOrigin;
}
int Pet::getPetAge()
{
    return petAge;
}

string Pet::ascii(int level)
{
    if(level == 0)
    {
        return "▁▁▁▁▁▁▁▁▁▁▁▁▁ 0%";
    }
    else if(level == 5)
    {
        return "▅▁▁▁▁▁▁▁▁▁▁▁ 5%";
    }
    else if(level == 10)
    {
        return "█▁▁▁▁▁▁▁▁▁ 10%";
    }
    else if(level == 15)
    {
        return "█▆▁▁▁▁▁▁▁▁▁▁ 15%";
    }
    else if(level == 20)
    {
        return "██▁▁▁▁▁▁▁▁ 20%";
    }
    else if(level == 25)
    {
        return "███▁▁▁▁▁▁▁▁▁ 25%";
    }
    else if(level == 30)
    {
        return "███▁▁▁▁▁▁▁ 30%";
    }
    else if(level == 35)
    {
        return "████▂▁▁▁▁▁▁▁ 35%";
    }
    else if(level == 40)
    {
        return "████▁▁▁▁▁▁ 40%";
    }
    else if(level == 45)
    {
        return "████▄▁▁▁▁▁ 45%";
    }
    else if(level == 50)
    {
        return "██████▁▁▁▁▁▁ 50%";
    }
    else if(level == 55)
    {
        return "███████▂▁▁▁▁▁ 55%";
    }
    else if(level == 60)
    {
        return "██████▁▁▁▁ 60%";
    }
    else if(level == 65)
    {
        return "███████▂▁▁▁ 65%";
    }
    else if(level == 70)
    {
        return "███████▁▁▁ 70%";
    }
    else if(level == 75)
    {
        return "█████████▁▁▁ 75%";
    }
    else if(level == 80)
    {
        return "████████▁▁ 80%";
    }
    else if(level == 85)
    {
        return "███████████▁▁ 85%";
    }
    else if(level == 90)
    {
        return "█████████▁ 90%";
    }
    else if(level == 95)
    {
        return "██████████▄ 95%";
    }
    else if(level == 100)
    {
        return "██████████ 100%";
    }
}

string Pet::typeOfPet(char option)
{
    string kindOfPet;
    
    if(option == '1')
    {
        kindOfPet = "Dog";
    }
    else if(option == '2')
    {
        kindOfPet = "Snake";
    }
    else if(option == '3')
    {
        kindOfPet = "Tiger";
    }
    else if(option == '4')
    {
        kindOfPet = "Monkey";
    }
    return kindOfPet;
}

string Pet::petStatus()
{
     
    return "Your pet stauts is...\n Bored: " + ascii(bored) + "\n"
    + "\n Happieness: " + ascii(happyness) + "\n"
    + "\n Hunger: " + ascii(hungry) + "\n"
    + "\n Tiredness: " + ascii(sleepy) + "\n"
    + "\n Train: " + ascii(train) + "\n";
    
}

void Pet::loadPetOptions()
{
    cout << "Suggested options..." << endl;
    if(bored <= 40 or happyness <= 40)
    {
        if(bored <= 40 and happyness > 40)
        {
            cout << "Your pet is bored! If you like to play with your pet please select option 'a'" << endl;
        }
        else if(happyness <= 40 and bored > 40)
        {
            cout << "Your pet is sad! If you like to play with your pet please select option 'a'" << endl;
        }
        else
        {
            cout << "Your pet is bored and sad! If you like to play with your pet please select 'a'" << endl;
        }
    }
    if(hungry <= 40)
    {
        cout << "Your pet is hungry! If you like to feed your pet please select option 'c'" << endl;
    }
    if(sleepy <= 40)
    {
        cout << "Your pet is sleepy! If you like your pet to sleep please select 'b'" << endl;
    }
    if(train <= 30)
    {
        cout << "Your pet is not well trained! If you like to train your pet, please select 'd'" << endl;
    }
    cout << endl;
    cout << "Please select an option...\n";
    cout << "(a) Play with your pet.\n" << "(b) Take a nap with your pet.\n" << "(c) Feed your pet.\n" << "(d) Train your pet.\n" << "(e) Save and exit.\n";
}

void Pet::petDescription()
{
    cout << petName << "'s, description is: \n" << 
    "Breed: " << petOrigin <<
    "\nAge: " << petAge << endl;
}

void Pet::levelBelowZero(int &_levelValue, int addedValue)
{
   if(_levelValue - addedValue < 0)
   {
       _levelValue = 0;
   }
   else
   {
       _levelValue = _levelValue - addedValue;
   }
  
}

void Pet::levelAbove(int &_levelValue, int addedValue)
{
    if(_levelValue + addedValue > 100)
    {
        _levelValue = 100;
    }
    else
    {
        _levelValue = _levelValue + addedValue;
    }
    
}

void Pet::setPetOverAllLevel(int _overAll)
{
    petOverAllLevel = _overAll;
}

int Pet::getOverAllLevel()
{
    return petOverAllLevel;
}

void Pet::newPetLevel()
{
    if(hungry == 100 and sleepy == 100 and happyness == 100 and bored == 100 and train == 100)
    {
        petOverAllLevel++;
        cout << "Your pet has reached a new level. Pet level: " << petOverAllLevel << endl;
        hungry = 0;
        sleepy = 0;
        happyness = 0;
        bored = 0;
        train = 0; 
    }
}
void Pet::nextHour()
{
    _time++;
}