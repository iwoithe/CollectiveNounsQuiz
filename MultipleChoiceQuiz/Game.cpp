#include "Game.h"

#include <algorithm>
#include <conio.h>

#include "Macros.h"

#include "IQuestion.h"
#include "QuizManager.h"

#define KEY_ENTER 13
#define KEY_n 110
#define KEY_y 121

enum EndQuizMode {
    PLAY_AGAIN,
    QUIT
};

Quiz::Game::~Game()
{
    DEL_PTR_S(m_quizManager);
}

void Quiz::Game::play()
{
    bool isPrompt = false;
    char promptChar{};

    if (m_quizManager == nullptr) {
        m_quizManager = new Quiz::QuizManager();
    }

    m_quizManager->init();

    system("cls");

    PRINT("Welcome to the quiz on collective nouns for animals!\n");

    PRINT_NO_NL("Do you the answers to be shown? ([y] or [n])  ");
    char showAnswersChar{};

    isPrompt = true;

    while (isPrompt) {
        switch (_getch()) {
        case KEY_ENTER:
            switch (promptChar) {
            case 'y':
                isPrompt = false;
                m_showAnswers = true;
                break;
            case 'n':
                isPrompt = false;
                m_showAnswers = false;
                break;
            default:
                break;
            }
            break;
        case KEY_y:
            promptChar = 'y';
            PRINT_NO_NL("\033[1D") PRINT_CONT("y");
            break;
        case KEY_n:
            promptChar = 'n';
            PRINT_NO_NL("\033[1D") PRINT_CONT("n");
            break;
        default:
            break;
        }
    }

    PRINT("\n\n");

    m_isRunning = true;

    while (m_isRunning) {
        PRINT(m_quizManager->currentQuestion()->title());
        if (m_quizManager->currentQuestion()->body() != "") {
            PRINT(m_quizManager->currentQuestion()->body());
        }

        std::string playerAnswer = m_quizManager->getPlayerAnswer();
        std::transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), std::tolower);

        if (playerAnswer == m_quizManager->currentQuestion()->answer()) {
            PRINT("Correct!\n");

            m_quizManager->incrementCorrectAnswers();
        }
        else {
            if (m_showAnswers) {
                PRINT("Incorrect. The correct answer is a " + m_quizManager->currentQuestion()->answer() + ".\n");
            }
            else {
                PRINT("Incorrect.\n");
            }

            m_quizManager->incrementIncorrectAnswers();
        }

        if (m_quizManager->isLastQuestion()) {
            break;
        }
        else {
            m_quizManager->goNextQuestion();
        }
    }

    PRINT_NO_NL("Quiz finished. You got ")
        PRINT_CONT(m_quizManager->correctAnswers())
        PRINT_CONT(" questions correct and ")
        PRINT_CONT(m_quizManager->incorrectAnswers())
        PRINT_CONT(" questions incorrect for a score of ")
        PRINT_CONT((float)m_quizManager->correctAnswers() / (float)m_quizManager->size() * 100.f)
        PRINT_CONT("%")
        PRINT_CONT_NL();
    
    PRINT_NO_NL("Play again? ([y] or [n])  ");

    isPrompt = true;
    EndQuizMode endQuizMode = EndQuizMode::QUIT;

    while (isPrompt) {
        switch (_getch()) {
        case KEY_ENTER:
            switch (promptChar) {
            case 'y':
                isPrompt = false;
                endQuizMode = EndQuizMode::PLAY_AGAIN;
                break;
            case 'n':
                isPrompt = false;
                endQuizMode = EndQuizMode::QUIT;
                break;
            default:
                break;
            }
            break;
        case KEY_y:
            promptChar = 'y';
            PRINT_NO_NL("\033[1D") PRINT_CONT("y");
            break;
        case KEY_n:
            promptChar = 'n';
            PRINT_NO_NL("\033[1D") PRINT_CONT("n");
            break;
        default:
            break;
        }
    }

    PRINT("\n\n");

    switch (endQuizMode) {
    case EndQuizMode::PLAY_AGAIN:
        play();
    case EndQuizMode::QUIT:
        break;
    }
}
