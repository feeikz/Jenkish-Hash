#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


unsigned int jenkins_one_at_a_time_hash(string key, unsigned int N)
{
	int i = 0;
	unsigned int hash = 0;
	while (i != key.length()) {
		hash += key[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;

	return hash % N;
}

int main()
{
	ifstream subor;
	subor.open("..\\slovnik.txt");

	if (!subor.is_open())
	{
		cout << "Chyba pri otvarani suboru" << endl;
	}

	string a;
	int pocet_vstupu = 0;
	while (!subor.eof() && pocet_vstupu-- >= 0)
	{
		getline(subor, a, '\n');
		//cout<<jenkins_one_at_a_time_hash(a,100) << '\n';
		cout << " 0x" << hex << uppercase << jenkins_one_at_a_time_hash(a, 100) << " = " << a << '\n';
	}

	subor.close();
	system("pause");
	return 0;
}


