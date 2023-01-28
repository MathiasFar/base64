#include <iostream>
#include <string>
#include "base64.h"

using namespace std;

int main() {
    string example_string{"test phrase"};
    string x = b64::encode(example_string);
    cout<<"Base64 Encoded: "<<x<<"\n";
    cout<<"Base64 Decoded: "<<b64::decode(x)<<"\n";
    cout<<"<---------------------------->\n";
    cout<<b64::encode("")<<endl;
    cout<<b64::encode("a")<<endl;
    cout<<b64::encode("ab")<<endl;
    cout<<b64::encode("abc")<<endl;
    cout<<b64::encode("abcd")<<endl;
    cout<<b64::encode("abcde")<<endl;
    cout<<b64::encode("abcdef")<<endl;
    return 0;
}
