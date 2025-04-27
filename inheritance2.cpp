//GT Inheritance 2
#include <iostream>
#include <string>

using namespace std;

class Number{
    private:
        int rawValue;

    public:
        Number(int rawValue) : rawValue(rawValue){}

        //Getter
        int getRawValue(){ return rawValue; }

        //Setter
        void setRawValue(int rv){ rawValue = rv; }
};

class WholeNumber: public Number{
    private:
        int value;

    public:
        WholeNumber(int value) : Number(value), value(value){}

        //Getter
        int getWholeNumber(){ return value; }

        //Setter
        void setWholeNumber(int v){ value = v; setRawValue(v); }

        void multiply(WholeNumber otherWhole){
            int product = getRawValue()*otherWhole.getWholeNumber();
            setRawValue(product);
            value = product;
        }
        
        string toString(){
            return to_string(value);
        }

};

class DecimalNumber: public Number{
    private:
        int decimalPlaces;
    
    public:
        DecimalNumber(WholeNumber wholeNumber, int decimalPlaces) 
        : Number(wholeNumber.getWholeNumber()), decimalPlaces(decimalPlaces){}

        //Getter
        int getDecimalPlaces(){ return decimalPlaces; }

        //Setter
        void setDecimalPlaces(int dp){ decimalPlaces = dp; }

        void multiply(DecimalNumber decimalNumber){
            int product = getRawValue()*decimalNumber.getRawValue();
            setRawValue(product);
            decimalPlaces += decimalNumber.getDecimalPlaces();
        }

        string toString(){
            return "0." + to_string(getRawValue()) + " (decimal places: " + to_string(getDecimalPlaces()) + ")";
        }
};

void optionWN(){
    int x;
    cout<<"Enter first whole number: ";
    cin>>x;
    WholeNumber num1(x);
    cout<<"Enter second whole number: ";
    cin>>x;
    WholeNumber num2(x);
    num1.multiply(num2);
    cout<<"Whole Number Result (Multiplication): "<<num1.toString()<<endl;
}

void optionDN(){
    int x, y;
    cout<<"Enter first decimal number's raw value (e.g 125 for 1.25): ";
    cin>>x;
    cout<<"Enter number of decimal places for first decimal: ";
    cin>>y;
    DecimalNumber dnum1(x,y);

    cout<<"Enter second decimal number's raw value (e.g 20 for 0.20): ";
    cin>>x;
    cout<<"Enter number of decimal places for second decimal: ";
    cin>>y;
    DecimalNumber dnum2(x,y);
    dnum1.multiply(dnum2);

    cout<<"DecimalNumber Result (Multiplication): "<<dnum1.toString()<<endl;

}

int main(){

    optionWN();
    cout<<endl;
    optionDN();

    return 0;
}