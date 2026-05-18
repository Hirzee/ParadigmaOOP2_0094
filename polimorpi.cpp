#include <iostream>
using namespace std;

class seseorang {
public:
    virtual void pesan() = 0;
    // virtual voidpesan(){
    //  cout<< "Pesan dari seseorang"<<endl;
    //}
};

class joko :public seseorang {

