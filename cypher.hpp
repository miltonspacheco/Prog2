#ifndef CYPHER_HPP
#define CYPHER_HPP


#include <iostream>
#include <vector>

using namespace std;

class ConversionTable //tabela de conversão
{
    private:
        vector< pair<char,char >> convTable;

    public: 
        ConversionTable(int password); //Constructor

        void ShowTable();
        
};

class Cypher//encriptador e desincriptador 
{
    private:
        string encrypted;
        string decrypted;
        vector< pair<char,char >> *table;
        

    public:
        Cypher(int password); //Constructor
        Cypher(string input); 

        void ShowEncrypted();
};

#endif