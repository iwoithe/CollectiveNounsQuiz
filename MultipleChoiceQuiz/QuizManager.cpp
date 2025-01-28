#include "QuizManager.h"

#include <iostream>

#include "Macros.h"
#include "Question.h"

using namespace Quiz;

QuizManager::~QuizManager()
{
	DEL_STD_VEC(m_questions);
}

void Quiz::QuizManager::init()
{
	m_correctAnswers = 0;
	m_incorrectAnswers = 0;
	m_currentIndex = 0;

	loadQuestions();
}

const int QuizManager::currentIndex() const
{
	return m_currentIndex;
}

const IQuestion* QuizManager::currentQuestion() const
{
	return m_questions.at(m_currentIndex);
}

const size_t Quiz::QuizManager::size() const
{
	return m_questions.size();
}

const std::vector<IQuestion*> Quiz::QuizManager::questions() const
{
	return m_questions;
}

void Quiz::QuizManager::loadQuestions()
{
	#define QUESTION_TITLE_STR(animal) std::string { "What is the collective noun for " } + animal + std::string { "?" }

	// Taken from https://www.macquariedictionary.com.au/collective-nouns-for-animals/
	m_questions = {
		new TextInputQuestion(QUESTION_TITLE_STR("crows"), "", "murder"),
		new TextInputQuestion(QUESTION_TITLE_STR("giraffes"), "", "herd"),
		new TextInputQuestion(QUESTION_TITLE_STR("jellyfish"), "", "smack"),
		new TextInputQuestion(QUESTION_TITLE_STR("toads"), "", "knot"),
		new TextInputQuestion(QUESTION_TITLE_STR("lions"), "", "pride"),
		new TextInputQuestion(QUESTION_TITLE_STR("bears"), "", "sloth"),
		new TextInputQuestion(QUESTION_TITLE_STR("cats"), "", "clowder"),
		new TextInputQuestion(QUESTION_TITLE_STR("elephants"), "", "herd"),
		new TextInputQuestion(QUESTION_TITLE_STR("ferrets"), "", "business"),
		new TextInputQuestion(QUESTION_TITLE_STR("chicks"), "", "peep"),
		new TextInputQuestion(QUESTION_TITLE_STR("ponies"), "", "string"),
		new TextInputQuestion(QUESTION_TITLE_STR("seals"), "", "plump"),
		new TextInputQuestion(QUESTION_TITLE_STR("gnats"), "", "cloud"),
		new TextInputQuestion(QUESTION_TITLE_STR("turkeys"), "", "rafter"),
		new TextInputQuestion(QUESTION_TITLE_STR("gorillas"), "", "band"),
		new TextInputQuestion(QUESTION_TITLE_STR("frogs"), "", "knot"),
		new TextInputQuestion(QUESTION_TITLE_STR("rhinoceroses"), "", "crash"),
	};
}

const bool Quiz::QuizManager::isLastQuestion() const
{
	return m_currentIndex == m_questions.size() - 1;
}

void QuizManager::goNextQuestion()
{
	m_currentIndex++;
}

const int Quiz::QuizManager::correctAnswers() const
{
	return m_correctAnswers;
}

const int Quiz::QuizManager::incorrectAnswers() const
{
	return m_incorrectAnswers;
}

void QuizManager::incrementCorrectAnswers()
{
	m_correctAnswers++;
}

void QuizManager::incrementIncorrectAnswers()
{
	m_incorrectAnswers++;
}

const std::string Quiz::QuizManager::getPlayerAnswer()
{
	std::string playerAnswer;

	std::getline(std::cin, playerAnswer);

	return playerAnswer;
}
