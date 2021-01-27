/*
 * @Descripttion: 
 * @Author: zhengjinhong
 * @Date: 2020-11-11 15:07:17
 * @LastEditors: zhengjinhong
 * @LastEditTime: 2020-11-13 15:39:57
 */

#include "clientsession.h"
#include "engine/inc/log/env.h"

bool ClientSession::Init() {
  return true;
}

void ClientSession::OnEstablish(shared_ptr<CSClientSession> sess) {
}

void ClientSession::OnTerminate(shared_ptr<CSClientSession> sess) {
}

void ClientSession::OnHandlerMsg(shared_ptr<CSClientSession> sess, uint32_t msg_id, const char* data, uint32_t len) {
  auto dealer = iddealer.Find(msg_id);
  if (dealer == nullptr) {
    LogWarnA("ClientSession OnHandlerMsg Can Not Find MsgID = {}", msg_id);
    return;
  }

  dealer(sess, data, len);
}

void ClientSession::OnBeatHeartError(shared_ptr<CSClientSession> sess) {
}
