//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#include "Mapa.h"
#include "Arma.h"
#include "Pocao.h"
#include "Inimigo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Construtor que inicializa o caminho com um determinado tamanho e nível
Mapa::Mapa(int tamanhoCaminho, int nivelAtual)
    : tamanhoCaminho(tamanhoCaminho), nivelAtual(nivelAtual) {  // Inicializando nivelAtual aqui
    // Aloca o array unidimensional que representa o caminho do nível
    caminho = new Celula[tamanhoCaminho];
    for (int i = 0; i < tamanhoCaminho; ++i) {
        // Inicializa cada célula do caminho como vazia
        caminho[i].item = nullptr;
        caminho[i].inimigo = nullptr;
    }
}

// Destrutor que libera a memória alocada para o caminho
Mapa::~Mapa() {
    delete[] caminho;
}

// Gera o mapa populando o caminho com itens e inimigos
void Mapa::gerarMapa() {
    srand(time(0));  // Semente para geração aleatória

    // Percorre cada célula no caminho
    for (int i = 0; i < tamanhoCaminho; ++i) {
        int chance = rand() % 100;

        if (i == tamanhoCaminho - 1) {
            // A última célula sempre terá um Boss dependendo do nível
            switch (nivelAtual) {
                case 1:
                    caminho[i].inimigo = new Dragao();  // Nível 1: Dragão
                    break;
                case 2:
                    caminho[i].inimigo = new ReiEsqueleto();  // Nível 2: Rei Esqueleto
                    break;
                case 3:
                    caminho[i].inimigo = new SlimeGigante();  // Nível 3: Slime Gigante
                    break;
                case 4:
                    caminho[i].inimigo = new LordeMorcego();  // Nível 4: Lorde Morcego
                    break;
                case 5:
                    caminho[i].inimigo = new LichKing();  // Nível 5: Lich King
                    break;
                case 6:
                    caminho[i].inimigo = new DarkKnight();  // Nível 6: Dark Knight
                    break;
                default:
                    caminho[i].inimigo = new Dragao();  // Padrão: Dragão
                    break;
            }
        } else if (caminho[i].item == nullptr && caminho[i].inimigo == nullptr) {
            // Gera o item ou inimigo apenas se a célula estiver vazia
            // Probabilidades de gerar diferentes itens ou inimigos
            if (chance < 5) {
                caminho[i].item = new BladeOfTheEternalFlame();  // 5% de chance de uma Espada
            } else if (chance < 10) {
                caminho[i].item = new ShadowReaver();  // 5% de chance de um Machado
            } else if (chance < 15) {
                caminho[i].item = new DragonsBane();  // 5% de chance de um Arco
            } else if (chance < 25) {
                caminho[i].item = new ElixirOfRenewal();  // 10% de chance de uma Poção de Vida
            } else if (chance < 35) {
                caminho[i].item = new TearsOfThePhoenix();  // 10% de chance de uma Poção de Mana
            } else if (chance < 45) {
                caminho[i].item = new WarriorsRespite();  // 10% de chance de uma Poção de Força
            } else if (chance < 60) {
                caminho[i].inimigo = new Goblin();  // 15% de chance de um Goblin
            } else if (chance < 75) {
                caminho[i].inimigo = new Orc();  // 15% de chance de um Orc
            } else if (chance < 85) {
                caminho[i].inimigo = new Esqueleto();  // 10% de chance de um Esqueleto
            } else if (chance < 95) {
                caminho[i].inimigo = new Slime();  // 10% de chance de um Slime
            } else {
                caminho[i].inimigo = new Morcego();  // 5% de chance de um Morcego
            }
        }
    }
}

// Mostra o caminho, com a posição atual do jogador destacada
void Mapa::mostrarMapa(int posicaoJogador) const {
    for (int i = 0; i < tamanhoCaminho; ++i) {
        if (i == posicaoJogador) {
            cout << "P ";  // Posição do jogador
        } else if (caminho[i].inimigo != nullptr) {
            cout << "I ";  // Inimigo presente na célula
        } else if (caminho[i].item != nullptr) {
            cout << "E ";  // Item presente na célula
        } else {
            cout << ". ";  // Célula vazia
        }
    }
    cout << endl;
}

// Retorna um ponteiro para a célula atual onde o jogador está
Mapa::Celula* Mapa::obterCelulaAtual(int posicaoJogador) {
    if (posicaoJogador >= 0 && posicaoJogador < tamanhoCaminho) {
        return &caminho[posicaoJogador];
    }
    return nullptr;
}
