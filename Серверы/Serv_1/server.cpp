#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string.h>
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
    ifstream file("f1.txt", ios::binary);
    ofstream file1;
    int check_size = file.seekg( 0, std::ios::end ).tellg();
    int new_size;
    file.close();
    while(1){
        file.open("f1.txt", ios::binary);
        new_size = file.seekg( 0, std::ios::end ).tellg();
        file.close();
        if(new_size!=check_size){
            check_size = new_size;
            file.open("f1.txt", ios::binary|ios::in);
            file.read((char*)&person, sizeof(Person));
            file.close();
            float index = person.weight / ((person.height/100)*(person.height/100));
            for(int i=0; i<256; i++){
                person1.name[i] = person.name[i];
            }
            if(index<16.5){
                strncpy(person1.health, "Severe underweight\n", 256);
            }else if(16.5<=index && index<18.49){
                strncpy(person1.health, "Insufficient (deficiency) body weight\n", 256);
            }else if(18.49<=index && index<24.99){
                strncpy(person1.health, "Normal\n", 256);
            }else if(24.99<=index && index<29.99){
                strncpy(person1.health, "Overweight (preobesity)\n", 256);
            }else if(29.99<=index && index<34.99){
                strncpy(person1.health, "First degree obesity\n", 256);
            }else if(34.99<=index && index<39.99){
                strncpy(person1.health, "Second degree obesity\n", 256);
            }else if(index>=39.99){
                strncpy(person1.health, "Obesity of the third degree (morbid)\n", 256);
            }
            file1.open("f2.txt", ios::binary|ios::out);
            file1.write((char*)&person1, sizeof(Person1));
            file1.close();
        }
    }
    return 0;
}
