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
        cout << "1- Encriptografar" << endl;
        cout << "2- Regerar table de conversão" << endl;
        cout << "3- Fechar programa" << endl;

        char option;
        cin >> option;

        string text;
        cout << "Insira o texto desejado: ";
        cin >> text;


        if(option == '1')
        {
            string encrypted = Creator.Encrypted(text);
            cout << "Original text: "  << text << endl;
            cout << "--------------------------------" << endl;
            cout << "Encrypted text: " << encrypted << endl;

            cout << "Digite 1 para Deseincriptografar o texto e 2 para voltar ao menu "<< endl;
            char resposta;
            cin >> resposta;

            if (resposta == '1')
            {
                string decrypted = Creator.Decrypted(encrypted);
                cout << "--------------------------------" << endl;
                cout << "Reverted text: "  << decrypted << endl;
            }
            else if (resposta == '2')
            {
                break;
            }
        }

        if(option == '2')
        {
            int newpassword;
            cout << "Enter other password to create a new Conversion Table: ";
            cin >> newpassword;
            Creator.NewConversionTable(newpassword);
        }

        if(option == '3')
        {
            break;
        }
    }

    return 0;
}
