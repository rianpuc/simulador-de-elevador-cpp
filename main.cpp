#include <iostream>

class Elevador{
    private:
        unsigned short andarAtual;
        unsigned short contagemPessoas;
        unsigned short andares;
        unsigned short capacidade;
    public:
        Elevador(unsigned short andarAtual, unsigned short contagemPessoas, unsigned short andares, unsigned short capacidade):
        andarAtual(andarAtual), contagemPessoas(contagemPessoas), andares(andares), capacidade(capacidade){}

        ~Elevador() = default;

        unsigned short getAndar(){
            return andarAtual;
        }
        unsigned short getAndares(){
            return andares;
        }
        unsigned short getPessoas(){
            return contagemPessoas;
        }
        unsigned short getCapacidade(){
            return capacidade;
        }
        void addPessoa(){
            contagemPessoas++;
        }
        void rmvPessoa(){
            contagemPessoas--;
        }
        void sobeAndar(){
            andarAtual++;
        }
        void desceAndar(){
            andarAtual--;
        }
};

int main();

void jogo(Elevador elevador){
    int escolha;
    system("cls");
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
    std::cout << "Bem vindo ao simulador de elevador" << std::endl;
    std::cout << "Andar atual: " << elevador.getAndar() << " Pessoas no elevador: " << elevador.getPessoas() << std::endl;
    std::cout << "[1] - Adicionar uma pessoa" << std::endl;
    std::cout << "[2] - Remover uma pessoa" << std::endl;
    std::cout << "[3] - Subir um andar" << std::endl;
    std::cout << "[4] - Descer um andar" << std::endl;
    std::cout << "[5] - Alterar o elevador" << std::endl;
    std::cout << "[0] - Sair do jogo" << std::endl;
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
    std::cin >> escolha;
    switch (escolha){
        case 1:
            if(elevador.getPessoas() + 1 <= elevador.getCapacidade())
                elevador.addPessoa();
            jogo(elevador);
            break;
        case 2:
            if(elevador.getPessoas() != 0)
                elevador.rmvPessoa();
            jogo(elevador);
            break;
        case 3:
            if(elevador.getAndar() + 1 <= elevador.getAndares())
                elevador.sobeAndar();
            jogo(elevador);
            break;
        case 4:
            if(elevador.getAndar() != 0)
                elevador.desceAndar();
            jogo(elevador);
            break;
        case 5:
            main();
            break;
        case 0:
            break;
        default:
            jogo(elevador);
            break;
    }
}

int main(void){
    unsigned short andares, capacidade;
    std::cout << "Digite o numero de andares: ";
    std::cin >> andares;
    std::cout << "Digite a capacidade do elevador: ";
    std::cin >> capacidade;
    Elevador elevador(0, 0, andares, capacidade);
    jogo(elevador);
}
