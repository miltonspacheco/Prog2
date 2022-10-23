#include "cypher.hpp"


//Criação da Primeira ConversionTable
ConversionTable::ConversionTable()
{
     m_A = NULL;
}

void ConversionTable::CreateConversionTable(int password) //: ConversionTable()
{  
    int pass = 0;
    int size = 1;
    int limit = 10;

    while ( password >= limit ) 
    {
        size++;
        limit *= 10;
    }
    
    m_A = new int[size];

    for ( int i = 0 ; i < size ; i++ ) 
    {
        limit /= 10;
        m_A[i] = (password / limit) % 10;
    }

    for (int i = 0 ; i < size ; i++) 
    {
        pass += m_A[i];
    }

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

//Acessos a ConvTable
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



//Nova ConversionTable
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