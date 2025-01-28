#pragma once

#include "IQuestion.h"

#include <vector>

namespace Quiz {
	class Question : public IQuestion
	{
	public:
		Question(std::string title, std::string body, std::string answer);

		std::string title() const override;
		std::string body() const override;
		std::string answer() const override;

	protected:
		std::string m_title;
		std::string m_body;
		std::string m_answer;
	};

	class MultipleChoiceQuestion : public Question
	{
	public:
		QuestionType type() const override;

		std::vector<std::string> options() const;
	};

	class TextInputQuestion : public Question
	{
	public:
		using Question::Question;

		QuestionType type() const override;
	};

	class NumberInputQuestion : public Question
	{
	public:
		QuestionType type() const override;
	};
}