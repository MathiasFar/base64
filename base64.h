#include <vector>
#include <string>
#include <cstring>
#include <bitset>

std::string b64table{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-"};

std::string b64_encode (std::string input) {
    // converts input to 8 bit bytes and stores it in buffer
    std::string buffer;
    std::string output;
    for(auto &ch : input) {
        std::bitset<8> byte(ch); 
        buffer+=byte.to_string();
    }
    // pads buffer so its len%6==0
    int rem = (buffer.length()%6);
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
        groups.push_back(element);
    }
    // converts the 6 bit bytes to ascii by using its dec value as an index in b64table
    for(auto &e : groups) {
        output+=b64table[strtol(e.c_str(), nullptr, 2)];
    }
    for(int i = 0; i < rem; ++i) {output+="=";}
    return output;
}
