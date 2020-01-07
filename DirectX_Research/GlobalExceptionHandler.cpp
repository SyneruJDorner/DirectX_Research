#include "GlobalExceptionHandler.h"
#include <sstream>


GlobalExceptionHandler::GlobalExceptionHandler(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* GlobalExceptionHandler::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* GlobalExceptionHandler::GetType() const noexcept
{
	return "Global Exception Handler";
}

int GlobalExceptionHandler::GetLine() const noexcept
{
	return line;
}

const std::string& GlobalExceptionHandler::GetFile() const noexcept
{
	return file;
}

std::string GlobalExceptionHandler::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}