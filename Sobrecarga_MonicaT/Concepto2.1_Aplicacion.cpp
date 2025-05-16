#include <iostream>
using namespace std;

class Punto{
public:
    int x,y;
    Punto(int a,int b): x(a), y(b){}

    bool operator==(const Punto& otro){
        return x==otro.x && y==otro.y;
    }

};

int main(){
    Punto a(5,5),b(5,5),c(5,6);
    cout<<"a==b: "<<(a==b)<<endl;
    cout<<"a==c: "<<(a==c)<<endl;

    return 0;
}
