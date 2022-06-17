#include "block.h"
#include <iostream>

Block::Block(int x, int y, float width, float height)
{
    this->x = x;
    this->y = y;
    this->w = width;
    this->h = height;

    this->sprite.setPosition(this->x, this->y);
    this->initTexture();
    this->initSprite(this->w, this->h);

}
Block::Block(int x, int y)
{
    this->x = x;
    this->y = y;

    this->sprite.setPosition(this->x, this->y);
    this->initTexture();
    this->initSprite(this->w, this->h);

}

void Block::initTexture(){
    if(!this->texture.loadFromFile("assety/top_tile.png")){
        std::cout << "nie udalo sie zaladowac zdjecia";
    }
}

void Block::initSprite(float sW, float sH){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(sW, sH);

}

void Block::render(sf::RenderTarget * target){
    target->draw(this->sprite);
}

const sf::FloatRect Block::getBounds() const{
    return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Block::getPos() const{
    return this->sprite.getPosition();
}
