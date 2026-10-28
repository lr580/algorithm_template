unsigned int nextSubset(unsigned int subset) {
    unsigned int u = subset & -subset;
    unsigned int v = subset + u;
    return v | (((v ^ subset) / u) >> 2);
}
void gospersHack(int k, int n) {
    unsigned int subset = (1 << k) - 1;
    unsigned int limit = (1 << n);
    while (subset < limit) {
        for (int i = 0; i < n; ++i) {
            if (subset & (1 << i)) {
                std::cout << i + 1 << " ";
            }// Process the subset here
        }// For example, printing it out
        std::cout << std::endl;
        subset = nextSubset(subset);
    }
}
