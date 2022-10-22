#include "cypher.hpp"

int main ()
{
    int password;
    cout << "Enter the password to create the Conversion Table: ";
    cin >> password;

    Cypher Creator(password);

    while (true)
    {
        cout << "-MENU-" << endl;
        cout << "1- Inserir texto" << endl;
        cout << "2- Encriptografar" << endl;
        cout << "3- Desincriptografar"<< endl;
        cout << "4- Regerar table de conversão" << endl;
        cout << "5- Fechar programa" << endl;

        char option;
        cin >> option;

        if(option == '1')
        {
            string text;
            cout << "Insira o texto desejado: ";
            cin >> text;
        }

        if(option == '2')
        {
            //Cypher Encriptar(text);
        }

        if(option == '3')
        {
            Cypher Desincriptar();
        }

        if(option == '4')
        {
            //Cypher Creator(password); mas passar paremetro para mudar o número da tabela
        }

        if(option == '5')
        {
            break;
        }
    }

    return 0;
}
