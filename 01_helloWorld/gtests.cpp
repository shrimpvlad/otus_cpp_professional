#include <gtest/gtest.h>
#include "version.h"

TEST(CheckVersionNumber, correct_version) {
    ASSERT_GT(BUILD_NUMBER, 0);
}