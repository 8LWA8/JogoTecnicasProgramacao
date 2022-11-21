#include "Estado.h"
#include "IDs.h"
#include "MaquinaEstados.h"

using namespace Estados;

//Código inspirado nos vídeos do monitor Giovane (Gege++ no youtube) e no seu Github (https://github.com/Giovanenero/JogoPlataforma2D-Jungle)



Estado::Estado(): remover(false)
{
}

Estado::~Estado() {

}

//void Estado::desenhar() {
//
//}

void Estado::setRemover(const bool remover) {
    this->remover = remover;
}

const bool Estado::getRemover() const {
    return remover;
}