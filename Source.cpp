#include <iostream>
#include<string>

//������ 1 ������� � ������
std::string spaces_str(std::string str);// ��� �������� �������
// ���������� ��������� ������� ����� ������� � ����� �����...
// ��� ����� ��� ���� ����� �� ������������ ������� ����� 

//������ 2. �������� �� ����
std::string spaces_str(std::string str);// ����� ���������� �������� �������
bool is_spam(std::string msg);// �������� �� � ���





// Finel Strings
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	//������ 1 ������� � ������
	// �������� ������ ���������� ������
	/*std::cout << "������ 1\n ������� ������ -> ";
	std::string str1;
	std::getline(std::cin, str1);//����� ������ ������ ���� �������� �� � ������� ������� ������ 
	// ������� ��� std::string

	// ��������� � ���� ���� ���� �������
	std::cout << spaces_str(str1) << "\n\n";*/

	//������ 2. �������� �� ����
	/*std::cout << "������ 2\n ������� ������ -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))// �������� �� ����
		std::cout << "��������� ����!!!\n\n";
	else
		std::cout << "���� �� ���������   !!!\n\n";
		*/


		//������ 3 �������� URL.
	std::string URL = "http://vk.com/super_user/photos";
	std::cout << "������ 3.\n ����� �����:\n" << URL << std::endl;
	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", URL.find("://") + 3) + 1;// ����� ����� � ���� (Ctrl x )��������
	std::string path = URL.substr(path_index);// ����� ����� � ���� (Ctrl x )��������
	std::string domen = URL.substr(domen_index, path_index - 1 -  domen_index);
	std::string protocol = URL.substr(0, domen_index - 3);

	std::cout << "��������: " << protocol << std::endl;
	std::cout << "�����: " << domen << std::endl;
	std::cout << "����: " << path << "\n\n";


	// ���� ������� :// ������ ���� / � �� ���� ��� ���������� ������ super_user/photos
	// 

	return 0;
}
//������ 1
// �������� �������� �������
std::string spaces_str(std::string str) {
	std::string result;
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		if(i != str.length() - 1)
		result += " ";
	}
	return result;// ����� ���� ����� � ���� main  std::cout << spaces_str(str1) << "\n\n";
}
//������ 2.
// ������ ������� �� �������� ��������� � ������� ������� tolower ����� ����
bool is_spam(std::string msg) {
	for (int i = 0; i < msg.length(); i++)
		msg[i] = std::tolower(msg[i]);

	const int spams_number = 4;// ��� ���������� �������� ���������
	std::string spams[spams_number]{
		"100% free",
		"seles increase",
		"onli today",
		"black friday" // ��� ������� �� ������
	};// ��� ��� ������� ������ ��� � ������ ;

	//������ ���� � ��������� ���������� �����
	for(int i = 0; i < spams_number; i++)
		if(msg.find(spams[i]) < msg.length())
			return true;
	return false;
}