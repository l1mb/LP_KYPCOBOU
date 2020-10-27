#include "pch.h"

IT::IdTable IT::Create(int size)
{
	if (size > TI_MAXSIZE)
		throw ERROR_THROW(114);
	IdTable idtable;
	idtable.table = DBG_NEW Entry[size];
	idtable.maxsize = size;
	idtable.size = 0;
	return idtable;
}

void IT::Add(IdTable& idtable, const Entry& entry)
{
	if (idtable.size == idtable.maxsize)
		throw ERROR_THROW(114);
	idtable.table[idtable.size] = entry;
	idtable.size++;
}

IT::Entry IT::GetEntry(IdTable& idtable, int n)
{
	return idtable.table[n];
}

bool IT::is_digit(const char* str)
{
	for (unsigned int i = 0; i < strlen(str); i++)
		if (str[i] < '0' || str[i] > '9')
			return false;
	return true;
}

int IT::IsId(IdTable& idtable, const char id[ID_MAXSIZE], const char prefix[ID_SCOPE_SIZE])
{
	bool is_found = false;
	for (int i = 0; i < idtable.size; i++) {
		for (size_t j = 0; j < strlen(idtable.table[i].id); j++) {
			is_found = false;
			if (idtable.table[i].id[j] == id[j])
				is_found = true;
			else
				break;
		}
		if (is_found)
			for (size_t j = 0; j < strlen(idtable.table[i].scope); j++) {
				is_found = false;
				if (idtable.table[i].scope[j] == prefix[j])
					is_found = true;
				else
					break;
			}
		if (is_found)
			return i;
	}
	return TI_NULLIDX;
}

int IT::LiteralRepeat(IdTable& idtable, std::string literal)
{
	for (int i = 0; i < idtable.size; i++)
		if (idtable.table[i].idtype == IT::IDTYPE::L)
			if (idtable.table[i].iddatatype == IT::IDDATATYPE::INT) {
				int temp = atoi(literal.c_str());
				if (temp == idtable.table[i].value.vint)
					return i;
			}
			else if (idtable.table[i].value.vstr.str == literal)
				return i;
	return TI_NULLIDX;
}

void IT::Delete(IdTable& idtable)
{
	delete[] idtable.table;
}

IT::Entry::Entry(int idxfirstLE, const char* id, const char* scope, IDDATATYPE iddatatype, IDTYPE idtype)
	: idxfirstLE(idxfirstLE), idtype(idtype), iddatatype(iddatatype), value({ NULL })
{
	for (int i = 0; i < ID_MAXSIZE; i++) {
		this->id[i] = id[i];
	}
	this->id[ID_MAXSIZE - 1] = '\0';

	for (int i = 0; i < ID_SCOPE_SIZE; i++) {
		this->scope[i] = scope[i];
	}
	this->scope[ID_SCOPE_SIZE - 1] = '\0';
}

IT::Entry::Entry(int idxfirstLE, const char* id, const char* scope, IDDATATYPE iddatatype, IDTYPE idtype, std::string value)
	: idxfirstLE(idxfirstLE), idtype(idtype), iddatatype(iddatatype), id(""), scope("")
{
	if (iddatatype == IT::IDDATATYPE::INT)
		this->value.vint = atoi(value.c_str());
	else {
		this->value.vstr.len = (unsigned char)value.size();
		for (size_t i = 0; i < value.size(); i++)
			this->value.vstr.str[i] = value[i];
		this->value.vstr.str[value.size()] = '\0';
	}
}