//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#ifndef MAPA_H
#define MAPA_H

#include "Item.h"
#include "Inimigo.h"

class Mapa {
public:
    struct Celula {
        Item* item;
        Inimigo* inimigo;
    };

private:
    int tamanhoCaminho;  // Tamanho do caminho (número de células no caminho)
    int nivelAtual;       // Nível atual
    Celula* caminho;      // Ponteiro para um array que representa o caminho

public:
    Mapa(int tamanhoCaminho, int nivelAtual); // Construtor que recebe o tamanho do caminho e o nível atual
    ~Mapa();

    void gerarMapa();
    void mostrarMapa(int posicaoJogador) const;
    Celula* obterCelulaAtual(int posicaoJogador);
};

#endif
