#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output) {
    if(input.length() == 0)
    {
        cout<<output<<endl;
        return;
    }

    solve(input.substr(1),output+"_"+input[0]);

    solve(input.substr(1),output+input[0]);
}

int main() {
    string input = "ABC";

    string output = "";
    output += input[0];  

    solve(input.substr(1), output);

    return 0;
}