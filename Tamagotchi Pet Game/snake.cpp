#include "snake.h"

Snake::Snake()
{
    snakeSkinColor = "Unknown";
    snakeEyeColor = "Unknown";
    snakeLength = 0;
    snakeHertz = 0;
    snakeSpeed = 0;
}

Snake::Snake(string _snakeName, string _snakeBreed, string _snakeColor, string _snakeEyeColor, int _snakeAge, int _snakeLength, int _snakeHertz,int _snakeSpeed) : Pet(_snakeName, _snakeBreed, _snakeAge)
{
    snakeSkinColor = _snakeColor;
    snakeEyeColor = _snakeEyeColor;
    snakeLength = _snakeLength;
    snakeHertz = _snakeHertz;
    snakeSpeed = _snakeSpeed;
}
Snake::~Snake(){};

void Snake::setSnakeSkinColor(string _skin)
{
    snakeSkinColor = _skin;
}
void Snake::setSnakeEyeColor(string _color)
{
    snakeEyeColor = _color;
}
void Snake::setSnakeLength(int _length)
{
    snakeLength = _length;
}
void Snake::setSnakeHertz(int _hertz)
{
    snakeHertz = _hertz;
}
void Snake::setSnakeSpeed(int _speed)
{
    snakeSpeed = _speed;
}

string Snake::getSnakeSkinColor()
{
    return snakeSkinColor;
}
string Snake::getsnakeEyeColor()
{
    return snakeEyeColor;
}
int Snake::getSnakeLength()
{
    return snakeLength;
}
int Snake::getSnakeHertz()
{
    return snakeHertz;
}
int Snake::getSnakeSpeed()
{
    return snakeSpeed;
}

void Snake::petDescription()
{
    Pet::petDescription();
    cout << "Length: " << snakeLength <<
    "\nHertz: " << snakeHertz <<
    "\nSpeed: " << snakeSpeed <<
    "\nEye color: " << snakeEyeColor <<
    "\nSkin color: " << snakeSkinColor << endl;
}

void Snake::snakeSpeedofPlay(char _option)
{
    if(_option == 'a') //chase mice
    {
        if(snakeSpeed < 5)
        {
            cout << "Hunger: +5\nHappiness: +5\nTiredness: -5\nBored: +10"<< endl;
            
        }
        else if(snakeSpeed <=5 and snakeSpeed >= 15)
        {
            cout << "Hunger: +5\nHappiness: +10\nTiredness: -10\nBored: +5"<< endl;
        }
        else if(snakeSpeed > 15)
        {
            cout << "Hunger: +10\nHappiness: +15\nTiredness: -5\nBored: +5"<< endl;
        }
    }
    else if(_option == 'b') //maze
    {
        if(snakeSpeed < 5)
        {
            cout << "Hunger: -5\nHappiness: -10\nTiredness: -5\nBored: -10"<< endl;
        }
        else if(snakeSpeed <=5 and snakeSpeed >= 15)
        {
            cout << "Hunger: -10\nHappiness: -5\nTiredness: -10\nBored: -5" << endl;
        }
        else if(snakeSpeed > 15)
        {
            cout << "Hunger: -15\nHappiness: +5\nTiredness: +5\nBored: +5" << endl;;
        }
    }
    else if(_option == 'c') //swim
    {
        if(snakeSpeed < 5)
        {
            cout << "Hunger: -10\nHappiness: +5\nTiredness: -5\nBored: +10" << endl;;
        }
        else if(snakeSpeed <=5 and snakeSpeed >= 15)
        {
            cout << "Hunger: -5\nHappiness: +10\nTiredness: -5\nBored: +15" << endl;;
        }
        else if(snakeSpeed > 15)
        {
            cout << "Hunger: -10\nHappiness: +15\nTiredness: -10\nBored: +10" << endl;;
        }
    }
    else if (_option == 'd') // hide and seek
    {
        if(snakeSpeed < 5)
        {
            cout << "Hunger: -10\nHappiness: +5\nTiredness: -5\nBored: -10" << endl;
        }
        else if(snakeSpeed <=5 and snakeSpeed >= 15)
        {
            cout << "Hunger: -10\nHappiness: +10\nTiredness: -10\nBored: -5" << endl;;
        }
        else if(snakeSpeed > 15)
        {
            cout << "Hunger: -5\nHappiness: +5\nTiredness: -5\nBored: +5" << endl;;
        }
    }
}

