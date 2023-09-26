#include <iostream>

using namespace std;

class RealString{
public:
    string realString;
    int compare(RealString other);
    int length();
};

int RealString::compare(RealString other){
    int leng = length();
    int otherLeng = other.length();
    if(otherLeng>leng){
        return -1;
    } else if(otherLeng==leng){
        return 0;
    }
    return 1;
}

int RealString::length(){
    return this->realString.length();
}

int main()
{
    RealString rs;
    RealString rs2;
    RealString rs3;

    rs.realString = "РАЗ";
    rs2.realString = "ДВА";
    rs3.realString = "ЧЕТЫРЕ";

    cout<<rs.compare(rs2);
    cout<<rs2.compare(rs3);
    cout<<rs3.compare(rs2);
    return 0;
}
