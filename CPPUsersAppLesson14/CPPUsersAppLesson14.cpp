﻿// CPPUsersAppLesson14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Задание 1. Напишите программу «Простейший файловый
//менеджер».Возможности:
//1. Смена текущего каталога(путь к текущему каталогу
//    должен всегда отображаться на экране);
//2. Отображение всех подкаталогов текущего каталога;
//3. Отображение всех файлов текущего каталога;
//4. Создание нового каталога в текущем каталоге;
//5. Удаление уже существующего каталога(если каталог не
//    пустой — то необходимо удалить все его содержимое,
//    для этого Вам необходимо использовать рекурсию).

//Задание 1. Пользователь вводит путь к папке и искомое
//слово.Программа ищет слово в папке и её подпапках.После
//работы программы формируется отчет с информацией
//о том, где было слово найдено, количество совпадений.

#include <iostream>
#include <string>
#include <filesystem>
#include <direct.h>
#include <directmanipulation.h>
using namespace std;
namespace fs = filesystem;
int main()
{
    setlocale(LC_ALL, "Russian");

    CreateDirectory(L"D:\\Илья\\New", NULL);

    RemoveDirectory(L"D:\\Илья\\New");
    
    

    /*fs::path pathToShow("D:\\task13_2_result.txt");
    cout <<pathToShow.root_path().string() << pathToShow.relative_path().string();
    pathToShow.filename().replace_filename("D:\\task13_2_result2.txt");*/
        
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
