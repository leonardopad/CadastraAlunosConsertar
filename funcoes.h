#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Estrutura de Alunos
struct Aluno {
	std::string nome;
	std::string matricula;
	float aep1;
	float prova1;
	float aep2;
	float prova2;
	float sub;
	float media;
	std::string status;
} typedef Aluno;

/**
* Esta função é chamada para exibir o menu
* na tela do usuário e retornar a opção
* selecionada
* retorna o char digitada pelo usuário
*/
char menu ();
Aluno alunos[100];

/**
* Esta função é chamada para permitir
* o cadastro de um Aluno, retorna
* true caso o cadastro tenha ocorrido com sucesso
* ou false caso acontecer um problema
*/
bool cadastraAluno (Aluno);

void perguntaAluno(Aluno);
/* nessa funcao se espera true or false na leitura do arquivo*/
bool realizaLeituraAprovados();
//Funcao que cria lista de aprovados
