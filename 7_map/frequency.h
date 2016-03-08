#ifndef __FREQUENCY_H__
#define __FREQUENCY_H__
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

template<typename FREQ=std::map<std::string, unsigned int>>
inline
FREQ frequencies(const std::vector<std::string> &text)
{
    FREQ result;
    for(const auto &word: text)
        ++ result[word];

    return result;
}

template<typename FIRST, typename SECOND>
inline
std::ostream &operator<<(std::ostream &stream, const std::pair<FIRST, SECOND> &pair)
{
    return stream << pair.first << ": " << pair.second;
}

template<typename CONTAINER>
inline
std::ostream &print_freqpairs(std::ostream &stream, const CONTAINER &data)
{
    for(const auto &pair: data)
        stream << pair << "\n";

    return stream;
}

template<typename CMP>
inline
std::ostream &operator<<(std::ostream &stream, const std::map<std::string, unsigned int, CMP> &freq)
{
    return print_freqpairs(stream, freq);
}

template<typename HASH, typename EQ>
inline
std::ostream &operator<<(std::ostream &stream, const std::unordered_map<std::string, unsigned int, HASH, EQ> &freq)
{
    return print_freqpairs(stream, freq);
}

/*
 * Returns:
 *  <0  if a < b
 *  0   if a == b
 *  >0  if a > b
 */
inline
int string_insensitive_cmp(const std::string &a, const std::string &b)
{
    int result = 0;
    for(size_t i = 0; i < a.size() && i < b.size() && !result; ++ i)
        result = tolower(a[i]) - tolower(b[i]);

    if(!result)
        result = a.size() - b.size();

    return result;
}

struct Case_insensitive_less
{
    inline
    bool operator()(const std::string &a, const std::string &b) const
    {
        return string_insensitive_cmp(a, b) < 0;
    }
}; // struct Case_insensitive_less

struct Case_insensitive_eq
{
    inline
    bool operator()(const std::string &a, const std::string &b) const
    {
        return !string_insensitive_cmp(a, b);
    }
}; // struct Case_insensitive_eq

struct Case_insensitive_hash
{
    inline
    size_t operator()(std::string s) const
    {
        std::transform(begin(s), end(s), begin(s), tolower);
        return std::hash<std::string>{}(s);
    }
}; // struct Case_insensitive_hash

/* Don't like copy? */
template <class T>
inline
void hash_combine(std::size_t& seed, const T& v)
{
    std::hash<T> hasher{};
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

struct Case_insensitive_hash_nocopy
{
    inline
    size_t operator()(std::string s) const
    {
        size_t result = std::hash<char>{}('\0');
        for(const auto &l: s)
            hash_combine(result, tolower(l));

        return result;
    }
}; // struct Case_insensitive_hash_nocopy

typedef std::map<std::string, unsigned int>                                                                 Cs_freq_map;
typedef std::map<std::string, unsigned int, Case_insensitive_less>                                          Ci_freq_map;
typedef std::unordered_map<std::string, unsigned int>                                                       Cs_freq_unordered_map;
typedef std::unordered_map<std::string, unsigned int, Case_insensitive_hash_nocopy, Case_insensitive_eq>    Ci_freq_unordered_map;

#endif // __FREQUENCY_H__
