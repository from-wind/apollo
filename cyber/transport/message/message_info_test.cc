/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/* note that the frame code of the following is Generated by script  */

#include "cyber/transport/message/message_info.h"

#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "cyber/transport/common/identity.h"

namespace apollo {
namespace cyber {
namespace transport {

TEST(MessageInfoTest, test) {
  Identity id, id2, id3;
  MessageInfo msgInfo(id, 123);
  MessageInfo msgInfoX;

  msgInfo = msgInfo;
  msgInfoX = msgInfo;

  msgInfo.set_spare_id(id3);
  EXPECT_NE(msgInfo, msgInfoX);
  msgInfo.set_sender_id(id2);
  EXPECT_NE(msgInfo, msgInfoX);
  msgInfo.set_seq_num(789);
  EXPECT_NE(msgInfo, msgInfoX);
  msgInfo.set_channel_id(123);
  EXPECT_NE(msgInfo, msgInfoX);

  MessageInfo msgInfo2(msgInfo);

  EXPECT_EQ(msgInfo.sender_id(), msgInfo2.sender_id());
  EXPECT_EQ(msgInfo.seq_num(), msgInfo2.seq_num());
  EXPECT_EQ(msgInfo.spare_id(), msgInfo2.spare_id());
  EXPECT_EQ(msgInfo, msgInfo2);

  std::string msgStr, msgStr2;
  EXPECT_TRUE(msgInfo.SerializeTo(&msgStr));
  msgStr2.resize(msgStr.size());

  EXPECT_FALSE(msgInfo.SerializeTo(const_cast<char*>(msgStr2.data()), 2));
  EXPECT_TRUE(
      msgInfo.SerializeTo(const_cast<char*>(msgStr2.data()), msgStr2.size()));

  EXPECT_EQ(msgStr, msgStr2);

  MessageInfo msgInfo3, msgInfo4;
  EXPECT_TRUE(msgInfo3.DeserializeFrom(msgStr));
  EXPECT_FALSE(msgInfo4.DeserializeFrom(msgStr2.data(), 2));
  EXPECT_TRUE(msgInfo4.DeserializeFrom(msgStr2.data(), msgStr2.size()));

  EXPECT_EQ(msgInfo3, msgInfo4);
}

}  // namespace transport
}  // namespace cyber
}  // namespace apollo
