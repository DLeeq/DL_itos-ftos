# DL_itos-ftos
## Три функции:
### Для преобразования целых 32-битных чисел в строку Си
```c
uint8_t DL_intToStr(char* str, int32_t num)
```
Аргументы:  
  - str - строка в которую будет записан результат преобразования  
  - num - целое число, которое нужно преобразовать в строку
    
Возвращаемое значение:  
  - Длина получившейся строки
---
### Для преобразования чисел с плавающей точкой в строку Си
```c
uint8_t DL_floatToStr(char* str, float num, uint8_t precision)
```
Аргументы:  
  - str - строка в которую будет записан результат преобразования  
  - num - число с плавающей точкой, которое нужно преобразовать в строку
  - precision - количество знаков после запятой, указание точности (от 0 до 6 знаков)
    
Возвращаемое значение:
  - Длина получившейся строки
---
### Для парсинга строки в целое 32-битное число
```c
uint8_t DL_parseInt(int32_t* num, char* str)
```  
Аргументы:  
  - num - целое число, в которое будет записан результат преобразования
  - str - строка, которую необходимо преобразовать в целое число  

Возвращаемое значение:
- Коды ошибок:
  - 0 : успешное преобразование
  - 1 : пустая строка
  - 2 : введен только знак
  - 3 : введен недопустимый символ
  - 4 : переполнение переменной

*Все пробелы и табуляции игнорируются при преобразовании*

---
Ничего лишнего =)

Если вы нашли баг, или есть предложения по доработке, пишите мне в [Телеграм - группу](https://t.me/DLeeFB) для обратной связи =)
