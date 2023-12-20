#include "C:\Users\KDFX Team\Desktop\hjgjgh\lab3stack\lab3stack\TStack.h"

#include "..\..\..\lab2\mp2-lab2-matrix\gtest\gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> stack(2));
}
TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> stack(1000));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> stack(-2));
}
TEST(TStack, can_create_copied_stack)
{
	TStack<int> stack(2);
	ASSERT_NO_THROW(TStack<int> stack1(stack));
}

TEST(TStack, can_push_element)
{
	TStack<int> stack(2);
	stack.Push(2);
	EXPECT_EQ(stack.GetTop(), 0);
}

TEST(TStack, can_check_full_of_stack)
{
	TStack<int> stack(2);
	stack.Push(2);
	stack.Push(2);
	EXPECT_EQ(stack.IsFull(), true);

}

TEST(TStack, can_check_empty_of_stack)
{
	TStack<int> stack(2);
	EXPECT_EQ(stack.IsEmpty(), true);
}


TEST(TStack, can_get_Value_element)
{
	TStack<int> stack(2);
	stack.Push(2);
	stack.Push(2);
	EXPECT_EQ(stack.TopView(), 2);
}
