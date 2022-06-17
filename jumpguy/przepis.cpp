#include "przepis.h"
#include <iostream>

Przepis::Przepis(int x, int y)
{
    this->x = x;
    this->y = y;

    this->sprite.setPosition(this->x, this->y);
    this->initTexture();
    this->initSprite(this->w, this->h);
}

void Przepis::initTexture(){
    if(!this->texture.loadFromFile("assety/przepis.png")){
        std::cout << "nie udalo sie zaladowac zdjecia";
    }
}

void Przepis::initSprite(float sW, float sH){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(sW, sH);

}

void Przepis::render(sf::RenderTarget * target){
    target->draw(this->sprite);
}

const sf::FloatRect Przepis::getBounds() const{
    return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Przepis::getPos() const{
    return this->sprite.getPosition();
}
