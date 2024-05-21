#include "pch.h"
#include <array>
#include <type_traits>
#include "C:\Users\matas\OneDrive\Desktop\vu\Objektinis\v3.0\v3.0_vektoriai\v3.0_vektoriai\ManoVektorius.cpp"

TEST(ManoVektoriusTest, MemberTypes) { // Vienas testas, kuris testuoja visus member types
    ManoVektorius<int> vec;
    // value_type
    static_assert(std::is_same<decltype(vec)::value_type, int>::value, "value_type should be int");
    // allocator_type
    static_assert(std::is_same<decltype(vec)::allocator_type, std::allocator<int>>::value, "allocator_type should be std::allocator<int>");
    // size_type
    static_assert(std::is_same<decltype(vec)::size_type, std::size_t>::value, "size_type should be std::size_t");
    // difference_type
    static_assert(std::is_same<decltype(vec)::difference_type, std::ptrdiff_t>::value, "difference_type should be std::ptrdiff_t");
    // reference
    static_assert(std::is_same<decltype(vec)::reference, int&>::value, "reference should be int&");
    // const_reference
    static_assert(std::is_same<decltype(vec)::const_reference, const int&>::value, "const_reference should be const int&");
    // pointer
    static_assert(std::is_same<decltype(vec)::pointer, int*>::value, "pointer should be int*");
    // const_pointer
    static_assert(std::is_same<decltype(vec)::const_pointer, const int*>::value, "const_pointer should be const int*");
    // iterator
    static_assert(std::is_same<decltype(vec)::iterator, typename ManoVektorius<int>::iterator>::value, "iterator should be ManoVektorius<int>::iterator");
    // const_iterator
    static_assert(std::is_same<decltype(vec)::const_iterator, typename ManoVektorius<int>::const_iterator>::value, "const_iterator should be ManoVektorius<int>::const_iterator");
    // reverse_iterator
    static_assert(std::is_same<decltype(vec)::reverse_iterator, std::reverse_iterator<typename ManoVektorius<int>::iterator>>::value, "reverse_iterator should be std::reverse_iterator<ManoVektorius<int>::iterator>");
    // const_reverse_iterator
    static_assert(std::is_same<decltype(vec)::const_reverse_iterator, std::reverse_iterator<typename ManoVektorius<int>::const_iterator>>::value, "const_reverse_iterator should be std::reverse_iterator<ManoVektorius<int>::const_iterator>");
}

TEST(ManoVektoriusTest, Constructor) {
    ManoVektorius<int> vec;
    EXPECT_EQ(vec.size(), 0);
}

TEST(ManoVektoriusTest, Destructor) {
    ManoVektorius<int>* vec = new ManoVektorius<int>();
    vec->push_back(1);
    delete vec;
}

TEST(ManoVektoriusTest, OperatorAssign) {
    ManoVektorius<int> vec1;
    vec1.push_back(1);
    ManoVektorius<int> vec2;
    vec2 = vec1;
    EXPECT_EQ(vec2.size(), 1);
    EXPECT_EQ(vec2[0], 1);
}

TEST(ManoVektoriusTest, Assign) {
    ManoVektorius<int> vec;
    std::vector<int> values(5, 10);
    vec.assign(values.begin(), values.end());
    EXPECT_EQ(vec.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(vec[i], 10);
    }
}

TEST(ManoVektoriusTest, AssignRange) {
    std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
    ManoVektorius<int> vec;
    vec.assign(arr.begin(), arr.end());
    EXPECT_EQ(vec.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(vec[i], arr[i]);
    }
}

TEST(ManoVektoriusTest, GetAllocator) {
    ManoVektorius<int> vec;
    std::allocator<int> alloc = vec.get_allocator();
    int* p = alloc.allocate(1);  // allocate an int
    alloc.deallocate(p, 1);  // deallocate it
}

TEST(ManoVektoriusTest, At) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    EXPECT_EQ(vec.at(0), 10);
    EXPECT_THROW(vec.at(1), std::out_of_range);
}

TEST(ManoVektoriusTest, OperatorSquareBrackets) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    EXPECT_EQ(vec[0], 10);
}

TEST(ManoVektoriusTest, Back) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    EXPECT_EQ(vec.back(), 20);
}

TEST(ManoVektoriusTest, End) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    typename ManoVektorius<int>::iterator it = vec.end();
    EXPECT_EQ(*(--it), 20);
}

TEST(ManoVektoriusTest, CEnd) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    typename ManoVektorius<int>::const_iterator it = vec.cend();
    EXPECT_EQ(*(--it), 20);
}

TEST(ManoVektoriusTest, RBegin) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    typename ManoVektorius<int>::reverse_iterator it = vec.rbegin();
    EXPECT_EQ(*it, 20);
}

TEST(ManoVektoriusTest, CRBegin) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    typename ManoVektorius<int>::const_reverse_iterator it = vec.crbegin();
    EXPECT_EQ(*it, 20);
}

TEST(ManoVektoriusTest, Empty) {
    ManoVektorius<int> vec;
    EXPECT_TRUE(vec.empty());
    vec.push_back(10);
    EXPECT_FALSE(vec.empty());
}

