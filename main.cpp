#include <SFML/Graphics.hpp>
#include "Screen.h"
#include <iostream>
#include <time.h>
#include <random>
#include <stack>
#include <queue>
#include "Point.h"
#include "Skin.h"

using namespace sf;
using namespace std;
void changeSkin();
void fillStack(stack<Skin> &st);
void fillQueue(queue<Texture> &maps);
void printAchievements(int score);

stack<Skin> stac;
queue<Texture> maps;



int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(640, 900), "My Doodle Jump");
    window.setFramerateLimit(60);

    start:
    Texture t1, t2, t3;

    t1.loadFromFile("res/background.png");
    t2.loadFromFile("res/platform.png");
    t3.loadFromFile("res/assets/skins/default_R.png");

    Button play("res/assets/ui/play-button.png","res/assets/ui/play-on.png", 100, 260);
    Button done("res/assets/ui/done.png","res/assets/ui/done-on.png", 400, 650);
    Button scores("res/assets/ui/scores.png","res/assets/ui/scores_on.png", 560, 825);

    Screen menuScreen("res/assets/menu-cover.png");

    Text scoreText, nameText;
    Font font, ft;
    font.loadFromFile("res/assets/MSComicSans.ttf");
    ft.loadFromFile("arial.ttf");
    nameText.setFont(font);
    nameText.setString("Jalen Smith | CS3A CRN 76408 | SPR21");
    nameText.setCharacterSize(20);
    nameText.setPosition(20, 845);
    nameText.setFillColor(Color::Black);

    Sprite background(t1), platform(t2), doodle(t3);


    int playerX = 100, playerY = 100, h = 200;
    float dy = 0; int score = 0;



    // TODO Start Menu
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        play.eventHandler(window, event);
        done.eventHandler(window, event);
        scores.eventHandler(window, event);

        queue<Texture> empty;
        swap( maps, empty );

        dy += 0.3;
        playerY += dy;
        if(playerY > 645)
            dy = -10;

        doodle.setPosition(playerX, playerY);
        play.update();
        done.update();
        scores.update();

        if(play.isEnabled(CLICKED))
            goto game;
        if(done.isEnabled(CLICKED))
            window.close();
        //if(scores.isEnabled(CLICKED)) // Poker Analysis Project Will be here

        window.draw(menuScreen);
        window.draw(doodle);
        window.draw(play);
        window.draw(done);
        window.draw(scores);
        window.draw(nameText);
        window.display();
    }



    // TODO Gameplay
    game:

    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setPosition(10, 0);
    scoreText.setFillColor(Color::Black);

    fillStack(stac);
    fillQueue(maps);

    Texture map = t1;
    Sprite gameBackground(map);

    Point plat[18];
    std::uniform_int_distribution<unsigned> x(0, 640 - t2.getSize().x);
    std::uniform_int_distribution<unsigned> y(100, 900);
    std::default_random_engine e(time(0));

    for (int i = 0; i < 18; i++)
    {
        plat[i].x = x(e);
        plat[i].y = y(e);
    }

    const int left_bound = 40;
    const int right_bound = 60;
    const int bottom_bound = 105;

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }
        scoreText.setString("Score: " + std::to_string(score));

        Texture t1 = stac.top().t1; // Right texture
        Texture t2 = stac.top().t2; // Left texture

        map = maps.front(); // Current map points to front of the queue

        if (Keyboard::isKeyPressed(Keyboard::Right)) { playerX += 4; doodle.setTexture(t1); }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { playerX -= 4;  doodle.setTexture(t2); }

        if (playerY == h && dy < (-1.62)) // terminal velocity when the player jump from a platform and doesn't go any higher
        {
            score += 1;
            scoreText.setString("Score: " + std::to_string(score));
        }
        if(score == 3000 || score == 7000)  // Better contrast for darker backgrounds
            scoreText.setFillColor(Color::White);
        else if(score == 4500)
          scoreText.setFillColor(Color::Black);

        printAchievements(score);

        if (playerX > 640) // reflect Player position on reaching borders
            playerX = 0;
        if (playerX < -40)
            playerX = window.getSize().x - t3.getSize().x;

        dy += 0.2;
        playerY += dy;


        if (playerY < h)
            for (int i = 0; i < 18; i++)
            {
                playerY = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > 900) {plat[i].y = 0; plat[i].x = rand() % 640;}
            }

        for (int i = 0; i < 18; ++i)
        {
            if ((playerX + right_bound > plat[i].x) && (playerX + left_bound < plat[i].x + t2.getSize().x)        // player's horizontal range can touch the platform
                && (playerY + bottom_bound > plat[i].y) && (playerY + bottom_bound < plat[i].y + t2.getSize().y)  // player's vertical   range can touch the platform
                && (dy > 0)) // player is falling
            {
                dy = -10;
            }

        }

        doodle.setPosition(playerX, playerY);
        window.draw(gameBackground);
        window.draw(doodle);

        for (int i = 0; i < 18; i++)
        {
            platform.setPosition(plat[i].x, plat[i].y);
            window.draw(platform);
        }

        if(playerY > 900)
        {
            scoreText.setPosition(200, 350);
            scoreText.setFillColor(Color::Black);
            goto gameover;
        }

        window.draw(scoreText);
        window.display();
    }



    // TODO Game Over
    gameover:


    Texture end;
    end.loadFromFile("res/assets/ui/gameover.png");
    Sprite gameOver(end);
    gameOver.setPosition(70, 130);
    gameOver.setScale({1.5, 1.5});


    Button playagain("res/assets/ui/play_again.png","res/assets/ui/play-again-button.png", 200, 550);
    Button menu("res/assets/ui/menu.png","res/assets/ui/menu-on.png", 200, 650);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        playagain.eventHandler(window, event);
        menu.eventHandler(window, event);

        playagain.update();
        menu.update();

        if(playagain.isEnabled(CLICKED))
        {
            playerX = 100, playerY = 100, h = 200;
            float dy = 0; score = 0;
            queue<Texture> empty;   // Clearing maps to refill on playAgain
            swap( maps, empty );
            goto game;
        }
        if(menu.isEnabled(CLICKED))
            goto start;

        window.draw(background);
        window.draw(gameOver);
        window.draw(scoreText);
        window.draw(playagain);
        window.draw(menu);
        window.display();

    }
    return 0;
}



