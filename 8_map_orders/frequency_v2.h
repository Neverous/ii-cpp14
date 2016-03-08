#ifndef __FREQUENCY_V2_H__
#define __FREQUENCY_V2_H__

#include <map>
#include <unordered_map>
#include <vector>

template<typename COMP=std::less<std::string>>
inline
std::map<std::string, unsigned int, COMP> frequencies(const std::vector<std::string> &text, const COMP &cmp)
{
    std::map<std::string, unsigned int, COMP> result{cmp};
    for(const auto &word: text)
        ++ result[word];

    return result;
}

template<typename HASH=std::hash<std::string>, typename EQ=std::equal_to<std::string>>
inline
std::unordered_map<std::string, unsigned int, HASH, EQ> frequencies(const std::vector<std::string> &text, const HASH &hash, const EQ &eq)
{
    std::unordered_map<std::string, unsigned int, HASH, EQ> result{0, hash, eq};
    for(const auto &word: text)
        ++ result[word];

    return result;
}

auto Cs_lambda_less = [](const std::string &a, const std::string &b)
{
    //return std::less<std::string>{}(a, b);
    return a < b;
};

auto Ci_lambda_less = [](const std::string &a, const std::string &b)
{
    return string_insensitive_cmp(a, b) < 0;
};

auto Cs_lambda_eq = [](const std::string &a, const std::string &b)
{
    return a == b;
};

auto Ci_lambda_eq = [](const std::string &a, const std::string &b)
{
    return !string_insensitive_cmp(a, b);
};

auto Cs_lambda_hash = [](const std::string &s)
{
    return std::hash<std::string>{}(s);
};

auto Ci_lambda_hash = [](const std::string &s)
{
    size_t result = std::hash<char>{}('\0');
    for(const auto &l: s)
        hash_combine(result, tolower(l));

    return result;
};

bool Cs_fpointer_less(const std::string &a, const std::string &b)
{
    //return std::less<std::string>{}(a, b);
    return a < b;
}

bool Ci_fpointer_less(const std::string &a, const std::string &b)
{
    return string_insensitive_cmp(a, b) < 0;
}

bool Cs_fpointer_eq(const std::string &a, const std::string &b)
{
    return a == b;
}

bool Ci_fpointer_eq(const std::string &a, const std::string &b)
{
    return !string_insensitive_cmp(a, b);
}

size_t Cs_fpointer_hash(const std::string &s)
{
    return std::hash<std::string>{}(s);
}

size_t Ci_fpointer_hash(const std::string &s)
{
    size_t result = std::hash<char>{}('\0');
    for(const auto &l: s)
        hash_combine(result, tolower(l));

    return result;
}

template<typename KEY=std::string, typename CONTAINER=std::map<KEY, unsigned int>>
std::pair<KEY, unsigned int> most_frequent(const CONTAINER &data)
{
    auto cmp = [](const std::pair<KEY, unsigned int> &a, const std::pair<KEY, unsigned int> &b)
    {
        if(a.second == b.second)
            return a.first < b.first;

        return a.second < b.second;
    };

    return *std::max_element(begin(data), end(data), cmp);
}

#endif // __FREQUENCY_V2_H__
