#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int n;
int main() {

  	freopen("output.txt", "w", stdout);

    std::ifstream file;

    file.open("input.txt");

    file >> n;
    std::string str;
    std::vector<int16_t> v(n);
    

    for(int i = 0;std::getline(file, str, ' '); i++ )
    {
        v[i] = std::stoi(str);
    }
    

    int t = v[0];
    for(int i = 1; i < n; i++)
    {
    	
    	if(v[i] > t){
    		t=v[i];
		}
	}

    std::cout << t;
    return 0;
}