#include "Itens/Item.h"

Item::Item(const std::string& nome, char simbolo, int valor) : nome(nome), simbolo(simbolo), valor(valor), instanteChegada(-1) {}

Item::~Item() {}

std::string Item::obterNome() const {return nome;}
char Item::obterSimbolo() const {return simbolo;}
int Item::obterValor() const {return valor;}
int Item::obterInstanteChegada() const {return instanteChegada;}

void Item::marcarChegada(int instante) {instanteChegada = instante;}

Item* Item::transformar() const {return nullptr;}