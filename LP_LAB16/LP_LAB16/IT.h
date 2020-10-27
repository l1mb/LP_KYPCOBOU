#pragma once

#pragma region defines
#define ID_MAXSIZE 6
#define ID_SCOPE_SIZE 10
#define TI_MAXSIZE 4096
#define TI_INT_DEFAUL 0x0000000
#define TI_STR_DEFAULT 0x00
#define TI_NULLIDX -1
#define TI_STR_MAXSIZE 255
#pragma endregion

namespace IT {
	enum class IDDATATYPE { INT = 1, STR = 2 };
	enum class IDTYPE { V = 1, F = 2, P = 3, L = 4 }; //q ТИПЫ ИДЕНТИФИКАТОРОВ: ПЕРЕМЕННАЯ, ФУНКЦИЯ, ПАРАМЕТР, ЛИТЕРАЛ

	struct Entry {
		int idxfirstLE; //q индекс первой строки в таблице лексем
		char id[ID_MAXSIZE];
		char scope[ID_SCOPE_SIZE];
		IDDATATYPE iddatatype;
		IDTYPE idtype;
		union Value {
			int vint; //q значение int
			struct String {
				unsigned char len;
				char str[TI_STR_MAXSIZE];
			} vstr;//q значение string
		} value;
		Entry() = default;
		Entry(int idxfirstLE, const char* id, const char* scope, IDDATATYPE iddatatype, IDTYPE idtype);
		Entry(int idxfirstLE, const char* id, const char* scope, IDDATATYPE iddatatype, IDTYPE idtype, std::string value);
	};

	struct IdTable {
		int maxsize, size; //q size < maxsize
		Entry* table;
	};

	IdTable Create(int size);
	void Add(IdTable& idtable, const Entry& entry);
	Entry GetEntry(IdTable& idtable, int n);
	bool is_digit(const char* str);
	int IsId(IdTable& idtable, const char id[ID_MAXSIZE], const char prefix[ID_SCOPE_SIZE]); //q Возврат номера строки, если существует || TI_NULLIDX
	int LiteralRepeat(IdTable& idtable, std::string literal);
	void Delete(IdTable& idtable);
}