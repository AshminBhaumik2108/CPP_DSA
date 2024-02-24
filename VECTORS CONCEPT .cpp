// USING VECTORS......
/*

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void Name(vector<double> &a, int n, vector<double> &b, int m)
{
    int tot = 0; //cout<<tot;
    vector<float> sum(tot);
    //cout<<sum.size();
    //sum.clear();
    sum.insert(sum.begin(), a.begin(), a.end());
    sum.insert(sum.end(), b.begin(), b.end());

    for(auto i : sum) {cout<<fixed<<setprecision(2)<<i<<" ";}
}

int main()
{
    int n, m; cin>>n>>m;
    vector<double> a(n), b(n);
    for(int i=0; i<n; i++) {cout<<" * "; cin>>a[i];}
    for(int i=0; i<m; i++) {cout<<" ** "; cin>>b[i];}
    Name(a, n, b, m);
}

#include<iostream>
#include<iomanip>
using namespace std;

class TemperatureConverter
{
    private:
      double celsius;
    public:
      void setCelsius(double temp)
      {
          celsius = temp;
      }

      double getCelsius();
      double getFahrenheit();
      double getKelvin();
};

double TemperatureConverter::getCelsius()
{
    return celsius;
}

double TemperatureConverter::getFehrenheit()
{
    return celsius*(9/5) + 32;
}

double TemperatureConverter::getKelvin()
{
    return celsius + 273.15;
}

int main()
{
    TemperatureConverter c;
    double celsius;

    cin>>celsius;
    c.setCelsius(celsius);
    double a = c.getFahrenheit();
    double b = c.getKelvin();

    cout<<"Temperature in Fahrenheit: "<<fixed<<setprecision(2)<<a<<endl;
    cout<<"Temperature in Kelvin: "<<fixed<<setprecision(2)<<b<<endl;
}

*/
