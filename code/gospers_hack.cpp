#include <iostream>
#include <vector>

// Function to generate the next subset
unsigned int nextSubset(unsigned int subset) {
    unsigned int u = subset & -subset;
    unsigned int v = subset + u;
    return v | (((v ^ subset) / u) >> 2);
}

// Function to generate all k-subsets of a set of size n
void gospersHack(int k, int n) {
    unsigned int subset = (1 << k) - 1;
    unsigned int limit = (1 << n);

    while (subset < limit) {
        // Process the subset here
        // For example, printing it out
        for (int i = 0; i < n; ++i) {
            if (subset & (1 << i)) {
                std::cout << i + 1 << " ";
            }
        }
        std::cout << std::endl;

        subset = nextSubset(subset);
    }
}

int main() {
    int k = 3; // Size of subsets
    int n = 5; // Size of the set

    std::cout << "All " << k << "-subsets of a " << n << "-element set:\n";
    gospersHack(k, n);

    return 0;
}
