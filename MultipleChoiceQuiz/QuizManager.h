#pragma once

#include "IQuizManager.h"

namespace Quiz {
	class QuizManager : public IQuizManager
	{
	public:
		~QuizManager();

		void init() override;

		const int currentIndex() const override;
		const IQuestion* currentQuestion() const override;
		const size_t size() const override;
		const std::vector<IQuestion*> questions() const override;

		void loadQuestions();

		const bool isLastQuestion() const override;

		void goNextQuestion() override;

		const int correctAnswers() const override;
		const int incorrectAnswers() const override;

		void incrementCorrectAnswers() override;
		void incrementIncorrectAnswers() override;

		const std::string getPlayerAnswer() override;
	private:
		std::vector<IQuestion*> m_questions {};
		int m_currentIndex = 0;

		int m_correctAnswers = 0;
		int m_incorrectAnswers = 0;
	};
}
