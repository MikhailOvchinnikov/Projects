

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <typeinfo>

using namespace std;


class FunctionPart
{

public:
    FunctionPart(char op, double v)
    {
        my_operator = op;
        value = v;
    }
    double Apply(double qual) const
    {
        if (my_operator == '+')
        {
            return qual + value;
        }
        else if (my_operator == '-')
        {
            return qual - value;
        }
        else if (my_operator == '*')
        {
            return qual * value;
        }
        else
        {
            return qual / value;
        }
    }
    void Invert()
    {
        if (my_operator == '+')
        {
            my_operator = '-';
        }
        else if (my_operator == '-')
        {
            my_operator = '+';
        }
        else if (my_operator == '*')
        {
            my_operator = '/';
        }
        else
        {
            my_operator = '*';
        }
    }
private:
    char my_operator;
    double value;
};

class Function
{

public:
    void AddPart(char new_operator, double val)
    {
        parts.push_back({ new_operator, val });
    }

    double Apply(double qual) const
    {
        for (const auto& i : parts)
        {
            qual = i.Apply(qual);
        }
        return qual;
    }
    void Invert()
    {
        for (auto& i : parts)
        {
            i.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

Function MakeWeightFunction(const Params& params,
    const Image& image) {
    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
    const Image& image,
    double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = { 10, 2, 6 };
    Params params = { 4, 2, 6 };
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;
    return 0;
}