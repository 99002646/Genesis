#include<map>
#include<algorithm>
#include<iostream>

bool isValid(std::pair<int,std::string> keyPair) {
    return keyPair.second.length() < 5;
}
int main() {
    std::map<int,std::string> cities;
    //some inserts
    auto iter = cities.find(103);
    if(iter!=cities.end())
       std::cout << iter->second << "\n";
    //auto res = std::find(cities.begin(),cities.end(),103);
    std::find_if(cities.begin(),cities.end(), isValid);
}