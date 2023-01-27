#include <bitset>
#include <algorithm>
#include <string>
#include <vector>
std::string b64Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
std::string b64_encode(std::string input) {
    // converts input to 8 bit bytes and stores it in buffer
    std::string buffer;
    std::string output;
    for(auto &ch:input) {
        std::bitset<8>byte(ch); 
        buffer+=byte.to_string();
    }
    // pads buffer so its len%6==0
    int rem=6-(buffer.length()%6);
    std::vector<std::string>bytes;
    for(int i=0;i<=rem;++i) {
        buffer+="0";
    }
    // splits buffer into 6 bit bytes
    for(int i=0; i<buffer.length()-1; i+=6) {
        std::string element;
        for(int j=0;j<6;++j) {
            element+=buffer[i+j];
        }
        bytes.push_back("00"+element);
    }
    // converts the 6 bit bytes to ascii by using its dec value as an index in b64table
    for(auto &e:bytes) {
        output+=b64Alphabet[strtol(e.c_str(),nullptr,2)];
    }
    for(int i=0;i< 3-(input.length()%3);++i) {
        if(input.length()%3!=0)
            output+="=";
    }
    return output;
}
std::string b64_decode(std::string input) {
    std::string buffer;
    std::string output;
    // convert base64 char to binary and then concat onto buffer
    for(auto &ch:input) {
        for(int i=0;i<b64Alphabet.length();++i) {
            if((char)b64Alphabet[i]==ch) {
                std::bitset<6>byte(i);
                buffer+=byte.to_string();
            }
        }
    }
    // splits the buffer into 8 bit bytes and discards the remainding
    std::vector<std::string>bytes;
    for(int i=0;i<buffer.length()-1;i+=8) {
        std::string element;
        for(int j=0;j<8;++j) {
            element+=buffer[i+j];
        }
        bytes.push_back(element);
    }
    for(auto &e:bytes) {
        output+=(char)strtol(e.c_str(),nullptr,2);
    }
    return output;
}
