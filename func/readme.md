# Тесты к лабораторной работе №01

## Позитивные тесты:
- 01 - делитель представлен целым числом;
- 02 - делитель имеет вид: -.0<num>E<degree>;
- 03 - делимое имеет вид: +<num>.,  а делитель <num>E<degree>;
- 04 - при делении произошло переполнение (степень результата превысила максимальное значение);
- 05 - мантисса делимого максимально возможная по длине;
- 06 - обычный тест; 
- 07 - при делении достигнут машинный ноль (степень результата ниже минимального значения);
- 08 - деление, при котором требуется округление (только последняя цифра увеличивается);
- 09 - деление, при котором требуется округление (причем последняя цифра мантиссы 9, а следующая больше 5, поэтому происходит перенос).
*num - натуральное


## Негативные тесты:
- 01 - длина делимого превысила максимальное значение;
- 02 - делимое задано некорректно.;
- 03 - длина делителя превысила максимальное значение;
- 04 - деление на число, мантисса которого не содержит чисел, отличных от нуля;
- 05 - делитель задан некорректно.