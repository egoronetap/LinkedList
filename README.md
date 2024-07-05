# LinkedList
Связный список на языке C

В качестве примера реализовать связный список из структур-студентов Student, имеющих формат:

int year

char[35] name

char[10] group

Реализовать однонаправленный связный список LinkedList со следующими функциями:

поиск в связном списке bool Search(LinkedList L, Student S)

добавление элеента в конец списка void Add(LinkedList L, Student S)

вставка элемента после заданного ключа void AddAfter(LinkedList L, Student S, string key)

удаление элемента по заданному ключу void Delete(LinkedList L, Student S, string key).
