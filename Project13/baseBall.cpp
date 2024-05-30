#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
	}



private:
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
