#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;

int x=0;
// Pads int with leading zeros returns string
string padInt(int n) {
	stringstream ss;
	ss<<n;
	string a;
	ss>>a;
	int strLen=a.length();
	for(int i=0;i<8-strLen;++i) {
		a="0"+a;
	}
	return a;
}

string padStr(string str, int n) {
	int strLen=str.length();
	for(int i=0;i<n;++i) {
		str=str+="0";
	}
	return str;
}
// returns binary representation of int 
void bin(unsigned n) {
    if(n > 1) 
        bin(n>>1);
    x*=10;
    x += n&1;
}
// Calls bin and resets x
int binCaller(unsigned n) {
    x=0;
    bin(n);
    return x;
}

// converts string to 6 bit groups and pads
vector<string> splitString(string str) {
    vector<string> groups;
    str = padStr(str, 6-(str.length()%6));
    for(int i=0; i<str.length()-1;i+=6) {
        string element;
        for(int j = 0; j < 6; ++j) {
            element += str[i+j];
        }
        groups.push_back(element);
    }
    return groups;
}

int bin2dec(string bin) {
    int dec=0, i=0, rem;
    int n = stoi(bin);
    while(n!=0) {
        rem = n%10;
        n/=10;
        dec+=rem*pow(2,i);
        ++i;
    }
    return dec;
}

char dec2base(int dec) {
    if(dec >= 0 and dec<=25) {
        return 'A'+dec;
    } else if(dec >= 26 and dec<=51) {
        return 'a'+(dec-26);
    } else if(dec > 52 and dec<=61) {
        return (char)(dec-52);
    } else {
        return '_';
    }
}

int main(int argc,char* argv[]) {
    string buffer = "";
    if(argc > 1) {
        for(int i=1;i<argc;++i){
            int j=0;
            while(argv[i][j]!=NULL) {
                buffer+=padInt(binCaller((int)argv[i][j]));
                ++j;
            }
        }
        vector<string> groups = splitString(buffer);
        for(string x : groups) {
            int a = bin2dec(x);
            cout<<dec2base(a);
        }
    } else {
        cout<<"Error: No Arguments passed"<<endl;
        return -1;
    }
    return 0;
}
