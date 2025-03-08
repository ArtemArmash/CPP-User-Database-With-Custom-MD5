#pragma once
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

unsigned char* input;
unsigned int T[64];
unsigned int* block;
int Size = 0;

unsigned int A = 0x67452301;
unsigned int B = 0xefcdab89;
unsigned int C = 0x98badcfe;
unsigned int D = 0x10325476;

unsigned int rotate_left(unsigned int value, unsigned int shift) { return value << shift | value >> (32 - shift); }

unsigned int F(unsigned int x, unsigned int y, unsigned int z) { return (x & y) | (~x & z); }
unsigned int G(unsigned int x, unsigned int y, unsigned int z) { return (x & z) | (~z & y); }
unsigned int H(unsigned int x, unsigned int y, unsigned int z) { return x ^ y ^ z; }
unsigned int I(unsigned int x, unsigned int y, unsigned int z) { return y ^ (x | ~z); }

const unsigned int shift[64] = {
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

void process_block() {


    unsigned int AA = A, BB = B, CC = C, DD = D;

    cout << endl;

    for (int i = 0; i < 64; i++) {
        unsigned int F_val;
        unsigned int g;

        if (i <= 15) {
            F_val = F(B, C, D);
            g = i;
        }
        else if (i <= 31) {
            F_val = G(B, C, D);
            g = (5 * i + 1) % 16;
        }
        else if (i <= 47) {
            F_val = H(B, C, D);
            g = (3 * i + 5) % 16;
        }
        else {
            F_val = I(B, C, D);
            g = (7 * i) % 16;
        }

        unsigned int temp = D;
        D = C;
        C = B;
        B = B + rotate_left(A + F_val + T[i] + block[g], shift[i]);
        A = temp;

    }

    A = AA + A;
    B = BB + B;
    C = CC + C;
    D = DD + D;

}


void appendBits(string& data) {
    memset(input, 0, Size);
    memcpy(input, data.c_str(), data.size());

    input[data.size()] = 0x80;

    uint64_t bit_length = data.size() * 8;
    memcpy(&input[Size - 8], &bit_length, 8);
}

string getHexMD5(vector<unsigned char> hash) {
    string hex = "0123456789ABCDEF";
    string result;
    for (unsigned char h : hash) {
        result += hex[h >> 4];
        result += hex[h & 0x0F];
    }
    return result;
}

vector<unsigned char> hastToArr() {
    vector<unsigned char> hash(16);
    memcpy(&hash[0], &A, 4);
    memcpy(&hash[4], &B, 4);
    memcpy(&hash[8], &C, 4);
    memcpy(&hash[12], &D, 4);
    return hash;
}

void init() {
    for (int i = 0; i < 64; i++) {
        T[i] = (unsigned int)floor(4294967296.0 * fabs(sin(i + 1)));

    }
    block = (unsigned int*)(input);
}


void process() {

    for (size_t i = 0; i < Size; i += 64) {
        block = (unsigned int*)(input + i);
        process_block();
    }
}

string MD5(string data) {
    A = 0x67452301;
    B = 0xefcdab89;
    C = 0x98badcfe;
    D = 0x10325476;

    int length = data.size();
    Size = ((length + 9) / 64 + 1) * 64;


    input = new unsigned char[Size];
    appendBits(data);
    init();
    process();
    delete[] input;

    return getHexMD5(hastToArr());
}

