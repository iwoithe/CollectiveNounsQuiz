#pragma once

#include <string>

namespace Quiz {
	enum QuestionType {
		MULTIPLE_CHOICE,
		TEXT_INPUT,
		NUMBER_INPUT
	};

	class IQuestion
	{
	public:
		virtual QuestionType type() const = 0;
		virtual std::string title() const = 0;
		virtual std::string body() const = 0;
		virtual std::string answer() const = 0;
	};
}
