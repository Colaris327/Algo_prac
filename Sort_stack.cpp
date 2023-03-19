// APCS 2017/10/18 P4
// https://zerojudge.tw/ShowProblem?problemid=c471
#include <iostream>
#include <vector>
#include <algorithm>

class Package
{
    public:
        Package(int w, int c): weight(w), count(c) {}
        unsigned long long weight;
        unsigned long long count;
};

// the core of this problem is the "Compare" function
// this function compare the cost of two package when they swap.
bool Compare(Package a, Package b) {return a.count * b.weight < b.count * a.weight;}

unsigned long long Solution(std::vector<Package>& pa_arr)
{
    unsigned long long sum_weight = 0;
    for (auto it = pa_arr.begin(); it < pa_arr.end(); it++)
        sum_weight += it->weight;

    std::sort(pa_arr.begin(), pa_arr.end(), Compare);
    unsigned long long min_energy = 0;
    for (auto it = pa_arr.begin(); it < pa_arr.end(); it++)
    {
        sum_weight -= it->weight;
        min_energy += sum_weight * it->count;
    }

    return min_energy;
}

int main()
{
    std::vector<Package> P;
    unsigned long long N, W;
    std::cin >> N;
    for (unsigned long long i = 0; i < N; i++)
    {
        std::cin >> W;
        P.push_back(Package(W, 0));
    }
    for (auto it = P.begin(); it < P.end(); it++)
        std::cin >> it->count;

    std::cout << Solution(P);
    return 0;
}