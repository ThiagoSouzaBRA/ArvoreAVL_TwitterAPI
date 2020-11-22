#include <iostream>
#include <string>
using namespace std;
class Node {

	private:

		Node *esq, *dir;
		int valor, profEsq, profDir;
    std::string nome;


        public:

		Node(string nome, int valor) {
			this->valor = valor;
			this->esq = this->dir = NULL;
			this->profEsq = this->profDir = 0;
      this->nome = nome;
      }

		int getValor() {
			return valor;
		}

    string getNome(){
      return nome;
    }

		Node *getEsq() {
			return esq;
		}

		Node *getDir() {
			return dir;
		}

		int getProfEsq() {
			return profEsq;
		}

		int getProfDir() {
			return profDir;
		}


		void setEsq(Node *no) {
			this->esq = no;
		}


		void setDir(Node *no) {
			this->dir = no;
		}


		void incrementaProfEsq() {
			this->profEsq++;
		}


		void incrementaProfDir() {
			this->profDir++;
		}


		int desequilibrio() {
			return this->profDir - this->profEsq;
		}
};