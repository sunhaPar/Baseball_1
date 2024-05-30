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

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		GuessResult result = {false, 0, 0};

		getStrikeAndBall(guessNumber, &result);
		return result;
	}



private:
	string question;

	void getStrikeAndBall(string guessNumber, GuessResult * result)
	{
		int nStrike = 0;
		for (int i = 0; i< question.size(); i++)
		{
			if (guessNumber[i] == question[i])
			{
				result->strikes++;
			}
			else
			{
				for (int j = 0; j < question.size(); j++)
				{
					if (i == j) continue;

					if (guessNumber[i] == question[j])  result->balls++;
				}
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
