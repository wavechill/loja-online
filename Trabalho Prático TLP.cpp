#include <iostream>
#include <queue>
#include <locale>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
using namespace std;

void fazerBackupEstoque();
void restaurarEstoque();
void atualizarBackupEstoque();

void menuLogin();
void fazerlogin();
void registrar();
void recuperarsenha();

void adicionarProdutoCategoria();
void renovarEstoqueProduto();
void loginAdm();
void menuAdministrador();


void menuDoSistema();

void mostrarCategorias();
void mostrarComponentes();
void mostrarPlacaMae();
void mostrarProcessador();
void mostrarPerifericos();
void mostrarMonitor();
void mostrarTeclado();
void mostrarEletrodomesticos();
void mostrarFrigorifico();
void mostrarMaqLavar();
void mostrarConsolas();
void mostrarPS5();
void mostrarNS2();

double aplicarCupom(double val1, string val2);
void mostrarCarrinho();


void salvarNoHistorico(double totalFinalCompra, const string& cupomUsado);
void mostrarHistoricoCompras();
void limparCarrinho();

void escolherMetodoPagamento();
void inserirEnderecoEntrega();
void mostrarRecibo();


void limparHistoricoCompras();
void limparCarrinho();


struct Produto {
    string nome{};
    double preco{};
    int quantidade{};
};

Produto carrinho[50];
int totalItensCarrinho{ 0 };

struct Compra {
    Produto itens[50];
    int quantidadeItens{};
    double total{};
    string cupom{};
};

Compra historico[100];
int totalCompras = 0;


Produto estoquePlacasMae[10];
Produto estoqueProcessador[7];
Produto estoqueMonitor[10];
Produto estoqueTeclado[10];
Produto estoqueFrigorifico[5];
Produto estoqueMaqLavar[5];
Produto estoquePS5[3];
Produto estoqueNS2[3];

Produto backupPlacasMae[10];
Produto backupProcessador[7];
Produto backupMonitor[10];
Produto backupTeclado[10];
Produto backupFrigorifico[5];
Produto backupMaqLavar[5];
Produto backupPS5[3];
Produto backupNS2[3];

double totalFinalCompra = 0;
string cupomUsado = "Nenhum";

bool compraFinalizada = false;


int main() {
    setlocale(LC_ALL, "Portuguese.UTF-8");

    bool opcoes = true;


    estoquePlacasMae[0].nome = "ASUS Prime B550M-A";
    estoquePlacasMae[0].preco = 100.00;
    estoquePlacasMae[0].quantidade = 10;

    estoqueProcessador[0].nome = "Ryzen 7 5700X3d";
    estoqueProcessador[0].preco = 180;
    estoqueProcessador[0].quantidade = 7;

    estoqueMonitor[0].nome = "LG UltraGear 24GN600-B";
    estoqueMonitor[0].preco = 199.99;
    estoqueMonitor[0].quantidade = 15;

    estoqueTeclado[0].nome = "Logitech G Pro X";
    estoqueTeclado[0].preco = 129.90;
    estoqueTeclado[0].quantidade = 20;

    estoqueFrigorifico[0].nome = "Samsung RT38K5930S8";
    estoqueFrigorifico[0].preco = 749.99;
    estoqueFrigorifico[0].quantidade = 5;

    estoqueMaqLavar[0].nome = "Bosch Serie 6 WAT2848XES";
    estoqueMaqLavar[0].preco = 599.00;
    estoqueMaqLavar[0].quantidade = 8;

    estoquePS5[0].nome = "PlayStation 5 Standard Edition";
    estoquePS5[0].preco = 499.99;
    estoquePS5[0].quantidade = 12;

    estoqueNS2[0].nome = "Nintendo Switch OLED Model";
    estoqueNS2[0].preco = 349.99;
    estoqueNS2[0].quantidade = 10;

    fazerBackupEstoque();

    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\tSeja bem-vindo a WAVE Store\n";
    cout << endl;

    cout << "\t\t\t\t";
    system("pause");
    menuLogin();
    opcoes = false;



    return 0;
}

// ------------------------------------ Sessão de LOGIN -----------------------------------

void menuLogin() {
    system("cls");
    string opcao, confirmar;
    bool opcoes = true;

    while (opcoes) {
        system("cls");
        cout << "______________________________\n\n";
        cout << "Bem Vindo a WAVE STORE!\n\n";
        cout << "__________   Menu   __________\n\n";
        cout << "| 1 Para Login!                    |\n";
        cout << "| 2 Para Registro!                 |\n";
        cout << "| 3 Para Recuperacao de senha      |\n";
        cout << "| 4 Para entrar como ADMINISTRADOR |\n";
        cout << "| 5 Para sair!                     |\n";
        cout << "\n| Informe a açao: ";
        cin >> opcao;
        cout << endl;

        if (opcao == "1") {
            system("cls");
            fazerlogin();
        }
        else if (opcao == "2") {
            system("cls");
            registrar();
        }
        else if (opcao == "3") {
            system("cls");
            recuperarsenha();
        }
        else if (opcao == "4") {
            system("cls");
            loginAdm();
        }
        else if (opcao == "5") {
            cout << "Deseja sair da loja? ('s'/'n')\n\n ";
            cin >> confirmar;

            if (confirmar == "s") {
                system("cls");
                cout << "Obrigado por visitar a loja Wave!\n";
                opcoes = false;
            }
            else if (confirmar == "n") {
                system("cls");            
            }
            else {
                cout << "Opção inválida!\n";
                system("cls");
            }
        }
        else {
            cout << "Escolha uma opcao valida!!\n\n";
            Sleep(500);
            system("cls");
        }
    }
}

void fazerlogin() {
    string nome, senha, rnome, rsenha, confirmar;
    bool encontrado = false;

    cout << "Deseja fazer login? ('s'/'n')\n\n ";
    cin >> confirmar;
    if (confirmar == "s") {
        system("cls");

        cout << "-Informe o Nome e a Senha do Usuario\n";
        cout << "USUARIO: ";
        cin >> nome;
        cout << "SENHA: ";
        cin >> senha;

        ifstream ler("registros.txt");
        while (ler >> rnome >> rsenha) {
            if (rnome == nome && rsenha == senha) {
                encontrado = true;
                break;
            }
        }
        ler.close();

        if (encontrado) {
            cout << "Login realizado com sucesso!!!\n\n";
            Sleep(500);
            system("cls");
            menuDoSistema();
        }
        else
            cout << "Erro! Usuario ou senha incorretos!\n\n";
        Sleep(500);
        system("cls");
    }
    else if (confirmar == "n") {
        system("cls");
        return;
    }
    else {
        cout << "Opção inválida!\n";
        return;
        system("cls");
    }
}

