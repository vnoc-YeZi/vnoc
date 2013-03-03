#ifndef VNOC_C_MESSAGE_MSG_RequestEnterClass
#define VNOC_C_MESSAGE_MSG_RequestEnterClass
#include "MessageDef.h"
#include "CMessage.h"
#include "MsgDataValue/StringData.h"
#include "MsgDataValue/NumData.hpp"
//测试中文
///> Generate by MessageProduse. DO NOT EDIT!

namespace VNOC
{
namespace Message
{

class MSG_RequestEnterClass : public CMessage
{
public:
    MSG_RequestEnterClass()
    {
        InitializeMessage("MSG_RequestEnterClass");
    }

    virtual ~MSG_RequestEnterClass(){}

    MsgStatus SetRoomID(const Define::uint32& Value)
    {
        return Write("RoomID", new NumData<Define::uint32>(Value));
    }

    MsgStatus SetRoomPassword(const std::string& Value)
    {
        return Write("RoomPassword", new StringData(Value));
    }

    MsgStatus SetVerificationCode(const std::string& Value)
    {
        return Write("VerificationCode", new StringData(Value));
    }

    MsgStatus GetRoomID(Define::uint32& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("RoomID", pReadValue);
        return pReadValue->ToUInt32(Value);
    }

    MsgStatus GetRoomPassword(std::string& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("RoomPassword", pReadValue);
        return pReadValue->ToStr(Value);
    }

    MsgStatus GetVerificationCode(std::string& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("VerificationCode", pReadValue);
        return pReadValue->ToStr(Value);
    }
};

}// namespace Message
}// namespace VNOC

#endif