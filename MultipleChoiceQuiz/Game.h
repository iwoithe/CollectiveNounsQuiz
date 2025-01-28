#pragma once

#include "IQuizManager.h"

namespace Quiz {
	class Game
	{
	public:
		~Game();
		void play();
	private:
		bool m_isRunning = false;
		Quiz::IQuizManager* m_quizManager = nullptr;
		bool m_showAnswers = false;
	};
}