void registrar() {
    string nome, senha, sn, sn2;

    cout << "\nVocê concorda com as Políticas da WAVE Store?('s/n' e 'ler' para ler as Políticas)?\n";
    cin >> sn;
    Sleep(500);
    system("cls");

    if (sn == "s") {

        cout << "-REGISTRO!!\n";
        cout << "Nome de usuario: ";
        cin >> nome;
        cout << "Senha: ";
        cin >> senha;

        ofstream escrever("registros.txt", ios::app);
        escrever << nome << " " << senha << endl;
        escrever.close();

        cout << "Registro efetuado com sucesso!!\n\n";
        Sleep(500);
        system("cls");
    }
    else if (sn == "ler") {

        cout << "\nAo continuar, você concorda com os Termos de Uso da Wave Store, incluindo:\n";
        cout << "- As condições de compra, que garantem que todos os pedidos estão sujeitos\n";
        cout << "  à disponibilidade de estoque e confirmação de pagamento;\n";
        cout << "- A política de devolução, que permite a devolução de produtos em até 24 horas\n";
        cout << "  após a compra, desde que estejam em perfeitas condições e com nota fiscal;\n";
        cout << "- Os meios de pagamento aceitos, como cartões de crédito, débito, e outros\n";
        cout << "  métodos disponíveis no momento da finalização da compra;\n";
        cout << "- O uso do histórico de compras, que armazena os dados da sua sessão atual\n";
        cout << "  para consulta durante o login.\n";
        cout << endl;

        cout << "Você concorda com as Políticas da WAVE Store ? ('s/n') ? \n";
        cin >> sn2;
        Sleep(500);
        system("cls");

        if (sn2 == "s") {
            cout << "-REGISTRO!!\n";
            cout << "Nome de usuario: ";
            cin >> nome;
            cout << "Senha: ";
            cin >> senha;

            ofstream escrever("registros.txt", ios::app);
            escrever << nome << " " << senha << endl;
            escrever.close();

            cout << "Registro efetuado com sucesso!!\n\n";
            Sleep(500);
            system("cls");
        }
        else {
            system("cls");
        }
    }
    else {
        system("cls");
    }
}

void recuperarsenha() {
    string procurado, nome, senha, confirmar;
    bool encontrado = false;

    cout << "Deseja recuperar a senha? ('s'/'n')\n\n ";
    cin >> confirmar;
    if (confirmar == "s") {
        system("cls");

        cout << "RECUPERACAO DE SENHA\n";
        cout << "Informe o nome de usuario: ";
        cin >> procurado;

        ifstream ler("registros.txt");
        while (ler >> nome >> senha) {
            if (nome == procurado) {
                encontrado = true;
                break;
            }
        }
        ler.close();

        if (encontrado) {
            cout << "Usuario encontrado! Sua senha: " << senha << "\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Usuario nao encontrado!\n\n";
            Sleep(500);
            system("cls");
        }
    }
    else if (confirmar == "n") {
        system("cls");
        return;
    }
    else {
        cout << "Opção inválida!\n";
        return;
        system("cls");
    }
}

void menuAdministrador() {
    bool continuar = true;
    string opcao;

    system("cls");
    while (continuar) {
        cout << "\n===== MENU DO ADMINISTRADOR =====\n\n";
        cout << "1. Adicionar novo produto\n";
        cout << "2. Renovar estoque de um produto existente\n";
        cout << "3. Sair do menu\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cout << endl;

        if (opcao == "1") {
            system("cls");
            adicionarProdutoCategoria();
        }
        else if (opcao == "2") {
            system("cls");
            renovarEstoqueProduto();
        }
        else if (opcao == "3") {
            system("cls");
            continuar = false;
            cout << "Saindo do menu do administrador...\n";
        }
        else {
            cout << "Opção inválida! Tente novamente.\n";
        }
    }
}

void loginAdm() {
    string nome;
    string senha, confirmar;
    bool continuar = true;

    cout << "Deseja fazer login como ADMINISTRADOR? ('s'/'n')\n\n ";
    cin >> confirmar;
    if (confirmar == "s") {
        system("cls");

        cout << "-Informe o Nome e a Senha do Usuario\n";
        cout << "USUARIO: ";
        cin >> nome;
        cout << "SENHA: ";
        cin >> senha;

        while (continuar) {


            if (nome == "adm123" && senha == "adm123") {
                cout << "Login realizado com sucesso!!!\n\n";
                system("pause");
                system("cls");
                menuAdministrador();
                continuar = false;
            }
            else {
                cout << "Erro! Usuario ou senha incorretos!\n\n";
                Sleep(500);
                system("cls");
                continuar = false;
            }
        }
    }
    else if (confirmar == "n") {
        system("cls");
        return;
    }
    else {
        cout << "Opção inválida!\n";
        return;
        system("cls");
    }
}

