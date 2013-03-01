#ifndef VNOC_C_MESSAGE_MSG_AnswerEnterClassroom
#define VNOC_C_MESSAGE_MSG_AnswerEnterClassroom
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

class MSG_AnswerEnterClassroom : public CMessage
{
public:
    MSG_AnswerEnterClassroom()
    {
        InitializeMessage("MSG_AnswerEnterClassroom");
    }

    virtual ~MSG_AnswerEnterClassroom(){}

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