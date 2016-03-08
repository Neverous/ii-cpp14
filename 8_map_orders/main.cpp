#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

#include "../7_map/frequency.h"
#include "frequency_v2.h"

void readfile(std::istream& input, std::vector<std::string> &vect);

int main(int argc, char *argv[])
{
    std::vector<std::string> words;
    for(int i = 1; i < argc; ++ i)
    {
        std::ifstream input{argv[i]};
        if(!input)
        {
            std::cerr << "could not open input file " << argv[i] << "\n";
            continue;
        }

        readfile(input, words);
    }

    auto start  = std::chrono::high_resolution_clock::now();
#ifdef MAP_TEST_OPERATORS_SENSITIVE
    std::cerr << "map operators sensitive " << argc - 1 << "\t\t";
    auto freq   = frequencies<Cs_freq_map>(words);
#endif // MAP_TEST_OPERATORS_SENSITIVE

#ifdef MAP_TEST_OPERATORS_INSENSITIVE
    std::cerr << "map operators insensitive " << argc - 1 << "\t\t";
    auto freq   = frequencies<Ci_freq_map>(words);
#endif // MAP_TEST_OPERATORS_INSENSITIVE

#ifdef HASH_MAP_TEST_OPERATORS_SENSITIVE
    std::cerr << "hash map operators sensitive " << argc - 1 << "\t";
    auto freq   = frequencies<Cs_freq_unordered_map>(words);
#endif // HASH_MAP_TEST_OPERATORS_SENSITIVE

#ifdef HASH_MAP_TEST_OPERATORS_INSENSITIVE
    std::cerr << "hash map operators insensitive " << argc - 1 << "\t";
    auto freq   = frequencies<Ci_freq_unordered_map>(words);
#endif // HASH_MAP_TEST_OPERATORS_INSENSITIVE

#ifdef MAP_TEST_LAMBDAS_SENSITIVE
    std::cerr << "map lambdas sensitive " << argc - 1 << "\t\t";
    auto freq   = frequencies(words, Cs_lambda_less);
#endif // MAP_TEST_LAMBDAS_SENSITIVE

#ifdef MAP_TEST_LAMBDAS_INSENSITIVE
    std::cerr << "map lambdas insensitive " << argc - 1 << "\t\t";
    auto freq   = frequencies(words, Ci_lambda_less);
#endif // MAP_TEST_LAMBDAS_INSENSITIVE

#ifdef HASH_MAP_TEST_LAMBDAS_SENSITIVE
    std::cerr << "hash map lambdas sensitive " << argc - 1 << "\t\t";
    auto freq   = frequencies(words, Cs_lambda_hash, Cs_lambda_eq);
#endif // HASH_MAP_TEST_LAMBDAS_SENSITIVE

#ifdef HASH_MAP_TEST_LAMBDAS_INSENSITIVE
    std::cerr << "hash map lambdas insensitive " << argc - 1 << "\t";
    auto freq   = frequencies(words, Ci_lambda_hash, Ci_lambda_eq);
#endif // HASH_MAP_TEST_LAMBDAS_INSENSITIVE

#ifdef MAP_TEST_FPOINTERS_SENSITIVE
    std::cerr << "map fpointers sensitive " << argc - 1 << "\t\t";
    auto freq   = frequencies(words, &Cs_fpointer_less);
#endif // MAP_TEST_FPOINTERS_SENSITIVE

#ifdef MAP_TEST_FPOINTERS_INSENSITIVE
    std::cerr << "map fpointers insensitive " << argc - 1 << "\t\t";
    auto freq   = frequencies(words, &Ci_fpointer_less);
#endif // MAP_TEST_FPOINTERS_INSENSITIVE

#ifdef HASH_MAP_TEST_FPOINTERS_SENSITIVE
    std::cerr << "hash map fpointers sensitive " << argc - 1 << "\t";
    auto freq   = frequencies(words, &Cs_fpointer_hash, &Cs_fpointer_eq);
#endif // HASH_MAP_TEST_FPOINTERS_SENSITIVE

#ifdef HASH_MAP_TEST_FPOINTERS_INSENSITIVE
    std::cerr << "hash map fpointers insensitive " << argc - 1 << "\t";
    auto freq   = frequencies(words, &Ci_fpointer_hash, &Ci_fpointer_eq);
#endif // HASH_MAP_TEST_FPOINTERS_INSENSITIVE

    auto end    = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed{end - start};
    std::cout << freq;
    std::cerr << "computing frequency took " << elapsed.count() << " seconds\n";
    std::cout << most_frequent(freq) << "\n";
    return 0;
}

inline
void readfile(std::istream& input, std::vector<std::string> &vect)
{
    if(!input.good())
        return;

    std::string lastword;
    int c = input.get();
    while(input.good())
    {
        if(isspace(c) || ispunct(c))
        {
            if(!lastword.empty())
                vect.push_back(lastword);

            lastword.clear();
        }

        else
            lastword += c;

        c = input.get();
    }

    if(lastword.size())
        vect.push_back(lastword);
}
