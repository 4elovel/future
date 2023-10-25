#include <iostream>
#include <future>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;

int get_file_size(string path) {
	string buf="";
	ifstream is;
	is.open(path);
	if (is.is_open())	while (!is.eof()) {
		string buf2;
		getline(is, buf2);
		buf += buf2;
	}
	is.close();
	return buf.size();
}
	int main(){
		system("chcp 1251>nul");
		auto res = async(launch::async, get_file_size, "test.txt");
		auto res2 = async(launch::async, get_file_size, "test2.txt");
		cout << "Кількість символів у першому файлі - " << res.get() << endl;
		cout << "Кількість символів у другому файлі - " << res2.get() << endl;

		//std::future<int> result = std::async(std::launch::async,randd,11711,28);

		//std::cout << "Під час очікування думайте про помірність у діях.." << std::endl;
		//result.wait();
		//std::cout << "А ось і виплід, він не результ: " << result.get() << std::endl;
		//result = std::async(std::launch::async, randd, 365, 11711);
		//std::cout << "А ось і виплід, він же результ: " << result.get() << std::endl;
		//return 0;



	}