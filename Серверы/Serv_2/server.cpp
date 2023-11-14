#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

int Find_Size(string DATA) {
	int size;
	ifstream CON;
	CON.open(DATA);
	CON.seekg(0, std::ios::end);
	size = CON.tellg();
	CON.close();
	return size;
}

struct Person{
    string name="";
    float mark_1 = 0;
    float mark_2 = 0;
    float mark_3 = 0;
    float mark_4 = 0;
};

struct Person1{
    string name="";
    float grant=0;
};

struct Person_file{
	string name="";
	int size=0;
};

int main(){
	int i;
    Person person_get;
    Person1 person_take;
	Person_file user;
    ifstream file_read, con_read;
    ofstream file_write, con_write("c.txt", ios::app);
	con_write.close();
    int new_size, con_size=Find_Size("c.txt");
	string nickname, command, str="", tmp_str="";
	vector<Person_file> connections;
	auto iter = connections.cbegin();
	bool exist;
    while(1){
		new_size = Find_Size("c.txt");
		if(new_size>con_size){
			con_read.open("c.txt");
			while (!con_read.eof()) {
				con_read >> nickname >> command;
			}
			con_read.close();
			exist=false;
			i=0;
			while(i<connections.size()){
				if(connections[i].name==nickname){
					exist=true;
					break;
				}
				i++;
			}
			if(exist){
				if(command=="START"){
					con_write.open("c.txt", ios::app);
					con_write << nickname << " BAD\n";
					con_write.close();
				}
				if(command=="EXIT"){
					connections.erase(iter+i);
				}
			}else{
				if(command=="START"){
					con_write.open("c.txt", ios::app);
					con_write << nickname << " WELCOME\n";
					con_write.close();
					user.name = nickname;
					user.size = Find_Size(nickname+".txt");
					connections.push_back(user);
				}
			}
			con_size = Find_Size("c.txt");
		}
		for(i=0; i<connections.size(); i++){
			new_size = Find_Size(connections[i].name+".txt");
			if(new_size > connections[i].size){
				cout << connections[i].name << '\n';
				file_read.open(connections[i].name+".txt");
				while(getline(file_read, str)){}
				file_read.close();
				cout << str << '\n';
				tmp_str = "";
				i=0;
				while(str[i]!=' '){tmp_str+=str[i]; i++;}
				i++;
				person_get.name = tmp_str;
				tmp_str = "";
				cout << person_get.name << '\n';
				while(str[i]!=' '){tmp_str+=str[i]; i++;}
				person_get.mark_1 = stof(tmp_str);
				i++;
				tmp_str = "";
				while(str[i]!=' '){tmp_str+=str[i]; i++;}
				person_get.mark_2 = stof(tmp_str);
				i++;
				tmp_str = "";
				while(str[i]!=' '){tmp_str+=str[i]; i++;}
				person_get.mark_3 = stof(tmp_str);
				i++;
				tmp_str = "";
				while(i!=str.length()-1){tmp_str+=str[i]; i++;}
				person_get.mark_4 = stof(tmp_str);
				cout << 2;
				person_take.name = person_get.name;
				person_take.grant = (person_get.mark_1+person_get.mark_2+person_get.mark_3+person_get.mark_4)/4;
				file_write.open(connections[i].name+".txt", ios::app);
				file_write << person_take.name << ' ' << person_take.grant << '\n';
				file_write.close();
				connections[i].size = Find_Size(connections[i].name+".txt");
			}
		}
    }
    return 0;
}
