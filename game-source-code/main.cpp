#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <math.h>
#include "Game.h"
#include "SplashScreen.h"

using namespace std;

int main()
{
    while (true)
    {
        Game game;
        game.run();
    }   
}