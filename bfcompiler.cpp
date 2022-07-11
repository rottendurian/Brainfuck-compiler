#include "bfcompiler.hpp"

int main() {
	
    std::cout << "Enter filename: ";
	std::cin >> filepath;
	std::string bf = readbf(filepath);
	writebf(bf);
	compile();
	

	return 0;
}

void compile() {
    filepath.pop_back();
    filepath.pop_back();
    filepath.pop_back();
	std::ofstream terminal("terminal.bat");
	terminal << "g++ temp.c -o "<< filepath << " -lmingw32";
	terminal.close();
	system("terminal.bat");
    remove("terminal.bat");
    remove("temp.c");

}
std::string readbf(std::string filepath) {
	std::string bf;
	std::ifstream read(filepath);

	std::string result;

	while (getline(read, bf)) {
		result += bf;
		result += "\n";
	}
	read.close();
	return result;
}

void writebf(std::string bf) {
	std::ofstream createC("temp.c");
	createC << "#include <stdio.h>\n";
	createC << "char array[30000] = {0}; char* ptr = array;\n";
	createC << "int main(int args, char* argv[]) {\n";
	int i = 0;
	while (i < bf.size()) {
		writeline(createC,(bf.at(i)));
		i++;
	}
	createC << "}\n";
	createC.close();
}

void writeline(std::ofstream& createC, char c) {
	if (c == '>') {
		createC << "++ptr;" << "\n";
	}
	else if (c == '<') {
		createC << "--ptr;" << "\n";
	}
	else if (c == '+') {
		createC << "++*ptr;" << "\n";
	}
	else if (c == '-') {
		createC << "--*ptr;" << "\n";
	}
	else if (c == '[') {
		createC << "while(*ptr) {" << "\n";
	}
	else if (c == ']') {
		createC << "}" << "\n";
	}
	else if (c == '.') {
		createC << "putchar(*ptr);" << "\n";
	}
	else if (c == ',') {
		createC << "*ptr = getchar();" << "\n";
	}
	
}