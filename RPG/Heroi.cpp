//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#include "Heroi.h"
#include "Arma.h"
#include "Pocao.h"
#include <iostream>

Heroi::Heroi(string nome, int vidaMaxima)
    : nome(nome), pontosVida(vidaMaxima), pontosVidaMaxima(vidaMaxima), quantidadeItensCinto(0), topoMochila(-1) {
    // Adicionar a Espada de Madeira ao cinto do heroi
    adicionarAoCinto(new EspadaMadeira());
}

string Heroi::getNome() const {
    return nome;
}

int Heroi::getPontosVida() const {
    return pontosVida;
}

void Heroi::receberDano(int dano) {
    pontosVida -= dano;
    if (pontosVida < 0) {
        pontosVida = 0;
    }
    cout << nome << " recebeu " << dano << " de dano. Vida atual: " << pontosVida << endl;
}

void Heroi::recuperarVida(int quantidade) {
    pontosVida += quantidade;
    if (pontosVida > pontosVidaMaxima) {
        pontosVida = pontosVidaMaxima;
    }
    cout << nome << " recuperou " << quantidade << " pontos de vida. Vida atual: " << pontosVida << endl;
}

int Heroi::getQuantidadeItensCinto() const {
    return quantidadeItensCinto;
}

void Heroi::adicionarAoCinto(Item* item) {
    if (quantidadeItensCinto < MAX_CINTO) {
        cinto[quantidadeItensCinto++] = item;
        cout << "Item adicionado ao cinto: " << item->getNome() << endl;
    } else {
        cout << "Cinto esta cheio!" << endl;
    }
}

void Heroi::adicionarNaMochila(Item* item) {
    if (topoMochila < MAX_MOCHILA - 1) {
        mochila[++topoMochila] = item;
        cout << "Item adicionado a mochila: " << item->getNome() << endl;
    } else {
        cout << "Mochila esta cheia!" << endl;
    }
}

void Heroi::usarItemCinto(int indice, Inimigo& inimigo) {
    if (indice >= 0 && indice < quantidadeItensCinto) {
        Item* item = cinto[indice];
        item->usar(*this, inimigo);  // Usa o item (pode ser uma arma ou uma poção)

        // Se for uma poção (ou qualquer outro item consumível), remove-a do cinto após o uso
        if (dynamic_cast<Pocao*>(item) != nullptr) {
            for (int i = indice; i < quantidadeItensCinto - 1; ++i) {
                cinto[i] = cinto[i + 1];
            }
            cinto[--quantidadeItensCinto] = nullptr;
        }
    } else {
        cout << "Indice invalido!" << endl;
    }
}

void Heroi::usarItemCinto(int indice) {
    if (indice >= 0 && indice < quantidadeItensCinto) {
        Item* item = cinto[indice];
        item->usar(*this);  // Usa o item (geralmente uma poção)

        // Se for uma poção, remove-a do cinto após o uso
        if (dynamic_cast<Pocao*>(item) != nullptr) {
            for (int i = indice; i < quantidadeItensCinto - 1; ++i) {
                cinto[i] = cinto[i + 1];
            }
            cinto[--quantidadeItensCinto] = nullptr;
        }
    } else {
        cout << "Indice invalido!" << endl;
    }
}

void Heroi::usarItemMochila() {
    if (topoMochila >= 0) {
        Item* item = mochila[topoMochila];
        item->usar(*this);  // Usa o item (sem inimigo)
        mochila[topoMochila--] = nullptr;  // Remove o item do topo da mochila após o uso
    } else {
        cout << "Mochila esta vazia!" << endl;
    }
}

void Heroi::descartarItemCinto(int indice) {
    if (indice >= 0 && indice < quantidadeItensCinto) {
        delete cinto[indice];
        for (int i = indice; i < quantidadeItensCinto - 1; ++i) {
            cinto[i] = cinto[i + 1];
        }
        cinto[--quantidadeItensCinto] = nullptr;
        cout << "Item descartado do cinto." << endl;
    } else {
        cout << "Indice invalido!" << endl;
    }
}

void Heroi::descartarItemMochila() {
    if (topoMochila >= 0) {
        delete mochila[topoMochila];
        mochila[topoMochila--] = nullptr;
        cout << "Item descartado da mochila." << endl;
    } else {
        cout << "Mochila esta vazia!" << endl;
    }
}

void Heroi::mostrarInventario() const {
    cout << "Cinto: ";
    for (int i = 0; i < quantidadeItensCinto; ++i) {
        cout << cinto[i]->getNome() << " ";
    }
    cout << endl;

    cout << "Mochila: ";
    for (int i = 0; i <= topoMochila; ++i) {
        cout << mochila[i]->getNome() << " ";
    }
    cout << endl;
}
