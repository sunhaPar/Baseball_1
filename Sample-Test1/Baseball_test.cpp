#include "pch.h"
#include "../Project13/baseBall.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLengthUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}