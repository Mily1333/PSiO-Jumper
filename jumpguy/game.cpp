#include "game.h"
#include <iostream>
#include <string>

Game::Game()
{
    this->initVar();
    this->initWindow();
    this->initBackground();
    this->initGround();
    this->setPlayer();
    this->createBlock();

    this->color.r = 75;
    this->color.g = 139;
    this->color.b = 59;
}

Game::~Game(){

}
void Game::setPlayer(){
    this->player = new Player();
    this->przepis = new Przepis(625,-4560);

}

void Game::initVar(){
    this->window = nullptr;
}

void Game::initWindow(){
    this->VM.width = 800;
    this->VM.height = 800;
    this->window = new sf::RenderWindow(this->VM, "PSiO - Jumper", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

    this->playerView.setCenter(400,400);
    this->playerView.setSize(800,800);
    this->window->setView(playerView);
}

void Game::initGround(){
    for(int i = 0; i<11;i++){
        ground.emplace_back(new Block(i*75,this->window->getSize().y-50));
    }
}

//render
void Game::render(){
    this->window->clear();
    this->renderBackground();

    this->player->render(this->window);

    this->renderGround();

    this->window->draw(showCollectedCoins);
    this->window->draw(showTimeText);

    this->przepis->render(this->window);

    if(this->endGame){
        this->window->draw(this->gameOver);
        this->window->draw(endGameText);
    }

   this->window->display();
}
void Game::renderBackground(){
    this->window->draw(this->background);
}

void Game::renderGround(){
    for(auto& el : ground){
        el->render(this->window);
    }
    for(auto& el : blocks){
        el->render(this->window);
    }
    for(auto& el : coins){
        if(!el->isTouched){
            el->render(this->window);
        }
    }
}
void Game::pollEvent(){
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::Closed:
                this->window->close();
            break;
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
            break;
        }
    }
}


bool Game::running(){
    return this->window->isOpen();
}

void Game::update(){
    this->pollEvent();

    if(!endGame){
        this->measureTime();
        this->player->update();
        this->blockCollision();
        this->coinCollision();
        this->updateView();
        this->showPoints();
    }


}
void Game::updateView(){
    //lvl 1
    if(this->player->getPos().y > 0){
        playerView.setCenter(400, 400);
        window->setView(playerView);
        background.setPosition(0,-780);
        this->showCollectedCoins.setPosition(5,5);
        this->showTimeText.setPosition(620,5);
    }
    //lvl 2
    if(this->player->getPos().y<= 0 && this->player->getPos().y>-820){
        playerView.setCenter(400, -400);
        window->setView(playerView);
        background.setPosition(0,-1200);
        this->showCollectedCoins.setPosition(5,-795);
        this->showTimeText.setPosition(620,-795);
    }
    //lvl 3
    if(this->player->getPos().y  <= -820 && this->player->getPos().y>-1620){
        playerView.setCenter(400, -1200);
        window->setView(playerView);
        background.setPosition(0,-1600);
        this->showCollectedCoins.setPosition(5,-1595);
        this->showTimeText.setPosition(620,-1595);
    }
   //lvl 4
    if(this->player->getPos().y  <= -1620 && this->player->getPos().y>-2400){
        playerView.setCenter(400, -2000);
        window->setView(playerView);
        background.setPosition(0,-2400);
        this->showCollectedCoins.setPosition(5,-2395);
        this->showTimeText.setPosition(620,-2395);
    }
    //lvl 5
    if(this->player->getPos().y  <= -2400 && this->player->getPos().y>-3200){
        playerView.setCenter(400, -2800);
        window->setView(playerView);
        background.setPosition(0,-3200);
        this->showCollectedCoins.setPosition(5,-3195);
        this->showTimeText.setPosition(620,-3195);
    }
    //lvl 6
    if(this->player->getPos().y  <= -3200 && this->player->getPos().y>-4000){
        playerView.setCenter(400, -3600);
        window->setView(playerView);
        background.setPosition(0,-4000);
        this->showCollectedCoins.setPosition(5,-3995);
        this->showTimeText.setPosition(620,-3995);
    }
    //lvl 7
    if(this->player->getPos().y  <= -4000 && this->player->getPos().y>-4800){
        playerView.setCenter(400, -4400);
        window->setView(playerView);
        background.setPosition(0,-4800);
        this->showCollectedCoins.setPosition(5,-4795);
        this->showTimeText.setPosition(620,-4795);
    }
}

