#include <iostream>
#include <vector>

using namespace std;

vector<int> generateGrayCode(int n){
    vector<int> grayCode;
    for (int i = 0; i < (1 << n); i++)
    {
        int gray = i^(i >> 1);
        grayCode.push_back(gray);
    }
    return grayCode;
} 


int main(int argc, char const *argv[])
{
    int n;
    bool run = true;
    while (run)
    {
        cout << "Input the bit generate [n]: ";
        cin >>n;

        vector<int> grayCode = generateGrayCode(n);

        cout << "Gray code for "<<n<<"bits: "<<endl;

        if (n > 0)
        {
            for (int code : grayCode)
            {
                for (int i =n-1; i >= 0; i--)
                {
                    cout << ((code >> i) & 1)<<" ";
                }
                cout <<endl;
                
            }
        }else{
            cout <<"Just for bit > 0 "<<endl;
        }
        string y;
        cout << "Continue.. [y/n] ";
        cin >>y;
        if (y == "n")
        {
            run = false;
        }
        
    }
    
    return 0;
}
