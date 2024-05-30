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

TEST_F(BaseballFixture, ReturnSolvedResultIfTwoStrike) {
	GuessResult result = game.guess("129");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIfTwoBall) {
	GuessResult result = game.guess("812");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(2, result.balls);
}


TEST_F(BaseballFixture, ReturnSolvedResultIfOneStrikeTwoBall) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}
