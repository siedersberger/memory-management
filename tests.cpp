#include <iostream>
#include <gtest/gtest.h>
#include "memorylist.h"


namespace
{
    class MemoryTest: public ::testing::Test 
    {
        public:
            void SetUp() override
            {
                ml_ff = new MemoryList(100, 1);
                ml_bf = new MemoryList(100, 2);
                ml_wf = new MemoryList(100, 3);
            }

            void TearDown() override
            {
                delete ml_ff;
                delete ml_bf;
                delete ml_wf;
            }

            MemoryList *ml_ff;
            MemoryList *ml_bf;
            MemoryList *ml_wf;
    };

    TEST_F(MemoryTest, EmptyMemory)
    {
        EXPECT_EQ(ml_ff->memory_allocated_percentage(), 0);
        EXPECT_EQ(ml_bf->memory_allocated_percentage(), 0);
        EXPECT_EQ(ml_wf->memory_allocated_percentage(), 0);
                EXPECT_EQ(ml_ff->mem_status(),"0");
        EXPECT_EQ(ml_bf->mem_status(),"0");
        EXPECT_EQ(ml_wf->mem_status(),"0");
    }

    TEST_F(MemoryTest, SimpleAllocation)
    {
        ml_ff->add_element(50);
        ml_bf->add_element(50);
        ml_wf->add_element(50);
        EXPECT_EQ(ml_ff->memory_allocated_percentage(), 50);
        EXPECT_EQ(ml_bf->memory_allocated_percentage(), 50);
        EXPECT_EQ(ml_wf->memory_allocated_percentage(), 50);
        EXPECT_EQ(ml_ff->mem_status(),"10");
        EXPECT_EQ(ml_bf->mem_status(),"10");
        EXPECT_EQ(ml_wf->mem_status(),"10");
    }

    TEST_F(MemoryTest, EmptyDeallocation)
    {
        EXPECT_EQ((ml_ff->del_element(1)), -1);
        EXPECT_EQ((ml_bf->del_element(1)), -1);
        EXPECT_EQ((ml_wf->del_element(1)), -1);
    }

        TEST_F(MemoryTest, OverAllocation)
    {
        ml_ff->add_element(50);
        ml_bf->add_element(50);
        ml_wf->add_element(50);
        ml_ff->add_element(51);
        ml_bf->add_element(51);
        ml_wf->add_element(51);
        EXPECT_EQ(ml_ff->memory_allocated_percentage(), 50);
        EXPECT_EQ(ml_bf->memory_allocated_percentage(), 50);
        EXPECT_EQ(ml_wf->memory_allocated_percentage(), 50);
        EXPECT_EQ(ml_ff->mem_status(),"10");
        EXPECT_EQ(ml_bf->mem_status(),"10");
        EXPECT_EQ(ml_wf->mem_status(),"10");
        ml_ff->add_element(50);
        ml_bf->add_element(50);
        ml_wf->add_element(50);
        EXPECT_EQ(ml_ff->memory_allocated_percentage(), 100);
        EXPECT_EQ(ml_bf->memory_allocated_percentage(), 100);
        EXPECT_EQ(ml_wf->memory_allocated_percentage(), 100);
        EXPECT_EQ(ml_ff->mem_status(),"11");
        EXPECT_EQ(ml_bf->mem_status(),"11");
        EXPECT_EQ(ml_wf->mem_status(),"11");
    }

    TEST_F(MemoryTest, FirstFitAllocation)
    {
        ml_ff->add_element(25);
        ml_ff->add_element(25);
        ml_ff->add_element(25);
        EXPECT_EQ(ml_ff->mem_status(),"1110");
        ml_ff->del_element(1);
        EXPECT_EQ(ml_ff->mem_status(),"0110");
        ml_ff->del_element(1);
        EXPECT_EQ(ml_ff->mem_status(),"010");
        ml_ff->add_element(10);
        EXPECT_EQ(ml_ff->mem_status(),"1010");
        ml_ff->add_element(10);
        EXPECT_EQ(ml_ff->mem_status(),"11010");
        ml_ff->add_element(25);
        EXPECT_EQ(ml_ff->mem_status(),"111010");
        ml_ff->add_element(25);
        EXPECT_EQ(ml_ff->mem_status(),"111011");
        ml_ff->add_element(5);
        EXPECT_EQ(ml_ff->mem_status(),"111111");
    }

}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}