char Snake::loadSnakePlayOptions()
{
    char option;
    cout << "You selected to Play with your pet snake " << getPetName() << ". Now select an option on what games you'll like to play with your pet...\n" <<
    "(a) Chase the mice. Chasing the mice would increase/decrease your pet snake's status...\n";
    snakeSpeedofPlay('a');

    cout << "\n(b) Maze. Playing the maze game would increase/decrease your pet snake's status...\n";
    snakeSpeedofPlay('b'); 

    cout << "\n(c) Swimming. Swimming would increase/decresase your pet snake's status...\n";
    snakeSpeedofPlay('c');

    cout << "\n(d) Hide and Seek. Playing hide and seek would increase/decrease your pet snake's status...\n";
    snakeSpeedofPlay('d');

    cout << "\n(e) Choose an option other than playing with your pet snake " << getPetName() << endl;
    snakeSpeedofPlay('e');
    cin >> option;
    return option;
}
void Snake::playWithPet(char _option)
{
   if(_option == 'a') //chase mice
    {
        cout << "Yout selected to play chase the mice with " << getPetName() << ". If you catch the mice, you get to eat it!" << endl;
        if(snakeSpeed < 5)
        {
            levelAbove(hungry, 5);
            levelAbove(happyness,5);
            levelBelowZero(sleepy,5);
            levelAbove(bored, 10);
        }
        else if(snakeSpeed <=5 and snakeSpeed >= 15)
        {
            levelAbove(hungry, 5);
            levelAbove(happyness, 10);
            levelBelowZero(sleepy, 10);
            levelAbove(bored, 5);
        }
        else if(snakeSpeed > 15)
        {
            levelAbove(hungry, 10);
            levelAbove(happyness, 15);
            levelBelowZero(sleepy, 5);
            levelAbove(bored, 5);
        }
    }
    else if(_option == 'b') //maze
    {
        cout << "Yout selected to play the maze game. Find your way out and win a prize!" << endl;
        if(snakeSpeed < 5)
        {
            levelBelowZero(hungry, 5);
            levelBelowZero(happyness, 10);
            levelBelowZero(sleepy, 5);
            levelBelowZero(bored, 10);
        }
        else if(snakeSpeed <=5 and snakeSpeed >= 15)
        {
            levelBelowZero(hungry, 10);
            levelBelowZero(happyness, 5);
            levelBelowZero(bored, 5);
            levelBelowZero(sleepy, 10);
        }
        else if(snakeSpeed > 15)
        {
            levelBelowZero(hungry, 15);
            levelAbove(happyness, 5);
            levelAbove(sleepy, 5);
            levelAbove(bored, 5);
        }
    }
    else if(_option == 'c') //swim
    {
        cout << "Yout selected to play swim. Make sure " << getPetName() << " does not drown!"<< endl;
        if(snakeSpeed < 5)
        {
            levelBelowZero(hungry,10);
            levelAbove(happyness,5);
            levelBelowZero(sleepy,5);
            levelAbove(bored, 10);
        }
        else if(snakeSpeed <=5 and snakeSpeed >= 15)
        {
            levelBelowZero(hungry, 5);
            levelAbove(happyness, 10);
            levelBelowZero(sleepy, 5);
            levelAbove(bored, 15);
        }
        else if(snakeSpeed > 15)
        {
            levelBelowZero(hungry, 10);
            levelAbove(happyness, 15);
            levelBelowZero(sleepy, 10);
            levelAbove(bored, 10);
        }
    }
    else if (_option == 'd') // hide and seek
    {
        cout << "Yout selected to play hide and seek. You will never find " << getPetName() << "." << endl;
        if(snakeSpeed < 5)
        {
            levelBelowZero(hungry, 10);
            levelAbove(happyness, 5);
            levelBelowZero(sleepy,5);
            levelBelowZero(bored, 10);
        }
        else if(snakeSpeed <=5 and snakeSpeed >= 15)
        {
            levelBelowZero(hungry,10);
            levelAbove(happyness, 10);
            levelBelowZero(sleepy, 10);
            levelBelowZero(bored, 5);
        }
        else if(snakeSpeed > 15)
        {
            levelBelowZero(hungry, 5);
            levelAbove(happyness, 5);
            levelBelowZero(sleepy, 5);
            levelAbove(bored, 5);
            
        }

    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    nextHour();
    newPetLevel();
}

char Snake::loadSnakeFoodOptions()
{
    char option;
    cout << "You selected to feed your pet snake " << getPetName() << ". Now select an option as to what you would like to feed your pet snake...\n" <<
    "(a) Insects. Feeding your pet snake " << getPetName() << " insects would increase/decrease your pet snake's status...\n" <<
    "Hunger: +10\nHappiness: +5\nTiredness: -10\nBored: -10" << "\n" <<
    
    "\n(b) Frogs. Feeding your pet snake " << getPetName() << " frogs would increase/decrease your pet snake's status...\n" <<
    "Hunger: +15\nHappiness: +10\nTiredness: -5\nBored: +0" << "\n" <<

    "\n(c) Rabbit. Feeding your pet snake " << getPetName() << " a rabbit would increase/decrease your pet snake's status...\n" <<
    "Hunger: +15\nHappiness: +15\nTiredness: +0\nBored: +5" << "\n" <<

    "\n(d) Human. Feeding your pet snake " << getPetName() << " a human would increase/decrease your pet snake's status...\n" <<
    "Hunger: +20\nHappiness: +10\nTiredness: +10\nBored: -10" << "\n" <<

    "\n(e) Choose an option other than feeding your pet snake " << getPetName() << endl;
    
    cin >> option;
    return option;
}
void Snake::feedPet(char _option)
{
    if(_option =='a')
    {
        cout << "You selected to feed your pet snake " << getPetName() << " insects. It's lunch time baby!" << endl;
        levelAbove(hungry, 10);
        levelAbove(happyness,5);
        levelBelowZero(sleepy, 10);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'b')
    {
        cout << "You selected to feed your pet snake " << getPetName() << " frogs. 'Ribbit' 'Ribbit' time baby!" << endl;
        levelAbove(hungry, 15);
        levelAbove(happyness, 10);
        levelBelowZero(sleepy, 5);
    }
    else if(_option == 'c')
    {
        cout << "You selected to feed your pet snake " << getPetName() << " a rabbit. Make sure your rabbit does not hop away!" << endl;
        levelAbove(hungry, 15);
        levelAbove(happyness,15);
        levelAbove(bored, 5);
    }
    else if(_option == 'd')
    {
        cout << "You selected to feed your pet snake " << getPetName() << " a human. It's time to feast baby!" << endl;
        levelAbove(hungry, 20);
        levelAbove(happyness, 10);
        levelAbove(sleepy, 10);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    nextHour();
    newPetLevel();

}

char Snake::loadSnakeNapOptions()
{
    char option;
    cout << "You selected to put your pet snake " << getPetName() << " to sleep. Now select an option as to where you would like for your pet snake to sleep at...\n" <<
    "(a) Box. As " << getPetName() << " sleeps in a box, it would increase/decrease your pet snake's status...\n" <<
    "Hunger: -10\nHappiness: -15\nTiredness: +15\nBored: -5" << "\n" <<

    "\n(b) Around neck. As " << getPetName() << " sleeps around pet owner's neck, it would increase/decrease your pet snake's status...\n" <<
    "Hunger: -5\nHappiness: +5\nTiredness: +15\nBored: -10" << "\n" <<

    "\n(c) Anywhere around owner's house. As " << getPetName()  << " sleeps anywhere around the owner's house, it would increase/decrease your pet snake's status...\n" <<
    "Hunger: +5\nHappiness: +10\nTiredness: +15\nBored: -5" << "\n" <<

    "\n(d) Boot. As " << getPetName() << " sleepes on owner's boot, it would increase/decrease your pet snake's status...\n" <<
    "Hunger: -10\nHappiness: +5\nTiredness: +15\nBored: -10" << "\n" <<

    "\n(e) Choose an option other than putting your pet snake " << getPetName() << " to sleep." << endl;
    cin >> option;
    return option;

}

void Snake::petSleeps(char _option)
{
    if(_option =='a')
    {
        cout << "You selected to put your pet snake " << getPetName() << " to sleep in a box. Goodnight." << endl;
        levelBelowZero(hungry, 10);
        levelBelowZero(happyness,15);
        levelAbove(sleepy, 15);
        levelBelowZero(bored, 5);
    }
    else if(_option == 'b')
    {
        cout << "You selected to put your pet snake " << getPetName() << " to sleep around owner's neck. Goodnight." << endl;
        levelBelowZero(hungry, 5);
        levelAbove(happyness, 5);
        levelAbove(sleepy, 15);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'c')
    {
        cout << "You selected to put your pet snake " << getPetName() << " to sleep anywhere around owner's house. Goodnight." << endl;
        levelAbove(hungry, 5);
        levelAbove(happyness,10);
        levelBelowZero(bored, 5);
        levelAbove(sleepy, 15);
    }
    else if(_option == 'd')
    {
        cout << "You selected to put your pet snake " << getPetName() << " to sleep in owner's boot. Goodnight." << endl;
        levelBelowZero(hungry, 10);
        levelAbove(happyness, 5);
        levelAbove(sleepy, 15);
        levelBelowZero(bored, 10);
    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    nextHour();
    newPetLevel();
}

char Snake::loadSnakeTrainOptions()
{
    char option;
    cout << "You selected to train your pet snake " << getPetName() << ". Now select what you would like to train your pet snake...\n" << 
    "(a) Be calm. Teaching your pet snake " << getPetName() << " how to be calm would increase/decrease your per snake's status...\n" << 
    "Train: +15\n" << "Happiness: +5\n" << "Hunger: +5\n" << "Tiredness: -10\n" << "Bored: +10" << "\n" <<

    "\n(b) Wrap around arm. Teaching your pet snake " << getPetName() << " how to wrap around any person's arm would increase/decrease your pet snake's status...\n" <<
    "Train: +15\n" << "Happiness: +10\n" << "Hunger: +10\n" << "Tiredness: -10\n" << "Bored: +5" <<  "\n" <<

    "\n(c) Be aggressive. Teaching your pet snake " << getPetName() << " how to be aggressive would increase/decrease your pet snake's status...\n" <<
    "Train: +15\n" << "Happiness: +5\n" << "Hunger: +5\n" << "Tiredness: -15\n" << "Bored: -5" << "\n" <<

    "\n(d) Play dead. Teaching your pet snake " << getPetName() << " how to play dead would increase/decrease your pet snake's status...\n" << 
    "Train: +15\n" << "Happiness: +10\n" << "Hunger: +15\n" << "Tiredness: +0\n" << "Bored: +5" << "\n" <<

    "\n(e) Choose an option other than training your pet snake " << getPetName() << endl;
    
    cin >> option;
    return option;
}

void Snake::trainPet(char _option)
{

    if(_option =='a')
    {
        cout << "You selected to train your pet snake " << getPetName() << " on how to be calm. Your snake deserves 1 treat." << endl;
        levelAbove(hungry, 5);
        levelAbove(happyness,5);
        levelBelowZero(sleepy, 10);
        levelAbove(bored, 5);
        
    }
    else if(_option == 'b')
    {
        cout << "You selected to train your pet snake " << getPetName() << " on how to wrap around arm. Your snake deserves 2 treats." << endl;
        levelAbove(hungry, 10);
        levelAbove(happyness, 10);
        levelBelowZero(sleepy, 10);
        levelAbove(bored, 5);
    }
    else if(_option == 'c')
    {
        cout << "You selected to train your pet snake " << getPetName() << " on how to be aggressive. Your snake deserves 1 treat." << endl;
        levelAbove(hungry, 5);
        levelAbove(happyness,5);
        levelBelowZero(bored, 5);
        levelBelowZero(sleepy, 15);
    }
    else if(_option == 'd')
    {
        cout << "You selected to train your pet snake " << getPetName() << " on how to play dead. Your pet snake deserves 4 treats." << endl;
        levelAbove(hungry, 15);
        levelAbove(happyness, 10);
        levelAbove(bored, 5);
    }
    else if(_option == 'e')
    {
        loadPetOptions();
    }
    levelAbove(train, 15);
    nextHour();
    newPetLevel();
}