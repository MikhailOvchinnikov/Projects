#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Rational {
private:
    int up_figure;
    int down_figure;
public:
    Rational() {
        up_figure = 0;
        down_figure = 1;
    }

    Rational(int numerator, int denominator) {
        if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0))
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        else if (numerator == 0)
        {
            denominator = 1;
        }

        int temp_n = abs(numerator);
        int temp_d = abs(denominator);

        while (temp_n > 0 && temp_d > 0)
        {
            if (temp_n > temp_d)
            {
                temp_n %= temp_d;
            }
            else
            {
                temp_d %= temp_n;
            }
        }
        up_figure = numerator / (temp_n + temp_d);
        down_figure = denominator / (temp_n + temp_d);
        
       
    }

    int Numerator() const {
        return up_figure;
    }

    int Denominator() const {
        return down_figure;
    }



};

bool operator==(const Rational& left, const Rational& right)
{
    return (left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator());
}

Rational operator+(const Rational& left, const Rational& right)
{
    int up;
    int down;
    up = left.Numerator() * right.Denominator() + right.Numerator() * left.Denominator();
    down = left.Denominator()*right.Denominator();
    return { up, down };
}
Rational operator-(const Rational& left, const Rational& right)
{
    int up;
    int down;
    up = left.Numerator() * right.Denominator() - right.Numerator() * left.Denominator();
    down = left.Denominator()*right.Denominator();
    return { up, down };
}

Rational operator*(const Rational& left, const Rational& right)
{
    int up;
    int down;
    up = left.Numerator() * right.Numerator();
    down = left.Denominator() * right.Denominator();
    return { up, down };
}

Rational operator/(const Rational& left, const Rational& right)
{
    int up;
    int down;
    up = left.Numerator() * right.Denominator();
    down = left.Denominator() * right.Numerator();
    return { up, down };
}

istream& operator>>(istream& stream, Rational& u_d)
{
    int up;
    int down;
    char temp;
    if (stream >> up && stream >> temp && stream >> down)
    {
        if (temp == '/')
        {
            u_d = { up, down };
        }
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& u_d)
{
    stream << u_d.Numerator() << '/' << u_d.Denominator();
    return stream;
}

bool operator<(const Rational& f, const Rational& s)
{
    return f.Numerator() / (double)f.Denominator() < s.Numerator() / (double)s.Denominator();
}

bool operator>(const Rational& f, const Rational& s)
{
    return f.Numerator() / (double)f.Denominator() > s.Numerator() / (double)s.Denominator();
}

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
