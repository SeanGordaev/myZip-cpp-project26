#include "../includes/myZip.h"
#include <iostream>
#include <bitset>

using namespace std;

template <typename T>
struct ZIP
{
    vector<bool> zip_data;
    vector<T> tree;
};

struct Node {
    int key;
    int weight;
    Node* left;
    Node* right;

    Node(int k, int w) : key(k), weight(w), left(nullptr), right(nullptr) {}
};

class WeightedBinaryTree {
    private:
    public:
};




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


int main(void) {

    vector<bool> bitText = textToBits("hello");

    printBits(bitText);

    auto D = counterDuplicateBytes(bitText);
    sortedCounderDuplicateBytes(D);

    string text = bitsToText(bitText);

    cout << "\n" + text << endl;

    for (auto P : D) {
        string text = bitsToText(P.first);
        cout << text << " - ";
        printBits(P.first);
        std::cout << "[" << P.second << "]" << endl;
    }

    return 0;
}