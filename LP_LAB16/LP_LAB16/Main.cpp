#include "pch.h"

#pragma region "Для вывода в консоль"

std::string pupa(IT::IDTYPE type) {
	switch (type) {
	case IT::IDTYPE::F: return "Function"; break;
	case IT::IDTYPE::V: return "Variable"; break;
	case IT::IDTYPE::P: return "Parameter"; break;
	case IT::IDTYPE::L: return "Literal"; break;
	default: return "ERROR"; break;
	}
}

std::string lupa(IT::IDDATATYPE type) {
	switch (type) {
	case IT::IDDATATYPE::INT: return "INT"; break;
	case IT::IDDATATYPE::STR: return "STRING"; break;
	default: return "ERROR"; break;
	}
}

#pragma endregion

void output(const LT::LexTable& lextable, std::ofstream* file) {
	int current_line = lextable.table[0].sn;
	for (int i = 0; i < lextable.size; i++) {
		if (lextable.table[i].lexema == '!')
			continue;
		if (current_line < lextable.table[i].sn) {
			*file << '\n';
			current_line = lextable.table[i].sn;
		}
		*file << lextable.table[i].lexema;
	}
}

//todo Избавиться от утечек памяти в Chain, Rule, Greibach

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "rus");

	Log::LOG log = Log::INITLOG;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in, parm.out);
		Log::WriteIn(log, in);
		LT::LexTable lextable = LT::Create(in.lexems.size());
		IT::IdTable idtable = IT::Create(in.lexems.size());
		std::ofstream outputFile(parm.out);
		FST::Recognize(in.lexems, log.stream, &outputFile, lextable, idtable);

		MFST_TRACE_START(log)
			MFST::Mfst mfst(lextable, GRB::getGreibach());
		mfst.start(log);

		PN::PolishNotation(17, lextable, idtable) ? std::cout << "Польская запись построена\n"
			: std::cout << "Польская запись не построена\n";

		//! Таблица идентификаторов
		[&] {
			std::cout << "+-+-+-+-+-+-+-+-+-+ Таблица идентификаторов +-+-+-+-+-+-+-+-+-+\n";
			for (int i = 0; i < idtable.size; i++) {
				std::cout << i << "\t| " << idtable.table[i].scope << idtable.table[i].id << " | " << idtable.table[i].idxfirstLE;
				std::cout << " | " << pupa(idtable.table[i].idtype) << " | " << lupa(idtable.table[i].iddatatype);
				std::cout << " | ";
				if (idtable.table[i].idtype == IT::IDTYPE::L)
					if (idtable.table[i].iddatatype == IT::IDDATATYPE::INT)
						std::cout << idtable.table[i].value.vint << std::endl;
					else
						std::cout << idtable.table[i].value.vstr.str << std::endl;
				else
					std::cout << std::endl;
			}
			std::cout << "+-+-+-+-+-+-+-+-+-+ Таблица идентификаторов +-+-+-+-+-+-+-+-+-+\n";
		};

		//! Таблица лексем
		[&] {
			std::cout << "+-+-+-+-+-+-+-+-+-+ Таблица лексем +-+-+-+-+-+-+-+-+-+\n";
			for (int i = 0; i < lextable.size; i++) {
				std::cout << i << '\t' << lextable.table[i].idxTI << '\t' << lextable.table[i].lexema;
				std::cout << '\t' << lextable.table[i].sn << std::endl;
			}
			std::cout << "+-+-+-+-+-+-+-+-+-+ Таблица лексем +-+-+-+-+-+-+-+-+-+\n";
		};

		output(lextable, &outputFile);

		LT::Delete(lextable);
		IT::Delete(idtable);
	}
	catch (Error::ERROR e) {
		Log::WriteError(log, e);
	}
	Log::Close(log);

#ifdef _DEBUG
	int hasMemoryLeaks = _CrtDumpMemoryLeaks();
#else
	system("pause");
#endif
	return 0;
}