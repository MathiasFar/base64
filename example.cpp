#include <iostream>
#include "base64.h"

using namespace std;

int main() {
    cout<<b64_encode("Hello World!")<<"\n";
    return 0;
}
