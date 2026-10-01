//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;

// the same program works on Windows and on Linux / Mac (NOI Linux)
#ifdef _WIN32
const char *GEN = "g_gen.exe", *SOL = "g_apple.exe", *BRUTE = "g_brute_apple.exe";
const char *CMP = "fc g_apple.out g_brute_apple.out > null";
#else
const char *GEN = "./g_gen", *SOL = "./g_apple", *BRUTE = "./g_brute_apple";
const char *CMP = "diff g_apple.out g_brute_apple.out > /dev/null";
#endif

int main() {
    const int ROUNDS = 20;
    char cmd[200];
    for (int i = 1; i <= ROUNDS; i++) {
        snprintf(cmd, sizeof cmd, "%s %d > data.in", GEN, i); // round i uses seed i
        system(cmd);
        snprintf(cmd, sizeof cmd, "%s < data.in > g_apple.out", SOL);
        system(cmd);
        snprintf(cmd, sizeof cmd, "%s < data.in > g_brute_apple.out", BRUTE);
        system(cmd);
        if (system(CMP) != 0) { // the two outputs are different
            printf("Round %d: DIFFERENT! The bad data is in data.in\n", i);
            return 0;
        }
        printf("Round %d: same\n", i);
    }
    printf("All %d rounds passed\n", ROUNDS);
    return 0;
}