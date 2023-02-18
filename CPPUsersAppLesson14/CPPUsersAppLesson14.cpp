// CPPUsersAppLesson14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    string command = "";
    string newpath = "";
    string buf = "";
    fs::path p = "D:\\Илья\\testdir";
    fs::directory_entry dir;
    dir.assign(p);   
    bool cd = false;
    bool view = false;
    bool error = false;
    bool create = false;
    bool remove = false;
    while (true)
    {

        if (command == "")
        { 
            cout << "\nТекущее расположение:\n";
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
            cout << p.string() << "\n";
            SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);                 
            cout << "Список команд:\ncd {path} - сменить директорию \n";
            cout << "view dirs - Показать подкаталоги по текущему пути\n";
            cout << "view files - Показать файлы по текущему пути\n";
            cout << "create {name} - Создать каталог с указанным именем по текущему пути\n";
            cout << "remove {name} - Удалить каталог с указанным именем по текущему пути (для точно удаления папки используйте предварительно коману view dirs)\n";
            cout << "exit - выход из проекта\n";
            cout << "Введите команду:\n";  
            cin >> command;
        }
        if (cd || view || create || remove)
        { 
            cin >> command;
        }
        if (command != "remove" && command != "cd" && !cd && !remove && !error && !view && !create && command != "view" && command != "create")
        {
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << "Такой команды не существует\n";
            command = "";
            SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        }
        if (error)
        {            
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            cout << command << "\n";
            command = "";
            error = false;
            SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        }
        if (view)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
            if (command == "dirs")
            {
                for (auto const& dir_entry : std::filesystem::directory_iterator{ dir.path()})
                {
                    if (dir_entry.is_directory())
                        std::cout << dir_entry.path() << '\n';
                }
            }
            if (command == "files")
            {
                for (auto const& dir_entry : std::filesystem::directory_iterator{ dir.path() })
                {
                    if (!dir_entry.is_directory())
                        std::cout << dir_entry.path() << '\n';
                }
            }
            SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            view = false;
            command = "";
        }
        if (cd)
        {
            newpath = command.substr(0, 1) == "{" ? command.substr(1, command.length() - 1) : command;
            fs::path pbuf = newpath;            
            dir.assign(pbuf);
            if (dir.exists())
            {
                p = newpath;
                command = "";               
            }
            else
            {                
                command = "Такого пути не существует";
                error = true;
            }
            dir.assign(p);
            pbuf.~path();
            cd = false;            
        }
        if (create)
        {
            newpath = command.substr(0, 1) == "{" ? command.substr(1, command.length() - 1) : command;
            fs::path pbuf = newpath;
            pbuf = p / pbuf;  
            fs::create_directory(pbuf);
            pbuf.~path();
            create = false;
        }
        if (remove)
        {
            fs::path pbuf;
            for (auto const& dir_entry : std::filesystem::directory_iterator{ dir.path() })
            {
                if (dir_entry.is_directory() && dir_entry.path().filename() == command)
                    pbuf = dir_entry.path();
                
            } 
            fs::remove_all(pbuf);
            pbuf.~path();
            remove = false;
        }
        if (command == "remove")
        {
            remove = true;
        }
        if (command == "view")
        {
            view = true;
        }
        if (command == "cd")
        {
            cd = true;
        }  
        if (command == "create")
        {
            create = true;
        }

        if (command == "exit")
        {
            break;
        }

    } 
        
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
