#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

void printSet(const multiset<int>& s) {
    cout << "Multiset: ";
    for (const int& elem : s) {
        cout << elem << " ";
    }
    cout << endl;
}

void unionOperation(const multiset<int>& set1, const multiset<int>& set2) {
    multiset<int> result(set1.begin(), set1.end());
    result.insert(set2.begin(), set2.end());

    printSet(result);
}

void intersectionOperation(const multiset<int>& set1, const multiset<int>& set2) {
    multiset<int> result;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));

    printSet(result);
}

void sumOperation(const multiset<int>& set1, const multiset<int>& set2) {
    multiset<int> result(set1.begin(), set1.end());
    result.insert(set2.begin(), set2.end());

    printSet(result);
}

void differenceOperation(const multiset<int>& set1, const multiset<int>& set2) {
    multiset<int> result;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));

    printSet(result);
}

void symmetricDifferenceOperation(const multiset<int>& set1, const multiset<int>& set2) {
    multiset<int> result;
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));

    printSet(result);
}

int main() {
    list<int> conj = list<int>();
    int controller;
    multiset<int> set1 = {1, 2, 5, 3, 4};
    multiset<int> set2 = {1, 3, 14, 9, 15};


    cout << "Set1: ";
    printSet(set1);
    cout <<"Set2: ";
    printSet(set2);

    cout << "Union Operation: ";
    unionOperation(set1, set2);

    cout << "Intersection Operation: ";
    intersectionOperation(set1, set2);

    cout << "Sum Operation: ";
    sumOperation(set1, set2);

    cout << "Difference Operation: ";
    differenceOperation(set1, set2);

    cout << "Symmetric Difference Operation: ";
    symmetricDifferenceOperation(set1, set2);

    return 0;
}