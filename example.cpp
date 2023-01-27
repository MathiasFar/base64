#include <iostream>
#include <string>
#include "base64.h"

using namespace std;

int main() {
    string example_string{"test phrase"};
    string x = b64_encode(example_string);
    cout<<"Base64 Encoded: "<<x<<"\n";
    cout<<"Base64 Decoded: "<<b64_decode(x)<<"\n";
    return 0;
}
