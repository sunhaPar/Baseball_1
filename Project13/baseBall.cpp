#include <stdexcept>
#include <vector>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string & question)
		:question(question)
	{

	}

	GuessResult playRound(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);

		if (isCorrectAnswer(guessNumber))
		{
			return { true, 3, 0 };
		}

		GuessResult result = {false, 0, 0};

		getStrikeAndBall(guessNumber, &result);
		return result;
	}



private:
	string question;
	
	bool isCorrectAnswer(const string& guessNumber)
	{
		return (guessNumber == question);
	}

	int getBallCount(int gIdx, char targetChar)
	{
		for (int qIdx = 0; qIdx < question.size(); qIdx++)
		{
			if (gIdx == qIdx) continue;
			if (targetChar == question[qIdx])
			{
				return 1;
			}
		}
		return 0;
	}

	void getStrikeAndBall(string guessNumber, GuessResult * result)
	{
		int nStrike = 0;
		for (int gIdx = 0; gIdx < question.size(); gIdx++)
		{
			if (guessNumber[gIdx] == question[gIdx])
			{
				result->strikes++;
			}
			else
			{
		    	result->balls += getBallCount(gIdx, guessNumber[gIdx]);
			}
		}
	}

	bool isDuplicateNumber(string guessNumber)
	{
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2])
		{
			return true;
		}
		return false;
	}

	void assertIllegalArgument(string guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char c : guessNumber)
		{
			if (c >= '0' && c <= '9') continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicateNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}
};
