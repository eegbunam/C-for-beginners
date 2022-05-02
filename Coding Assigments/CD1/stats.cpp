#include "stats.h"
using namespace main_savitch_2C;



statistician::statistician()
{
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;


}

void statistician::next(double r)
{
    if (count == 0)
    {
        tinyest = r;
        largest = r;
    }
    else
    {
        if (r < tinyest)
        {
            tinyest = r;
        }
        if (r > largest)
        {
            largest = r;
        }
    }
    total += r;
    count++;
    data.push_back(r);
}

void statistician::reset()
{
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
    data.clear();
}

int statistician::length() const
{
    return count;
}

double statistician::sum() const
{
    return total;
}

double statistician::mean() const
{
    if (length() == 0){ return 0; } 
    return total / count;
}

double statistician::minimum() const
{
    if (length() == 0){ return 0; }
    return tinyest;
}

double statistician::maximum() const
{
    if (length() == 0){ return 0; }
    return largest;
}

statistician operator + (const statistician& s1, const statistician& s2)
{
    statistician s3;
    for (int i = 0; i < s1.data.size(); i++)
    {
        s3.next(s1.data[i]);
    }
    for (int i = 0; i < s2.data.size(); i++)
    {
        s3.next(s2.data[i]);
    }
    return s3;
}

statistician operator *( double scale , const statistician& s)
{
    statistician s3;
    for (int i = 0; i < s.data.size(); i++)
    {
        s3.next(s.data[i] * scale);
    }
    return s3;
}

bool operator ==(const statistician &s1 , const statistician &s2)
{

    if(s1.length() == 0 && s2.length() == 0) { return true; }

    bool length = s1.length() == s2.length();
    bool mean = s1.mean() == s2.mean();
    bool minimum = s1.minimum() == s2.minimum();
    bool maximum = s1.maximum() == s2.maximum();

    return length && mean && minimum && maximum;
}


// bool test(statistician s1 , statistician s2){
//     cout << s1.testNumber << " " << s2.testNumber << endl;
// }