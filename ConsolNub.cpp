#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
#include <optional>
#include <ranges>
#include <string>

int main()
{
    char word[] = "Hi!";
    char word1[] = { 'H','Y','!' };
    for (auto i = 0; i < 3; ++i)
    {
        std::cout << word[i];
        std::cout << word1[i];
    }
    std::string name = "Pokki";
    std::ranges::for_each(name, [](auto a) {std::cout << a;});

    auto lenS = name.length();
    auto lenS1 = name.size();
    bool iseS = name.empty();
    auto newname = name.append("text");
    auto subname = name.substr(0, 5);
    subname.clear();
    name.push_back('!');
    int scor = 500;
    auto intostring = std::to_string(scor);
    std::string input_int = "42";
    int num = std::stoi(input_int);
    auto indstr = newname.find("P");
    if (indstr != std::string::npos)
    {
        newname.replace(indstr, 1, { "pop" });
        newname.erase(indstr, 1);
    }
    auto cname = newname.c_str();
    std::cout << std::endl;
    std::cin >> name;
    std::cout << name << std::endl;
}


