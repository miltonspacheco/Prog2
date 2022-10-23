#include "cypher.hpp"

int main ()
{
    int password;
    cout << "Enter with your student code to create your Conversion Table: ";
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

        if(option == '1')
        {
            string text;
            cout << "Insira o texto desejado: ";
            cin >> text;

            string encrypted = Creator.Encrypted(text);
            cout << "--------------------------------" << endl;
            cout << "Original text: "  << text << endl;
            cout << "Encrypted text: " << encrypted << endl << endl;

            cout << "-Insira- "<< endl;
            cout << "1 - Desincriptografar "<< endl;
            cout << "2 - Voltar ao menu "<< endl;
            char resposta;
            cin >> resposta;

            if (resposta == '1')
            {
                string decrypted = Creator.Decrypted(encrypted);
                cout << "--------------------------------" << endl;
                cout << "Reverted text: "  << decrypted << endl << endl;
            }
            else if (resposta == '2')
            {
                continue;
            }
        }

        if(option == '2')
        {
            int newpassword;
            cout << "Enter with other student code to create a new Conversion Table: ";
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
