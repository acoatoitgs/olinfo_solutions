#include <bits/stdc++.h>
using namespace std;

int n;
int main() {

  	freopen("output.txt", "w", stdout);

    std::ifstream file;

    file.open("input.txt");

    file >> n;
    std::string str;
    std::vector<int> v(n);
    

    for(int i = 0;std::getline(file, str, ' '); i++ )
    {
        v[i] = std::stoi(str);
    }
    

    int t = *max_element(v.begin(), v.end());

    std::cout << t;
    return 0;
}