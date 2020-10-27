#include "pch.h"

#define BUFFER_MAX_SIZE 200

Log::LOG Log::getlog(wchar_t logfile[]) {
	LOG new_log;

	new_log.stream = DBG_NEW std::ofstream;
	new_log.stream->open(logfile);
	if (!new_log.stream->is_open())
		throw ERROR_THROW(112);

	wcscpy_s(new_log.logfile, logfile);

	return new_log;
}

void Log::WriteLine(LOG log, const char* c, ...) {
	const char** args = &c;

	for (int i = 0; args[i] != ""; ++i)
		*log.stream << args[i];
	*log.stream << std::endl;
}

void Log::WriteLine(LOG log, const wchar_t* c, ...) {
	char convertedBuffer[BUFFER_MAX_SIZE];
	const wchar_t** args = &c;

	for (int i = 0; args[i] != L""; ++i) {
		wcstombs_s(nullptr, convertedBuffer, args[i], sizeof(convertedBuffer));
		*log.stream << convertedBuffer;
	}
	*log.stream << std::endl;
}

void Log::WriteLog(LOG log) {
	char timeBuffer[BUFFER_MAX_SIZE];
	tm currentTime;
	time_t now = time(0);

	localtime_s(&currentTime, &now);
	strftime(timeBuffer, sizeof(timeBuffer), "%c", &currentTime);

	*log.stream << "---- �������� ------ ����: " << timeBuffer << " ------------" << std::endl;
}

void outputConverted(Log::LOG& log, wchar_t(&source)[PARM_MAX_SIZE], const wchar_t* key) {
	char convertedBuffer[BUFFER_MAX_SIZE];
	wcstombs_s(nullptr, convertedBuffer, key, sizeof(convertedBuffer));
	*log.stream << convertedBuffer << " ";
	wcstombs_s(nullptr, convertedBuffer, source, sizeof(convertedBuffer));
	*log.stream << convertedBuffer << std::endl;
}

void Log::WriteParm(LOG log, Parm::PARM parm) {
	*log.stream << "---- ��������� --------" << std::endl;
	outputConverted(log, parm.log, PARM_LOG);
	outputConverted(log, parm.out, PARM_OUT);
	outputConverted(log, parm.in, PARM_IN);
}

void Log::WriteIn(LOG log, In::IN in) {
	*log.stream << "---- �������� ������ ------" << std::endl <<
		"���������� ��������: " << in.size << std::endl <<
		"���������������: " << in.ignor << std::endl <<
		"���������� �����: " << in.lines << std::endl;
}

void Log::WriteError(LOG log, Error::ERROR error) {
	std::ostream& output = log.stream && log.stream->is_open() ? *log.stream : std::cout;

	output << "������ " << error.id << ' ' << error.message;
	error.inext.col + error.inext.line >= 0 ? output <<
		", ������ " << error.inext.line <<
		", ������� " << error.inext.col << std::endl : output << std::endl;
}

void Log::Close(LOG& log) {
	if (!log.stream)
		return;

	log.stream->close();
	delete log.stream;
	log.stream = nullptr;
}