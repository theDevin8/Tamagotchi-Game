#include "monkey.h"

Monkey::Monkey()
{
    monkeyFurColor = "Unknown";
    monkeyEyeColor = "Unknown";
    monkeyWeight = 0;
    monkeyHeight = 0;
    monkeySpeed = 0;
}

Monkey::Monkey(string _monkeyName, string _monkeyOrigin, string _furColor, string _eyeColor, int _monkeyAge, int height, int weight, int speed) : Pet(_monkeyName, _monkeyOrigin, _monkeyAge)
{
    monkeyFurColor = _furColor;
    monkeyEyeColor = _eyeColor;
    monkeyHeight = height;
    monkeyWeight = weight;
    monkeySpeed = speed;
}

void Monkey::petDescription()
{
    Pet::petDescription();
    cout << "Height: " << monkeyHeight <<
    "\nWeight: " << monkeyWeight <<
    "\nFur color: " << monkeyFurColor <<
    "\nEye color: " << monkeyEyeColor <<
    "\nSpeed: " << monkeySpeed << endl;
}
string Monkey::monkeyWeightofHunger()
{
    if(getMonkeyWeight() < 15)
    {
        return "Hunger: -5";
    }
    else if(getMonkeyWeight() >= 15 and getMonkeyWeight() <= 40)
    {
        return "Hunger: -10";
    }
    else if(getMonkeyWeight() > 40)
    {
        return "Hunger: -15";
    }

}

int Monkey::monkeyofHunger()
{
    if(getMonkeyWeight() < 15)
    {
        return 5;
    }
    else if(getMonkeyWeight() >= 15 and getMonkeyWeight() <= 40)
    {
        return 10;
    }
    else if(getMonkeyWeight() > 40)
    {
        return 15;
    }
}

char Monkey::loadMonkeyPlayOptions()
{
    char option;
    cout << "You selected to Play with your pet monkey " << getPetName() << ". Now select an option on what games you'll like to play with your pet...\n" <<
    "(a) Swing on monkey bars. Swinging on monkey bars would increase/decrease you pey monkey's status...\n" <<
    monkeyWeightofHunger() << "\nHappiness: +15" << "\nTiredness: -10" << "\nBored: +10" << "\n" << 

    "\n(b) Play with small toys. Playing with small toys would increase/decrease you pet monkey's status...\n" <<
    monkeyWeightofHunger() << "\nHappiness: +5" << "\nTiredness: -10" << "\nBored: +5" << "\n" <<

    "\n(c) Play with lard hard ball. Playing with large hard ball would increase/decrease you pet monkey's status...\n" <<
    monkeyWeightofHunger() << "\nHappiness: +10" << "\nTiredness: -5" << "\nBored: +5" << "\n" <<

    "\n(d) Bounce on moonwalk. Bouncing on moonwalk would increase/decrease your pet monkey's status...\n" <<
    monkeyWeightofHunger() << "\nHappiness: +10" << "\nTiredness: -10" << "\nBored: +10" << "\n" <<

    "\n(e) Choose an option other than playing with you pet...\n";
    cin >> option;
    return option;
}

