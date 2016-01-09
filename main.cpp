
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> messageLog;

void writeLog(string message)
{
    messageLog.push_back(message);
}

string arrayToString(vector<int> array)
{
    string msg;
    for(int x: array)
        msg += to_string(x) + " ";
    return msg;
}


//Функция вычисления факториала
vector<int> fact(int number)
{
    //Массив значений разрядов
    vector<int> res;
    writeLog("Создается массив для хранения результата res.");

    writeLog("Проверка на возможность вычисления факториала.");
    writeLog(string("number = ") + to_string(number));

    //Если число на входе меньше нуля, то вернем его обратно, факториал не определен
    if (number < 0)
    {
        writeLog("Значение number меньше нуля. Факториал не определен.");
        res.push_back(number);
        writeLog("Содержимое массива res: " + arrayToString(res));
        return res;
    }
    else
    {
        writeLog("Значение number больше нуля.");
        //Значение факториала для 0,1
        writeLog("Внесем в массив значение факториала для 0 и 1.");
        res.push_back(1);
        writeLog("Содержимое массива res: " + arrayToString(res));
        int n = 1;
        writeLog("Переменную счетчика цикла приравниваем 1.");
        writeLog("n = " + to_string(n));
        for(int i = 2; i <= number; i++)
        {
            writeLog("Остаток от деления приравняем 0");
            int div=0;
            writeLog("div = " + to_string(div));
            //Число разрядов в числе
            writeLog("Объявляем переменную счетчика разрядов m.");
            int m;
            writeLog("Начинаем цикл расчета факториала.");
            for(m = 0; (m < n)||(div > 0); m++)
            {
                //Проверка на необходимость увеличения числа елементов в массиве
                writeLog("Проверяем необходимость увеличения числа элементов в массиве.");
                int size = res.size();
                writeLog("m = " + to_string(m) + " res.size() = " + to_string(size));
                if (m >= size)
                {
                    //Увеличение массива и заполнение остатка нулями
                    writeLog("m >= res.size(). Увеличиваем размер массива.");
                    res.resize(size + 1, 0);
                    writeLog("res.size() = " + to_string(size));
                }
                else
                {
                    writeLog("m < res.size(). Размер массива размер не изменяем.");
                    //Умножение значения разряда на шаговое число
                    writeLog("Умножаем значение разряда на шаговое число.");
                    writeLog("d = res[m] * i + div");
                    int d = res[m] * i + div;
                    writeLog("d = " + to_string(d));
                    //В ячейку записываем остаток от деления
                    writeLog("В ячейку массива записываем остаток от деления.");
                    writeLog("res[m] = d % 10");
                    res[m] = d % 10;
                    writeLog("res[m] = " + to_string(res[m]));
                    //В остаток сохраняем целую часть
                    writeLog("В остаток сохраняем целую часть от деления.");
                    writeLog("div = d / 10");
                    div = d / 10;
                    writeLog("div = " + to_string(div));
                }
            }
            n = m;
        }
        //Приводим порядок разрядов в удобный вид
        reverse(res.begin(),res.end());
        return res;
    }
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
