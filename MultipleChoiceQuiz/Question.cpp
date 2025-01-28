#pragma once

#include "Question.h"

using namespace Quiz;

Question::Question(std::string title, std::string body, std::string answer)
{
	m_title = title;
	m_body = body;
	m_answer = answer;
}

std::string Question::title() const {
	return m_title;
}

std::string Question::body() const {
	return m_body;
}

std::string Question::answer() const {
	return m_answer;
}

QuestionType MultipleChoiceQuestion::type() const {
	return QuestionType::MULTIPLE_CHOICE;
}

std::vector<std::string> MultipleChoiceQuestion::options() const
{
	return std::vector<std::string>();
}

QuestionType Quiz::TextInputQuestion::type() const
{
	return QuestionType::TEXT_INPUT;
}

QuestionType Quiz::NumberInputQuestion::type() const
{
	return QuestionType::NUMBER_INPUT;
}
