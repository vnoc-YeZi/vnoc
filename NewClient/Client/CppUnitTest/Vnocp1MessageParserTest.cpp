#ifdef CPPTEST
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "..\..\Message\MessageParser.h"
#include <string.h>
class Vnocp1MessageParserTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( Vnocp1MessageParserTest );
	CPPUNIT_TEST( MSGParserCheckTest );
	CPPUNIT_TEST( MSGAVCParseTest );
	CPPUNIT_TEST( MSGRVCParseTest );
	CPPUNIT_TEST( MSGALIParseTest );
	CPPUNIT_TEST( MSGRLIParseTest );
	CPPUNIT_TEST( MSGAPSParseTest );
	CPPUNIT_TEST( MSGRPSParseTest );
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp()
    {
        
    }
    void tearDown()
    {

    }
public:

	void MSGParserCheckTest()
	{
		byte testAllRubbish[] = {
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
		};
		byte testHasHeadRubbish[] = 
		{
			0x12,0x12,0x12,0x12,
			'V',0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
		};
		byte testLengthLack[] = 
		{
			'V',0x12,0x12,0x12,
			0x00,0x00,0x00,0xff,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
		};
		byte testNoTailRubbish[]=
		{
			'V',0x12,0x12,0x12,
			0x00,0x00,0x00,0x10,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
		};
		byte testGood[]=
		{
			'V',0x12,0x12,0x12,
			0x00,0x00,0x00,0x10,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,'C',
		};
		byte testRubbishWithGood[]=
		{
			0x12,0x12,0x12,0x12,
			'V',0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,0x12,

			'V',0x12,0x12,0x12,
			0x00,0x00,0x00,0x10,
			0x12,0x12,0x12,0x12,
			0x12,0x12,0x12,'C',
		};
		CPPUNIT_ASSERT(CMessageParser::Check(testAllRubbish,sizeof(testAllRubbish)) == -1);
		CPPUNIT_ASSERT(CMessageParser::Check(testHasHeadRubbish,sizeof(testHasHeadRubbish)) == -1);
		CPPUNIT_ASSERT(CMessageParser::Check(testLengthLack,sizeof(testLengthLack)) == -1);
		CPPUNIT_ASSERT(CMessageParser::Check(testNoTailRubbish,sizeof(testNoTailRubbish)) == -1);
		CPPUNIT_ASSERT(CMessageParser::Check(testGood,sizeof(testGood)) == 0x10);
		CPPUNIT_ASSERT(CMessageParser::Check(testRubbishWithGood,sizeof(testRubbishWithGood)) == 0x2c);
	}

	void MSGAVCParseTest()
	{
		byte testParamO [] = {0x01,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02};
		byte testParamT [] = {0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03};
		byte testParamS [] = {0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04};

		byte testAVC [] = {0x56,
			0x00,
			0x00,0x01,
			0x00,0x00,0x00,0x3F,


			0x01,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x15,
			0x00,0x00,0x00,0x00,
			0x03,

			0x00,0x00,0x00,0x01,
			0x00,0x00,0x00,0x01,
			0x00,0x00,0x00,0x10,

			0x1e,

			0x1e,

			0x01,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x00,0x00,
			0x43};


		byte testPackAVC[63] = {0};

		//AVC
		CMessageParser msgParser;
		CMessage* msgAVC = msgParser.Parse(testAVC,sizeof(testAVC));
		CPPUNIT_ASSERT(msgAVC->GetMessageType() == MSG_AVC_TYPE);//验证消息类型是AVC
		MSG_AVC* msg_avc = (MSG_AVC *)msgAVC;
		CPPUNIT_ASSERT(msg_avc->GetSerial() == 1);
		CPPUNIT_ASSERT(memcmp(msg_avc->GetGUID(),testParamO,sizeof(byte) * 16) == 0);
		CPPUNIT_ASSERT(memcmp(msg_avc->GetCaptcha(),testParamO,16) == 0);
		CPPUNIT_ASSERT(msg_avc->GetLoginTag() == 0x1e);
		CPPUNIT_ASSERT(msg_avc->GetCaptchaType() == 0x1e);
		delete msg_avc;
	}

	void MSGRVCParseTest()
	{
		byte testParamO [] = {0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02};
		byte testParamT [] = {0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03};
		byte testParamS [] = {0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04};

		byte testRVC [] = {0x56,
			0x00,
			0x00,0x01,
			0x00,0x00,0x00,0x35,

			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x14,
			0x00,0x00,0x00,0x00,
			0x01,

			0x00,0x00,0x00,0x10,

			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x00,0x00,
			0x43};

		byte testPackRVC[53] = {0};

		CMessageParser msgParser;
		CMessage* msgRVC = msgParser.Parse(testRVC,sizeof(testRVC));
		CPPUNIT_ASSERT(msgRVC->GetMessageType() == MSG_RVC_TYPE);//验证消息类型是RVC
		MSG_RVC* msg_rvc = (MSG_RVC *)msgRVC;

		CPPUNIT_ASSERT(msg_rvc->GetSerial() == 1);

		CPPUNIT_ASSERT(memcmp(msg_rvc->GetGUID(),testParamO,sizeof(byte) * 16) == 0);
		CPPUNIT_ASSERT(memcmp(msg_rvc->GetMachineAddress(),testParamO,16) == 0);
		delete msg_rvc;
	}

	void MSGRLIParseTest()
	{
		byte testParamO [] = {0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02};
		byte testParamT [] = {0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03};
		byte testParamS [] = {0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04};

		byte testRLI [] = {0x56,
			0x00,
			0x00,0x01,
			0x00,0x00,0x00,0x5D,


			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x16,
			0x00,0x00,0x00,0x00,

			0x03,

			0x00,0x00,0x00,0x10,
			0x00,0x00,0x00,0x10,
			0x00,0x00,0x00,0x10,


			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,

			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,

			0x00,0x00,
			0x43};

		byte testPackRLI[100] = {0};

		//RLI
		CMessageParser  msgParser;
		CMessage* msgRLI = msgParser.Parse(testRLI,sizeof(testRLI));
		CPPUNIT_ASSERT(msgRLI->GetMessageType() == MSG_RLI_TYPE);//验证消息类型是RLI
		MSG_RLI* msg_rli = (MSG_RLI *)msgRLI;

		CPPUNIT_ASSERT(msg_rli->GetSerial() == 1);

		CPPUNIT_ASSERT(memcmp(msg_rli->GetGUID(),testParamO,sizeof(byte) * 16) == 0);

		CPPUNIT_ASSERT(memcmp(msg_rli->GetVerificationCode(),testParamO,sizeof(byte) * 16) == 0);

		CPPUNIT_ASSERT(memcmp(msg_rli->GetAccountNumber(),testParamT,16) == 0);

		CPPUNIT_ASSERT(memcmp(msg_rli->GetPassword(),testParamS,16) == 0);
		delete msg_rli;

	}

	void MSGRPSParseTest()
	{
		byte testParamO [] = {0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02};
		byte testParamT [] = {0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03};
		byte testParamS [] = {0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04};


		byte testRPS [] = {0x56,
			0x00,
			0x00,0x01,
			0x00,0x00,0x00,0x67,

			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x18,
			0x00,0x00,0x00,0x00,

			0x05,

			0x00,0x00,0x00,0x01,
			0x00,0x00,0x00,0x10,
			0x00,0x00,0x00,0x10,
			0x00,0x00,0x00,0x01,
			0x00,0x00,0x00,0x10,

			0x01,

			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,

			'A',

			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,

			0x00,0x00,
			0x43};

		byte testPackRPS[120] = {0};

		//RPS
		CMessageParser msgParser;
		CMessage* msgRPS = msgParser.Parse(testRPS,sizeof(testRPS));
		CPPUNIT_ASSERT(msgRPS->GetMessageType() == MSG_RPS_TYPE);//验证消息类型是RPS
		MSG_RPS* msg_rps = (MSG_RPS *)msgRPS;

		CPPUNIT_ASSERT(msg_rps->GetSerial() == 1);

		CPPUNIT_ASSERT(memcmp(msg_rps->GetGUID(),testParamO,sizeof(byte) * 16) == 0);

		CPPUNIT_ASSERT(msg_rps->GetRank() == 0x01);

		CPPUNIT_ASSERT(memcmp(msg_rps->GetNickname(),testParamO,sizeof(byte) * 16) == 0);

		CPPUNIT_ASSERT(memcmp(msg_rps->GetAutograph(),testParamT,sizeof(byte) * 16) == 0);

		CPPUNIT_ASSERT(msg_rps->GetHeadForm() == 'A');

		CPPUNIT_ASSERT(memcmp(msg_rps->GetHeadPortrait(),testParamS,sizeof(byte) * 16) == 0);
		delete msg_rps;

	}

	void MSGAPSParseTest()
	{
		byte testParamO [] = {0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02};
		byte testParamT [] = {0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03};
		byte testParamS [] = {0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04};

		byte testAPS [] = {0x56,
			0x00,
			0x00,0x01,
			0x00,0x00,0x00,0x35,

			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x19,
			0x00,0x00,0x00,0x00,
			0x01,

			0x00,0x00,0x00,0x10,

			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x00,0x00,
			0x43};

		byte testPackAPS[100] = {0};
		//APS
		CMessageParser msgParser;
		CMessage* msgAPS = msgParser.Parse(testAPS,sizeof(testAPS));
		CPPUNIT_ASSERT(msgAPS->GetMessageType() == MSG_APS_TYPE);//验证消息类型是RPS
		MSG_APS* msg_aps = (MSG_APS *)msgAPS;
	
		CPPUNIT_ASSERT(msg_aps->GetSerial() == 1);

		CPPUNIT_ASSERT(memcmp(msg_aps->GetGUID(),testParamO,sizeof(byte) * 16) == 0);

		CPPUNIT_ASSERT(memcmp(msg_aps->GetMessageSynchro(),testParamO,sizeof(byte) * 16) == 0);
		delete msg_aps;
	}

	void MSGALIParseTest()
	{
		byte testParamO [] = {0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02};
		byte testParamT [] = {0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03};
		byte testParamS [] = {0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04,
			0x04,0x04,0x04,0x04};

		byte testALI [] = {0x56,
			0x00,
			0x00,0x01,
			0x00,0x00,0x00,0x4E,

			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x17,
			0x00,0x00,0x00,0x00,

			0x03,

			0x00,0x00,0x00,0x01,
			0x00,0x00,0x00,0x10,
			0x00,0x00,0x00,0x10,

			0x1e,

			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,
			0x02,0x02,0x02,0x02,

			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,
			0x03,0x03,0x03,0x03,

			0x00,0x00,
			0x43};

		byte testPackALI[100] = {0};

		CMessageParser msgParser;
		CMessage* msgALI = msgParser.Parse(testALI,sizeof(testALI));
		CPPUNIT_ASSERT(msgALI->GetMessageType() == MSG_ALI_TYPE);//验证消息类型是ALI
		MSG_ALI* msg_ali = (MSG_ALI *)msgALI;

		CPPUNIT_ASSERT(msg_ali->GetSerial() == 1);

		CPPUNIT_ASSERT(memcmp(msg_ali->GetGUID(),testParamO,sizeof(byte) * 16) == 0);

		CPPUNIT_ASSERT(msg_ali->GetLoginResult() == 0x1E);

		CPPUNIT_ASSERT(memcmp(msg_ali->GetATLGUID(),testParamT,sizeof(byte) * 16) == 0);
		delete msg_ali;
	}

};
CPPUNIT_TEST_SUITE_REGISTRATION ( Vnocp1MessageParserTest );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(Vnocp1MessageParserTest, "Vnocp1MessageParserTest");

#endif 