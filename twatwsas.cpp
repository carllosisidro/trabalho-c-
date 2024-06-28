#include <iostream> // Padrao pra receber os valores do CIN
#include <iomanip> // formata a saída para que os números sejam exibidos de forma clara e organizada.
#include <vector> // permite o uso de vetores para armazenar e manipular dados, como os gastos com diferentes contas.

using namespace std;

int main() {
    double salarioMensal, gastosTotais = 0, sobraParaInvestir, meta, economiaMensal;
    int mesesParaMeta;

    // Matriz 2x3 para armazenar as contas e seus gastos mensais
    vector<vector<string>> contas = {
        {"Comida", "0"},
        {"Aluguel", "0"},
        {"Energia e Água", "0"},
        {"Internet", "0"},
        {"Transporte", "0"},
        {"Outros", "0"}
    };

    // Título do programa
    cout << "\n**********************************\n";
    cout << "*** Planejador Financeiro ***\n";
    cout << "**********************************\n\n";

    // Entrada do salário mensal
    cout << "Digite o seu salário mensal: R$ ";
    cin >> salarioMensal;

    // Validação do salário positivo
    while (salarioMensal <= 0) {
        cout << "Salário inválido. Digite um valor positivo: R$ ";
        cin >> salarioMensal;
    }

    // Seleção das contas
    vector<int> contasSelecionadas;
    char confirma;
    cout << "\nSelecione as contas que você possui (digite o número da conta e pressione Enter, digite 'C' para confirmar):\n";
    for (int i = 0; i < contas.size(); ++i) {
        cout << i + 1 << ") " << contas[i][0] << endl;
    }
    do {
        int escolha;
        cin >> escolha;
        if (escolha >= 1 && escolha <= contas.size()) {
            contasSelecionadas.push_back(escolha - 1);
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Selecione mais contas ou digite 'C' para confirmar: ";
        cin >> confirma;
    } while (confirma != 'C');

    // Entrada dos gastos mensais para as contas selecionadas
    for (int i = 0; i < contasSelecionadas.size(); ++i) {
        int indice = contasSelecionadas[i];
        cout << "Gasto com " << contas[indice][0] << ": R$ ";
        double gasto;
        cin >> gasto;
        contas[indice][1] = to_string(gasto); // Armazena o gasto na matriz
        gastosTotais += gasto;
    }

    // Cálculo do que sobra para investir
    sobraParaInvestir = salarioMensal - gastosTotais;

    // Validação de sobra positiva
    while (sobraParaInvestir <= 0) {
        cout << "Seus gastos são iguais ou maiores que o seu salário mensal. Revise seus números.\n";
        cout << "Digite o seu salário mensal: R$ ";
        cin >> salarioMensal;
        // ... (Repetir a parte de entrada dos gastos)
        sobraParaInvestir = salarioMensal - gastosTotais;
    }

    // Entrada da meta financeira
    cout << "\nQual é a sua meta financeira? R$ ";
    cin >> meta;

    // Validação da meta positiva
    while (meta <= 0) {
        cout << "Meta inválida. Digite um valor positivo: R$ ";
        cin >> meta;
    }

    // Mostrar o valor que sobra para investir
    cout << "\nVocê tem R$ " << fixed << setprecision(2) << sobraParaInvestir << " sobrando para investir por mês.\n";

    // Entrada da economia mensal pretendida
    cout << "Quanto você pretende investir por mês para alcançar essa meta? R$ ";
    cin >> economiaMensal;

    // Validação da economia mensal
    while (economiaMensal <= 0 || economiaMensal > sobraParaInvestir) {
        cout << "Valor de investimento mensal inválido. Digite um valor positivo e menor ou igual ao que sobra para investir (R$ " << fixed << setprecision(2) << sobraParaInvestir << "): R$ ";
        cin >> economiaMensal;
    }

    // Cálculo de meses necessários para alcançar a meta
    mesesParaMeta = static_cast<int>((meta + economiaMensal - 1) / economiaMensal);

    // Impressão dos resultados
    cout << "\n**********************************\n";
    cout << "*** Resultados ***\n";
    cout << "**********************************\n\n";

    cout << "Com um salário de R$ " << fixed << setprecision(2) << salarioMensal << " por mês,\n";
    cout << "gastando R$ " << fixed << setprecision(2) << gastosTotais << " com as contas selecionadas,\n";
    cout << "e investindo R$ " << fixed << setprecision(2) << economiaMensal << " por mês,\n";
    cout << "você levará aproximadamente " << mesesParaMeta << " meses para alcançar sua meta de R$ " << fixed << setprecision(2) << meta << ".\n\n";
    






    return 0;
}