# Длинная целочисленная арифметика
Позволяет хранить и выполнять операции сложения, вычитания, умножения, деления, вычисления остатка, формирования и разбора строкового представления для чисел, разрядность которой превышает максимальную допустимую для существующих типов.

## Структура
Число хранится в виде структуры с тремя полями:
* `digits` — массив из блоков разрядов — чисел от 0 до 999 (индексируются от младших к старшим);
* `released_size` — количество блоков разрядов, под которые выделена память; 
* `size` — количество блоков действительных разрядов числа — разрядов, старше которых есть хотя бы один ненулевой разряд. Считается, что у нуля один блок разрядов.

## Функции
```c
big_num create_empty(int released_size)
```
Выделяет из памяти место на `released_size` блоков разрядов, создает ноль.

```c
void put(big_num* num, int to, int what)
```
Помещает в блоков разрядов `to` числа `big_num` значение `what`.

```c
big_num create(int i)
```
Создает большое число, у которого младший блок разрядов равен `i`.

```c
int compare(big_num a, big_num b)
```
Сравнивает числа `a` и `b`, сначала по числу блоков, затем поразрядно, начиная со старших.

```c
big_num shift(big_num num, int exp)
```
Сдвигает число `num` на `exp` блоков влево, освободившиеся разряды заполняет нулями.

```c
big_num add(big_num a, big_num b)
```
Складывает поблочно числа `a` и `b`.

```c
big_num sub(big_num a, big_num b)
```
Находит разность между числами `a` и `b` (вычитает поблочно из большего меньшее).

```c
big_num mul(big_num a, big_num b)
```
Умножает поразрядно числа`a` и `b`.

```c
division div_euc(big_num a, big_num b)
```
Делит числа `a` и `b` [столбиком](https://ru.wikipedia.org/wiki/Деление_столбиком). Возвращает таблицу из двух больших чисел — частного и остатка.

```c
big_num from_string(char* str)
```
Переводит большое число из строкового представления `str`.

```c
char* to_string(big_num num)
```
Выводит строковое представление большого числа `num`.
