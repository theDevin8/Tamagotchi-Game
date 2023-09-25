#include "dog.h"

Dog::Dog()
{
    furColor = "Unknown";
    eyeColor = "Uknown";
    height = 0;
    weight = 0;
}
Dog::Dog(string _dogName, string _dogOrigin, string _furColor, string _eyeColor, int _dogAge, int _height, int _weight) : Pet(_dogName, _dogOrigin, _dogAge)
{
    furColor = _furColor;
    eyeColor = _eyeColor;
    height = _height;
    weight = _weight;
}

void Dog::setDogFurColor(string _furColor)
{
    furColor = _furColor;
}
void Dog::setDogEyeColor(string _eyeColor)
{
    eyeColor = _eyeColor;
}
void Dog::setDogHeight(int _height)
{
    height = _height;
}
void Dog::setDogWeight(int _weight)
{
    weight = _weight;
}

string Dog::getDogFurColor()
{
    return furColor;
}
string Dog::getDogEyeColor()
{
    return eyeColor;
}
int Dog::getDogHeight()
{
    return height;
}
int Dog::getDogWeight()
{
    return weight;
}

void Dog::petDescription()
{
    Pet::petDescription();
    cout << "Height: " << height <<
    "\nWeight: " << weight <<
    "\nFur color: " << furColor <<
    "\nEye color: " << eyeColor << endl;
}
string Dog::dogWeightofHunger()
{
    if(getDogWeight() < 35)
    {
        return "Hunger: -5";
    }
    else if(getDogWeight() >= 35 and getDogWeight() <= 65)
    {
        return "Hunger: -10";
    }
    else if(getDogWeight() > 65)
    {
        return "Hunger: -15";
    }
}
//playing with pet dog
char Dog::loadDogPlayOptions()
{
    char option;
    cout << "You selected the Play with your pet dog " << getPetName() << ". Now select an option on what games you'll like to play with your pet...\n" <<
    "(a) Chase the Prey. Playing Chase the Prey would increase/decrease your pet dog's status to...\n" <<
    dogWeightofHunger() << "\nHappiness: +15" << "\nTiredness: -10" << "\nBored: -10" << "\n" <<

    "\n(b) Fetch. Playing Fetch would increase/decrease your pet dog's status to..." <<
    dogWeightofHunger() << "\nHappiness: +10" << "\nTiredness: -15" << "\nBored: -5" << "\n" <<

    "\n(c) Tug of War. Playing Tug of War would increase/decrease your pet dog's status to...\n" <<
    dogWeightofHunger() << "\nHappiness: +5" << "\nTiredness: -10" << "\nBored: -5" << "\n" <<

    "\n(d) Hide and Seek. Playing Hide and Seek would increase/decrease your pet dog's status to...\n" <<
    dogWeightofHunger() << "\nHappiness: +10" << "\nTiredness: -5" << "\nBored: -10" << "\n" <<

    "\n(e) Choose an option other than playing with your pet...\n";
    cin >> option;
    return option;
}

