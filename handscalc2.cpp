#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <regex>

using namespace std;

void result(float num1, char op, float num2) {

float result;
string nop;
                                                
    switch (op) {                               //Case de acordo com cada operação. 
        
        case '+':                               //Soma.
        result = num1 + num2;                    
        break;

        case '-':                               //Subtração.
        result = num1 - num2;                   
        break;

        case '*':                               //Multiplicação.
        result = num1 * num2;                   
        break;

        case '/':                               //Divisão.
        result = num1 / num2;                   
        break;

        case '%':                               //Porcentagem.
        result = 100*(num1 / num2);             
        break;

        case '^':                               //Potência.
        result = pow(num1, num2);                
        break;

        default:                                //Operação inválida nos casos que não for escolhida um dos operadores acima ou divisão por 0.
        nop = "Operacao invalida";              
        cout << nop;
        cout << endl;
        exit;
    }
    if (nop != "Operacao invalida") {

        cout << endl;
        cout << "O resultado da expressao (" << num1 << " " << op << " " << num2 << ") é: " << result << endl;              //Traz o resultado da expressão. 
    }
    
}


void input() {                                       //Função para entrada de dados. 


regex floater("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");    
string n1, n2;
char op;
float num11, num22;


do {

    cout << "Informe o primeiro numero: ";            //Entrada do primeiro número. 
    cin >> n1;
    cin.ignore();                              

} while (!regex_match(n1,floater));

num11 = stof(n1);  


cout << "Informe a operacao: ";                         //Entrada operação desejada. 
cin.get(op);
cin.ignore();   


do {

    cout << "Informe o segundo numero: ";               //Entrada do segundo número.         
    cin >> n2;                                          

} while (!regex_match(n2,floater));

num22 = stof(n2); 


if (op == '/' && num22 == 0) {                          //Validação para operação de divisão quando o divisor for 0. 

    system("clear");
    op = '0';
    cin.ignore();

} else
    cin.ignore();
    result(num11,op,num22);                              //Chama função que realiza as operações e informa o resultado. 
}

//INÍCIO DO CÓDIGO

int main() {

char op;

cout << endl;
cout << "#################### Calculadora C++ ####################\n";
cout << endl;

do {

    cout << "Operacoes disponiveis: " << endl;
    cout << endl;
    cout << "'+' : soma" << endl;
    cout << "'-' : subtracao" << endl; 
    cout << "'*' : multiplicacao" << endl; 
    cout << "'/' : divisao" << endl; 
    cout << "'%' : porcentagem" << endl; 
    cout << "'^' : potenciacao" << endl;
    cout << endl;

    input();                                         //Chama função para entrada de dados. 
    cout << endl;
    cout << "Deseja repetir o calculo?(S/N): ";
    cin.get(op);
    system("clear");

} while (toupper(op)=='S');                           // Reinicia a operação de acordo com a escolha do usuário.                  

return 0;

}