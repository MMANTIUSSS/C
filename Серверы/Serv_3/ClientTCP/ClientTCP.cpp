#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#include<WinSock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string>

#pragma warning(disable: 4996)

SOCKET Connection;

enum Packet { // пакеты
	P_ChatMessage, 
	P_Test

};

bool ProcessPacket(Packet packettype) { // считывание данных и вывод сообщений
	switch (packettype) {
	case P_ChatMessage: {
		int msg_size;
		recv(Connection, (char*)&msg_size, sizeof(int), NULL); // инициализация чтения данных по соединению
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0'; // пустой массив - строка
		recv(Connection, msg, msg_size, NULL);  // чтение данных
		std::cout << msg << std::endl; 
		delete[] msg; // удалить из буфера массив
		break;
	}
	case P_Test:
		std::cout << "Test_start.\n";
		break;
	default:
		std::cout << "Unrecognized_packet: " << packettype << std::endl; // неопределенный пакет
	}
	return true;
}

void ClientHandler() { // считывание пакетов
	Packet packettype;
	while (true) {
		recv(Connection, (char*)&packettype, sizeof(Packet), NULL);

		if (!ProcessPacket(packettype)) {
			break;
		}
	}
	closesocket(Connection);
}

int main(int argc, char* argv[]) {
	WSAData wsaData; // структура с пакетами windows
	WORD DLLVersion = MAKEWORD(2, 1); // вызов со стороны сервера
	if (WSAStartup(DLLVersion, &wsaData) != 0) { // если тип сокета не WSA - выход, WSAStart инициализирует wsaData
		std::cout << "ERROR#1\n";
		exit(1); 
	}

	SOCKADDR_IN addr; // описывает socket для работы с протоколом
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP
	addr.sin_port = htons(1111); // порт процесса
	addr.sin_family = AF_INET; // TCP/IPv4
	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) { // connection
		std::cout << "ERROR: problem to connect\n";
		return 1;
	}
	std::cout << "CONNECTED\n";

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

	std::string msgl;
	while (true) {
		std::getline(std::cin, msgl);
		int msg_size = msgl.size();
		Packet packettyp = P_ChatMessage;
		send(Connection, (char*)&packettyp, sizeof(Packet), NULL); // запись данных в сокет
		send(Connection, (char*)&msg_size, sizeof(int), NULL);
		send(Connection, msgl.c_str(), msg_size, NULL);
		Sleep(10);
	}

	system("pause");
}