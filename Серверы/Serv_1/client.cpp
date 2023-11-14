#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
using namespace std;

struct Person{
    char name[256]={'\0'};
    float height=0;
    float weight=0;
};

struct Person1{
    char name[256]={'\0'};
    char health[256]={'\0'};
};

int main(){
    Person person;
    Person1 person1;
    ofstream file;
    ifstream file1;

	cout << "Name: ";
    cin >> person.name;
	cout << "Height: ";
	cin >> person.height;
	cout << "Weight: ";
	cin >> person.weight;
        file.open("f1.txt", ios::binary|ios::out);
        file.write((char*)&person, sizeof(Person));
        file.close();
        sleep(2);
        file1.open("f2.txt", ios::binary|ios::in);
        file1.read((char*)&person1, sizeof(Person1));
        file1.close();
        cout << person1.name << " " << person1.health;

    return 0;
}
