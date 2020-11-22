#include "arvoreavl.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main() {
	Arvore arv;
	int reproc = 0;

  //Recebe todos os dados
  vector<string> lista;
  string line;
  ifstream myfile ("tweets.txt"); // ifstream = padrão ios:in
  if (myfile.is_open()) {
    while (!myfile.eof()){ //enquanto end of file for false continua
      getline (myfile,line); // como foi aberto em modo texto(padrão)
                             //e não binário(ios::bin) pega cada linha
      //cout << line << endl;
      lista.push_back(line);
    }
    myfile.close();
  }

  vector<string> listaNome;
  vector<int> listaFrequencia;
  list<string> listaOrdenadaNome;

  //Inserindo informações
  for(int x=0; x <= lista.size(); x++){
    if( x % 2 == 0){
      listaNome.push_back(lista[x]);
      listaOrdenadaNome.push_back(lista[x]);
    }
    else{
      listaFrequencia.push_back(stoi(lista[x]));
    }    
  }

  high_resolution_clock::time_point horarioInicionInsercao = high_resolution_clock::now();
  for(int z=0 ; z < listaNome.size(); z++){
    string nome_novo = listaNome[z];
    int frequencia_novo = listaFrequencia[z];
    arv.insere(nome_novo, frequencia_novo);
  }

	arv.balancea(); //Balancear a arvore
  high_resolution_clock::time_point horarioFimInsercao = high_resolution_clock::now();
  duration<double, std::milli> tempoDeExecucao = horarioFimInsercao - horarioInicionInsercao;

  cout << "\nOrdem Alfabética: \n";
  listaOrdenadaNome.sort();
  arv.emOrdemA(arv.getRaiz());
  arv.exEmOrdemA(listaOrdenadaNome);

	cout << "\nTrending Topics: \n";
	arv.emOrdem(arv.getRaiz());

  cout << endl;
  cout << "Quantidade de comparações: " << arv.getQuantidadeComparacoes() << endl;
  cout << "Tempo de execução: " << tempoDeExecucao.count() << endl;

	return 0;
}

