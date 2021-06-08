#include "dxException.h"
#include <sstream>

dxException::dxException(int line, const char* file) noexcept
    : line(line), file(file)
{
}

const char* dxException::what() const noexcept
{
    std::ostringstream oss;
    oss << GetType() << '\n' << GetOriginString();
    whatBuffer = oss.str();
    return whatBuffer.c_str();
}

const char* dxException::GetType() const noexcept
{
    return "Dx Exception";
}

int dxException::GetLine() const noexcept
{
    return line;
}

const std::string& dxException::GetFile() const noexcept
{
    return file;
}

std::string dxException::GetOriginString() const noexcept
{
    std::ostringstream oss;
    oss << "[File] " << file << '\n'
        << "[Line] " << line;
    return oss.str();
}
