#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int sindromeToDec(std::vector<int> novoC)
{
    return(novoC.at(0)*1+novoC.at(1)*2+novoC.at(2)*4+novoC.at(3)*8+novoC.at(4)*16);
}

std::string reverseString(std::string inverter)
{
    for (int i = 0; i<21/2;i++)
    {
        std::swap(inverter[i], inverter[21-i-1]);
    }
    return inverter;
}

void hamming(std::string entrada)
{
    std::vector<int> novoC;

    novoC.push_back(((entrada[18]-'0')^(entrada[16]-'0')^(entrada[14]-'0')^(entrada[11]-'0')^(entrada[10]-'0')^(entrada[8]-'0')^(entrada[6]-'0')^(entrada[4]-'0')^(entrada[2]-'0')^(entrada[0]-'0')^(entrada[20]-'0')));
    novoC.push_back(((entrada[18]-'0')^(entrada[15]-'0')^(entrada[14]-'0')^(entrada[12]-'0')^(entrada[11]-'0')^(entrada[10]-'0')^(entrada[7]-'0')^(entrada[6]-'0')^(entrada[3]-'0')^(entrada[2]-'0')^(entrada[19]-'0')));
    novoC.push_back(((entrada[16]-'0')^(entrada[15]-'0')^(entrada[14]-'0')^(entrada[9]-'0')^(entrada[8]-'0')^(entrada[7]-'0')^(entrada[6]-'0')^(entrada[1]-'0')^(entrada[0]-'0')^(entrada[17]-'0')));
    novoC.push_back(((entrada[12]-'0')^(entrada[11]-'0')^(entrada[10]-'0')^(entrada[9]-'0')^(entrada[8]-'0')^(entrada[7]-'0')^(entrada[6]-'0')^(entrada[13]-'0')));
    novoC.push_back(((entrada[4]-'0')^(entrada[3]-'0')^(entrada[2]-'0')^(entrada[1]-'0')^(entrada[0]-'0')^(entrada[5]-'0')));

    int cXor = sindromeToDec(novoC);
    if(cXor != 0){
        std::string reversa = reverseString(entrada);
        for (int i = 0; i<21; i++)
        {
            if(cXor-1 == i)
            {
                if(reversa[i] == '1'){
                    reversa[i] = '0';
                }
                else if(reversa[i] == '0')
                {
                    reversa[i] = '1';
                }
            }
            entrada = reverseString(reversa);
        }
    }
    std::string saida;
    saida = std::string() + entrada[0]+entrada[1]+entrada[2]+entrada[3]+entrada[4]+entrada[6]+entrada[7]+entrada[8]+entrada[9]+entrada[10]+entrada[11]+entrada[12]+entrada[14]+entrada[15]+entrada[16]+entrada[18];
    std::cout<<saida<<std::endl;

}

int main()
{
    std::ifstream arquivo("entrada.txt");
    std::string texto;
    int linhas=0;
    int N = 0;
    std::cin>>N;

    while(getline (arquivo, texto ) && N>0){
        hamming(texto);
        N=N-1;
    }
}