// We'll try something called input redirection. We can store the context of an input stream, and redirect to a different one.
// In this program, we will read from the standard input and write to a file.
// We will then read from the file and write to the standard output.

#include <iostream>
#include <fstream>
#include <string>

void f()
{
    std::string line;
    while(std::getline(std::cin, line))  //input from the file in.txt
    {
        std::cout << line << "\n";   //output to the file out.txt
    }
}

int main()
{
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::string word;
    std::cin >> word;           //input from the file in.txt
    std::cout << word << "  ";  //output to the file out.txt
    
    f(); //call function

    std::cin.rdbuf(cinbuf);   //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    std::cin >> word;   //input from the standard input
    std::cout << word;  //output to the standard input

    in.close();
    out.close();

    return 0;
}