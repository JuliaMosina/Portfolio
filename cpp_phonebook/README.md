# Phonebook
Язык: С++

Задание: написать программу для телефонной книги, приложив .hpp файлы и Makefile, со следующим поведением
 * при запуске принимает команды ADD, SEARCH или EXIT, любой другой ввод отбрасывается
 * программа запускается без контактов, не использует динамическое выделение памяти и не может хранить более 8 контактов
 * при команде EXIT программа закрывается, и контакты теряются навсегда
 * при команде ADD программа предлагает пользователю ввести информацию о новом контакте, по одному полю за раз, пока все поля не будут учтены
 * контакт должен быть представлен как экземпляр класса
 * при команде SEARCH программа отобразит список доступных непустых контактов в 4 столбцах. Каждый столбец должен быть шириной 10 символов, выровнен по правому краю и разделен символом |. Любой вывод, длина которого превышает ширину столбца, обрезается, а последний отображаемый символ заменяется точкой. Затем программа снова запросит индекс нужной записи и отобразит информацию о контакте, по одному полю в строке.