#include <iostream>
#include <string>
#include "base64.h"

using namespace std;

int main() {
    string example_string{"test phrase"};
    string x = b64_encode(example_string);
    cout<<"Base64 Encoded: "<<x<<"\n";
    cout<<"Base64 Decoded: "<<b64_decode(x)<<"\n";
    cout<<"<---------------------------->\n";
    cout<<b64_encode("")<<endl;
    cout<<b64_encode("a")<<endl;
    cout<<b64_encode("ab")<<endl;
    cout<<b64_encode("abc")<<endl;
    cout<<b64_encode("abcd")<<endl;
    cout<<b64_encode("abcde")<<endl;
    cout<<b64_encode("abcdef")<<endl;
    return 0;
}
