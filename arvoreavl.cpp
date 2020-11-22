#include "node.cpp"
#include <list>


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_LENGTH 100

using namespace std;

class Arvore
{

	private:

    /*atributos */
		Node *raiz;
    unsigned quantidadeComparacoes;

		void insereNodeVetor(Node *no) {
			vetorDeInsercao[ponteiroDeInsercao] = no;
			ponteiroDeInsercao++;
		}

		Node *rotacaoAEsquerda(Node *no) {
			Node *subarvoreDireita = no->getDir();
			no->setDir(subarvoreDireita->getEsq());
			subarvoreDireita->setEsq(no);
			return subarvoreDireita;
		}

		Node *rotacaoADireita(Node *no) {
			Node *subarvoreEsquerda = no->getEsq();
			no->setEsq(subarvoreEsquerda->getDir());
			subarvoreEsquerda->setDir(no);
			return subarvoreEsquerda;
		}

		void insereAux(Node *no, string nome, int valor) {
      quantidadeComparacoes++;
			if(valor <= no->getValor()) {
        quantidadeComparacoes++;
				if(no->getEsq() == NULL) {
					Node *novo_no = new Node(nome,valor);
					no->setEsq(novo_no);
					insereNodeVetor(novo_no);
					no->incrementaProfEsq();
				} else {
					no->incrementaProfEsq();
					insereAux(no->getEsq(), nome, valor);
				}
			} else {
        quantidadeComparacoes++;
				if(no->getDir() == NULL) {
					Node *novo_no = new Node(nome,valor);
					no->setDir(novo_no);
					insereNodeVetor(novo_no);
					no->incrementaProfDir();
				} else {
					no->incrementaProfDir();
					insereAux(no->getDir(), nome, valor);
				}
			}
		}

	public:

    Node *vetorDeInsercao[MAX_LENGTH];
  	int ponteiroDeInsercao;
		
    Arvore() {
			raiz = NULL;
			ponteiroDeInsercao = 0;
		}

		Node *getRaiz() {
			return this->raiz;
		}

    unsigned getQuantidadeComparacoes() {
      return quantidadeComparacoes;
    }

		void insere(string nome, int valor) {
      quantidadeComparacoes++;
			if(raiz == NULL) {
				raiz = new Node(nome,valor);
				insereNodeVetor(raiz);
			} else {
				insereAux(raiz, nome,valor);
			}
		}

		void emOrdem(Node *no) {
			if(no != NULL && no->getNome() != "") {
				emOrdem(no->getEsq());
        cout << no->getNome();
        cout << ": ";
				cout << no->getValor() << endl;
				emOrdem(no->getDir());
			}
		}

    list<string> listaOrdenadaNome;
    vector<string> listaOrdenadaFrequencia;
    void emOrdemA(Node *no) {
			if(no != NULL && no->getNome() != "") {
				emOrdemA(no->getEsq());
        listaOrdenadaNome.push_back(no->getNome());
        listaOrdenadaFrequencia.push_back(to_string(no->getValor()));
				emOrdemA(no->getDir());
			}
		}

    
    void exEmOrdemA(list<string> lista) {
      int j=0 ;
      for (auto const& i: lista) {
        j=0;
        for (auto const& k: listaOrdenadaNome) {
          j++;
          if(i == k){
              cout << i << ": " + listaOrdenadaFrequencia[j-1] + "\n";
            }
          }
        }
    }

    list<string> getListaOrdenadaNome(){
      return listaOrdenadaNome;
    }

		void mostraVetorDeInsercao() {
			int i;
			for(i = 0; i < ponteiroDeInsercao; i++) {
				cout << ("\n\n");
				cout << "[" << i << "]: Node " << vetorDeInsercao[i]->getValor();
				cout << "\nProfundidade esq: " << vetorDeInsercao[i]->getProfEsq();
				cout << "\nProfundidade dir: " << vetorDeInsercao[i]->getProfDir();
				cout << "\nDesequilibro: " << vetorDeInsercao[i]->desequilibrio();
			}
		}

		void balancea() {
			int i;
			for(i = 0; i < this->ponteiroDeInsercao; i++) {
        quantidadeComparacoes++;
				if(this->vetorDeInsercao[i]->desequilibrio() >= 2) {
					this->vetorDeInsercao[i] = this->rotacaoAEsquerda(this->vetorDeInsercao[i]);
				}
				else if(this->vetorDeInsercao[i]->desequilibrio() <= -2) {
					quantidadeComparacoes++;
          this->vetorDeInsercao[i] = this->rotacaoADireita(this->vetorDeInsercao[i]);
				}
			}
		}

};
