# OOP_C
Исматов Фаррух
# 1)
Чтобы мы могли совершать с классами те же операции, что и со стандартными типами данных.

# 2)
При поверхностным копировании используют почленный метод копирования, то есть выполняют копирование для каждого члена класса индивидуально.
При глубоком копировании память сначала выделяется для копирования адреса, который содержит исходный указатель, а затем для копирования фактического значения.

# 3)
std::cout - это объект std::ostream и нам не нужна его копия, поэтому и использыем ссылки

# 4)
Ключевое слово explicit делает конструктор закрытым для выполнения любых неявных преобразований, но все еще может использоваться внутри класса. Для решения этой проблемы используется delete для удаления конструктора. После удаления метода, любое ее использование приведет к ошибке.
