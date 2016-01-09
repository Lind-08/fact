
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

vector<string> messages;

void writeLog(string message)
{
    messages.push_back(message);
}

string arrayToString(vector<int> array)
{
    string msg;
    for(int x: res)
        msg += to_string(x) + " ";
    return msg;
}


//Функция вычисления факториала
vector<int> fact(int number)
{
    //Массив значений разрядов
    vector<int> res;
    writeLog("Создается массив для хранения результата res.");
    //Если число на входе меньше нуля, то вернем его обратно, факториал не определен
    writeLog("Проверка на возможность вычисления факториала.");
    writeLog(string("number = ") + to_string(number));
    if (number < 0)
    {
        writeLog("Значение number меньше нуля. Факториал не определен.");
        res.push_back(number);
        writeLog("Содержимое массива res: " + arrayToString(res));
        return res;
    }
    //Значение факториала для 0,1
    res.push_back(1);
    int n = 1;
    for(int i = 2; i <= number; i++)
    {
        int div=0;
        //Число разрядов в числе
        int m;
        for(m = 0; (m < n)||(div > 0); m++)
        {
            //Проверка на необходимость увеличения числа елементов в массиве
            int size = res.size();
            if (m >= size)
            {
                //Увеличение массива и заполнение остатка нулями
                res.resize(size+1,0);
            }
            //Умножение значения разряда на шаговое число
            int d = res[m] * i + div;
            //В ячейку записываем остаток от деления
            res[m] = d % 10;
            //В остаток сохраняем целую часть
            div = d / 10;
        }
        n = m;
    }
    //Приводим порядок разрядов в удобный вид
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число:" << endl;
    int number;
    cin >> number;
    cout << number << "!=";
    vector<int> res = fact(number);
    for (int x: res)
        cout << x;
    cout << endl;
    return 0;
}
