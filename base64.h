#include <bitset>
#include <algorithm>
#include <string>
#include <vector>
std::string b64Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
std::string b64_encode(std::string input) {
    if(input.empty()) return "";
    std::string buffer, output;
    // converts input to 8 bit bytes and stores it in buffer
    for (char ch : input) { buffer += std::bitset<8>(ch).to_string(); }
    // pads buffer so its len%6==0
    int rem = 6 - (buffer.length() % 6);
    buffer.resize(buffer.length() + rem, '0');
    // splits buffer into 6 bit bytes and converts to ascii by using its dec value as an index in b64table
    for (int i = 0; i < buffer.length() - 1; i += 6) {
        std::string element = buffer.substr(i, 6);
        output += b64Alphabet[std::bitset<6>(element).to_ulong()];
    }
    // adds padding
    output.resize(output.length() + (input.length() % 3 == 0 ? 0 : 3 - (input.length() % 3)), '=');
    return output;
}
std::string b64_decode(std::string input) {
    std::string buffer, output;
    // convert base64 char to binary and then concat onto buffer
    for (char ch : input) {
        if (ch != '=') 
            buffer += std::bitset<6>(b64Alphabet.find(ch)).to_string();
    }
    // splits the buffer into 8 bit bytes and converts to ascii
    for (int i = 0; i < buffer.length() - 1; i += 8) {
        std::string element = buffer.substr(i, 8);
        output += (char)std::bitset<8>(element).to_ulong();
    }
    return output;
}
