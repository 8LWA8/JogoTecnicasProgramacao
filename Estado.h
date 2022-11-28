#pragma once
#include "Ente.h"
#include "IDs.h"

//Código inspirado nos vídeos do monitor Giovane (Gege++ no youtube) e no seu Github (https://github.com/Giovanenero/JogoPlataforma2D-Jungle)
namespace Estados
{
    class Estado : public Ente {
    private:
        bool remover;
    public:
        Estado();
        ~Estado();
        virtual void executar() = 0;
        //virtual void desenhar();
        void setRemover(const bool remover = true);
        const bool getRemover() const;
    };
}
