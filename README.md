# yadro-algo-test-task

### Сборка

``` bash
mkdir build
cd build
cmake ..
make all
```

### Запуск

``` bash
cd build
./src/task_run test_file.txt
```

### TODO

- [ ] Проверка правильности ввода данных
- [ ] Классы и структуры данных для хранения данных
- [x] Считывание
- [ ] Юнит-тесты при помощи библиотеки GoogleTest
- [x] Сборка при помощи CMake
- [x] Возможность компиляции и в Linux, и в Windows
- [x] Обработка события
    - [x] Клиент пришёл
    - [x] Клиент сел за стол
    - [x] Клиент ожидает
    - [x] Клиент ушёл
- [x] Создание исходящих событий
    - [x] Клиент ушёл
    - [x] Клиент сел за стол
    - [x] Ошибки
- [x] Производится подсчёт выручки
- [x] Вывод производится в описанном формате


### Вопросы, которые возникли

- Может ли имя пользователя состоять только из "-", "\_" или чисел?
- Каждый пришедший клиент сразу попадает в очередь? Или только после события клиент ожидает?


### Примеры работы

Пример из задания

``` bash
~$ cat ../examples/basic_example.txt
3
09:00 19:00
10
08:48 1 client1
09:41 1 client1
09:48 1 client2
09:52 3 client1
09:54 2 client1 1
10:25 2 client2 2
10:58 1 client3
10:59 2 client3 3
11:30 1 client4
11:35 2 client4 2
11:45 3 client4
12:33 4 client1
12:43 4 client2
15:52 4 client4
~$ ./src/task_run ../examples/basic_example.txt
09:00
08:48 1 client1
08:48 13 NotOpenYet
09:41 1 client1
09:48 1 client2
09:52 3 client1
09:52 13 ICanWaitNoLonger
09:54 2 client1 1
10:25 2 client2 2
10:58 1 client3
10:59 2 client3 3
11:30 1 client4
11:35 2 client4 2
11:35 13 PlaceIsBusy
11:45 3 client4
12:33 4 client1
12:33 12 client4
12:43 4 client2
15:52 4 client4
19:00 11 client3
19:00
1 70 05:58
2 30 02:18
3 90 08:01
```

Обработка файла с неправильным шаблоном

``` bash
~$ cat ../examples/not_right_template.cpp
10:00 12:00
3
14:00 meow meow
~$ ./src/task_run ../examples/not_right_template.cpp 
terminate called after throwing an instance of 'std::invalid_argument'
  what():  file can't read
[1]    7342 IOT instruction (core dumped)  ./src/task_run ../examples/not_right_template.cpp  
```


Передача в параметр пустого файла

``` bash
~$ ls ../examples
bad_name_example.txt  basic_example.txt  not_right_template.cpp
~$ ./src/task_run ../examples/not_exists_file.txt         
terminate called after throwing an instance of 'std::invalid_argument'
  what():  file is not opened
[1]    9428 IOT instruction (core dumped)  ./src/task_run ../examples/not_exists_file.txt > output
```
