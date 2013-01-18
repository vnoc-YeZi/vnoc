

#ifndef VNOC_ACL
#define VNOC_ACL

#include "BaseMessage.h"

class MSG_ACL:public CMessage
{
public:
	MSG_ACL(){
		//0x1F
		BEGIN_PARAM_LIST
		ADD_PARAM_LIST("RoomIdList")
		INIT_PARAM_OBJEDT(MSG_ACL_COM)
		END_PARAM_LIST
	}
	virtual ~MSG_ACL(){}

public:

	int  GetRoomIdList(std::vector<int>& RoomList) const
	GetParam_t_tamp_r("RoomIdList",int,RoomList);

	int GetRoomListSize() const{
		return (CMessage::GetParamLen(0) / 4);
	}

};

#endif