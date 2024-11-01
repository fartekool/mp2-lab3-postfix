#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
	EXPECT_ANY_THROW(TStack<int> st(-1));
}

TEST(TStack, method_empty_for_empty_stack_return_true)
{	
	TStack<int> st(5);
	EXPECT_TRUE(st.Empty());
}

TEST(TStack, method_empty_for_not_empty_stack_return_false)
{
	TStack<int> st(5);
	st.Push(1);
	EXPECT_FALSE(st.Empty());
}

TEST(TStack, method_full_for_full_stack_return_true)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	EXPECT_TRUE(st.Full());
}

TEST(TStack, method_full_for_not_full_stack_return_false)
{
	TStack<int> st(5);
	for (int i = 0; i < 4; ++i)
		st.Push(1);
	EXPECT_FALSE(st.Full());
}

TEST(TStack, can_get_size_of_stack)
{
	TStack<int> st(10);
	for (int i = 0; i < 4; ++i)
		st.Push(1);
	EXPECT_EQ(st.Size(), 4);
}

TEST(TStack, can_push_element_into_not_full_stack)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(st.Push(1));
}

TEST(TStack, cant_push_element_into_full_stack)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	ASSERT_ANY_THROW(st.Push(1));
}

TEST(TStack, can_pop_and_top_element_from_not_empty_stack)
{
	TStack<int> st(3);
	st.Push(1);
	ASSERT_NO_THROW(st.Pop());
	st.Push(1);
	ASSERT_NO_THROW(st.Top());
}

TEST(TStack, cant_pop_and_top_element_from_empty_stack)
{
	TStack<int> st(3);
	ASSERT_ANY_THROW(st.Pop());
	ASSERT_ANY_THROW(st.Top());
}

TEST(TStack, method_top_return_top_element)
{
	TStack<int> st(3);
	st.Push(147);
	EXPECT_EQ(st.Top(), 147);
}

TEST(TStack, method_pop_decrement_size)
{
	TStack<int> st(10);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	st.Pop();
	EXPECT_EQ(st.Size(), 4);
}

TEST(TStack, method_top_doesnt_change_size)
{
	TStack<int> st(10);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	st.Top();
	EXPECT_EQ(st.Size(), 5);
}

TEST(TStack, can_clear_stack)
{
	TStack<int> st(10);
	ASSERT_NO_THROW(st.Clear());
}

TEST(TStack, size_equals_zero_after_clear_stack)
{
	TStack<int> st(10);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	st.Clear();
	EXPECT_EQ(st.Size(), 0);
}
