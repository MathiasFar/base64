#include <iostream>
#include "base64.h"

using namespace std;

int main() {
    cout<<b64_encode("test123")<<"\n";
    cout<<b64_encode("test with space")<<"\n";
    return 0;
}
