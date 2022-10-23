#include "cypher.hpp"

ConversionTable::ConversionTable()
{
     m_A = NULL;
}

void ConversionTable::CreateConversionTable(int password)
{  
    int pass = password/5;
        for(size_t i=0; i<256; i++)
        {
            pair<char,char> p;
            p.first = i;
            p.second = p.first + pass;
            this->convTable.push_back(p);
        }
}

Cypher::Cypher()
{
    table = NULL;
}

Cypher::Cypher(int password)
{
    table = new ConversionTable();
    table->CreateConversionTable(password);
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

string Cypher::Encrypted(string input) 
{
    string words = input;
    string result;

    for(size_t i=0; i<words.length(); i++)
    {
        char chi = words.at(i); 
        char cho = table->TableInformation(chi);  
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
        char chi = words.at(i);

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

void Cypher::NewConversionTable(int password) 
{
    table = NULL;
    table = new ConversionTable();
    table->CreateConversionTable(password);
}


//Destrutores 
ConversionTable::~ConversionTable()
{
    if(m_A) delete m_A;
}

Cypher::~Cypher()
{
    if(table) delete table;
}