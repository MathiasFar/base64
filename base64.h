#include <bitset>
#include <algorithm>
#include <string>
#include <vector>
const char b64Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
std::string b64_encode (std::string input) {
    // converts input to 8 bit bytes and stores it in buffer
    std::string buffer;
    std::string output;
    for(auto &ch : input) {
        std::bitset<8> byte(ch); 
        buffer+=byte.to_string();
    }
    // pads buffer so its len%6==0
    int rem = 6-(buffer.length()%6);
    std::vector<std::string> groups;
    for(int i = 0; i <= rem; ++i) {
        buffer+="0";
    }
    // splits buffer into 6 bit bytes
    for(int i = 0; i < buffer.length()-1; i+=6) {
        std::string element;
        for(int j = 0; j < 6; ++j) {
            element+=buffer[i+j];
        }
        groups.push_back("00"+element);
    }
    // converts the 6 bit bytes to ascii by using its dec value as an index in b64table
    for(auto &e : groups) {
        output+=b64Alphabet[strtol(e.c_str(), nullptr, 2)];
    }
    for(int i = 0; i < 3-(input.length()%3); ++i) {
        if(input.length()%3!=0)
            output+="=";
    }
    return output;
}
