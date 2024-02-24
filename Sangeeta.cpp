#include<iostream>
#include<iomanip>
using namespace std;

class Money
{
private:
    int rupee;
    int paisa;
    float p;
public:
    double getters()
    {
        cin>>rupee>>paisa;
    }
    double setters()
    {
        p = paisa/100;
    }
    float constructor()
    {
        return rupee+p;
    }
};

int main()
{
    double total=0;
    Money m, n;
       m.getters();
       m.setters();
       float tot = m.constructor();
       n.getters();
       n.setters();
       float to = n.constructor();
       total = tot + to;
    cout<<fixed<<setprecision(2)<<total<<endl;
}