int Dog::dogWeightHunger() 
{
    if(getDogWeight() < 35)
    {
        return 5;
    }
    else if(getDogWeight() >= 35 and getDogWeight() <= 65)
    {
        return 10;
    }
    else if(getDogWeight() > 65)
    {
        return 15;
    }

}
void Dog::playWithPet(char _option)
{
    if(_option == 'a')
    {
        cout << "You selected to play Chase the Prey. Good luck on trying to stop " << getPetName() << " from playing!" << endl;
        levelBelowZero(hungry, dogWeightHunger());
        levelAbove(happyness, 15);
        levelBelowZero(sleepy, 10);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'b')
    {
        cout << "You selected to play Fetch. Make sure you do not loose the freesbie." << endl;
        levelBelowZero(hungry, dogWeightHunger());
        levelAbove(happyness, 10);
        levelBelowZero(sleepy, 15);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'c')
    {
        cout << "You selected to play Tug of War. Pull as hard as you can!" << endl;
        levelBelowZero(hungry, dogWeightHunger());
        levelAbove(happyness, 5);
        levelBelowZero(sleepy, 10);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'd')
    {
        cout << "You selected to play Hind and Seek. Hopefully you do not loose " << getPetName() << endl;
        levelBelowZero(hungry, dogWeightHunger());
        levelAbove(happyness, 10);
        levelBelowZero(sleepy, 5);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'e')
    {
        loadPetOptions();//call funciton that reappears the origin 4 options
    }
    nextHour();
    newPetLevel();
}
//feeding pet dog
char Dog::loadDogFoodOptions()
{
    char option;
    cout << "You seleted to feed your pet dog " << getPetName() << ". Now select what you would like to feed your pet...\n" <<
    "(a) Chicken. Feeding " << getPetName() << " chicken would increase/decrease your dog status...\n" <<
    "Hunger: +15\n" << "Happiness: +5\n" << "Tiredness: -5\n" << "Bored: -10" << "\n" <<
    
    "\n(b) Turkey. Feeding " << getPetName() << " Turkey would increase your dog status..\n" <<
    "Hungry: +15\n" << "Happiness: +10\n" << "Tiredness: -5\n" << "Bored: -5" << "\n" <<

    "\n(c) Lean beef. Feeding " << getPetName() << " Lean beef would increase your dog status..\n" <<
    "Hungry: +15\n" << "Happiness: +5\n" << "Tiredness: -10\n" << "Bored: -5" << "\n" <<


    "\n(d) Fish. Feeding " << getPetName() << " Fish would increase your dog status...\n" <<
    "Hungry: +10\n" << "Happiness: +5\n" << "Tiredness: -5\n" << "Bored: -10" << "\n" <<


    "\n(e) Choose an option other than feeding your pet dog " << getPetName() << "\n";
    cin >> option;
    return option;
}

void Dog::feedPet(char _option)
{
    if(_option == 'a')
    {
        cout << "You selected to feed your pet dog " <<  getPetName() << " Chicken. It's chicken time baby!" << endl;
        levelAbove(hungry, 15);
        levelAbove(happyness, 5);
        levelBelowZero(sleepy, 5);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'b')
    {
        cout << "You selected to feed your pet dog " << getPetName() << " Turkey. It's gobble gobble time baby!" << endl;
        levelAbove(hungry, 15);
        levelAbove(happyness, 10);
        levelBelowZero(sleepy, 5);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'c')
    {
        cout << "You selected to feed your pet dog " << getPetName() << " Lean beef. This lean beef going to smack baby!" << endl;
        levelAbove(hungry, 15);
        levelAbove(happyness, 5);
        levelBelowZero(sleepy, 10);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'd')
    {
        cout << "You selected to feed your pet dog " << getPetName() << " Fish. Fish isn't the worst, but for sure isn't the best. Lets feast!" << endl;
        levelAbove(hungry, 10);
        levelAbove(happyness, 5);
        levelBelowZero(sleepy, 5);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'e')
    {
        loadPetOptions();//call funciton that reappears the origin 4 options
    }
    nextHour();
    newPetLevel();
}

char Dog::loadDogNapOptions()
{
    char option;
    cout << "You selected to put your pet dog " << getPetName() << " to sleep. Now select where you would like your dog to sleep at...\n" <<
    "(a) " << getPetName() << "'s bed. As " << getPetName() << " sleeps on his/her bed, it would increase/decrease your pet dog's status...\n" <<
    "Tiredness: +15\n" << "Happieness: +10\n" << "Hunger: -5\n" << "Bored: -5\n" << "\n" <<
    
    "\n(b) Sleep with pet owner. Sleeping with pet owner would increase/decrease your pet dog's status...\n" <<
    "Tiredness: +15\n" << "Happieness: +15\n" << "Hunger: -5\n" << "Bored: -5\n" << "\n" <<

    "\n(c) Outside. Leaving your pet dog to sleep outside would inccreases/decrease your pet dog's status...\n" <<
    "Tiredness: +15\n" << "Happieness: -5\n" << "Hunger: -5\n" << "Bored: -5\n" << "\n" <<

    "\n(d) Sofa. Letting your pet dog sleep on the sofa would increase/decrease your pet dog's status...\n"
    "Tiredness: +15\n" << "Happieness: +5\n" << "Hunger: -5\n" << "Bored: -5\n" << "\n" <<

    "\n(e) Choose an option other than putting your pet dog " << getPetName() << " to sleep\n";

    cin >> option;
    return option;
}

