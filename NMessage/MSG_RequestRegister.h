#ifndef VNOC_C_MESSAGE_MSG_RequestRegister
#define VNOC_C_MESSAGE_MSG_RequestRegister
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

class MSG_RequestRegister : public CMessage
{
public:
    MSG_RequestRegister()
    {
        InitializeMessage("MSG_RequestRegister");
    }

    virtual ~MSG_RequestRegister(){}

    MsgStatus SetAge(const Define::uint8& Value)
    {
        return Write("Age", new NumData<Define::uint8>(Value));
    }

    MsgStatus SetAutograph(const std::string& Value)
    {
        return Write("Autograph", new StringData(Value));
    }

    MsgStatus SetBirthday(const std::string& Value)
    {
        return Write("Birthday", new StringData(Value));
    }

    MsgStatus SetEmailAddress(const std::string& Value)
    {
        return Write("EmailAddress", new StringData(Value));
    }

    MsgStatus SetHeadForm(const Define::uint8& Value)
    {
        return Write("HeadForm", new NumData<Define::uint8>(Value));
    }

    MsgStatus SetHeadPortrait(const std::string& Value)
    {
        return Write("HeadPortrait", new StringData(Value));
    }

    MsgStatus SetNickname(const std::string& Value)
    {
        return Write("Nickname", new StringData(Value));
    }

    MsgStatus SetPersonalExplanation(const std::string& Value)
    {
        return Write("PersonalExplanation", new StringData(Value));
    }

    MsgStatus SetRank(const Define::uint8& Value)
    {
        return Write("Rank", new NumData<Define::uint8>(Value));
    }

    MsgStatus GetAge(Define::uint8& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("Age", pReadValue);
        return pReadValue->ToUInt8(Value);
    }

    MsgStatus GetAutograph(std::string& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("Autograph", pReadValue);
        return pReadValue->ToStr(Value);
    }

    MsgStatus GetBirthday(std::string& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("Birthday", pReadValue);
        return pReadValue->ToStr(Value);
    }

    MsgStatus GetEmailAddress(std::string& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("EmailAddress", pReadValue);
        return pReadValue->ToStr(Value);
    }

    MsgStatus GetHeadForm(Define::uint8& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("HeadForm", pReadValue);
        return pReadValue->ToUInt8(Value);
    }

    MsgStatus GetHeadPortrait(std::string& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("HeadPortrait", pReadValue);
        return pReadValue->ToStr(Value);
    }

    MsgStatus GetNickname(std::string& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("Nickname", pReadValue);
        return pReadValue->ToStr(Value);
    }

    MsgStatus GetPersonalExplanation(std::string& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("PersonalExplanation", pReadValue);
        return pReadValue->ToStr(Value);
    }

    MsgStatus GetRank(Define::uint8& Value)
    {
        MsgDataValue* pReadValue = NULL;
        Read("Rank", pReadValue);
        return pReadValue->ToUInt8(Value);
    }
};

}// namespace Message
}// namespace VNOC

#endif