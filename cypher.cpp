#include "cypher.hpp"

//Criação da primeira ConversioTable
ConversionTable::ConversionTable()
{
     m_A = NULL;
}

void ConversionTable::FirstConversionTable(int password)
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
         m_A = new int[1024];
    }
    else
    {
        cout << "Wrong password";
    }
}
 //---------------------------------------------------------------//

Cypher::Cypher()
{
    table = NULL;
}

Cypher::Cypher(int password)
{
    table = new ConversionTable();
    table->FirstConversionTable(password);

    table->ShowTable();
}

Cypher::~Cypher()
{
    if(table) delete table;
}

char ConversionTable::TableInformation(char index)
{
    char cho = convTable.at(index).second;
    return cho;
}

int ConversionTable::FirstTableIndex(int index)
{
    int x;
    x = convTable.at(index).second;
    return x;
}

int ConversionTable::SecondTableIndex(int index)
{
    int x;
    x = convTable.at(index).first;
    return x;
}

string Cypher::Encrypted(string input) //como vou acessar table?
{
    string words = input;
    string result;

    for(size_t i=0; i<words.length(); i++)
    {
        char chi = words.at(i); //input character
        char cho = table->TableInformation(chi);  //output character
        result += cho;
    }
    return result;
}

string Cypher::Decrypted(string input)
{
    string words = input;
    string result;

    for(size_t i=0; i<words.length(); i++)
    {
        char chi = words.at(i);//input character

        for(size_t j=0; j<table->tam; j++)
        {
            if(chi == table->FirstTableIndex(j))
            {
                result += table->SecondTableIndex(j);
                break;
            }
        }
    }
    
    return result;
}

void NewConversionTable(int password)
{

}


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