void Game::createBlock(){
    //lvl 1
    blocks.emplace_back(new Block(200,615));
    blocks.emplace_back(new Block(450,495));
    blocks.emplace_back(new Block(190,340));
    blocks.emplace_back(new Block(650,260));
    blocks.emplace_back(new Block(720,260));
    blocks.emplace_back(new Block(430,150));
    blocks.emplace_back(new Block(130,30));
    coins.emplace_back(new Coin(730,210));
    //lvl 2
    blocks.emplace_back(new Block(375,-105));
    blocks.emplace_back(new Block(555,-260));
    blocks.emplace_back(new Block(150,-300));
    blocks.emplace_back(new Block(410,-500));
    blocks.emplace_back(new Block(150,-700));
    blocks.emplace_back(new Block(530,-750));
    coins.emplace_back(new Coin(570,-305));
    //lvl 3
    blocks.emplace_back(new Block(725,-910));
    blocks.emplace_back(new Block(570,-1060));
    blocks.emplace_back(new Block(340,-1140));
    blocks.emplace_back(new Block(80,-1265));
    blocks.emplace_back(new Block(290,-1440));
    blocks.emplace_back(new Block(555,-1540));
    //lvl 4
    blocks.emplace_back(new Block(300,-1700));
    blocks.emplace_back(new Block(600,-1825));
    blocks.emplace_back(new Block(300,-2000));
    blocks.emplace_back(new Block(695,-2125));
    blocks.emplace_back(new Block(155,-2185));
    blocks.emplace_back(new Block(500,-2300));
    blocks.emplace_back(new Block(0,-2330));
    coins.emplace_back(new Coin(715,-2170));
    //lvl 5
    blocks.emplace_back(new Block(155,-2520));
    blocks.emplace_back(new Block(0,-2665));
    blocks.emplace_back(new Block(675,-2645));
    blocks.emplace_back(new Block(140,-2835));
    blocks.emplace_back(new Block(340,-3020));
    blocks.emplace_back(new Block(60,-3110));
    coins.emplace_back(new Coin(695,-2690));
    //lvl 6
    blocks.emplace_back(new Block(300,-3300));
    blocks.emplace_back(new Block(550,-3500));
    blocks.emplace_back(new Block(15,-3580));
    blocks.emplace_back(new Block(295,-3600));
    blocks.emplace_back(new Block(565,-3765));
    blocks.emplace_back(new Block(330,-3895));
    coins.emplace_back(new Coin(35,-3625));
    //lvl 7
    blocks.emplace_back(new Block(80,-4100));
    blocks.emplace_back(new Block(115,-4305));
    blocks.emplace_back(new Block(300,-4490));
    blocks.emplace_back(new Block(375,-4490));
    blocks.emplace_back(new Block(450,-4490));
    blocks.emplace_back(new Block(525,-4490));
    blocks.emplace_back(new Block(600,-4490));
    blocks.emplace_back(new Block(675,-4490));

}
void Game::blockCollision(){
    this->player->isJumping = true;

    for(auto& el : ground){
        if(this->player->getPos().y+ this->player->getBounds().height>=el->getPos().y){
            this->player->sprite.setPosition(this->player->getPos().x, el->getPos().y- this->player->getBounds().height);
            this->player->isJumping  = false;

        }
    }

    for(auto& el : blocks){
        if(el->getBounds().intersects(this->player->getBounds())) this->isPlayerTouchingBlock = true;
        else this->isPlayerTouchingBlock = false;

        if(isCollidingUp(el) && !isCollidingLeft(el) && !isCollidingRight(el)){
            this->player->sprite.setPosition(this->player->getPos().x, el->getPos().y- this->player->getBounds().height);
            this->player->isJumping  = false;
            this->player->velocityY = 0;
        }
        else if(isCollidingDown(el)){
            this->player->sprite.setPosition(this->player->getPos().x, el->getPos().y+  el->getBounds().height);
            this->player->velocityY = 0;
        }
        else if(isCollidingLeft(el) || isCollidingRight(el)){
            this->player->velocityX *= -0.5;
        }

    }
}

