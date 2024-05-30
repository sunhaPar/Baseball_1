#include "pch.h"
#include "../Project13/baseBall.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIlleagalArgument(string guessNumber)
	{
		//exception 발생해야 Pass
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e) { //pass
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {

	assertIlleagalArgument("12");
	assertIlleagalArgument("12s");
	assertIlleagalArgument("121");
}


