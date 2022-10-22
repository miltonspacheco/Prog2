#include "cypher.hpp"

ConversionTable::ConversionTable(int password)
{
    if(password==22104547)
    {
    for(size_t i=0; i<256; i++)
    {
        pair<char,char> p;
        p.first = i;
        p.second = p.first + 10;
        this->convTable.push_back(p);
    }
    }
    else
    {
        cout << "Wrong password";
    }
}

Cypher::Cypher(int password)
{
    int senha;
    senha=password;

    ConversionTable *table = new ConversionTable(senha);
}

/*
Cypher::Cypher(string input)
{
    string result;

    for(size_t i=0; i<input.length(); i++)
    {
        char chi = input.at(i); //input character
        char cho = *table.at(chi).second;  //output character
        result += cho;
    }
}




void Cypher::ShowEncrypted()
{
    cout << "Original text: "  << this->input << endl;
    cout << "--------------------------------" << endl;
    cout << "Encrypted text: " << this->result << endl;
}

*/
void ConversionTable::ShowTable()
{
    for(size_t i=0; i<this->convTable.size(); i++)
    {
        char orig = this->convTable.at(i).first;
        char dest = this->convTable.at(i).second;

        cout << " Orig: " << (char) orig << " - " << (int) orig << " -> " <<
        " Destino: " << (char) dest << " - " << (int) dest << endl;
    }
}