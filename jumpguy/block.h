#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Block
{
private:
    sf::Texture texture;

    int x = 500;
    int y = 700;
    float w = 0.3;
    float h = 0.2;

public:
    Block(int x, int y);
    Block(int x, int y, float width, float height);

    sf::Sprite sprite;

    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;

    void update();
    void init();
    void render(sf::RenderTarget * target);
    void initTexture();
    void initSprite(float sW, float sH);
};

#endif // BLOCK_H
