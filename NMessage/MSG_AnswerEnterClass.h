#ifndef VNOC_C_MESSAGE_MSG_AnswerEnterClass
#define VNOC_C_MESSAGE_MSG_AnswerEnterClass
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

class MSG_AnswerEnterClass : public CMessage
{
public:
    MSG_AnswerEnterClass()
    {
        InitializeMessage("MSG_AnswerEnterClass");
    }

    virtual ~MSG_AnswerEnterClass(){}

    MsgStatus SetRetTag(const Define::uint32& Value)
    {
        return Write("RetTag", new NumData<Define::uint32>(Value));
    }

    MsgStatus GetRetTag(Define::uint32& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("RetTag", pReadValue);
        return pReadValue->ToUInt32(Value);
    }
};

}// namespace Message
}// namespace VNOC

#endif