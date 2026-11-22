#pragma once

#include <string>

class Item;
class Fabrica;

class Maquina {
    public:
        Maquina(int custo, char direcao);
        Maquina(const Maquina& outra);
        virtual ~Maquina();

        static Maquina* criar(char tipo, char direcao);
        static bool direcaoValida(char direcao);

        virtual void atuar(Fabrica& fabrica, int linha, int coluna) = 0;
        virtual bool aceitarItem(Item* novo) = 0;
        virtual bool melhorar();
        virtual int obterCustoMelhoria() const;
        virtual char obterSimbolo() const = 0;
        virtual std::string obterTipo() const = 0;
        virtual std::string obterResumo() const = 0;
        virtual std::string obterDescricao() const = 0;
        virtual Maquina* duplicar() const = 0;

        int obterCusto() const;
        char obterDirecao() const;
        bool rodar(char novaDirecao);

        int obterEngenheiros() const;
        void adicionarEngenheiro();
        void removerEngenheiro();

    protected:
        Maquina& operator=(const Maquina& outra);

        int duracaoComEngenheiros(int duracaoBase) const;
        std::string descricaoBase() const;

    private:
        int custo;
        char direcao;
        int engenheiros;
};