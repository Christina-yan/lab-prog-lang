#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <vector>

using namespace std;

struct Box {
    int num;
    int wi;
    int vi;
    Box(int n, int w, int v) : num(n), wi(w), vi(v) {}
};

class Stock {
private:
    vector<Box> boxes;
    int next_num;

public:
    Stock();

    void Add(int w, int v);
    int GetByW(int min_w);
    int GetByV(int min_v);
};

#endif