#include <gtest/gtest.h>
#include "client.cpp"

TEST(ClientTest, ClientNameIsRight)
{ 
    Client client("test_name");
    ASSERT_TRUE(client.is_valid_name());
    client.set_name("with_numbers_123");
    ASSERT_TRUE(client.is_valid_name());
    client.set_name("another_example");
    ASSERT_TRUE(client.is_valid_name());
}


TEST(ClientTest, ClientNameIsBadWithCapitalLetters) {
    try {
        Client client("BadName");
        FAIL() << "Expected std::invalid_argument";
    } 
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("name is not valid"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}


TEST(ClientTest, ClientNameIsBadWithForbiddenCharacters) {
    try {
        Client client("bad_name&231");
        FAIL() << "Expected std::invalid_argument";
    } 
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("name is not valid"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(ClientTest, ClientNameIsEmpty) {
    try {
        Client client("");
        FAIL() << "Expected std::invalid_argument";
    } 
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("name is not valid"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

