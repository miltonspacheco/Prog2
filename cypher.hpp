#ifndef CYPHER_HPP
#define CYPHER_HPP


#include <iostream>
#include <vector>

using namespace std;

class ConversionTable //tabela de conversão
{
    private:
        vector< pair<char,char >> convTable;
        int *m_A;
        

    public: 
        ConversionTable(); //Constructor
        ~ConversionTable(); //Destructor

        void FirstConversionTable(int password);
        void ShowTable();
        char TableInformation(char index);
        int FirstTableIndex(int index);
        int SecondTableIndex(int index);
        size_t tam;
     
};

class Cypher//encriptador e desincriptador 
{
    private:
       
        ConversionTable *table;

    public:
        Cypher(); //Constructor
        ~Cypher(); //Desctructor
        Cypher(int password); 

        string Encrypted(string input);
        string Decrypted(string input);
        void NewConversionTable(int password);
};

#endif