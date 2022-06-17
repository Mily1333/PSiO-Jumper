#include "player.h"
#include <iostream>

Player::Player(){
   this->init();
   this->initTexture();
   this->initSprite();
}

Player::~Player(){

}

//metody init
void Player::init(){

    this->sprite.setPosition(this->x,this->y);
}

void Player::initTexture(){
    if(!this->texture.loadFromFile("assety/guy.png")){
        std::cout << "nie udalo sie zaladowac zdjecia";
    }
}

void Player::initSprite(){
    this->sprite.setTexture(this->texture);

}

//pozycje
const sf::Vector2f& Player::getPos() const{
    return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const{
    return this->sprite.getGlobalBounds();
}

//metody update
void Player::updateInput(){
    this->sprite.move(velocityX, velocityY);


        if(isJumping){
            //grawitacja
            this->velocityY+=1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& !isJumping){
           this->velocityX = -8;
           this->velocityY = -20;
            isJumping = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping){
            this->velocityX = 8;
            this->velocityY = -20;
            isJumping = true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping){
                this->velocityY = -20;
                 isJumping = true;
         }
         else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isJumping){
                this->velocityX = -6;
         }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isJumping){
               this->velocityX = 6;
        }
         else if(!isJumping){
             this->velocityX = 0;
         }

}

void Player::updateWallCollision(){

    if(getPos().x<=0 && this->velocityX<0){
        this->sprite.setPosition(0, getPos().y);
        this->velocityX*=-1;
    }
    else if(getPos().x+getBounds().width>=800 && this->velocityX>0) {
        this->sprite.setPosition(800 - getBounds().width, getPos().y);
        this->velocityX*=-1;
    }
    if(getPos().y+getBounds().height>=800) this->sprite.setPosition(getPos().x, 800-getBounds().height);

}

void Player::update(){
    this->updateInput();
    this->updateWallCollision();
}

void Player::render(sf::RenderTarget * target){
    target->draw(this->sprite);
}


