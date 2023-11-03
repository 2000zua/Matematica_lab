#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(int k, int n){
    vector<int> subset;
    if (k == (n+1))
    {
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] <<" ";
        }
        cout << endl;
    }else{
        // recursive
        generateSubsets((k+1), n);
        subset.push_back(k);
        generateSubsets((k+1), n);
        subset.pop_back();
    }
} 


int main(int argc, char const *argv[])
{
    int n;
    cout << "Input [n]: ";
    cin >>n;

    generateSubsets( 1, n);
    return 0;
}
