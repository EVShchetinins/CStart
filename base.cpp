#include <iostream>

void func_of_size_and_spesific()
{
    std::cout << "Hello World!\n";
    std::cout << "hello," << std::endl;
    std::cout << "STRING WITH quotes \"quots\"\n";

    double x5 = -15;
    float x6 = -16777.216;
    signed int x7 = -1;
    unsigned int x8 = 0;

    std::cout << "int " << " size = " << sizeof(int) << "\n";
    std::cout << "short " << " size = " << sizeof(short) << "\n";
    std::cout << "long " << " size = " << sizeof(long) << std::endl;
    std::cout << "long long " << " size = " << sizeof(long long) << std::endl;
    std::cout << "float " << " size =" << sizeof(float) << std::endl;
    std::cout << "signed int " << " size =" << sizeof(signed int) << std::endl;
    std::cout << "unsigned int " << " size =" << sizeof(unsigned int) << std::endl;

    char c1 = 69; //ASCII American Standard Code foe Information Interchange
    std::cout << "c1 =" << c1 << std::endl;

    wchar_t c2 = 'a'; // UTF-N Unicode Transformation Form
    char16_t tt = 0; // UTF
    //std::cout << "c2 =" << c2 << std::endl;
    std::wcout << "c2 =" << c2 << std::endl;

    std::string str = "kek";
    std::cout << str << std::endl;
    std::cout << sizeof(str) << std::endl;
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