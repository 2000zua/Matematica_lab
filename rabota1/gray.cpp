#include <iostream>
#include <vector>
#include <string>

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

// Função para converter Gray para binário
string grayToBinary(string grayCode) {
    string binaryCode = "";
    binaryCode += grayCode[0];
    for (int i = 1; i < grayCode.length(); i++) {
        if (grayCode[i] == '0' && binaryCode[i - 1] == '0' || grayCode[i] == '1' && binaryCode[i - 1] == '1') {
            binaryCode += '0';
        } else {
            binaryCode += '1';
        }
    }
    return binaryCode;
}

// Função para converter binário para decimal
int binaryToDecimal(string binaryCode) {
    int decimal = 0;
    int power = 1;
    for (int i = binaryCode.length() - 1; i >= 0; i--) {
        if (binaryCode[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

int main() {
    vector<string> grayCodes;
    int n;
    cout << "Digite o número de códigos Gray: ";
    cin >> n;
    vector<int> grayCODE = generateGrayCode(n);



    //cout << "Digite os códigos Gray:" << endl;
    string linha = "";
    for (int code : grayCODE) {
        for (int i =n-1; i >= 0; i--){
            cout << ((code >> i) & 1)<<">";
            linha = to_string((code >> i) & 1);
        }
        cout <<endl;
        grayCodes.push_back(linha);
    }

    cout << "Códigos Binários e Valores Decimais:" << endl;
    for (const string& grayCode : grayCodes) {
        string binaryCode = grayToBinary(grayCode);
        int decimalValue = binaryToDecimal(binaryCode);
        cout << "Gray: " << grayCode << "  Binário: " << binaryCode << "  Decimal: " << decimalValue << endl;
    }

    return 0;
}