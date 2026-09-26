// #include "List.h"
// #include <gtest/gtest.h>
// #include <string>

// // ============================================================================
// // 单链表单元测试（GoogleTest）
// // 覆盖 List.h 中声明的全部 14 个接口。
// // 说明：带哨兵位的单链表中，L 指向头结点（哨兵位），L->next 才是第一个有效结点。
// // ============================================================================

// // ---------------------------------------------------------------------------
// // 基础测试：不依赖夹具，用于验证“创建结点 / 初始化”这类构造性接口。
// // ---------------------------------------------------------------------------

// // 测试 ListInit：初始化后应返回非空的哨兵位结点，
// // 其 data 为 -1、next 为 NULL（即空链表）。
// TEST(ListBasicTest, ListInit)
// {
//     LNode* L = ListInit();
//     ASSERT_NE(L, nullptr);
//     EXPECT_EQ(L->data, -1);
//     EXPECT_EQ(L->next, nullptr);
//     ListDestroy(L);
// }

// // 测试 BuyListNode：申请的新结点 data 为传入值，next 默认为 NULL。
// TEST(ListBasicTest, BuyListNode)
// {
//     LNode* node = BuyListNode(42);
//     ASSERT_NE(node, nullptr);
//     EXPECT_EQ(node->data, 42);
//     EXPECT_EQ(node->next, nullptr);
//     free(node);
// }

// // ---------------------------------------------------------------------------
// // 测试夹具：每个用例运行前自动建表，运行后自动销毁并置空，避免内存泄漏。
// // ---------------------------------------------------------------------------
// class ListTest : public ::testing::Test
// {
// protected:
//     LNode* L = nullptr;

//     // 每个用例开始前：创建一个空链表
//     void SetUp() override
//     {
//         L = ListInit();
//         ASSERT_NE(L, nullptr);
//     }

//     // 每个用例结束后：销毁链表，并把指针置空防止重复释放
//     void TearDown() override
//     {
//         if (L != nullptr)
//         {
//             ListDestroy(L);
//             L = nullptr;
//         }
//     }
// };

// // 测试 ListSize：空链表有效元素个数为 0；插入 3 个后为 3。
// TEST_F(ListTest, ListSize)
// {
//     EXPECT_EQ(ListSize(L), 0);

//     ListPushBack(L, 1);
//     ListPushBack(L, 2);
//     ListPushBack(L, 3);

//     EXPECT_EQ(ListSize(L), 3);
// }

// // 测试 ListEmpty：空链表返回 true，插入元素后返回 false。
// TEST_F(ListTest, ListEmpty)
// {
//     EXPECT_TRUE(ListEmpty(L));

//     ListPushBack(L, 1);

//     EXPECT_FALSE(ListEmpty(L));
// }

// // 测试 ListLocateElem：能定位到第一个值等于 x 的结点；不存在时返回 NULL。
// TEST_F(ListTest, ListLocateElem)
// {
//     ListPushBack(L, 1);
//     ListPushBack(L, 2);
//     ListPushBack(L, 3);

//     LNode* p = ListLocateElem(L, 2);
//     ASSERT_NE(p, nullptr);
//     EXPECT_EQ(p->data, 2);

//     // 不存在的值应返回 NULL
//     EXPECT_EQ(ListLocateElem(L, 100), nullptr);
// }

// // 测试 ListGetElem：返回下标为 i 的结点；越界返回 NULL。
// TEST_F(ListTest, ListGetElem)
// {
//     ListPushBack(L, 10);
//     ListPushBack(L, 20);
//     ListPushBack(L, 30);

//     ASSERT_NE(ListGetElem(L, 0), nullptr);
//     EXPECT_EQ(ListGetElem(L, 0)->data, 10);
//     EXPECT_EQ(ListGetElem(L, 2)->data, 30);

//     // 下标越界（合法下标为 0~2），应返回 NULL
//     EXPECT_EQ(ListGetElem(L, 3), nullptr);
// }

