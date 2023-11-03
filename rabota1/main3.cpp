#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(int n){
    vector<int> subset;
    for (int i = 0; i < (1 << n); i++)
    {
        subset.clear();
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                subset.push_back(j+1);
            }
        }
        cout << "{";
        for (int j = 0; i < subset.size(); j++)
        {
            cout << subset[j];
            if (j < subset.size() -1)
            {
                cout << ", ";
            }
        }
        cout << "}"<<endl;
        
        
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Input [n]: ";
    cin >>n;
    generateSubsets(n);
    return 0;
}
