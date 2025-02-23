//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#ifndef HEROI_H
#define HEROI_H

#include <string>
#include "Item.h"

using namespace std;

class Heroi {
private:
    string nome;
    int pontosVida;
    int pontosVidaMaxima;

    static const int MAX_CINTO = 5;  // Limite de itens no cinto
    Item* cinto[MAX_CINTO];  // Array fixo para o cinto
    int quantidadeItensCinto;

    static const int MAX_MOCHILA = 10;  // Limite de itens na mochila
    Item* mochila[MAX_MOCHILA];  // Array fixo para a mochila
    int topoMochila;

public:
    Heroi(std::string nome, int vidaMaxima);

    string getNome() const;
    int getPontosVida() const;
    void receberDano(int dano);
    void recuperarVida(int quantidade);  // Método para recuperar vida

    int getQuantidadeItensCinto() const;  // Método para obter a quantidade de itens no cinto

    void adicionarAoCinto(Item* item);
    void adicionarNaMochila(Item* item);
    void usarItemCinto(int indice, Inimigo& inimigo);  // Método atualizado para usar item com inimigo
    void usarItemCinto(int indice);  // Método para usar item sem inimigo
    void usarItemMochila();  // Método para usar item da mochila
    void descartarItemCinto(int indice);  // Método para descartar item do cinto
    void descartarItemMochila();  // Método para descartar item da mochila
    void mostrarInventario() const;
};

#endif
