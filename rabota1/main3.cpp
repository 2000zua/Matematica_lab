#include <iostream>
#include <vector>

using namespace std;

void generateGrayCode(vector<string>& grayCode, int n){

    if (n <= 0)
    {
        grayCode.push_back(" ");
        return;
    }

    generateGrayCode(grayCode,(n-1));
    
    for (int i = grayCode.size()-1; i>= 0; i--)
    {
        string mirrored = grayCode[i];
        mirrored += mirrored+"1";
        grayCode.push_back(mirrored);
    }
    for (int i =0; i < grayCode.size()/2; i++)
    {
        swap(grayCode[i], grayCode[grayCode.size()-1-i]);
    }
    
    
}

int main(int argc, char const *argv[])
{
    vector<string> subset;
    int n;
    cout << "Input [n]: ";
    cin >>n;

    generateGrayCode(subset, n);

    cout << "Generate:"<<endl;;

    for (const string& code : subset)
    {
        cout << code<<endl;
    }
    
    return 0;
}
