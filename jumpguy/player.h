#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player{
private:
    sf::Texture texture;
    sf::Event ev;


    int x = 400;
    int y = 700;



public:
    Player();
     virtual ~Player();
    sf::Sprite sprite;
    bool isJumping = false;
    float velocityX = 0;
    float velocityY = 0;

    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;


    void update();
    void updateInput();
    void updateWallCollision();
    void init();
    void render(sf::RenderTarget * target);
    void initTexture();
    void initSprite();


};

#endif // PLAYER_H