void Monkey::playWithPet(char _option)
{
    if(_option == 'a')
    {
        cout << "You selected for your pet monkey " << getPetName() << " to play swing on monkey bars. You pet monkey is now going for a swing!" << endl;
        levelAbove(happyness, 15);
        levelBelowZero(sleepy, 10);
        levelAbove(bored, 10);
    }
    else if(_option == 'b')
    {
        cout << "You selected for your pet monkey " << getPetName() << " to play with his/her small toys. Goodluck trying to get them toys back!" << endl;
        levelAbove(happyness, 5);
        levelBelowZero(sleepy, 10);
        levelAbove(bored, 5);
    }
    else if(_option == 'c')
    {
        cout << "You selected for your pet monkey " << getPetName() << " to play wiht his/her large ball. Make sure he/she doesn't break anything around his/her surroundings!" << endl;
        levelAbove(happyness, 10);
        levelBelowZero(sleepy, 5);
        levelAbove(bored, 5);
    }
    else if(_option == 'd')
    {
        cout << "You selected for you pet monkey " << getPetName() << " to bounce on the moonwalk. Your pet monkey is going to jump to the moon!" << endl;
        levelAbove(happyness, 10);
        levelBelowZero(sleepy, 10);
        levelAbove(bored, 10);
    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    nextHour();
    levelBelowZero(hungry, monkeyofHunger());
    newPetLevel();
}

char Monkey::loadMonkeyFoodOptions()
{
    char option;
    cout << "You selected to feed your pet monkey " << getPetName() << ". Now select what you would like to feed you pet...\n" <<
    "(a) Bananas. Feeding " << getPetName() << " a bananas would increase/decrease your monkey's status...\n" <<
    "Hungry: +15\n" << "Happiness: +10\n" << "Tiredness: -10\n" << "Bored: -5" << "\n" <<

    "\n(b) Nuts. Feeding " << getPetName() << " nuts would increase/decrease your monkey's status...\n" <<
    "Hungry: +10\n" << "Happiness: +5\n" << "Tiredness: -5\n" << "Bored: -10" << "\n" <<

    "\n(c) Chicken(with no spices). Feeding " << getPetName() << " chicken would increase/decrease your monkey's status...\n" <<
    "Hungry: +15\n" << "Happiness: +10\n" << "Tiredness: -5\n" << "Bored: -5" << "\n" <<

    "\n(d) Yogurt. Feeding " << getPetName() << " yogurt would increase/decrese your monkey's satuts...\n" << 
    "Hungry: +5\n" << "Happiness: +5\n" << "Tiredness: -10\n" << "Bored: -10\n" <<

    "\n(e) Choose an option other than feeding your pet monkey " << getPetName() << endl;
    cin >> option;
    return option;
    
}

void Monkey::feedPet(char _option)
{
    if(_option == 'a')
    {
        cout << "You selected to feed your pet monkey " << getPetName() << " Bananas. Very stereotypical huh." << endl;
        levelAbove(hungry, 15);
        levelAbove(happyness, 10);
        levelBelowZero(sleepy, 10);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'b')
    {
        cout << "You selected to feed your pet monkey " << getPetName() << " Nuts. Awe nuts, time to feast on some nuts!" << endl;
        levelAbove(hungry, 10);
        levelAbove(happyness, 5);
        levelBelowZero(sleepy, 5);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'c')
    {
        cout << "You selected to feed your pet monkey " << getPetName() << " Chicken(with no spices). Now time to full up your monkey's belly!" << endl;
        levelAbove(hungry, 15);
        levelAbove(happyness,10);
        levelBelowZero(sleepy,5);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'd')
    {
        cout << "You selected to feed your pet monkey " << getPetName() << " Yogurt. Is the yogurt gluten free? Time to eat!" << endl;
        levelAbove(hungry, 5);
        levelAbove(happyness, 5);
        levelBelowZero(sleepy, 10);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    nextHour();
    newPetLevel();
}

char Monkey::loadMonkeyNapOptions()
{
    char option;
    cout << "You selected to put your pet monkey " << getPetName() << " to sleep. Now select where you would like your monkey to sleep at...\n"<<
    "(a) " << getPetName() << "'s cage. As " << getPetName() << " sleeps in his/her cage, it would increase/decrease your pet monkey's status...\n" <<
    "Tiredness: +15\n" << "Happieness: -5\n" << "Hunger: -5\n" << "Bored: -5\n" << "\n" <<
    
    "\n(b) Sleep on tree. As " << getPetName() << " sleeps on the tree, it would increase/decrease your pet monkey's status...\n" <<
    "Tiredness: +15\n" << "Happieness: +5\n" << "Hunger: -5\n" << "Bored: -5\n" << "\n" <<

    "\n(c) Hammock. As " << getPetName() << " sleeps on his/hers hammock, it would increase/decrease your pet monkey's status...\n" <<
    "Tiredness: +15\n" << "Happieness: +10\n" << "Hunger: -5\n" << "Bored: +0\n" << "\n" <<

    "\n(d) Sleep with owner. As " << getPetName() << " sleeps with pet owner, it would increase/decrease your pet monkey's status...\n" <<
    "Tiredness: +15\n" << "Happieness: +15\n" << "Hunger: -5\n" << "Bored: +0\n" << "\n" <<

    "\n(e) Choose an option other than putting your pet monkey " << getPetName() << " to sleep\n";
    
    cin >> option;
    return option;
}

void Monkey::petSleeps(char _option)
{
    if(_option =='a')
    {
        cout << "You selected your pet to sleep in its cage. Goodnight." << endl;
        levelBelowZero(happyness, 5);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'b')
    {
        cout << "You selected your pet to sleep on a tree. Goodnight." << endl;
        levelAbove(happyness, 5);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'c')
    {
        cout << "You selected your pet to sleep on hammock. Goodnight." << endl;
        levelAbove(happyness,10);
    }
    else if(_option == 'd')
    {
        cout << "You selected your pet to sleep on pet owner's bed. Goodnight." << endl;
        levelAbove(happyness, 15);
    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    nextHour();
    levelBelowZero(hungry, 5);
    levelAbove(sleepy, 15);
}

char Monkey::loadMonkeyTrainOptions()
{
    char option;
    cout << "You selected to train your pet monkey " << getPetName() << ". Now selected what you would like to train your pet monkey...\n" << 
    "(a) Retrieving dropped or out of reach object. Teaching your monkey " << getPetName() << " to retrieve an object would increase/decrease your pet monkey's status...\n" <<
    "Train: +15\n" << "Happiness: +5\n" << "Hunger: +5\n" << "Tiredness: -10\n" << "Bored: +10\n" << "\n" <<
    
    "\n(b) Stay on shoulder. Teaching your pet monkey " << getPetName() << " to stay and rest on your shoulder would increase/decrease your pet monkey's status...\n" <<
    "Train: +10\n" << "Happiness: +5\n" << "Hunger: +5\n" << "Tiredness: +5\n" << "Bored: -5\n" << "\n" <<

    "\n(c) Backflip. Teaching your pet monkey " << getPetName() << " to do a backflip would increase/decrease your pet monkey's status...\n" <<
    "Train: +15\n" << "Happiness: +10\n" << "Hunger: +10\n" << "Tiredness: -10\n" << "Bored: +5\n" << "\n" <<

    "\n(d) Balance on ball. Teach your pet monkey " << getPetName() << " to balance on top of a ball would increase/decrease your pet monkey's status...\n" <<
    "Train: +15\n" << "Happiness: -5\n" << "Hungry: +15\n" << "Tiredness: -10\n" << "Bored: -10\n" << "\n" <<

    "\n(e) Choose an option other than training your pet monkey " << getPetName() << endl;
    
    cin >> option;
    return option;
}

void Monkey::trainPet(char _option)
{
    if(_option == 'a')
    {
        cout << "You selected to train your pet monkey " << getPetName() << " on how to retrive an object. Your pet monkey deserves 2 treats." << endl;
        levelAbove(train, 15);
        levelAbove(happyness, 5);
        levelAbove(hungry, 10);
        levelAbove(bored, 10);
        levelBelowZero(sleepy, 10);
    }
    else if(_option == 'b')
    {
        cout << "You selected to train your pet monkey " << getPetName() << " on how to rest on shoulder. Your pet monkey deserves 1 treats." << endl;
        levelAbove(train, 10);
        levelAbove(happyness, 5);
        levelAbove(sleepy, 5);
        levelBelowZero(bored,5);
        levelAbove(hungry, 5);
    }
    else if(_option == 'c')
    {
        cout << "You selected to train your pet monkey " << getPetName() << " on how to do a backflip. Your pet monkey deserves 2 treats." << endl;
        levelAbove(train, 15);
        levelAbove(happyness, 10);
        levelAbove(hungry,10);
        levelBelowZero(sleepy, 10);
        levelAbove(bored, 5);
    }
    else if(_option == 'd')
    {
        cout << "You selected to train your pet monkey " << getPetName() << " on how to balance on a ball. Your pet monkey deserves 4 treats." << endl;
        levelAbove(train, 15);
        levelBelowZero(happyness,5);
        levelAbove(hungry, 15);
        levelBelowZero(sleepy, 10);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    nextHour();
}
Monkey::~Monkey(){};