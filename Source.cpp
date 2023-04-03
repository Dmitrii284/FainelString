#include <iostream>
#include<string>

//Задача 1 Пробелы в строке
std::string spaces_str(std::string str);// Это прототип функции
// Реализацию прототипа функции можно сделать в любом месте...
// Это нужно для того чтобы не нагромождать верхнюю часть 

//Задача 2. Проверка на спам
std::string spaces_str(std::string str);// Опять используем прототип функции
bool is_spam(std::string msg);// Копируем ее в низ





// Finel Strings
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	//Задача 1 Пробелы в строке
	// Создадим псевдо глобальную строку
	/*std::cout << "Задача 1\n Введите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);//Ввели строку сейчас надо передать ее в функцию которая должна 
	// вернуть нам std::string

	// Добавляем в тело мейн нашу функцию
	std::cout << spaces_str(str1) << "\n\n";*/

	//Задача 2. Проверка на спам
	/*std::cout << "Задача 2\n Введите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))// Проверка на спам
		std::cout << "Обнаружен спам!!!\n\n";
	else
		std::cout << "Спам не обнаружен   !!!\n\n";
		*/


		//Задача 3 Разбивка URL.
	std::string URL = "http://vk.com/super_user/photos";
	std::cout << "Задача 3.\n Адрес сайта:\n" << URL << std::endl;
	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", URL.find("://") + 3) + 1;// Берем адрес и ищем (Ctrl x )вырезаем
	std::string path = URL.substr(path_index);// Берем адрес и ищем (Ctrl x )вырезаем
	std::string domen = URL.substr(domen_index, path_index - 1 -  domen_index);
	std::string protocol = URL.substr(0, domen_index - 3);

	std::cout << "Протокол: " << protocol << std::endl;
	std::cout << "Домен: " << domen << std::endl;
	std::cout << "Путь: " << path << "\n\n";


	// Ищем сначала :// отсюда ищем / и от него все возвращаем тоесть super_user/photos
	// 

	return 0;
}
//Задача 1
// Вызываем прототип функции
std::string spaces_str(std::string str) {
	std::string result;
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		if(i != str.length() - 1)
		result += " ";
	}
	return result;// После чего пишем в теле main  std::cout << spaces_str(str1) << "\n\n";
}
//Задача 2.
// Делаем функцию не регистро зависимой с помощью функции tolower через цикл
bool is_spam(std::string msg) {
	for (int i = 0; i < msg.length(); i++)
		msg[i] = std::tolower(msg[i]);

	const int spams_number = 4;// Это количество спамовых сообщений
	std::string spams[spams_number]{
		"100% free",
		"seles increase",
		"onli today",
		"black friday" // Тут запятую не ставим
	};// Это как обычный массив вот и ставим ;

	//Делаем цикл и проверяем совпадения спама
	for(int i = 0; i < spams_number; i++)
		if(msg.find(spams[i]) < msg.length())
			return true;
	return false;
}