void fillStack(stack<Skin> &st)
{
    for(int i = 8; i >= 1; i--)
    {
        Skin s = Skin(i);
        stac.push(s);
    }
}

void fillQueue(queue<Texture> &maps)
{
    for(int i = 1; i <= 7; i++)
    {
        Texture t;
        switch(i)
        {
            case 1:
                t.loadFromFile("res/background.png"); break;
            case 2:
                t.loadFromFile("res/soccer.png"); break;
            case 3:
                t.loadFromFile("res/hop.png"); break;
            case 4:
                t.loadFromFile("res/jungle.png"); break;
            case 5:
                t.loadFromFile("res/ice.png"); break;
            case 6:
                t.loadFromFile("res/underwater.png"); break;
            case 7:
                t.loadFromFile("res/space.png");
        }
        maps.push(t);
    }

}

void changeSkin()
{
    stac.pop();
}

void changeMap()
{
    maps.pop();
}

void printAchievements(int score)
{

    if(score == 1000)
    {
        changeSkin();
        changeMap();
        cout << "__________________________\nNew Skin Unlocked: Soccer \nGoal!\n\n";
    }
    else if(score == 2000)
    {
        changeSkin();
        changeMap();
        cout << "__________________________\nNew Skin Unlocked: Bunny\n\n";
    }
    else if(score == 3000)
    {
        changeSkin();
        changeMap();
        cout << "__________________________\nNew Skin Unlocked: Ninja\n\n";
    }
    else if(score == 4500)
    {
        changeSkin();
        changeMap();
        cout << "__________________________\nNew Skin Unlocked: Eskimo \nBrrrr!\n\n";
    }
    else if(score == 4800)
    {
        changeSkin();
        cout << "Uh Oh! Frozen!\n\n";
    }
    else if(score == 7000)
    {
        changeSkin();
        changeMap();
        cout << "Thawed out from all that jumping!\n"
                "__________________________\nNew Skin Unlocked: Nautilus\n\n";
    }
    else if(score == 10000)
    {
        changeSkin();
        changeMap();
        cout << "__________________________\nNew Skin Unlocked: Astronaut\nBlast Off!\n\n";
    }
}