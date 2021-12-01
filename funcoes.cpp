#include "funcoes.h"

char menu () {
	char escolha = ' ';
	std::cout << "\n==SELECIONE UMA OPCAO ABAIXO==";
	std::cout << "\n=========DIGITE A LETRA=======";
	std::cout << "\n========== C - Cadastra Aluno===========";
	std::cout << "\n========== L - Ler o Arquivo de Alunos Aprovados===========";
	std::cout << "\n========== A - Criar arquivo com alunos aprovados===========";
	std::cout << "\n==========F - FINALIZA========\n";
	std::cin >> escolha;
	system("cls");
	return escolha;
}
bool criaArquivoDP1 (Aluno aluno){
	std::ofstream arquivo4;
	arquivo4.open("DepedenciaSegundoSemestre.csv", std::fstream::app);

	if(!arquivo4.is_open()){
		std:: cout << "Houve um erro ao abrir o arquivo de criacao da tabela de aprovados";
		return false;
	}

	arquivo4 << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << "\n";
			arquivo4.close();
			return true;

}
bool criaArquivoDP2 (Aluno aluno){
	std::ofstream arquivo5;
	arquivo5.open("DepedenciaPrimeiroSemestre.csv", std::fstream::app);

	if(!arquivo5.is_open()){
		std:: cout << "Houve um erro ao abrir o arquivo de criacao da tabela de aprovados";
		return false;
	}

	arquivo5 << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << "\n";
			arquivo5.close();
			return true;

}



bool criaArquivoAprovados (Aluno aluno){
	std::ofstream arquivo2;
	arquivo2.open("Aprovados.csv", std::fstream::app);

	if(!arquivo2.is_open()){
		std:: cout << "Houve um erro ao abrir o arquivo de criacao da tabela de aprovados";
		return false;
	}

	arquivo2 << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
			arquivo2.close();
			return true;

}

bool criaArquivoDependencia (Aluno aluno){
	std::ofstream arquivo3;
	arquivo3.open("Dependencia.csv", std::fstream::app);

	if(!arquivo3.is_open()){
		std:: cout << "Houve um erro ao abrir o arquivo de criacao da tabela de aprovados";
		return false;
	}

	arquivo3 << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
			arquivo3.close();
			return true;
}

bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.csv", std::fstream::app);

	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;
	}

	arquivo << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";

	arquivo.close();
	return true;
}

void perguntaAluno(Aluno aluno){
	std:: cin.get();//limpar o buffer
	std:: cout << "Digite o nome do aluno: \n";
//	std::getline (std::cin, aluno.nome);
	std:: getline(std::cin, aluno.nome);
	std:: cout << "Digite a matricula do aluno: \n";
	std:: cin >> aluno.matricula;
	std:: cout << "Digite a aep do aluno: \n";
	std:: cin >> aluno.aep1;
	std:: cout << "Digite a prova do primeiro semestre do aluno: \n";
	std:: cin >> aluno.prova1;
	std:: cout << "Digite a aep do segundo semestre do aluno: \n";
	std:: cin >> aluno.aep2;
	std:: cout << "Digite a prova do segundo semestre do aluno: \n";
	std:: cin >> aluno.prova2;
	aluno.media = ((aluno.aep1 + aluno.prova1)/2) + ((aluno.aep2 + aluno.prova2)/2);
	if (aluno.media < 6){
		std:: cout << "Digite a nota da substitutiva: \n";
		std:: cin >> aluno.sub;
	}else if(aluno.media >= 6){
		aluno.sub = 0;
		aluno.status = "Aprovado";
	}
	if(aluno.media < 6){
		if ((aluno.prova1 + aluno.aep1) > (aluno.prova2 + aluno.aep2)){
			criaArquivoDP2(aluno);
			aluno.media =((aluno.aep1 + aluno.prova1)/2) + ((aluno.sub + aluno.prova2)/2);
		}else if((aluno.prova2 + aluno.aep2) > (aluno.prova1 + aluno.aep1)){
			aluno.media = ((aluno.sub + aluno.prova1)/2) + ((aluno.aep2 + aluno.prova2)/2);
			criaArquivoDP1(aluno);
		}else if((aluno.prova1 + aluno.aep1)  == (aluno.prova2 + aluno.aep2)){
			aluno.media =((aluno.aep1 + aluno.sub)/2) + ((aluno.sub + aluno.prova2)/2);
			criaArquivoDP1(aluno);
		}
	if(aluno.media >= 6){
		aluno.status = "Aprovado";
	}else {
		aluno.status = "Em dependecia";
	}
	}
	if(aluno.status == "Aprovado"){
		criaArquivoAprovados(aluno);
	}else if (aluno.status == "Em dependencia") {
		criaArquivoDependencia(aluno);
	}

	//Cria o Arquivo
	if (cadastraAluno(aluno)){
		std::cout << "Aluno cadastrado\n";
	} else {
		std::cout << "Erro ao cadastrar aluno teste\n";
	}
}

bool realizaLeitura () {
	std::ifstream arquivo;
	arquivo.open("database.csv");

	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!";
		return false;
	}

	std::string linha;
	int indexAluno = 0;
	while (std::getline(arquivo, linha)) {
		int coluna = 0;
		int controleColuna = 0;
		std::string conteudo = "";
		for (int i = 0; i < linha.size(); i++) {
			if (coluna == 1 && controleColuna == 0)  {
				alunos[indexAluno].nome = conteudo;
				conteudo = "";
				controleColuna = 1;
			} else if (coluna == 2 && controleColuna == 1) {
				alunos[indexAluno].matricula = conteudo;
				conteudo = "";
				controleColuna = 2;
			} else if (coluna == 3 && controleColuna == 2) {
				alunos[indexAluno].aep1 = std::stof(conteudo);
				conteudo = "";
				controleColuna = 3;
			} else if (coluna == 4 && controleColuna == 3) {
				alunos[indexAluno].prova1 = std::stof(conteudo);
				conteudo = "";
				controleColuna = 4;
			} else if (coluna == 5 && controleColuna == 4) {
				alunos[indexAluno].aep2 = std::stof(conteudo);
				conteudo = "";
				controleColuna = 5;
			} else if (coluna == 6 && controleColuna == 5) {
				alunos[indexAluno].prova2 = std::stof(conteudo);
				conteudo = "";
				controleColuna = 6;
			} else if (coluna == 7 && controleColuna == 6) {
				alunos[indexAluno].sub = std::stof(conteudo);
				conteudo = "";
				controleColuna = 7;
			} else if (coluna == 8 && controleColuna == 7) {
				alunos[indexAluno].media = std::stof(conteudo);
				conteudo = "";
				controleColuna = 8;
			} else {
				alunos[indexAluno].status = conteudo;
			}
			if (linha[i] == ';') {
				coluna++;
				continue;
			}
			conteudo.push_back(linha[i]);
		}
		indexAluno++;
	}

	arquivo.close();
	return true;
}

bool realizaLeituraAprovados(){
    std::ifstream arquivo;
	arquivo.open("database.csv");
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!" << std::endl << std::endl;
		return false;
	}


    realizaLeitura();

        for(int i = 0; i <= 100; i++){
        if(alunos[i].status == "Aprovado"){
            std:: cout << "Aluno n-" << i;
            std::cout << "Nome: " << alunos[i].nome;
			std::cout << "Matricula: " << alunos[i].matricula <<"\n";
			std::cout << "Status: " << alunos[i].status << "\n";
			std::cout << "--------------------------------------------";
        }
    }
    arquivo.close();
	return true;
}



