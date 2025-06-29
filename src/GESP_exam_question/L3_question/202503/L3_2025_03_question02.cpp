//
// Created by Emma on 2025/6/27.
//
#include<iostream>
using namespace std;

int a[110];
string all_word[110];

int main() {
    int n, m = 0;
    // 输入
    cin >> n;
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        // 将大写全部转为小写(这样便于统计单词数量)
        for (int j = 0; j < word.size(); j++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] += 32;
            }
        }
        // 遍历数组,检查这个单词是否在数组中被统计过
        bool flag = false;
        for (int j = 0; j < m; j++) {
            if (all_word[j] == word) {
                // 情况1:如果在此单词之前被统计过,直接将此单词的次数加1
                a[j]++;
                flag = true;
                break;
            }
        }
        if (!flag) {
            // 情况2(没有进情况1的if):如果这个单词之前没有被统计过,也就是说这是一个新单词,就新加一个元素
            all_word[m++] = word;
            a[m]++;
        }
    }
    // 寻找出现次数最多的单词
    int maxx = 0, maxidx = -1;
    for (int i = 0; i < m; i++) {
        if (a[i] > maxx) {
            // 每次发现最大不仅要更新maxx,还要更新maxidx,否则无法输出all_word[maxidx]
            maxx = a[i];
            maxidx = i;
        }
    }
    // 输出
    cout << all_word[maxidx] << endl;
    return 0;
}