void Dog::petSleeps(char _option)
{
    if(_option == 'a')
    {
        cout << "You selected your pet to sleep on his/her bed. Goodnight." << endl;
        levelAbove(happyness, 10);
    }
    else if(_option == 'b')
    {
        cout << "You selected your pet to sleep on pet owner's bed. Goodnight." << endl;
        levelAbove(happyness, 15);
    }
    else if(_option == 'c')
    {
        cout << "You selected your pet to sleep outside. Goodnight." << endl;
        levelBelowZero(happyness, 5);
    }
    else if(_option == 'd')
    {
        cout << "Your selected your pet to sleep on the sofa. Goodnight." << endl;
        levelAbove(happyness, 5);
    }
    else if(_option == 'e')
    {
        loadPetOptions();//call function that reapperas the origin 4 options
    }
    nextHour();
    levelAbove(sleepy, 15);
    levelBelowZero(bored,5);
    levelBelowZero(hungry, 5);
    newPetLevel();
}

char Dog::loadDogtrainOptions()
{
    char option;
    cout << "You selected to train your pet dog " << getPetName() << ". Now select what you would like to train your pet dog...\n" <<
    "(a) Play Dead. Teaching your dog to play dead would increase/decrease your pet dog's status...\n" <<
    "Train: +15\n" << "Happiness: +5\n" << "Hunger: +5\n" << "Tiredness: +5\n" << "Bored: +10" << "\n" <<
    
    "\n(b) High Five. Teaching your dog to give a high five would increase/decrease your pet dog's status..\n" <<
    "Train: +10\n" << "Happiness: +5\n" << "Hunger: +5\n" << "Tiredness: -5\n" << "Bored: -5" << "\n" <<

    "\n(c) Roll over. Teaching your dog " << getPetName() << " to roll over would increease/decrease your pet dog's status...\n" <<
    "Train: +15\n" << "Happiness: +5\n" << "Hunger: +10\n" << "Tiredness: +5\n" << "Bored: +10" << "\n" <<

    "\n(d) Sit down. Teaching your pet dog " << getPetName() << " to sit down would increase/decrease your pet dog's status... \n" <<
    "Train: +10\n" << "Happiness: +5\n" << "Hunger: +5\n" << "Tiredness: -5\n" << "Bored: -5" << "\n" <<

    "\n(e) Choose an option other than training your pet dog " << getPetName() << endl;
    cin >> option;
    return option;
}

void Dog::trainPet(char _option)
{
    if(_option == 'a')
    {
        cout << "You selected to train your pet dog " << getPetName() << " how to play dead. Your pet dog deserves 2 treats. Now reach for the skies " << getPetName() << ".";
        levelAbove(bored, 10);
        levelAbove(happyness, 5);
        levelAbove(sleepy, 5);
        levelAbove(train, 15);
        levelAbove(hungry,5);
    }
    else if(_option == 'b')
    {
        cout << "You selected to train your pet dog " << getPetName() << " how to give a high five. You pet dog deserves 1 treat. Now up high " << getPetName() << ".";
        levelBelowZero(bored, 5);
        levelAbove(happyness, 5);
        levelAbove(hungry, 5);
        levelBelowZero(sleepy, 5);
        levelAbove(train, 10);
    }
    else if(_option == 'c')
    {
        cout << "You selected to train your pet dog " << getPetName() << " how to roll over. Your pet dog deserves 3 treats. Now roll over " << getPetName() << ".";
        levelAbove(bored, 10);
        levelAbove(happyness, 5);
        levelAbove(sleepy, 5);
        levelAbove(train, 15);
        levelAbove(hungry,10);
    }
    else if(_option == 'd')
    {
        cout << "You selected to train your pet dog " << getPetName() << " how to sit down. Your pet dog deserves 1 treat. Now sit " << getPetName() << ".";
        levelBelowZero(bored, 5);
        levelAbove(happyness, 5);
        levelAbove(hungry, 5);
        levelBelowZero(sleepy, 5);
        levelAbove(train, 10);

    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    nextHour();
    newPetLevel();
}
Dog::~Dog(){};