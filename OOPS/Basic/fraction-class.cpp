class  Fraction
{
private:
   int numerator;
   int denominator;

public:
    Fraction(int numerator, int denominator);
    this->numerator = numerator;   // this pointer is used to differentiate between class member and parameter
    this->denominator = denominator;

    void print(){
        cout << this->numerator << "/" << denominator << endl;

    }
    void simplify(){
        int gcd = 1;
        int j = min(numerator, denominator);
        for(int i=1; i<=j; i++){
            if(numerator % i == 0 && denominator % i == 0){
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;

    }

    void add(Fraction const & f2){ // f2 is another fraction which we are adding to current fraction
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify(); 
     // this will simplify the fraction after addition
    }
    void multiply(Fraction const & f2){ // f2 is another fraction which we are multiplying to current fraction
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
    }



};
