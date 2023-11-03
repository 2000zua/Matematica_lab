#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& subset, int k, int n){
    if (k == (n+1))
    {
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] <<" ";
        }
        cout << endl;
    }else{
        generateSubsets(subset, (k+1), n);
        subset.push_back(k);
        generateSubsets(subset, (k+1), n);
        subset.pop_back();
    }
} 


int main(int argc, char const *argv[])
{
    int n;
    cout << "Input [n]: ";
    cin >>n;

    vector<int> subset;
    generateSubsets(subset, 1, n);
    return 0;
}
