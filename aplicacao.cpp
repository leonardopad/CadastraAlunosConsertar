#include "funcoes.cpp"

int main () {
	char opcao = ' ';
	int QTSALUNOS = 1;
	char continuar = ' ';
	Aluno aluno[100];
	do {
	   opcao = menu();
	   switch (opcao) {
	   		case 'C':
	   			for(int i = 0; i <= QTSALUNOS; i++){
	   					perguntaAluno(aluno[i]);
				    std:: cout << "Deseja continuar?\nDigite S para sim e N para nao!\n";
					std:: cin >> continuar;
					if(continuar == 'S'){
						QTSALUNOS++;
					}else if(continuar == 'N'){
						break;
					}else{
						std:: cout << "Digite uma opcao valida!";
					}
				   }
	   		break;
	   		case 'F':
	   			std::cout << "Finalizando aplicacao...\n";
	   		break;
	   		case 'L':
	   			realizaLeituraAprovados();
	   			break;
	   		default:
	   			std::cout << "Opcao invalida\n Tente Novamente!\n";
	   }
	} while(opcao != 'F');
}
