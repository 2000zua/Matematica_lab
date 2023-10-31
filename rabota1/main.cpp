#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

// funcao para calcular o numero de um subconjunto
int calculateSubsetNumber(vector<int>& set, vector<int>& subset){
    int n = set.size();
    int k = subset.size();
    int number = 0;

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (subset[i] == set[j])
            {
                number += 1 << j;
                break;
            }   
        }   
    }
    return number;
}


// funcao para gerar um subconjunto a partir de um numeroespecifico
vector<int> generateSubsetFromNumber(vector<int>& set, int number){
    vector<int> subset;
    int n = set.size();

    for (int i = 0; i < n; ++i)
    {
        if (number & (1 <<i))
        {
            subset.push_back(set[i]);
        }
    }
    return subset;
}



// Função para gerar todas as permutações de {1, ..., n} para um dado n
void generatePermutations(int n) {
    std::vector<int> permutation(n);
    for (int i = 1; i <= n; ++i) {
        permutation[i - 1] = i;
    }

    do {
        for (int i = 0; i < n; ++i) {
            std::cout << permutation[i] << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(permutation.begin(), permutation.end()));
}

// Função para gerar um determinado subconjunto do subconjunto seguinte em ordem lexicográfica
std::vector<int> generateNextSubset(const std::vector<int>& set, const std::vector<int>& subset) {
    std::vector<int> nextSubset;
    int n = set.size();
    int k = subset.size();
    nextSubset.reserve(k);

    int i = k - 1;
    while (i >= 0 && subset[i] == set[n - k + i]) {
        i--;
    }

    if (i >= 0) {
        int nextElement = subset[i] + 1;
        for (int j = 0; j < i; j++) {
            nextSubset.push_back(subset[j]);
        }
        nextSubset.push_back(nextElement);
        for (int j = i + 1; j < k; j++) {
            nextSubset.push_back(nextElement + j - i);
        }
    }

    return nextSubset;
}

int main() {
    std::vector<int> set = {1, 2, 3, 4, 5};
    std::vector<int> subset = {2, 4, 5};

    // 1. Calcular o número de um subconjunto especificado
    int number = calculateSubsetNumber(set, subset);
    std::cout << "Número do subconjunto: " << number << std::endl;

    // 2. Gerar um subconjunto a partir de um número específico
    std::vector<int> generatedSubset = generateSubsetFromNumber(set, number);
    std::cout << "Subconjunto gerado: ";
    for (int element : generatedSubset) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 3. Gerar todas as permutações de {1, ..., n} para um dado n
    int n = 3; // Altere o valor de 'n' conforme necessário
    generatePermutations(n);

    // 4. Geração de um determinado subconjunto do subconjunto seguinte
    std::vector<int> nextSubset = generateNextSubset(set, subset);
    std::cout << "Subconjunto seguinte: ";
    for (int element : nextSubset) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}