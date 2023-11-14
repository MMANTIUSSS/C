#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
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

int main(){
tryAgain:
	ofstream con_write;
	ifstream con_read;
    string nickname, command;
    cout << "Enter name >> ";
    cin >> nickname;
    command = nickname + " START\n";
    int con_size, new_size;
    con_write.open("c.txt", ios::app);
    con_write << command;
    con_write.close();
    con_size = Find_Size((string)"c.txt");
    int status = 0;
    string tmp_nick, tmp_command;
    while(1){
        new_size = Find_Size((string)"c.txt");
        if (new_size > con_size){
            con_read.open("c.txt");
            while(!con_read.eof()){
                con_read >> tmp_nick >> tmp_command;
            }
            con_read.close();
            if(tmp_nick==nickname){
                if(tmp_command == "WELCOME"){
                    status = 1;
                }
                if(tmp_command == "BAD"){
                    status = -1;
                }
            }
            if(status==-1){
                cout << "Try Again\n";
                goto tryAgain;
            }else if(status==1){
                cout << "Connection Successfull\n";
                break;
            }
            new_size = con_size;
        }
    }
    string str="";
    Person person;
    Person1 person1;
    ofstream file_write(nickname+".txt", ios::app);
	file_write.close();
    ifstream file_read;
    int file_size, check_size;
    while(1){
        cin >> str;
        if(str == "EXIT"){
            con_write.open("c.txt", ios::app);
            command = nickname + " EXIT\n";
			con_write << command;
			con_write.close();
            return 0;
        }else{
            person.name = str;
        }
        cin >> person.mark_1 >> person.mark_2 >> person.mark_3 >> person.mark_4;
        file_write.open(nickname+".txt", ios::app);
        file_write << person.name << ' ' << person.mark_1 << " " << person.mark_2 << " " << person.mark_3 << " " << person.mark_4 << '\n';
        file_write.close();
        file_size = Find_Size(nickname+".txt");
        check_size = file_size;
        sleep(5);
        file_read.open(nickname+".txt");
        file_read >> person1.name >> person1.grant;
        file_read.close();
        cout << person1.name << " " << person1.grant << '\n';
    }
    return 0;
}
