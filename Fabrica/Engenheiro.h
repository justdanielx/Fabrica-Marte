#pragma once

#include <string>

class Maquina;

class Engenheiro {
    public:
        Engenheiro(const std::string& nome);

        int obterId() const;
        std::string obterNome() const;
        bool estaLivre() const;
        const Maquina* obterMaquina() const;

        void atribuir(Maquina* maquina);
        void libertar();

    private:
        inline static int proximoId = 1;

        int id;
        std::string nome;
        Maquina* maquina;
};
