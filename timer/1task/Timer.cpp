#include"1task.h"

Timer::Timer()
{
	timepoint begin = clock::now();
	std::cout << "Запустился конструктор и таймер\n";
}

Timer::~Timer()
{
	std::cout << "Вызвался деструктор\n";
	timepoint end = clock::now();
	duration elapsed_time = end - begin;
	std::cout << std::chrono::duration_cast<std::chrono::seconds>(elapsed_time).count() << std::endl;

}

void Timer::smt()
{
	for (auto idx = 0; idx < 1e6; idx++) {
		auto res = std::sin(idx) + std::tan(idx);
	}
}
