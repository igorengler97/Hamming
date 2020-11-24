#include <iostream>
#include <vector>
#include <string>

int SindromeToDec(std::vector<int> newC)
{
    return(newC.at(0)*1+newC.at(1)*2+newC.at(2)*4+newC.at(3)*8+newC.at(4)*16);
}

std::string reverseString(std::string reverse)
{
    for (int i = 0; i<21/2;i++)
    {
        std::swap(reverse[i], reverse[21-i-1]);
    }
    return reverse;
}

std::string hamming(std::string input)
{
    std::vector<int> newC;

    newC.push_back(((input[18]-'0')^(input[16]-'0')^(input[14]-'0')^(input[11]-'0')^(input[10]-'0')^(input[8]-'0')^(input[6]-'0')^(input[4]-'0')^(input[2]-'0')^(input[0]-'0')^(input[20]-'0')));
    newC.push_back(((input[18]-'0')^(input[15]-'0')^(input[14]-'0')^(input[12]-'0')^(input[11]-'0')^(input[10]-'0')^(input[7]-'0')^(input[6]-'0')^(input[3]-'0')^(input[2]-'0')^(input[19]-'0')));
    newC.push_back(((input[16]-'0')^(input[15]-'0')^(input[14]-'0')^(input[9]-'0')^(input[8]-'0')^(input[7]-'0')^(input[6]-'0')^(input[1]-'0')^(input[0]-'0')^(input[17]-'0')));
    newC.push_back(((input[12]-'0')^(input[11]-'0')^(input[10]-'0')^(input[9]-'0')^(input[8]-'0')^(input[7]-'0')^(input[6]-'0')^(input[13]-'0')));
    newC.push_back(((input[4]-'0')^(input[3]-'0')^(input[2]-'0')^(input[1]-'0')^(input[0]-'0')^(input[5]-'0')));

    int cXor = SindromeToDec(newC);
    if(cXor != 0){
        std::string reverse = reverseString(input);
        for (int i = 0; i<21; i++)
        {
            if(cXor-1 == i)
            {
                std::cout<<"Error found on bit "<<cXor<<std::endl;
                if(reverse[i] == '1'){
                    reverse[i] = '0';
                }
                else if(reverse[i] == '0')
                {
                    reverse[i] = '1';
                }
            }
            input = reverseString(reverse);
        }
    }
    else{
        std::cout<<"No error found"<<std::endl;
    }
    std::string output;
    output = std::string() + input[0]+input[1]+input[2]+input[3]+input[4]+input[6]+input[7]+input[8]+input[9]+input[10]+input[11]+input[12]+input[14]+input[15]+input[16]+input[18];
    return output;

}

int main()
{
    std::string input;
    int N = 0;
    std::cout<<"Insert the amount of verifications to be done: ";
    std::cin>>N;

    while(N>0){
        std::cin>>input;
        std::cout<<hamming(input)<<std::endl<<std::endl;
        N=N-1;
    }
}
