#include "../includes/myZip.h"
#include "../includes/struct.h"
#include <iostream>
#include <bitset>

using namespace std;

void printBits(vector<bool> bits) {
    for (int i = 0; i < bits.size(); i++) {
        cout << bits[i];
        if (i % 8 == 7)
            cout << " ";
    }
}

vector<bool> textToBits(string text) {
    vector<bool> vectorBits;
    for (char c : text) {
        bitset<8> bits(c);

         for (int i = 0; i < 8; ++i) {
            vectorBits.push_back((c >> (7 - i)) & 1);
        }
    }

    return vectorBits;
} 

string bitsToText(const vector<bool>& bits) {
    string text;
    bitset<8> bitSet; 

    for (int i = 0; i < bits.size(); i++) {
        bitSet[7 - (i % 8)] = bits[i];

        if (i % 8 == 7) {
            char c = static_cast<char>(bitSet.to_ulong());
            text.push_back(c);
            bitSet.reset();
        }
    }

    return text;
}

void printTree(Node* root, int step = 0) {
    Node* posRoot = root;
    cout << "step: " << step << " - ";
    printBits(root->value);
    cout << " | " << bitsToText(root->value);
    cout << " - " << root->weight << endl;

    if (posRoot->right != nullptr) {
        printTree(posRoot->right, step + 2);
    }
    if (posRoot->left != nullptr) {
        printTree(posRoot->left, step + 1);
    }
}


int main(void) {

    string text = "HHHELOO";

    cout << "Value: " << text << endl << endl;
    
    vector<bool> bitsOfValue = textToBits(text);
    cout << "Bits of value: "; printBits(bitsOfValue); cout << endl << endl;

    cout << "translate to text: " << bitsToText(bitsOfValue) << endl << endl;

    auto duplicateBytes = counterDuplicateBytes(bitsOfValue);
    sortedCounterDuplicateBytes(duplicateBytes);

    for (auto P : duplicateBytes) {
        string text = bitsToText(P.first);
        cout << text << " - ";
        printBits(P.first);
        std::cout << "[" << P.second << "]" << endl;
    }

    cout << endl;

    Node* root = createTree(duplicateBytes);
    printTree(root);

    return 0;
}