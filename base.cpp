#include <iostream>
#include <algorithm>
#include <string>
void func_of_size_and_spesific()
{
    //types
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

    //mass
    int nums[3];
    nums[0] = 5;
    nums[2] = sizeof(0)["a"];
    int num3[] = {1,2,3};
    float nums1[2] = { 1,2 };
    std::cout << nums1 << '\n';
    auto x = std::ranges::for_each(nums, [](auto a) {std::cout << a << std::endl;});

    short matrix[2][4] = {
        {1,1,1,1},
        {11,11,7,9} };
    std::cout << matrix[1][3] << std::endl;

    //new delete
    long long* dnumone = new long long();
    *dnumone = 5;
    int* dnumtwo = new int;
    double* dnumthree = new double();
    std::cout << "Adress: " << dnumone << " Memory: " << *dnumone << std::endl;
    std::cout << "Adress: " << dnumtwo << " Memory: " << *dnumtwo << std::endl;
    std::cout << "Adress: " << dnumthree << " Memory: " << *dnumthree << std::endl;
    long long* dnum = new long long[300];
    dnum[0] = 45;
    std::cout << "First: " << dnum[0] << " Second:" << dnum[1] << std::endl;
    delete[] dnum;
    delete dnumone;
    delete dnumtwo;
    delete dnumthree;
    std::cout << "El" << dnum[0] << std::endl;

    //string
    char word[] = "Hi!";
    char word1[] = { 'H','Y','!' };
    for (auto i = 0; i < 3; ++i)
    {
        std::cout << word[i];
        std::cout << word1[i];
    }
    std::string name = "Pokki";
    std::ranges::for_each(name, [](auto a) {std::cout << a;});

    auto lenS = name.length();
    auto lenS1 = name.size();
    bool iseS = name.empty();
    auto newname = name.append("text");
    auto subname = name.substr(0, 5);
    subname.clear();
    name.push_back('!');
    int scor = 500;
    auto intostring = std::to_string(scor);
    std::string input_int = "42";
    int num = std::stoi(input_int);
    auto indstr = newname.find("P");
    if (indstr != std::string::npos)
    {
        newname.replace(indstr, 1, {"pop"});
        newname.erase(indstr, 1);
    }
    auto cname = newname.c_str();
    std::cout << std::endl;
    std::cin >> name;
    std::cout << name << std::endl;
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