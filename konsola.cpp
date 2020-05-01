#include "grafyLepsze.h"

int toInt(string s)
{
    int out = 0;
    if(s.size()>0)
    {
        if(s[0] < '0' || s[0] > '9')
                return -1;
        out = s[0] - '0';
        for(int i=1;i<s.size();i++)
        {
            if(s[i] < '0' || s[i] > '9')
                return -1;
            out *= 10;
            out += s[i] - '0';
        }
    }
    return out;
}

string toString(int i)
{
    string out = "";
    bool minus = i<0;
    if(minus)
        i *= -1;
    while(i>0)
    {
        out = (char)(i%10+'0') + out;
        i/=10;
    }
    if(minus)
        return "-" + out;
    return out;
}

int zKonsoli(int minv, int maxv, string komunikat, string blad)
{
    int out = -1;
    do
    {
        cout << komunikat;
        string s;
        cin >> s;
        out = toInt(s);
        if(out == -1 || out < minv || out > maxv)
            cout << blad << endl;
    }while(out == -1 || out < minv || out > maxv);
    return out;
}

int zKonsoli(string komunikat, string blad)
{
    return zKonsoli(0, 32767, komunikat, blad);
}

void wypEl(int element)
{
    cout<<element;
    for (int i=0;i<to_string(v).size()+2-to_string(element).size();i++) cout<<" ";
}
