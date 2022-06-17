#ifndef COIN_H
#define COIN_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Coin{
private:
     sf::Texture texture;

     int x = 500;
     int y = 700;
     float w = 0.1;
     float h = 0.1;

public:
      Coin(int x, int y);

      sf::Sprite sprite;
      bool isTouched = false;
      const sf::Vector2f& getPos() const;
      const sf::FloatRect getBounds() const;

      void update();
      void init();
      void render(sf::RenderTarget * target);
      void initTexture();
      void initSprite(float sW, float sH);
};

#endif // COIN_H