void Game::coinCollision(){
    for(auto& el : coins){
        if(el->getBounds().intersects(this->player->getBounds()) && el->isTouched==false){
            //delete el;
            this->collectedCoins++;
            el->isTouched = true;
            std::cout << collectedCoins<< " ";
        }
    }
    if(this->przepis->getBounds().intersects(this->player->getBounds())){
        this->endGame = true;
        this->endGameScreen();
    }
}
void Game::showPoints(){
    if(!this->font.loadFromFile("assety/Arial.ttf")){
        std::cout<<"nie udalo sie zaladowac fonta"<<"\n";
    }
    this->showCollectedCoins.setFont(this->font);
    this->showCollectedCoins.setCharacterSize(40);
    this->showCollectedCoins.setFillColor(sf::Color::Black);
    this->showCollectedCoins.setString(std::to_string(this->collectedCoins)+"/5");

}
//czas
void Game::showTime(){
    if(!this->font.loadFromFile("assety/Arial.ttf")){
        std::cout<<"nie udalo sie zaladowac fonta"<<"\n";
    }
    this->showTimeText.setFont(this->font);
    this->showTimeText.setCharacterSize(40);
    this->showTimeText.setFillColor(sf::Color::Black);
    this->showTimeText.setString(std::to_string(static_cast<int>(this->timer.asSeconds()))+" s");

}

void Game::measureTime(){
    this->timer  = clock.getElapsedTime();
  // std::cout << this->timer.asSeconds()<< " ";

   this->showTime();
}
void Game::initBackground(){
        if(!this->backgroundTex.loadFromFile("assety/sky_background.png")){
                std::cout << "nie udalo sie zaladowac obrazu";
           }
        this->background.setTexture(this->backgroundTex);
}
//koniec gry
void Game::endGameScreen(){
    gameOver.setSize(sf::Vector2f(400,350));
    gameOver.setFillColor(color);
    gameOver.setPosition(200,-4600);

    this->endGameText.setFont(this->font);
    this->endGameText.setCharacterSize(40);
    this->endGameText.setFillColor(sf::Color::White);
    this->endGameText.setString("Zdobyles Przepis!!!\n\nCzas: "+std::to_string(static_cast<int>(this->timer.asSeconds()))+" s\n\nMonety: "+std::to_string(this->collectedCoins)+"/5");
    this->endGameText.setPosition(250,-4550);

}

//kolizja
bool Game::isCollidingUp(Block* el){
    return (this->player->getPos().y+ this->player->getBounds().height>=el->getPos().y &&  this->player->velocityY>0 && this->isPlayerTouchingBlock);//&& this->player->getPos().y+ this->player->getBounds().height<=el->getPos().y+20
}

bool Game::isCollidingDown(Block* el){
    return (this->player->getPos().y <= el->getPos().y + el->getBounds().height && this->player->getPos().y >= el->getPos().y-15 + el->getBounds().height && this->isPlayerTouchingBlock &&  this->player->velocityY<0);
}
bool Game::isCollidingRight(Block* el){
    return (this->player->getPos().x <= el->getPos().x + el->getBounds().width && this->player->getPos().x >= el->getPos().x + el->getBounds().width-10 && this->isPlayerTouchingBlock && this->player->velocityX<0);
}
bool Game::isCollidingLeft(Block* el){
    return (this->player->getPos().x + this->player->getBounds().width >= el->getPos().x && this->player->getPos().x + this->player->getBounds().width <= el->getPos().x+10 && this->isPlayerTouchingBlock&& this->player->velocityX>0);
}
