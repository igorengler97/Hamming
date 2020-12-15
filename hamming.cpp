#include <iostream>
#include <vector>
#include <string>

int SindromeToDec(std::vector<int> newC)
{
    return(newC.at(0)*1+newC.at(1)*2+newC.at(2)*4+newC.at(3)*8+newC.at(4)*16);
}

void printHamming(std::string input)
{
    for (int i=0 ; i<16;i++){
        std::cout<<input[i];
    }
    std::cout<<std::endl;
}

void verifyBit(std::string input, int num)
{
    if (input[num] == '0'){
        input[num] = '1';
    }
    else if (input[num] == '1'){
        input[num] = '0';
    }
    printHamming (input);
}

void hamming(std::string input)
{
    std::vector<int> newC;
    newC.push_back(((input[15]-'0')^(input[14]-'0')^(input[12]-'0')^(input[11]-'0')^(input[9]-'0')^(input[7]-'0')^(input[5]-'0')^(input[4]-'0')^(input[2]-'0')^(input[0]-'0')^(input[20]-'0')));
    newC.push_back(((input[15]-'0')^(input[13]-'0')^(input[12]-'0')^(input[10]-'0')^(input[9]-'0')^(input[6]-'0')^(input[5]-'0')^(input[3]-'0')^(input[2]-'0')^(input[19]-'0')));
    newC.push_back(((input[14]-'0')^(input[13]-'0')^(input[12]-'0')^(input[8]-'0')^(input[7]-'0')^(input[6]-'0')^(input[5]-'0')^(input[1]-'0')^(input[0]-'0')^(input[18]-'0')));
    newC.push_back(((input[11]-'0')^(input[10]-'0')^(input[9]-'0')^(input[8]-'0')^(input[7]-'0')^(input[6]-'0')^(input[5]-'0')^(input[17]-'0')));
    newC.push_back(((input[4]-'0')^(input[3]-'0')^(input[2]-'0')^(input[1]-'0')^(input[0]-'0')^(input[16]-'0')));

    int cXor = SindromeToDec(newC);
    if (cXor == 0){
        printHamming(input);
    }
    else if (cXor == 3) {
        verifyBit(input, 21 - cXor - 3);
    }
    else if (cXor>= 5 && cXor<=7){
        verifyBit(input, 21 - cXor - 2);
    }
    else if (cXor >=9 && cXor <=15){
        verifyBit(input, 21 - cXor - 1);
    }
    else if (cXor >=17 && cXor <=21){
        verifyBit(input, 21 - cXor - 0);
    }
}

int main()
{
    std::string input;
    int N = 0;
    //std::cout<<"Insert the amount of verifications to be done: ";
    std::cin>>N;

    while(N>0){
        std::cin>>input;
        hamming(input);
        N=N-1;
    }
    system("pause");
    return 0;
}
