#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "player.h"
#include "block.h"
#include "coin.h"
#include "przepis.h"

class Game{
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode VM;
    void initVar();
    void initWindow();

    //background
    sf::Texture backgroundTex;
    sf::Sprite background;
    //GUI
    sf::Font font;
    sf::Text showCollectedCoins;
    sf::Text showTimeText;
    sf::Text endGameText;
    float gravity;

    Player* player;
    Przepis* przepis;
    std::vector<Block*> ground;
    std::vector<Block*> blocks;
    std::vector<Coin*> coins;

    bool isPlayerTouchingBlock = false;
    sf::View playerView;
    int collectedCoins = 0;
    sf::Clock clock;
    sf::Time timer;
    sf::RectangleShape gameOver;
    sf::Color color;
    bool endGame = false;



public:
    Game();
    virtual ~Game();
    bool running();
    void pollEvent();

    void initBackground();
    void renderBackground();
    void update();
    void updateCollision();
    void render();
    void setPlayer();
    void initGround();
    void renderGround();
    void blockCollision();
    void createBlock();
    bool isCollidingUp(Block *el);
    bool isCollidingDown(Block *el);
    bool isCollidingRight(Block *el);
    bool isCollidingLeft(Block *el);
    void updateView();
    void coinCollision();
    void showPoints();
    void measureTime();
    void showTime();
    void endGameScreen();


};

#endif // GAME_H
