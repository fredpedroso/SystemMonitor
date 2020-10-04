#include <cctype>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::add_cv_t;
using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {}

// Return this process's ID
int Process::Pid() { return pid_; }

// Return this process's CPU utilization
float Process::CpuUtilization() { return LinuxParser::CpuUtilization(pid_); }

// Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// Return this process's memory utilization based on RSS
long int Process::Rss() { return LinuxParser::Rss(pid_); }

// Return this process's memory utilization based on PSS
long int Process::Pss() { return LinuxParser::Pss(pid_); }

// Return the user that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const &process) const {
  return LinuxParser::CpuUtilization(process.pid_) <
         LinuxParser::CpuUtilization(this->pid_);
}