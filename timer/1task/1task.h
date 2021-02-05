// 1task.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <memory>
#include <chrono>
#include <cmath>

class Timer
{
public:
	Timer();
	~Timer();
	void smt();

private:
	using clock = std::chrono::steady_clock;
	using timepoint = clock::time_point;
	using duration = clock::duration;
	timepoint begin;
};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