void adicionarProdutoCategoria() {
    string grupo, sub;
    Produto novo;

    bool continuar = true;

    system("cls");
    while (continuar) {
        cout << "\n=== Adicionar Produto ===\n\n";
        cout << "1. Componentes\n";
        cout << "2. Periféricos\n";
        cout << "3. Eletrodomésticos\n";
        cout << "4. Consolas\n";
        cout << "5. Voltar\n";
        cout << "Escolha o grupo da categoria: ";
        cin >> grupo;
        cout << endl;

        if (grupo == "5") {
            continuar = false;
            system("cls");
            return;
        }
        system("cls");

        cout << "Adicionando novo produto\n\n";
        cin.ignore();
        cout << "Nome do produto: ";
        getline(cin, novo.nome);
        cout << "Preço: ";
        cin >> novo.preco;
        cout << "Quantidade: ";
        cin >> novo.quantidade;
        cout << endl;

        bool continuarSub = true;

        while (continuarSub) {
            if (grupo == "1") {
                cout << "1. Placas-mãe\n";
                cout << "2. Processadores\n";
                cout << "3. Voltar\n";
                cout << "Escolha a subcategoria: ";
                cin >> sub;
                cout << endl;

                if (sub == "1") {
                    bool adicionado = false;
                    for (int i = 0; i < 10; i++) {
                        if (estoquePlacasMae[i].nome == "") {
                            estoquePlacasMae[i] = novo;
                            atualizarBackupEstoque();
                            adicionado = true;
                            cout << "\nProduto adicionado ao estoque de Placas-mãe com sucesso!\n\n";
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    if (!adicionado)
                        cout << "Erro: Estoque de Placas-mãe cheio.\n\n";
                    continuarSub = false;
                    continuar = false;
                }
                else if (sub == "2") {
                    bool adicionado = false;
                    for (int i = 0; i < 7; i++) {
                        if (estoqueProcessador[i].nome == "") {
                            estoqueProcessador[i] = novo;
                            atualizarBackupEstoque();
                            adicionado = true;
                            cout << "\nProduto adicionado ao estoque de Processadores com sucesso!\n\n";
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    if (!adicionado)
                        cout << "Erro: Estoque de Processadores cheio.\n\n";
                    continuarSub = false;
                    continuar = false;
                }
                else if (sub == "3") {
                    continuarSub = false;
                    system("cls");

                }
            }
            else if (grupo == "2") {
                cout << "1. Monitores\n";
                cout << "2. Teclados\n";
                cout << "3. Voltar\n";
                cout << "Escolha a subcategoria: ";
                cin >> sub;
                cout << endl;

                if (sub == "1") {
                    bool adicionado = false;
                    for (int i = 0; i < 10; i++) {
                        if (estoqueMonitor[i].nome == "") {
                            estoqueMonitor[i] = novo;
                            atualizarBackupEstoque();
                            adicionado = true;
                            cout << "\nProduto adicionado ao estoque de Monitores com sucesso!\n\n";
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    if (!adicionado)
                        cout << "Erro: Estoque de Monitores cheio.\n\n";
                    continuarSub = false;
                    continuar = false;
                }
                else if (sub == "2") {
                    bool adicionado = false;
                    for (int i = 0; i < 10; i++) {
                        if (estoqueTeclado[i].nome == "") {
                            estoqueTeclado[i] = novo;
                            atualizarBackupEstoque();
                            adicionado = true;
                            cout << "\nProduto adicionado ao estoque de Teclados com sucesso!\n\n";
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    if (!adicionado)
                        cout << "Erro: Estoque de Teclados cheio.\n\n";
                    continuarSub = false;
                    continuar = false;
                }
                else if (sub == "3") {
                    continuarSub = false;
                    system("cls");
                }
            }
            else if (grupo == "3") {
                cout << "1. Frigoríficos\n";
                cout << "2. Máquinas de Lavar\n";
                cout << "3. Voltar\n";
                cout << "Escolha a subcategoria: ";
                cin >> sub;
                cout << endl;

                if (sub == "1") {
                    bool adicionado = false;
                    for (int i = 0; i < 5; i++) {
                        if (estoqueFrigorifico[i].nome == "") {
                            estoqueFrigorifico[i] = novo;
                            atualizarBackupEstoque();
                            adicionado = true;
                            cout << "\nProduto adicionado ao estoque de Frigoríficos com sucesso!\n\n";
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    if (!adicionado)
                        cout << "Erro: Estoque de Frigoríficos cheio.\n\n";
                    continuarSub = false;
                    continuar = false;
                }
                else if (sub == "2") {
                    bool adicionado = false;
                    for (int i = 0; i < 5; i++) {
                        if (estoqueMaqLavar[i].nome == "") {
                            estoqueMaqLavar[i] = novo;
                            atualizarBackupEstoque();
                            adicionado = true;
                            cout << "\nProduto adicionado ao estoque de Máquinas de Lavar com sucesso!\n\n";
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    if (!adicionado)
                        cout << "Erro: Estoque de Máquinas de Lavar cheio.\n\n";
                    continuarSub = false;
                    continuar = false;
                }
                else if (sub == "3") {
                    continuarSub = false;
                    system("cls");
                }
            }
            else if (grupo == "4") {
                cout << "1. PlayStation 5\n";
                cout << "2. Nintendo Switch\n";
                cout << "3. Voltar\n";
                cout << "Escolha a subcategoria: ";
                cin >> sub;
                cout << endl;

                if (sub == "1") {
                    bool adicionado = false;
                    for (int i = 0; i < 3; i++) {
                        if (estoquePS5[i].nome == "") {
                            estoquePS5[i] = novo;
                            atualizarBackupEstoque();
                            adicionado = true;
                            cout << "\nProduto adicionado ao estoque de PlayStation 5 com sucesso!\n\n";
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    if (!adicionado)
                        cout << "Erro: Estoque de PS5 cheio.\n\n";
                    continuarSub = false;
                    continuar = false;
                }
                else if (sub == "2") {
                    bool adicionado = false;
                    for (int i = 0; i < 3; i++) {
                        if (estoqueNS2[i].nome == "") {
                            estoqueNS2[i] = novo;
                            atualizarBackupEstoque();
                            adicionado = true;
                            cout << "\nProduto adicionado ao estoque de Nintendo Switch com sucesso!\n\n";
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    if (!adicionado)
                        cout << "Erro: Estoque de Switch cheio.\n\n";
                    continuarSub = false;
                    continuar = false;
                }
                else if (sub == "3") {
                    continuarSub = false;
                    system("cls");
                }
            }
            else {
                cout << "Opção inválida!\n";
                continuarSub = false;
                system("cls");
            }
        }
    }
}

void renovarEstoqueProduto() {
    int indiceProduto, novaQuantidade;
    string grupo, sub, confirmar;

    bool continuar = true;
    bool continuar2 = true;

    system("cls");
    cout << "\n=== Renovar Estoque ===\n\n";

    cout << "1. Componentes\n";
    cout << "2. Periféricos\n";
    cout << "3. Eletrodomésticos\n";
    cout << "4. Consolas\n";
    cout << "5. Voltar\n";
    cout << "Escolha o grupo da categoria: ";
    cin >> grupo;
    cout << endl;

    if (grupo == "5") {
        continuar = false;
        system("cls");
    }

    system("cls");
    while (continuar) {

        if (grupo == "1") {
            cout << "1. Placas-mãe\n";
            cout << "2. Processadores\n";
            cout << "3. Voltar\n";
            cout << "Escolha a subcategoria: ";
            cin >> sub;
            cout << endl;

            system("cls");

            if (sub == "1") {

                cout << "Confirme novamente se deseja atualizar o estoque! ('s'/'n')\n\n ";
                cin >> confirmar;
                if (confirmar == "s") {
                    system("cls");

                    cout << "\n=== Lista de Placas-mãe ===\n\n";
                    cout << endl;
                    for (int i = 0; i < 10; i++) {
                        if (!estoquePlacasMae[i].nome.empty()) {
                            cout << i + 1 << ". " << estoquePlacasMae[i].nome
                                << " | " << estoquePlacasMae[i].quantidade << " unidades em estoque\n\n";
                        }
                    }
                

                    cout << "Escolha o número do produto para renovar o estoque: ";
                    cin >> indiceProduto;
                    cout << endl;

                    if (indiceProduto >= 1 && indiceProduto <= 10 && !estoquePlacasMae[indiceProduto - 1].nome.empty()) {
                    cout << "Quantas unidades deseja adicionar? ";
                    cin >> novaQuantidade;
                    cout << endl;
                    estoquePlacasMae[indiceProduto - 1].quantidade += novaQuantidade;
                    cout << "Estoque de " << estoquePlacasMae[indiceProduto - 1].nome
                        << " renovado com sucesso! Nova quantidade: " << estoquePlacasMae[indiceProduto - 1].quantidade << endl;
                    atualizarBackupEstoque();
                    cout << endl;

                    Sleep(500);
                    system("pause");
                    system("cls");
                    }
                    else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                    }
                }
                else if (confirmar == "n"){
                    system("cls");
                    return;
                }
                else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                }
            }
            else if (sub == "2") {
                cout << "Confirme novamente se deseja atualizar o estoque! ('s'/'n')\n\n ";
                cin >> confirmar;
                if (confirmar == "s") {
                    system("cls");

                    cout << "\n=== Lista de Processadores ===\n\n";
                    cout << endl;
                    for (int i = 0; i < 7; i++) {
                         if (!estoqueProcessador[i].nome.empty()) {
                            cout << i + 1 << ". " << estoqueProcessador[i].nome
                                    << " | " << estoqueProcessador[i].quantidade << " unidades em estoque\n\n";
                         }
                    }
                     cout << "Escolha o número do produto para renovar o estoque: ";
                     cin >> indiceProduto;
                     cout << endl;

                     if (indiceProduto >= 1 && indiceProduto <= 7 && !estoqueProcessador[indiceProduto - 1].nome.empty()) {
                         cout << "Quantas unidades deseja adicionar? ";
                         cin >> novaQuantidade;
                         cout << endl;
                         estoqueProcessador[indiceProduto - 1].quantidade += novaQuantidade;
                         cout << "Estoque de " << estoqueProcessador[indiceProduto - 1].nome
                         << " renovado com sucesso! Nova quantidade: " << estoqueProcessador[indiceProduto - 1].quantidade << endl;
                         atualizarBackupEstoque();
                         cout << endl;

                         Sleep(500);
                         system("pause");
                         system("cls");
                     }
                     else {
                         cout << "Produto inválido!\n";
                         continuar = false;
                         system("cls");
                     }
                }
                else if (confirmar == "n") {
                    system("cls");
                    return;
                }
                else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                }
            }
            else if (sub == "3") {
                continuar = false;
                system("cls");
            }
        }
        else if (grupo == "2") {
            cout << "1. Monitores\n";
            cout << "2. Teclados\n";
            cout << "3. Voltar\n";
            cout << "Escolha a subcategoria: ";
            cin >> sub;
            cout << endl;

            system("cls");

            if (sub == "1") {

                cout << "Confirme novamente se deseja atualizar o estoque! ('s'/'n')\n\n ";
                cin >> confirmar;
                if (confirmar == "s") {
                    system("cls");


                    cout << "\n=== Lista de Monitores ===\n\n";
                    cout << endl;
                    for (int i = 0; i < 10; i++) {
                        if (!estoqueMonitor[i].nome.empty()) {
                            cout << i + 1 << ". " << estoqueMonitor[i].nome
                                << " | " << estoqueMonitor[i].quantidade << " unidades em estoque\n\n";
                        }
                    }
                    cout << "Escolha o número do produto para renovar o estoque: ";
                    cin >> indiceProduto;
                    cout << endl;

                    if (indiceProduto >= 1 && indiceProduto <= 10 && !estoqueMonitor[indiceProduto - 1].nome.empty()) {
                        cout << "Quantas unidades deseja adicionar? ";
                        cin >> novaQuantidade;
                        estoqueMonitor[indiceProduto - 1].quantidade += novaQuantidade;
                        cout << "Estoque de " << estoqueMonitor[indiceProduto - 1].nome
                            << " renovado com sucesso! Nova quantidade: " << estoqueMonitor[indiceProduto - 1].quantidade << endl;
                        atualizarBackupEstoque();
                        cout << endl;

                        Sleep(500);
                        system("pause");
                        system("cls");
                    }
                    else {
                        cout << "Produto inválido!\n";
                        system("cls");
                    }
                }
                else if (confirmar == "n") {
                    system("cls");
                    return;
                }
                else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                }
            }
            else if (sub == "2") {
                cout << "Confirme novamente se deseja atualizar o estoque! ('s'/'n')\n\n ";
                cin >> confirmar;
                if (confirmar == "s") {
                    system("cls");

                    cout << "\n=== Lista de Teclados ===\n\n";
                    cout << endl;

                    for (int i = 0; i < 10; i++) {
                        if (!estoqueTeclado[i].nome.empty()) {
                            cout << i + 1 << ". " << estoqueTeclado[i].nome
                                << " | " << estoqueTeclado[i].quantidade << " unidades em estoque\n\n";
                        }
                    }
                    cout << "Escolha o número do produto para renovar o estoque: ";
                    cin >> indiceProduto;
                    cout << endl;

                    if (indiceProduto >= 1 && indiceProduto <= 10 && !estoqueTeclado[indiceProduto - 1].nome.empty()) {
                        cout << "Quantas unidades deseja adicionar? ";
                        cin >> novaQuantidade;
                        estoqueTeclado[indiceProduto - 1].quantidade += novaQuantidade;
                        cout << "Estoque de " << estoqueTeclado[indiceProduto - 1].nome
                            << " renovado com sucesso! Nova quantidade: " << estoqueTeclado[indiceProduto - 1].quantidade << endl;
                        atualizarBackupEstoque();
                        cout << endl;

                        Sleep(500);
                        system("pause");
                        system("cls");
                    }
                    else {
                        cout << "Produto inválido!\n";
                        system("cls");
                    }
                }
                else if (confirmar == "n") {
                    system("cls");
                    return;
                }
                else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                }
            }
            else if (sub == "3") {
                continuar = false;
            }
        }
        else if (grupo == "3") {
            cout << "1. Frigoríficos\n";
            cout << "2. Máquinas de Lavar\n";
            cout << "3. Voltar\n";
            cout << "Escolha a subcategoria: ";
            cin >> sub;
            cout << endl;

            system("cls");

            if (sub == "1") {
                cout << "Confirme novamente se deseja atualizar o estoque! ('s'/'n')\n\n ";
                cin >> confirmar;
                if (confirmar == "s") {
                    system("cls");

                    cout << "\n=== Lista de Frigoríficos ===\n\n";
                    cout << endl;

                    for (int i = 0; i < 5; i++) {
                        if (!estoqueFrigorifico[i].nome.empty()) {
                            cout << i + 1 << ". " << estoqueFrigorifico[i].nome
                                << " | " << estoqueFrigorifico[i].quantidade << " unidades em estoque\n\n";
                        }
                    }
                    cout << "Escolha o número do produto para renovar o estoque: ";
                    cin >> indiceProduto;
                    cout << endl;

                    if (indiceProduto >= 1 && indiceProduto <= 5 && !estoqueFrigorifico[indiceProduto - 1].nome.empty()) {
                        cout << "Quantas unidades deseja adicionar? ";
                        cin >> novaQuantidade;
                        estoqueFrigorifico[indiceProduto - 1].quantidade += novaQuantidade;
                        cout << "Estoque de " << estoqueFrigorifico[indiceProduto - 1].nome
                            << " renovado com sucesso! Nova quantidade: " << estoqueFrigorifico[indiceProduto - 1].quantidade << endl;
                        atualizarBackupEstoque();
                        cout << endl;

                        Sleep(500);
                        system("pause");
                        system("cls");
                    }
                    else {
                        cout << "Produto inválido!\n";
                        system("cls");
                    }
                }
                else if (confirmar == "n") {
                    system("cls");
                    return;
                }
                else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                }
            }
            else if (sub == "2") {
                cout << "Confirme novamente se deseja atualizar o estoque! ('s'/'n')\n\n ";
                cin >> confirmar;
                if (confirmar == "s") {
                    system("cls");

                    cout << "\n=== Lista de Máquinas de Lavar ===\n\n";
                    cout << endl;

                    for (int i = 0; i < 5; i++) {
                        if (!estoqueMaqLavar[i].nome.empty()) {
                            cout << i + 1 << ". " << estoqueMaqLavar[i].nome
                                << " | " << estoqueMaqLavar[i].quantidade << " unidades em estoque\n\n";
                        }
                    }
                    cout << "Escolha o número do produto para renovar o estoque: ";
                    cin >> indiceProduto;
                    cout << endl;

                    if (indiceProduto >= 1 && indiceProduto <= 5 && !estoqueMaqLavar[indiceProduto - 1].nome.empty()) {
                        cout << "Quantas unidades deseja adicionar? ";
                        cin >> novaQuantidade;
                        estoqueMaqLavar[indiceProduto - 1].quantidade += novaQuantidade;
                        cout << "Estoque de " << estoqueMaqLavar[indiceProduto - 1].nome
                            << " renovado com sucesso! Nova quantidade: " << estoqueMaqLavar[indiceProduto - 1].quantidade << endl;
                        atualizarBackupEstoque();
                        cout << endl;

                        Sleep(500);
                        system("pause");
                        system("cls");
                    }
                    else {
                        cout << "Produto inválido!\n";
                        system("cls");
                    }
                }
                else if (confirmar == "n") {
                    system("cls");
                    return;
                }
                else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                }
            }
            else if (sub == "3") {
                continuar = false;
            }
        }
        else if (grupo == "4") {
            cout << "1. PlayStation 5\n";
            cout << "2. Nintendo Switch\n";
            cout << "3. Voltar\n";
            cout << "Escolha a subcategoria: ";
            cin >> sub;
            cout << endl;

            system("cls");

            if (sub == "1") {
                cout << "Confirme novamente se deseja atualizar o estoque! ('s'/'n')\n\n ";
                cin >> confirmar;
                if (confirmar == "s") {
                    system("cls");


                    cout << "\n=== Lista de PlayStation 5 ===\n\n";
                    cout << endl;
                    for (int i = 0; i < 3; i++) {
                        if (!estoquePS5[i].nome.empty()) {
                            cout << i + 1 << ". " << estoquePS5[i].nome
                                << " | " << estoquePS5[i].quantidade << " unidades em estoque\n\n";
                        }
                    }
                    cout << "Escolha o número do produto para renovar o estoque: ";
                    cin >> indiceProduto;
                    cout << endl;

                    if (indiceProduto >= 1 && indiceProduto <= 3 && !estoquePS5[indiceProduto - 1].nome.empty()) {
                        cout << "Quantas unidades deseja adicionar? ";
                        cin >> novaQuantidade;
                        estoquePS5[indiceProduto - 1].quantidade += novaQuantidade;
                        cout << "Estoque de " << estoquePS5[indiceProduto - 1].nome
                            << " renovado com sucesso! Nova quantidade: " << estoquePS5[indiceProduto - 1].quantidade << endl;
                        atualizarBackupEstoque();
                        cout << endl;

                        Sleep(500);
                        system("pause");
                        system("cls");
                    }
                    else {
                        cout << "Produto inválido!\n";
                        system("cls");
                    }

                }
                else if (confirmar == "n") {
                    system("cls");
                    return;
                }
                else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                }
            }
            else if (sub == "2") {
                cout << "Confirme novamente se deseja atualizar o estoque! ('s'/'n')\n\n ";
                cin >> confirmar;
                if (confirmar == "s") {
                    system("cls");


                    cout << "\n=== Lista de Nintendo Switch ===\n\n";
                    cout << endl;

                    for (int i = 0; i < 3; i++) {
                        if (!estoqueNS2[i].nome.empty()) {
                            cout << i + 1 << ". " << estoqueNS2[i].nome
                                << " | " << estoqueNS2[i].quantidade << " unidades em estoque\n\n";
                        }
                    }
                    cout << "Escolha o número do produto para renovar o estoque: ";
                    cin >> indiceProduto;
                    cout << endl;

                    if (indiceProduto >= 1 && indiceProduto <= 3 && !estoqueNS2[indiceProduto - 1].nome.empty()) {
                        cout << "Quantas unidades deseja adicionar? ";
                        cin >> novaQuantidade;
                        estoqueNS2[indiceProduto - 1].quantidade += novaQuantidade;
                        cout << "Estoque de " << estoqueNS2[indiceProduto - 1].nome
                            << " renovado com sucesso! Nova quantidade: " << estoqueNS2[indiceProduto - 1].quantidade << endl;
                        atualizarBackupEstoque();
                        cout << endl;

                        Sleep(500);
                        system("pause");
                        system("cls");
                    }
                    else {
                        cout << "Produto inválido!\n";
                        system("cls");
                    }
                }
                else if (confirmar == "n") {
                    system("cls");
                    return;
                }
                else {
                    cout << "Produto inválido!\n";
                    continuar = false;
                    system("cls");
                }
            }
            else if (sub == "3") {
                continuar = false;
            }
        }
        else {
            cout << "Opção inválida\n\n";
            Sleep(500);
            system("cls");
            return;
        }

    }
    system("cls");
}


// ---------------------------------------------------------------------------------

void menuDoSistema() {
    system("cls");
    string escolha;
    bool continuar = true;

    while (continuar) {
        cout << "===== WAVE STORE =====\n";
        cout << "1. Ver produtos\n";
        cout << "2. Ver carrinho\n";
        cout << "3. Ver histórico de compras\n";
        cout << "4. Sair da conta\n";
        cin >> escolha;
        cout << endl;

        if (escolha == "1") {
            system("cls");
            mostrarCategorias();
        }
        else if (escolha == "2") {
            system("cls");
            mostrarCarrinho();

        }
        else if (escolha == "3") {
            system("cls");
            mostrarHistoricoCompras();

        }
        else if (escolha == "4") {
            limparCarrinho();
            limparHistoricoCompras();
            if (!compraFinalizada) {
                restaurarEstoque();
            }
            system("cls");
            continuar = false;
            compraFinalizada = false;
        }
        else {
            cout << "Opção inválida!\n\n";
            system("cls");
        }
    }
}

void mostrarCategorias() {
    system("cls");
    string opcao;
    bool continuar = true;

    while (continuar) {
        cout << "Escolha uma das categorias\n\n";
        cout << "1. Componentes\n";
        cout << "2. Periféricos\n";
        cout << "3. Eletrodomésticos\n";
        cout << "4. Consolas\n";
        cout << "5. Voltar\n";
        cout << endl;
        cin >> opcao;

        if (opcao == "1") {
            system("cls");
            mostrarComponentes();
        }
        else if (opcao == "2") {
            system("cls");
            mostrarPerifericos();
        }
        else if (opcao == "3") {
            system("cls");
            mostrarEletrodomesticos();
        }
        else if (opcao == "4") {
            system("cls");
            mostrarConsolas();
        }
        else if (opcao == "5") {
            continuar = false;
            system("cls");
        }
        else {
            cout << "Categoria inválida!\n\n";
            system("cls");
        }
    }
}

// ------------------------------------ Componentes --------------------------------

void mostrarComponentes() {
    system("cls");
    string opcao;
    bool continuar = true;

    while (continuar) {
        cout << "Selecione o produto desejado\n\n";
        cout << "1. Placa-mãe\n";
        cout << "2. Processador\n";
        cout << "3. Voltar\n";
        cin >> opcao;

        if (opcao == "1") {
            mostrarPlacaMae();
        }
        else if (opcao == "2") {
            mostrarProcessador();
        }
        else if (opcao == "3") {
            continuar = false;
            system("cls");
        }
        else {
            cout << "Produto inválido!\n\n";
            system("cls");
        }
    }
}

void mostrarPlacaMae() {
    system("cls");
    string opcao;
    cout << "Adicionar o produto ao Carrinho\n\n";


    bool produtosDisponiveis = false;
    for (int i = 0; i < 10; i++) {
        if (!estoquePlacasMae[i].nome.empty()) {
            cout << i + 1 << ". " << estoquePlacasMae[i].nome
                << " | " << estoquePlacasMae[i].preco << " Euros"
                << " | Em estoque: " << estoquePlacasMae[i].quantidade << "\n";
        }
    }


    cout << "\nEscolha o produto ou '0' para voltar: ";
    cin >> opcao;

    int escolha = stoi(opcao) - 1;
    if (escolha >= 0 && escolha < 10 && !estoquePlacasMae[escolha].nome.empty()) {
        if (estoquePlacasMae[escolha].quantidade > 0) {
            Produto pMae;
            pMae.nome = estoquePlacasMae[escolha].nome;
            pMae.preco = estoquePlacasMae[escolha].preco;
            pMae.quantidade = 1;

            carrinho[totalItensCarrinho] = pMae;
            totalItensCarrinho++;

            estoquePlacasMae[escolha].quantidade--;

            cout << "Produto adicionado ao carrinho!\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Produto fora de estoque!\n\n";
            system("pause");
            system("cls");
        }
    }
    else if (opcao == "0") {
        cout << "Voltando ao menu de componentes...\n\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Opção inválida!\n\n";
        system("cls");
    }
}

void mostrarProcessador() {
    system("cls");
    string opcao;
    cout << "Adicionar o produto ao Carrinho\n\n";
    for (int i = 0; i < 7; i++) {
        if (!estoqueProcessador[i].nome.empty()) {
            cout << i + 1 << ". " << estoqueProcessador[i].nome
                << " | " << estoqueProcessador[i].preco << " Euros"
                << " | Em estoque: " << estoqueProcessador[i].quantidade << "\n";
        }
    }

    cout << "\nEscolha o produto ou '0' para voltar: ";
    cin >> opcao;

    int escolha = stoi(opcao) - 1;
    if (escolha >= 0 && escolha < 7 && !estoqueProcessador[escolha].nome.empty()) {
        if (estoqueProcessador[escolha].quantidade > 0) {
            Produto pCPU;
            pCPU.nome = estoqueProcessador[escolha].nome;
            pCPU.preco = estoqueProcessador[escolha].preco;
            pCPU.quantidade = 1;

            carrinho[totalItensCarrinho] = pCPU;
            totalItensCarrinho++;

            estoqueProcessador[escolha].quantidade--;

            cout << "Produto adicionado ao carrinho!\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Produto fora de estoque!\n\n";
            system("pause");
            system("cls");
        }
    }
    else if (opcao == "0") {
        cout << "Voltando ao menu de Processadores...\n\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Opção inválida!\n\n";
        system("cls");
    }
}


// ------------------------------------ Perifericos --------------------------------

void mostrarPerifericos() {
    system("cls");
    string opcao;
    bool continuar = true;

    while (continuar) {
        cout << "Selecione o produto desejado\n\n";
        cout << "1. Monitor\n";
        cout << "2. Teclado\n";
        cout << "3. Voltar\n";
        cin >> opcao;

        if (opcao == "1") {
            mostrarMonitor();
        }
        else if (opcao == "2") {
            mostrarTeclado();
        }
        else if (opcao == "3") {
            continuar = false;
            system("cls");
        }
        else {
            cout << "Produto inválido!\n\n";
            system("cls");
        }
    }
}

void mostrarMonitor() {
    system("cls");
    string opcao;
    cout << "Adicionar o produto ao Carrinho\n\n";
    for (int i = 0; i < 10; i++) {
        if (!estoqueMonitor[i].nome.empty()) {
            cout << i + 1 << ". " << estoqueMonitor[i].nome
                << " | " << estoqueMonitor[i].preco << " Euros"
                << " | Em estoque: " << estoqueMonitor[i].quantidade << "\n";
        }
    }

    cout << "\nEscolha o produto ou '0' para voltar: ";
    cin >> opcao;

    int escolha = stoi(opcao) - 1;
    if (escolha >= 0 && escolha < 10 && !estoqueMonitor[escolha].nome.empty()) {
        if (estoqueMonitor[escolha].quantidade > 0) {
            Produto pMonitor;
            pMonitor.nome = estoqueMonitor[escolha].nome;
            pMonitor.preco = estoqueMonitor[escolha].preco;
            pMonitor.quantidade = 1;

            carrinho[totalItensCarrinho] = pMonitor;
            totalItensCarrinho++;

            estoqueMonitor[escolha].quantidade--;

            cout << "Produto adicionado ao carrinho!\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Produto fora de estoque!\n\n";
            system("pause");
            system("cls");
        }
    }
    else if (opcao == "0") {
        cout << "Voltando ao menu de Monitores...\n\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Opção inválida!\n\n";
        system("cls");
    }
}

void mostrarTeclado() {
    system("cls");
    string opcao;
    cout << "Adicionar o produto ao Carrinho\n\n";
    for (int i = 0; i < 10; i++) {
        if (!estoqueTeclado[i].nome.empty()) {
            cout << i + 1 << ". " << estoqueTeclado[i].nome
                << " | " << estoqueTeclado[i].preco << " Euros"
                << " | Em estoque: " << estoqueTeclado[i].quantidade << "\n";
        }
    }

    cout << "\nEscolha o produto ou '0' para voltar: ";
    cin >> opcao;

    int escolha = stoi(opcao) - 1;
    if (escolha >= 0 && escolha < 10 && !estoqueTeclado[escolha].nome.empty()) {
        if (estoqueTeclado[escolha].quantidade > 0) {
            Produto pTeclado;
            pTeclado.nome = estoqueTeclado[escolha].nome;
            pTeclado.preco = estoqueTeclado[escolha].preco;
            pTeclado.quantidade = 1;

            carrinho[totalItensCarrinho] = pTeclado;
            totalItensCarrinho++;

            estoqueTeclado[escolha].quantidade--;

            cout << "Produto adicionado ao carrinho!\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Produto fora de estoque!\n\n";
            system("pause");
            system("cls");
        }
    }
    else if (opcao == "0") {
        cout << "Voltando ao menu de Teclados...\n\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Opção inválida!\n\n";
        system("cls");
    }
}

// ------------------------------------ Eletrodomésticos ---------------------------

void mostrarEletrodomesticos() {
    system("cls");
    string opcao;
    bool continuar = true;

    while (continuar) {
        cout << "Selecione o produto desejado\n\n";
        cout << "1. Frigorifico\n";
        cout << "2. Maquina de Lavar\n";
        cout << "3. Voltar\n";
        cin >> opcao;

        if (opcao == "1") {
            mostrarFrigorifico();
        }
        else if (opcao == "2") {
            mostrarMaqLavar();
        }
        else if (opcao == "3") {
            continuar = false;
            system("cls");
        }
        else {
            cout << "Produto inválido!\n\n";
            system("cls");
        }
    }
}

void mostrarFrigorifico() {
    system("cls");
    string opcao;
    cout << "Adicionar o produto ao Carrinho\n\n";
    for (int i = 0; i < 5; i++) {
        if (!estoqueFrigorifico[i].nome.empty()) {
            cout << i + 1 << ". " << estoqueFrigorifico[i].nome
                << " | " << estoqueFrigorifico[i].preco << " Euros"
                << " | Em estoque: " << estoqueFrigorifico[i].quantidade << "\n";
        }
    }

    cout << "\nEscolha o produto ou '0' para voltar: ";
    cin >> opcao;

    int escolha = stoi(opcao) - 1;
    if (escolha >= 0 && escolha < 5 && !estoqueFrigorifico[escolha].nome.empty()) {
        if (estoqueFrigorifico[escolha].quantidade > 0) {
            Produto pFrigorifico;
            pFrigorifico.nome = estoqueFrigorifico[escolha].nome;
            pFrigorifico.preco = estoqueFrigorifico[escolha].preco;
            pFrigorifico.quantidade = 1;

            carrinho[totalItensCarrinho] = pFrigorifico;
            totalItensCarrinho++;

            estoqueFrigorifico[escolha].quantidade--;

            cout << "Produto adicionado ao carrinho!\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Produto fora de estoque!\n\n";
            system("pause");
            system("cls");
        }
    }
    else if (opcao == "0") {
        cout << "Voltando ao menu de Eletrodomésticos...\n\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Opção inválida!\n\n";
        system("cls");
    }
}

void mostrarMaqLavar() {
    system("cls");
    string opcao;
    cout << "Adicionar o produto ao Carrinho\n\n";
    for (int i = 0; i < 5; i++) {
        if (!estoqueMaqLavar[i].nome.empty()) {
            cout << i + 1 << ". " << estoqueMaqLavar[i].nome
                << " | " << estoqueMaqLavar[i].preco << " Euros"
                << " | Em estoque: " << estoqueMaqLavar[i].quantidade << "\n";
        }
    }

    cout << "\nEscolha o produto ou '0' para voltar: ";
    cin >> opcao;

    int escolha = stoi(opcao) - 1;
    if (escolha >= 0 && escolha < 5 && !estoqueMaqLavar[escolha].nome.empty()) {
        if (estoqueMaqLavar[escolha].quantidade > 0) {
            Produto pMaqLavar;
            pMaqLavar.nome = estoqueMaqLavar[escolha].nome;
            pMaqLavar.preco = estoqueMaqLavar[escolha].preco;
            pMaqLavar.quantidade = 1;

            carrinho[totalItensCarrinho] = pMaqLavar;
            totalItensCarrinho++;

            estoqueMaqLavar[escolha].quantidade--;

            cout << "Produto adicionado ao carrinho!\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Produto fora de estoque!\n\n";
            system("pause");
            system("cls");
        }
    }
    else if (opcao == "0") {
        cout << "Voltando ao menu de Eletrodomésticos...\n\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Opção inválida!\n\n";
        system("cls");
    }
}

// ------------------------------------ Consolas -----------------------------------

void mostrarConsolas() {
    system("cls");
    string opcao;
    bool continuar = true;

    while (continuar) {
        cout << "Selecione o produto desejado\n\n";
        cout << "1. Sony\n";
        cout << "2. Nitendo\n";
        cout << "3. Voltar\n";
        cin >> opcao;

        if (opcao == "1") {
            mostrarPS5();
        }
        else if (opcao == "2") {
            mostrarNS2();
        }
        else if (opcao == "3") {
            continuar = false;
            system("cls");
        }
        else {
            cout << "Produto inválido!\n\n";
            system("cls");
        }
    }
}

void mostrarPS5() {
    system("cls");
    string opcao;

    cout << "Adicionar o produto ao Carrinho\n\n";
    for (int i = 0; i < 3; i++) {
        if (!estoquePS5[i].nome.empty()) {
            cout << i + 1 << ". " << estoquePS5[i].nome
                << " | " << estoquePS5[i].preco << " Euros"
                << " | Em estoque: " << estoquePS5[i].quantidade << "\n";
        }
    }

    cout << "\nEscolha o produto ou '0' para voltar: ";
    cin >> opcao;

    int escolha = stoi(opcao) - 1;
    if (escolha >= 0 && escolha < 3 && !estoquePS5[escolha].nome.empty()) {
        if (estoquePS5[escolha].quantidade > 0) {
            Produto pPS5;
            pPS5.nome = estoquePS5[escolha].nome;
            pPS5.preco = estoquePS5[escolha].preco;
            pPS5.quantidade = 1;

            carrinho[totalItensCarrinho] = pPS5;
            totalItensCarrinho++;

            estoquePS5[escolha].quantidade--;

            cout << "Produto adicionado ao carrinho!\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Produto fora de estoque!\n\n";
            system("pause");
            system("cls");
        }
    }
    else if (opcao == "0") {
        cout << "Voltando ao menu de Consolas...\n\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Opção inválida!\n\n";
        system("cls");
    }
}

void mostrarNS2() {
    system("cls");
    string opcao;
    cout << "Adicionar o produto ao Carrinho\n\n";
    for (int i = 0; i < 3; i++) {
        if (!estoqueNS2[i].nome.empty()) {
            cout << i + 1 << ". " << estoqueNS2[i].nome
                << " | " << estoqueNS2[i].preco << " Euros"
                << " | Em estoque: " << estoqueNS2[i].quantidade << "\n";
        }
    }

    cout << "\nEscolha o produto ou '0' para voltar: ";
    cin >> opcao;

    int escolha = stoi(opcao) - 1;
    if (escolha >= 0 && escolha < 3 && !estoqueNS2[escolha].nome.empty()) {
        if (estoqueNS2[escolha].quantidade > 0) {
            Produto pNS2;
            pNS2.nome = estoqueNS2[escolha].nome;
            pNS2.preco = estoqueNS2[escolha].preco;
            pNS2.quantidade = 1;

            carrinho[totalItensCarrinho] = pNS2;
            totalItensCarrinho++;

            estoqueNS2[escolha].quantidade--;

            cout << "Produto adicionado ao carrinho!\n\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Produto fora de estoque!\n\n";
            system("pause");
            system("cls");
        }
    }
    else if (opcao == "0") {
        cout << "Voltando ao menu de Consolas...\n\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Opção inválida!\n\n";
        system("cls");
    }
}

// ---------------------------------------------------------------------------------

double aplicarCupom(double val1, string val2) {

    if (val2 == "BRAYAN15") return val1 * 0.85;
    else if (val2 == "MATEUS05") return val1 * 0.95;
    else if (val2 == "MIGUEL10") return val1 * 0.90;
    else {
        return val1;
    }
}

void mostrarCarrinho() {
    string opcao;
    string opcao2;
    string opcao3;
    bool continuar = true;
    bool continuar2 = true;
    bool cupomsair = true;

    if (totalItensCarrinho == 0) {
        system("cls");
        cout << "Carrinho vazio!\n\n";
        system("pause");
        system("cls");
    }
    else {
        double total = 0;
        for (int i = 0; i < totalItensCarrinho; i++) {
            cout << i + 1 << ". " << carrinho[i].nome << " "
                << carrinho[i].preco << " - euros"
                << " x" << carrinho[i].quantidade << endl;
            total += carrinho[i].preco * carrinho[i].quantidade;
        }
        cout << "Total: " << total << " euros " << "\n\n";
        cout << endl;
        system("pause");
        system("cls");

        while (continuar) {
            cout << "Finalizar compra?" << "\n";
            cout << "1. Sim." << "\n";
            cout << "2. Não." << "\n";
            cin >> opcao;
            cout << endl;
            system("cls");

            if (opcao == "1") {

                while (continuar2) {
                    cout << "Quer inserir um CUPOM de desconto?" << "\n\n";
                    cout << "1. Sim." << "\n";
                    cout << "2. Não." << "\n";
                    cin >> opcao2;
                    cout << endl;

                    if (opcao2 == "1") {
                        string cupom;
                        double totalComDesconto;

                        while (cupomsair) {
                            cout << "Insira o Cupon: ";
                            cin >> cupom;
                            cout << endl;

                            totalComDesconto = aplicarCupom(total, cupom);
                            if (totalComDesconto != total) {
                                cout << "Total com desconto: " << totalComDesconto << " Euros\n";
                                cout << endl;


                                totalFinalCompra = totalComDesconto;
                                cupomUsado = cupom;

                                cupomsair = false;
                                system("pause");
                                system("cls");
                            }
                            else {
                                cout << "\nCUPOM inválido! Insira um CUPOM válido ou prossiga sem desconto.\n\n";
                                cout << "Quer tentar novamente? (1 para sim, 2 para não): \n\n";
                                cin >> opcao3;
                                Sleep(500);
                                system("cls");

                                if (opcao3 != "1") {
                                    cout << "Total sem desconto: " << total << " Euros\n";
                                    cout << endl;

                                    totalFinalCompra = total;
                                    cupomUsado = "Nenhum";

                                    cupomsair = false;
                                    system("pause");
                                    system("cls");
                                }
                            }
                        }

                        escolherMetodoPagamento();
                        continuar2 = false;
                        system("cls");

                    }

                    else if (opcao2 == "2") {
                        cout << "Total sem desconto: " << total << " Euros\n";
                        cout << endl;

                        totalFinalCompra = total;
                        cupomUsado = "Nenhum";

                        system("pause");
                        system("cls");

                        escolherMetodoPagamento();
                        continuar2 = false;
                        system("cls");
                    }

                    else {
                        cout << "Opção inválida! Por favor, escolha uma opção válida.\n";
                        Sleep(500);
                        system("cls");
                    }
                }
                
                continuar = false;
            }
            else if (opcao == "2") {
                continuar = false;
                system("cls");
            }
            else {
                cout << "Opção inválida!\n\n";
                system("cls");
            }
        }
    }

}

void escolherMetodoPagamento() {
    string opcao2;
    bool continuar2 = true;

    while (continuar2) {
        cout << "Métodos de Pagamento\n\n";
        cout << "1. Google Pay\n";
        cout << "2. PayPal\n";
        cout << "3. MB Way\n";
        cout << "4. Voltar\n";
        cout << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao2;
        cout << endl;

        if (opcao2 == "1") {
            cout << "\nVocê escolheu Google Pay.\nPagamento processado com sucesso!\n\n";
            continuar2 = false;
            cout << endl;
            system("pause");
            system("cls");

        }
        else if (opcao2 == "2") {
            cout << "\nVocê escolheu PayPal.\nPagamento processado com sucesso!\n\n";
            continuar2 = false;
            cout << endl;
            system("pause");
            system("cls");

        }
        else if (opcao2 == "3") {
            cout << "\nVocê escolheu MB Way.\nPagamento processado com sucesso!\n\n";
            continuar2 = false;
            cout << endl;
            system("pause");
            system("cls");

        }
        else if (opcao2 == "4") {
            cout << "\nVoltando ao menu anterior...\n\n";
            cout << endl;
            system("cls");
            return;
        }
        else {
            cout << "\nOpção inválida. Tente novamente.\n\n";
            system("cls");

        }
    }

    inserirEnderecoEntrega();
    continuar2 = false;
}

void inserirEnderecoEntrega() {
    string endereco, codigoPostal, pais;

    cout << "==============================\n\n";
    cout << "Insira seu endereço para a compra ser enviada.\n\n";

    cout << "Endereço: ";
    cin.ignore();
    getline(cin, endereco);

    cout << "Código Postal: ";
    getline(cin, codigoPostal);

    cout << "País: ";
    getline(cin, pais);

    cout << "\nEndereço registrado com sucesso!\n";
    cout << endl;
    cout << "Seu item será enviado para:\n";
    cout << endl;
    cout << "Endereço: " << endereco << "\n";
    cout << "Código Postal: " << codigoPostal << "\n";
    cout << "País: " << pais << "\n";
    cout << endl;

    system("pause");
    system("cls");

    mostrarRecibo();
    cout << endl;
}

void mostrarRecibo() {
    cout << "\n----------------------- Recibo de Compra -----------------------\n\n";

    for (int i = 0; i < totalItensCarrinho; i++) {
        cout << carrinho[i].nome << " | Preço: " << carrinho[i].preco
            << " Euros | Quantidade: " << carrinho[i].quantidade << "\n";
    }

    cout << "\nTotal da Compra: " << totalFinalCompra << " Euros\n\n";

    if (cupomUsado != "Nenhum" && !cupomUsado.empty()) {
        cout << "Cupom aplicado: " << cupomUsado << "\n\n";
    }

    cout << "Você tem DIREITO à 24 HORAS para ser feita a DEVOLUÇÃO da compra\n\n";
    cout << "Obrigado pela compra! Volte sempre!\n\n";
    cout << "----------------------------------------------------------------\n\n";
    cout << endl;
    system("pause");
    system("cls");
    salvarNoHistorico(totalFinalCompra, cupomUsado);
    limparCarrinho();
    compraFinalizada = true;
    atualizarBackupEstoque();
}

void salvarNoHistorico(double totalFinalCompra, const string& cupomUsado) {
    if (totalCompras >= 100) {
        cout << "Histórico cheio! Não é possível salvar mais compras.\n";
        return;
    }

    Compra nova;
    nova.quantidadeItens = totalItensCarrinho;
    nova.total = totalFinalCompra;
    nova.cupom = cupomUsado;

    for (int i = 0; i < totalItensCarrinho; i++) {
        nova.itens[i] = carrinho[i];
    }

    historico[totalCompras] = nova;
    totalCompras++;
}

void mostrarHistoricoCompras() {
    if (totalCompras == 0) {
        cout << "\nNenhuma compra realizada ainda.\n";
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < totalCompras; i++) {
        cout << "\n---- Compra #" << (i + 1) << " ----\n";
        for (int j = 0; j < historico[i].quantidadeItens; j++) {
            cout << historico[i].itens[j].nome << " | Preço: " << historico[i].itens[j].preco
                << " Euros | Quantidade: " << historico[i].itens[j].quantidade << "\n";
        }
        cout << "Total: " << historico[i].total << " Euros\n";
        if (historico[i].cupom != "Nenhum" && !historico[i].cupom.empty()) {
            cout << "Cupom aplicado: " << historico[i].cupom << "\n";
        }
        cout << "-----------------------------\n";
    }
    system("pause");
    system("cls");
}

void limparCarrinho() {
    for (int i = 0; i < totalItensCarrinho; i++) {
        carrinho[i].nome = "";
        carrinho[i].preco = 0.0;
        carrinho[i].quantidade = 0;
    }
    totalItensCarrinho = 0;
}

void limparHistoricoCompras() {
    for (int i = 0; i < totalCompras; i++) {
        for (int j = 0; j < historico[i].quantidadeItens; j++) {
            historico[i].itens[j].nome = "";
            historico[i].itens[j].preco = 0.0;
            historico[i].itens[j].quantidade = 0;
        }
        historico[i].quantidadeItens = 0;
        historico[i].total = 0.0;
        historico[i].cupom = "";
    }
    totalCompras = 0;
}

void fazerBackupEstoque() {
    for (int i = 0; i < 10; i++) backupPlacasMae[i] = estoquePlacasMae[i];
    for (int i = 0; i < 7; i++)  backupProcessador[i] = estoqueProcessador[i];
    for (int i = 0; i < 10; i++) backupMonitor[i] = estoqueMonitor[i];
    for (int i = 0; i < 10; i++) backupTeclado[i] = estoqueTeclado[i];
    for (int i = 0; i < 5; i++)  backupFrigorifico[i] = estoqueFrigorifico[i];
    for (int i = 0; i < 5; i++)  backupMaqLavar[i] = estoqueMaqLavar[i];
    for (int i = 0; i < 3; i++)  backupPS5[i] = estoquePS5[i];
    for (int i = 0; i < 3; i++)  backupNS2[i] = estoqueNS2[i];
}

void restaurarEstoque() {
    for (int i = 0; i < 10; i++) estoquePlacasMae[i] = backupPlacasMae[i];
    for (int i = 0; i < 7; i++)  estoqueProcessador[i] = backupProcessador[i];
    for (int i = 0; i < 10; i++) estoqueMonitor[i] = backupMonitor[i];
    for (int i = 0; i < 10; i++) estoqueTeclado[i] = backupTeclado[i];
    for (int i = 0; i < 5; i++)  estoqueFrigorifico[i] = backupFrigorifico[i];
    for (int i = 0; i < 5; i++)  estoqueMaqLavar[i] = backupMaqLavar[i];
    for (int i = 0; i < 3; i++)  estoquePS5[i] = backupPS5[i];
    for (int i = 0; i < 3; i++)  estoqueNS2[i] = backupNS2[i];
}

void atualizarBackupEstoque() {
    for (int i = 0; i < 10; i++) backupPlacasMae[i] = estoquePlacasMae[i];
    for (int i = 0; i < 7; i++)  backupProcessador[i] = estoqueProcessador[i];
    for (int i = 0; i < 10; i++) backupMonitor[i] = estoqueMonitor[i];
    for (int i = 0; i < 10; i++) backupTeclado[i] = estoqueTeclado[i];
    for (int i = 0; i < 5; i++)  backupFrigorifico[i] = estoqueFrigorifico[i];
    for (int i = 0; i < 5; i++)  backupMaqLavar[i] = estoqueMaqLavar[i];
    for (int i = 0; i < 3; i++)  backupPS5[i] = estoquePS5[i];
    for (int i = 0; i < 3; i++)  backupNS2[i] = estoqueNS2[i];
}
