#include <iostream>
#include<string>
using namespace std;

//��������
string secret(string password,int  key) {
	
	string secret = "";
	for (int i = 0; i < password.length(); i++) {
		secret += char((password[i] - 'a' + key) % 26 + 'a');
	};
	return secret;
}

//��������
string unsecret(string password, int key) {
	string secret = "";
	for (int i = 0; i < password.length(); i++) {
		secret += char((password[i] - 'a' - key+26) % 26 + 'a');
	};
	return secret;
}

int main() {
	srand(time(0));
	int key = 9;
	key = (rand()%26)+1;
	string password = "";
	string secret_password = "";
	string unsecret_password = "";
	cout << "����������" << endl;
	cin >> password;
	secret_password =  secret(password,key);
	cout << secret_password << endl;
	cout << "�Ƿ����" << endl;
	char word ='0';
	cin >> word;
	if (word == 'y') {
		unsecret_password = unsecret(secret_password, key);
		cout << unsecret_password << endl;
	}
	return 0;
}