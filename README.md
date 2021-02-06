# OOP_C
Исматов Фаррух

1)

1.**Наследование** - механизм, который позволяет описать новый класс на основе существующего (родительского). При этом свойства и функциональность родительского класса заимствуются новым классом.

2.**Инкапсуляция** означает ограничение доступа к данным и возможностям их изменения.

3.**Полиморфизм**  - это возможность работать с несколькими типами так, будто это один и тот же тип.

4.**Абстракция** - это выделение главных, наиболее значимых характеристик предмета и наоборот — отбрасывание второстепенных, незначительных.
<hr>
2)

**Идиома RAII** - это великое правило, без которого не может обойтись любой программист. Если задействовал ресурсы компьютера, так изволь освободить их после окончания работы. Пример  в стандартной библиотеке.
«`{C++}< >{
template<typename T>
class Pointer
{
public:
	Pointer(T* ptr) {
		this->ptr = ptr;
	}
	~Pointer() {
		delete ptr;
	}

private:
	T* ptr;

};}«`
<hr>
3)

**Public** – доступ открыт всем, кто видит определение данного класса. Там в основном пишутся методы класса.
**Private** – доступ открыт только для самого класса. Там в основном пишутся переменные, члены класса.
Какой принцип ООП они реализуют? **Инкапсуляции.**

<hr>
4)
Допустим у нас есть заголовочные файлы с функциями. Эти функции имеют одинаковые имена и параметры, но выполняют разные вещи. Если мы подключим эти функции в одну область видимости, то это приведет к конфликту имен, так как компилятор не будет понимать какую именно функцию ему надо использовать. В результате, компилятор выдаст ошибку. Для решения подобных проблем и вводятся пространства имен.

Способ указать компилятору искать функцию в определенном пространстве имен — это использовать название необходимого пространства имен вместе с оператором  (::) и требуемом функцией. Еще допускается объявление пространств имен в нескольких местах. И последним свойством является то, что одни пространства имен могут быть вложены в другие пространства имен.

<hr>
5) Системы контроля версий нужны для работы с исходным кодом как одному программисту, так и целой команде. Вообще системы контроля версий - это некий инструмент, а инструментом можно пользоваться по разному, в зависимости от задач. Приведу основные примеры. Доступна история изменения кода, твой код видят остальные члены команды, собрать проект воедино в разы легче, видна твоя активность работодателям, хранить код в гите в разы безопаснее, ведь в любую секунду у тебя может слететь видна и тд...
