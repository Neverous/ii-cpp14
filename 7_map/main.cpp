#include <iostream>

#include "frequency.h"

int main(void)
{
    std::cout << frequencies({"AA", "aA", "Aa", "this", "THIS"}) << "\n";

    {
        Case_insensitive_less less;
        std::cout << less("a", "A") << less("a", "a") << less("A", "a") << less("A", "a") << "\n";
        std::cout << less("a", "B") << less("a", "b") << less("A", "b") << less("A", "b") << "\n";
        std::cout << less("b", "A") << less("b", "a") << less("B", "a") << less("B", "a") << "\n";
        std::cout << less("ba", "A") << less("b", "aa") << less("Ba", "a") << less("B", "aa") << "\n\n";
    }

    std::cout << frequencies<Ci_freq_map>({"AA", "aA", "Aa", "this", "THIS"}) << "\n";


    {
        Case_insensitive_hash_nocopy hash_nocopy;
        Case_insensitive_hash hash;
        std::cout << hash("xxx") << " " << hash("XXX") << " " << hash_nocopy("xxx") << " " << hash_nocopy("XXX") << "\n";
        std::cout << hash("Abc") << " " << hash("abC") << " " << hash_nocopy("Abc") << " " << hash_nocopy("abC") << "\n";
        std::cout << hash("Abd") << " " << hash("DbC") << " " << hash_nocopy("Abd") << " " << hash_nocopy("DbC") << "\n";

        Case_insensitive_eq eq;
        std::cout << eq("xxx", "XXX") << eq("abc", "aBd") << eq("a", "bc") << "\n\n";
    }

    std::cout << frequencies<Cs_freq_unordered_map>({"AA", "aA", "Aa", "this", "THIS"}) << "\n";
    std::cout << frequencies<Ci_freq_unordered_map>({"AA", "aA", "Aa", "this", "THIS"}) << "\n";
    return 0;
}
