#include <iostream>
#include <sstream>
#include<vector>
#include<string>
#include <numeric> //make gcd function 
#include<math.h>
#include<map>
#include <set>

using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }
    Rational(int numerator, int denominator) {

        if (numerator == 0) {
            denom = 1;
            num = 0;
        }
        if (denominator==0) {
            throw invalid_argument("Invalid argument");
        }
        else {
            if (denominator < 0 && numerator < 0) {
                num = abs(numerator);
                denom = abs(denominator);
            }
            else if (denominator < 0 && numerator>0) {
                num = numerator * (-1);
                denom = abs(denominator);
            }
            else if (denominator > 0 && numerator < 0) {
                num = numerator;
                denom = abs(denominator);
            }
            else if (denominator > 0 && numerator > 0) {
                num = numerator;
                denom = denominator;
            }
        }

        nod = gcd(num, denom);
        if (nod != 0) {
            num = num / nod;
            denom = denom / nod;
        }
    }

    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return denom;
    }

private:
    int num, denom;
    int nod = 0;
};

bool operator==(Rational a, Rational b) {
    if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator())) {
        return true;
    }
    else return false;
}
Rational operator + (Rational a, Rational b) {
    int an = ((a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator()));
    int dn = (a.Denominator() * b.Denominator());
    return Rational(an, dn);
}
Rational operator - (Rational a, Rational b) {
    int an = ((a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator()));
    int dn = (a.Denominator() * b.Denominator());
    return Rational(an, dn);
}
Rational operator * (Rational a, Rational b) {
    return Rational((a.Numerator() * b.Numerator()), (a.Denominator() * b.Denominator()));
}
Rational operator / (Rational a, Rational b) {
    if (a.Numerator() == 0) {
        throw domain_error("Domain error");
    };
    if (b.Numerator() == 0) {
        throw domain_error("Domain error");
    };
    return Rational((a.Numerator() * b.Denominator()), (a.Denominator() * b.Numerator()));
}
istream& operator >> (istream& stream, Rational& r) {
    int n, d;
    char c;
    stream >> n >> c >> d;
    if (stream && c == '/') {
        r = Rational(n, d);
    }
    return stream;
}
ostream& operator << (ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}
bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}

int main() {
    try {
    char oper;
    Rational a;
    Rational b;
    cin >> a >> oper >> b;
    if (oper == '+')cout << a + b;
    else if (oper == '-')cout << a - b;
    else if (oper == '/')cout << a / b;
    else if (oper == '*')cout << a * b;
    }
    catch (exception&ex) {
        cout << ex.what();
    }
    return 0;
}