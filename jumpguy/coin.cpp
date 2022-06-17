#include "coin.h"
#include <iostream>

Coin::Coin(int x, int y)
{
    this->x = x;
    this->y = y;

    this->sprite.setPosition(this->x, this->y);
    this->initTexture();
    this->initSprite(this->w, this->h);
}


void Coin::initTexture(){
    if(!this->texture.loadFromFile("assety/gold_coin.png")){
        std::cout << "nie udalo sie zaladowac zdjecia";
    }
}

void Coin::initSprite(float sW, float sH){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(sW, sH);

}

void Coin::render(sf::RenderTarget * target){
    target->draw(this->sprite);
}

const sf::FloatRect Coin::getBounds() const{
    return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Coin::getPos() const{
    return this->sprite.getPosition();
}
