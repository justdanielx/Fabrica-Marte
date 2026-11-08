#pragma once

class Settings {
    public:
        inline static const int ecra_max_linhas = 40;
        inline static const int ecra_max_colunas = 80;

        inline static const int fabrica_max_linhas = 26;
        inline static const int fabrica_max_colunas = 26;
        inline static const int fabrica_creditos_iniciais = 1000;

        inline static const int fabrica_num_crateras = 5;
        inline static const int fabrica_num_depositos_ferro = 8;
        inline static const int fabrica_num_depositos_silicio = 6;
        inline static const int fabrica_num_depositos_gelo = 6;

        inline static const int deposito_quantidade_min = 40;
        inline static const int deposito_quantidade_max = 60;

        inline static const int maquina_percentagem_venda = 50;
        inline static const int maquina_duracao_minima = 1;

        inline static const int perfuradora_custo = 100;
        inline static const int perfuradora_periodo = 3;
        inline static const int perfuradora_capacidade = 1;
        inline static const int perfuradora_prob_perda = 40;
        inline static const int perfuradora_melhoria_reducao_prob = 10;
        inline static const int perfuradora_melhoria_custo = 15;

        inline static const int transportador_custo = 5;
        inline static const int transportador_capacidade = 1;

        inline static const int refinaria_custo = 150;
        inline static const int refinaria_duracao = 4;

        inline static const int oficina_custo = 200;
        inline static const int oficina_duracao = 5;
        inline static const int oficina_receita_placas_ferro = 2;
        inline static const int oficina_receita_silicio_puro = 1;
        inline static const int oficina_receita_agua = 1;
        inline static const int oficina_receita_kits_produzidos = 1;
        inline static const int oficina_melhoria_reducao_duracao = 1;
        inline static const int oficina_melhoria_custo = 30;
        inline static const int oficina_melhoria_max = 1;

        inline static const int silo_custo = 120;
        inline static const int silo_prob_perda = 20;
        inline static const int silo_melhoria_reducao_prob = 5;
        inline static const int silo_melhoria_custo = 50;

        inline static const int lancador_custo = 80;
        inline static const int lancador_recarga = 4;
        inline static const int lancador_prob_perda = 30;
        inline static const int lancador_melhoria_reducao_prob = 10;
        inline static const int lancador_melhoria_custo = 25;

        inline static const int engenheiro_custo_contratacao = 50;
        inline static const int engenheiro_salario = 1;
        inline static const int engenheiro_reducao_duracao = 1;

        inline static const int valor_minerio_ferro = 2;
        inline static const int valor_silicio_bruto = 3;
        inline static const int valor_gelo = 1;
        inline static const int valor_placa_ferro = 8;
        inline static const int valor_silicio_puro = 10;
        inline static const int valor_agua = 4;
        inline static const int valor_kit_habitat = 120;
};