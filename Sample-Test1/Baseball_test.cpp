#include "pch.h"
#include "../Project13/baseBall.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
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

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);

}

