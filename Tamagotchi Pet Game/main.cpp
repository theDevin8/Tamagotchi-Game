#include <iostream>
#include <string>
#include <fstream>
#include "pet.h"
#include "dog.h"
#include "monkey.h"
#include "snake.h"

using namespace std;

int main()
{
    string begin;
    cout << "Welcome to the Tamagotchi Pet Game.\n" << 
    "Game Objective: Thanks for choosing to play the Tamagotchi Pet Game. In our Tamgotchi Pet Game, we've desgined for the user, which is you, to have the option to" << 
    "select either a pet dog, monkey, or snake. You will be generated a random sataus for your pet, which contains the level of boredom, happiness, hunger, and tireness. This game is also designed for you to desgin your own pet with amazing features," <<
    "and allows you to have the option to either play, feed, sleep, or train with your pet. Choosing one of the options would affect the stauts of your pet, however, gives you the opportunity to maximize your pets status. Now the objective of the game is to maximize your pets overall level to 100." << 
    " Maximizing your pet status to 100's will increase your overall level by 1. Now I've explained everything you need to know about the Tamgotchi Pet Game, so enjoy!" << endl;
    cout << endl;
    cout << "Enter 'start' to begin playing the Tamagotchi Pet Game..." << endl;
    cin >> begin; //starts program

    if(begin == "start")
    {
        char petOption;
        while(petOption != 'd')
        {
        cout << "Please select a pet option or exit the Tamagotchi Pet Game...\n" <<
        "(a) Dog. Choosing a pet Dog lets you input the features of your pet dog's height, weight, eye color, and fur color.\n" <<
        "(b) Monkey. Choosing a pet Monkey lets you input the features of your pet monkey's height, weight, eye color, fur color, and speed.\n" <<
        "(c) Snake. Choosing a pet Snake lets you input the features of your pet snake's length, eye color, skin color, hertz, and speed.\n" <<
        "(d) Exit.\n" << 
        "(e) Load a Pet from a previous game." << endl;
        cin >> petOption; // loads pet options

        int userPetAge, userPetHeight, userPetWeight, userPetSpeed, userPetLength, userPetHertz;
        string userPetName, userPetBreed, userPetEyeColor, userPetFurColor, userPetSkinColor;
        Dog userDog;
        Monkey userMonkey;
        Snake userSnake;
        
        string typeofPet;
        userDog.setRandomValues(); 
        userMonkey.setRandomValues();
        userSnake.setRandomValues(); //sets random values

        if(petOption == 'a')
        {
            typeofPet = "Dog";

            cout << "You chose to have a pet dog. Now please eneter your dog's name(single name), breed(prees 'return' after entering breed of pet), and age." << endl;
            cin >> userPetName; 
            userDog.setpetName(userPetName);
            getline(cin, userPetBreed);
            userDog.setpetOrigin(userPetBreed);
            cin >> userPetAge;
            cin.ignore();
            userDog.setpetAge(userPetAge); // sets attributes of a pet

            cout << "Now that you've entered your pet dog's name, breed, and age; Please enter your pet dog's height(in.), weight(lbs.), eye color(single color), and fur color(single color)." << endl;
            cin >> userPetHeight >> userPetWeight >> userPetEyeColor >> userPetFurColor;
            userDog.setDogHeight(userPetHeight);
            userDog.setDogWeight(userPetWeight);
            userDog.setDogEyeColor(userPetEyeColor);
            userDog.setDogFurColor(userPetFurColor); // sets features of a pet dog
        
            cout << "Creating your pet dog " << userPetName << "..." << endl;
            userDog.petDescription();
            char nextOption;
            cout << "\nPlease input 'f' to continue or 'e' to exit..." << endl;
            cin >> nextOption;
            if(nextOption == 'e')
            {
                exit(-1);
            }
            while(nextOption != 'f')
            {
                cout << "You've eneter an invaild letter, please enter 'f' to continue...";
                cin >> nextOption;
            }

            cout << "Generating your pet dog " << userPetName << " status..." << endl;
            cout << userDog.petStatus() << endl;
            char nextOption2;
            cout << "\nPlease input 'f' to continue or 'e' to exit..." << endl;
            cin >> nextOption2;
            if(nextOption2 == 'e')
            {
                exit(-1);
            }
            while(nextOption2 != 'f')
            {
                cout << "You've eneter an invaild letter, please enter 'f' to continue...";
                cin >> nextOption2;
            }

            char userPetOption;
            bool dogBool = true;
            userDog.loadPetOptions();
            cin >> userPetOption;
            do
            {
                if(userPetOption == 'a')
                {
                    userDog.playWithPet(userDog.loadDogPlayOptions());
                    cout << userDog.petStatus();
                    userDog.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'b')
                {
                    userDog.petSleeps(userDog.loadDogNapOptions());
                    cout << userDog.petStatus();
                    userDog.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'c')
                {
                    userDog.feedPet(userDog.loadDogFoodOptions());
                    cout << userDog.petStatus();
                    userDog.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'd')
                {
                    userDog.trainPet(userDog.loadDogtrainOptions());
                    cout << userDog.petStatus();
                    userDog.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'e')
                {
                    ofstream fout("FileSave.txt");
                    fout << typeofPet << endl;
                    fout << userPetName << endl;
                    fout << userPetBreed << endl;
                    fout << userPetAge << endl;
                    fout << userPetHeight << endl;
                    fout << userPetWeight << endl;
                    fout << userPetEyeColor << endl;
                    fout << userPetFurColor << endl;
                    fout << userDog.getBored() << endl;
                    fout << userDog.getHungry() << endl;
                    fout << userDog.getSleepy() << endl;
                    fout << userDog.getHappieness() << endl;
                    fout << userDog.getTrain() << endl;
                    fout.close();
                    dogBool = false;
                    exit(-1);
                }
                if(userDog.getOverAllLevel() >= 100)
                {
                    cout << "You completed the Tamagotchi Pet Game. Thanks for playing!" << endl;
                    exit(-1);
                }
                
            
            } while(dogBool == true);

        } //end for dog

        else if(petOption == 'b')
        {
            typeofPet = "Monkey";
            cout << "You chose to have a pet monkey. Now please enter you monkey's name(single name), breed(prees 'return' after entering breed of pet), and age." << endl;
            cin >> userPetName;
            userMonkey.setpetName(userPetName);
            getline(cin, userPetBreed);
            userMonkey.setpetOrigin(userPetBreed);
            cin >> userPetAge;
            userMonkey.setpetAge(userPetAge); // sets basic values of a pet

            cout << "Now that you've entered your pet monkey's name, breed, and age; Please enter your pet monkey's height(in.), weight(lbs.), eye color(single color), fur color(single color), and speed(mph.)." << endl;
            cin >> userPetHeight >> userPetWeight >> userPetEyeColor >> userPetFurColor >> userPetSpeed;
            userMonkey.setMonkeyHeight(userPetHeight);
            userMonkey.setMonkeyWeight(userPetWeight);
            userMonkey.setMonekyEyeColor(userPetEyeColor);
            userMonkey.setMonkeyFurColor(userPetFurColor);
            userMonkey.setMonkeySpeed(userPetAge); 
            userMonkey.setMonkeySpeed(userPetSpeed);// sets features of monkey
            
            cout << "Creating your pet monkey " << userPetName << "..." << endl;
            userMonkey.petDescription();
            char nextOption;
            cout << "\nPlease input 'f' to continue or enter 'e' to exit..." << endl;
            cin >> nextOption;
            if(nextOption == 'e')
            {
                exit(-1);
            }
            while(nextOption != 'f')
            {
                cout << "You've eneter an invaild letter, please enter 'f' to continue or enter 'e' to exit...";
                cin >> nextOption;
            } //checks if user inputed f or e;
            
            cout << "Generating your pet dog " << userPetName << "'s status..." << endl;
            cout << userMonkey.petStatus() << endl;
            char nextOption2;
            cout << "\nPlease enter 'f' to continue or 'e' to exit..." << endl;
            cin >> nextOption2;
            if(nextOption2 == 'e')
            {
                exit(-1);
            }
            while(nextOption2 != 'f')
            {
                cout << "You've eneter an invaild letter, please enter 'f' to continue or enter 'e' to exit...";
                cin >> nextOption2;
            } //checks if usere inputed f or e;

            char userPetOption;
            bool boolMonkey = true;
            userMonkey.loadPetOptions();
            cin >> userPetOption;
            do
            {
                if(userPetOption == 'a')
                {
                    userMonkey.playWithPet(userMonkey.loadMonkeyPlayOptions());
                    cout << userMonkey.petStatus();
                    userMonkey.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'b')
                {
                    userMonkey.petSleeps(userMonkey.loadMonkeyNapOptions());
                    cout << userMonkey.petStatus();
                    userMonkey.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'c')
                {
                    userMonkey.feedPet(userMonkey.loadMonkeyFoodOptions());
                    cout << userMonkey.petStatus();
                    userMonkey.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'd')
                {
                    userMonkey.trainPet(userMonkey.loadMonkeyTrainOptions());
                    cout << userMonkey.petStatus();
                    userMonkey.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'e')
                {
                    ofstream fout("FileSave.txt");
                    fout << typeofPet << endl;
                    fout << userPetName << endl;
                    fout << userPetBreed << endl;
                    fout << userPetAge << endl;
                    fout << userPetHeight << endl;
                    fout << userPetWeight << endl;
                    fout << userPetEyeColor << endl;
                    fout << userPetFurColor << endl;
                    fout << userPetSpeed << endl;
                    fout << userMonkey.getBored() << endl;
                    fout << userMonkey.getHungry() << endl;
                    fout << userMonkey.getSleepy() << endl;
                    fout << userMonkey.getHappieness() << endl;
                    fout << userMonkey.getTrain() << endl;
                    fout.close();
                    boolMonkey = false;
                    exit(-1);
                }
                if(userMonkey.getOverAllLevel() >= 100)
                {
                    cout << "You completed the Tamagotchi Pet Game. Thanks for playing!" << endl;
                    exit(-1);
                }
            }while(boolMonkey == true);

        }// end of monkey

        else if(petOption == 'c')
        {
            typeofPet = "Snake";
            cout << "You chose to have a pet snake. Now please enter your snake's name(single name), breed(prees 'return' after entering breed of pet), and age." << endl;
            cin >> userPetName;
            userSnake.setpetName(userPetName);
            getline(cin, userPetBreed);
            userSnake.setpetOrigin(userPetBreed);
            cin >> userPetAge;
            cin.ignore();
            userSnake.setpetAge(userPetAge); // sets values of a pet

            cout << "Now that you've enter your pet snake's name, breed, and age; Please enter your pet snake's length(in.), hertz(Hz.), speed(mph.), skin color(single color), eye color(single color)." << endl;
            cin >> userPetLength >> userPetHertz >> userPetSpeed >> userPetSkinColor >> userPetEyeColor;
            userSnake.setSnakeLength(userPetLength);
            userSnake.setSnakeHertz(userPetHertz);
            userSnake.setSnakeSpeed(userPetSpeed);
            userSnake.setSnakeSkinColor(userPetSkinColor);
            userSnake.setSnakeEyeColor(userPetEyeColor); //sets values of a pet snake

            cout << "Creating your pet snake " << userPetName << "..." << endl;
            userSnake.petDescription();
            char nextOption;
            cout << "\nPlease input 'f' to continue or 'e' to exit..." << endl;
            cin >> nextOption;
            if(nextOption == 'e')
            {
                exit(-1);
            }
            while(nextOption != 'f')
            {
                cout << "You've eneter an invaild letter, please enter 'f' to continue...";
                cin >> nextOption;
            } //first continue option
            
            cout << "Generating your pet snake " << userPetName << " status..." << endl;
            cout << userSnake.petStatus() << endl;
            char nextOption2;
            cout << "\nPlease input 'f' to continue or 'e' to exit..." << endl;
            cin >> nextOption2;
            if(nextOption2 == 'e')
            {
                exit(-1);
            }
            while(nextOption2 != 'f')
            {
                cout << "You've eneter an invaild letter, please enter 'f' to continue...";
                cin >> nextOption2;
            }// second continue option
            
            char userPetOption;
            bool boolsnake = true;
            userSnake.loadPetOptions();
            cin >> userPetOption;
            do
            {
                if(userPetOption == 'a')
                {
                    userSnake.playWithPet(userSnake.loadSnakePlayOptions());
                    cout << userSnake.petStatus();
                    userSnake.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'b')
                {
                    userSnake.petSleeps(userSnake.loadSnakeNapOptions());
                    cout << userSnake.petStatus();
                    userSnake.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'c')
                {
                    userSnake.feedPet(userSnake.loadSnakeFoodOptions());
                    cout << userSnake.petStatus();
                    userSnake.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'd')
                {
                    userSnake.trainPet(userSnake.loadSnakeTrainOptions());
                    cout << userSnake.petStatus();
                    userSnake.loadPetOptions();
                    cin >> userPetOption;
                }
                else if(userPetOption == 'e')
                {
                    ofstream fout("FileSave.txt");
                    fout << typeofPet << endl;
                    fout << userPetName << endl;
                    fout << userPetBreed << endl;
                    fout << userPetAge << endl;
                    fout << userPetSkinColor << endl;
                    fout << userPetEyeColor << endl;
                    fout << userPetLength << endl;
                    fout << userPetHertz << endl;
                    fout << userPetSpeed << endl;
                    fout << userSnake.getBored() << endl;
                    fout << userSnake.getHungry() << endl;
                    fout << userSnake.getSleepy() << endl;
                    fout << userSnake.getHappieness() << endl;
                    fout << userSnake.getTrain() << endl;
                    fout.close();
                    boolsnake = false;
                    exit(-1);
                }
                if(userSnake.getOverAllLevel() >= 100)
                {
                    cout << "You completed the Tamagotchi Pet Game. Thanks for playing!" << endl;
                    exit(-1);
                }
                
            
            } while(boolsnake == true);

        }//end of snake

        else if(petOption == 'd')
        {
            exit(-1);
        }// end of option d
        
        else if(petOption == 'e')
        {
            fstream fin("FileSave.txt");
            fin >> typeofPet;
            if(typeofPet == "Dog")
            {
                int userBored, userHungry, userSleepy, userHappieness, userTrain;
                int userPetHeight, userPetWeight;
                string userPetEyeColor, userPetFurColor;
                fin >> userPetName;
                fin.ignore();
                getline(fin, userPetBreed);
                fin >> userPetAge;
                fin >> userPetHeight >> userPetWeight >> userPetEyeColor >> userPetFurColor;
                fin.ignore();
                fin >> userBored >> userHungry >> userSleepy >> userHappieness >> userTrain;
                fin.close();
                userDog.setpetName(userPetName);
                userDog.setpetOrigin(userPetBreed);
                userDog.setpetAge(userPetAge);
                userDog.setDogHeight(userPetHeight);
                userDog.setDogWeight(userPetWeight);
                userDog.setDogEyeColor(userPetEyeColor);
                userDog.setDogFurColor(userPetFurColor);
                userDog.setBored(userBored);
                userDog.setHungry(userHungry);
                userDog.setSleepy(userSleepy);
                userDog.setHappieness(userHappieness);
                userDog.setTrain(userTrain);
                cout << "Loading previous pet dog status..." << endl;
                cout << userDog.petStatus();

                char userPetOption;
                bool dogBool = true;
                userDog.loadPetOptions();
                cin >> userPetOption;
                do
                {
                    if(userPetOption == 'a')
                    {
                        userDog.playWithPet(userDog.loadDogPlayOptions());
                        cout << userDog.petStatus();
                        userDog.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'b')
                    {
                        userDog.petSleeps(userDog.loadDogNapOptions());
                        cout << userDog.petStatus();
                        userDog.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'c')
                    {
                        userDog.feedPet(userDog.loadDogFoodOptions());
                        cout << userDog.petStatus();
                        userDog.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'e')
                    {
                        ofstream fout("FileSave.txt");
                        fout << typeofPet << endl;
                        fout << userPetName << endl;
                        fout << userPetBreed << endl;
                        fout << userPetAge << endl;
                        fout << userPetHeight << endl;
                        fout << userPetWeight << endl;
                        fout << userPetEyeColor << endl;
                        fout << userPetFurColor << endl;
                        fout << userDog.getBored() << endl;
                        fout << userDog.getHungry() << endl;
                        fout << userDog.getSleepy() << endl;
                        fout << userDog.getHappieness() << endl;
                        fout << userDog.getTrain() << endl;
                        fout.close();
                        dogBool = false;
                        exit(-1);
                    }
                    if(userDog.getOverAllLevel() >= 100)
                    {
                        cout << "You completed the Tamagotchi Pet Game. Thanks for playing!" << endl;
                        exit(-1);
                    }
                    
                
                } while(dogBool == true);
                
            }
            else if(typeofPet == "Monkey")
            {
                int userBored, userHungry, userSleepy, userHappieness, userTrain;
                int userPetHeight, userPetWeight, userSpeed;
                string userPetEyeColor, userPetFurColor;
                fin >> userPetName;
                fin.ignore();
                getline(fin, userPetBreed);
                fin >> userPetAge;
                fin >> userPetHeight >> userPetWeight >> userPetEyeColor >> userPetFurColor >> userPetSpeed;
                fin.ignore();
                fin >> userBored >> userHungry >> userSleepy >> userHappieness >> userTrain;
                fin.close();

                userMonkey.setpetName(userPetName);
                userMonkey.setpetOrigin(userPetBreed);
                userMonkey.setpetAge(userPetAge);
                userMonkey.setMonkeyHeight(userPetHeight);
                userMonkey.setMonkeyWeight(userPetWeight);
                userMonkey.setMonekyEyeColor(userPetEyeColor);
                userMonkey.setMonkeyFurColor(userPetFurColor);
                userMonkey.setMonkeySpeed(userPetSpeed);
                userMonkey.setBored(userBored);
                userMonkey.setHungry(userHungry);
                userMonkey.setSleepy(userSleepy);
                userMonkey.setHappieness(userHappieness);
                userMonkey.setTrain(userTrain);

                cout << "Loading previous pet monkey status..." << endl;
                cout << userMonkey.petStatus();

                char userPetOption;
                bool monkeyBool = true;
                userMonkey.loadPetOptions();
                cin >> userPetOption;
                do
                {
                    if(userPetOption == 'a')
                    {
                        userMonkey.playWithPet(userMonkey.loadMonkeyPlayOptions());
                        cout << userMonkey.petStatus();
                        userMonkey.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'b')
                    {
                        userMonkey.petSleeps(userMonkey.loadMonkeyNapOptions());
                        cout << userMonkey.petStatus();
                        userMonkey.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'c')
                    {
                        userMonkey.feedPet(userMonkey.loadMonkeyFoodOptions());
                        cout << userMonkey.petStatus();
                        userMonkey.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'd')
                    {
                        userMonkey.trainPet(userMonkey.loadMonkeyTrainOptions());
                        cout << userMonkey.petStatus();
                        userMonkey.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'e')
                    {
                        ofstream fout("FileSave.txt");
                        fout << typeofPet << endl;
                        fout << userPetName << endl;
                        fout << userPetBreed << endl;
                        fout << userPetAge << endl;
                        fout << userPetHeight << endl;
                        fout << userPetWeight << endl;
                        fout << userPetEyeColor << endl;
                        fout << userPetFurColor << endl;
                        fout << userPetSpeed << endl;
                        fout << userMonkey.getBored() << endl;
                        fout << userMonkey.getHungry() << endl;
                        fout << userMonkey.getSleepy() << endl;
                        fout << userMonkey.getHappieness() << endl;
                        fout << userMonkey.getTrain() << endl;
                        fout.close();
                        monkeyBool = false;
                        exit(-1);
                    }
                    if(userMonkey.getOverAllLevel() >= 100)
                    {
                        cout << "You completed the Tamagotchi Pet Game. Thanks for playing!" << endl;
                        exit(-1);
                    }
                        
                } while(monkeyBool == true);
                
            }
            else if(typeofPet == "Snake")
            {
                int userBored, userHungry, userSleepy, userHappieness, userTrain;
                fin >> userPetName;
                fin.ignore();
                getline(fin,userPetBreed);
                fin >> userPetAge;
                fin >> userPetSkinColor >> userPetEyeColor >> userPetLength >> userPetHertz >> userPetSpeed;
                fin.ignore();
                fin >> userBored >> userHungry >> userSleepy >> userHappieness >> userTrain;
                fin.close();

                userSnake.setpetName(userPetName);
                userSnake.setpetOrigin(userPetBreed);
                userSnake.setpetAge(userPetAge); // sets values of a pet
                userSnake.setSnakeLength(userPetLength);
                userSnake.setSnakeHertz(userPetHertz);
                userSnake.setSnakeSpeed(userPetSpeed);
                userSnake.setSnakeSkinColor(userPetSkinColor);
                userSnake.setSnakeEyeColor(userPetEyeColor);
                userSnake.setBored(userBored);
                userSnake.setHungry(userHungry);
                userSnake.setSleepy(userSleepy);
                userSnake.setHappieness(userHappieness);
                userSnake.setTrain(userTrain);

                cout << "Loading previous pet snake status..." << endl;
                cout << userSnake.petStatus();
                char userPetOption;
                bool boolsnake = true;
                userSnake.loadPetOptions();
                cin >> userPetOption;
                do
                {
                    if(userPetOption == 'a')
                    {
                        userSnake.playWithPet(userSnake.loadSnakePlayOptions());
                        cout << userSnake.petStatus();
                        userSnake.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'b')
                    {
                        userSnake.petSleeps(userSnake.loadSnakeNapOptions());
                        cout << userSnake.petStatus();
                        userSnake.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'c')
                    {
                        userSnake.feedPet(userSnake.loadSnakeFoodOptions());
                        cout << userSnake.petStatus();
                        userSnake.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'd')
                    {
                        userSnake.trainPet(userSnake.loadSnakeTrainOptions());
                        cout << userSnake.petStatus();
                        userSnake.loadPetOptions();
                        cin >> userPetOption;
                    }
                    else if(userPetOption == 'e')
                    {
                        ofstream fout("FileSave.txt");
                        fout << typeofPet << endl;
                        fout << userPetName << endl;
                        fout << userPetBreed << endl;
                        fout << userPetAge << endl;
                        fout << userPetSkinColor << endl;
                        fout << userPetEyeColor << endl;
                        fout << userPetLength << endl;
                        fout << userPetHertz << endl;
                        fout << userPetSpeed << endl;
                        fout << userSnake.getBored() << endl;
                        fout << userSnake.getHungry() << endl;
                        fout << userSnake.getSleepy() << endl;
                        fout << userSnake.getHappieness() << endl;
                        fout << userSnake.getTrain() << endl;
                        fout.close();
                        boolsnake = false;
                        exit(-1);
                    }
                    if(userSnake.getOverAllLevel() >= 100)
                    {
                        cout << "You completed the Tamagotchi Pet Game. Thanks for playing!" << endl;
                        exit(-1);
                    }
                    
                
                } while(boolsnake == true);

            }

        }//end of option 'e' load a pet from a previous game
        

        
        }

    }

    return 0;
}