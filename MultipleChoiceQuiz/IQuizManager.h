#pragma once

#include <vector>

#include "IQuestion.h"

namespace Quiz {

	class IQuizManager
	{
	public:
		virtual void init() = 0;

		virtual const int currentIndex() const = 0;
		virtual const IQuestion* currentQuestion() const = 0;
		virtual const size_t size() const = 0;
		virtual const std::vector<IQuestion*> questions() const = 0;

		virtual void loadQuestions() = 0;

		virtual const bool isLastQuestion() const = 0;

		virtual void goNextQuestion() = 0;

		virtual const int correctAnswers() const = 0;
		virtual const int incorrectAnswers() const = 0;

		virtual void incrementCorrectAnswers() = 0;
		virtual void incrementIncorrectAnswers() = 0;

		virtual const std::string getPlayerAnswer() = 0;
	};
}