// // 测试 ListInsert：分别在下标 0（头）、中间、末尾插入，验证顺序与个数。
// TEST_F(ListTest, ListInsert)
// {
//     ListInsert(L, 0, 1); // 头插：1
//     ListInsert(L, 1, 3); // 尾插：1->3
//     ListInsert(L, 1, 2); // 中间插：1->2->3

//     ASSERT_EQ(ListSize(L), 3);
//     EXPECT_EQ(ListGetElem(L, 0)->data, 1);
//     EXPECT_EQ(ListGetElem(L, 1)->data, 2);
//     EXPECT_EQ(ListGetElem(L, 2)->data, 3);
// }

// // 测试 ListDelete：删除下标 1 的结点，返回其值，并验证剩余结构。
// TEST_F(ListTest, ListDelete)
// {
//     ListPushBack(L, 1);
//     ListPushBack(L, 2);
//     ListPushBack(L, 3);

//     EXPECT_EQ(ListDelete(L, 1), 2); // 删除的值应为 2
//     EXPECT_EQ(ListSize(L), 2);      // 个数减一

//     EXPECT_EQ(ListGetElem(L, 0)->data, 1);
//     EXPECT_EQ(ListGetElem(L, 1)->data, 3);
// }

// // 测试 ListPushBack：尾插后元素顺序与个数正确。
// TEST_F(ListTest, ListPushBack)
// {
//     ListPushBack(L, 1);
//     ListPushBack(L, 2);

//     EXPECT_EQ(ListSize(L), 2);
//     EXPECT_EQ(ListGetElem(L, 0)->data, 1);
//     EXPECT_EQ(ListGetElem(L, 1)->data, 2);
// }

// // 测试 ListPushFront：头插后新元素位于表头。
// TEST_F(ListTest, ListPushFront)
// {
//     ListPushFront(L, 1);
//     ListPushFront(L, 2);

//     EXPECT_EQ(ListSize(L), 2);
//     EXPECT_EQ(ListGetElem(L, 0)->data, 2);
//     EXPECT_EQ(ListGetElem(L, 1)->data, 1);
// }

// // 测试 ListPopBack：尾删后返回被删的尾元素，个数减一。
// TEST_F(ListTest, ListPopBack)
// {
//     ListPushBack(L, 1);
//     ListPushBack(L, 2);

//     EXPECT_EQ(ListPopBack(L), 2); // 返回被删的尾元素

//     EXPECT_EQ(ListSize(L), 1);
//     EXPECT_EQ(ListGetElem(L, 0)->data, 1);
// }

// // 测试 ListPopFront：头删后返回被删的首元素，个数减一。
// TEST_F(ListTest, ListPopFront)
// {
//     ListPushBack(L, 1);
//     ListPushBack(L, 2);

//     EXPECT_EQ(ListPopFront(L), 1); // 返回被删的首元素

//     EXPECT_EQ(ListSize(L), 1);
//     EXPECT_EQ(ListGetElem(L, 0)->data, 2);
// }

// // 测试 ListPrint：捕获标准输出，验证打印格式为“头结点->1->2->NULL”。
// TEST_F(ListTest, ListPrint)
// {
//     ListPushBack(L, 1);
//     ListPushBack(L, 2);

//     testing::internal::CaptureStdout(); // 开始捕获 stdout
//     ListPrint(L);
//     std::string output = testing::internal::GetCapturedStdout(); // 结束捕获

//     EXPECT_EQ(output, "头结点->1->2->NULL\n");
// }

// // 测试 ListDestroy：正常销毁整条链表（含哨兵位）且不崩溃。
// // 销毁后手动把 L 置空，避免夹具 TearDown 再次释放。
// TEST_F(ListTest, ListDestroy)
// {
//     ListPushBack(L, 1);
//     ListPushBack(L, 2);

//     ListDestroy(L);
//     L = nullptr;

//     SUCCEED();
// }