TEST(ManoVektoriusTest, Size) {
    ManoVektorius<int> vec;
    EXPECT_EQ(vec.size(), 0);
    vec.push_back(10);
    EXPECT_EQ(vec.size(), 1);
}

TEST(ManoVektoriusTest, MaxSize) {
    ManoVektorius<int> vec;
    EXPECT_EQ(vec.max_size(), std::numeric_limits<size_t>::max() / sizeof(int));
}

TEST(ManoVektoriusTest, Reserve) {
    ManoVektorius<int> vec;
    EXPECT_EQ(vec.getCapacity(), 0);
    vec.reserve(100);
    EXPECT_GE(vec.getCapacity(), 100);
}

TEST(ManoVektoriusTest, Capacity) {
    ManoVektorius<int> vec;
    vec.reserve(100);
    EXPECT_EQ(vec.getCapacity(), 100);
}

TEST(ManoVektoriusTest, ShrinkToFit) {
    ManoVektorius<int> vec;
    vec.reserve(100);
    vec.push_back(10);
    vec.shrink_to_fit();
    EXPECT_EQ(vec.getCapacity(), vec.size());
}

TEST(ManoVektoriusTest, Clear) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.clear();
    EXPECT_EQ(vec.size(), 0);
}

TEST(ManoVektoriusTest, Insert) {
    ManoVektorius<int> vec;
    vec.insert(vec.begin(), 10);
    EXPECT_EQ(vec[0], 10);
}


TEST(ManoVektoriusTest, Emplace) {
    ManoVektorius<int> vec;
    vec.emplace(vec.begin(), 10);
    EXPECT_EQ(vec[0], 10);
}

TEST(ManoVektoriusTest, Erase) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.erase(vec.begin());
    EXPECT_EQ(vec.size(), 0);
}

TEST(ManoVektorius, PushBack) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    EXPECT_EQ(vec[0], 10);
}

TEST(ManoVektoriusTest, EmplaceBack) {
    ManoVektorius<int> vec;
    vec.emplace_back(10);
    EXPECT_EQ(vec[0], 10);
}

TEST(ManoVektoriusTest, AppendRange) {
    ManoVektorius<int> vec;
    std::vector<int> range = { 10, 20, 30 };
    vec.append_range(range.begin(), range.end());
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 30);
}

TEST(ManoVektoriusTest, PopBack) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 0);
}

TEST(ManoVektoriusTest, Resize) {
    ManoVektorius<int> vec;
    vec.resize(10);
    EXPECT_EQ(vec.size(), 10);
}

TEST(ManoVektoriusTest, Swap) {
    ManoVektorius<int> vec1;
    vec1.push_back(10);
    ManoVektorius<int> vec2;
    vec2.push_back(20);
    vec1.swap(vec2);
    EXPECT_EQ(vec1[0], 20);
    EXPECT_EQ(vec2[0], 10);
}

TEST(ManoVektoriusTest, OperatorEqual) {
    ManoVektorius<int> vec1;
    vec1.push_back(10);
    ManoVektorius<int> vec2;
    vec2.push_back(10);
    EXPECT_TRUE(vec1 == vec2);
}

TEST(ManoVektoriusTest, OperatorNotEqual) {
    ManoVektorius<int> vec1;
    vec1.push_back(10);
    ManoVektorius<int> vec2;
    vec2.push_back(20);
    EXPECT_TRUE(vec1 != vec2);
}

TEST(ManoVektoriusTest, OperatorLessThan) {
    ManoVektorius<int> vec1;
    vec1.push_back(10);
    ManoVektorius<int> vec2;
    vec2.push_back(20);
    EXPECT_TRUE(vec1 < vec2);
}

TEST(ManoVektorius, OperatorLessThanOrEqual) {
    ManoVektorius<int> vec1;
    vec1.push_back(10);
    ManoVektorius<int> vec2;
    vec2.push_back(10);
    EXPECT_TRUE(vec1 <= vec2);
}

TEST(ManoVektoriusTest, OperatorGreaterThan) {
    ManoVektorius<int> vec1;
    vec1.push_back(20);
    ManoVektorius<int> vec2;
    vec2.push_back(10);
    EXPECT_TRUE(vec1 > vec2);
}

TEST(ManoVektoriusTest, OperatorGreaterThanOrEqual) {
    ManoVektorius<int> vec1;
    vec1.push_back(20);
    ManoVektorius<int> vec2;
    vec2.push_back(20);
    EXPECT_TRUE(vec1 >= vec2);
}

TEST(ManoVektoriusTest, StdSwap) {
    ManoVektorius<int> vec1;
    vec1.push_back(10);
    ManoVektorius<int> vec2;
    vec2.push_back(20);
    std::swap(vec1, vec2);
    EXPECT_EQ(vec1[0], 20);
    EXPECT_EQ(vec2[0], 10);
}

TEST(ManoVektoriusTest, NonMemberErase) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    auto it = std::find(vec.begin(), vec.end(), 10);
    if (it != vec.end()) {
        vec.erase(it);
    }
    EXPECT_EQ(vec[0], 20);
}

TEST(ManoVektoriusTest, EraseIf) {
    ManoVektorius<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) {return x == 10; });
    if (it != vec.end()) {
        vec.erase(it);
    }
    EXPECT_EQ(vec[0], 20);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}