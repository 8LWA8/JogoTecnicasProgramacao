#include "Jogador1.h"


using namespace Entidades::Personagens;

Jogador1::Jogador1() 
{
    this->setId(1);
    this->setTextura("assets\\textures\\astronauta.png");
        
    /*if (MyReadFile)
        {
            
            while (getline(MyReadFile, text)) 
            {
                float vid = std::stof(text);
                if (vid>0)
                this->setNumVidas(vid);
                int pont = std::stoi(text);
                this->setPontuacao(pont);
                std::cout << text << std::endl;
                
                /*
                getline(MyReadFile, text);
                
                this->setPontuacao(pont);
                getline(MyReadFile, text);
                float x = std::stof(text);
                getline(MyReadFile, text);
                float y = std::stof(text);

                this->getCorpo()->setPosition(sf::Vector2f(x, y));
                
            }
        }*/
    
}

void Jogador1::mover()
{
    if (mov == true)
    {
        

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (coll.getX() != 1.0))
        {
            corpo.move(sf::Vector2f(vel.getX(), 0.f));
            coordenada.addX(vel.getX());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (coll.getX() != -1.0))
        {
            corpo.move(sf::Vector2f(-vel.getX(), 0.f));
            coordenada.addX(-vel.getY());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (coll.getY() != 0.0))
        {
            //TESTE
            corpo.move(sf::Vector2f(0.f, -150 * vel.getY()));
            coordenada.addY(-150 * vel.getY());

        }
        else
        {
            sofrer_gravidade();
        }
    }

}



