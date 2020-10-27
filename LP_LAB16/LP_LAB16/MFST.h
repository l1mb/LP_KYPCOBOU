#pragma once
#include "GRB.h"

#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3

template <typename T>
struct use_container : T
{
	using T::T;
	using T::c;
};

typedef use_container<std::stack<short>> MFSTSTSTACK;

namespace MFST {
	struct MfstState {
		short lenta_position, nrule, nrulechain;
		MFSTSTSTACK st;
		MfstState();
		MfstState(short pposition, MFSTSTSTACK pst, short pnrulechain);
		MfstState(short pposition, MFSTSTSTACK pst, short pnrule, short pnrulechain);
	};

	struct Mfst {
		enum class RC_STEP {	//! ��� �������� ������� step
			NS_OK,				//! ������� ������� � �������, ������� �������� � ����
			NS_NORULE,			//! �� ������� ������� ���������� (������ � ����������)
			NS_NORULECHAIN,		//! �� ������� ���������� ������� ������� (������ � �������� ����)
			NS_ERROR,			//! ����������� �������������� ������ ����������
			TS_OK,				//! ������� ������ ����� == ������� �����, ������������ �����, ��� �����
			TS_NOK,				//! ������� ������ ����� != ������� �����, ������������� ���������
			LENTA_END,			//! ������� ������� ����� >= lenta_size
			SURPRISE			//! ����������� ��� �������� ( ������ � step)
		};
		struct MfstDiagnosis {
			short lenta_position, nrule, nrule_chain;
			RC_STEP rc_step;
			MfstDiagnosis();
			MfstDiagnosis(short plenta_position, RC_STEP prc_step, short pnrule, short pnrule_chain);
		}diagnosis[MFST_DIAGN_NUMBER];
		GRBALPHABET* lenta;
		short lenta_position, nrule, nrulechain, lenta_size;
		GRB::Greibach grebach;
		LT::LexTable lex;
		MFSTSTSTACK st;
		use_container<std::stack<MfstState>> storestate;
		Mfst();
		Mfst(LT::LexTable plex, GRB::Greibach pgrebach);
		char* getCSt(char* buf);
		char* getCLenta(char* buf, short pos, short n = 25);
		char* getDiagnosis(short n, char* buf);
		bool savestate(const Log::LOG& log);
		bool reststate(const Log::LOG& log);
		bool push_chain(GRB::Rule::Chain chain);
		RC_STEP step(const Log::LOG& log);
		bool start(const Log::LOG& log);
		bool savediagnois(RC_STEP pprc_step);
		void printrules(const Log::LOG& log);
		struct Deducation {
			short size;
			short* nrules, * nrulechains;
			Deducation() { size = 0; nrules = 0; nrulechains = 0; };
		}deducation;
		bool savededucation();
	};
};