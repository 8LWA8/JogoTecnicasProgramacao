#pragma once

//Código inspirado nos vídeos do monitor Matheus Augusto Burda (Burda Canal no youtube)
namespace Estados
{
	class MaquinaEstados;

    enum IDestado {
        desconhecido = -1,
        menuPrincipal = 0,
        novoJogo,
        Jogando,
        menuPausa,
        //config,
        ranking
        //salvar
    };

	class Estado
	{
    protected:
        MaquinaEstados* pME;
        IDestado id;

    public:
        Estado(MaquinaEstados* pME = nullptr, IDestado id = desconhecido);

        virtual ~Estado();

        void setMaquinaEstados(MaquinaEstados* pME);

        void mudarEstado(IDestado id);

        IDestado getID() const;

        virtual void update(const float dt) = 0;

        virtual void render() = 0;

        virtual void resetEstado() = 0;
	};
}
