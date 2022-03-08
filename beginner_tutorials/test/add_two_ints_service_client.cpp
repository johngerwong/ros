#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <beginner_tutorials/AddTwoInts.h>

std::shared_ptr<ros::NodeHandle> nh;

TEST(TESTSuite, AddTwoPositiveN_GetPositiveSum)
{
  ros::ServiceClient client = nh->serviceClient<beginner_tutorials::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::AddTwoInts srv;
  srv.request.a = 5;
  srv.request.b = 8;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(TESTSuite, AddTwoNegative_GetNegativeSum)
{
  ros::ServiceClient client = nh->serviceClient<beginner_tutorials::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::AddTwoInts srv;
  srv.request.a = -5;
  srv.request.b = -8;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(TESTSuite, AddPositiveNegative_GetNegativeSum)
{
  ros::ServiceClient client = nh->serviceClient<beginner_tutorials::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::AddTwoInts srv;
  srv.request.a = 5;
  srv.request.b = -8;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(TESTSuite, AddPositiveNegative_GetPositiveSum)
{
  ros::ServiceClient client = nh->serviceClient<beginner_tutorials::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::AddTwoInts srv;
  srv.request.a = -5;
  srv.request.b = 8;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(TESTSuite, AddZeroPositive_GetPositiveSum)
{
  ros::ServiceClient client = nh->serviceClient<beginner_tutorials::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::AddTwoInts srv;
  srv.request.a = 0;
  srv.request.b = 8;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(TESTSuite, AddZeroNegative_GetNegativeSum)
{
  ros::ServiceClient client = nh->serviceClient<beginner_tutorials::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::AddTwoInts srv;
  srv.request.a = -5;
  srv.request.b = 0;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

int main(int argc,
         char **argv)
{
  ros::init(argc, argv, "add_two_ints_service_client");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

